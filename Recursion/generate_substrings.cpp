#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
void generate_subsequences(char *inp, char*out, int i, int j){
    //base
    if(inp[i]=='\0'){
        out[j]='\0';
        cout<<out<<" ";
        return;
    }
    //rec
    //including
    out[j]=inp[i];
    generate_subsequences(inp, out, i+1, j+1);
    //excluding
    generate_subsequences(inp, out, i+1, j);
}
int main() {
    char a[1000];
    char out[1000];
    cin>>a;
    int n=strlen(a);
    generate_subsequences(a, out, 0, 0);
    cout<<endl;
    cout<<pow(2,n);
}
