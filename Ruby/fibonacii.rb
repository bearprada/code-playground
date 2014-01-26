def fibonacci_recursive(n)
    if n == 0 or n == 1
        return n
    else
        return fibonacci_recursive(n-1) + fibonacci_recursive(n-2)
    end
end

def fibonacci_dp1(n)
    computed_value = {0 => 0, 1 => 1}
    (2..(n+1)).each do |i|
        if !computed_value.include?(i)
            computed_value.store(i, computed_value[i-1] + computed_value[i-2])
        end
    end
    return computed_value[n]
end

global_result_tbl = {0 => 0, 1 => 1}
def fibonacci_dp2(n)
    if n == 0 or n == 1
        return n
    else
        if global_result_tbl.include?(n)
            return global_result_tbl[n]
        else
            global_result_tbl[n] = fibonacci_dp2(n-1)+fibonacci_dp2(n-2)
            return global_result_tbl[n]
        end
    end
end

puts "1. " + fibonacci_recursive(10).to_s()
puts "2. " + fibonacci_dp1(10).to_s()
puts "3. " + fibonacci_dp2(10).to_s()