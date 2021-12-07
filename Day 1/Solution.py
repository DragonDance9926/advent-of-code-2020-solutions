# -*- coding: utf-8 -*-
from itertools import combinations
lis = []
with open("input.txt") as f:
    for line in f:
        lis.append(line)
        
def part1(lis):
    comb = list(combinations(lis,2))
    i = 0
    while int(comb[i][0])+(int(comb[i][1])) != 2020:
        i += 1
    return int(comb[i][0])*int(comb[i][1])

def part2(lis):
    comb = list(combinations(lis,3))
    i = 0
    while int(comb[i][0])+(int(comb[i][1])+int(comb[i][2])) != 2020:
        i += 1
    return int(comb[i][0])*int(comb[i][1])*int(comb[i][2])

print(part1(lis))
print(part2(lis))
            
            