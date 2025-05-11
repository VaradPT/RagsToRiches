// MatMix.hpp
#ifndef MATMIX_HPP
#define MATMIX_HPP

#include <iostream>
#include <fstream>
using namespace std;

class Matmix 
{
public:
    int rows, cols;
    double** data;                      // Dynamic 2D array
    string filename;
    // Constructors & Destructor
    Matmix();                           // Default constructor
    Matmix(int r, int c);               // Null constructor
    Matmix(const Matmix& other);        // Copy constructor
    ~Matmix();                          // Destructor

    // Input/Output
    friend istream& operator>>(istream& in, Matmix& m);               // Input from stream
    friend ostream& operator<<(ostream& out, const Matmix& m);        // Output to stream
    void readFromFile(const string& filename);
    void writeToFile(const string& filename) const;

    // Arithmetic Operations
    Matmix operator+(const Matmix& other);
    Matmix operator-(const Matmix& other);
    Matmix operator*(const Matmix& other);

    // System of Linear Equations Solvers
    Matmix gaussianElimination();
    Matmix LUDecomposition();
    Matmix gaussSeidel(int maxIter = 1000, double tol = 1e-10);
    Matmix gaussJacobi(int maxIter = 1000, double tol = 1e-10);
    Matmix choleskyDecomposition();
    //Matmix dooittleMethod();

    // Matrix Properties
    bool isDiagonallyDominant() const;
    void makeDiagonallyDominant();
    bool isSymmetric() const;


    //Utility:
    //Utility operations: Trace(Sum of Diagonals)
    //Eigen Values and further operations

    int getRows() const;
    int getCols() const;
    double getValue(int r, int c) const;
    void setValue(int r, int c, double val);
    /*Under construction*/bool areAllFilesEqual(numofiles, filenames) const;
};

#endif
