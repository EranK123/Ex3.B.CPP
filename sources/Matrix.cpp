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

Matrix::Matrix(vector<double> v, int rows, int cols){
    size_t k = 0;
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

Matrix::Matrix(const Matrix &other){
    this->matrix = other.matrix;
    this->rows = other.rows;
    this->cols = other.cols;
}


double sum_matrix(const Matrix &m){
    double sum = 0;
     for(size_t i = 0; i < m.getRows(); i++){
         for(size_t j = 0; j < m.getCols(); j++){
            sum += m.getMat()[i][j];
    }

}
return sum;
}

bool check_eq(const Matrix &m1,const  Matrix &m2){
       for(size_t i = 0; i < m1.getRows(); i++){
         for(size_t j = 0; j < m1.getCols(); j++){
             if(m1.getMat()[i][j] != m2.getMat()[i][j]){
                return false;
             }
         }
}
 return true;
}

bool check_sizes(const Matrix &m1,const Matrix &m2){
    if (m1.getCols() != m2.getCols() || m1.getRows() != m2.getRows()){
        return false;
    }
    return true;
}

Matrix Matrix::operator+(const Matrix &m){
    if(!check_sizes(*this, m)){
        throw std::invalid_argument("Must be same dimensions");
    }
    Matrix mat(*this);
    for(size_t i = 0; i < rows; i++){
            for(size_t j = 0; j < cols; j++){
                mat.matrix[i][j] += m.matrix[i][j];
    }
}
return mat;
}

Matrix Matrix::operator+=(double num){
     for(size_t i = 0; i < rows; i++){
                for(size_t j = 0; j < cols; j++){
                    this->matrix[i][j]+= num;
    }
}
    return *this;
}

Matrix Matrix::operator+=(const Matrix &m){
     if(!check_sizes(*this, m)){
        throw std::invalid_argument("Must be same dimensions");
    }
    for(size_t i = 0; i < rows; i++){
                for(size_t j = 0; j < cols; j++){
                    this->matrix[i][j] += m.matrix[i][j];
    }
}
    return *this;
}


Matrix Matrix::operator+(){ 
   Matrix mat(*this);
   for(size_t i = 0; i < rows; i++){
        for(size_t j = 0; j < cols; j++){
            if(mat.matrix[i][j] == 0){
                continue;
            }
           mat.matrix[i][j] = abs(mat.matrix[i][j]);
        }
      }
      return mat;
    }

// Matrix operator+ (const Matrix &m, int num){ //regular number addition
//     return Matrix();
// }

Matrix Matrix::operator- (const Matrix &m){
     if(!check_sizes(*this, m)){
        throw std::invalid_argument("Must be same dimensions");
    }
      if(!check_sizes(*this, m)){
        throw std::invalid_argument("Must be same dimensions");
    }
    Matrix mat(*this);
    for(size_t i = 0; i < rows; i++){
            for(size_t j = 0; j < cols; j++){
                mat.matrix[i][j] -= m.matrix[i][j];
    }
}
return mat;
}
Matrix Matrix::operator-= (double num){
      for(size_t i = 0; i < rows; i++){
                for(size_t j = 0; j < cols; j++){
                    this->matrix[i][j] -= num;
    }
}
    return *this;
}

Matrix Matrix::operator-= (const Matrix &m){
     if(!check_sizes(*this, m)){
        throw std::invalid_argument("Must be same dimensions");
    }
     for(size_t i = 0; i < rows; i++){
                for(size_t j = 0; j < cols; j++){
                    this->matrix[i][j] -= m.matrix[i][j];
    }
}
    return *this;
}

// Matrix operator- (Matrix &m, int num){ //regular number substraction
//     return Matrix();
// }

Matrix Matrix::operator- (){ //unary minus
    Matrix mat(*this);
      for(size_t i = 0; i < rows; i++){
        for(size_t j = 0; j < cols; j++){
            if(mat.matrix[i][j] == 0){
                continue;
            }
            mat.matrix[i][j] *= -1;
        }
      }
 return mat;   
}

bool Matrix::operator>(const Matrix &m) const{
     if(!check_sizes(*this, m)){
        throw std::invalid_argument("Must be same dimensions");
    }
    double sum1 = sum_matrix(*this);
    double sum2 = sum_matrix(m);
    return (sum1 > sum2);
}
bool Matrix::operator>=(const Matrix &m) const{
     if(!check_sizes(*this, m)){
        throw std::invalid_argument("Must be same dimensions");
    }
    double sum1 = sum_matrix(*this);
    double sum2 = sum_matrix(m);
    return(sum1 >= sum2);
  }

bool Matrix::operator<(const Matrix &m) const{
     if(!check_sizes(*this, m)){
        throw std::invalid_argument("Must be same dimensions");
    }
    double sum1 = sum_matrix(*this);
    double sum2 = sum_matrix(m);
    return(sum1 < sum2);
}
bool Matrix::operator<=(const Matrix &m) const{
     if(!check_sizes(*this, m)){
        throw std::invalid_argument("Must be same dimensions");
    }
    double sum1 = sum_matrix(*this);
    double sum2 = sum_matrix(m);
    return(sum1 <= sum2);
}

bool Matrix::operator==(const Matrix &m) const{
     if(!check_sizes(*this, m)){
        throw std::invalid_argument("Must be same dimensions");
    }
    return check_eq(*this, m); 
}

bool Matrix::operator!=(const Matrix &m) const{
     if(!check_sizes(*this, m)){
        throw std::invalid_argument("Must be same dimensions");
    }
    return !check_eq(*this, m); 
}

Matrix Matrix::operator++ (){
     for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            this->matrix[i][j] += 1;
        }
}
return *this;
}

