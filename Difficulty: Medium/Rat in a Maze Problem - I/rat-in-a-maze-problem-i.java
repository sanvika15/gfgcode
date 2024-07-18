//{ Driver Code Starts
// Initial Template for Java

import java.util.*;

class Rat {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int[][] a = new int[n][n];
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) a[i][j] = sc.nextInt();

            Solution obj = new Solution();
            ArrayList<String> res = obj.findPath(a);
            Collections.sort(res);
            if (res.size() > 0) {
                for (int i = 0; i < res.size(); i++) System.out.print(res.get(i) + " ");
                System.out.println();
            } else {
                System.out.println(-1);
            }
        }
    }
}

// } Driver Code Ends

// m is the given matrix and n is the order of matrix
class Solution {
    public ArrayList<String> findPath(int[][] mat) {
        ArrayList<String> list = new ArrayList<>();
        boolean[][] visited = new boolean[mat.length][mat[0].length];
        ratMaze(mat, visited, 0, 0, "", list);
        return list;
    }

    public static void ratMaze(int[][] mat, boolean[][] visited, int i, int j, String ans, ArrayList<String> list) {
        if (i == mat.length - 1 && j == mat[0].length - 1 && mat[i][j] == 1) {
            list.add(ans);
            return;
        }
        if (i < 0 || i == mat.length || j < 0 || j == mat[0].length || visited[i][j] || mat[i][j] == 0) {
            return;
        }
        visited[i][j] = true;
        ratMaze(mat, visited, i - 1, j, ans + "U", list);
        ratMaze(mat, visited, i, j + 1, ans + "R", list);
        ratMaze(mat, visited, i + 1, j, ans + "D", list);
        ratMaze(mat, visited, i, j - 1, ans + "L", list);
        visited[i][j] = false;
    }
}