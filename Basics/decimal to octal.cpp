#include<iostream>
#include<math.h>
using namespace std;
int main() {
	int deci;
	cin>>deci;
	int octal=0;
	int i=0;
	while(true){
		int digit = deci%8;
		octal = octal + digit*pow(10,i);
		i++;
		deci=deci/8;
		if(deci==0){
			break;
		}
	}
	cout<<octal<<endl;
	return 0;
}
