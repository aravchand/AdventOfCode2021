def p1(): 
    a1 = 0
    # [(#num zeros), (#num ones)]
    a = [[0, 0] for _ in range(12)] 

    for line in open("AdventOfCode2021/Day3/input.in"):
        line = line.strip()
        for i in range(12):
            if line[i] == "1":
                a[i][1] += 1
            else:
                a[i][0] += 1

    mx = [max(a[i]) == a[i][1] for i in range(12)]
    mn = [min(a[i]) == a[i][1] for i in range(12)]

    # print(mx, mn)
    s, t = "", ""
    for i in range(12):
        s += str(int(mx[i]))
        t += str(int(mn[i]))
    
    a1 = int(s, 2) * int(t, 2)
    print(s, t)
    print(a1)

def calcA(inp):
    a = [[0, 0] for _ in range(12)] 


    for line in inp:
        for i in range(12):
            if line[i] == "1":
                a[i][1] += 1
            else:
                a[i][0] += 1

    mx = [max(a[i]) == a[i][1] for i in range(12)]
    mn = [min(a[i]) == a[i][1] for i in range(12)]

    # print(mx, mn)
    copy = inp
    s, t = "", ""
    for i in range(12):
        s += str(int(mx[i]))
        t += str(int(mn[i]))
    return (a, s, t) 

def p2():
    a2 = 0

    inp = []
    for line in open("AdventOfCode2021/Day3/input.in"):
        line = line.strip()
        inp.append(line)

    a = [[0, 0] for _ in range(12)] 
    # for _ in range(1000)]

    for line in inp:
        for i in range(12):
            if line[i] == "1":
                a[i][1] += 1
            else:
                a[i][0] += 1

    mx = [max(a[i]) == a[i][1] for i in range(12)]
    mn = [min(a[i]) == a[i][1] for i in range(12)]

    # print(mx, mn)
    copy = inp
    s, t = "", ""
    for i in range(12):
        s += str(int(mx[i]))
        t += str(int(mn[i]))
    
    for i in range(12):
        if len(inp) == 1:
            break
        
        ne = []
        aa, ss, tt = calcA(inp)
        for line in (inp):
            
            want = None
            if aa[i][0] == aa[i][1]:
                want = "1"

            else:
                want = ss[i]
            if line[i] == want:
                ne.append(line)
        inp = ne

        print(inp)

    x1 = inp[0]

    inp = copy
    for i in range(12):
        if len(inp) == 1:
            break
            
        ne = []
        aa, ss, tt = calcA(inp)
        for line in inp:
            want = None
            if aa[i][0] == aa[i][1]:
                want = "0"
            else:
                want = tt[i]
            if line[i] == want:
                ne.append(line)
        inp = ne

    x2 = inp[0]

    print(x1, x2)
    a2 = int(x1, 2) * int(x2, 2)
    print(a2)
        

p1()
p2()