from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        out = []
        p = 1

        for i in range(0, len(nums)):
            out.append(p)
            p = p * nums[i]
        p = 1
        print(out)

        for i in range(len(nums) - 1, 0 - 1, -1):
            out[i] *= p
            p *= nums[i]
        return out


nums = [1, 2, 3, 4]
print(Solution().productExceptSelf(nums))
