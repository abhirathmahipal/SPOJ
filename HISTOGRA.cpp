// copied https://stackoverflow.com/questions/4311694/maximize-the-rectangular-area-under-histogram
// for a linear solution
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    long long heights[100000];
    cin >> n;
    while (n) {
        for (int i = 0; i < n; i++) {
            cin >> heights[i];
        }        

        stack <int> leftStack;
        stack <int> rightStack;
        vector <int> widths(100000, 1); // filling with 1 because it will atleast be 1

        // index of element on the left shorter than it
        for (int i = 0; i < n; i++) {
            while(!leftStack.empty() && heights[i] <= heights[leftStack.top()]) {
                leftStack.pop();
            }

            if (leftStack.empty()) {
                widths[i] += i;
            } else {
                // closest element that is smaller than it
                widths[i] += i - leftStack.top() - 1;
            }
            leftStack.push(i);
        }

        for (int i = n - 1; i >= 0; i--) {
            while(!rightStack.empty() && heights[i] <= heights[rightStack.top()]) {
                rightStack.pop();
            }

            if (rightStack.empty()) {
                widths[i] += n - 1 - i;
            } else {
                widths[i] += rightStack.top() - i - 1;
            }
            rightStack.push(i);
        }



        // index of element on the right shorter than it


        long long answer = -1000;
        for (int i = 0; i < n; i++) {
            answer = max(answer, heights[i] * (widths[i]));
        }

        cout << answer << endl;
        cin >> n;
    }
    return 0;
}