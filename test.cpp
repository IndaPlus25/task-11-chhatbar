#include <iostream>
#include "gtest/gtest.h"
#include <vector>
#include <unordered_map>
using namespace std;

void insertionSort(std::vector<int>& arr);
void mergeSort(std::vector<int>& arr);
void selectionSort(std::vector<int>& arr);
void quickSort(std::vector<int>& arr);

bool noDataLoss(vector <int> initialA, vector<int> sortedA) {
    unordered_map<int, int> numberCounts;

    for (int x : initialA)
    {
        numberCounts[x]++;
    }

    for (int x : sortedA)
    {
        numberCounts[x]--;
    }

    for (auto pair : numberCounts)
    {
        if (pair.second != 0) {
            return false;
        }
    }
    return true;
}

TEST(InsertionSortTest, BasicAssertions) {
    vector<int> A = {5, 2, 9, 1, 5, 6};
    vector<int> initialA = A;
    insertionSort(A);
    vector<int> sortedA = A;

    for (int i{0}; i<A.size()-1; i++)
    {
        ASSERT_LE(A[i], A[i+1]) << "Error at index " << i;
    }

    ASSERT_TRUE(noDataLoss(initialA, sortedA)) << "Data loss detected";
}

TEST(InsertionSortTest, Reverse) {
    vector<int> A = {6, 5, 1, 9, 2, 5};
    vector<int> initialA = A;
    insertionSort(A);
    vector<int> sortedA = A;

    for (int i{0}; i<A.size()-1; i++)
    {
        ASSERT_LE(A[i], A[i+1]) << "Error at index " << i;
    }

        ASSERT_TRUE(noDataLoss(initialA, sortedA)) << "Data loss detected";
}

TEST(InsertionSortTest, Empty) {
    vector<int> A = {};
    vector<int> initialA = A;
    insertionSort(A);
    vector<int> sortedA = A;

    for (int i{0}; i<A.size()-1; i++)
    {
        ASSERT_LE(A[i], A[i+1]) << "Error at index " << i;
    }

        ASSERT_TRUE(noDataLoss(initialA, sortedA)) << "Data loss detected";
}

TEST(InsertionSortTest, Negative) {
    vector<int> A = {-5, -2, -9, -1, -5, -6};
    vector<int> initialA = A;
    insertionSort(A);
    vector<int> sortedA = A;

    for (int i{0}; i<A.size()-1; i++)
    {
        ASSERT_LE(A[i], A[i+1]) << "Error at index " << i;
    }

        ASSERT_TRUE(noDataLoss(initialA, sortedA)) << "Data loss detected";
}

TEST(MergeSortTest, BasicAssertions) {
    vector<int> A = {5, 2, 9, 1, 5, 6};
    vector<int> initialA = A;
    mergeSort(A);
    vector<int> sortedA = A;

    for (int i{0}; i<A.size()-1; i++)
    {
        ASSERT_LE(A[i], A[i+1]) << "Error at index " << i;
    }

        ASSERT_TRUE(noDataLoss(initialA, sortedA)) << "Data loss detected";
}

TEST(MergeSortTest, Reverse) {
    vector<int> A = {6, 5, 1, 9, 2, 5};
    vector<int> initialA = A;
    mergeSort(A);
    vector<int> sortedA = A;

    for (int i{0}; i<A.size()-1; i++)
    {
        ASSERT_LE(A[i], A[i+1]) << "Error at index " << i;
    }

        ASSERT_TRUE(noDataLoss(initialA, sortedA)) << "Data loss detected";
}

TEST(MergeSortTest, Empty) {
    vector<int> A = {};
    vector<int> initialA = A;
    mergeSort(A);
    vector<int> sortedA = A;

    for (int i{0}; i<A.size()-1; i++)
    {
        ASSERT_LE(A[i], A[i+1]) << "Error at index " << i;
    }

        ASSERT_TRUE(noDataLoss(initialA, sortedA)) << "Data loss detected";
}

