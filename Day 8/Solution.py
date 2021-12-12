# -*- coding: utf-8 -*-
commands = []

with open("input.txt") as f:
    for line in f:
        commands.append(line[:-1])
        
        


def part1(commands):
    line = 0
    acc = 0
    while commands[line] != -1:
        x = commands[line].split()
        commands[line] = -1
        command = x[0]
        value = x[1]
        if '-' in value:
            num = int(value[1:])
            num *= -1
        elif '+' in value:
            num = int(value[1:])
        if command == "acc":
            acc += num
            line += 1
        elif command == "jmp":
            line += num
        else:
            line += 1
    return acc

    
        
        

print(part1(commands))