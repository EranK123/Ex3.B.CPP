#include "Matrix.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <sstream>
using namespace zich;
using namespace std;

Matrix::Matrix(){

}

Matrix::Matrix(vector<double> v, int rows, int cols){
    
}
Matrix Matrix::operator+(Matrix &m){
    return Matrix();
}

Matrix Matrix::operator+=(double num){
    return Matrix();  
}

Matrix Matrix::operator+(){
    return Matrix();
}

Matrix operator+ (Matrix &m, int num){
    return Matrix();
}

Matrix Matrix::operator- (Matrix &m){
    return Matrix();
}
Matrix Matrix::operator-= (Matrix &m){
    return Matrix();
}
Matrix operator- (Matrix &m, int num){
    return Matrix();
}

bool Matrix::operator>(Matrix &m){
    return true;
  }
bool Matrix::operator>=(Matrix &m){
        return true;
}
bool Matrix::operator<(Matrix &m){
    return true;
}
bool Matrix::operator<=(Matrix &m){
    return true;
}
bool Matrix::operator==(Matrix &m){
    return true;
}
bool Matrix::operator!=(Matrix &m){
    return true;
}

Matrix Matrix::operator- (){
    return Matrix();
}

Matrix Matrix::operator++ (){
    return Matrix();
}
Matrix Matrix::operator++ (int num){
    return Matrix();
}
Matrix Matrix::operator-- (){
    return Matrix();
}
Matrix Matrix::operator-- (int num){
    return Matrix();
}

Matrix Matrix::operator*(Matrix &m){
    return Matrix();
}
Matrix Matrix::operator*=(double num){
    return Matrix();
}
 
// istream& operator>>(istream  &input, Matrix &m){
//     return input;
// }

// int main(){
//     return 0;
// }