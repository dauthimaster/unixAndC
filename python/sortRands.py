#James Current

# create or open file to put sorted numbers into
fs = open('sortedRands.csv', 'w')
# open unsorted randoms file
fu = open('rands.csv', 'r')

listIn = []

# read in first unsorted line
s = fu.readline()

# number of comparisons
count = 0

# fill unsorted list
while s:
    listIn.append(int(s[:len(s)-1]))
    s = fu.readline()

# init listOut with same length as listIn
listOut = [None] * len(listIn)

#simple insertion sort
for i in xrange(len(listIn)):
    val = listIn[i]
    pos = i
    while pos > 0 and val < listOut[pos - 1]:
        listOut[pos] = listOut[pos - 1]
        pos -= 1
# count each time we make a comparison
        count += 1
    listOut[pos] = val

# put sorted list into the file for sorted numbers
for i in xrange(len(listOut)):
    fs.write(str(listOut[i]) + '\n')

print count

# clean up
fs.close()
fu.close()

