#include <iostream>
#include <vector>

using namespace std;

int main() {
    string input;
    cin >> input;
    int problem_number = 1;
    while(input[0] != '-') {
        int count = 0;
        int moves_individual = 0;
        for (int i = 0;input[i] != '\0'; i++) {
            char ch = input[i];
            if (ch == '{') {
                count++;
            } else if (ch == '}') {
                if (count == 0) {
                    // This has to be changed, so let's change it
                    moves_individual++;
                    count++;
                } else {
                    count--;
                }
            }
        }

        moves_individual += count / 2;

        cout << problem_number << ". " << moves_individual << endl;
        cin >> input;
        problem_number++;
    }
}