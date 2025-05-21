/* A binary tree node has data, pointer to left child
   and a pointer to right child
class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */
class Solution {
  public:
    vector<int> findSpiral(Node* root) {
vector<int> ans;
        if(root == nullptr) return ans;
        
        queue<Node*> que;
        que.push(root);
        
        bool dir = false;
        
        while(!que.empty()){
            int n = que.size();
            vector<int> row(n);
            
            for(int i =0; i<n; i++){
                Node* node = que.front();
                que.pop();
                
               int ind = dir ? i : (n - 1 - i);
               row[ind] = node->data;
               
               if(node->left){
                   que.push(node->left);
               }
               if(node->right){
                   que.push(node->right);
               }
            }
            
            for(auto val : row){
                ans.push_back(val);
            }
            
            dir = !dir;
        }
        return ans;        
    }
};