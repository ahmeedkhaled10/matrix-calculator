// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I - Task 1 - Problem 0
// Program: CS213-2018-A1-T1-P0
// Purpose: Skeleton code for the student to start working
// Author:  Dr. Mohammad El-Ramly
// Date:    10 August 2018
// Version: 1.0

#include <iostream>
#include <iomanip>
//#include <cassert>

using namespace std;

// The needed counters for all the loops in the whole program
int i = 0, j = 0;

// Array of zeros to create data for createMatrix function
int fillData [100] = {0};

// A structure to store a matrix
struct matrix
{
  int** data;       // Pointer to 2-D array that will simulate matrix
  int row, col;
};

// Create a matrix by calling these parameters
void createMatrix (int row, int col, int num[], matrix& mat);

// All these operations return a new matrix with the calculation result
matrix operator+  (matrix mat1, matrix mat2);
matrix operator-  (matrix mat1, matrix mat2);
matrix operator*  (matrix mat1, matrix mat2);
matrix operator+  (matrix mat1, int scalar);
matrix operator-  (matrix mat1, int scalar);
matrix operator*  (matrix mat1, int scalar);
matrix operator+= (matrix& mat1, matrix mat2);
matrix operator-= (matrix& mat1, matrix mat2);
matrix operator+= (matrix& mat, int scalar);
matrix operator-= (matrix& mat, int scalar);
void operator++ (matrix& mat);
void operator-- (matrix& mat);
istream& operator>> (istream& in, matrix& mat);
ostream& operator<< (ostream& out, matrix mat);
bool operator== (matrix mat1, matrix mat2);
bool operator!= (matrix mat1, matrix mat2);
bool isSquare   (matrix mat);
bool isSymetric (matrix mat);
bool isIdentity (matrix mat);
matrix transpose(matrix mat);


//__________________________________________
// Start Main Function
int main()
{
  int data1 [] = {1,0,0,
                  0,1,0,
                  0,0,1};
  int data2 [] = {13,233,3,4,5,6};
  int data3 [] = {10,100,10,100,10,100,10,100};

  matrix mat1, mat2, mat3;
  createMatrix (3, 3, data1, mat1);
  createMatrix (2, 3, data2, mat2);
  createMatrix (4, 2, data3, mat3);


  if ( isIdentity(mat1))
    cout << "ahmeeeeeeeeeeeeeeeeed\n\n";


  cout << transpose(mat1);


/* The next code will not work until you write the functions
  cout << mat1 << endl;
  cout << mat2 << endl;
  cout << mat3 << endl;

  cout << (mat1 + mat3) << endl << endl;
  cout << (mat3 + mat3) << endl << endl;

  ++mat1;
  cout << mat1 << endl;

  mat1+= mat3 += mat3;
  cout << mat1 << endl;
  cout << mat2 << endl;
  cout << mat3 << endl;
  // Add more examples of using matrix
  // .......
*/
  return 0;
}
// End Main Function
//__________________________________________


//__________________________________________
// Takes an array of data and stores in matrix according
// to rows and columns
void createMatrix (int row, int col, int num[], matrix& mat) {
  mat.row = row;
  mat.col = col;
  mat.data = new int* [row];

  for (i = 0; i < row; i++)
    mat.data[i] = new int [col];

  for (i = 0; i < row; i++)
    for (j = 0; j < col; j++)
      mat.data[i][j] = num[i * col + j];
}

//__________________________________________
// Takes two matrices and add them [ Overloading the (+) Operator ]
// Return a new matrix with the result
matrix operator+  (matrix mat1, matrix mat2) {
    if (mat1.row * mat1.col != mat2.row * mat2.col) {
        cout << "Can't add these matrices, because they're not the same size !\n";
    }
    else {
        matrix result;
        createMatrix (mat1.row, mat1.col, fillData, result);

        for (i = 0; i < result.row; i++) {
            for (j = 0; j < result.col; j++)
                result.data[i][j] = mat1.data[i][j] + mat2.data[i][j];
        }
        return result;
    }
}

