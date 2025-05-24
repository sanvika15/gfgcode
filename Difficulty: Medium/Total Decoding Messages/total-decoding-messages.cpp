class Solution {
  public:
  int find(string &s,int i){
      if(i==s.length()) return 1;
      if(i>s.length()||s[i]=='0') return 0;
      int single=find(s,i+1);
      int doubles=0;
      if(i+1<s.length() and (s[i]=='1'||(s[i]=='2' and ( s[i+1]-'0'<7)))) doubles=find(s,i+2);
      return single+doubles;
  }
  int find(string &digits){
      int n=digits.length();
      vector<int>dp(n+1);
      dp[n]=1;
      for(int i=n-1;i>=0;i--){
          int single=dp[i+1];
          int doubles=0;
          if(i+1<digits.length() and (digits[i]=='1'||(digits[i]=='2' and ( digits[i+1]-'0'<7)))) doubles=dp[i+2];
          dp[i]=single+doubles;
          if(digits[i]=='0') dp[i]=0;
      }
      return dp[0];
  }
  int findS(string &digits){
      int n=digits.length();
      int pre1=1;
      int pre2=0;
      for(int i=n-1;i>=0;i--){
          int single=pre1;
          int doubles=0;
          if(i+1<digits.length() and (digits[i]=='1'||(digits[i]=='2' and ( digits[i+1]-'0'<7)))) doubles=pre2;
          int curr=single+doubles;
          if(digits[i]=='0') curr=0;
          pre2=pre1;
          pre1=curr;
      }
      return pre1;
  }
    int countWays(string &digits) {
        // Code here
        // return find(digits,0);
        // return find(digits);
           return findS(digits);
    }
};