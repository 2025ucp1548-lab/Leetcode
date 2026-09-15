class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_map<int, int> first;
        unordered_map<int, int> last;
        int degree = 0;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
            if (first.find(nums[i]) == first.end()) {
                first[nums[i]] = i;
            }  
             last[nums[i]] = i;   
            degree = max(degree, freq[nums[i]]);
        }
        int ans = nums.size();
          for (auto x : freq) {
            if (x.second == degree) {
                int length = last[x.first] - first[x.first] + 1;
                ans = min(ans, length);
            }
        }
        return ans;
    }
};