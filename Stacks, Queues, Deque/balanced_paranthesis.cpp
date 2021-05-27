
#include <iostream>
#include<stack>
using namespace std;
int main() {
    stack <char> s;
    bool isbalanced = true;
    char a[10000];
    cin>>a;

    for(int i=0;a[i]!='\0';i++){
        char ch = a[i];
        if(ch=='('){
            s.push(ch);
        }
        else if (ch==')'){
            if(s.empty() or s.top()!='('){
                isbalanced=false;
            }
            s.pop();
        }
    }
    if(isbalanced){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
}
