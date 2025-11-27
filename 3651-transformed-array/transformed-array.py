class Solution:
    def constructTransformedArray(self, nums: List[int]) -> List[int]:
        N = len(nums)
        result = [None] * N
        for i in range(N):
            result[i] = nums[(i + nums[i]) % N]
            

        return result
