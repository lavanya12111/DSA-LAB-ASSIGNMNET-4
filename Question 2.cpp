#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
    int items[SIZE], front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int element) {
        if (isFull()) {
            cout << "Queue is Full!\n";
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        items[rear] = element;
        cout << "Inserted: " << element << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!\n";
            return -1;
        }
        int element = items[front];
        if (front == rear) { // Reset queue when last element is removed
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % SIZE;
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
        cout << "Circular Queue elements: ";
        int i = front;
        while (true) {
            cout << items[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq;
    int choice, val;
    do {
        cout << "\n--- Circular Queue Menu ---\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Check Empty\n5. Check Full\n6. Display\n7. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; cq.enqueue(val); break;
            case 2: val = cq.dequeue(); if(val != -1) cout << "Dequeued: " << val << endl; break;
            case 3: val = cq.peek(); if(val != -1) cout << "Front element: " << val << endl; break;
            case 4: cout << (cq.isEmpty() ? "Queue is Empty\n" : "Queue is not Empty\n"); break;
            case 5: cout << (cq.isFull() ? "Queue is Full\n" : "Queue is not Full\n"); break;
            case 6: cq.display(); break;
        }
    } while (choice != 7);
    return 0;
}