TEST(MergeSortTest, Negative) {
    vector<int> A = {-5, -2, -9, -1, -5, -6};
    vector<int> initialA = A;
    mergeSort(A);
    vector<int> sortedA = A;

    for (int i{0}; i<A.size()-1; i++)
    {
        ASSERT_LE(A[i], A[i+1]) << "Error at index " << i;
    }

        ASSERT_TRUE(noDataLoss(initialA, sortedA)) << "Data loss detected";
}

TEST(SelectionSortTest, BasicAssertions) {
    vector<int> A = {5, 2, 9, 1, 5, 6};
    vector<int> initialA = A;
    selectionSort(A);
    vector<int> sortedA = A;

    for (int i{0}; i<A.size()-1; i++)
    {
        ASSERT_LE(A[i], A[i+1]) << "Error at index " << i;
    }

        ASSERT_TRUE(noDataLoss(initialA, sortedA)) << "Data loss detected";
}

TEST(SelectionSortTest, Reverse) {
    vector<int> A = {6, 5, 1, 9, 2, 5};
    vector<int> initialA = A;
    selectionSort(A);
    vector<int> sortedA = A;

    for (int i{0}; i<A.size()-1; i++)
    {
        ASSERT_LE(A[i], A[i+1]) << "Error at index " << i;
    }

        ASSERT_TRUE(noDataLoss(initialA, sortedA)) << "Data loss detected";
}

TEST(SelectionSortTest, Empty) {
    vector<int> A = {};
    vector<int> initialA = A;
    selectionSort(A);
    vector<int> sortedA = A;

    for (int i{0}; i<A.size()-1; i++)
    {
        ASSERT_LE(A[i], A[i+1]) << "Error at index " << i;
    }

        ASSERT_TRUE(noDataLoss(initialA, sortedA)) << "Data loss detected";
}

TEST(SelectionSortTest, Negative) {
    vector<int> A = {-5, -2, -9, -1, -5, -6};
    vector<int> initialA = A;
    selectionSort(A);
    vector<int> sortedA = A;

    for (int i{0}; i<A.size()-1; i++)
    {
        ASSERT_LE(A[i], A[i+1]) << "Error at index " << i;
    }

        ASSERT_TRUE(noDataLoss(initialA, sortedA)) << "Data loss detected";
}

TEST(QuickSortTest, BasicAssertions) {
    vector<int> A = {5, 2, 9, 1, 5, 6};
    vector<int> initialA = A;
    quickSort(A);
    vector<int> sortedA = A;

    for (int i{0}; i<A.size()-1; i++)
    {
        ASSERT_LE(A[i], A[i+1]) << "Error at index " << i;
    }

        ASSERT_TRUE(noDataLoss(initialA, sortedA)) << "Data loss detected";
}

TEST(QuickSortTest, Reverse) {
    vector<int> A = {6, 5, 1, 9, 2, 5};
    vector<int> initialA = A;
    quickSort(A);
    vector<int> sortedA = A;

    for (int i{0}; i<A.size()-1; i++)
    {
        ASSERT_LE(A[i], A[i+1]) << "Error at index " << i;
    }

        ASSERT_TRUE(noDataLoss(initialA, sortedA)) << "Data loss detected";
}

TEST(QuickSortTest, Empty) {
    vector<int> A = {};
    vector<int> initialA = A;
    quickSort(A);
    vector<int> sortedA = A;

    for (int i{0}; i<A.size()-1; i++)
    {
        ASSERT_LE(A[i], A[i+1]) << "Error at index " << i;
    }

        ASSERT_TRUE(noDataLoss(initialA, sortedA)) << "Data loss detected";
}

TEST(QuickSortTest, Negative) {
    vector<int> A = {-5, -2, -9, -1, -5, -6};
    vector<int> initialA = A;
    quickSort(A);
    vector<int> sortedA = A;

    for (int i{0}; i<A.size()-1; i++)
    {
        ASSERT_LE(A[i], A[i+1]) << "Error at index " << i;
    }

        ASSERT_TRUE(noDataLoss(initialA, sortedA)) << "Data loss detected";
}