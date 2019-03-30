# # -*- coding:utf-8 -*-
# class Solution:
#     def GetLeastNumbers_Solution(self, tinput, k):
#         # write code here
#         if k == 0:
#             return []
#         if len(tinput)<k:
#             return []
#         temp = tinput[-1]
#         out = [temp] + [x for x in tinput[:-1] if x <= temp]
#         if len(out) == k:
#             return sorted(out)
#         elif len(out) > k:
#             flag = 0
#             for i in out[1:]:
#                 if i != out[0]:
#                     flag = 1
#             if flag == 0:
#                 return out[:k]
#             else:
#                 return sorted(self.GetLeastNumbers_Solution(out, k))
#         else:
#             left = [x for x in tinput[:-1] if x > temp]
#             return sorted(self.GetLeastNumbers_Solution(left, k - len(out)) + out)