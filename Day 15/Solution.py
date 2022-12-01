start = [2,1,10,11,0,6]
d = {start[i]:(i + 1, 0) for i in range(len(start))}

last = start[-1]
turn = len(start) + 1
while turn <= 30000000:
    #print (turn, end=":")
    if last not in d or d[last][1] == 0:
        last = 0
    else:
        last = d[last][0] - d[last][1]
    if last not in d:
        d[last] = (turn, 0)
    else:
        d[last] = (turn, d[last][0])
    if (turn == 2020):
        print("Part 1:", last)
    turn += 1
print("Part 2:", last)


    
        

        