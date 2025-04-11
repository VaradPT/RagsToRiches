#include <iostream>
using namespace std;
int main()
{
     cout<<"Hello world";
     
     getSum(2,10);
       
}
/*Keywords used sofar :
Datatypes: int, bool, char, long, string,
endl:? gobal:? using namespace std:? */
const int n=5;//Value cannot change after initialization
int num=9; 
char al='a';
string sr="Stringg";
long ln;
double db;

void funct()
{
    //Function
}

void getSum(int a, int b)
{
    int sum = a+b;
    cout<<"The sum is: "<<sum;
}

class Car
{
    string Brand;
    string Model;
    int year;
};




/*
Q: Implement Matrix Class in C++ to Handle operations on Matrices
To Do: 
1. Class should implement Constructors and Destructor
2. Class should read input from a file and also be able to write Output to File or console
3.   This class should handle all arithmetic operations on Matrices using Operators:
      i)  Insertion, Extraction operators
      ii) Addition Subtraction and Multiplication of Matrices 
4. This Class should have following member functions to solve system of linear equations. 
       i)   Gaussian Elimination
       ii)  LU Decomposition
       iii) Gauss Siedel 
       iv)  Gauss Jacobi
       v)   Crout's Algo
       vi)  Dolittle's algo
       vii) Choleski  
5. This class should have following member function to solve for Eigen Values 
i.   Power Method
ii.  Shift Inverse Power Method
iii. House Holder's Method
iv.  Jacobi Rotation
v.   Strum Sequences

6. Class should have member functions like 
i.    isDiagonallyDominant() that returns true or false if matrix is diagonally dominant 
ii.   makeDiagonallyDominant() Checks if Diag. Dominant, if not it try to make the matrix diagonally dominant, else display appropriate message
iii.  isSymmetric() checks if matrix is symmetric
 
Design the class in such a way that more useful functions should be able to be added later too

Rules:  No hard coding, memory to be allocated dynamically, code to be written in three files, classname.cpp, classname.hpp and main.cpp. Program should be run using big matrices, all methods should produce same output. Comments to be inserted in the code. 

//Matmix.hpp
#ifndef MATMIX_HPP
#define MATMIX_HPP

#include <iostream>
#include <vector>

using namespace std;

class MatMix {
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

    friend ostream& operator<<(ostream& os, const MatMix& mat);
    friend istream& operator>>(istream& is, MatMix& mat);

    
    /*
    bool isMatDiagonal() const;
    bool isMatNull() const;
    bool isDiagonallyDominant() const;
    bool isSymmetric() const;
    bool isIdentity() const;
    bool isUpperTrilar() const;
    bool isLowerTrilar() const;
    

    rowOps()
    colOps()
    getRank();//with two parameters
    
    void checkSpl();//Symmetric Matrices, Skew Symmetric, Orthogonal, Indempotent, Nilpotent, Hermitian
    bool isDgnlb();
    void makeDiagonallyDominant();
    void getTranspose(); Properties
    void MatSum();
    void MatDiff();
    void ScalarProd();
    void MatProd();//Parameters based on properties(Multiple Matrices) and appropriate use
    void Invert();//Criteria, properties
    void Minor();
    void Det(); // Square matrices only 
    MatMix operator+(const MatMix& other) const; 
    MatMix operator-(const MatMix& other) const;
    MatMix operator*(const MatMix& other) const;
    //2hs a day

    MatMix gaussianElimination() const;
    MatMix luDecomposition() const;
    MatMix gaussSeidel(const vector<double>& b, int iterations, double tol) const;
    MatMix gaussJacobi(const vector<double>& b, int iterations, double tol) const;
    MatMix Choleski(const vector<double>& b, int iterations,) const;

    /*Functions-Methods for Eigen Values: 
    powerMethod() const; 
    shiftInversePower() const
    houseHoldersMethod() const
    jacobiRotation() const;
    strumSequences() const;*/


#endif
