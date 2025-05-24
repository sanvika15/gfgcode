class Solution {
  public:
    int solve(vector<int> arr,int i,int j,vector<vector<int>>&t)
{
    if(i>=j) return 0;
    if(t[i][j]!=-1) return t[i][j];
    int cost = INT_MAX;
    for(int k=i;k<j;k++)
    {
        int ans = solve(arr,i,k,t) + solve(arr,k+1,j,t) + arr[i-1]*arr[k] * arr[j];
        
        cost = min(cost,ans);
    }
    return t[i][j] = cost;
    
} 
 
    int matrixMultiplication(vector<int> &arr) {
    
    vector<vector<int>>t (arr.size()+1,vector<int>(arr.size()+1, - 1));
    
    return solve(arr,1,arr.size()-1,t);
    }
};