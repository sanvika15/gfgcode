//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
     vector<int> A; 
     int max1=*max_element(arr.begin(),arr.begin()+k); 
     A.push_back(max1); 
     for(int i=1;i<=arr.size()-k;i++) { 
        if(arr[i-1]==max1)  
        max1=*max_element(arr.begin()+i,arr.begin()+(i+k)); 
        else
        if(max1<arr[i+k-1]) max1=arr[i+k-1]; 
        A.push_back(max1); 
     }
    return A;        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends