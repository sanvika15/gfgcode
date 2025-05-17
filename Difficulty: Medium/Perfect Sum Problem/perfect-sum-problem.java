//{ Driver Code Starts
import java.io.*;
import java.util.*;

class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine().trim()); // Read number of test cases

        // Loop for each test case
        while (t-- > 0) {
            String line = read.readLine().trim(); // Read the array input
            String[] numsStr = line.split(" ");   // Split the input string by spaces
            int[] nums =
                new int[numsStr.length]; // Convert string array to integer array
            for (int i = 0; i < numsStr.length; i++) {
                nums[i] = Integer.parseInt(numsStr[i]);
            }

            int target = Integer.parseInt(read.readLine().trim()); // Read target sum

            Solution ob = new Solution(); // Create an object of Solution class
            System.out.println(
                ob.perfectSum(nums, target)); // Call perfectSum and print the result
            System.out.println("~");          // Call perfectSum and print the result
        }
    }
}
// } Driver Code Ends


class Solution {
    // Function to calculate the number of subsets with a given sum
    public int perfectSum(int[] nums, int target) {
int n=nums.length;
        int[] dp=new int[target+1];
        int[] curr=new int[target+1];
        if(nums[0]==0)dp[0]=2;
        else dp[0]=1;
        if(nums[0]!=0 && nums[0]<=target)dp[nums[0]]=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<=target;j++){
                int notPick=dp[j];
                int pick=0;
                if(nums[i]<=j)pick=dp[j-nums[i]];
                curr[j]=pick+notPick;
            }
            dp=curr.clone();
        }
        return dp[target];        
    }
}