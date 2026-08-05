class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mid=n/2;
        int count=0;
        int target=nums[mid];
        for (int num : nums) {
            count += abs(num - target); 
        }
        return count;
    }
};