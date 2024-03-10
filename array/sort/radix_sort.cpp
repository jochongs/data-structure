#include <iostream>
using namespace std;

int square(int num, int size) {
    if (size == 0) {
        return 1;
    }

    for (int i = 0; i < size - 1; i++) {
        num *= 10;
    }

    return num;
}

void radix_sort(int arr[], int size, int k) {
    for (int i = 0; i < k; i++) {   
        int new_arr[10][100000] = {0, };
        int idx_arr[10] = {0, };
        
        for (int j = 0; j < size; j++) {
            int num = arr[j] % square(10, i + 1) / square(10, i);

            new_arr[num][idx_arr[num]] = arr[j];
            idx_arr[num]++;
        }

        int idx = 0;
        for (int i = 0; i < 10; i ++) {
            int j = 0;
            while (true) {
                if (new_arr[i][j] == 0) {
                    break;
                }

                arr[idx] = new_arr[i][j];
                j++;
                idx++;
            }
        }
    }
}

int main() {
    int arr[100000] = {0, };

    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    radix_sort(arr, n, 6);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
}