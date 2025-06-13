#include <iostream>
#include <cstdlib>  // for malloc

using namespace std;

class Array {
private:
    int *A;
    int n;

public:
    Array() {
        A = nullptr;
        n = 0;
    }

    void create(int size) {
        A = (int *)malloc(sizeof(int) * size);
        n = 0;
    }

    void insert(int ele, int index) {
        for (int j = n; j > index; j--) {
            A[j] = A[j - 1];
        }
        A[index] = ele;
        n = n + 1;
    }

    int search(int ele) {
        for (int i = 0; i < n; i++) {
            if (A[i] == ele)
                return i;
        }
        return -1;
    }

    void deleteAt(int index) {
        for (int j = index; j < n - 1; j++) {
            A[j] = A[j + 1];
        }
        n = n - 1;
    }

    void display() {
        for (int i = 0; i < n; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Array X;
    X.create(10);         // Allocate space for 10 elements
    X.insert(5, 0);       // Insert 5 at index 0
    X.insert(7, 1);       // Insert 7 at index 1
    X.insert(9, 2);       // Insert 9 at index 2

    cout << "Array contents:\n";
    X.display();

    int pos = X.search(7);
    if (pos != -1)
        cout << "Element 7 found at index " << pos << endl;
    else
        cout << "Element 7 not found\n";

    X.deleteAt(1);  // Delete element at index 1
    cout << "After deletion:\n";
    X.display();

    return 0;
}
