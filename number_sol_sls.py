import numpy as np
import scipy.special as scc
import math
import pandas as pd


input = open('data.csv', 'r')
line = input.readline()
line = line.replace("\n", '')
b = []
r = []
v = []
time = []
while line != '':
    line = line.split(',')
    v.append(int(line[0]))
    b.append(int(line[1]))
    r.append(int(line[2]))
    time.append(scc.comb(b[-1], r[-1])**v[-1] / math.factorial(v[-1]))
    line = input.readline()
    line = line.replace("\n", '')

data = list(zip(v, b, r, time))

df = pd.DataFrame(data=data, columns=['v', 'b', 'r', 'time'])
df.to_csv('test.csv', index=False, header=True)

