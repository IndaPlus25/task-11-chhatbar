//# MERGE SORT (top-down) #
#include <iostream>
#include <vector>
using namespace std;

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

int main()
{
    // Define an unsorted vector of integers
    vector <int> A = {38, 27, 43, 3, 9, 82, 10};
    // Call the mergeSort function and store the resulting sorted vector back into A.
    A = mergeSort(A);
    // After this line, vector A will be sorted: {3, 9, 10, 27, 38, 43, 82}
    for (auto x : A)
    {
        cout << x << " ";
    }
}