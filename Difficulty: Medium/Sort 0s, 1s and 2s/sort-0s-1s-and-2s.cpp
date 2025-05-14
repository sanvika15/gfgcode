//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int n = arr.size();
        int i = 0, j = 0, h = n-1;
        while(j<=h)
        {
            if(arr[j] == 0)
            {
            swap(arr[j], arr[i]);
            i++;
            j++;
            }
            
            else if(arr[j] == 1)
            {
                j++;
            }
            
            else if(arr[j] == 2)
            {
                swap(arr[j], arr[h]);
                h--;
            }
        }
        
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends