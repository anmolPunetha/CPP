#include <iostream>
using namespace std;
char table[][10]={"", ".+@$", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void matching_keypad(char *output, char *input, int i, int j){
    //base
    if(input[i]=='\0'){
        output[j]='\0';
        cout<<output<<endl;
        return;
    }

    //rec
    int digit = input[i]-'0';
    if (digit==0){  //to pass null values
        matching_keypad(output, input, i+1,j);
    }
    for(int k=0; table[digit][k]!='\0';k++){
        output[j] = table[digit][k];
        matching_keypad(output, input, i+1,j+1);
    }
}
int main() {
    char num[11];
    cin>>num;
    char output[10];
    matching_keypad(output, num, 0, 0);
}
