def sort(arr)
    if arr.count == 1
        return arr
    else
        mid = arr.count/2
        return merge(sort(arr[0..(mid - 1)]), sort(arr[mid..arr.count]))
    end
end

def merge(al, ar)
    r = Array.new
    lidx = 0
    ridx = 0
    while (lidx < al.count and ridx < ar.count) do
        if al[lidx] < ar[ridx]
            r.push(al[lidx])
            lidx += 1
        else
            r.push(ar[ridx])
            ridx += 1
        end
    end
    if lidx < al.count
        r += al[lidx..al.count]
    end
    if ridx < ar.count
        r += ar[ridx..ar.count]
    end
    return r
end

result = sort([23,8,4,662,0,456,45,645,64,76,4345,2,33,8,5,454,5,45])
result.each do |i|
    puts i.to_s() + " "
end