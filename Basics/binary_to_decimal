#include<iostream>
using namespace std;
int main() {
	int n;
	cin>>n;
	int binary;


	for(int i=1;i<=n;i++){
        int mul = 1;
        int sum = 0;
		cin>>binary;
		while(binary!=0){
			int num = binary%10;

			num = num*mul;
			sum = sum + num;
			binary = binary/10;
			mul = mul*2;
		}
		cout<<sum<<endl;

	}
	return 0;
}
