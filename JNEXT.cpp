#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    int t; 
    cin >> t;
    int digits[1000001];
    for (int i = 0; i < t; i++) {
        int length;
        scanf("%d", &length);
        // get all the numbers
        for (int j = 0; j < length; j++){
            scanf("%d", &digits[j]);
        }

        int sort_from = 0;
        int sort_to = length;
        bool possible = false;
        int start_search_from; // time limit exceeding so using this
        // if it's decreasing from start to end it's -1
        for (int j = length - 2; j >= 0; j--) {
            if (digits[j] < digits[j + 1]) {
                possible = true;
                start_search_from = j;
                break;

            }
        }

        if (!possible) {
            printf("-1\n");
            continue;
        }
        // for (int j = start_search_from; j > 0; j--) {
        // for (int j = length - 2; j > 0; j--) {
            int j = start_search_from;
            int pos = 100;
            bool switch_m = false;
            for (int k = length - 1; k > j; k--) {
                if (digits[j] < digits[k]) {
                    pos = k;
                    switch_m = true;
                    break;
                }
            }
            if (switch_m) {
                int temp = digits[j];
                digits[j] = digits[pos];
                digits[pos] = temp;
                sort_from = j + 1;
                sort_to = length;
                // break;
            }     
        // }
        reverse(&digits[sort_from], &digits[sort_to]);
        for (int j = 0; j < length; j++) {
            printf("%d", digits[j]);
        }
        cout << "\n";
    }

    return 0;
}