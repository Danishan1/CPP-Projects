#include "matrix.hpp"

template <class t>
void matrix<t>::PrintMat(vector<vector<t>> a, string name)
{
    cout << name << "\n";
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "Array Printed Successfully\n\n";
}

// Checking Dimension of Matrices
template <class t>
void matrix<t>::errorGenerate(vector<vector<t>> a, vector<vector<t>> b, string s)
{
    try
    {
        if (a.size() != b.size())
        {
            throw false;
        }
        else
        {
            for (int i = 1; i < a.size(); i++)
                if (a[0].size() != a[i].size())
                {
                    throw false;
                }
            for (int i = 1; i < a.size(); i++)
                if (a[0].size() != b[i].size())
                {
                    throw false;
                }
        }
    }
    catch (bool)
    {
        cout << "ERROR : To " << s << ", both Matrix must have same Order.";
        exit(0);
    }
}

template <class t>
vector<vector<t>> matrix<t>::sumMat(vector<vector<t>> a, vector<vector<t>> b)
{
    errorGenerate(a, b, "Sum");
    for (int i = 0; i < a.size(); i++) // Size of 2D vector
    {
        for (int j = 0; j < a[i].size(); j++) // Size of 1D vector
        {
            a[i][j] = a[i][j] + b[i][j];
        }
    }
    return a;
}

template <class t>
vector<vector<t>> matrix<t>::diffMat(vector<vector<t>> a, vector<vector<t>> b)
{
    errorGenerate(a, b, "Differecne");

    for (int i = 0; i < a.size(); i++) // Size of 2D vector
    {
        for (int j = 0; j < a[i].size(); j++) // Size of 1D vector
        {
            a[i][j] = a[i][j] - b[i][j];
        }
    }
    return a;
}

template <class t>
vector<vector<t>> matrix<t>::TransposeMat(vector<vector<t>> a)
{

    vector<vector<t>> b(a.size(), vector<t>(a[0].size(), 0));
    for (int i = 0; i < a.size(); i++) // Size of 2D vector
    {
        for (int j = 0; j < a[i].size(); j++) // Size of 1D vector
        {
            b[i][j] = a[j][i];
        }
    }
    return b;
}

template <class t>
vector<vector<t>> matrix<t>::CompoProductMat(vector<vector<t>> a, vector<vector<t>> b)
{
    errorGenerate(a, b, "Component Wise Product");

    for (int i = 0; i < a.size(); i++) // Size of 2D vector
    {
        for (int j = 0; j < a[i].size(); j++) // Size of 1D vector
        {
            a[i][j] = a[i][j] * b[i][j];
        }
    }
    return a;
}

template <class t>
vector<vector<t>> matrix<t>::innerProductMat(vector<vector<t>> a, vector<vector<t>> b)
{
    try // mn nd
    {
        if (a[0].size() != b.size())
        {
            throw false;
        }
        else
        {
            for (int i = 1; i < a.size(); i++)
                if (a[0].size() != a[i].size())
                {
                    throw false;
                }
            for (int i = 1; i < b.size(); i++)
                if (b[0].size() != b[i].size())
                {
                    throw false;
                }
        }
    }
    catch (bool)
    {
        cout << "ERROR : To Multiply, if Matrix A : mxn then B must : nxd.";
        exit(0);
    }

    vector<vector<t>> a1(a.size(), vector<t>(b[0].size(), 0)); // mn np
    int sum = 0;

    for (int i = 0; i < a.size(); i++) // Size of 2D vector
    {
        for (int j = 0; j < a[i].size(); j++) // Size of 1D vector
        {
            for (int k = 0; k < a[i].size(); k++) //
            {
                sum += a[i][k] * b[k][j];
            }
            a1[i][j] = sum;
            sum = 0;
        }
    }
    return a1;
}

template <class t>
vector<vector<t>> matrix<t>::outerProductMat(vector<vector<t>> a, vector<vector<t>> b)
{
    try // mn nd
    {
        if (a.size() != b[0].size())
        {
            throw false;
        }
        else
        {
            for (int i = 1; i < a.size(); i++)
                if (a[0].size() != a[i].size())
                {
                    throw false;
                }
            for (int i = 1; i < b.size(); i++)
                if (b[0].size() != b[i].size())
                {
                    throw false;
                }
        }
    }
    catch (bool)
    {
        cout << "ERROR : To Outer Product, if Matrix A : mxn then B must : dxm.";
        exit(0);
    }

    vector<vector<t>> a1(a[0].size(), vector<t>(b.size(), 0)); // mn np
    int sum = 0;

    for (int i = 0; i < a[0].size(); i++) // Size of 2D vector
    {
        for (int j = 0; j < b.size(); j++) // Size of 1D vector
        {
            for (int k = 0; k < a.size(); k++) //
            {
                cout << a[k][i] << "*" << b[j][k] << " ";
                sum += a[k][i] * b[j][k];
            }
            cout << " | ";
            a1[i][j] = sum;
            sum = 0;
        }
        cout << " \n";
    }
    return a1;
    // return vector<vector<t>>();
}

