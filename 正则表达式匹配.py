# -*- coding:utf-8 -*-
import os

class Solution:
    # s, pattern都是字符串
    def match(self, s, pattern):
        # write code here
        if len(s) == 0 and len(pattern) == 0:
            print('1')
            return True
        if len(s) == 0 and len(pattern) == 2 and pattern[1] == '*':
            print('2')
            return True
        if len(s) > 0 and len(pattern) == 0:
            return False
        if len(pattern)>1 and pattern[1] == '*':
            if len(s)>0 and pattern[0] == '.':
                if len(s) == 1:
                    return True
                else:
                    print('4')
                    return self.match(s, pattern[2:]) or self.match(s[1:], pattern)
            if len(s)>0 and pattern[0] != '.':
                print('5')
                if s[0] == pattern[0]:
                    return self.match(s[1:], pattern) or self.match(s, pattern[2:])
                else:
                    return self.match(s, pattern[2:])
        if len(s)>0 and (pattern[0] == s[0] or pattern[0] == '.'):
            print('6')
            return self.match(s[1:], pattern[1:])
        # os.system("clear")
        return False
        

if __name__ == "__main__":
    sol = Solution()
    s = 'bcbbabab'
    pattern = '.*a*a'
    if sol.match(s, pattern):
        print('True')
    else:
        print('False')