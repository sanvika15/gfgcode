//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        
        long int len = arr.size();
        int m = 0;
        vector<int> subarray;
        int sum = 0;
        for(long int n=0; n<len;n++)
        {
            sum = arr[n];
            subarray.clear();
            subarray.push_back(n+1);
            for(m=n+1;m<len;m++)
            {
                if(sum == target)
                {
                    break;
                }
                else
                {
                    sum = sum + arr[m];
                }
            }
            if(sum == target)
            {
                break;
            }
        }
        if(sum == target)
        {
            subarray.push_back(m);
            return subarray;
        }
        else
        {
            subarray.clear();
            subarray.push_back(-1);
        }
        return subarray;
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends