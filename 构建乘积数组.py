def multiply(A):
    # write code here
    B = [None]*len(A)
    B[0] = 1
    for i in range(1,len(A)):
        B[i] = B[i-1] * A[i-1]
    temp = 1
    for i in range(len(A)-2,-1,-1):
        temp = temp * A[i+1]
        B[i] *= temp
    return B

print(multiply([1,2,3,4,5]))