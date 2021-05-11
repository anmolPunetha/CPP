#include<iostream>
#include<math.h>
using namespace std;
int main() {
	int a,b,c;
	cin>>a>>b>>c;

	int r1, r2;
	int d = sqrt(pow(b,2) - 4*a*c);
	if(d>0){
		cout<<"Real and Distinct"<<endl;
		r1 = (-b + d)/(2*a);
		r2 = (-b - d)/(2*a);
		if(r1>r2){
			cout<<r2<<" "<<r1<<endl;
		}
		else{
			cout<<r1<<" "<<r2<<endl;
		}
	}
	else if(d==0){
		cout<<"Real and Equal"<<endl;
		r1 = (-b + d)/(2*a);
		r2 = (-b - d)/(2*a);
		cout<<r2<<" "<<r1<<endl;
	}
	else {
		cout<<"Imaginary"<<endl;
	}

	return 0;
}
