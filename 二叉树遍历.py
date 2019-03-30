class TreeNode():
    def __init__(self,x):
        self.val = x
        self.left = None
        self.right = None

Val = [1,2,3,4,5,6]

#        1
#     2     3
#   4   5  6

root = TreeNode(Val[0])
def build_Tree(root, Val, i):
    if not root:
        return
    left_Node = TreeNode(Val[i*2+1]) if i*2+1 < len(Val) else None
    right_Node = TreeNode(Val[i*2+2]) if i*2+2 < len(Val) else None              
    root.left = left_Node
    build_Tree(root.left, Val, i*2+1)
    root.right = right_Node
    build_Tree(root.right, Val, i*2+2)

#**先序遍历**#
# 递归
def preTraverse_recursion(root):
    if not root:
        return 
    print(root.val, end=' ')
    preTraverse_recursion(root.left)
    preTraverse_recursion(root.right)
    
# 非递归
def preTraverse(root):
    if not root:
        return
    stack = [root]
    while stack:
        node = stack.pop()
        print(node.val, end=' ')
        if node.right:
            stack.append(node.right)
        if node.left:
            stack.append(node.left)
    print('')

#**中序遍历**#
# 递归
def inTraverse_recursion(root):
    if not root:
        return
    inTraverse_recursion(root.left)
    print(root.val, end=' ')
    inTraverse_recursion(root.right)

# 非递归
def inTraverse(root):
    if not root:
        return
    stack = []
    node = root
    while node or stack:
        if node:
            stack.append(node)
            node = node.left
        else:
            node = stack.pop()
            print(node.val, end=' ')
            node = node.right

#**后序遍历**#
# 递归
def postTraverse_recursion(root):
    if not root:
        return
    postTraverse_recursion(root.left)
    postTraverse_recursion(root.right)
    print(root.val, end=' ')

# 非递归
def postTraverse(root):
    if not root:
        return
    stack1 = [root]
    stack2 = []
    while stack1:
        node = stack1.pop()
        stack2.append(node)
        if node.left:
            stack1.append(node.left)
        if node.right:
            stack1.append(node.right)
    while stack2:
        print(stack2.pop().val, end=' ')

#**层次遍历**#
def layerTraverse(root):
    if not root:
        return
    stack = [root]
    while stack:
        node = stack.pop(0)
        print(node.val, end=' ')
        if node.left:
            stack.append(node.left)
        if node.right:
            stack.append(node.right)
        
def layerTraverse_2(root):
    if not root:
        return
    stack = [root]
    res = [] 
    while stack:
        nextstack = []
        line = []
        for node in stack:
            line.append(node.val)
            if node.left:
                nextstack.append(node.left)                
            if node.right:
                nextstack.append(node.right)                
        
        res.append(line)
        print(line)
        stack = nextstack
    return res

build_Tree(root, Val, 0)
# print(root.val)
# print(root.left.val)
# print(root.right.val)
# print(root.left.left.val)
# print(root.left.right.val)
# print(root.right.left.val)
print('前序 递归')
preTraverse_recursion(root)
print('\n前序 非递归')
preTraverse(root)
print('\n中序 递归')
inTraverse_recursion(root)
print('\n中序 非递归')
inTraverse(root)
print('\n\n后序 递归')
postTraverse_recursion(root)
print('\n后序 非递归')
postTraverse(root)
print('\n\n层次遍历')
layerTraverse(root)
print('\n\n 分层打印')
layerTraverse_2(root)