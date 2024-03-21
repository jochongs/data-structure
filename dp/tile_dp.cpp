#include <iostream>
using namespace std;

long long tile_count_2(int n, long long memo[]) {
    if (n <= 1) {
        return 1;
    }
    
    if (memo[n] != 0) {
        return memo[n];
    }

    memo[n] = tile_count_2(n - 1, memo) + tile_count_2(n - 2, memo) + tile_count_2(n - 2, memo);
    return memo[n];
}

long long tile_count(int n, long long memo[]) {
    if (n <= 1) {
        memo[n] = 1;
        return memo[n];
    }

    if (memo[n] != 0) {
        return memo[n];
    }

    memo[n] = tile_count(n - 1, memo) + tile_count(n - 2, memo);
    return memo[n];
}

int main() {
    int n = 0;
    cin >> n;

    long long memo[10000] = {0, };

    long long tile_num = tile_count_2(n, memo);

    cout << "Tile Count: " << tile_num << '\n';
}