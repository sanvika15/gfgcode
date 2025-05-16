//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
    int prefix=INT_MIN;
    int suffix=INT_MIN;
    
    int prod1=1;
    int prod2=1;
    
    for(int i=0,j=arr.size()-1;i<arr.size();i++,j--)
    {
        prod1*=arr[i];
        prod2*=arr[j];
        prefix=max(prod1,prefix);
        suffix=max(prod2,suffix);
        
        if(prod1==0)prod1=1;
        if(prod2==0)prod2=1;
    }
    return max(prefix,suffix);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends