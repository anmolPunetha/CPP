//give all strings (permutaions) smaller than the input string
// lets use a single array and backtracking
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void possible_permutations(string main_s,string input, int i){
    //base
    if(input[i]=='\0'){
        if(input<main_s){
            cout<<input<<endl;
        }
        return;
    }

    //rec
    for(int j=i; input[j]!='\0';j++){
        swap(input[i], input[j]);
        possible_permutations(main_s, input, i+1);
        swap(input[i], input[j]); //backtrack
    }
}
int main() {
    string str;
    cin>>str;
    string main_s = str;
    sort(str.begin(), str.end()); 
    possible_permutations(main_s, str,0);
}
