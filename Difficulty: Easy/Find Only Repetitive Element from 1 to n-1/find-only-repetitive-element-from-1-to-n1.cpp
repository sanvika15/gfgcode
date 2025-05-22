// User function Template for C++
class Solution {
  public:
    int findDuplicate(vector<int>& arr) {
        long long int n =arr.size();
       long long sum = 0;
       for(int i=0;i<n;i++)
       {
           sum=sum+arr[i];
       }
       return (n-(n*(n+1)/2-sum));
        
    }
};