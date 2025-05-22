class Solution {
  public:
    int missingNum(vector<int>& arr) {
        int num=0;
    int idx=0;
    int n=arr.size()+1;
    
    for(int i=0;i<arr.size();i++){
        num=num^arr[i];
    }
    for(int i=0;i<=n;i++){
        idx=idx^i;
    }
    return num^idx;
        
    }
};