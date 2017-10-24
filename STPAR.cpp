#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int main() {
    int count; 
    cin >> count;

    while(count) {
        int numbers[count + 1];
        stack <int> street;
        for (int i = 1; i <= count; i++) {
            cin >> numbers[i];
        }

        int i;
        int count_required = 1;
        for (i = 1; i <= count;) {
            if (count_required != numbers[i]) {
                if (street.size() && street.top() == count_required) {
                    street.pop();
                    count_required++;
                } else {
                    street.push(numbers[i]);
                    i++;
                }
            }
            else {
                count_required++;
                i++;
            }
        }

        // emptying street stack
        while (street.size()) {
            if (street.top() == count_required) {
                street.pop();
                count_required++;
            }
            else break;
        }
        if (count_required < count) cout << "no\n";
        else cout << "yes\n";


        cin >> count;
    }



}