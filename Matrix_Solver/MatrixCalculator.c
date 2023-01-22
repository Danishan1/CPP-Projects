#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define N 3

int ansArr[N][N], array1[N][N], array2[N][N];

void PrintMat(int arr[N][N])
{
    printf("\n");

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("Array Printed Successfully\n\n");
}

// Checking Dimension of Matrices

void sumMat(int arr[N][N], int arr1[N][N])
{
    for (int i = 0; i < N; i++) // Size of 2D vector
    {
        for (int j = 0; j < N; j++) // Size of 1D vector
        {
            ansArr[i][j] = arr[i][j] + arr1[i][j];
        }
    }
}

void diffMat(int arr[N][N], int arr1[N][N])
{

    for (int i = 0; i < N; i++) // Size of 2D vector
    {
        for (int j = 0; j < N; j++) // Size of 1D vector
        {
            ansArr[i][j] = arr[i][j] - arr1[i][j];
        }
    }
}

void TransposeMat(int arr[N][N])
{

    int arr1[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            ansArr[i][j] = arr[j][i];
        }
    }
}

void CompoProductMat(int arr[N][N], int arr1[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            ansArr[i][j] = arr[i][j] * arr1[i][j];
        }
    }
}

void innerProductMat(int arr[N][N], int arr1[N][N])
{

    // int arr[N][N]; // mn np
    int sum = 0;

    for (int i = 0; i < N; i++) // Size of 2D vector
    {
        for (int j = 0; j < N; j++) // Size of 1D vector
        {
            for (int k = 0; k < N; k++) //
            {
                sum += arr[i][k] * arr1[k][j];
            }
            ansArr[i][j] = sum;
            sum = 0;
        }
    }
}

void takeMatrix(int arr[N][N], char *A)
{
    printf("\nEnter 9 (3x3) Values for Matirx %s \n", A);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            printf("Enter at index %d, %d : ", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        }
}

void showmatrix(int arr[N][N], char *A)
{
    printf("\n The Matrix %s : \n ", A);
    for (int i = 0; i < N; i++) // Size of 2D vector
    {
        for (int j = 0; j < N; j++) // Size of 1D vector
        {
            printf("%d    ", arr[i][j]);
        }
        printf("\n ");
    }
    printf("Matrix printed Successfully\n");
}

int main()
{
    // int array1[N][N], array2[N][N];
    system("cls");
    printf("\n---------- Welcome to Square Matrix (3x3) Calculator -------------\n\n");
    printf("\nNOTE: In this project I have Used Concept of\n\n"
           "   1. Data Type \n"
           "   2. Conditions \n"
           "   3. Loops \n"
           "   4. Function \n"
           "   5. Array (1D and 2D) \n"
           "   6. Pointers \n"
           "   7. Matrix Operations \n\n"
           "Enter Any Key to Start ... ");
    getch();

    int num = 0;

    system("cls");
    printf("\n---------- Welcome to Square Matrix (3x3) Calculator -------------\n\n");
    takeMatrix(array1, "A");
    takeMatrix(array2, "B");

    while (1)
    {
        system("cls");
        printf("\n---------- Welcome to Square Matrix (3x3) Calculator -------------\n\n");
        showmatrix(array1, "A");
        showmatrix(array2, "B");

        printf("\nEnter value to perform the Operation \n\n"
               "   1. Add two Matrix (A+B)\n"
               "   2. subtract two Matrix (A-B) \n"
               "   3. Multiply or Inner Product of two matrix \n"
               "   4. Element wise product of two matrix \n"
               "   5. Transpose of Matrix A \n"
               "   6. Transpose of Matrix B \n"
               "   7. ReEnter Matrices \n"
               "   8. Print of Matrix A \n"
               "   9. Print of Matrix B \n"
               "   10. Enter -1 to EXIT  \n\n"
               "Enter : ");
        scanf("%d", &num);

        switch (num)
        {
        case -1:
            exit(0);
            break;
        case 1:
            sumMat(array1, array2);
            showmatrix(ansArr, "A+B");
            break;
        case 2:
            diffMat(array1, array2);
            showmatrix(ansArr, "A-B");
            break;
        case 3:
            innerProductMat(array1, array2);
            showmatrix(ansArr, "AxB");
            break;
        case 4:
            CompoProductMat(array1, array2);
            showmatrix(ansArr, "AOB");
            break;
        case 5:
            TransposeMat(array1);
            showmatrix(ansArr, "A'");
            break;
        case 6:
            TransposeMat(array2);
            showmatrix(ansArr, "B'");
            break;
        case 7:
            system("cls");
            printf("\n---------- Welcome to Square Matrix (3x3) Calculator -------------\n\n");
            takeMatrix(array1, "A");
            takeMatrix(array2, "B");
            continue;
            break;
        case 8:
            showmatrix(array1, "A");
            break;
        case 9:
            showmatrix(array2, "B");
            break;

        default:
            printf("Enter a Valid Number");
            continue;
        }

        printf("Enter any Key to move Further ... ");
        getch();
    }
    showmatrix(array1, "A");
    showmatrix(array2, "B");

    return 0;
}
