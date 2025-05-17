//{ Driver Code Starts
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int testCases = Integer.parseInt(br.readLine());

        while (testCases-- > 0) {
            int capacity = Integer.parseInt(br.readLine());
            String[] valInput = br.readLine().split(" ");
            String[] wtInput = br.readLine().split(" ");

            int[] val = new int[valInput.length];
            int[] wt = new int[wtInput.length];

            for (int i = 0; i < valInput.length; i++) {
                val[i] = Integer.parseInt(valInput[i]);
            }

            for (int i = 0; i < wtInput.length; i++) {
                wt[i] = Integer.parseInt(wtInput[i]);
            }

            System.out.println(Solution.knapsack(capacity, val, wt));
            System.out.println("~");
        }
    }
}

// } Driver Code Ends


class Solution {
      static Integer dp[][];

    static int knapsack(int W, int val[], int wt[]) {
        dp = new Integer[val.length+1][W+1];
        // return sol(W, val, wt, 0, val.length);
        return dynamicProgramming(W, val, wt, val.length);
    }

    private static int sol(int weight, int val[], int wt[], int i, int n) {
        if (weight == 0)
            return 0;
        if (i == n)
            return 0;
        int take = 0;
        if (wt[i] <= weight)
            take = val[i] + sol(weight - wt[i], val, wt, i + 1, n);
        int notTake = sol(weight, val, wt, i + 1, n);
        return dp[i][weight] = Math.max(take, notTake);

    }

    private static int dynamicProgramming(int weight, int val[], int wt[], int n) {

        for (int i = n; i >= 0; i--) {
            for (int j = 0; j <= weight; j++) {
                if (j == 0 || i == n)
                    dp[i][j] = 0;
                else if (wt[i] <= j) {
                    dp[i][j] = Math.max(val[i] + dp[i + 1][j - wt[i]], dp[i + 1][j]);
                } else {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }

        return dp[0][weight];
}}
