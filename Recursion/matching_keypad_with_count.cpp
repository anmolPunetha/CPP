#include <iostream>
#include <set>
#include <string>
using namespace std;
char table[][10]={"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wx", "yz"};
void matching_keypad(char *output, char *input, int i, int j, set <string> &s){
    //base
    if(input[i]=='\0'){
        output[j]='\0';
        s.insert(output);
        return;
    }

    //rec
    int digit = input[i]-'1';

    for(int k=0; table[digit][k]!='\0';k++){
        output[j] = table[digit][k];
        matching_keypad(output, input, i+1,j+1, s);
    }
}
int main() {
    char num[11];
    cin>>num;
    char output[10];
    set <string> s;
    matching_keypad(output, num, 0, 0, s);
    int count = 0;
    for(auto it:s){
        count++;
        cout<<it<<" ";
    }
    cout<<endl;
    cout<<count;
}
