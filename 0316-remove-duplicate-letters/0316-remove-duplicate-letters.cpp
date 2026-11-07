class Solution {
public:
    string removeDuplicateLetters(string s) {
       vector<int> last(26,0);
       vector<bool> visited(26,false);
       for(int i=0;i<s.size();i++)
       {
        last[s[i]-'a']=i;
       } 
       string st;
       for(int i=0;i<s.size();i++)
       {
        char c=s[i];
        int idx=c-'a';
        if(visited[idx])
        {
            continue;
        }
        while(!st.empty() && st.back()>c && last[st.back()-'a']>i)
        {
            visited[st.back()-'a']=false;
            st.pop_back();
        }
        st.push_back(c);
        visited[idx]=true;
       }
       return st;
    }
};