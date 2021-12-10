# -*- coding: utf-8 -*-
with open('input.txt') as f:
    lines = f.read().split("\n\n")
    groups = []
    groups2 =  []
    for x in lines:
        a = x.split('\n')
        c = ''
        y = []
        for j in a:
            c += j
            y.append(j)
        groups2.append(y)
        groups.append(c)
        
            
    
print(groups2)
def part1(groups):
    c = 0
    for x in groups:
        c += len(set(list(x)))
    return c

def part2(groups2):
    c = 0
    for x in groups2:
        k = [set(i) for i in x]
        first = k[0]
        i = 1
        if len(k) > 1:
            while i < len(k):
                first.intersection_update(k[i])
                i += 1
        c += len(first)
    return c
            

print(part1(groups))
print(part2(groups2))