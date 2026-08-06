class Solution {
private:
    int getDigitProduct(int n) {
        int prod = 1;
        while (n > 0) {
            prod *= (n % 10);
            n /= 10;
        }
        return prod;
    }
public:
    int smallestNumber(int n, int t) {
       while (getDigitProduct(n) % t != 0) {
            n++;
        }
        return n; 
    }
};