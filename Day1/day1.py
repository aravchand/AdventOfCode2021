def p1(): 
    p1 = 0
    prev = None
    for line in open("AdventOfCode2021/Day1/input.in"):
        line = line.strip()
        x = int(line)
        if prev and x > prev:
            p1+=1
        prev = x
    print(p1)


def p2():
    a = []
    for line in open("AdventOfCode2021/Day1/input.in"):
        line = line.strip()
        x = int(line)
        a.append(x)

    sums = []

    for i in range(len(a)-2):
        sums.append(a[i] + a[i+1] + a[i+2])

    prev = None
    p2 = 0
    for x in sums:
        if prev and x > prev:
            p2+=1
        prev = x

    print(p2)

p1()
p2()