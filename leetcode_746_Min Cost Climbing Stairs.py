# problem : https://leetcode.com/problems/min-cost-climbing-stairs?envType=study-plan-v2&envId=dynamic-programming
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        total_stairs = len(cost)
        total_cost = 0
        memo = [float('inf') for i in range(len(cost)+1)] # the array which contains the minimum cost until we reach the stairs N.
        # the elements in the last index is the minimum cost until we reach the top.

        memo[0] = 0
        memo[1] = 0

        for idx in range(2, len(memo), 1):
            option_1 = memo[idx-1] + cost[idx-1]
            option_2 = memo[idx-2] + cost[idx-2]

            min_cost = min(option_1, option_2)

            memo[idx] = min_cost

        return memo[-1]
        
