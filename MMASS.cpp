#include <iostream>
#include <stack>
#include <map>
#include <vector>
#include <cstdio>
// #include <cstdlib>

using namespace std;

int atoi (char input) {
    int temp = input - 48;
    return temp;
}
int main() {
    // I am basically growing a stack.
    // If a ( is encountered, I fill in a new spot in an array for it and set it to zeros
    // I keep adding to the  new spot the weights until ) is encountered. On that point I transer the weight
    // to the previous spot as if there's another bracket open before it, it will contain this sub bracket as well
    // If ) indicated the end of the first bracket ever encountered, it's weight will be transfered to spot[0]

    // so the 0th position is for the general space if you want to call it that.
    // each bracket has a spot starting from 1..100, so we don't need a special case for 
    // things outside the bracket.
    
    // when evrything's transfered to the previous element, position 0 will by default have the sum :)
    map <char, int> weights;
    weights.insert(make_pair('H', 1));
    weights.insert(make_pair('C', 12));
    weights.insert(make_pair('O', 16));
    int unit_position = 0;
    string input;
    vector <int> track_of(101, 0); // 0 is for stuff outside the bracket or general space
    cin >> input;
    int weight = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '(') {
            unit_position++;
            track_of[unit_position] = 0;
        } else if(input[i] == ')') {
            int temp = track_of[unit_position--];
            if (input[i + 1] != '\0' && isdigit(input[i + 1])) {
                int foo = atoi(input[i+1]) * temp;
                track_of[unit_position] += foo;
                // cout << "transfered weight of " << foo << " from unit " << unit_position + 1 << " to " << unit_position;
                i++;
            } else {
                track_of[unit_position] += temp;
                // cout << "transfered weight of " << temp << " from unit " << unit_position + 1 << " to " << unit_position;
            }
        } else if(isdigit(input[i])) {
            char prev = input[i - 1];
            if (isalpha(prev)) {
                track_of[unit_position] += (atoi(input[i]) - 1) * weights[prev]; // reducing one cuz we already would have added it once
            }
        } else if (isalpha(input[i])) {
            track_of[unit_position] += weights[input[i]];
        }
    }

    cout << track_of[0] << endl;

    return 0;
}