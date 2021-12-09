# -*- coding: utf-8 -*-

with open('input.txt') as f:
    lines = []
    for line in f:
        lines.append(line[:-1])
        
a = 'FBFBBFFRLR'
    
#Part 1
def part1(lines):
    ids = []
    for a in lines:
        sn = 128
        s = 0
        e = 127
        for x in a[:-3]:
            if x == 'F':
                sn = sn //2
                e = e - sn
            if x == 'B':
                sn = sn //2
                s += sn
        cn = 8
        sc = 0
        ec = 7
        for x in a[-3:]:
            if x == 'R':
                cn = cn//2
                sc += cn
            if x == 'L':
                cn = cn//2
                ec -= cn
        ids.append(s*8 + ec)
    return ids

print(max(part1(lines)))

#Part 2
def part2(lines):
    ids = []
    for a in lines:
        sn = 128
        s = 0
        e = 127
        for x in a[:-3]:
            if x == 'F':
                sn = sn //2
                e = e - sn
            if x == 'B':
                sn = sn //2
                s += sn
        cn = 8
        sc = 0
        ec = 7
        for x in a[-3:]:
            if x == 'R':
                cn = cn//2
                sc += cn
            if x == 'L':
                cn = cn//2
                ec -= cn
        if s != 127 or s !=0:
            ids.append(s*8 + ec)
    for x in ids:
        for y in ids:
            if (abs(x-y) == 2) and (x+y) // 2 not in ids:
                a = (x+y) // 2
                break
    return a

print(part2(lines))
    
    
