#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
    Node *left;
    Node *right;
    int value;
    int count;
    int height;
    
    Node(int val) : value(val), count(1), height(1), left(nullptr), right(nullptr) {}

    void updateValues() {
        int leftCount = (left ? left->count : 0);
        int rightCount = (right ? right->count : 0);
        count = leftCount + rightCount + 1;

        int leftHeight = (left ? left->height : 0);
        int rightHeight = (right ? right->height : 0);
        height = max(leftHeight, rightHeight) + 1;
    }

    int balanceFactor() {
        int leftHeight = (left ? left->height : 0);
        int rightHeight = (right ? right->height : 0);
        return leftHeight - rightHeight;
    }
    
    Node* left_rotate() {
        Node* newRoot = right;
        right = newRoot->left;
        newRoot->left = this;
        
        updateValues();
        newRoot->updateValues();
        
        return newRoot;
    }

    Node* right_rotate() {
        Node* newRoot = left;
        left = newRoot->right;
        newRoot->right = this;
        
        updateValues();
        newRoot->updateValues();
        
        return newRoot;
    }
};

class AVLTree {
private:
    int _size;
    Node *root;

    Node* insertHelper(Node* node, int value, int depth, int& result) {
        if (!node) {
            _size++;
            Node* newNode = new Node(value);
            result = depth + newNode->height;
            return newNode;
        }

        if (value == node->value) {
            result = depth + node->height;
            return node;
        } else if (value < node->value) {
            node->left = insertHelper(node->left, value, depth + 1, result);
        } else {
            node->right = insertHelper(node->right, value, depth + 1, result);
        }

        node->updateValues();

        int bf = node->balanceFactor();

        // Left Heavy
        if (bf > 1) {
            if (value > node->left->value) { // LR Case
                node->left = node->left->left_rotate();
            }
            return node->right_rotate(); // LL Case
        }
        
        // Right Heavy
        if (bf < -1) {
            if (value < node->right->value) { // RL Case
                node->right = node->right->right_rotate();
            }
            return node->left_rotate(); // RR Case
        }

        return node;
    }

    Node* eraseHelper(Node* node, int value, int depth, int& result) {
        if (!node) return nullptr;

        if (value < node->value) {
            node->left = eraseHelper(node->left, value, depth + 1, result);
        } else if (value > node->value) {
            node->right = eraseHelper(node->right, value, depth + 1, result);
        } else {
            result = depth + node->height;
            
            if (!node->left || !node->right) {
                Node* temp = node->left ? node->left : node->right;
                if (!temp) {
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp;
                }
                delete temp;
                _size--;
            } else {
                Node* successor = findMin(node->right);
                node->value = successor->value;
                node->right = eraseHelper(node->right, successor->value, depth + 1, result);
            }
        }

        if (!node) return nullptr;

        node->updateValues();

        int bf = node->balanceFactor();

        // Left Heavy
        if (bf > 1) {
            if (node->left->balanceFactor() < 0) { // LR Case
                node->left = node->left->left_rotate();
            }
            return node->right_rotate(); // LL Case
        }
        
        // Right Heavy
        if (bf < -1) {
            if (node->right->balanceFactor() > 0) { // RL Case
                node->right = node->right->right_rotate();
            }
            return node->left_rotate(); // RR Case
        }

        return node;
    }

    Node* findMin(Node* node) {
        while (node->left) {
            node = node->left;
        }
        return node;
    }