Matrix Matrix::operator++ (int){
    Matrix temp = *this;
       for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            this->matrix[i][j] += 1;
        }
}
return temp;
}
Matrix Matrix::operator-- (){
      for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            this->matrix[i][j] -= 1;
        }
}
return *this;
}
Matrix Matrix::operator-- (int){
      Matrix temp = *this;
       for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            this->matrix[i][j] -= 1;
        }
}
return temp;
}

Matrix Matrix::operator*(const Matrix &m){
    if(this->cols != m.rows){
        throw std::invalid_argument("Cols and Rows must be the same"); 
    }
    vector<double> v (size_t(m.cols), 0);
    Matrix result(v, rows, m.cols);
    for(size_t i = 0; i < rows; i++){
        for(size_t j = 0; j < m.cols; j++){
            result.matrix[i][j] = 0;
            for(size_t k = 0; k < m.rows; k++){
                 result.matrix[i][j] += matrix[i][k] * m.matrix[k][j];
            }
        }
    }
    return result;
}
Matrix Matrix::operator*=(double num){
    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            this->matrix[i][j] *= num;
        }
    }
    return *this;
}

Matrix Matrix::operator*=(const Matrix &m){
    for(size_t i = 0; i < this->rows; i++){
        for(size_t j = 0; j < this->cols; j++){
            this->matrix[i][j] *= m.matrix[i][j];
        }
    }
    return *this;
}
 
zich::Matrix zich::operator*(double num, const Matrix &m){
        Matrix mat(m); 
        for(size_t i = 0; i < m.rows; i++){
        for(size_t j = 0; j < m.cols; j++){
            mat.matrix[i][j] *= num;
        }
    }
    return mat;
    }

zich::Matrix zich::operator*(const Matrix &m, double num){
        Matrix mat(m); 
        for(size_t i = 0; i < m.rows; i++){
        for(size_t j = 0; j < m.cols; j++){
            mat.matrix[i][j] *= num;
        }
    }
    return mat;
    }

    ostream& zich::operator<<(ostream& output, const Matrix &m){
             for(size_t i = 0; i < m.rows; i++){
                 output << "[";
                for(size_t j = 0; j < m.cols; j++){
                    if(j == m.cols-1){
                        output << m.matrix[i][j]; 
                    }
                    else{
                        output << m.matrix[i][j] << " "; 
                    }
                            
        }
        cout << "]" << '\n';
    }
         return output;
        }
istream& operator>>(istream &input, Matrix &m){
    return input;
}

// int main(){
//      vector<double> identity_3 = {1,0,0,0,1,0,0,0,1};//3x3
//     vector<double> vec1 = {1,1,1,1,1,1,1,1,1};//3x3
//     vector<double> arr = {2,1,1,1,2,1,1,1,2};//3x3   arr = identity_3 + vec1
//     vector<double> vec2 = {1,0,0,0,0,1,0,0,0,0,1,0};//3x4
//     vector<double> identity_4 = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};//4x4
//     Matrix mat1(identity_3,3,3);
//     Matrix mat2(vec2,3,4);
//     Matrix mat3(identity_4,4,4);
//     Matrix mat4_arr(arr,3,3);
//      for (double i = 0; i < 500; i++)
//     {
//     vector<double> arr1 = {i, i+1, i+2, i+3};//2x2
//     vector<double> arr2 = {i,i,i,i,i,i,i,i,i};//3x3
//     vector<double> arr = {i};//1x1
//     Matrix mat1(arr1,2,2);
//     Matrix mat2(arr2,3,3);
//     Matrix mat(arr,1,1);
//     mat1+mat2;    
// }
// }
