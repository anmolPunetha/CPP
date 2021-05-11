#include<iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	int row=1;
	while(row<=n){
		if(row==1 or row==n){
			for(int i=1;i<=n;i++){
				cout<<'*'<<'\t';
			}
		}
		if(row==(n+1)/2){
			cout<<'*'<<'\t';
			for(int i=1;i<=n-2;i++){
				cout<<" "<<'\t';
			}
			cout<<'*'<<'\t';
		}
		if(row>1 and row<(n+1)/2){
			for(int i=1;i<(n+1)/2-(row-2);i++){
				cout<<'*'<<'\t';
			}
			for(int i=1;i<=2*(row-1)-1;i++){
				cout<<" "<<'\t';
			}
			for(int i=1;i<(n+1)/2-(row-2);i++){
				cout<<'*'<<'\t';
			}
		}
		if(row>(n+1)/2 and row<n){
			int temp=row-(n+1)/2;
			for(int i=1;i<=temp+1;i++){
				cout<<'*'<<'\t';
			}
			for(int i=1;i<=(n-2*(temp+1));i++){
				cout<<" "<<'\t';
			}
			for(int i=1;i<=temp+1;i++){
				cout<<'*'<<'\t';
			}
		}
		cout<<endl;
		row++;
	}
	return 0;
}
