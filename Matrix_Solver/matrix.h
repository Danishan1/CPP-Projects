#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <class t>
class matrix
{
    void errorGenerate(vector<vector<t>> a, vector<vector<t>> b, string s);

public:
    vector<vector<t>> sumMat(vector<vector<t>> a, vector<vector<t>> b);
    vector<vector<t>> diffMat(vector<vector<t>> a, vector<vector<t>> b);
    vector<vector<t>> CompoProductMat(vector<vector<t>> a, vector<vector<t>> b);
    vector<vector<t>> innerProductMat(vector<vector<t>> a, vector<vector<t>> b);
    vector<vector<t>> outerProductMat(vector<vector<t>> a, vector<vector<t>> b);

    vector<vector<t>> scalerProductMat(vector<vector<t>> a, t b);
    void PrintMat(vector<vector<t>> a, string name);

    vector<vector<t>> TransposeMat(vector<vector<t>> a);
    vector<vector<t>> determinantMat(vector<vector<t>> a);
    vector<vector<t>> adjMat(vector<vector<t>> a);
    vector<vector<t>> inverseMat(vector<vector<t>> a);
    vector<vector<t>> traceMat(vector<vector<t>> a);
    vector<vector<t>> rankMat(vector<vector<t>> a);
    vector<vector<t>> SystemofLinearEquation(vector<vector<t>> a);
    vector<vector<t>> EigenValues(vector<vector<t>> a);
    vector<vector<t>> EigenVectorMat(vector<vector<t>> a);

    bool isEqualMat(vector<vector<t>> a, vector<vector<t>> b);
    bool isSquareMat(vector<vector<t>> a);
    bool isSymmetricMat(vector<vector<t>> a);
    bool isSkewSymmetricMat(vector<vector<t>> a);
    bool isDiagonalMat(vector<vector<t>> a);
    bool isTriDiagonalMat(vector<vector<t>> a);
    bool isIdentityMat(vector<vector<t>> a);
    bool isOrthogonalMat(vector<vector<t>> a);
    bool isIdempotentMat(vector<vector<t>> a);
    bool isInvolutory(vector<vector<t>> a);


    // vector<vector<t>> sumSqrMat(vector<vector<t>> a, vector<vector<t>> b);
    // vector<vector<t>> diffSqrMat(vector<vector<t>> a, vector<vector<t>> b);
    // vector<vector<t>> TransposeSqrMat(vector<vector<t>> a);
    // vector<vector<t>> CompoProductSqrMat(vector<vector<t>> a, vector<vector<t>> b);
    // vector<vector<t>> ProductSqrMat(vector<vector<t>> a, vector<vector<t>> b);
};