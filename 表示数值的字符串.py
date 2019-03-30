# -*- coding:utf-8 -*-
class Solution:
    # s字符串
    def isNumeric(self, s):
        # write code here
        hase, sign, decimal = False, False, False
        for i in range(len(s)):
            print(i)
            if s[i] == 'e' or s[i] == 'E':
                if i == len(s) - 1: # e后面要接数字
                    print('1')
                    return False
                if hase: # e不能出现多次
                    print('2')
                    return False
                hase = True
            elif s[i] == '+' or s[i] == '-':
                if sign and s[i-1] != 'e' and s[i-1] != 'E': # 第二次出现符号要在e后面
                    print('3')
                    return False
                if not sign and s != 0 and s[i-1] != 'e' and s[i-1] != 'E': # 第一次出现在非开头出也必须在e后面
                    print('4')
                    return False
                sign = True
            elif s[i] == '.':
                if hase or decimal: # 小数点不能出现在e后面，而且不能出现多次
                    print('5')
                    return False
                decimal = True
            elif s[i] < '0' or s[i] > '9':
                print('6')
                return False
        return True

if __name__ == "__main__":
    sol = Solution()
    s = '123.45e6'
    sol.isNumeric(s)