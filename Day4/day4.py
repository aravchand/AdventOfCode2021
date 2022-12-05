def p1(): 
    a1 = 0

    numbers = None
    boards = []
    
    cur = []
    for line in open("AdventOfCode2021/Day4/input.in"):
        line = line.strip()
        if numbers is None:
            numbers = line.split(",")
        elif line != "":
            cur.append(line.split())
        else:
            boards.append(cur)
            cur = []
    boards.remove([])
    boards.append(cur)
    # print(len(boards))
    
    marked = [[[False for _ in range(5)] for _ in range(5)] for _ in range(100)]

    for num in numbers:
        for bnum, board in enumerate(boards):
            res = contains(board, num)
            if res == False:
                pass
            else:
                marked[bnum][res[1][0]][res[1][1]] = True
                if win(marked[bnum]):
                    a1 = int(num) * sumUnmarked(board=board, marked=marked[bnum])
                    print(a1)
                    return;        


def contains(board, num):
    for r in range(5):
        for c in range(5):
            if num == board[r][c]:
                return [True, [r, c]]
    return False


def win(marked):
    for row in marked:
        if row == [True, True, True, True, True]:
            return True
    for c in range(5):
        cur = []
        for r in range(5):
            cur.append(marked[r][c])
        if cur == [True, True, True, True, True]:
            return True
    mainDiag = []
    for i in range(5):
        mainDiag.append(marked[i][i])
    if mainDiag == [True, True, True, True, True]:
        return True
    
    otherD = []
    for i in range(5):
        otherD.append(marked[i][5-i-1])
    if otherD == [True, True, True, True, True]:
        return True
    
    return False


def sumUnmarked(board, marked):
    sum = 0
    for r in range(5):
        for c in range(5):
            if marked[r][c] == False:
                sum += int(board[r][c])
    return sum


def p2():
    a2 = 0

    numbers = None
    boards = []
    
    cur = []
    for line in open("AdventOfCode2021/Day4/input.in"):
        line = line.strip()
        if numbers is None:
            numbers = line.split(",")
        elif line != "":
            cur.append(line.split())
        else:
            boards.append(cur)
            cur = []
    boards.remove([])
    boards.append(cur)
    # print(len(boards))
    
    marked = [[[False for _ in range(5)] for _ in range(5)] for _ in range(100)]

    won = [False for _ in range(1000)]
    orderWon = []
    boardWhenWon = {}  # not neccesarily needed due to the continue if won statement
    for num in numbers:
        for bnum, board in enumerate(boards):
            if won[bnum]:
                continue
            res = contains(board, num)
            if res == False:
                pass
            else:
                marked[bnum][res[1][0]][res[1][1]] = True
                if win(marked[bnum]):
                    won[bnum] = True
                    orderWon.append(bnum)
                    boardWhenWon[bnum] = [num, board, marked[bnum]]

    n, b1, m1 = boardWhenWon[orderWon[-1]]
    a2 = int(n) * sumUnmarked(b1, m1)
    print(a2)
            
        
p1()
p2()