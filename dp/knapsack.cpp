#include <iostream>
using namespace std;

struct Jewel {
    int weight;
    int price;
};

Jewel createJewel(int weight, int price) {
    Jewel jewel;
    jewel.price = price;
    jewel.weight = weight;

    return jewel;
}

int dp(int i, int j, vector<Jewel> jewel_list, vector< vector<int> > &memo) {
    if (i < 0 || j < 0) {
        return 0;
    }

    if (j == 0) {
        memo[i][j] = 0;
        return memo[i][j];
    }

    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    int maximum = -1;
    
    // i번 째 보석을 가져갔을 경우
    if (j >= jewel_list[i].weight) {
        // i값이 0이고 무게가 딱 맞다면 그 무게가 maximum
        if (i - 1 < 0 && j - jewel_list[i].weight == 0) {
            maximum = jewel_list[i].price;

        // i - 1이 인덱스 범위 안에 들어있을 경우
        // 
        } else if (i - 1 >= 0) {
            int total_price_with_i = dp(i - 1, j - jewel_list[i].weight, jewel_list, memo);

            // -1이 나온 경우는 해당 금액을 딱 만족할 경우의 수가 없다는 의미
            if (total_price_with_i != -1) { 
                maximum = max(maximum, total_price_with_i + jewel_list[i].price);
            }        
        }
    }

    // i번 째 보석을 가져가지 않았을 경우
    if (i - 1 >= 0) {
        int total_price_without_i = dp(i - 1, j, jewel_list, memo);

        // -1이 나온 경우는 해당 금액을 딱 만족할 경우의 수가 없다는 의미
        if (total_price_without_i != -1) {
            maximum = max(maximum, total_price_without_i);
        }
    }

    memo[i][j] = maximum;
    return memo[i][j];
}

int main() {
    int n = 20;

    vector<Jewel> jewel_list;

    jewel_list.push_back(createJewel(2, 3));
    jewel_list.push_back(createJewel(6, 5));
    jewel_list.push_back(createJewel(2, 4));
    jewel_list.push_back(createJewel(3, 2));
    jewel_list.push_back(createJewel(4, 3));
    jewel_list.push_back(createJewel(5, 3));
    jewel_list.push_back(createJewel(4, 2));
    jewel_list.push_back(createJewel(6, 6));
    jewel_list.push_back(createJewel(7, 9));
    jewel_list.push_back(createJewel(10, 8));

    vector< vector<int> > memo;
    for (int i = 0; i < jewel_list.size(); i++) {
        vector<int> temp_vector;
        for (int j = 0; j <= n; j++) {
            temp_vector.push_back(-1);
        }

        memo.push_back(temp_vector);
    }

    for (int i = 0; i < jewel_list.size(); i++) {
        for (int j = 0; j <= n; j++) {
            dp(i, j, jewel_list, memo);
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j <= n; j++) {
            cout.width(3);
            cout << memo[i][j] << ' ';
        }
        cout << '\n';
    }
}