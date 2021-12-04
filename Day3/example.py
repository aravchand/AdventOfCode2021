''' afternote: I figured out from this that the question was saying to count the most common bits
for each new list after every character '''




def p2():
    a2 = 0

    inp = []
    for line in open("AdventOfCode2021/Day3/example.in"):
        line = line.strip()
        inp.append(line)

    a = [[0, 0] for _ in range(5)] 
    # for _ in range(1000)]

    for line in inp:
        for i in range(5):
            if line[i] == "1":
                a[i][1] += 1
            else:
                a[i][0] += 1

    mx = [max(a[i]) == a[i][1] for i in range(5)]
    mn = [min(a[i]) == a[i][1] for i in range(5)]
    print(a)    
    # print(mx, mn)
    copy = inp
    s, t = "", ""
    for i in range(5):
        s += str(int(mx[i]))
        t += str(int(mn[i]))
    
    for i in range(5):
        if len(inp) == 1:
            break
        
        ne = []
        
        for which, line in enumerate(inp):
            want = None
            if a[i][0] == a[i][1]:
                want = "1"
                print(i + " is equal placing")
            else:
                want = s[i]
            if line[i] == want:
                ne.append(line)
        inp = ne

        print(inp)

    x1 = inp[0]

    inp = copy
    for i in range(5):
        if len(inp) == 1:
            break
            
        ne = []

        for line in inp:
            want = None
            if a[i][0] == a[i][1]:
                want = "0"
            else:
                want = t[i]
            if line[i] == want:
                ne.append(line)
        inp = ne

    x2 = inp[0]

    print(x1, x2)
    a2 = int(x1, 2) * int(x2, 2)
    print(a2)

p2()