class ShowLogger:
    def __showOperation__(self,num,paramName):
        if num > 0:
            if num is 1:
                return "+"+paramName
            else:
                op = "+"
                if num < 0 :
                    op = "-"
                return op + str(num)+ paramName
        else:
            return ""

class ComplexNumber(ShowLogger):
    def __init__(self,real,ima):
        self.r = real
        self.i = ima
    def show(self):
        print str(self.r) + self.__showOperation__(self.i,"i") 

    def __add__(self,other):
        mr = self.r + other.r
        mi = self.i + other.i
        return ComplexNumber(mr, mi)

    def __sub__(self,other):
        mr = self.r - other.r
        mi = self.i - other.i
        return ComplexNumber(mr, mi)

    def __div__(self,other): # (ac+bd)/(c^2+d^2) + (bc-ad)/(c^2+d^2) i
        tmp = (other.r*other.r)+(other.i*other.i)
        mr = ((self.r*other.r)+(self.i*other.i))/tmp
        mi = ((self.i*other.r)-(self.r*other.i))/tmp
        return ComplexNumber(mr, mi)

    def __mul__(self,other): #(a+bi)(c+di) = ac+adi+bci+bidi = (ac-bd)+(ad+bc)i
        mr = (self.r*other.r) - (self.i*other.i)
        mi = (self.r*other.i) + (self.i*other.r)
        return ComplexNumber(mr, mi)

class Quaternion(ShowLogger):
    def __init__(self,r,i,j,k):
        self.r = r
        self.i = i
        self.j = j
        self.k = k

    def show(self):
        print str(self.r) + self.__showOperation__(self.i,"i") + self.__showOperation__(self.j,"j") + self.__showOperation__(self.k,"k")

    def __add__(a,b):
        mr = a.r + b.r
        mi = a.i + b.i
        mj = a.j + b.j
        mk = a.k + b.k
        return Quaternion(mr,mi,mj,mk)

    def __sub__(a,b):
        mr = a.r - b.r
        mi = a.i - b.i
        mj = a.j - b.j
        mk = a.k - b.k
        return Quaternion(mr,mi,mj,mk)

    def __div__(a,b):
        # TODO
        pass

    def __mul__(a,b):
        #a1a2-b1b2-c1c2-d1d2
        mr = (a.r*b.r) - (a.i*b.i) - (a.j*b.j) - (a.k*b.k)
        #a1b2+b1a2+c1d2-d1c2
        mi = (a.r*b.i) + (a.i*b.r) + (a.j*b.k) - (a.k*b.j)
        #a1c2-b1d2+c1a2+d1b2
        mj = (a.r*b.j) - (a.i*b.k) + (a.j*b.r) + (a.k*b.i)
        #a1d2+b1c2-c1b2+d1a2
        mk = (a.r*b.k) + (a.i*b.j) - (a.j*b.i) + (a.k*b.r)
        return Quaternion(mr,mi,mj,mk)

if __name__ == "__main__":
    print "====== start test ComplexNumber ======"
    a = ComplexNumber(2,-1)
    b = ComplexNumber(0,1)
    c = ComplexNumber(1,1)
    print "@ c = "
    c.show()
    print "@ a+b="
    (a+b).show()
    print "@ b*c="
    (b*c).show()
    print "@ a*b*c="
    (a*b*c).show()
    print "@ a/b="
    (a/b).show() # the divide still support
    print "====== start test Quaternion ======"
    z = Quaternion(2,-1,3,2)
    w = Quaternion(0,1,1,1)
    x = Quaternion(1,1,1,1)
    print "@ x = "
    x.show()
    print "@ z+w = "
    (z+w).show()
    print "@ w*x = "
    (w*x).show()
    print "@ z*x*w = "
    (z*x*w).show()