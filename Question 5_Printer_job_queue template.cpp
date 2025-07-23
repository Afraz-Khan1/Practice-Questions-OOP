#include<iostream>
#include<string>
using namespace std;

// Abstract class
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

// Queue class
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

    bool isFull() { return count == capacity; }
    bool isEmpty() { return count == 0; }
    int size() { return count; }

    T Front() {
        if (!isEmpty()) return arr[front];
        throw runtime_error("Queue is empty");
    }

    T Rear() {
        if (!isEmpty()) return arr[rear];
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
            cout << "Queue Underflow\n";
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

// Simulating print job system
int main() {
    Queue<string> printQueue;
    int totalJobs;
    cout << "Enter number of print jobs: ";
    cin >> totalJobs;

    cin.ignore();  // ignore newline left in buffer

    // Enqueue all print jobs
    for (int i = 1; i <= totalJobs; ++i) {
        string job;
        cout << "Enter name of print job " << i << ": ";
        getline(cin, job);
        printQueue.enqueue(job);
        cout << "Job '" << job << "' added to the queue.\n";
    }

    cout << "\n--- Starting print jobs ---\n";

    // Simulate printing
    while (!printQueue.isEmpty()) {
        string currentJob = printQueue.Front();
        cout << "Printing: " << currentJob << "...\n";
        printQueue.dequeue();
    }

    cout << "All print jobs completed. Printer is now idle.\n";
    return 0;
}