def p1(): 
    a1 = 0
    '''
    For now, only consider horizontal and vertical lines: 
    lines where either x1 = x2 or y1 = y2.
    '''

    graph = [[0 for _ in range(1000)] for _ in range(1000)]

    for line in open("AdventOfCode2021/Day5/input.in"):
        line = line.strip().split("->")
        x1, y1 = [int(x) for x in line[0].split(",")]
        x2, y2 = [int(x) for x in line[1].split(",")]
        # print((x1, y1), (x2, y2))
        if not x1 == x2 and not y1 == y2:
            continue
        if x1 == x2:
            if y1 > y2:
                y1, y2 = y2, y1
            for y in range(y1, y2+1):
                graph[x1][y] += 1
        else:
            if x1 > x2:
                x1, x2 = x2, x1
            for x in range(x1, x2+1):
                graph[x][y1] += 1
    
    for row in graph:
        for n in row:
            if n >= 2:
                a1 += 1 
    print(a1)



def p2():
    a2 = 0
    '''Obviously, for part 2 we must include the diagonal lines,
    conveniently at 45 deg angles aka slopes of 1 or -1'''

    graph = [[0 for _ in range(1000)] for _ in range(1000)]

    for line in open("AdventOfCode2021/Day5/input.in"):
        line = line.strip().split("->")
        x1, y1 = [int(x) for x in line[0].split(",")]
        x2, y2 = [int(x) for x in line[1].split(",")]
        if x1 == x2:
            if y1 > y2:
                y1, y2 = y2, y1
            for y in range(y1, y2+1):
                graph[x1][y] += 1
        elif y1 == y2:
            if x1 > x2:
                x1, x2 = x2, x1
            for x in range(x1, x2+1):
                graph[x][y1] += 1
        else:
            if x1 > x2:
                x1, x2 = x2, x1
                y1, y2 = y2, y1
            
            if (x2-x1)/(y2-y1) == 1:
                for i in range(x2-x1+1):
                    graph[x1 + i][y1 + i] += 1
            else:
                for i in range(x2-x1+1):
                    graph[x1 + i][y1 - i] += 1


    for row in graph:
        for n in row:
            if n >= 2:
                a2 += 1 
    print(a2)


p1()
p2()