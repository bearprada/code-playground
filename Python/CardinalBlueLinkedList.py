"""
cardinal blue test quiz

[o]1. linked list
[o]2. check the cycle linked list
[o]3. reverse the linked list

a. is the two linked lists cross?
"""

class Node:
    def __init__(self,value):
        self.value = value
        self.next = None
    def setNextNode(self,next):
        self.next = next
    def setValue(self,value):
        self.value = value
    def getNext(self):
        return self.next
    def getValue(self):
        return self.value

class LinkedList:
    def __init__(self):
        self.root = None

    def getRoot(self):
        return self.root

    def insertNode(self,i):
        node = Node(i)
        if self.root == None:
            self.root = node
            return
        q = self.root
        while q.getNext()!=None:
            q = q.getNext()
        q.setNextNode(node)

    def printStack(self):
        q = self.root
        while q != None:
            print " > "+str(q.getValue())
            q = q.getNext()

    def shuffle(self):
        q = self.root
        while q.getNext() != None:
            q = q.getNext()
        q.setNextNode(self.root)

    def isCycled(self): # bad impl.
        tmp = []
        q = self.root
        while q != None:
            if q in tmp:
                return True
            else:
                tmp.append(q)
                q = q.getNext()
        return False

    def setNodeValue(self,fromValue,toValue):
        q = self.root
        while q != None:
            if q.getValue() == fromValue:
                q.setValue(toValue)
            q = q.getNext()

    def __isExsist__(self,node):
        q = self.root
        while q != None:
            if q == node:
                return False
            elif q == node.getNext():
                return True
            q = q.getNext()

    def isCycled2(self): # without temp memory to store the data we scan
        q = self.root
        while q != None:
            if self.__isExsist__(q):
                return True
            q = q.getNext()
        return False

    def isCycled3(self):
        p = self.root
        q = self.root
        for i in range(50): #FIXME the number should be meansful
            # p move 2 times
            if p.getNext()==None or p.getNext().getNext()==None:
                return False
            # q move 1 times
            if q.getNext()==None:
                return False
            q = q.getNext()
            p = p.getNext().getNext()
            if q==p:
                return True
        return False

    def reverse(self):
        if self.isCycled() == True:
            raise Exception('reason', 'it is a cycly linked list')
        else:
            p = self.root
            newRoot = None
            q = newRoot
            while(p!=None):
                q = p
                p = p.getNext()
                q.setNextNode(newRoot)
                newRoot = q
            self.root = newRoot

if __name__ == '__main__':
    linkedList = LinkedList()
    for i in range(0,100):
        linkedList.insertNode(i)
    linkedList.printStack()

    linkedList.reverse()
    print " --- print reverse list --- "
    linkedList.printStack()
    linkedList.reverse()
    print " --- print double reverse list --- "
    linkedList.printStack()

    print linkedList.isCycled()
    print linkedList.isCycled2()
    print linkedList.isCycled3()
    linkedList.shuffle()
    print linkedList.isCycled()
    print linkedList.isCycled2()
    print linkedList.isCycled3()

    try:
        linkedList.reverse()
    except Exception as inst:
        print '[EXCEPTION] ', str(inst)
