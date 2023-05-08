#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;


// Partition function to sort array########################
int partition(int arr[], int start, int end){
    int pivot = arr[end];
    int i = start - 1;

    for(int j=start; j<end; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }i++;
     
    swap(arr[i], arr[end]);
    return i;
}

// Recursive QuickSort function##############################
void quickSort(int arr[], int start, int end){
    if(start < end){
        int pivot = partition(arr, start, end);

        quickSort(arr, start, pivot-1);
        quickSort(arr, pivot+1, end);
    }
}

//Iterative quick sort algorithm #############################
void quickSortIterative(int arr[], int start, int end){
    // Create an auxiliary stack
    int stack[end - start + 1];
  
    // initialize top of stack
    int top = -1;
  
    // push initial values of start and end to stack
    stack[++top] = start;
    stack[++top] = end;
  
    // Keep popping from stack while is not empty
    while (top >= 0) {
        // Pop end and start
        end = stack[top--];
        start = stack[top--];
  
        // Set pivot element at its correct position
        // in sorted array
        int p = partition(arr, start, end);
  
        // If there are elements on left side of pivot,
        // then push left side to stack
        if (p - 1 > start) {
            stack[++top] = start;
            stack[++top] = p - 1;
        }
  
        // If there are elements on right side of pivot,
        // then push right side to stack
        if (p + 1 < end) {
            stack[++top] = p + 1;
            stack[++top] = end;
        }
    }
}
int main(){
    int arr[2000]; // Initialize the array with random elements by changing the size of array to our prefference
    for(int i=0; i<2000; i++){
        arr[i] = rand()%1000;
    }

    auto start = high_resolution_clock::now(); // Start the clock
    quickSort(arr, 0,1999);
    auto stop = high_resolution_clock::now(); // Stop the clock

    auto duration = duration_cast<microseconds>(stop - start); // Calculate the duration in microseconds
    cout << "Time taken by quickSort function: " << duration.count() << " microseconds" << endl;
    
    auto start1= high_resolution_clock::now(); // Start the clock
    quickSortIterative(arr,0,999);
    auto stop1= high_resolution_clock::now(); // Stop the clock
    auto duration1= duration_cast<microseconds>(stop1- start1);// Calculate the duration in microseconds
    cout << "Time taken by quickSortIterative: " <<duration1.count() << " microseconds" << endl;
    return 0;
}
