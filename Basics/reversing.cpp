#include<iostream>
#include<math.h>
using namespace std;
int main() {
	int n;
	cin>>n;

	int reverse=0;
	int len=0;
	int temp = n;
	while(temp>0){
		int digit = temp%10;
		len++;
		temp=temp/10;
	}
	
	while(n>0){
		int digit=n%10;
		reverse = reverse + digit*pow(10,(len-1));
		len--;
		n=n/10;

	}
	cout<<reverse<<endl;
	return 0;
}
