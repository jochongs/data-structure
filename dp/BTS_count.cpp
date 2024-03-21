#include <iostream>
using namespace std;

long long BTS_count(int n, long long memo[]) {
    if (n <= 1) {
        return 1;
    }

    if (memo[n] != 0) {
        return memo[n];
    }

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += BTS_count(i, memo) * BTS_count(n - 1 - i, memo);
    }
    memo[n] = sum;
    return memo[n];
}

int main() {
    int n = 0;
    cin >> n;

    long long memo[10000] = {0, };

    long long result = BTS_count(n, memo);

    cout << "Result: " << result << '\n';
}