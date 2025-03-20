#ifndef MatMix
#define MatMix 

#include <iostream>
#include <vector>
using namespace std;

class MatMix:
{
private: 
    int rows, cols;
    double** data;

    void allocateMemory();
    void deallocateMemory();
     
public: 
    MatMix(int rows, int cols);
    MatMix(const MatMix& other);
    ~MatMix();

    void readFromFile(const string& filename);
    void writeToFile(const string& filename) const;

    void print() const;

    //Operator overloading
    friend ostream& operator<<(ostream& os, const MatMix& mat);
    friend istream& operator>>(istream& is, MatMix& mat);

    MatMix operator+(const MatMix& other) const;
    MatMix operator-(const MatMix& other) const;
    MatMix operator*(const MatMix& other) const;

    // Checks if the matrix is diagonally dominant
    bool isDiagonallyDominant() const;

    // Attempts to modify the matrix to make it diagonally dominant
    void makeDiagonallyDominant();

    // Checks if the matrix is symmetric
    bool isSymmetric() const;
    bool isIdentity() const;
    bool isUpperTrilar() const;
    bool isLowerTrilar() const;
    //bool is

    Matrix gaussianElimination() const;

    Matrix luDecomposition() const;

    Matrix gaussSeidel(const vector<double>& b, int iterations, double tol) const;

    Matrix gaussJacobi(const vector<double>& b, int iterations, double tol) const;

    // Computes the largest eigenvalue using the Power Method
    //double powerMethod(int maxIter, double tol) const;

    // Computes the eigenvalue closest to a given shift using Shifted Inverse Power Method
    //double shiftInversePowerMethod(double shift, int maxIter, double tol) const;

    // Reduces a matrix to tridiagonal form using Householder's Method
    //Matrix houseHolderMethod() const;

    // Computes eigenvalues using the Jacobi Rotation method
    //Matrix jacobiRotation() const;

    // Computes Sturm sequences to find eigenvalues
    //vector<double> strumSequences() const;

    // ********************** Matrix Properties **********************

}



#endif 