#include <iostream>
#include<list>
using namespace std;
int main() {
    bool ispal=true;
    list<int>l;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        l.push_back(num);
    }

    auto fwd = l.begin();
    auto last = l.end();
    last--;
    while(fwd!=last){
        if(*fwd!=*last){
            // cout<<*fwd<<*last<<endl;
            ispal=false;
            break;
        }
        fwd++;
        last--;
    }
    if(ispal){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}
