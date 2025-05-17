class Solution:
    def nextLargerElement(self, arr):
        stk = []
        ans = []
        for item in arr[::-1]:
            while stk and item >= stk[-1]: stk.pop()
            if not stk: ans.append(-1)
            else: ans.append(stk[-1])
            stk.append(item)
        return ans[::-1]


#{ 
 # Driver Code Starts
# Initial Template for Python 3

t = int(input())  # number of test cases
for _ in range(t):
    arr = list(map(int, input().split()))  # input array
    s = Solution().nextLargerElement(arr)  # find the next greater elements

    # Output formatting
    if s:
        print(" ".join(map(str, s)))  # Print next greater elements
    else:
        print("[]")  # Print empty list if no next greater element is found
    print("~")
# } Driver Code Ends