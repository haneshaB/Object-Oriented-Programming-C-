#include <bits/stdc++.h>
using namespace std;

class matrix{
public:
    int row, col;
    vector<vector<int>> mat;

    matrix(int r, int c){
        row = r;
        col = c;
        mat.resize(row, vector<int>(col));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                cin >> mat[i][j];
            }
        }
    }

    matrix(){}

    void display(){
        for(int i=0;i<row;i++){ 
            for(int j=0;j<col;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    matrix operator+(matrix& mat2){
        matrix temp;
        temp.row = row;
        temp.col = col;
        temp.mat.assign(row, vector<int>(col,0));

        for(int i=0;i<row;i++){ 
            for(int j=0;j<col;j++){
                temp.mat[i][j] = mat[i][j] + mat2.mat[i][j];
            }
        }
        return temp;
    }

    matrix operator*(matrix& mat2){
        matrix temp;
        temp.row = row;
        temp.col = mat2.col;
        temp.mat.assign(row, vector<int>(mat2.col,0));

        for(int i=0;i<row;i++){
            for(int j=0;j<mat2.col;j++){
                for(int k=0;k<col;k++){
                    temp.mat[i][j] += mat[i][k] * mat2.mat[k][j];
                }
            }
        }
        return temp;
    }

    bool operator==(matrix& mat2){
        if(row != mat2.row || col != mat2.col) return false;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j] != mat2.mat[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
};

//////////////////////////////////////////////////////////
// DETERMINANT FUNCTION
//////////////////////////////////////////////////////////
int determinant(vector<vector<int>> a, int n){
    if(n == 1) return a[0][0];

    int det = 0;
    int sign = 1;

    for(int f = 0; f < n; f++){
        vector<vector<int>> sub(n-1, vector<int>(n-1));
        for(int i=1;i<n;i++){
            int colIndex = 0;
            for(int j=0;j<n;j++){
                if(j == f) continue;
                sub[i-1][colIndex++] = a[i][j];
            }
        }
        det += sign * a[0][f] * determinant(sub, n-1);
        sign = -sign;
    }

    return det;
}

//////////////////////////////////////////////////////////

class SquareMatrix: public matrix{
public:
    int n;

    SquareMatrix(int k): matrix(k,k){
        n = k;
    }

    void compute(){
        int det = determinant(mat, n);
        cout << det << endl;
    }
};

class DiagonalMatrix: public matrix{
public:
    int n;

    DiagonalMatrix(int k): matrix(k,k){
        n = k;
    }

    void compute(){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] != 0 && i != j){
                    cout<<"false"<<endl;
                    return;
                }
            }
        }
        cout<<"true"<<endl;
    }
};

//////////////////////////////////////////////////////////

int main(){

    string s;
    cin>>s;

    if(s=="P1"){
        int row,col;
        cin>>row>>col;
        matrix mat(row,col);
        mat.display();
    }

    else if(s=="P2"){
        int r1,c1,r2,c2;
        cin>>r1>>c1;
        matrix m1(r1,c1);

        cin>>r2>>c2;
        matrix m2(r2,c2);

        int op;
        cin>>op;

        if(op==1){
            if(r1!=r2 || c1!=c2){
                cout<<"incompatible matrices"<<endl;
            }
            else{
                matrix m3 = m1 + m2;
                m3.display();
            }
        }

        else if(op==2){
            if(c1!=r2){
                cout<<"incompatible matrices"<<endl;
            }
            else{
                matrix m3 = m1 * m2;
                m3.display();
            }
        }

        else{
            if(r1!=r2 || c1!=c2){
                cout<<"incompatible matrices"<<endl;
            }
            else{
                cout << (m1==m2 ? "true" : "false") << endl;
            }
        }
    }

    else if(s=="P3"){
        int type;
        cin>>type;
        int n;
        cin>>n;

        if(type==1){
            SquareMatrix mat(n);
            mat.compute();   // determinant
        }
        else{
            DiagonalMatrix mat(n);
            mat.compute();
        }
    }

    return 0;
}