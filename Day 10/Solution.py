
with open("input.txt") as f:
    volts = list(map(int,f.readlines()))
    volts.append(max(volts) + 3)
    volts.insert(0, 0)

def part1(volts):
    volts.sort()
    diff_one = 0
    diff_three = 0
    for i in range(1,len(volts)):
        if volts[i] - volts[i-1] == 1:
            diff_one += 1
        elif volts[i] - volts[i-1] == 3:
            diff_three += 1
    return diff_one*(diff_three)

def part2(volts):
    volts.sort()
    groups = []
    i = 1
    while (i < len(volts)-1):
        sub = []
        while volts[i] - volts[i-1] == 1:
            sub.append(volts[i-1])
            i += 1
        sub.append(volts[i-1])
        groups.append(sub)
        i += 1
        comb = 1
        for x in groups:
            if len(x) == 1 or len(x) == 2:
                comb *= 1
            elif len(x) == 3:
                comb *= 2
            elif len(x) == 4:
                comb *= 4
            elif len(x) == 5:
                comb *= 7

    return comb


print(part1(volts))
print(part2(volts))