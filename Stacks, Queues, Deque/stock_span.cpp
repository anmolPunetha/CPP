#include<iostream>
#include<stack>
using namespace std;
void stockSpan(int *prices, int*span, int n){
	stack<int>s;
	//for day 1
	s.push(0);    //we are pushing indicies
	span[0]=1;

	//for rest days
	for(int i=1;i<n;i++){
		int currentPrice = prices[i];
		while(!s.empty() and prices[s.top()]<=currentPrice){
			s.pop();
		}
		if(!s.empty()){
			int prev_highest = s.top();
			span[i]=i-prev_highest;
		}
		else{
			span[i]=i+1;
		}
		s.push(i);
	}
	
}
int main() {
	int n;
	int prices[1000000];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>prices[i];
	}
	int span[n]={0};
	stockSpan(prices,span,n);

	for(int i=0;i<n;i++){
		cout<<span[i]<<" ";
	}
	cout<<"END";
	
	return 0;
}
