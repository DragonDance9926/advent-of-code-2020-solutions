import re
d = dict()
with open("input.txt") as f:
    for line in f:
        title = ""
        buffer = ""
        num = 0
        u_num = False
        parts = re.split(r',| ',line.strip().rstrip('.'))
        for part in parts:
            if part == 'contain':
                if (buffer.endswith('bag')):
                    buffer += 's'
                d[buffer] = {}
                title = buffer
                buffer = ''
            else:
                numis = True
                try:
                    a = int(part)
                except ValueError:
                    numis = False
                if numis:
                    if num != 0:
                        if (buffer.endswith('bag')):
                            buffer += 's'
                        d[title][buffer] = num
                        buffer = ""
                    num = int(part)
                else:
                    buffer += part
        if buffer == 'nootherbags':
            d[title] = 0
        else:
            if (buffer.endswith('bag')):
                    buffer += 's'
            d[title][buffer] = num


print(d)
def search(word):
    global d
    if (d[word] == 0):
        return 0
    if (word == 'shinygoldbags'):
        return 1
    return sum([d[word][k] * search(k) for k in d[word].keys()])

c = -1
for k in d.keys():
    if (search(k)):
        c += 1
print("Part 1:", c)

def search2(word):
    global d
    if (d[word] == 0):
        return 1
    return 1 + sum([(d[word][k] * search2(k)) for k in d[word].keys()])

print("Part 2:", search2('shinygoldbags') - 1)



