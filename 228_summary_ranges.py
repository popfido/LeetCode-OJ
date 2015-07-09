class Solution:
    # @param {integer[]} nums
    # @return {string[]}
    def summaryRanges(self, nums):
        res = [] if len(nums) == 0 else [(nums[0], nums[0])]
        for i in xrange(1,len(nums)):
            if nums[i]-1 != nums[i-1]:
                res.append((nums[i],nums[i]))
            else:
                refresh = res.pop()
                res.append((refresh[0],refresh[1]+1))
        res = map(lambda a: str(a[0]) if a[0] == a[1] else str(a[0]) + "->" + str(a[1]), res)
        return res