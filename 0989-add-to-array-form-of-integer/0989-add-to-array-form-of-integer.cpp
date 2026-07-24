class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int i=num.size()-1;
        vector<int> a;
        while(i>=0 || k>0){
            if(i>=0){
                k+=num[i];
                i--;
            }
            a.push_back(k%10);
            k/=10;
        }
        reverse(a.begin(),a.end());
        return a;
    }
};