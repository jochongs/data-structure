#include <iostream>
#include <stack>
using namespace std;

bool bracket_check(string input_str) {
    stack<char> s;
    for (int i = 0; i < input_str.size(); i++) {
        if (input_str[i] != '(' && input_str[i] != ')') {
            return false;
        }

        if (input_str[i] == '(') {
            s.push('(');
        }

        if (input_str[i] == ')') {
            if (s.empty()) {
                return false;
            }

            s.pop();
        }
    }

    if (s.empty()) {
        return true;
    }

    return false;
}

int main() {
    string input_str;
    cin >> input_str;

    bool result = bracket_check(input_str);

    if (result) {
        cout << "Valid bracket" << '\n';
    } else {
        cout << "Invalid bracket" << '\n';
    }

    return 0;
}