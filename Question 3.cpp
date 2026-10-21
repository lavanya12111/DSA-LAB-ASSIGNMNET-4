#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void interleaveQueue(queue<int>& q) {
    if (q.size() % 2 != 0) {
        cout << "Queue size must be even!\n";
        return;
    }

    stack<int> s;
    int halfSize = q.size() / 2;

    for (int i = 0; i < halfSize; i++) {
        s.push(q.front());
        q.pop();
    }


    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    
    for (int i = 0; i < halfSize; i++) {
        q.push(q.front());
        q.pop();
    }

    for (int i = 0; i < halfSize; i++) {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    int arr[] = {4, 7, 11, 20, 5, 9};
    for (int x : arr) q.push(x);

    interleaveQueue(q);

    cout << "Interleaved Output: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}
