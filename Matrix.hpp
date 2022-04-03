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
        // vector<double> convert_to_vector(vector<vector<double> > matrix , int rows, int cols);
        Matrix();
        Matrix(vector<double> v, int rows, int cols);
        Matrix operator+ (Matrix &m);
        Matrix operator+= (double num);
        Matrix operator+ ();
        Matrix operator- (Matrix &m);
        Matrix operator-= (double num);
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
        
        friend ostream& operator<<(ostream& output, const Matrix &m){
             for(int i = 0; i < m.rows; i++){
                 output << "[";
                for(int j = 0; j < m.cols; j++){
                    output << m.matrix[i][j];         
        }
        cout << "]" << endl;
    }
         return output;
        }

    //     friend Matrix operator*(double num, Matrix &m){
    //     vector<vector<double> > copy_matrix = m.matrix;
    //     for(int i = 0; i < m.rows; i++){
    //     for(int j = 0; j < m.cols; j++){
    //         copy_matrix[i][j] *= num;
    //     }
    // }
    // return Matrix(convert_to_vector(copy_matrix, m.rows, m.cols), m.rows, m.cols);
    // }

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