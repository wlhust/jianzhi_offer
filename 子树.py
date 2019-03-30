# -*- coding:utf-8 -*-
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def __init__(self):
        self.pre = []
    
    def pre_tra(self,root):
        if root is None:
            return None
        self.pre.append(root.val)
        self.pre_tra(root.left)
        self.pre_tra(root.right)
        return self.pre

if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(5)
    root.left.left = TreeNode(3)
    root.left.right = TreeNode(4)
    root.right.left = TreeNode(6)
    root.right.right = TreeNode(7)
    root2 = TreeNode(0)
    root2.left = TreeNode(2)
    root2.right = TreeNode(5)
    root2.left.left = TreeNode(3)
    root2.left.right = TreeNode(4)
    root2.right.left = TreeNode(6)
    root2.right.right = TreeNode(7)
    sol = Solution()
    print(sol.pre_tra(root))
    sol.__init__()
    print(sol.pre_tra(root2))