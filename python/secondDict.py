#James Current

import random, string

# grab files
fs = open('sortedRands.csv', 'r')
fd = open('secondDict.csv', 'w')

# each line in fs will be used as a key (minus the \n)
keys = fs.readlines()

d = {}

# create the map
for i in keys:
#match keys with a random string of 5 lowercase alphabetical characters
    d[int(i[:len(i)-1])] = ''.join(random.choice(string.lowercase) for i in xrange(5))

# write the map out to a file (specifically fd)
for i in d:
    fd.write(str(i) + "," + d[i] + '\n')

# clean up
fs.close()
fd.close()
