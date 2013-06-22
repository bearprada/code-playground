def MergeSort(arr):
    if len(arr) == 1:
        return arr
    return merge(mergeSort(arr[0:len(arr)/2]),mergeSort(arr[len(arr)/2:]))

def Merge(al,ar):
    r = []
    lidx = 0
    ridx = 0
    while (lidx<len(al)) and (ridx<len(ar)):
        if al[lidx] < ar[ridx]:
            r.append(al[lidx])
            lidx = lidx + 1
        else:
            r.append(ar[ridx])
            ridx = ridx + 1
    if lidx < len(al):
        r = r + al[lidx:]
    if ridx < len(ar):
        r = r + ar[ridx:]
    return r

if __name__=='__main__':
    for i in mergeSort([23,8,4,662,0,456,45,645,64]):
        print str(i)