# -*- coding:utf-8 -*-
class Solution:
    def VerifySquenceOfBST(self, sequence):
        # write code here
        if len(sequence) == 1 or len(sequence) == 0:
            return True
        print(sequence)
        root = sequence[-1]
        left, right = 0, len(sequence) - 1
        while(left < right):
            if left == right - 1:
                if left == 0 and sequence[left] > root:
                    left -= 1
                break
            mid = (left + right) / 2
            # print(mid)
            if sequence[mid] < root:
                left = mid
            if sequence[mid] > root:
                right = mid
            
        print(left)
        flag1 = 0
        for i in sequence[:left+1]:
            if i > root:
                flag1 = 1
                return False
        flag2 = 0
        for i in sequence[left+1:-1]:
            if i < root:
                flag2 = 1
                return False
        print(left)
        return True and self.VerifySquenceOfBST(sequence[:left+1]) and self.VerifySquenceOfBST(sequence[left+1:-1])


if __name__ == "__main__":
    sol = Solution()
    sequence = [5,4]
    sol.VerifySquenceOfBST(sequence)