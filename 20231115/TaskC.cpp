#include <iostream>
#include <ctime>

using namespace std;

void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void insertion_sort(int data[], int data_size) {
    int i, j;

    for (i = 1; i < data_size; i++) {
        j = i;
        while ((j > 0) && (data[j - 1] > data[j])) {
            swap(&data[j - 1], &data[j]);
            j--;
        }
    }
}

int binary_search(int data[], int data_size, int target) {
    int left = 0;
    int right = data_size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (data[mid] == target) {
            return mid; 
        } else if (data[mid] < target) {
            left = mid + 1; 
        } else {
            right = mid - 1;
        }
    }

    return -1;  
}

int main() {
    int data[100];
    int i, target;
    srand(static_cast<unsigned int>(time(NULL)));

    for (i = 0; i < 100; i++) {
        data[i] = (rand() % 100) + 1;
        cout << data[i] << " ";
    }

    cout << endl;

    insertion_sort(data, 100);
    cout << "Sorted Data:" << endl;
    for (i = 0; i < 100; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
    
    cout << "target value to search is 50: " << endl;
    target = 50;

    int result = binary_search(data, 100, target);

    if (result >= 0) {
        cout << "Target found at index: " << result << endl;
    } else {
        cout << "Target not found in the data." << endl;
    }
    
    return 0;
}
