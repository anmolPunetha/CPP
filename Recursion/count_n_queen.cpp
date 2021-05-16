#include <iostream>
#include <vector>
using namespace std;
bool isSafe(int matrix[][11], int i, int j, int n){
    // check col
    for(int row=0;row<i;row++){
        if (matrix[row][j]==1){
            return false;
        }
    }

    // //left diagonal
    int x,y;
    x =i;
    y =j;
    while(x>=0 and y>=0){
        if(matrix[x][y]==1){
            return false;
        }
        x--;
        y--;
    }

    //right diagonal
    x=i;
    y=j;
    while(x>=0 and y<n){
        if(matrix[x][y]==1){
            return false;
        }
        x--;
        y++;
    }
    return true;
    

}
//i is the row
bool solveNqueen(int matrix[][11], int n, int i, vector<int> &v){
    if(i==n){
		v.push_back(1);
        // print
        // for(int a=0;a<n;a++){
        //     for(int b=0;b<n;b++){
        //         cout<<matrix[a][b]<<" ";
        //     }
        //     cout<<endl;
        // }
		// cout<<endl;
        return false;
    }
    //rec
    for(int j=0;j<n;j++){
        if(isSafe(matrix,i,j,n)){
            //place the queen
            matrix[i][j]=1;
            bool nextQueenplaced = solveNqueen(matrix, n , i+1, v);
            if (nextQueenplaced){
                return true;
            }
            matrix[i][j]=0;
        }
    }
    return false;
}
int main() {
    int n;
    cin>>n;
    int matrix[11][11]={0};
	vector<int> v;
	solveNqueen(matrix,n,0,v);
	cout<<v.size();
}
