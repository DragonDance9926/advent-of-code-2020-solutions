
with open("input.txt") as f:
    mapping = [list(x)[:-1] for x in f.readlines()]

def rules(mapping, i, j):
    occ = 0
    if i < len(mapping) - 1:
        if mapping[i + 1][j] == '#':
            occ += 1  # down
        if j > 0:
            if mapping[i + 1][j - 1] == '#':
                occ += 1  # ldcorner

        if j < len(mapping[0]) - 1:
            if mapping[i + 1][j + 1] == '#':
                occ += 1 # rdcorner

    if i > 0:
        if mapping[i - 1][j] == '#':
            occ += 1  # up
        if j > 0:
            if mapping[i - 1][j - 1] == '#':
                occ += 1  # lucorner
        if j < len(mapping[0]) - 1:
            if mapping[i - 1][j + 1] == '#':
                occ += 1  # rucorner

    if j > 0:
        if mapping[i][j - 1] == '#':
            occ += 1   # left
    if j < len(mapping[0]) - 1:
        if mapping[i][j + 1] == '#':
            occ += 1  # right
    if occ >= 4 and mapping[i][j] == '#':
        return 'empty'
    elif occ == 0 and mapping[i][j] == 'L':
        return 'occ'
    else:
        return 0


def part1(mapping):
    loop = 1
    while loop:
        occ_coor = []
        empty_coor = []
        b = 0
        i = 0
        while i < len(mapping):
            j = 0
            while j < len(mapping[0]):
                if mapping[i][j] == '#':
                    b += 1
                j += 1
            i += 1

        i = 0
        while i < len(mapping):
            j = 0
            while j < len(mapping[0]):
                if mapping[i][j] == 'L' or mapping[i][j] == '#':
                    if rules(mapping, i, j) == 'empty':
                        empty_coor.append((i,j))
                    elif rules(mapping, i, j) == 'occ':
                        occ_coor.append((i,j))
                j += 1
            i += 1
        for (i,j) in empty_coor:
            mapping[i][j] = 'L'
        for (i,j) in occ_coor:
            mapping[i][j] = '#'
        a = 0
        i = 0
        while i < len(mapping):
            j = 0
            while j < len(mapping[0]):
                if mapping[i][j] == '#':
                    a += 1
                j += 1
            i += 1
        if a == b:
            loop = 0
    return b


def rules2(mapping, i, j):
    occ = 0
    if i < len(mapping) - 1:
        a = i + 1
        while a < len(mapping):
            if mapping[a][j] == '#':
                occ += 1
                break
            if mapping[a][j] == 'L':
                break
            a += 1
        if j > 0:
            a = i + 1
            b = j - 1
            while a < len(mapping) and b >= 0:
                if mapping[a][b] == '#':
                    occ += 1  # ldcorner
                    break
                if mapping[a][b] == 'L':
                    break
                a += 1
                b -= 1

        if j < len(mapping[0]) - 1:
            a = i + 1
            b = j + 1
            while a < len(mapping) and b < len(mapping[0]):
                if mapping[a][b] == '#':
                    occ += 1  # rdcorner
                    break
                if mapping[a][b] == 'L':
                    break
                a += 1
                b += 1

    if i > 0:
        a = i-1
        while a >= 0:
            if mapping[a][j] == '#': # up
                occ += 1
                break
            if mapping[a][j] == 'L':
                break
            a -= 1

        if j > 0:
            a = i - 1
            b = j - 1
            while a >= 0 and b >= 0:
                if mapping[a][b] == '#':
                    occ += 1  # lucorner
                    break
                if mapping[a][b] == 'L':
                    break
                a -= 1
                b -= 1
        if j < len(mapping[0]) - 1:
            a = i - 1
            b = j + 1
            while a >= 0 and b < len(mapping[0]):
                if mapping[a][b] == '#':
                    occ += 1  # rucorner
                    break
                if mapping[a][b] == 'L':
                    break
                a -= 1
                b += 1

    if j > 0:
        b = j-1
        while b >= 0:
            if mapping[i][b] == '#':
                occ += 1  # left
                break
            if mapping[i][b] == 'L':
                break
            b -= 1
    if j < len(mapping[0]) - 1:
        b = j + 1
        while b < len(mapping[0]):
            if mapping[i][b] == '#':
                occ += 1  # right
                break
            if mapping[i][b] == 'L':
                break
            b += 1
    if occ >= 5 and mapping[i][j] == '#':
        return 'empty'
    elif occ == 0 and mapping[i][j] == 'L':
        return 'occ'
    else:
        return 0

def part2(mapping):
    loop = 1
    while loop:
        occ_coor = []
        empty_coor = []
        b = 0
        i = 0
        while i < len(mapping):
            j = 0
            while j < len(mapping[0]):
                if mapping[i][j] == '#':
                    b += 1
                j += 1
            i += 1

        i = 0
        while i < len(mapping):
            j = 0
            while j < len(mapping[0]):
                if mapping[i][j] == 'L' or mapping[i][j] == '#':
                    if rules2(mapping, i, j) == 'empty':
                        empty_coor.append((i,j))
                    elif rules2(mapping, i, j) == 'occ':
                        occ_coor.append((i,j))
                j += 1
            i += 1
        for (i,j) in empty_coor:
            mapping[i][j] = 'L'
        for (i,j) in occ_coor:
            mapping[i][j] = '#'
        a = 0
        i = 0
        while i < len(mapping):
            j = 0
            while j < len(mapping[0]):
                if mapping[i][j] == '#':
                    a += 1
                j += 1
            i += 1
        if a == b:
            loop = 0
    return b
print(part2(mapping))