template <class t>
vector<vector<t>> matrix<t>::scalerProductMat(vector<vector<t>> a, t b)
{
    for (int i = 0; i < a.size(); i++) // Size of 1D vector
    {
        for (int j = 0; j < a[0].size(); j++) //
        {
            a[i][j] = b * a[i][j];
        }
    }
    return a;
}

template <class t>
vector<vector<t>> matrix<t>::determinantMat(vector<vector<t>> a) {}

template <class t>
vector<vector<t>> matrix<t>::adjMat(vector<vector<t>> a) {}

template <class t>
vector<vector<t>> matrix<t>::inverseMat(vector<vector<t>> a) {}

template <class t>
vector<vector<t>> matrix<t>::traceMat(vector<vector<t>> a) {}

template <class t>
vector<vector<t>> matrix<t>::rankMat(vector<vector<t>> a) {}

template <class t>
vector<vector<t>> matrix<t>::SystemofLinearEquation(vector<vector<t>> a) {}

template <class t>
vector<vector<t>> matrix<t>::EigenValues(vector<vector<t>> a) {}

template <class t>
vector<vector<t>> matrix<t>::EigenVectorMat(vector<vector<t>> a) {}

template <class t>
bool matrix<t>::isEqualMat(vector<vector<t>> a, vector<vector<t>> b)
{
    if (a.size() == b.size() && a[0].size() == b[0].size())
    {
        for (int i = 1; i < a.size(); i++)
            for (int j = i; j < a[0].size(); j++)
            {
                if (a[i][j] != b[i][j] || a[j][i] != b[j][i])
                {
                    return false;
                }
            }
        return true;
    }
    else
    {
        return false;
    }
}

template <class t>
bool matrix<t>::isSquareMat(vector<vector<t>> a)
{
    if (a.size() != a[0].size())
    {
        return false;
    }
    else
        for (int i = 1; i < a.size(); i++)
            if (a[0].size() != a[i].size())
            {
                return false;
            }
    return true;
}

template <class t>
bool matrix<t>::isSymmetricMat(vector<vector<t>> a)
{
    if (isSquareMat(a))
    {
        for (int i = 1; i < a.size(); i++)
        {
            for (int j = i + 1; j < a[0].size(); j++)
            {
                if (a[i][j] != a[j][i])
                {
                    return false;
                }
            }
        }
        return true;
    }
    else
        return false;
}

template <class t>
bool matrix<t>::isSkewSymmetricMat(vector<vector<t>> a)
{
    if (isSquareMat(a))
    {
        for (int i = 1; i < a.size(); i++)
        {
            if (a[i][i] != 0)
            {
                return false;
            }
        }
        for (int i = 1; i < a.size(); i++)
        {
            for (int j = i + 1; j < a[0].size(); j++)
            {
                if (a[i][j] != -1 * a[j][i])
                {
                    return false;
                }
            }
        }
        return true;
    }
    else
        return false;
}

template <class t>
bool matrix<t>::isDiagonalMat(vector<vector<t>> a)
{
    if (isSquareMat(a))
    {
        bool flag = false;

        for (int i = 1; i < a.size(); i++)
        {
            for (int j = i + 1; j < a[0].size(); j++)
            {
                if (a[i][j] != 0 || a[j][i] != 0)
                {
                    return false;
                }
            }
        }
        return true;
    }
    else
        return false;
}

template <class t>
bool matrix<t>::isTriDiagonalMat(vector<vector<t>> a)
{
}

template <class t>
bool matrix<t>::isIdentityMat(vector<vector<t>> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i][i] != 1)
        {
            return false;
        }
    }
    if (isSquareMat(a))
    {
        for (int i = 1; i < a.size(); i++)
        {
            for (int j = i + 1; j < a[0].size(); j++)
            {
                if (a[i][j] != 0 || a[j][i] != 0)
                {
                    return false;
                }
            }
        }
        return true;
    }
    else
        return false;
}

