#!/usr/bin/python3
import sys, os, shutil, random

# [type] [number]
type = sys.argv[1]
number = int(sys.argv[2])

# change port in different modes in order to avoid situation, when OS doesn't close ports yet
ports = random.randint(5000, 20000)

open('mutex.txt', 'tw+').close()

if os.path.exists('log'):
    shutil.rmtree('log')
os.mkdir('log')

config = "{0} mutex.txt log/ {1}".format(type, number)

for i in range(1, number+1):
    config += " {0} 127.0.0.1 {1}".format(i, ports + i)

for i in range(1, number+1):
    os.system("./LMutex {0} {1} &".format(i, config))

if type == "user":
    os.system("./cli 0 {0}".format(config))