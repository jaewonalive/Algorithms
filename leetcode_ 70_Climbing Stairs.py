# problem : https://leetcode.com/problems/climbing-stairs/description/?envType=study-plan-v2&envId=dynamic-programming


class Solution:
    def climbStairs(self, n: int) -> int:
        # initialize the memo table.

        memo = [None for i in range(n+1)]

        # memo[n] is the number of ways to climb up the stairs when n stairs remain.

        if n == 0 :
            return 1
        
        if n == 1:
            return 1


        memo[0] = 1 # initial condition.
        memo[1] = 1


        # memo[n] = (memo[n-1]) + (memo[n-2])

        for i in range(2, n+1, 1):
            memo[i] = memo[i-1] + memo[i-2]

        
        return memo[n]
