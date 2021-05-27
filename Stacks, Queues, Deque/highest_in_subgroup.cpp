//pure application of stack

#include <iostream>
#include<stack>
using namespace std;
int main() {
    int n,k;
    cin>>n;
    int a[1000000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cin>>k;
    for(int i=0;i<n;i++){
        if(i+k<=n){
            stack<int> s;
            for(int j=i;j<k+i;j++){
                if(s.empty()){
                    s.push(a[j]);
                }
                else{
                    if(a[j]>s.top()){
                        s.push(a[j]);
                    }
                }
            }
            cout<<s.top()<<" ";
        }
    }
    return 0;
}
