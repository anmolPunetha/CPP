#include <iostream>
using namespace std;
//m-row
bool ratInMaze(char maze[1000][1000], int soln[][1000], int i, int j, int m, int n){
    if(i==m and j==n){
        soln[m][n]=1;
        //print
        for(int a=0;a<=m;a++){
            for(int b=0;b<=n;b++){
                cout<<soln[a][b]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }
    //rat should be inside
    if(i>m or j>n){
        return false;
    }
    if(maze[i][j]=='X'){
        return false;
    }
    //assume solun exists through current cell
    soln[i][j]=1;
    bool rightSuccess = ratInMaze(maze, soln, i, j+1, m ,n);
	bool downSuccess;
	if(!rightSuccess){
		downSuccess = ratInMaze(maze, soln, i+1, j, m ,n);
	}
    

    //backtrack
    soln[i][j]=0;

    if(rightSuccess or downSuccess ){
        return true;
    }
    return false;
}
int main() {
    int m,n;
    cin>>m>>n;
    char maze[1000][1000];
    int soln[1000][1000]={0};
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>maze[i][j];
        }
    }

    bool val = ratInMaze(maze, soln, 0, 0, m-1, n-1);
    if(val==0){
		cout<<-1;
	}
 return 0;
}
