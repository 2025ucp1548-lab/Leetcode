class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
       vector<int> res;
       int n=nums.size();
       int j=0;
       while (j < n) {
            int ind = nums[j] - 1;
            if (nums[j] != nums[ind]) {
                swap(nums[j], nums[ind]);
            } else {
                j++;
            }
        }
       for(int i=0;i<n;i++){
        if(nums[i]!=i+1){
            res.push_back(nums[i]);
            res.push_back(i+1);
        }
       } 
       return res;
    }
};