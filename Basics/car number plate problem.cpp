#include<iostream>
using namespace std;
int main() {
	int n;
	int num;
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num;
		int temp = num;
		int sum_odd=0;
	int sum_even = 0;
		while(temp>0){
			int digit = temp%10;
			if(digit%2==0){
				sum_even=sum_even+digit;
			}
			else{
				sum_odd=sum_odd+digit;
			}
			temp=temp/10;
		}
	
		if((sum_even%4==0) || (sum_odd%3==0)){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}
