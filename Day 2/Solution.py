# -*- coding: utf-8 -*-
import re
import operator
with open("input.txt") as f:
    data = []
    for line in f:
        data.append(line)
        
         
        
def part1(data):
    validNum = []
    letter = []
    string = []
    i = 0
    for line in data:
        x = re.split(' ',line)
        validNum.append(x[0])
        letter.append(x[1][0])
        string.append(x[2])
    i = 0
    c = 0
    while i < len(string):
        a = validNum[i].split('-',2)
        n1 = int(a[0])
        n2 = int(a[1])
        check = string[i].count(letter[i])
        if check <= n2 and check >= n1:
            c += 1
        i += 1
    return c

def part2(data):
    validNum = []
    letter = []
    string = []
    i = 0
    for line in data:
        x = re.split(' ',line)
        validNum.append(x[0])
        letter.append(x[1][0])
        string.append(x[2])
    i = 0
    c = 0
    while i < len(string):
        a = validNum[i].split('-',2)
        n1 = int(a[0])
        n2 = int(a[1])
        if operator.xor(string[i][n1-1] == letter[i],string[i][n2-1]==letter[i]):
            c += 1
        i += 1
    return c


print(part1(data))
print(part2(data))
    
