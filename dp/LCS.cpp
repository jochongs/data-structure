#include <iostream>
#include <vector>
using namespace std;

int dp(int i, int j, string A, string B, vector< vector<int> >& memo) {
    if (i == 0 && j == 0) {
        memo[i][j] = A[i] == B[j];
        return memo[i][j];
    }

    if (A[i] == B[j]) {
        if (i == 0 || j == 0) {
            memo[i][j] = 1;
            return memo[i][j];
        }
        memo[i][j] = memo[i - 1][j - 1] + 1;
        return memo[i][j];
    }

    int maximum;
    if (i == 0) {
        maximum = memo[i][j - 1];
    } else if (j == 0) {
        maximum = memo[i - 1][j];
    } else {
        maximum = max(memo[i - 1][j], memo[i][j - 1]);
    }
    memo[i][j] = maximum;
    return memo[i][j];
}

int main() {
    string A;
    string B;

    vector< vector<int> > memo;

    cin >> A >> B;

    for (int i = 0; i < A.size(); i++) {
        vector <int> temp;
        for (int j = 0; j < B.size(); j++) {
            temp.push_back(0);
        }
        memo.push_back(temp);
    }

    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B.size(); j++) {
            dp(i, j, A, B, memo);
        }
    }

    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B.size(); j++) {
            cout << memo[i][j] << ' ';
        }
        cout << '\n';
    }
}