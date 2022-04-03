#include "Matrix.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace zich;
using namespace std;

Matrix::Matrix(){

}

Matrix::Matrix(vector<double> v, int rows, int cols){
    int k = 0;
    for(int i = 0; i < rows; i++){
        vector<double> temp;
        for(int j = 0; j < cols; j++){
            temp.push_back(v[k++]);
        }
        this->matrix.push_back(temp);
    }
    this->rows = rows;
    this->cols = cols;
}



vector<double> convert_to_vector(vector<vector<double> > matrix , int rows, int cols){
      vector<double> v;
      for(int i = 0; i < rows; i++){
         for(int j = 0; j < cols; j++){
             v.push_back(matrix[i][j]);
    }
}
return v;
}

double sum_matrix(Matrix &m){
    double sum = 0;
     for(int i = 0; i < m.getRows(); i++){
         for(int j = 0; j < m.getCols(); j++){
            sum += m.getMat()[i][j];
    }

}
return sum;
}

bool check_eq(Matrix &m1, Matrix &m2){
       for(int i = 0; i < m1.getRows(); i++){
         for(int j = 0; j < m1.getCols(); j++){
             if(m1.getMat()[i][j] != m2.getMat()[i][j]){
                return false;
             }
         }
}
 return true;
}

bool check_sizes(Matrix &m1, Matrix &m2){
    if(m1.getCols() != m2.getCols() || m1.getRows() != m2.getRows()){
        return false;
    }
    return true;
}

Matrix Matrix::operator+(Matrix &m){
    if(!check_sizes(*this, m)){
        throw std::invalid_argument("Must be same dimensions");
    }
    vector<vector<double> > copy_matrix = matrix;
    for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                copy_matrix[i][j] += m.matrix[i][j];
    }
}
    return Matrix(convert_to_vector(copy_matrix, rows, cols), rows, cols);
}

Matrix Matrix::operator+=(double num){
     for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    this->matrix[i][j]+= num;
    }
}
    return *this;
}


Matrix Matrix::operator+(){ //unary plus????
    vector<vector<double> > copy_matrix = matrix;
   for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(copy_matrix[i][j] == 0){
                continue;
            }
           copy_matrix[i][j] = abs(copy_matrix[i][j]);
        }
      }
     return Matrix(convert_to_vector(copy_matrix, rows, cols), rows, cols);
}

Matrix operator+ (Matrix &m, int num){ //regular number addition
    return Matrix();
}

Matrix Matrix::operator- (Matrix &m){
      if(!check_sizes(*this, m)){
        throw std::invalid_argument("Must be same dimensions");
    }
    vector<vector<double> > copy_matrix = matrix;
    for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                copy_matrix[i][j] -= m.matrix[i][j];
    }
}
    return Matrix(convert_to_vector(copy_matrix, rows, cols), rows, cols);
}
Matrix Matrix::operator-= (double num){
      for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    this->matrix[i][j] -= num;
    }
}
    return *this;
}
Matrix operator- (Matrix &m, int num){ //regular number substraction
    return Matrix();
}

Matrix Matrix::operator- (){ //unary minus
    vector<vector<double> > copy_matrix = matrix;
      for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(copy_matrix[i][j] == 0){
                continue;
            }
            copy_matrix[i][j] *= -1;
        }
      }
       return Matrix(convert_to_vector(copy_matrix, rows, cols), rows, cols);
}

bool Matrix::operator>(Matrix &m){
    double sum1 = sum_matrix(*this);
    double sum2 = sum_matrix(m);
    if(sum1 > sum2){
        return true;
    }
    return false;
  }
bool Matrix::operator>=(Matrix &m){
    double sum1 = sum_matrix(*this);
    double sum2 = sum_matrix(m);
    if(sum1 >= sum2){
        return true;
    }
    return false;
  }

bool Matrix::operator<(Matrix &m){
     double sum1 = sum_matrix(*this);
    double sum2 = sum_matrix(m);
    if(sum1 < sum2){
        return true;
    }
    return false;
}
bool Matrix::operator<=(Matrix &m){
    double sum1 = sum_matrix(*this);
    double sum2 = sum_matrix(m);
    if(sum1 <= sum2){
        return true;
    }
    return false;
}
bool Matrix::operator==(Matrix &m){
    return check_eq(*this, m); 
}
bool Matrix::operator!=(Matrix &m){
    return !check_eq(*this, m); 
}


Matrix Matrix::operator++ (){
     for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            this->matrix[i][j] += 1;
        }
}
return *this;
}

Matrix Matrix::operator++ (int){
    Matrix temp = *this;
       for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            this->matrix[i][j] += 1;
        }
}
return temp;
}
Matrix Matrix::operator-- (){
      for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            this->matrix[i][j] -= 1;
        }
}
return *this;
}
Matrix Matrix::operator-- (int){
      Matrix temp = *this;
       for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            this->matrix[i][j] -= 1;
        }
}
return temp;
}

Matrix Matrix::operator*(Matrix &m){
    if(cols != m.rows){
        throw std::invalid_argument("Cols and Rows must be the same"); 
    }
    vector<double> v (m.cols, 0);
    Matrix result(v, rows, m.cols);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < m.cols; j++){
            result.matrix[i][j] = 0;
            for(int k = 0; k < m.rows; k++){
                 result.matrix[i][j] += matrix[i][k] * m.matrix[k][j];
            }
        }
    }
    return result;
}
Matrix Matrix::operator*=(double num){
    for(int i = 0; i < this->rows; i++){
        for(int j = 0; j < this->cols; j++){
            this->matrix[i][j] *= num;
        }
    }
    return *this;
}
 
// istream& operator>>(istream  &input, Matrix &m){
//     return input;
// }

int main(){
    int arr1[] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    int arr2[]= {3, 0, 0, 0, 3, 0, 0, 0, 3};
    int arr3[]= {3, 0, 0, 0, 3, 0, 0, 0, 3};
    vector<double> v1(arr1, arr1+9);
    vector<double> v2(arr2, arr2 + 9);
    vector<double> v3(arr3, arr3 + 9);
    Matrix a(v1, 3 , 3);
    Matrix b(v2, 3 , 3);
    Matrix c(v3, 1, 9);
    cout << -a;
    cout << a;
    cout << 3 * a; 
    cout << a;
    return 0;
}