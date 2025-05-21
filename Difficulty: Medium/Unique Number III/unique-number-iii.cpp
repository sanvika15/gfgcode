// User function Template for C++

class Solution {
  public:
int getSingle(vector<int> &arr) {
        // code here
        int n = arr.size();
        int arr1[32] = {0}, arr2[32] = {0};
        for(int i = 0; i<n; i++){
            if(arr[i]>=0){
                int x = 31;
                int y = arr[i];
                while(y>0){
                    if(y%2==1)
                    arr1[x]++;
                    x--;
                    y = y/2;
                }
            }
            else{
                int x = 31;
                int y = abs(arr[i]);
                while(y>0){
                    if(y%2==1)
                    arr2[x]++;
                    x--;
                    y = y/2;
                }
            }
        }
        
        long long int ans = 0;
        long long x = 1;
        for(int i = 31; i>=0; i--){
            int y = arr1[i]%3;
            ans = ans + y*x;
            x = x*2;
        }
        
        if(ans!=0){
            return ans;
        }
        
        ans = 0;
        x = 1;
        for(int i = 31; i>=0; i--){
            int y = arr2[i]%3;
            ans = ans + y*x;
            x = x*2;
        }
        
        return -ans;
        
    }
};