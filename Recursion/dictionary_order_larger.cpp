//give all strings (permutaions) greater than the input string
// lets use a single array and backtracking
#include <iostream>
#include <string>
#include <set>
using namespace std;
int count=0;
int inc(){
    count+=1;
    return count;
}
void possible_permutations(string input, int i, set <string> &s){
    //base
    if(input[i]=='\0'){
        string t(input);
        s.insert(t);
        return;
    }

    //rec
    for(int j=i; input[j]!='\0';j++){
        swap(input[i], input[j]);
        possible_permutations(input, i+1, s);
        swap(input[i], input[j]); //backtrack
    }
}
int main() {
    string str;
    cin>>str;
    set <string> s;
    possible_permutations(str,0, s);

    for(auto it:s){
        if (it>str){
            cout<<it<<endl;
        }
    }
}