    void destroyTree(Node* node) {
        if (node) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

    bool collectAncestors(Node* node, int value, vector<int>& ancestors, int depth) {
        if (!node) return false;
    
    if (node->value == value) {
        cout << depth + node->height;
        if (ancestors.empty()) cout << " 0";
        else {
            cout << " ";
            int sum = 0;
            for (int i = 0; i < ancestors.size(); i++) {
                sum += ancestors[i];
            }
            cout << sum;
        }
        cout << endl;
        return true;
    }
    
    ancestors.push_back(node->value);
    bool found = false;
        if (value < node->value) {
            found = collectAncestors(node->left, value, ancestors, depth + 1);
        } else {
            found = collectAncestors(node->right, value, ancestors, depth + 1);
        }
        if (!found) ancestors.pop_back();
        return found;
    }

    void findMinMax(Node* node, int& minVal, int& maxVal) {
        if (!node) return;
        
        minVal = min(minVal, node->value);
        maxVal = max(maxVal, node->value);
        
        findMinMax(node->left, minVal, maxVal);
        findMinMax(node->right, minVal, maxVal);
    }

    int countLessThan(Node* node, int value) {
        if (!node) return 0;
        
        if (node->value == value) {
            return (node->left ? node->left->count : 0);
        }
        
        if (value < node->value) {
            return countLessThan(node->left, value);
        }
        
        return (node->left ? node->left->count : 0) + 1 + 
               countLessThan(node->right, value);
    }

public:
    AVLTree() : _size(0), root(nullptr) {}
    
    ~AVLTree() {
        destroyTree(root);
    }
    
    Node* insert(int value) {
        int result = 0;
        root = insertHelper(root, value, 0, result);
        cout << result << endl;
        return root;
    }

    void erase(int value) {
        int result = 0;
        root = eraseHelper(root, value, 0, result);
        cout << result << endl;
    }

    int empty() {
        return root == nullptr ? 0 : 1;
    }

    int height() {
        return root ? root->height - 1 : -1;
    }

    void ancestor(int value) {
        vector<int> ancestors;
        collectAncestors(root, value, ancestors, 0);
    }

    int average(int value) {
        Node* node = findNode(value);
        if (!node) return 0;
        
        int minVal = node->value;
        int maxVal = node->value;
        findMinMax(node, minVal, maxVal);
        return (minVal + maxVal) / 2;
    }

    int rank(int value) {
        Node* currNode = findNode(value);
        if (!currNode) {
            cout << "0" << endl;
            return 0;
        }
        
        int depth = 0;
        Node* curr = root;
        while (curr && curr->value != value) {
            depth++;
            curr = (value < curr->value) ? curr->left : curr->right;
        }
        
        int result = countLessThan(root, value) + 1;
        cout << depth + currNode->height << " " << result << endl;
        return result;
    }

    int size() {
        return _size;
    }

    void find(int value) {
        int depth = 0;
        Node* curr = root;
        while (curr && curr->value != value) {
            depth++;
            curr = (value < curr->value) ? curr->left : curr->right;
        }
        if (curr) {
            cout << depth + curr->height << endl;
        }
    }

    Node* findNode(int value) {
        Node* curr = root;
        while (curr && curr->value != value) {
            curr = (value < curr->value) ? curr->left : curr->right;
        }
        return curr;
    }

    void display() {
        if (!root) {
            cout << "Tree is empty" << endl;
            return;
        }

        vector<vector<string> > levels;
        queue<pair<Node*, int> > q;
        q.push(make_pair(root, 0));
        int currentLevel = 0;
        levels.push_back(vector<string>());

        while (!q.empty()) {
            pair<Node*, int> front = q.front();
            Node* node = front.first;
            int level = front.second;
            q.pop();

            if (level != currentLevel) {
                levels.push_back(vector<string>());
                currentLevel = level;
            }

            string nodeStr = to_string(node->value) + "(" + to_string(node->height) + ")";
            levels[level].push_back(nodeStr);

            if (node->left) q.push(make_pair(node->left, level + 1));
            if (node->right) q.push(make_pair(node->right, level + 1));
        }

        for (int i = 0; i < levels.size(); i++) {
            for (int j = 0; j < levels[i].size(); j++) {
                cout << levels[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int commandCount = 0;
    cin >> commandCount;
    
    AVLTree tree;
    
    while(commandCount--) {
        string command;
        cin >> command;
        
        if (command == "insert") {
            int value;
            cin >> value;
            tree.insert(value);
        }
        else if (command == "erase") {
            int value;
            cin >> value;
            tree.erase(value);
        }
        else if (command == "empty") {
            cout << tree.empty() << endl;
        }
        else if (command == "height") {
            cout << tree.height() << endl;
        }
        else if (command == "size") {
            cout << tree.size() << endl;
        }
        else if (command == "find") {
            int value;
            cin >> value;
            tree.find(value);
        }
        else if (command == "ancestor") {
            int value;
            cin >> value;
            tree.ancestor(value);
        }
        else if (command == "rank") {
            int value;
            cin >> value;
            tree.rank(value);
        }
        else if (command == "average") {
            int value;
            cin >> value;
            cout << tree.average(value) << endl;
        }
        else if (command == "display") {
            tree.display();
        }
    }
    
    return 0;
}
