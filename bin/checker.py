#!/usr/bin/python3

import os

class Event:
    def __init__(self, line):
        spline = line.split()
        self.id = int(spline[1])
        self.type = int(spline[2])
        self.time = int(spline[3])

def checkAcuireReleaseIntersect(events):
    lockNum = 0
    for e in events:
        if e.type == 6: # Acquire
            lockNum += 1
        elif e.type == 1: # Release
            lockNum -= 1
        assert ((lockNum in [0, 1]))

def checkAquireAfterRequest(events):
    ac = dict()
    for e in events:
        if e.type == 2:
            ac[e.id] = ac.get(e.id, 0) + 1
        elif e.type == 6:
            ac[e.id] = ac.get(e.id, 0) - 1
        for p in ac:
            assert (ac[p] in [0, 1])

data = []

for file in os.listdir('log'):
    with open("log/{0}".format(file), 'r') as log:
        for line in log:
            data.append(Event(line))

data.sort(key=lambda x: x.time)

checkAcuireReleaseIntersect(data)
checkAquireAfterRequest(data)

print ("All tests were passed!")