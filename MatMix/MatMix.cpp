// MatMix.cpp
#include "MatMix.hpp"
#include <cmath>
#include <stdexcept>
#include <iomanip>
#include <algorithm>


// Default Constructor
Matmix::Matmix() : rows(0), cols(0), data(nullptr) {}

// Null Constructor (rows × cols, initialized to 0)
Matmix::Matmix(int r, int c) : rows(r), cols(c) {
    data = new double*[rows];
    for (int i = 0; i < rows; ++i)
        data[i] = new double[cols]();
}

// Copy Constructor
Matmix::Matmix(const Matmix& other) : rows(other.rows), cols(other.cols) {
    data = new double*[rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new double[cols];
        for (int j = 0; j < cols; ++j)
            data[i][j] = other.data[i][j];
    }
}

// Destructor
Matmix::~Matmix() {
    for (int i = 0; i < rows; ++i)
        delete[] data[i];
    delete[] data;
}

// Input operator >>
istream& operator>>(istream& in, Matmix& m) {
    for (int i = 0; i < m.rows; ++i)
        for (int j = 0; j < m.cols; ++j)
            in >> m.data[i][j];
    return in;
}

// Output operator <<
ostream& operator<<(ostream& out, const Matmix& m) {
    for (int i = 0; i < m.rows; ++i) {
        for (int j = 0; j < m.cols; ++j)
            out << setw(10) << m.data[i][j] << " ";
        out << endl;
    }
    return out;
}



void Matmix::readFromFile(const std::string& filename) {
    filename="49l.txt";
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("Could not open file: " + filename);

    // Step 1: Read the matrix dimensions from the first line
    file >> rows >> cols;

    // Step 2: Allocate memory dynamically
    data = new double*[rows];
    for (int i = 0; i < rows; ++i)
        data[i] = new double[cols];

    // Step 3: Read matrix values row-wise
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            file >> data[i][j];

    file.close();
}





// Read from file
/*
void Matrix::readFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) throw runtime_error("File not found!");

    file >> rows >> cols;

    data = new double*[rows];
    for (int i = 0; i < rows; ++i)
        data[i] = new double[cols];

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            file >> data[i][j];

    file.close();
}
*/

// Write to file
void Matmix::writeToFile(const string& filename) const {
    ofstream file(filename);
    file << rows << " " << cols << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            file << data[i][j] << " ";
        file << endl;
    }
    file.close();
}

