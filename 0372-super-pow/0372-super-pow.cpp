class Solution {
public:
    long long power(long long a, int b) {
        long long ans = 1;
        a = a % 1337;

        while (b > 0) {
            if (b % 2 == 1) {
                ans = (ans * a) % 1337;
            }

            a = (a * a) % 1337;
            b = b / 2;
        }

        return ans;
    }

    int superPow(int a, vector<int>& b) {
        long long ans = 1;

        for (int digit : b) {
            ans = (power(ans, 10) * power(a, digit)) % 1337;
        }

        return ans;
    }
};