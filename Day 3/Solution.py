# -*- coding: utf-8 -*-
with open("input.txt") as f:
    mapping = []
    for line in f:
        mapping.append(line[:-1])
        
'''
x.##.......  0,0 -> 3,1 -6,2 -> 9,3 ->1,4
#..x#...#..  l = 11
.#....x..#.
..#.#...#x#
.x...##..#.
..#.##.....
.#.#.#....#
.#........#
#.##...#...
#...##....#
.#..#...#.#'
'''

def part1(mapping):
    w = len(mapping[0])
    x = 0
    y = 0
    c = 0
    while y < len(mapping):
        if mapping[y][x%w] == '#':
            c += 1
        x += 3
        y += 1
    return c

def part2(mapping):
    tot = 1
    w = len(mapping[0])
    a = [1,3,5,7,1]
    b = [1,1,1,1,2]
    i = 0
    while i < len(a):
        x = 0
        y = 0
        c = 0
        while y < len(mapping):
            if mapping[y][x%w] == '#':
                c+= 1
            x += a[i]
            y += b[i]
        tot *= c
        i += 1
    return tot
                
    

print(part1(mapping))
print(part2(mapping))