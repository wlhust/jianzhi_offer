# -*- coding:utf-8 -*-
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
class Solution:
    def Serialize(self, root):
        # write code here
        if not root:
            return '#'
        return str(root.val) + self.Serialize(root.left) + self.Serialize(root.right)
    
    def Deserialize(self, s):
        # write code here
        return self.deserialize(list(s))
        
    def deserialize(self, s):
        if s:
            val = s.pop(0)
            root = None
            if val != '#':
                print(val)
                root = TreeNode(int(val))
                root.left = self.deserialize(s)
                root.right = self.deserialize(s)
            return root

if __name__ == "__main__":
    sol = Solution()
    s = '865##7##109##11##'
    sol.Deserialize(s)