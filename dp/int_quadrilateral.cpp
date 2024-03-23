#include <iostream>
#include <vector>
using namespace std;

int dp(
    int i,
    int j,
    vector< vector<int> > quad,
    vector< vector<int> > &memo
) {
    //cout << "한 번 실행" << '\n';
    cout << "i: " << i << "  j: " << j << '\n';
    if (j <= 0 && i <= 0) {
        memo[0][0] = quad[0][0];
        return memo[0][0];
    }

    if (j <= 0) {
        memo[i][j] = quad[i][j] + dp(i - 1, 0, quad, memo);
        return memo[i][j];
    }

    if (i <= 0) {
        memo[i][j] = quad[i][j] + dp(0, j - 1, quad, memo);
        return memo[i][j];
    }

    if (memo[i][j] != 0) {
        return memo[i][j];
    }

    memo[i][j] = quad[i][j] + max(dp(i, j - 1, quad, memo), dp(i - 1, j, quad, memo));
    return memo[i][j];
}

int main() {
    int n = 0;
    cin >> n;
    
    vector< vector<int> > quad;
    vector< vector<int> > memo;

    for (int i = 0; i < n; i++) {
        vector<int> temp;
        vector<int> memo_temp;

        for (int j = 0; j < n; j++) {
            int input_num;
            cin >> input_num;
            temp.push_back(input_num);
            memo_temp.push_back(0);
        }

        quad.push_back(temp);
        memo.push_back(memo_temp);
    }

    dp(n - 1, n - 1, quad, memo);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << memo[i][j] << ' ';
        }
        cout << '\n';
    }
}