#include<iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	int row=1;
	while(row<=n){
		if(row==1){
			cout<<'*';
			for(int i=1;i<(n+1)/2-1;i++){
				cout<<" ";
			}
			for(int i=1;i<=(n+1)/2;i++){
				cout<<"*";
			}
		}
		if(row==n){
			for(int i=1;i<=(n+1)/2;i++){
				cout<<"*";
			}
			for(int i=1;i<=(n+1)/2-2;i++){
				cout<<" ";
			}
			cout<<"*";
		}
		if(row==(n+1)/2){
			for(int i=1;i<=n;i++){
				cout<<"*";
			}
		}
		if(row>1 and row<(n+1)/2){
			cout<<'*';
			for(int i=1;i<=(n+1)/2-2;i++){
				cout<<' ';
			}
			cout<<'*';
		}
		if(row>(n+1)/2 and row<n){
			for(int i=1;i<(n+1)/2;i++){
				cout<<" ";
			}
			cout<<'*';
			for(int i=1;i<=(n+1)/2-2;i++){
				cout<<' ';
			}
			cout<<'*';
		}
		cout<<endl;
		row++;
	}
	return 0;
}
