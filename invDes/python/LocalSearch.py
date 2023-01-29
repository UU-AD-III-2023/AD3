import random
import numpy as np
import matplotlib.pyplot as plt
import time
from tqdm import tqdm
from operator import itemgetter




class Row():
    def __init__(self, *args):
        print(args)
        if isinstance(args[0], list):
            self.coloured = args
        else:
            max = args[0]
            aColoured = args[1]
            self.length = max
            self.coloured = np.zeros(max)
            while sum(self.coloured) < aColoured:
                x = random.randrange(max)
                if self.coloured[x] == 0:
                    self.coloured[x] = 1 
    def get_dot_product(self, other):
        a = np.array(self.coloured)
        b = np.array(other.coloured).transpose()
        return np.dot(a, b)
    def get_neibourghs(self):
        x = random.randrange(self.length)
        while self.coloured[x] !=  1:
            x = random.randrange(self.length)
        new_neibourgh = list()
        for i in range(self.length):
            if self.coloured[i] == 1:
                continue
            else:
                self.coloured[i] = 1
                new_neibourgh.append(self.coloured)
                self.coloured[i] = 0
        return new_neibourgh
                
class Matrix():
    def __init__(self, *args):
        if isinstance(args[0], list):
            self.rows = args
        else:
            length = args[0]
            width = args[1] 
            aColoured = args[2]
            self.rows = list()
            for i in range(width):
                self.rows.append(Row(length, aColoured))
    def max_dot_prod(self):
        lst = list()
        for i in range(len(self.rows)):
            lst.append(Row(self.rows[i]).coloured)
        a = np.array(lst)
        matrix = a @ a.T
        return max(matrix)
    def matrix_without_line(self, line, linenumber):
        lst = list()
        for i in range(len(self.rows)):
            if i != linenumber:
                lst.append(self.rows[i])
            else:
                lst.append(line)
        return lst
    def get_neibourgs(self):
        neighbourgh = list()
        for i in range(len(self.rows)):
            neighbourgh.append(self.rows[i].get_neibourghs())
        for i in range(len(neighbourgh)):
            for k in range(len(neighbourgh[i])):
                neighbourgh[i][k] = (i, neighbourgh[i][k], Matrix(self.matrix_without_line(len(neighbourgh[i][k]), i)).max_dot_prod())
        return neighbourgh

def lb(r, v, b):
    a2 = (r*v) % b
    if a2 != 0:
        a1 = ((r*v) // b + 1)**2
    else:
        a1 = ((r*v) // b)**2
    a3 = ((r*v) // b)**2
    a4 = b - (r*v) % b
    up = a1*a2 + a3 *a4 - r*v
    down = v*(v-1)
    if up % down == 0:
        return up // down
    else:
        return up // down + 1
# def choose_neibourgh(lst):
    
# v, b, r = input('v, b, l: ').split(',', 2) 
# v = int(v)
# b = int(b)
# r = int(r)
v = 10 # to be commented out
b = 8
r = 3
min = v
lb = lb(r, v, b)
n = 1
for _ in tqdm(range(n)):
    matrix = Matrix(v, b, r)
    print(matrix.get_neibourgs())
    
    # matrix = choose_neibourgh(lst)
    