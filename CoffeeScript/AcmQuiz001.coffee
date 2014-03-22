quiz3Nplus1 = (n, sum) ->
    return if n <= 1 then sum else if n%2 == 1 then quiz3Nplus1(n*3+1, ++sum) else quiz3Nplus1(n/2, ++sum)

main = () ->
    console.log "max len : " + Math.max (quiz3Nplus1(i, 1) for i in [1..10])

main()
