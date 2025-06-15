#include <iostream>
using namespace std;

class Stack {
private:
    int TOP;
    int *A;
    int MAX;

public:
    Stack(int n) {
        TOP = -1;
        MAX = n;
        A = (int*)malloc(sizeof(int) * MAX);
    }

    int PUSH(int ele) {
        if (TOP < MAX - 1) {
            TOP++;
            A[TOP] = ele;
            return 1; // success
        } else {
            return -1; // overflow
        }
    }

    int POP() {
        if (TOP > -1) {
            int ele = A[TOP];
            TOP--;
            return ele;
        } else {
            return -1; // underflow
        }
    }

    void display() {
        for (int i = 0; i <= TOP; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }

    int TopOfStack() {
        return A[TOP];
    }

    int isEmpty() {
        return TOP == -1;
    }

    int isFull() {
        return TOP == MAX - 1;
    }

    ~Stack() {
        free(A);
    }
};

// Main function to demonstrate the Stack
int main() {
    Stack s(100);

    s.PUSH(10);
    s.PUSH(13);
    s.PUSH(5);

    s.display(); // optional, shows stack elements

    cout << "Popped: " << s.POP() << endl;

    return 0;
}
