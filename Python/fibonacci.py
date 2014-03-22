def fibonacci_recursive(n):
    if n == 0 or n == 1:
        return n
    else:
        return fibonacci_recursive(n-1)+fibonacci_recursive(n-2)

def fibonacci_dp1(n):
    computed_value = {0:0,1:1}
    for i in range(2,n+1):
        if i not in computed_value:
            computed_value[i] = computed_value[i-1] + computed_value[i-2]
    return computed_value[n]

RESULT_TBL = {0:0,1:1}
def fibonacci_dp2(n):
    if n == 0 or n == 1:
        return n
    else:
        if n in RESULT_TBL:
            return RESULT_TBL[n]
        else:
            RESULT_TBL[n] = fibonacci_dp2(n-1)+fibonacci_dp2(n-2)
            return RESULT_TBL[n]

if __name__ == '__main__':
    #print str(fibonacci_recursive(10))
    print str(fibonacci_dp1(100))
    print str(fibonacci_dp2(100))