#include<iostream>
using namespace std;
//int cnt=0;
bool rat(char maze[][10],int sol[][10],int i,int j,int m,int n)
{
    if(i==m and j==n){
        //cnt++;
        sol[m][n]=1;
        for(i=0;i<=m;i++){
            for(j=0;j<=n;j++){
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }
    if(i>m or j>n or i<0 or j<0 or sol[i][j]){
        return false;
    }
    if(maze[i][j]=='X'){
        return false;
    }
	bool down=false,left=false,up=false,right=false;
    sol[i][j]=1;

    right=rat(maze,sol,i,j+1,m,n);
	if(right==false){
     down=rat(maze,sol,i+1,j,m,n);}
	if(down==false){
	left=rat(maze,sol,i,j-1,m,n);}
	if(left==false){
	 up=rat(maze,sol,i-1,j,m,n);}

    sol[i][j]=0;
    if(right or down or left or up){
        return true;
    }
    else{
        return false;
    }
}


int main()
{
    int m,n,i,j;
	cin>>m>>n;
    char maze[10][10];
	for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                cin>>maze[i][j];
            }
	}
    int sol[10][10]={0};
    bool ans=rat(maze,sol,0,0,m-1,n-1);
    if(ans==false){
        cout<<"NO PATH FOUND";
    }
    //cout<<endl<<cnt;

}
