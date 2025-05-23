class Solution {
    public int maxPartitions(String s) {
        // code here
        Set<Character> set=new HashSet<>();
        int n=s.length();
        int[] arr=new int[n];
        int curr_min=0;
        for(int i=0;i<n;i++){
            char curr=s.charAt(i);
            if(!set.contains(curr)){
                set.add(curr);
                curr_min++;
                arr[i]=curr_min;
            } else {
                int prev_idx=i-1;
                int min_value=arr[prev_idx];
                while(prev_idx>=0){
                    if(s.charAt(prev_idx)==curr){
                        min_value=Math.min(min_value,arr[prev_idx]);
                        break;
                    }
                    min_value=Math.min(min_value,arr[prev_idx]);
                    prev_idx--;
                }
                arr[i]=min_value;
                curr_min=arr[i];
            }
        }
        return arr[n-1];
    }
}