#James Current

import random

# open my files I need
fs = open('sortedRands.csv', 'r')
fd = open('firstDict.csv', 'w')

# random nums will be unique, but easy way to populate a list with randoms
rands = random.sample(range(200), 100)
# each line of fs is a key (without the newline)
keys = fs.readlines()
d = {}

# build dictionary
for i in xrange(len(rands)):
    d[int(keys[i][:len(keys[i])-1])] = rands[i]

# write dictionary to csv
for i in d:
    fd.write(str(i) + "," + str(d[i]) + '\n')

# clean up
fs.close()
fd.close()
