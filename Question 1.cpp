#include <iostream>
using namespace std;

#define SIZE 5

class SimpleQueue {
    int items[SIZE], front, rear;

public:
    SimpleQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == SIZE - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is Full!\n";
            return;
        }
        if (front == -1) front = 0;
        rear++;
        items[rear] = element;
        cout << "Inserted: " << element << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return -1;
        }
        int element = items[front];
        front++;
        if (front > rear) { // Reset queue when empty
            front = -1;
            rear = -1;
        }
        return element;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return -1;
        }
        return items[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
            cout << items[i] << " ";
        cout << endl;
    }
};

int main() {
    SimpleQueue q;
    int choice, val;
    do {
        cout << "\n--- Simple Queue Menu ---\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Check Empty\n5. Check Full\n6. Display\n7. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; q.enqueue(val); break;
            case 2: val = q.dequeue(); if(val != -1) cout << "Dequeued: " << val << endl; break;
            case 3: val = q.peek(); if(val != -1) cout << "Front element: " << val << endl; break;
            case 4: cout << (q.isEmpty() ? "Queue is Empty\n" : "Queue is not Empty\n"); break;
            case 5: cout << (q.isFull() ? "Queue is Full\n" : "Queue is not Full\n"); break;
            case 6: q.display(); break;
        }
    } while (choice != 7);
    return 0;
}
