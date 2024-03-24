#include <iostream>
using namespace std;

// Direction
// 1: 증가하는 방향
// 2: 감소하는 방향
int dp(int idx, vector<int> input_arr, int memo[], int direction = 1) {
    int target = input_arr[idx];

    if (memo[idx] != 0) {
        return memo[idx];
    }

    int result = 0;
    for (int i = idx - 1; i >= 0; i--) {
        if (direction == 1 && input_arr[i] >= target) {
            continue;
        }
        if (direction == 2 && input_arr[i] <= target) {
            continue;
        }

        result = max(result, dp(i, input_arr, memo, direction));
    }

    memo[idx] = result + 1;
    return memo[idx];
}

int main() {
    int n = 0;
    cin >> n;

    vector<int> input_arr;
    int memo[100] = {0, };

    for (int i = 0; i < n; i++) {
        int input_num = 0;
        cin >> input_num;
        input_arr.push_back(input_num);
    }

    for (int i = 0; i < n; i++) {
        dp(i, input_arr, memo, 2);
    }

    for (int i = 0; i < n; i++) {
        cout << memo[i] << ' ';
    }
}