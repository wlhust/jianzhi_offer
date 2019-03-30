# -*- coding:utf-8 -*-
# topk 最小值
def adjust(arr, start, end):
    i = start
    temp = arr[i]
    j = 2 * i
    while j <= end:
        if j < end and arr[j] < arr[j+1]:
            j += 1
        if arr[j] > temp:
            arr[i], arr[j] = arr[j], arr[i]
            i = j
            j = 2 * i
        else:
            break
    arr[i] = temp

def topk(arr, k):
    arrk = [0] + arr[:k]
    print(arrk)
    for i in range(k / 2):
        adjust(arrk, k / 2 - i, k)
    print(arrk)
    print('*')
    for j in arr[k:]:
        if j < arrk[1]:
            arrk[1] = j
            adjust(arrk, 1, k)
        print(arrk)
        print('-----')
    return arrk[1:]

arr = [1,4,3,2,5,7,0,1]
print(topk(arr, 3))