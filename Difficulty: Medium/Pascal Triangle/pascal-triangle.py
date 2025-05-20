#User function Template for python3
from math import comb
class Solution:

	def nthRowOfPascalTriangle(self, n):
	    # code here]
	    return [comb(n-1,i) for i in range(n)]