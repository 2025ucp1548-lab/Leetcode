class Solution {
public:
    int maxProduct(int n) {
        std::string s = std::to_string(n);
        std::sort(s.begin(), s.end());
        
        int len = s.length();
        int firstMax = s[len - 1] - '0';
        int secondMax = s[len - 2] - '0';

        return firstMax * secondMax;
    }
};