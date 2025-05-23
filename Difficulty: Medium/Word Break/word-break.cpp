class Solution {
  public:
    unordered_set<string>st;
    int n;
    vector<int>dp;
    int solve(int i,string &s){
        if(i==n)return 1;
        if(dp[i]!=-1)return dp[i];
        int res=0;
        for(string curr:st){
            int sz=curr.size();
            if(sz+i>n || s.substr(i,sz)!=curr)continue;
            if(solve(i+sz,s))res = 1;
        }
        return dp[i] = res;
    }
    bool wordBreak(string &s, vector<string> &dictionary) {
        // code here
        for(string &str:dictionary)st.insert(str);
        n=s.size();
        dp.resize(n,-1);
        return solve(0,s);
    }
};