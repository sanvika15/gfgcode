class Solution {
  public:
    int countWays(string &s) {
        // code here
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<vector<int>> total(n, vector<int>(n, 0));
        for(int i = 0; i < n; i+=2){
            dp[i][i] = s[i] == 'T'? 1 : 0;
            total[i][i] = 1;
        }
        
        for(int i = n - 1; i >= 0; i -= 2){
            for(int j = i + 2; j < n; j += 2){
                for(int k = i + 1; k < j; k += 2){
                    int expr = 0;
                    int total1 = total[i][k-1];
                    
                    int total2 = total[k+1][j];
                    
                    total[i][j] += total1 * total2;
                  
                    
                    int num1 = dp[i][k - 1] == 0 ? 0 : 1;
                    int num2 = dp[k + 1][j] == 0 ? 0 : 1;
                    if(s[k] == '&'){
                        expr = dp[i][k - 1] * dp[k + 1][j];
                    }
                    else if(s[k] == '|'){
                        expr = dp[i][k - 1] * (total2 - dp[k + 1][j]) + (total1 - dp[i][k - 1]) * dp[k + 1][j] + dp[i][k - 1] * dp[k + 1][j];
                    }
                    else if(s[k] == '^'){
                        expr = dp[i][k - 1] * (total2 - dp[k + 1][j]) + (total1 - dp[i][k - 1]) * dp[k + 1][j];
                    }
                    dp[i][j] += expr; 
                }
            }
        }
        return dp[0][n - 1];
    }
};