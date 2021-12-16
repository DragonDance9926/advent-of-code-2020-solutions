#Part 1
with open("input.txt") as f:
    timestamp = int(f.readline())
    buses_bak = list(f.readline()[:-1].split(','))
    buses = [int(x) for x in buses_bak if x.isnumeric() == True]
    bus_offset = [buses_bak.index(str(x)) for x in buses]

i = 0
times = {}

for bus in buses:
    time = timestamp - (timestamp % bus)
    while time < timestamp:
        time += bus
    times[time] = bus

id = times[min(times.keys())]
print(id*(min(times.keys())-timestamp))

#Part 2



stepsize = buses[0]
timestamp = 0
i = 1
while i < len(buses):
    while ((timestamp + bus_offset[i]) % buses[i]) != 0 :
        timestamp += stepsize
    stepsize *= buses[i]
    i += 1
print(timestamp)
