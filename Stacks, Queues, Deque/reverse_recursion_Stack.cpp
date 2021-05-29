#include <iostream>
#include<stack>
using namespace std;
void insertAtBottom(stack<int>&s, int x){
	//base
	if(s.empty()){
		s.push(x);
		return;
	}

	//rec
	int data = s.top();
	s.pop();
	insertAtBottom(s,x);
	s.push(data);
}
void reverseStack(stack<int>&s){
	//base
	if(s.empty()){
		return;
	}

	//rec
	int x= s.top();
	s.pop();
	reverseStack(s);
	insertAtBottom(s,x);
}
int main() {
	int n;
	cin>>n;
	stack <int> s;
	for(int i=0;i<n;i++){
		int  num;
		cin>>num;
		s.push(num);
	}
	reverseStack(s);

	// for(auto i:s){
	// 	cout<<i<<endl;
	// }
	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}
    return 0;
}
