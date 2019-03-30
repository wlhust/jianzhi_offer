def FindNumbersWithSum(array, tsum):
    # write code here
    a = dict()
    out = dict()
    for i in range(len(array)):
        a[array[i]] = i
        sub = tsum-array[i]
        if not a.has_key(sub):
            a[sub] = i
        else:
            out[(array[i], sub)] = array[i] * sub
    out = sorted(out.items(), key=lambda x:x[1])
    print(out)
    if len(out) == 0:
        return []
    else:
        return sorted(out[0][0])

if __name__ == "__main__":
    print(FindNumbersWithSum([1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20],21))