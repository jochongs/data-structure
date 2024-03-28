#include<iostream>
using namespace std;

int dp(int n, int memo[]) {
    if (n <= 0) {
        return 0;
    }

    if (memo[n] != 0) {
        return memo[n];
    }

    int sum = 0;
    cout << "n: " << n << '\n';
    for (int i = 0; i < 4 && i < n; i++) {
        cout << "dp_result = " << n - 1 - i << '\n';
        int dp_result = dp(n - i - 1, memo);

        if (dp_result == 0) {
            sum += 1;
        } else {
            sum += dp_result;
        }
    }

    memo[n] = sum;
    return memo[n];
}

int main() {
    int n = 0;
    cin >> n;

    int memo[1000] = {0, };

    for (int i = 0; i <= n; i++) {
        dp(i, memo);
    }

    for (int i = 0; i <= n; i++) {
        cout << memo[i] << ' ';
    }
}