class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int st=0;
        int end=digits.size()-1;
        for(int i=end;i>=0;i--)
        {
            if(digits[i]<9)
            {
                digits[i]+=1;
                return digits;
            }
            digits[i]=0;
        }
        digits.insert(digits.begin(),1);
        return digits;
    }
};