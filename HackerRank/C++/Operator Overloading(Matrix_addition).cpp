/*
Problem:
https://www.hackerrank.com/challenges/operator-overloading/problem

Resources:
https://www.geeksforgeeks.org/matrix-operations-using-operator-overloading/
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// user code starts

class Matrix {
  public:
    vector<vector<int>> a;
    Matrix operator + (const Matrix &m);
};

// return type, class name, scope resolution operator, method signature
Matrix Matrix :: operator + (const Matrix &m) {
    Matrix addition;
    int row = this -> a.size();
    int col = this -> a[0].size();

    for(int i = 0; i < row; i++) {
        vector<int> b;
        for(int j = 0; j < col; j++) {
            b.push_back(this -> a[i][j] + m.a[i][j]);
        }
        addition.a.push_back(b);
    }
    return addition;
}
// another solution (not creating any additional Matrix object, hence it consumes less memory)
/**
Matrix Matrix :: operator + (const Matrix &m) {
    int row = this -> a.size();
    int col = this -> a[0].size();

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            this->a[i][j] += m.a[i][j];
        }
    }
    return (*this); //  pointer (Matrix *) of the current obj
}
*/
// user code ends

int main () {
   int cases,k;
   cin >> cases;
   for(k=0;k<cases;k++) {
      Matrix x;
      Matrix y;
      Matrix result;
      int n,m,i,j;
      cin >> n >> m;
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         x.a.push_back(b);
      }
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         y.a.push_back(b);
      }
      result = x+y;
      for(i=0;i<n;i++) {
         for(j=0;j<m;j++) {
            cout << result.a[i][j] << " ";
         }
         cout << endl;
      }
   }
   return 0;
}
