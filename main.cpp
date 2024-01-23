#include <iostream>

using namespace std;

class List {
public:
    virtual void insert(int value) = 0;
    virtual int remove() = 0;
    virtual void display() const = 0;
    virtual ~List() {}
};

class Stack : public List {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* top;

public:
    Stack() : top(nullptr) {}

    void insert(int value) override {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    int remove() override {
        if (top == nullptr) {
            cerr << "Stack underflow!\n";
            return -1; 
        }

        Node* temp = top;
        int value = temp->data;
        top = top->next;
        delete temp;
        return value;
    }

    void display() const override {
        Node* current = top;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }

    ~Stack() override {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

class Queue : public List {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void insert(int value) override {
        Node* newNode = new Node(value);
        if (rear == nullptr) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int remove() override {
        if (front == nullptr) {
            cerr << "Queue underflow!\n";
            return -1; 
        }

        Node* temp = front;
        int value = temp->data;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr; 
        }
        delete temp;
        return value;
    }

    void display() const override {
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }

    ~Queue() override {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr; 
    }
};

int main() {
    Stack stack;
    Queue queue;

    for (int i = 1; i <= 5; ++i) {
        stack.insert(i);
        queue.insert(i);
    }

    cout << "Stack: ";
    stack.display();
    cout << "Removed from stack: " << stack.remove() << "\n";
    cout << "Stack after removal: ";
    stack.display();

    cout << "Queue: ";
    queue.display();
    cout << "Removed from queue: " << queue.remove() << "\n";
    cout << "Queue after removal: ";
    queue.display();

    return 0;
}
