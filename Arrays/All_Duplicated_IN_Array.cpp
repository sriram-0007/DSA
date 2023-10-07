class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            int index=abs(nums[i]);
            if(nums[index-1]>0) nums[index-1]*=-1;
            else result.push_back(abs(nums[i]));
        }
        return result;
    }
};