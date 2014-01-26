class Skipper
    def initialize(num)
        @skip_num = num
    end

    def next(num)
        count = num + 1
        while @skip_num.to_s().include?(count.to_s()) or (count % @skip_num) == 0 do
            count += 1
        end
        count
    end
end

# main script
puts "=== test 3 game ==="
s3 = Skipper.new(3)
for i in 1..50
    puts "num : " + i.to_s() + " > "+ s3.next(i).to_s()
end

puts "=== test 4 game === "
s4 = Skipper.new(4)
for i in 1..50
    puts "num : " + i.to_s() + " > "+ s4.next(i).to_s()
end