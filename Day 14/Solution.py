import re
import itertools

def update_mem(mem,line,mask):
    m = re.search(r'\d+',line)
    key = int(m.group(0))
    val = mem[key]
    for i, v in enumerate(mask):
        if v =='1':
            val = val | 2**(36-i-1)
        elif v =='0':
            val = val & ~(2 ** (36 - i - 1))
    mem[key] = val
    return mem
def part1(code):
    mem = {}
    mask = ""
    for line in code:
        if 'mask' in line:
            mask = line.split('=')[1].strip()
        elif 'mem' in line:
            exec(line)
            mem = update_mem(mem,line,mask)
    return sum([mem[key] for key in mem])


def permute_masks(mask):
    masks = []
    bits = [i for i, v in enumerate(mask) if v == 'X']
    perms = [''.join(seq) for seq in itertools.product('21', repeat=len(bits))]
    new_mask = mask[:]
    for perm in perms:
        bit_vals = dict(zip(bits, perm))
        for k in bit_vals:
            new_mask = new_mask[:k] + bit_vals[k] + new_mask[k + 1:]
        masks.append(new_mask)
    return masks


def update_addr(addr, mask):
    addresses = []
    masks = permute_masks(mask)
    for mask in masks:
        for i, v in enumerate(mask):
            if v == '1':
                addr = addr | (2 ** (36 - i - 1))
            elif v == '2':
                addr = addr & ~(2 ** (36 - i - 1))
        addresses.append(addr)
    return addresses


def update_mem_part2(mem, line, mask):
    pattern = re.compile(r'\d+')
    match = pattern.findall(line)
    target_addr = int(match[0])
    target_value = int(match[1])
    addrs = update_addr(target_addr, mask)
    for addr in addrs:
        mem[addr] = target_value
    return mem


def part2(code):
    mem = {}
    mask = ""
    for line in code:
        if 'mask' in line:
            mask = line.split('=')[1].strip()
        elif 'mem' in line:
            mem = update_mem_part2(mem, line, mask)
        else:
            pass
    return sum([mem[key] for key in mem])
with open('input.txt') as f:
    code = f.read().strip().split('\n')
    print(part1(code))
    print(part2(code))