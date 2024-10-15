# problem : https://leetcode.com/problems/fibonacci-number/description/?envType=study-plan-v2&envId=dynamic-programming

class Solution:
    def fib(self, n: int) -> int:

        if n == 0:
            return 0

        if n == 1:
            return 1

        # initialize the memo array.

        memo = [None for i in range(n+1)]
        memo[0] = 0
        memo[1] = 1

        for i in range(2, n+1, 1):
            memo[i] = memo[i-1] + memo[i-2]


        return memo[n]
