# problem : https://leetcode.com/problems/n-th-tribonacci-number/description/?envType=study-plan-v2&envId=dynamic-programming

class Solution:
    def tribonacci(self, n: int) -> int:
        if n == 0:
            return 0

        if n == 1:
            return 1

        if n == 2:
            return 1

        # initialize the memo array.
        memo = [ None for i in range(n+1)]
        
        memo[0] = 0
        memo[1] = 1
        memo[2] = 1

        
        for i in range(3, n+1, 1):
            memo[i] = memo[i-1] + memo[i-2] + memo[i-3]

        return memo[n]

        
