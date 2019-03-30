# -*- coding:utf-8 -*-
class Solution:
    def Permutation(self, ss):
        # write code here
        if ss == "":
            return []
        for i in range(len(ss)):
            char = ss[i]
            print(char, end='')
            if len(ss) == 1:
                print('')
                return
            if i == 0:
                self.Permutation(ss[i+1:])
            if i == len(ss) - 1:
                self.Permutation(ss[0:i])
            else:
                self.Permutation(ss[0:i]+ss[i+1:])

if __name__ == "__main__":
    sol = Solution()
    ss = "abc"
    sol.Permutation(ss)