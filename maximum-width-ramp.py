class Solution:      
    def maxWidthRamp(self, nums: list[int]) -> int:
        stack = [0]
        maxLen = 0
        for i in range(1, len(nums)):
            if nums[i] < nums[stack[-1]]: stack += [i]

        while len(stack):
            top = stack.pop(0)
            for j in range(len(nums) - 1, top, -1):
                if nums[j] >= nums[top]: maxLen = max(maxLen, j - top)

        return maxLen
    
nums = [6,0,8,2,1,5]
print(Solution().maxWidthRamp(nums))