class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, int index, vector<int>& curr)
    {
        ans.push_back(curr);
        for(int i=index; i<nums.size(); i++)
        {
            curr.push_back(nums[i]);
            solve(nums,i+1,curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<int> curr;
       solve(nums,0,curr);
       return ans; 
    }
};