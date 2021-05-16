// 5 3 0 0 7 0 0 0 0 
// 6 0 0 1 9 5 0 0 0 
// 0 9 8 0 0 0 0 6 0 
// 8 0 0 0 6 0 0 0 3 
// 4 0 0 8 0 3 0 0 1 
// 7 0 0 0 2 0 0 0 6 
// 0 6 0 0 0 0 2 8 0 
// 0 0 0 4 1 9 0 0 5 
// 0 0 0 0 8 0 0 7 9 

#include <iostream>
#include <cmath>
using namespace std;
bool canPlace(int a[][9], int i, int j, int n, int num){
    //row-col check
    for(int x=0;x<n;x++){
        if(a[x][j]==num or a[i][x]==num){
            return false;
        }
    }

    //for grid
    int rn = sqrt(n);
    int sx = (i/rn)*rn; //x coord start of grid
    int sy = (j/rn)*rn; //y coord start of grid
    for(int x =sx;x<sx+rn;x++){
        for(int y=sy;y<sy+rn;y++){
            if(a[x][y]==num){
                return false;
            }
        }
    }
    return true;
}
bool solveSudoku(int a[][9], int i, int j, int n){
    //base
    if(i==n){
        //print
        for(int x=0;x<n;x++){
            for( int b=0;b<n;b++){
                cout<<a[x][b]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    //case for row ends
    if(j==n){
        return solveSudoku(a, i+1, 0, n);
    }
    //skip pre filled cells
    if(a[i][j]!=0){
        return solveSudoku(a, i, j+1, n);
    }
    //rec
    for(int num=1;num<=9;num++){
        if(canPlace(a, i, j, n, num)){
            a[i][j]=num;
            bool couldWeSolve = solveSudoku(a, i, j+1,n);
            if(couldWeSolve){
                return true;
            }
        }
    }
    //backtrack
    a[i][j]=0;
    return false;
}
int main() {
    int n;
    cin>>n;
    int a[9][9];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    solveSudoku(a,0,0,n);
}

