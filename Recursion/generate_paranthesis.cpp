#include <iostream>
using namespace std;
void generate_paranthesis(char *a, int n, int idx, int open, int close){
    //base 
    if(idx==2*n){
        a[idx]='\0';
        cout<<a<<endl;
        return;
    }
    //rec
    if(close<open){
        a[idx]=')';
        generate_paranthesis(a,n,idx+1,open,close+1);
    }
    if(open<n){
        a[idx]='(';
        generate_paranthesis(a,n,idx+1,open+1,close);
    }
    
    return;
}
int main() {
    int n;
    char a[30];
    cin>>n;
    generate_paranthesis(a,n,0,0,0);
}
