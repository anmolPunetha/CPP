    int longestnondec(vector<int>&nums){
        int n=nums.size();
        vector<int>temp;
        for(int i=0;i<n;i++){
            if(temp.empty() or temp.back()<=nums[i]){
                temp.push_back(nums[i]);
            }
            else{
                int idx=upper_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[idx]=nums[i];
            }
        }
        return temp.size();
   }
