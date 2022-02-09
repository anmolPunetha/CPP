    long long get_pal(long long num, bool is_even){
        long long org=num;
        if(!is_even)num=num/10;
        while(num){
            org=org*10 + num%10;
            num=num/10;
        }
        return org;
    }
    void solve() {
        for(long long i=1;i<10000;i*=10){
          
            //smaller (odd) length
            for(long long j=i;j<i*10 and n>0;j++){
                long long num=get_pal(j,false); //get pal base 10 num
                cout<<num<<" ";  
            }
            cout<<endl;
            //bigger (even) length
            for(long long j=i;j<i*10 and n>0;j++){
                long long num=get_pal(j,true);
                cout<<num<<" ";
            }
          cout<<endl;
        }
        return sum;
    }
