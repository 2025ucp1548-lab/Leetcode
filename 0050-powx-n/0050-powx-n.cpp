class Solution {
public:
    double myPow(double x, int n) {
        long long N=n;
        if(N<0){
            x=1/x;
            N=-N;
        }
        double prod=1.0;
        while (N > 0) {
            if (N % 2 == 1) {
                prod *= x;
            }
            x *= x;
            N /= 2;
        }
        return prod;
    }
};