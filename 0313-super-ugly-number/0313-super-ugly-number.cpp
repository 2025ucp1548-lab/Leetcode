class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
       int k=primes.size();
       vector<int> ugly(n,0);
       vector<int> idx(k,0);
       ugly[0]=1;
       for(int i=1;i<n;i++)
       {
        long long nextUgly=LLONG_MAX;
        for(int j=0;j<k;j++)
        {
            nextUgly=min(nextUgly, 1LL*primes[j]*ugly[idx[j]]);
        }
        ugly[i]=nextUgly;
        for(int j=0;j<k;j++)
        {
            if(1LL*primes[j]*ugly[idx[j]]==nextUgly)
            {
                idx[j]++;
            }
        }
       } 
       return ugly[n-1];
    }
};