#include <iostream>
using namespace std;

int padovan_sequnce(int num, int memo[]) {
    if (memo[num - 1] != 0) {
        return memo[num - 1];
    }
    
    return padovan_sequnce(num - 2, memo) + padovan_sequnce(num - 3, memo);
}

int main() {
    int memo[100000] = { 1, 1, 1, };

    int n = 0;
    cin >> n;

    cout << padovan_sequnce(n, memo);
}