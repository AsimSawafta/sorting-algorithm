#include <iostream>
#include <ctime>  // For time()
#include <chrono>
using namespace std;
using namespace std::chrono;
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}


/////////////////////////

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
}

////////////////////////

void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(arr[min_idx], arr[i]);
    }
}

//////////////////
void merge(int arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1], R[n2]; // Temporary arrays

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

///////////////////////



int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // choosing the last element as pivot
    int i = low - 1;  // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++;    // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        /* pi is partitioning index, arr[pi] is now at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


////////////////////////////////////////
 void RandomArray(int arr[], int size) {
    srand(time(NULL));  // Seed for random number generation
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;  // Random numbers between 0 and 99
    }
}

void sortArray(int arr[],int size)
{
     for (int i = 0; i < size; i++) {
        arr[i] = i;
    }
}
void PartiallySortedArray(int arr[], int size) {

    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }

    swap(arr[size/2],arr[size-1]);
}


void ReverseArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = size - i - 1;
    }
}


void displayArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


//double measureExecutionTime(void (*sortFunction)(int[], int), int arr[], int size) {
 //   auto start = high_resolution_clock::now(); // Start the timer

  //  sortFunction(arr, size); // Execute the sorting function

  //  auto stop = high_resolution_clock::now(); // Stop the timer

    // Calculate the duration
  //  auto duration = duration_cast<microseconds>(stop - start);

    //return duration.count();
//}
double measureExecutionTime(void (*sortFunction)(int[], int, int), int arr[], int size) {
    auto start = high_resolution_clock::now();
    sortFunction(arr, 0, size - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count();
}
int main() {

    // Setting sizes for small, medium, and large arrays
    const int SMALL_SIZE = 100;
    const int MEDIUM_SIZE = 1500;
    const int LARGE_SIZE =  10000;

    // Declaring arrays
    int smallArray[SMALL_SIZE];
    int mediumArray[MEDIUM_SIZE];
    int largeArray[LARGE_SIZE];

    ReverseArray(largeArray, LARGE_SIZE);
    //PartiallySortedArray(largeArray, LARGE_SIZE);
    //RandomArray(largeArray, LARGE_SIZE);
    //sortArray(largeArray, LARGE_SIZE);
  cout << "Bubble Sort (MEDIUM_SIZE)\nBefore sorting: ";
  displayArray(largeArray, LARGE_SIZE);

  double timeTaken = measureExecutionTime(quickSort, largeArray, LARGE_SIZE);
  cout << "After sorting: \n";
  displayArray(largeArray, LARGE_SIZE);
    cout << "Time taken: " << timeTaken << " microseconds\n";
    return 0;
}


