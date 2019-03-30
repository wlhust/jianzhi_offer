def hasPath(matrix, rows, cols, path):
    # write code here
    cnt = 0
    def moving(matrix, rows, cols, path, x, y):
        nonlocal cnt
        if cnt >= len(path):
            return 0
        print(path[cnt], x, y, 'mark', mark[4][7])
        if x > rows - 1 or y > cols - 1 or x < 0 or y < 0:
            return 0
        if mark[x][y] == 1:
            return 0
        if matrix[x][y] != path[cnt]:
            return 0
        else:
            print(x,y)
            mark[x][y] = 1
            cnt += 1
            if cnt >= len(path):
                return 0
            else:
                return moving(matrix,rows,cols,path,x,y+1)+moving(matrix,rows,cols,path,x,y-1)+moving(matrix,rows,cols,path,x-1,y)+moving(matrix,rows,cols,path,x+1,y)
    
    first = []
    for i in range(rows):
        for j in range(cols):
            if matrix[i][j] == path[0]:
                first.append([i, j])
    if len(first) == 0:
        return False
    for k in first:
        mark = [[0 for _ in range(cols)] for _ in range(rows)]
        moving(matrix, rows, cols, path, k[0], k[1])
        print(cnt)
        if cnt == len(path):
            return True
        cnt = 0
    return False

if __name__ == "__main__":
    
    # matrix = [['A','B','C','E'],['S','F','C','S'],['A','D','E','E']]
    matrix = [['A','B','C','E','H','J','I','G'],['S','F','C','S','L','O','P','Q'],['A','D','E','E','M','N','O','E'],['A','D','I','D','E','J','F','M'],['V','C','E','I','F','G','G','S']]
    # matrix = [['A','B','C','E'],['S','F','C','S']]
    hasPath(matrix, 5,8,"SGGFIECVAASABCEHJIGQEMS")
    # hasPath(matrix, 2, 4, 'SCFSABCES')