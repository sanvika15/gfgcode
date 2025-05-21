#User function Template for python3

'''
# Node Class:
class Node:
    def __init__(self,val):
        self.data = val
        self.left = None
        self.right = None
'''

class Solution:
    #Function to return the maximum sum of non-adjacent nodes.
 def getMaxSum(self, root):
        def score(node):
            # returns tuple [<score-if-node-included>, <score-if-node-excluded>]  
            if node==None:
                return 0, 0
            l1, l2 = score(node.left)
            r1, r2 = score(node.right)
            return node.data + l2 + r2, max(l1, l2)+max(r1,r2)     
        
        return max(*score(root))