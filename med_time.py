import sys
alpha = sys.argv[1]
beta = sys.argv[2]
str = "alpha_" + str(alpha) + "_beta_" + str(beta) + ".txt"
input = open(str, "r")
line = input.readline()
line = line.replace('\n', '')
count = 0
while line != '':
    count = 0
    av_time = 0
    while count != 5:
        if line.startswith("TIMING"):
            line = line.split(' ')
            av_time += float(line[1])
            count += 1
        line = input.readline()
        line = line.replace('\n', '')
    print(av_time/5)
    count += 1
    line = input.readline()
    line = line.replace('\n', '')
    if count >= 20:
        break
