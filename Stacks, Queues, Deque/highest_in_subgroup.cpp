//pure application of deque

#include <iostream>
#include<deque>
using namespace std;

int main() {
    // these two lines are used for fast input and output in CP (printf, scanf)
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    int n;
	int x = 10000000;
	int *a = new int[x];
    int k;
    
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>k;
    
    //We have to process first k elements separtely
    deque<int> Q(k);
    int i;
    for(i=0;i<k;i++){
        
        while(!Q.empty() &&a[i]>a[Q.back()]){
            Q.pop_back();
        }
        Q.push_back(i);
        
    }
    //Process the remaining elements 
    for(;i<n;i++){
        cout<<a[Q.front()]<<" ";
        
        //1. Remove the elements which are not the part of the window(Contraction)
        while((!Q.empty() && (Q.front()<=i-k))){
            Q.pop_front();
        }
        
        //2. Remove the elements which are not useful and are in window
        while(!Q.empty() && a[i]>=a[Q.back()]){
            Q.pop_back();   
        }
        
        //3. Add the new elements(Expansion)
        Q.push_back(i);
    }
    
    cout<<a[Q.front()]<<endl;
    
    
    return 0;
}
