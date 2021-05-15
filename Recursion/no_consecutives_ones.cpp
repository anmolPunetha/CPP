#include <iostream>
using namespace std;
int find_possible_strings(int n){
    //base
    if(n==0){
        return 1;
    }
    if(n==1){
        return 2;
    }
    //rec
    return find_possible_strings(n-1) + find_possible_strings(n-2);
}
int main() {
    int t;
    cin>>t;
    for(int i =1;i<=t;i++){
        int num;
        cin>>num;
        int result = find_possible_strings(num);
        cout<<"#"<<i<<" : "<<result<<endl;
    }
 return 0;
}
