function fibonacci_recursive(n) {
    return (n == 0 || n == 1) ? n : fibonacci_recursive(n-1) + fibonacci_recursive(n-2);
}

function fibonacci_dp1(n) {
    var computed_value = {0:0, 1:1};
    for (var i = 2 ; i < n+1 ; i++) {
        if (!(i in computed_value)) {
            computed_value[i] = computed_value[i-1] + computed_value[i-2];
        }
    }
    return computed_value[n];
}

var RESULT_TBL = {0:0, 1:1};
function fibonacci_dp2(n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        if (n in RESULT_TBL) {
            return RESULT_TBL[n];
        } else {
            RESULT_TBL[n] = fibonacci_dp2(n-1) + fibonacci_dp2(n-2)
            return RESULT_TBL[n];
        }
    }
}

function main() {
    console.log(fibonacci_recursive(10));
    console.log(fibonacci_dp1(100));
    console.log(fibonacci_dp2(100));
}
main();