# -*- coding:utf-8 -*-
class Solution:
    def IsPopOrder(self, pushV, popV):
        # write code here
        idx = pushV.index(popV[0])
        cur = pushV[:idx]
        res = pushV[idx+1:]
        for i in range(1,len(popV)):
            print('in cur', cur, ' res', res, '  popV', popV[i])
            if popV[i] in cur:
                if popV[i] != cur[-1]:
                    return False
                else:
                    cur.pop()
            elif popV[i] in res:
                cur = cur + res[:res.index(popV[i])]
                res = res[res.index(popV[i])+1:]
            else:
                return False
            print('out cur', cur, ' res', res, '  popV', popV[i])
        return True



if __name__ == "__main__":
    sol = Solution()
    pushV = [1,2,3,4,5]
    popV = [4,5,3,2,1]
    if sol.IsPopOrder(pushV, popV):
        print('True')
    else:
        print('False')
