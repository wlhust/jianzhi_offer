# -*- coding:utf-8 -*-

import numpy as np

class Solution:
    def decompose(self, x):
        count = 0
        while x / 10 >= 1:
            num = x % 10
            count += num
            x /= 10
        count += x
        return count
    
    def print_(self, mark, rows, cols):
        for i in range(rows):
            for j in range(cols):
                print(mark[i][j], end='')
            print('\n', end='')
        print('\n')

    def movingCount(self, threshold, rows, cols):
        # write code here
        x, y = 0, 0
        mark = [[0 for _ in range(cols)] for _ in range(rows)]
        def moving(threshold, rows, cols, x, y):
            print(x, y)
            if x > cols - 1 or y > rows - 1:
                self.print_(mark, rows, cols)
                print(x, y, 'b')
                return 0
            if mark[y][x] == -1 or self.decompose(x) + self.decompose(y) > threshold:
                mark[y][x] = -1
                self.print_(mark, rows, cols)
                print(x, y, 'a')
                return 0
            if mark[y][x] == 1:
                self.print_(mark, rows, cols)
                print(x, y, 'c')
                return 0
            mark[y][x] = 1
            self.print_(mark, rows, cols)
            print(x, y, 'd')
            return 1 + moving(threshold, rows, cols, x+1, y) + moving(threshold, rows, cols, x, y+1)
        return moving(threshold, rows, cols, 0, 0)

if __name__ == "__main__":
    Sol = Solution()
    print(Sol.movingCount(4, 3, 4))