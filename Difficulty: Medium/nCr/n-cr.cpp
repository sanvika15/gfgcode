//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int nCr(int n, int r) {
        if(n<r) return 0;
        if(r==0) return 1;
        r=(n-r)>r?r:n-r;
        long long num=1,t=1;
        for(int i=n;i>n-r;i--){
            num=(num*i)/t;
            t++;
        }
        return num;      
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends