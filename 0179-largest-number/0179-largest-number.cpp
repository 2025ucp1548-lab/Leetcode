class Solution {
public:
    static bool compare(int a, int b) {
        string x = to_string(a);
        string y = to_string(b);

        return x + y > y + x;
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        if (nums[0] == 0) {
            return "0";
        }

        string result = "";

        for (int num : nums) {
            result += to_string(num);
        }

        return result;
    }
};