//__________________________________________
// Takes two matrices and subtract them [ Overloading the (-) Operator ]
// Return a new matrix with the result
matrix operator-  (matrix mat1, matrix mat2) {
    if (mat1.row * mat1.col != mat2.row * mat2.col) {
        cout << "Can't subtract these matrices, because they're not the same size !\n";
    }
    else {
        matrix result;
        createMatrix (mat1.row, mat1.col, fillData, result);

        for (i = 0; i < result.row; i++) {
            for (j = 0; j < result.col; j++)
                result.data[i][j] = mat1.data[i][j] - mat2.data[i][j];
        }
        return result;
    }
}

//__________________________________________
// Takes two matrices and multiply them [ Overloading the (*) Operator ]
// Return a new matrix with the result
matrix operator*  (matrix mat1, matrix mat2) {
    if(mat1.col != mat2.row)
        cout << "Can't multiply these two matrices, Col of matrix 1 must be = Row of matrix 2 !\n";
    else {
        matrix result;
        createMatrix (mat1.row, mat2.col, fillData, result);

        for (i = 0; i < result.row; i++) {
            for (j = 0; j < result.col; j++)
                for(int k = 0; k < mat1.col; k++)
                    result.data[i][j] += mat1.data[i][k] * mat2.data[k][j];
        }
        return result;
    }
}

//__________________________________________
// Takes a matrix and a number then add them [ Overloading the (+) Operator ]
// Return a new matrix with the result
matrix operator+  (matrix mat1, int scalar) {
    for (i = 0; i < mat1.row; i++)
        for(j = 0; j < mat1.col; j++)
            mat1.data[i][j] += scalar;
    return mat1;
}

//__________________________________________
// Takes a matrix and a number then subtract them [ Overloading the (-) Operator ]
// Return a new matrix with the result
matrix operator-  (matrix mat1, int scalar) {
    for (i = 0; i < mat1.row; i++)
        for(j = 0; j < mat1.col; j++)
            mat1.data[i][j] -= scalar;
    return mat1;
}

//__________________________________________
// Takes a matrix and a number then multiply them [ Overloading the (*) Operator ]
// Return a new matrix with the result
matrix operator*  (matrix mat1, int scalar) {
    for (i = 0; i < mat1.row; i++)
        for(j = 0; j < mat1.col; j++)
            mat1.data[i][j] *= scalar;
    return mat1;
}

//__________________________________________
// Takes two matrices and add them [ Overloading the (+=) Operator ]
// Changes mat1 to the sum of the two matrices, return it with the result
matrix operator+= (matrix& mat1, matrix mat2) {
    if (mat1.row * mat1.col != mat2.row * mat2.col) {
        cout << "Can't add these matrices, because they're not the same size !\n";
    }
    else {
        for (i = 0; i < mat1.row; i++)
            for(j = 0; j < mat1.col; j++)
            mat1.data[i][j] += mat2.data[i][j];
    }
    return mat1;
}

//__________________________________________
// Takes two matrices and subtract them [ Overloading the (-=) Operator ]
// Changes mat1 to the subtraction of the two matrices, return it with the result
matrix operator-= (matrix& mat1, matrix mat2) {
    if (mat1.row * mat1.col != mat2.row * mat2.col) {
        cout << "Can't subtract these matrices, because they're not the same size !\n";
    }
    else {
        for (i = 0; i < mat1.row; i++)
            for(j = 0; j < mat1.col; j++)
            mat1.data[i][j] -= mat2.data[i][j];
    }
    return mat1;
}

//__________________________________________
// Takes a matrix and a number and add them [ Overloading the (+=) Operator ]
// Changes mat to the sum of the matrix and scalar, return it with the result
matrix operator+= (matrix& mat, int scalar) {
    for (i = 0; i < mat.row; i++)
        for(j = 0; j < mat.col; j++)
            mat.data[i][j] += scalar;
    return mat;
}

