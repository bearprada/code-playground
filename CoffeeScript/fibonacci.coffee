fibonacci_recursive = (n) ->
    return if (n == 0 || n == 1) then n else fibonacci_recursive(n-1) + fibonacci_recursive(n-2)

fibonacci_dp1 = (n) ->
    computed_value = {0:0, 1:1}
    if (n > 1)
        computed_value[i] = computed_value[i-1] + computed_value[i-2] for i in [2..n+1]
    return computed_value[n];

result_tbl = {0:0, 1:1}
fibonacci_dp2 = (n) ->
    if (n > 1 and !(n in result_tbl))
        result_tbl[n] = fibonacci_dp2(n-1) + fibonacci_dp2(n-2)
    return result_tbl[n]

main = () ->
    console.log fibonacci_recursive(10)
    console.log fibonacci_dp1(100)
    console.log fibonacci_dp2(100)

main()