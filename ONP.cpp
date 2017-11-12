#include <stack>
#include <vector>
#include <iostream>
#include <map>

// Referred https://github.com/cacophonix/SPOJ/blob/master/ONP.cpp for the map
using namespace std;
int main() {

    map<char, int> precedence;
    string infix;
    stack <char> operators;
    precedence.insert(pair<char, int> ('(', 0));
    precedence.insert(pair <char, int> ('+', 1));
    precedence.insert(pair <char, int> ('-', 2));
    precedence.insert(pair <char, int> ('*', 3));
    precedence.insert(pair <char, int> ('/', 4));
    precedence.insert(pair <char, int> ('^', 5));

    int length;
    cin >> length;

    while(length--) {
        cin >> infix;

        int i = 0;
        while(infix[i] != '\0') {
            char literal = infix[i];

            if (isalpha(literal)) {
                cout << literal;
            } else if (literal == '+' || literal == '-' || literal == '*' || literal == '/' || literal == '^' || literal == '(') {
                if (literal == '(') operators.push('(');
                else {
                    if (!operators.size()) {
                        operators.push(literal);
                    } else {
                        while(true) {
                            if (!operators.size() || (precedence[literal] >= precedence[operators.top()])) {
                                operators.push(literal);
                                break;
                            } else {
                                cout << operators.top();
                                operators.pop();
                            }
                        }
                    }
                }

            } else if (literal == ')') {
                while (operators.top() != '(') {
                        cout << operators.top();
                        operators.pop();
                }
                operators.pop(); // popping the ( as well
            }


            i++;
        }


        if (length != 0 ) cout << endl;
    }

    return 0;
}