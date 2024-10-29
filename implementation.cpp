#include <bits/stdc++.h>

using namespace std;

class minHeadp {
private:
    int *arr;
    int size;
    int capacity;

public:
    // Constructor should be public
    minHeadp(int x) {
        arr = new int[x];
        size = 0;
        capacity = x;
    }

    ~minHeadp() {
        delete[] arr; // Destructor to free allocated memory
    }

    int left(int i) {
        return (2 * i + 1);
    }

    int right(int i) {
        return (2 * i + 2);
    }

    int parent(int i) {
        return (i - 1) / 2;
    }

    void insert(int x) {
        if (size == capacity) {
            return; // Avoid inserting if heap is full
        }

        size++;
        arr[size - 1] = x;

        for (int i = size - 1; i != 0 && arr[i] < arr[parent(i)];) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void minheapify(int index) {
        int lf = left(index);
        int rt = right(index);
        int smallest = index;

        if (lf < size && arr[lf] < arr[smallest]) {
            smallest = lf;
        }

        if (rt < size && arr[rt] < arr[smallest]) { // Corrected from rf to rt
            smallest = rt;
        }

        if (smallest != index) {
            swap(arr[index], arr[smallest]);
            minheapify(smallest);
        }
    }

    int extractMin() {
        if (size == 0) {
            return INT_MIN;
        }

        if (size == 1) {
            size--;
            return arr[0];
        }

        int minVal = arr[0]; // Store the minimum value to return
        arr[0] = arr[size - 1]; // Move last element to root
        size--;
        minheapify(0); // Heapify the root
        return minVal; // Return the minimum value
    }

    void decreaseKey(int i, int x) {
        if (i >= size) return; // Index out of bounds
        arr[i] = x;

        while (i != 0 && arr[i] < arr[parent(i)]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void deleteKey(int i) {
        decreaseKey(i, INT_MIN);
        extractMin();
    }

    void buildHeap() {
        for (int i = (size - 2) / 2; i >= 0; i--) {
            minheapify(i);
        }
    }

    void heapsort() {
        buildHeap(); // Build the heap first
        for (int i = size - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            size--; // Reduce the heap size
            minheapify(0); // Heapify the root
        }
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl; // Print new line after printing array
    }
};

int main() {
    minHeadp h(10);
    h.insert(1);
    h.insert(2);
    h.insert(10);
    h.insert(9);
    h.insert(5);
    h.insert(3);
    h.insert(4);
    h.insert(6);
    h.insert(7);
    h.insert(8);
    h.heapsort();
    h.print();

    return 0;
}
