# problem : https://leetcode.com/problems/house-robber?envType=study-plan-v2&envId=dynamic-programming
class Solution:
    def rob(self, nums: List[int]) -> int:
        memo = [None for i in range(len(nums))]

        memo[0] = nums[0]

        if len(nums) == 1:
            return memo[0]

        memo[1] = max(memo[0], nums[1])

        if len(nums) == 2:
            return max(nums[0], nums[1])

        for i in range(2, len(nums), 1):
            memo[i] = max(memo[i-1], memo[i-2]+nums[i])

        return memo[-1]
