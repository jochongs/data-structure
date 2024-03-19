#include <iostream>
using namespace std;

long padovan_sequnce(long num, long memo[]) {
    if (memo[num - 1] != 0) {
        return memo[num - 1];
    }

    if (num <= 3) {
        return 1;
    }
    
    memo[num - 1] = padovan_sequnce(num - 2, memo) + padovan_sequnce(num - 3, memo);
    return memo[num - 1];
}

int main() {
    long memo[100000] = { 1, 1, 1, };

    long n = 0;
    cin >> n;

    cout << padovan_sequnce(n, memo);

    return 0;
}