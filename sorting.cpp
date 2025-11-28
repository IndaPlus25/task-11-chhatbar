//# INSERTION SORT #
#include <iostream>
#include <vector>
using namespace std;

// Function to perform Insertion Sort on a vector of integers
vector <int> insertionSort(vector <int> A)
{
// Initialize the loop counter 'i'. The outer loop iterates from the second element (index 1) 
// up to the end of the array, separating the sorted part (left) from the unsorted part (right).
int i = 1;
while (i < A.size()) 
{
    // Store the value of the current element A[i] to be inserted into the sorted subarray
    int x = A[i];
    // Initialize the pointer 'j' to the last element of the sorted subarray (A[0] to A[i-1])
    int j = (i-1);

    // Inner loop: Check elements in the sorted subarray (from right to left)
    // Shift elements greater than 'x' one position to the right
    while (j >= 0 && A[j] > x) 
    {
        // Shift A[j] to the position A[j+1]
        A[j+1] = A[j];
        // Decrement j to compare 'x' with the next element to the left
        j--;
    }
    // 'j+1' is the correct position for 'x' (the element being inserted) 
    // because A[j] is now less than or equal to 'x', or 'j' is -1.
    A[j+1] = x;
    // Move to the next element in the unsorted part
    i++;
}
return A; // Return the fully sorted vector
}

// Function to merge two already sorted vectors, A and B, into a single sorted vector C.
vector <int> merge(vector <int> A, vector <int> B)
{
    vector <int> C; // Initialize the resulting merged vector

    // Step 1: Compare the front elements of A and B and append the smaller one to C.
    // This loop continues as long as both vectors have elements.
    while (A.size() > 0 && B.size() > 0)
    {
        // If the front element of A is greater than the front element of B
        if (A[0] > B[0])
        {
            // Append the smaller element (from B) to C
            C.push_back(B[0]);
            // Remove the element from the front of B
            // Note: Erasing the first element (A.begin() + 0) is inefficient (O(N)), 
            // but it follows the logic of consuming the elements one by one.
            B.erase(B.begin() + 0);  
        }
        else // A[0] <= B[0]
        {
            // Append the smaller element (from A) to C
            C.push_back(A[0]);
            // Remove the element from the front of A
            A.erase(A.begin() + 0);
        }
    }
    
    // Step 2: Append any remaining elements from vector A (if B is empty)
    while (A.size() > 0)
    {
        C.push_back(A[0]);
        A.erase(A.begin() + 0);
    }
    
    // Step 3: Append any remaining elements from vector B (if A is empty)
    while (B.size() > 0)
    {
        C.push_back(B[0]); 
        B.erase(B.begin() + 0);
    }
    
    return C; // Return the new sorted and merged vector
}

// Recursive function to perform the Top-Down Merge Sort.
vector <int> mergeSort(vector <int> A)
{
    // Base Case: If the vector has only one element, it is already sorted.
    if (A.size() == 1)
    {
        return A;
    } 
    
    // Step 1: Divide the vector A into two halves: 'left' and 'right'.
    vector <int> left;
    // Copy the first half of A (from index 0 up to, but not including, the midpoint) into 'left'.
    for (int i = 0; i < A.size()/2; i++)
    {
        left.push_back(A[i]);
    }
    
    vector <int> right;
    // Copy the second half of A (from the midpoint to the end) into 'right'.
    for (int i = A.size()/2; i < A.size(); i++)
    {
        right.push_back(A[i]);
    }

    // Step 2: Recursively sort the two halves.
    left = mergeSort(left);
    right = mergeSort(right);

    // Step 3: Combine the two sorted halves using the merge function.
    return merge(left, right);
}

int partition(vector<int> arr, int low, int high) {
  
    // choose the pivot
    int pivot = arr[high];
  
    // index of smaller element and indicates 
    // the right position of pivot found so far
    int i = low - 1;

    // Traverse arr[low..high] and move all smaller
    // elements on left side. Elements from low to 
    // i are smaller after every iteration
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    // move pivot after smaller elements and
    // return its position
    swap(arr[i + 1], arr[high]);  
    return i + 1;
}

// the quickSort function implementation
void quickSort(vector<int>& arr, int low, int high) {
  
    if (low < high) {
      
        // pi is the partition return index of pivot
        int pi = partition(arr, low, high);

        // recursion calls for smaller elements
        // and greater or equals elements
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


vector <int> selectionSort(vector <int> A)
{
// Initialize the index 'i'. The outer loop iterates through the entire list 
// (or up to the second-to-last element, as the last element will be sorted by then).
int i  = 0;

// Outer loop: iterates through the unsorted portion of the array.
// 'i' marks the beginning of the unsorted segment.
while (i < A.size()-1)
{
    // Assume the current element at 'i' is the minimum in the unsorted segment.
    int minIndex = i;
    // Initialize 'j' to start searching from the element after 'i'.
    int j = i + 1;
    
    // Inner loop: searches for the actual minimum element in the unsorted segment (A[i+1] to A[end]).
    while (j < A.size())
    {
        // If an element smaller than the current minimum is found
        if (A[j] < A[minIndex])
        {
            // Update the index of the minimum element found so far
            minIndex = j;
        }
        // Move to the next element in the unsorted segment
        j++;
    }

    // After the inner loop finishes (or, in this code, potentially infinite loops if A.size() > 0 and 'j' is not incremented),
    // compare if a new minimum was found.
    if (minIndex != i)
    {
        // Swap the element at the current position 'i' with the actual minimum element found at 'minIndex'.
        // This places the smallest element into its correct sorted position.
        swap(A[i], A[minIndex]); 
    }
    // Move the boundary of the sorted segment one step to the right.
    i++;
}
return A; // Return the sorted vector
}
