#James Current

# magic
def makeDict(f):
#value to be returned
    d = {}
#grab all the lines from the file
    lines = f.readlines()

    for i in lines:
#key and value stored on this line, key at 0, value at 1
        knv = i[:len(i)-1].split(',')

#set them up in our map
        d[knv[0]] = knv[1]

    return d

# grab all the files we need
fd1 = open('firstDict.csv', 'r')
fd2 = open('secondDict.csv', 'r')
f = open('pretendItsAWebSite.csv', 'w')

# recreate the maps stored in each file
d1 = makeDict(fd1)
d2 = makeDict(fd2)

# write each key and the matching values from d1 and d2 to a file
for i in d1:
    f.write(i + ',' + d1[i] + ',' + d2[i] + '\n')

# clean up
fd1.close()
fd2.close()
f.close()


