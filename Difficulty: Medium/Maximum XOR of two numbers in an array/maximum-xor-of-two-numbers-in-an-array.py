#User function Template for python3

class TrieNode:
    def __init__(self):
        self.child = [None, None]  # 0 and 1

class Solution:
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, num):
        node = self.root
        for i in range(20, -1, -1):  # 20 bits for up to 10^6
            bit = (num >> i) & 1
            if not node.child[bit]:
                node.child[bit] = TrieNode()
            node = node.child[bit]

    def findMaxXor(self, num):
        node = self.root
        max_xor = 0
        for i in range(20, -1, -1):
            bit = (num >> i) & 1
            toggled_bit = 1 - bit
            if node.child[toggled_bit]:
                max_xor |= (1 << i)
                node = node.child[toggled_bit]
            else:
                node = node.child[bit]
        return max_xor

    def maxXor(self, arr):
        max_result = 0
        for num in arr:
            self.insert(num)
        
        for num in arr:
            max_result = max(max_result, self.findMaxXor(num))
        
        return max_result