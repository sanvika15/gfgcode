class Solution(object):
 def kthSmallest(self, m, n, k):
    l,h=1,m*n
    count_less_equal=lambda x:sum(min(n,x//i) for i in range(1,m+1))
    while l<h:
        mid=(l+h)//2
        if count_less_equal(mid)<k:
            l=mid+1
        else:
            h=mid
    return l