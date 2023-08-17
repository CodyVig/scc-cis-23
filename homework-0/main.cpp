#include <iostream>
#include <fstream>

using namespace std;

// function declarations here

void inputArray(int*);
void doubleInputArray(int*, int*);
void copyArrayToMatrix(int*, int*, int(*)[2]);
void printMatrix(int(*)[2]);

/** 
 * Main program to test various functions defined in this file. 
 */
int main()
{
    int arrSize = 5;
    int arr1[arrSize];
    int arr2[arrSize];
    int mat[5][2];
    
    /* test functions here */
    inputArray(arr1);
    doubleInputArray(arr1, arr2);
    copyArrayToMatrix(arr1, arr2, mat);
    printMatrix(mat);
}

/**
 * Populates array with user-selected integers. 
 *
 * @param inputArr: An integer array of length 5.
 */
void inputArray(int inputArr[5])
{ 
    cout << "Enter five (5) array elemets: \n";
    for (int idx = 0; idx < 5; idx++)
    {
        cout << "Element " << idx << ": ";
        cin >> inputArr[idx];
    }
}

/**
 * Populates `outputArr` with the doubles of the elements of `inputArray`.
 *
 * @param inputArr: The array to be doubled.
 * @param outpuptArray: The desination of the doubled array.
 */
void doubleInputArray(int inputArr[], int outputArr[]) 
{ 
    int arraySize = 5; 
    for (int idx = 0; idx < arraySize; idx++)
    {
        outputArr[idx] = 2 * inputArr[idx];
    }
}

/**
 * Copies input arrays into a matrix.
 *
 * @param inputArray1: The first row of the matrix.
 * @param inputArray2: The second row of the matrix.
 * @param otputMatrix: The destination of the matrix.
 */
void copyArrayToMatrix(int inputArray1[], int inputArray2[], int outputMatrix[][2])
{ 
    int arraySize = 5;
    for (int idx = 0; idx < arraySize; idx++)
    {
        outputMatrix[idx][0] = inputArray1[idx];
        outputMatrix[idx][1] = inputArray2[idx];
    }
}

/**
 * Prints a matrix to the console.
 *
 * @param matrix: The matrix whose elements are to be printed.
 */
void printMatrix(int matrix[][2])
{ 
    int arraySize = 5; 
    cout << "Matrix = \n";
    for (int row = 0; row < 2; row++)
    {
        for (int col = 0; col < arraySize; col++)
        {
            cout << matrix[col][row] << " ";
        }
        cout << endl;
    }
}
