class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        while(i < n && nums[i] != target)
        {
            i++;
        }
        vector<int> result;
        for(int j=i;j<n;j++)
        {
            if(nums[j]==target)
            {
                result.push_back(j);
            }
        }
        return result;
    }
};