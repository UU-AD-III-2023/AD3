import numpy as np
import scipy.special as scc
import math
import pandas as pd


input = open('DemoReports/results-SLS.tex', 'r')
line = input.readline()
line = input.readline()
line = line.replace("\\\n", '')
b = []
r = []
v = []
time_1 = []
time_2 = []
lb = []
steps_1 = []
steps_2 = []
lambda_1 = []
lambda_2 = []
bf_time = []


while line != '':
    line = line.split(' & ')
    v.append(int(line[0]))
    b.append(int(line[1]))
    r.append(int(line[2]))
    lb.append(int(line[3]))
    time_1.append(float(line[4]))
    steps_1.append(int(line[5]))
    lambda_1.append(int(line[6]))
    time_2.append(float(line[7]))
    steps_2.append(int(line[8]))
    lambda_2.append(int(line[9]))
    bf_time.append(scc.comb(b[-1], r[-1])**v[-1] / (time_1[-1] * math.factorial(v[-1])))
    line = input.readline()
    line = line.replace("\n", '')

data = list(zip(v, b, r, lb, time_1, steps_1, lambda_1, time_2, steps_2, lambda_2, bf_time))

df = pd.DataFrame(data=data, columns=['v', 'b', 'r', 'lb',  'time', 'steps', 'lambda', 'time', 'steps', 'lambda', 'bf'])
df.to_csv('test.csv', index=False, header=False)
