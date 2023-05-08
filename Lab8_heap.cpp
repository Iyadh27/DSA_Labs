#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// function to heapify the subtree rooted at node- root
void heapify(int arr[], int n, int root)
{
    int Greatest = root; // initialize biggest as the root because 0 is the starting index
    int Left = 2*root + 1; // left child of node
    int Right = 2*root + 2; // right child of node

    // if left child greater than root node
    if (Left < n && arr[Left] > arr[Greatest])
        Greatest = Left;

    // if right child greater than everything till now
    if (Right < n && arr[Right] > arr[Greatest])
        Greatest = Right;

    // if greatest isnt root
    if (Greatest != root)
    {
        swap(arr[root], arr[Greatest]);

        // recursively heapify sub-tree
        heapify(arr, n, Greatest);
    }
}

// function to implement heap sort
void heapSort(int arr[], int n)
{
    // build heap by rearranging the array
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // extracting elements from heap one by one
    for (int i = n - 1; i >= 0; i--)
    {
        // move current root to the end
        swap(arr[0], arr[i]);

        // now calling max heapify for reduced heap 
        heapify(arr, i, 0);
    }
}

// print contents of array 
void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// main program
int main()
{
    int n;

    // get user input for array size preffered
    cout << "Enter size of array: ";
    cin >> n;

//create heap array of size n
    int heap_arr[n];

   
// get user input for array values
    cout << "Enter array values:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "arr[" << i << "]: ";
        cin >> heap_arr[i];
    }

    cout << "Input array:" << endl;
    displayArray(heap_arr, n);

    heapSort(heap_arr, n);

    cout << "Sorted array:" << endl;
    displayArray(heap_arr, n);

    return 0;
}
