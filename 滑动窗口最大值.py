def maxInWindows(num, size):
    # write code here
    que = [0]
    out = []
    for idx, i in enumerate(num):
        if idx > size and que[0] <= idx - size:
            que.pop(0)
        while que and num[que[-1]] < i:
            que.pop()
        que.append(idx)
        if idx >= size - 1:
            out.append(num[que[0]])
    return out

            
if __name__ == "__main__":
    num = [2,3,4,2,6,2,5,1]
    size = 3
    out = maxInWindows(num, size)
    print(out)