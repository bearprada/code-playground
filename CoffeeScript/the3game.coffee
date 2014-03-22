class Skipper
    constructor: (@skip_num) ->

    next: (num) -> find_next(num)

    find_next : (num) ->
        count = num + 1
        count++ while !(count % @skip_num) and (count.toString().indexOf @skip_num.toString() != -1)
        return count

main = () ->
    console.log "=== test 3 game === "
    s3 = new Skipper 3
    console.log "num : " + i + " > "+ s3.next(i) for i in [1..50]
    console.log "=== test 4 game === "
    s4 = new Skipper 4
    console.log "num : " + i + " > "+ s4.next(i) for i in [1..50]
