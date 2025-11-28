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

int main()
{
    // Define an unsorted vector of integers
    vector <int> A = {5, 2, 9, 1, 5, 6};
    // Call the insertion sort function on vector A. 
    A = insertionSort(A);

    for (auto x : A)
    {
        cout << x << " ";
    }
}