// Addition
Matmix Matmix::operator+(const Matmix& other) {
    if (rows != other.rows || cols != other.cols)
        throw runtime_error("Matrix size mismatch!");

    Matmix result(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[i][j] = data[i][j] + other.data[i][j];

    return result;
}

// Subtraction
Matmix Matmix::operator-(const Matmix& other) {
    if (rows != other.rows || cols != other.cols)
        throw runtime_error("Matrix size mismatch!");

    Matmix result(rows, cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            result.data[i][j] = data[i][j] - other.data[i][j];

    return result;
}

// Multiplication
Matmix Matmix::operator*(const Matmix& other)
{
    if (cols != other.rows)
        throw runtime_error("Matrix multiplication dimension error!");

    Matmix result(rows, other.cols);
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < other.cols; ++j)
            for (int k = 0; k < cols; ++k)
                result.data[i][j] += data[i][k] * other.data[k][j];

    return result;
}

// Utility Getters
int Matmix::getRows() const { return rows; }
int Matmix::getCols() const { return cols; }
double Matmix::getValue(int r, int c) const { return data[r][c]; }
void Matmix::setValue(int r, int c, double val) { data[r][c] = val; }

// Check Symmetry
bool Matmix::isSymmetric() const {
    if (rows != cols) return false;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            if (data[i][j] != data[j][i])
                return false;
    return true;
}

// Check Diagonal Dominance
bool Matmix::isDiagonallyDominant() const {
    for (int i = 0; i < rows; ++i) 
    {
        double diag = fabs(data[i][i]);
        double sum = 0;
        for (int j = 0; j < cols; ++j)
        {
            if (j != i) sum += fabs(data[i][j]);
        }
        if (diag < sum) return false;
    }
    return true;
}

// Make Diagonally Dominant 
void Matmix::makeDiagonallyDominant() {
    for (int i = 0; i < rows; ++i) {
        int maxRow = i;
        for (int j = i + 1; j < rows; ++j) {
            if (abs(data[j][i]) > abs(data[maxRow][i]))
                maxRow = j;
        }
        if (maxRow != i) {
            swap(data[i], data[maxRow]);
        }
    }
}
// Gaussian Elimination
Matmix Matmix::gaussianElimination() {
    Matrix A(*this); // Copy current matrix

    for (int i = 0; i < rows; ++i) {
        // Pivoting
        int maxRow = i;
        for (int k = i + 1; k < rows; ++k)
            if (abs(A.data[k][i]) > abs(A.data[maxRow][i]))
                maxRow = k;

        swap(A.data[i], A.data[maxRow]);

        // Make all rows below this one 0 in current column
        for (int k = i + 1; k < rows; ++k) {
            double f = A.data[k][i] / A.data[i][i];
            for (int j = i; j < cols; ++j)
                A.data[k][j] -= A.data[i][j] * f;
        }
    }

    // Back substitution
    Matrix x(rows, 1);
    for (int i = rows - 1; i >= 0; --i) {
        x.data[i][0] = A.data[i][cols - 1];
        for (int j = i + 1; j < cols - 1; ++j)
            x.data[i][0] -= A.data[i][j] * x.data[j][0];
        x.data[i][0] /= A.data[i][i];
    }

    return x;
}
Matrix Matrix::LUDecomposition() {
    if (rows != cols)
        throw runtime_error("LU Decomposition requires square matrix.");

    Matrix L(rows, cols), U(rows, cols);

    for (int i = 0; i < rows; i++) {
        // Upper Triangular
        for (int k = i; k < cols; k++) {
            double sum = 0;
            for (int j = 0; j < i; j++)
                sum += (L.data[i][j] * U.data[j][k]);
            U.data[i][k] = data[i][k] - sum;
        }

        // Lower Triangular
        for (int k = i; k < rows; k++) {
            if (i == k)
                L.data[i][i] = 1; // Diagonal as 1
            else {
                double sum = 0;
                for (int j = 0; j < i; j++)
                    sum += (L.data[k][j] * U.data[j][i]);
                L.data[k][i] = (data[k][i] - sum) / U.data[i][i];
            }
        }
    }

    // Return both L and U concatenated side by side for now (user can split)
    Matrix LU(rows, cols * 2);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            LU.data[i][j] = L.data[i][j];
            LU.data[i][j + cols] = U.data[i][j];
        }

    return LU;
}
Matrix Matrix::gaussJacobi(int maxIter, double tol) {
    Matrix x(rows, 1); // Initial guess = 0

    for (int it = 0; it < maxIter; ++it) {
        Matrix x_new(x);

        for (int i = 0; i < rows; ++i) {
            double sigma = 0;
            for (int j = 0; j < cols - 1; ++j)
                if (j != i)
                    sigma += data[i][j] * x.data[j][0];

            x_new.data[i][0] = (data[i][cols - 1] - sigma) / data[i][i];
        }

        // Check convergence
        double err = 0;
        for (int i = 0; i < rows; ++i)
            err += abs(x_new.data[i][0] - x.data[i][0]);

        if (err < tol) break;
        x = x_new;
    }

    return x;
}
Matrix Matrix::gaussSeidel(int maxIter, double tol) {
    Matrix x(rows, 1); // Initial guess = 0

    for (int it = 0; it < maxIter; ++it) {
        Matrix x_old(x);

        for (int i = 0; i < rows; ++i) {
            double sigma = 0;
            for (int j = 0; j < cols - 1; ++j)
                if (j != i)
                    sigma += data[i][j] * x.data[j][0];

            x.data[i][0] = (data[i][cols - 1] - sigma) / data[i][i];
        }

        // Check convergence
        double err = 0;
        for (int i = 0; i < rows; ++i)
            err += abs(x.data[i][0] - x_old.data[i][0]);

        if (err < tol) break;
    }

    return x;
}
Matrix Matrix::choleskyDecomposition() {
    if (!isSymmetric()) throw runtime_error("Cholesky: Matrix not symmetric");

    Matrix L(rows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j <= i; ++j) {
            double sum = 0;
            if (j == i) {
                for (int k = 0; k < j; ++k)
                    sum += pow(L.data[j][k], 2);
                L.data[j][j] = sqrt(data[j][j] - sum);
            } else {
                for (int k = 0; k < j; ++k)
                    sum += (L.data[i][k] * L.data[j][k]);
                L.data[i][j] = (data[i][j] - sum) / L.data[j][j];
            }
        }
    }

    return L;
}

bool areAllFilesEqual(const std::vector<std::string>& files) {
    for (size_t i = 1; i < files.size(); ++i) {
        if (!areFilesEqual(files[0], files[i]))
            return false;
    }
    return true;
}
std::vector<std::string> files = {
    "gaussianResult.txt", "GausJacobiRslt", "GaussiedelRslt.txt"
};
