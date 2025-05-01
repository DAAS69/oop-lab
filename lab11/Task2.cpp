#include <iostream>
#include <exception>
using namespace std;

class StackOverflowException : public exception {
public:
    const char* what() const noexcept override {
        return "StackOverflowException - Stack is full!";
    }
};

class StackUnderflowException : public exception {
public:
    const char* what() const noexcept override {
        return "StackUnderflowException - Stack is empty!";
    }
};

template <typename T>
class Stack {
private:
    T data[5];
    int top;
public:
    Stack() {
        top = -1;
    }

    void push(T value) {
        if (top >= 4) {
            throw StackOverflowException();
        }
        data[++top] = value;
    }

    T pop() {
        if (top < 0) {
            throw StackUnderflowException();
        }
        return data[top--];
    }
};

int main() {
    Stack<int> s;

    try {
        for (int i = 0; i < 6; i++) {
            s.push(i);
            cout << "Pushed: " << i << endl;
        }
    } 
    
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    try {
        for (int i = 0; i < 6; i++) {
            int value = s.pop();
            cout << "Popped: " << value << endl;
        }
    } 
    
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
