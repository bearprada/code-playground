class Skipper:
    def __init__(self,skipNum):
        self.skipNum = skipNum

    def next(self,num):
        return self.__findNext__(num)

    def __findNext__(self,num):
        count = num + 1
        while ((str(self.skipNum) not in str(count)) and (count%self.skipNum)) == False:
            count = count + 1
        return count

if __name__ == "__main__":
    print "=== test 3 game === "
    s3 = Skipper(3)
    for i in range(1,50):
        print "num : " +str(i) + " > "+ str(s3.next(i))
    print "=== test 4 game === "
    s4 = Skipper(4)
    for i in range(1,50):
        print "num : " +str(i) + " > "+ str(s4.next(i))
