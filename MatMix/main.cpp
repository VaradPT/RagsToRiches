// main.cpp
#include <fstream>   // for file input/output
#include <vector>
#include <string>  // for std::string
#include "MatMix.hpp"
#include <iostream>

int main() {
    try {


        // Load matrix from file
        B.readFromFile("49r.txt");   
        A.readFromFile("49l.txt"); // Ensure this file exists with [rows cols] at top
        std::cout << "Input Matrix1:\n" << A << std::endl;

        // Gaussian Elimination
        std::cout << "\n=== Gaussian Elimination Solution ===\n";
        Matrix x1 = A.gaussianElimination();
        x1.writeToFile("gaussianResult.txt");
        //std::cout << x1 << std::endl;

        // LU Decomposition
        std::cout << "\n=== LU Decomposition (L|U) ===\n";
        Matrix LU = A.LUDecomposition();
        LU.writeToFile("LUResult.txt");
        //std::cout << LU << std::endl;

        // Gauss-Jacobi
        std::cout << "\n=== Gauss-Jacobi Method ===\n";
        Matrix x2 = A.gaussJacobi();
        //std::cout << x2 << std::endl;
        x2.writeToFile("GausJacobiRslt.txt");

        // Gauss-Seidel
        std::cout << "\n=== Gauss-Seidel Method ===\n";
        Matrix x3 = A.gaussSeidel();
        std::cout << x3 << std::endl;
        x3.writeToFile("GaussiedelRslt.txt");


        // Cholesky Decomposition
        if (A.isSymmetric()) {
            std::cout << "\n=== Cholesky Decomposition ===\n";
            Matrix chol = A.choleskyDecomposition();
            //std::cout << chol << std::endl;
            chol.writeToFile("choleskiDec.txt");

        

        } else {
            std::cout << "\nCholesky Decomposition skipped (Matrix not symmetric).\n";
        }

        
        
        if (areAllFilesEqual(files)) {
            std::cout << "All solver outputs match!\n";
        } else {
            std::cout << "Mismatch in at least one solver output.\n";
        }
        



    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }

    return 0;
}
