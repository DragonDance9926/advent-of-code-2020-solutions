import random
from itertools import permutations
import re
borders = []
with open("input.txt") as f:
    x =  f.read().split('\n\n')
    #print(x)
    for y in x[0].split('\n'):
        b1 = y.split()[-3].strip()
        b11, b12 = map(int, b1.split('-'))
        b2 = y.split()[-1].strip()
        b21, b22 = map(int, b2.split('-'))
        #print(b11,b12,b21,b22)
        borders.append([b11,b12,b21,b22])
    #print(x[1].split(':')[1].strip().split(','))
    mytict = [int(i) for i in x[1].split(':')[1].strip().split(',')]
    othtict = [ [int(i) for i in x.split(',')] for x in x[2].split(':')[1].strip().split('\n')]


err = 0;


valid_tict = []
i = 0
for person in othtict:
    valid = True
    for data in person:
        j = 0
        for v in borders:
            j += v[0] <= data <= v[1] or v[2] <= data <= v[3]
        if not j:
            err += data
            valid = False
    if valid:
        valid_tict.append(person)

print("Part 1:", err)
print(len(othtict), len(valid_tict))


with open("input.txt") as f:
    notes = f.read().strip()

fields = [
    (c, int(a_1), int(a_2), int(b_1), int(b_2))
    for c, a_1, a_2, b_1, b_2 in re.findall(
        r"((?:\w+ ?)+): (?:(\d+)-(\d+)) or (?:(\d+)-(\d+))", notes
    )
]
my_ticket, *nearby_tickets = [
    list(map(int, ticket.split(",")))
    for ticket in re.findall(r"^((?:\d+,?)+)$", notes, flags=re.MULTILINE)
]

valid_tickets = valid_tict
product = 1
columns = set(range(6))
product = 1
columns = set(range(len(fields)))
for _ in range(len(fields)):
    for i, (field, a, b, c, d) in enumerate(fields):
        candidates = [
            col
            for col in columns
            if all(
                a <= ticket[col] <= b or c <= ticket[col] <= d
                for ticket in valid_tickets
            )
        ]
        if len(candidates) == 1:
            columns.remove(candidates[0])
            fields = fields[:i] + fields[i + 1 :]

            if field.startswith("departure"):
                product *= my_ticket[candidates[0]]
            break
print("Part 2:", product)
