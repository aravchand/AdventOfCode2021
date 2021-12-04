def p1():
    xtot = 0
    ytot = 0
    for line in open("AdventOfCode2021/Day2/input.in"):
        line = line.strip()
        cmd, _x = line.split(" ")
        x = int(_x)
        if cmd == "forward":
            xtot += x
        elif cmd == "down":
            ytot += x
        elif cmd == "up":
            ytot -= x
    print(xtot * ytot)

def p2(): 
    xtot = 0
    ytot = 0
    aim = 0
    for line in open("AdventOfCode2021/Day2/input.in"):
        line = line.strip()
        cmd, _x = line.split(" ")
        x = int(_x)
        if cmd == "forward":
            xtot += x
            ytot += aim*x
        elif cmd == "down":
            aim += x
        elif cmd == "up":
            aim -= x
    print(xtot * ytot)

print("puzzle 1: ") 
p1()
print("puzzle 2: ")
p2()
