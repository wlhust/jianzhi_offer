def printMatrix(matrix):
    # write code here
    i, j = 0, 0
    h = len(matrix)
    w = len(matrix[0])
    bias_h = 0
    bias_w = 0
    fir = [0, 0]
    for k in range(h*w):
        print(matrix[j][i])
        if j == bias_h and i != w-bias_w-1:
            i += 1
        elif i == w-bias_w-1 and j != h-bias_h-1:
            j += 1
        elif j == h-bias_h-1 and i != bias_w:
            i -= 1
        elif i == bias_w and j != bias_h:
            j -= 1
        if [j, i] == fir:
            bias_h += 1 
            bias_w += 1
            j += 1
            i += 1
            fir = [j, i]
        

if __name__ == "__main__":
    matrix = [[1,2,3,4,5],[6,7,8,9,10],[11,12,13,14,15],[16,17,18,19,20],[21,22,23,24,25]]
    printMatrix(matrix)    