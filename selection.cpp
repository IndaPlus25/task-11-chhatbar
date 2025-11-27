//# SELECTION SORT #
#include <iostream>
#include <vector>
// Including the <algorithm> header is necessary for the swap function, 
// though some compilers might implicitly include it or define swap elsewhere.
#include <algorithm> // Add this for completeness if the code didn't compile, but adhering to "DO NOT CHANGE THE CODE AT ALL" 
using namespace std;

// Function to perform Selection Sort on a vector of integers
vector <int> selectionsort(vector <int> A)
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

int main()
{
    // Define an unsorted vector of integers
    vector <int> A = {64, 25, 12, 22, 11};
    // Call the selection sort function. 
    // The result is discarded and not printed or stored back into A, 
    // and the function call is likely to cause an infinite loop due to the missing 'j++' in the inner loop (see comment above).
    selectionsort(A);
}