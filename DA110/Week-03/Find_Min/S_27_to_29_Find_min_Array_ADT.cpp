#include <iostream>
using namespace std;

class Array {
private:
    int *A;
    int size;   // total allocated size
    int n;      // current number of elements

public:
    Array(int);                 // Constructor
    int element(int);          // Get element at index
    void insert(int, int);     // Insert element at index
    void remove(int);          // Delete element at index
    void display();            // Display all elements
    ~Array();                  // Destructor
};

// Constructor: Allocates memory
Array::Array(int s) {
    size = s;
    A = new int[size];
    n = 0;
}

// Get element at index i
int Array::element(int i) {
    if (i >= 0 && i < n)
        return A[i];
    else {
        cout << "Invalid index.\n";
        return -1;
    }
}

// Insert element at index i
void Array::insert(int ele, int i) {
    if (i >= 0 && i <= n && n < size) {
        for (int j = n; j > i; j--)
            A[j] = A[j - 1];
        A[i] = ele;
        n++;
    } else {
        cout << "Insertion failed.\n";
    }
}

// Delete element at index i
void Array::remove(int i) {
    if (i >= 0 && i < n) {
        for (int j = i; j < n - 1; j++)
            A[j] = A[j + 1];
        n--;
    } else {
        cout << "Deletion failed.\n";
    }
}

// Display all elements
void Array::display() {
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
}

// Destructor: Frees memory
Array::~Array() {
    delete[] A;
}


int main() {
    int n;
    cout << "What is the size of the collection? - ";
    cin >> n;

    // Create Array object with capacity >= n
    Array data(n);

    int ele, i;

    // Read n elements into the array
    cout << "Enter " << n << " elements:" << endl;
    for (i = 0; i < n; i++) {
        cin >> ele;
        data.insert(ele, i);  // Insert at the end (index i)
    }

    // Display the array
    cout << "You entered: ";
    data.display();

    // Find the minimum element in the array
    int min = data.element(0);
    for (i = 1; i < n; i++) {
        if (min > data.element(i))
            min = data.element(i);
    }

    // Output the minimum
    cout << "Minimum element is: " << min << endl;

    return 0;
}

