#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        priority_queue<int> leftheap;
        priority_queue<int, vector<int>, greater<int>> rightheap;

        int n;
        cin>>n;

        int num;
        cin>>num;
        leftheap.push(num);
        
        int med=num;
        cout<<med<<" ";

        for(int j=1;j<n;j++){
            cin>>num;

            if(leftheap.size()>rightheap.size()){
                if(num<med){
                    rightheap.push(leftheap.top());
                    leftheap.pop();
                    leftheap.push(num);
                }
                else{
                    rightheap.push(num);
                }

                med=(leftheap.top()+rightheap.top())/2.0;
            }
            else if(leftheap.size()==rightheap.size()){
                if(num<med){
                    leftheap.push(num);
                    med = leftheap.top();
                }
                else{
                    rightheap.push(num);
                    med = rightheap.top();
                }
            }
            else{
                if(num>med){
                    leftheap.push(rightheap.top());
                    rightheap.pop();
                    rightheap.push(num);
                }
                else{
                    leftheap.push(num);
                }

                med=(leftheap.top()+rightheap.top())/2.0;
            }

            cout<<med<<" ";
        }
        cout<<endl;
    }
    return 0;
}
