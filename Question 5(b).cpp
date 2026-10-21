#include <iostream>
#include <queue>
using namespace std;

class StackUsingOneQueue {
    queue<int> q;

public:
    void push(int x) {
        int size = q.size();
        q.push(x);
     
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) return;
        q.pop();
    }

    int top() {
        if (q.empty()) return -1;
        return q.front();
    }
};

int main() {
    StackUsingOneQueue s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top element (One Queue implementation): " << s.top() << endl; // Should be 30
    s.pop();
    cout << "Top element after pop: " << s.top() << endl; // Should be 20
    return 0;
}
