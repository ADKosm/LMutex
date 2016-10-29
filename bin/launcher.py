#!/usr/bin/python3
import sys, os

# [type] [number]
type = sys.argv[1]
number = int(sys.argv[2])
ports = int(sys.argv[3])

open('mutex.txt', 'tw+').close()

config = "{0} mutex.txt log/ {1}".format(type, number)

for i in range(1, number+1):
    config += " {0} 127.0.0.1 {1}".format(i, 1000*ports + i)

for i in range(1, number+1):
    os.system("./LMutex {0} {1} &".format(i, config))