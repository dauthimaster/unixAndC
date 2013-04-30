#James Current

import random

# create or open file 'rands.csv'
f = open('rands.csv', 'w')

# create 100 unique random numbers (since they will be used as keys in a map later)
rands = random.sample(range(200), 100)

# write 100 random numbers to rands.csv
for x in xrange(len(rands)):
    # turn a random number between 1 and 200 into a string, add an endline to it, then write to rands.csv
    f.write(str(rands[x]) + '\n')

# close rands.csv
f.close()
