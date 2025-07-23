#include<iostream>
using namespace std;
template <class T>
class DynamicArray {
public:
    virtual bool isFull() = 0;
    virtual bool isEmpty() = 0;
    virtual int size() = 0;
    virtual T Front() = 0;
    virtual T Rear() = 0;
    virtual void enqueue(T val) = 0;
    virtual void dequeue() = 0;
    virtual void resize() = 0;
    virtual ~DynamicArray() {} 
};
template <class T>
class Queue : public DynamicArray<T> {
    T* arr;
    int capacity;
    int front, rear, count;
public:
    Queue(int cap = 5) {
        capacity = cap;
        arr = new T[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }
    bool isFull() {
        return count == capacity;
}
    bool isEmpty() {
        return count == 0;
     }
    int size() {
        return count;
     }
    T Front() {
        if (!isEmpty())
            return arr[front];
        throw runtime_error("Queue is empty");
    }

    T Rear() {
        if (!isEmpty())
            return arr[rear];
        throw runtime_error("Queue is empty");
}
    void enqueue(T val) {
        if (isFull()) resize();
        rear = (rear + 1) % capacity;
        arr[rear] = val;
        count++;
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return;
        }
        front = (front + 1) % capacity;
        count--;
    }

    void resize() {
        int newCap = capacity * 2;
        T* temp = new T[newCap];

        for (int i = 0; i < count; ++i)
            temp[i] = arr[(front + i) % capacity];

        delete[] arr;
        arr = temp;
        capacity = newCap;
        front = 0;
        rear = count - 1;
    }

    ~Queue() {
        delete[] arr;
    }
};
int main() {
    Queue<int> q(3);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40); 

    cout << "Front: " << q.Front() << endl;
    cout << "Rear: " << q.Rear() << endl;

    q.dequeue();
    cout << "After dequeue, Front: " << q.Front() << endl;

    cout << "Size: " << q.size() << endl;

    return 0;
}