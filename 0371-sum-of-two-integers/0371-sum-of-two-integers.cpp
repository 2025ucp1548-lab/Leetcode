class Solution {
public:
    int getSum(int a, int b) {
      while(b!=0){
        int sum1=a^b;
        unsigned int carry=(unsigned int)(a & b)<<1;
        a=sum1;
        b=carry;
      }  
      return a;
    }
};