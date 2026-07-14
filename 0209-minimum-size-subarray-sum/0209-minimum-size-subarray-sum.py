class Solution(object):
    def minSubArrayLen(self, target, nums):
        left = 0
        currSum = 0
        ans = float('inf')

        for right in range(len(nums)):
            currSum += nums[right]

            while currSum >= target:
                ans = min(ans, right - left + 1)
                currSum -= nums[left]
                left += 1

        if ans == float('inf'):
            return 0
        return ans