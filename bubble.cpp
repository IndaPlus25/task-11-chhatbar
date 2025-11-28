#include <iostream>
#include <vector>
using namespace std;

vector <int> bubbleSort(vector <int> A)
{
    int n = A.size();
    
    for (int i{0}; i<n-1; i++)
    {
        for (int j{0}; j<n-i-1; j++)
        {
            if (A[j] > A[j+1])
            {
                swap(A[j], A[j+1]);
            }
        }
    }

    return A;
}

int main()
{
    // Define an unsorted vector of integers
    vector <int> A = {5, 2, 9, 1, 5, 6};
    // Call the insertion sort function on vector A. 
    A = bubbleSort(A);

    for (auto x : A)
    {
        cout << x << " ";
    }
}