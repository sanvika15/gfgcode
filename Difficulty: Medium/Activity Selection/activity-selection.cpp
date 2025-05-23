class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
        int n = start.size();
        vector<pair<int,int>>vp;
        for(int i=0;i<n;i++){
            vp.push_back({finish[i],i});
        }
        int ans = 1;
        sort(vp.begin(),vp.end());
        int prev_finish = vp[0].first;
        for(int i = 1;i<n;i++){
            if(start[vp[i].second] > prev_finish){
                ans++;
                prev_finish = vp[i].first;
            }
        }
        return ans;
    }
};

