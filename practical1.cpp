#include <iostream>
#include <string>
#include <cctype>
using namespace std;

#define MAX 100

// Stack implementation using array
class Stack {
private:
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    // Push an element
    void push(int value) {
        if (top == MAX - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = value;
    }

    // Pop an element
    int pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }
};

// Perform arithmetic operation
int operation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '%': return a % b;
        default:
            cout << "Invalid operator\n";
            return 0;
    }
}

// Evaluate postfix expression
int evaluatePostfix(string expression) {
    Stack s;

    for (char ch : expression) {

        // If operand, push it onto stack
        if (isdigit(ch)) {
            s.push(ch - '0');
        }

        // If operator, pop two operands
        else if (ch == '+' || ch == '-' || ch == '*' ||
                 ch == '/' || ch == '%') {

            int b = s.pop();
            int a = s.pop();

            int result = operation(a, b, ch);

            s.push(result);
        }
    }

    return s.pop();
}

int main() {
    string postfix;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);

    cout << "Result = " << result << endl;

    return 0;
}
