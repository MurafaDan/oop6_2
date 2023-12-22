#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Matrix {
private:

    vector<vector<T>> data;
    size_t rows, cols;

public:
    Matrix(size_t rows, size_t cols) : rows(rows), cols(cols), data(rows, vector<T>(cols)) {}
    ~Matrix() {}
    size_t getRows() const {
        return rows;
    }
    size_t getCols() const {
        return cols;
    }

    vector<T>& operator[](size_t index) {
        return data[index];
    }


    Matrix operator+(const Matrix& other) const {
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator-(const Matrix& other) const {
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        Matrix result(rows, other.cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < other.cols; ++j) {
                for (size_t k = 0; k < cols; ++k) {
                    result[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    // Overload <<
    friend ostream& operator<<(ostream& os, const Matrix& matrix) {
        for (size_t i = 0; i < matrix.rows; ++i) {
            for (size_t j = 0; j < matrix.cols; ++j) {
                os << matrix.data[i][j] << ' ';
            }
            os << endl;
        }
        return os;
    }

    // Overload >>
    friend istream& operator>>(istream& is, Matrix& matrix) {
        for (size_t i = 0; i < matrix.rows; ++i) {
            for (size_t j = 0; j < matrix.cols; ++j) {
                is >> matrix.data[i][j];
            }
        }
        return is;
    }
};

int main() {
    Matrix<int*> mat1(2, 2), mat2(2, 2);
    cout << "Enter elements for matrix 1:\n";
    cin >> mat1;
    cout << "Enter elements for matrix 2:\n";
    cin >> mat2;

    Matrix<int*> sum = mat1 + mat2;
    Matrix<int*> diff = mat1 - mat2;
    Matrix<int*> prod = mat1 * mat2;

    cout << "Matrix 1:\n" << mat1 << "Matrix 2:\n" << mat2;
    cout << "Sum:\n" << sum << "Difference:\n" << diff << "Product:\n" << prod;

    return 0;
}