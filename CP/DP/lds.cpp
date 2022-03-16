//writes to an array the length of lds till ith position   
void longestdec(vector<int>&nums, vector<int>&dec){
        int n=nums.size();
        vector<int>temp;
        for(int i=0;i<n;i++){
            if(temp.empty() or (temp.back()>nums[i])){
                temp.push_back(nums[i]);
            }
            else{
                int idx=lower_bound(temp.begin(),temp.end(),nums[i], greater<int>())-temp.begin();
                temp[idx]=nums[i];
            }
            
            dec[i]=temp.size();
        }
    }
