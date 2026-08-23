class Solution {
public:
    bool sumGame(string num) {
        int n=num.length();
        int mid=n/2;
        int leftsum=0;
        int rightsum=0;
        int leftq=0;
        int rightq=0;
        for(int i=0;i<mid;i++)
        {
            if(num[i]=='?')
            {
                leftq++;
            }
            else
            {
                leftsum+=num[i]-'0';
            }
        }
        for(int i=mid;i<n;i++)
        {
            if(num[i]=='?')
            {
                rightq++;
            }
            else
            {
                rightsum+=num[i]-'0';
            }
        }
        int diff=leftsum-rightsum;
        int qdiff=leftq-rightq;
        if((leftq+rightq)%2==1)
        {
            return true;
        }
        return diff+(qdiff/2)*9!=0;
    }
};