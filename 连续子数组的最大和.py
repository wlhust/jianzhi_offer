# -*- coding:utf-8 -*-
class Solution:
    def FindGreatestSumOfSubArray(self, array):
        # write code here
        max_sum, cur_sum = -0xffffff, 0
        for i in array:
            if cur_sum <= 0:
                cur_sum = i
            else:
                cur_sum += i
            if cur_sum > max_sum:
                max_sum = cur_sum
        return max_sum

if __name__ == "__main__":
    sol = Solution()
    array = [6,-3,-5,7]