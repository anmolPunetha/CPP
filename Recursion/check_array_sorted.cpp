#include <iostream>
using namespace std;
bool check_array(int *arr, int n){
    //base
    if(n==0 or n==1){
        return true;
    }
    //rec
    if(arr[0]<arr[1] and check_array(arr+1, n-1)){
        return true;
    }
    return false;
}
int main() {
    int n;
    cin>>n;
    int arr[1000];
    for(int k=0;k<n;k++){
        cin>>arr[k];
    }
    int val = check_array(arr, n);
    if(val){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
}
