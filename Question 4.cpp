#include <iostream>
#include <queue>
#include <string>
using namespace std;

void findFirstNonRepeating(string str) {
    queue<char> q;
    int charCount[26] = {0};

    cout << "Output: ";
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        if (ch == ' ') continue; 

        q.push(ch);
        charCount[ch - 'a']++;

       
        while (!q.empty() && charCount[q.front() - 'a'] > 1) {
            q.pop();
        }

        if (q.empty()) {
            cout << "-1 ";
        } else {
            cout << q.front() << " ";
        }
    }
    cout << endl;
}

int main() {
    string input = "a a b c";
    cout << "Input: " << input << endl;
    findFirstNonRepeating(input);
    return 0;
}
