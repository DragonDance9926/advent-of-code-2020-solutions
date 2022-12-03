def eval1(text):
    stack = []
    sum = 0
    buffer = ""
    for part in text:
        if part in '0123456789':
            buffer += part
        elif part in '+*()':
            if len(buffer) > 0:
                stack.append(int(buffer))
                buffer = ""
            stack.append(part)
        else:
            if len(buffer) > 0:
                stack.append(int(buffer))
                buffer = ""
    if len(buffer) > 0:
        stack.append(int(buffer))
        buffer = ""
    #print(stack)
    num_s = []
    op_s = []
    f = False
    while (len(stack) > 0):
        smt = stack.pop()
        if any([i in '0123456789' for i in str(smt)]):
            num_s.append(smt)
        elif smt in '+*)':
            op_s.append(smt)
        else:
            while True:
                l = op_s.pop()
                if l == ')':
                    break
                else:
                    n1 = num_s.pop()
                    n2 = num_s.pop()
                    num_s.append(eval(f"{n1}{l}{n2}"))
    while len(op_s) > 0:
        l = op_s.pop()
        n1 = num_s.pop()
        n2 = num_s.pop()
        num_s.append(eval(f"{n1}{l}{n2}"))
    return num_s[0]
            


def eval2(text):
    def pred(op):
        if op == '*':
            return 1
        return 2
    stack = []
    sum = 0
    buffer = ""
    for part in text:
        if part in '0123456789':
            buffer += part
        elif part in '+*()':
            if len(buffer) > 0:
                stack.append(int(buffer))
                buffer = ""
            stack.append(part)
        else:
            if len(buffer) > 0:
                stack.append(int(buffer))
                buffer = ""
    if len(buffer) > 0:
        stack.append(int(buffer))
        buffer = ""
    num_s = []
    op_s = []
    print(stack)
    while (len(stack) > 0):
        smt = stack.pop()
        if any([i in '0123456789' for i in str(smt)]):
            num_s.append(smt)
        elif smt in '+*':
            while(len(op_s) and op_s[-1] != ')' and len(num_s) >= 2 and pred(op_s[-1]) >= pred(smt)):
                n1 = num_s.pop()
                n2 = num_s.pop()
                num_s.append(eval(f"{n1}{op_s.pop()}{n2}"))
            op_s.append(smt)
        elif smt ==  ')':
            op_s.append(smt)
        else:
            while True:
                l = op_s.pop()
                if l == ')':
                    break
                else:
                    n1 = num_s.pop()
                    n2 = num_s.pop()
                    num_s.append(eval(f"{n1}{l}{n2}"))
    while len(op_s) > 0:
        l = op_s.pop()
        n1 = num_s.pop()
        n2 = num_s.pop()
        num_s.append(eval(f"{n1}{l}{n2}"))
    return num_s[0]


s = 0
s2 = 0
with open('input.txt') as f:
    for line in f:
        s += eval1(line)
        s2 += eval2(line)
print("Part 1:", s)
print("Part 2:", s2)