template <class t>
bool matrix<t>::isOrthogonalMat(vector<vector<t>> a) // ATA = I
{
    if (isSquareMat(a))
    {
        vector<vector<t>> a1 = TransposeMat(a);
        a1 = innerProductMat(a, a1);
        if (isIdentityMat(a1))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
        return false;
}

template <class t>
bool matrix<t>::isIdempotentMat(vector<vector<t>> a) // A*A = A
{
    if (isSquareMat(a))
    {
        vector<vector<t>> a1 = innerProductMat(a, a);
        if (isEqualMat(a1, a))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

template <class t>
bool matrix<t>::isInvolutory(vector<vector<t>> a) // A*A = I
{
    if (isSquareMat(a))
    {
        vector<vector<t>> a1 = innerProductMat(a, a);
        if (isIdentityMat(a1))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

// template <class t>
// bool matrix<t>::isInvolutory(vector<vector<t>> a) {}

// Square Matrix  ----------------------------------------------------------------------------------

// template <class t>
// vector<vector<t>> matrix<t>::sumSqrMat(vector<vector<t>> a, vector<vector<t>> b) {}
// template <class t>
// vector<vector<t>> matrix<t>::diffSqrMat(vector<vector<t>> a, vector<vector<t>> b) {}
// template <class t>
// vector<vector<t>> matrix<t>::TransposeSqrMat(vector<vector<t>> a) {}
// template <class t>
// vector<vector<t>> matrix<t>::CompoProductSqrMat(vector<vector<t>> a, vector<vector<t>> b) {}
// template <class t>
// vector<vector<t>> matrix<t>::ProductSqrMat(vector<vector<t>> a, vector<vector<t>> b) {}

int main()
{
    vector<vector<float>> a = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {1, 2, 3, 4},
        {5, 6, 7, 8}};
    vector<vector<int>> a1 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {1, 2, 3, 4},
        {5, 0, 7, 8}};

    // vector<vector<int>> b = {
    //     {1, 2, 3, 4},
    //     {-2, 6, 5, 7},
    //     {-3, -5, 6, 8},
    //     {-4, -7, -8, 4}};

    // vector<vector<int>> b = {
    //     {0, 2, 3, 4},
    //     {-2, 0, 5, 7},
    //     {-3, -5, 0, 8},
    //     {-4, -7, -8, 0}};

    vector<vector<float>> b = {
        {2.0, -2.0, -4.0},
        {-1.0, 3.0, 4.0},
        {1.0, -2.0, -3.0}};

    // vector<vector<int>> b = {
    //     {1, 2, 2, 4},
    //     {5, 6, 6, 8},
    //     {5, 6, 6, 8},
    //     {1, 2, 2, 4}};

    matrix<float> M;
    M.PrintMat(a, "Matrix A : ");
    M.PrintMat(b, "Matrix B : ");
    // M.PrintMat(M.sumMat(a, a), "Sum (A + A) : ");
    // M.PrintMat(M.diffMat(a, a), "Difference (A - A) : ");
    // M.PrintMat(M.TransposeMat(a), "Transpose (A = A') : ");
    // M.PrintMat(M.TransposeMat(b), "Transpose (B = B') : ");
    // M.PrintMat(M.CompoProductMat(a, a), "Component Multiple (A O A) : ");
    // M.PrintMat(M.innerProductMat(a, b), "Inner Product (ATB) : "); // T => transpose
    // M.PrintMat(M.outerProductMat(a, b), "Outer Product (ABT) : "); // T => transpose

    cout << "is Equal Matrix (A, B) : " << M.isEqualMat(a, b) << "\n";
    cout << "is Square Matrix (A) : " << M.isSquareMat(a) << "\n";
    cout << "is Symmetrix Matrix (A): " << M.isSymmetricMat(a) << "\n";
    cout << "is Symmetrix Matrix (B): " << M.isSymmetricMat(b) << "\n";
    cout << "is SwewSymmetrix Matrix (B): " << M.isSkewSymmetricMat(b) << "\n";
    cout << "is Diagonal Matrix (B) : " << M.isDiagonalMat(b) << "\n";
    cout << "is Orthogonal Matrix (B) : " << M.isOrthogonalMat(b) << "\n";
    cout << "is Idempotant Matrix (B) : " << M.isIdempotentMat(b) << "\n";

    cout << "\nSuccessfully Printed ...End :)\n\n";
}
