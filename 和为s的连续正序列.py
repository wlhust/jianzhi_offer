import time

# def FindContinuousSequence(tsum):
#     # write code here
#     small = 1
#     big = 2
#     res = []
#     while not (big == tsum and small == tsum-1):
#         if (small + big)*(big - small + 1)/2 > tsum:
#             small += 1
#         elif (small + big)*(big - small + 1)/2 < tsum:
#             if big <= tsum:
#                 big += 1
#         else:
#             if big - small >= 1:
#                 res.append(range(small, big+1))
#             if big <= tsum:
#                 big += 1

#     return res

# def FindContinuousSequence(tsum):
#     # write code here
#     res=[]
#     for i in range(1,tsum/2+1):
#         for j in range(i,tsum/2+2):
#             tmp=(j+i)*(j-i+1)/2
#             if tmp>tsum:
#                 break
#             elif tmp==tsum:
#                 res.append(range(i,j+1))
#     return res

# -*- coding:utf-8 -*-

def FindContinuousSequence(tsum):
    # write code here
    res = []
    for n in range(int((2*tsum)**0.5), 1, -1):
        if (n % 2 != 0 and tsum % n == 0) or (n % 2 == 0 and (tsum % n) * 2 == n):
            begin = tsum / n - (n / 2 - 1)
            res.append([k for k in range(begin, begin+n)])
    return res

if __name__ == "__main__":
    start = time.time()
    print(FindContinuousSequence(3))
    end = time.time()
    print(end-start)