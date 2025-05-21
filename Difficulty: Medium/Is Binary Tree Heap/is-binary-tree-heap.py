#User Template for python3

'''
class Node:
    def __init__(self,val):
        self.data = val
        self.left = None
        self.right = None
'''

from collections import deque
class Solution:
    def isHeap(self, root):
        flag=False
        q=deque()
        q.append(root)
        while q:
            node=q.popleft()
            if node.left:
                if flag or node.data<node.left.data:
                    return False
                q.append(node.left)
            else:
                flag=True
            if node.right:
                if flag or node.data<node.right.data:
                    return False
                q.append(node.right)
            else:
                flag=True
        return True