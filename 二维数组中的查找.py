# -*- coding:utf-8 -*-
import numpy as np

# array 二维列表
def Find(target, array):
    # write code here
    if len(array) == 0:
        return False
    h = len(array)
    w = len(array[0])
    idx_w, idx_h = 1, 0
    while idx_w < w and idx_h < h:
        if target == array[idx_h][w-idx_w]:
            return True
        if target < array[idx_h][w-idx_w]:
            idx_w += 1
        elif target > array[idx_h][w-idx_w]:
            idx_h += 1
        if idx_h != h and idx_w != w and target == array[idx_h][w-idx_w]:
            return True
            # print(array[idx_h][w-idx_w])
    if (idx_w == w or idx_h == h):
        return False
    else:
        return True

if __name__ == "__main__":
    array = np.array([[1,2,8,9],[2,4,9,12],[4,7,10,13],[6,8,11,15]])
    target = 16
    print(Find(target, array))