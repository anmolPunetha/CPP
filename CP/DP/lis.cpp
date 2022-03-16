//this writes a in a passed vector the lis till all ith element, sirf last chahiye toh end m return temp.size()    
void longestinc(vector<int>&nums, vector<int>&inc){
        int n=nums.size();
        vector<int>temp;
        for(int i=0;i<n;i++){
            if(temp.empty() or temp.back()<nums[i]){
                temp.push_back(nums[i]);
            }
            else{
                int idx=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[idx]=nums[i];
            }
            inc[i]=temp.size();
        }
    }
