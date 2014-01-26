def quiz3Nplus1(n, sum)
    if n <= 1
        return sum
    elsif n % 2 == 1
        return quiz3Nplus1(n*3+1, sum + 1)
    else
        return quiz3Nplus1(n/2, sum + 1)
    end
end

mMax = 0
(1..10).each do |q|
    tmp = quiz3Nplus1(q,1)
    if tmp > mMax
        mMax = tmp
    end
end
puts "max len : #{mMax}"