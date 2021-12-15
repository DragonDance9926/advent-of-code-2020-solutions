with open("input.txt") as f:
    commands = []
    for line in f:
        commands.append(line[:-1])


def part1(commands):
    points = ['N', 'E', 'S', 'W']
    facing = 'E'
    horizon = 0
    vertical = 0
    for command in commands:
        face = command[0]
        move = int(command[1:])
        if face == 'N':
            horizon += move
        elif face == 'S':
            horizon -= move
        elif face == 'E':
            vertical += move
        elif face == 'W':
            vertical -= move
            #{N,E,S,W} right 90 degrees each 0,1,2,3
        elif face == 'R':
            index = points.index(facing)
            facing = points[(index + (move // 90)) % 4]
        elif face == 'L':
            index = points.index(facing)
            facing = points[(index - (move // 90)) % 4]
        elif face == 'F':
            if facing == 'N':
                horizon += move
            elif facing == 'S':
                horizon -= move
            elif facing == 'E':
                vertical += move
            elif facing == 'W':
                vertical -= move
    return abs(horizon) + abs(vertical)

def wp_change(x_wp, y_wp, direction, degrees):
        x_wp_new = int()
        y_wp_new = int()
        if direction == "L":
            if degrees == 90:
                x_wp_new = y_wp * -1
                y_wp_new = x_wp
            elif degrees == 180:
                x_wp_new = x_wp * -1
                y_wp_new = y_wp * -1
            elif degrees == 270:
                x_wp_new = y_wp
                y_wp_new = x_wp * -1
        elif direction == "R":
            if degrees == 90:
                x_wp_new = y_wp
                y_wp_new = x_wp * -1
            elif degrees == 180:
                x_wp_new = x_wp * -1
                y_wp_new = y_wp * -1
            elif degrees == 270:
                x_wp_new = y_wp * -1
                y_wp_new = x_wp
        return x_wp_new, y_wp_new
def part2(data_input):
    x_wp = 10
    y_wp = 1
    x_ferry = 0
    y_ferry = 0
    for instruction in data_input:
        if instruction[0] == 'N':
            y_wp += int(instruction[1:])
        elif instruction[0] == 'S':
            y_wp -= int(instruction[1:])
        elif instruction[0] == 'E':
            x_wp += int(instruction[1:])
        elif instruction[0] == 'W':
            x_wp -= int(instruction[1:])
        elif instruction[0] == 'F':
            x_ferry += int(instruction[1:]) * x_wp
            y_ferry += int(instruction[1:]) * y_wp
        elif instruction[0] == 'R' or 'L':
            x_wp, y_wp = wp_change(x_wp, y_wp, instruction[0], int(instruction[1:]))
    return abs(x_ferry) + abs(y_ferry)

print(part1(commands))
print(part2(commands))