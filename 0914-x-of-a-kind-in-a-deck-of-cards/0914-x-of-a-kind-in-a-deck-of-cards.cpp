class Solution {
public:
     int gcd(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> freq;
        for (int card : deck) {
            freq[card]++;
        }
        int g = 0;
        for (auto it : freq) {
            g = gcd(g, it.second);
        }
        return g >= 2;
    }
};