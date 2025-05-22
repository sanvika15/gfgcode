class Node:
    
    def __init__(self):
        self.children=[None]*26
        self.isEnd=False

class Trie:
    
    def __init__(self):
        self.root=Node()

    def insert(self, word: str):
        curr=self.root
        for w in word:
            i=ord(w)-ord("a")
            if curr.children[i]==None:
                curr.children[i]=Node()
            curr=curr.children[i]
        curr.isEnd=True

    def search(self, word: str) -> bool:
        curr=self.root
        for w in word:
            i=ord(w)-ord("a")
            if curr.children[i]==None:
                return False
            curr=curr.children[i]
        return curr.isEnd

    def isPrefix(self, word: str) -> bool:
        curr=self.root
        for w in word:
            i=ord(w)-ord("a")
            if curr.children[i]==None:
                return False
            curr=curr.children[i]
        return True