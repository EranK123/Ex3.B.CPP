#include<iostream>
#include <vector>
using namespace std;
namespace zich{
    class Matrix{

        private:
        vector<vector<double> > matrix;
        int rows;
        int cols;

        public:
        Matrix();
        Matrix(vector<double> v, int rows, int cols);
        Matrix(const Matrix &other);
        Matrix operator+ (const Matrix &m);
        Matrix operator+= (double num);
        Matrix operator+= (const Matrix &m);
        Matrix operator+ ();
        Matrix operator- (const Matrix &m);
        Matrix operator-= (double num);
        Matrix operator-= (const Matrix &m);
        Matrix operator- ();
        bool operator>(const Matrix &m);
        bool operator>=(const Matrix &m);
        bool operator<(const Matrix &m);
        bool operator<=(const Matrix &m);
        bool operator==(const Matrix &m);
        bool operator!=(const Matrix &m);
        // friend Matrix operator- (Matrix &m, int num);
        // friend Matrix operator+ (Matrix &m, int num);
        Matrix operator++ ();  
        Matrix operator++ (int);
        Matrix operator-- (); 
        Matrix operator-- (int); 
        friend Matrix operator*(double num, const Matrix &m);
        Matrix operator*(const Matrix &m);
        Matrix operator*=(double num);
        friend ostream& operator<<(ostream& os, const Matrix &m);
        friend istream& operator>>(istream& input, Matrix &m);
        


    int getRows() const{
        return rows;
    }

     int getCols() const{
        return cols;
    }
     
     vector<vector<double> > getMat() const{
         return matrix;
     }

    };

     
}