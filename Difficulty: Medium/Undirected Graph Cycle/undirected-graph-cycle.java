//{ Driver Code Starts
// Initial Template for Java
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();
        while (tc-- > 0) {
            int V = sc.nextInt();
            int E = sc.nextInt();
            int[][] edges = new int[E][2];
            for (int i = 0; i < E; i++) {
                edges[i][0] = sc.nextInt();
                edges[i][1] = sc.nextInt();
            }

            Solution obj = new Solution();
            boolean ans = obj.isCycle(V, edges);
            System.out.println(ans ? "true" : "false");
            System.out.println("~");
        }
        sc.close();
    }
}

// } Driver Code Ends


class Solution {
    public boolean isCycle(int V, int[][] edges) {
// make adj list
        ArrayList<ArrayList<Integer>> adjList = new ArrayList<>();
        for(int i = 0; i<V; i++) {
            adjList.add(new ArrayList<>());
        }
        
        for(int[] edge : edges) {
            adjList.get(edge[0]).add(edge[1]);
            adjList.get(edge[1]).add(edge[0]);
        }
        
        // Through BFS find Cycle
        // In BFS this time we'll need to store the prevNode in Queue also, 
        // because we want to keep track of from which node we came to a particular node.
        // If edge is 1->2 then we'll store {1,2} in queue.
        // This will help us find real cycle with the help of visited array.
        // If there is vis[x] = 1 already that means it's already visited, that means
        // there is cycle, but we also need to make sure it's not just the prevNode
        // of the node where we found cycle. 
        // In short we want to avoid saying 1->2 and 2->1 a cycle. So we keep track of 
        // prevNode of 2 which is 1.
        
        
        int[] vis = new int[V];
        
        for(int i = 0; i<V; i++) {
            if(vis[i] == 0) {
                Queue<int[]> q = new LinkedList<>();
                q.add(new int[]{-1, i}); // we're starting from 0 so we take prevNode -1
                vis[i] = 1;
                
                while(!q.isEmpty()) {
                    int prevNode = q.peek()[0];
                    int node = q.remove()[1];
                    
                    for(int adjNode : adjList.get(node)) {
                        if(adjNode != prevNode && vis[adjNode] == 1) 
                            return true;
                        else if(vis[adjNode] == 0) {
                            vis[adjNode] = 1;
                            q.add(new int[]{node, adjNode});
                        }
                    }
                }
            }
        }
        
        return false;        
    }
}