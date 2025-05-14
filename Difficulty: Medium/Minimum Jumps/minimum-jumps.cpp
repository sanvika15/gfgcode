//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        int max_reach=0;
        for(int i=0;i<n;i++){
            if(i<=max_reach){
                max_reach = max(max_reach, i+arr[i]);
            }
        }
        if(max_reach<n-1) return -1;
        int l=0, r=0, jump=0;
        while(r<n-1){
            int maxi=0;
            for(int i=l;i<=r;i++){
                maxi = max(maxi, i+arr[i]);
            }
            l=r+1;
            r=maxi;
            jump++;
        }
        return jump;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends