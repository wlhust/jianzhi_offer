# -*- coding:utf-8 -*-
class TreeNode():
    def __init__(self,x):
        self.val = x
        self.left = None
        self.right = None

Val = [1,2,3,4,5,6]
Val2 = [1,2,3,4]
#        1
#     2     3
#   4   5  6

root = TreeNode(Val[0])
root2 = TreeNode(Val2[0])

def build_Tree(root, Val, i):
    if not root:
        return
    left_Node = TreeNode(Val[i*2+1]) if i*2+1 < len(Val) else None
    right_Node = TreeNode(Val[i*2+2]) if i*2+2 < len(Val) else None              
    root.left = left_Node
    build_Tree(root.left, Val, i*2+1)
    root.right = right_Node
    build_Tree(root.right, Val, i*2+2)

build_Tree(root, Val, 0)
build_Tree(root2, Val2, 0)

# class Solution:
#     def __init__(self):
#         self.pre = ''
    
#     def pre_tra(self,root):
#         if not root:
#             return None
#         self.pre += (str(root.val))
#         self.pre_tra(root.left)
#         self.pre_tra(root.right)
#         return self.pre

#     def HasSubtree(self, pRoot1, pRoot2):
#         # write code here
#         if pRoot2 is None or pRoot1 is None:
#             return False
#         pre1 = self.pre_tra(pRoot1)
#         print(pre1)
#         self.__init__()
#         pre2 = self.pre_tra(pRoot2)
#         print(pre2)
#         if pre2 in pre1:
#             return True
#         else:
#             return False

class Solution():
    def doesTree1hasTree2(self, pRoot1, pRoot2):
        if not pRoot2:
            return True
        if not pRoot1:
            return False
        if pRoot1.val == pRoot2.val:
            return self.doesTree1hasTree2(pRoot1.left, pRoot2.left) and self.doesTree1hasTree2(pRoot1.right, pRoot2.right)
        else:
            return False
        
    def HasSubtree(self, pRoot1, pRoot2):
        result = False
        if pRoot2 and pRoot1:
            if pRoot1.val == pRoot2.val:
                result = self.doesTree1hasTree2(pRoot1, pRoot2)
            if not result:
                result = self.HasSubtree(pRoot1.left, pRoot2)
            if not result:
                result = self.HasSubtree(pRoot1.right, pRoot2)
        return result

sol = Solution()
sol.HasSubtree(root, root2)