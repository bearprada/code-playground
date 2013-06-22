def quiz3Nplus1(n,mSum):
    if n <= 1:
        return mSum
    elif n%2==1:
        return quiz3Nplus1(n*3+1,mSum+1)
    else:
        return quiz3Nplus1(n/2,mSum+1)

if __name__ =='__main__':
    i = 1
    j = 10
    mMax = 0
    for q in range(i,j):
        tmp = quiz3Nplus1(q,1)
        if tmp > mMax:
            mMax = tmp
    print "max len : "+str(mMax)