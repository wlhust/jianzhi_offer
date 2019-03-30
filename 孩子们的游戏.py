# -*- coding:utf-8 -*-
class Solution:
    def LastRemaining_Solution(self, n, m):
        # write code here
        cur = 0
        num = range(n)
        while 1:
            print('num  ', num)
            print('cur', cur)
            print('n', n)
            print('******')
            if n == 1:
                return num[cur]
            temp = (cur + m - 1) % n
            num.pop(temp)
            if temp == n - 1:
                cur = 0
            else:
                cur = temp
            n -= 1

if __name__ == "__main__":
    sol = Solution()
    n = 5
    m = 4
    sol.LastRemaining_Solution(n, m)
