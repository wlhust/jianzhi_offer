class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def reConstructBinaryTree(pre, tin):
    # write code here
    if len(pre)>1:
        left_tin = tin[:tin.index(pre[0])]
        right_tin = tin[tin.index(pre[0])+1:]
        left_pre = pre[1:tin.index(pre[0])+1]
        right_pre = pre[tin.index(pre[0])+1:]
        print('left_pre:', left_pre)
        print('left_tin:', left_tin)
        print('right_pre:',right_pre)
        print('right_tin:', right_tin)
        print('******')
        reConstructBinaryTree(left_pre, left_tin)
        reConstructBinaryTree(right_pre, right_tin)
        

if __name__ == "__main__":
    pre = ['a','b','c','d','e','f','g']
    tin = ['d','c','b','a','e','f','g']
    reConstructBinaryTree(pre,tin)
