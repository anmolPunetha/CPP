#include<iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	int a[100000];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		bool x=false;
		for(int j=i+1;j<n;j++){
			if(a[j]>a[i]){
				cout<<a[j]<<" ";
				x=true;
				break;
			}
		}
		if(x==0){
			for(int k=0;k<i;k++){
				if(a[k]>a[i]){
					cout<<a[k]<<" ";
					x=true;
					break;
				}
			}
		}
		if(x==0){
			cout<<-1<<" ";
		}
		
	}
	return 0;
}
