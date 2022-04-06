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
        Matrix operator+ (Matrix &m);
        Matrix operator+= (double num);
        Matrix operator+= (Matrix &m);
        Matrix operator+ ();
        Matrix operator- (Matrix &m);
        Matrix operator-= (double num);
        Matrix operator-= (Matrix &m);
        Matrix operator- ();
        bool operator>(Matrix &m);
        bool operator>=(Matrix &m);
        bool operator<(Matrix &m);
        bool operator<=(Matrix &m);
        bool operator==(Matrix &m);
        bool operator!=(Matrix &m);
        // friend Matrix operator- (Matrix &m, int num);
        // friend Matrix operator+ (Matrix &m, int num);
        Matrix operator++ ();  
        Matrix operator++ (int);
        Matrix operator-- (); 
        Matrix operator-- (int); 
        friend Matrix operator*(double num, Matrix &m);
        Matrix operator*(Matrix &m);
        Matrix operator*=(double num);
        friend ostream& operator<<(ostream& os, const Matrix &m);
        friend istream& operator>>(istream& input, Matrix &m);
        


    int getRows(){
        return rows;
    }

     int getCols(){
        return cols;
    }
     
     vector<vector<double> > getMat(){
         return matrix;
     }

    };

     
}