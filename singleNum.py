class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def singleNumber(self, nums):
        temp = 0
        for num in nums:
            temp ^= num
        return temp