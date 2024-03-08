#include <iostream>
using namespace std;

// 기본 버블 정렬
void bubble_sort(int arr[], int size) {
    int cal_cnt = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            cal_cnt++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "버블정렬 연산 횟수: " << cal_cnt << '\n';
    return;
}

// 개선된 버블정렬
void enhance_bubble_sort(int arr[], int size) {
    int cal_cnt = 0; // 연산 횟수

    for (int i = 0; i < size; i++) {
        // 하나의 순회동안 변경 내역을 확인하기 위한 변수
        bool change_state = false;

        for (int j = 0; j < size - 1 - i; j++) {
            cal_cnt++; 
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                change_state = true;
            }
        }

        // 하나의 순회 동안 변경된 내용이 없다면 이미 정렬이 되었다는 뜻
        if (!change_state) {
            break;
        }
    }

    cout << "개선된 버블정렬 연산 횟수: " << cal_cnt << '\n';
    return;
}

int main() {
    int arr[10] = {0, 10, 9, 3, 4, 5, 1, 2, 200, 300};
    int arr2[10] = {0, 10, 9, 3, 4, 5, 1, 2, 200, 300};

    bubble_sort(arr, 10); // 정렬 연산: 45회
    enhance_bubble_sort(arr2, 10); // 정렬 연산: 39회

    // 버블 정렬
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';

    // 개선된 버블 정렬
    for (int i = 0; i < 10; i++) {
        cout << arr2[i] << ' ';
    }
    cout << '\n';
}