//__________________________________________
// Takes a matrix and a number and subtract them [ Overloading the (-=) Operator ]
// Changes mat to the subtraction of the matrix and scalar, return it with the result
matrix operator-= (matrix& mat, int scalar) {
    for (i = 0; i < mat.row; i++)
        for(j = 0; j < mat.col; j++)
            mat.data[i][j] -= scalar;
    return mat;
}

//__________________________________________
// Takes a matrix and increment each element with 1 [ Overloading the prefix(++) Operator ]
void   operator++ (matrix& mat) {
    for (i = 0; i < mat.row; i++)
        for(j = 0; j < mat.col; j++)
            ++mat.data[i][j];
}

//__________________________________________
// Takes a matrix and decrement each element with 1 [ Overloading the prefix(--) Operator ]
void   operator-- (matrix& mat) {
    for (i = 0; i < mat.row; i++)
        for(j = 0; j < mat.col; j++)
            --mat.data[i][j];
}

//__________________________________________
// Takes an istream and a matrix [ Overloading the (>>) Operator ]
// return the same istream so it is possible to cascade input like cin >> matrix1 >> matrix2;
istream& operator>> (istream& in, matrix& mat) {
    cout << "Enter number of rows: ";
    in >> mat.row;
    cout << "Enter number of columns: ";
    in >> mat.col;
    int temp[mat.row * mat.col];
    cout << "Enter data > ";
    for (i = 0; i < mat.row * mat.col; i++)
        in >> temp[i];
    createMatrix(mat.row, mat.col, temp, mat);
    return in;
}

//__________________________________________
// Takes an ostream and a matrix [ Overloading the (<<) Operator ]
// return the same ostream so it is possible to cascade input like cout << matrix1 << matrix2;
ostream& operator<< (ostream& out, matrix mat) {
    for (int i = 0; i < mat.row; i++){
        for (int j =0; j < mat.col; j++)
            out << mat.data[i][j] << "\t";
        out << endl;
    }
    return out;
}

//__________________________________________
bool operator== (matrix mat1, matrix mat2) {
    if (mat1.row * mat1.col != mat2.row * mat2.col) {
        return false;
    }
    for (int i = 0; i < mat1.row; i++){
        for (int j =0; j < mat1.col; j++){
            if(mat1.data[i][j] != mat2.data[i][j])
                return false;
        }
    }
    return true;
}

//__________________________________________
bool operator!= (matrix mat1, matrix mat2) {
    if (mat1.row * mat1.col != mat2.row * mat2.col) {
        return true;
    }
    for (int i = 0; i < mat1.row; i++){
        for (int j =0; j < mat1.col; j++){
            if(mat1.data[i][j] != mat2.data[i][j])
                return true;
        }
    }
    return false;
}

//__________________________________________
bool isSquare (matrix mat) {
    if (mat.row == mat.col)
        return true;
    else
        return false;
}

//__________________________________________
bool   isSymetric (matrix mat) {
    if (isSquare(mat)) {
        for (int i = 0; i < mat.row; i++){
            for (int j =0; j < mat.col; j++){
                if(mat.data[i][j] != mat.data[j][i])
                    return false;
            }
        }
        return true;
    }
    else {
        return false;
    }
}

//__________________________________________
bool   isIdentity (matrix mat) {
    if (isSquare(mat)) {
        for (int i = 0; i < mat.row; i++){
            for (int j =0; j < mat.col; j++){
                if (i == j && mat.data[i][j] != 1)
                    return false;
                else if (i != j && mat.data[i][j] != 0)
                    return false;
            }
        }
        return true;
    }
    else {
        return false;
    }

}  // True if square and identity

//__________________________________________
matrix transpose(matrix mat) {
    matrix temp;
    createMatrix(mat.col, mat.row, fillData, temp);
    for (int i = 0; i < mat.row; i++){
        for (int j =0; j < mat.col; j++){
            temp.data[j][i] = mat.data[i][j];
        }
    }
    return temp;
}  // Return new matrix with the transpose



