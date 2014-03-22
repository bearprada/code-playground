Function::property = (prop, desc) ->
    Object.defineProperty @prototype, prop, desc

class Node
    constructor : (@value, @next = null) ->

    # TODO replace the setter/getter pattern
    set_next : (node) ->
        @next = node

    set_value : (value) ->
        @value = value

class LinkedList
    constructor : () ->
        @root = null

    insert : (num) ->
        node = Node(num)
        if @root == null
            @root = node
        else
            q = @root
            q = q.next while q.next != null
            q.set_next node

    print : () ->
        q = @root
        while q != null
            console.log " > " + q.value
            q = q.next

    shuffle : () ->
        q = @root
        q = q.next while (q.next != null)
        q.next @root

    # bad impl.
    isCycled : () ->
        tmp = []
        q = @root
        while q != null
            if (q in tmp)
                return true
            else
                tmp.push(q)
                q = q.next
        return false

    set_node_value : (from, target) ->
        q = @root
        while q != null
            if q.value == from
                q.set_value(target)
            q = q.next

    __isExsist__ : (node) ->
        q = @root
        while q != null
            if q == node
                return false
            else if q == node.next
                return true
            q = q.next

    isCycled2 : () -> # without temp memory to store the data we scan
        q = @root
        while q != null
            if __isExsist__(q)
                return true
            q = q.next
        return false

    isCycled3 : () ->
        p = @root
        q = @root
        for i in [0..50] #FIXME the number should be meansful
            # p move 2 times
            if p.next == null or p.next.next == null
                return false
            # q move 1 times
            if q.next == null
                return false
            q = q.next
            p = p.next.next
            if q == p
                return true
        return false

    reverse : () ->
        return if isCycled() #raise Exception('reason', 'it is a cycly linked list')

        p = @root
        newRoot = null
        q = newRoot
        while( p != null)
            q = p
            p = p.next
            q.set_next(newRoot)
            newRoot = q
        @root = newRoot

main = () ->
    linkedList = new LinkedList()
    linkedList.insert(i) for i in [0..100]
    linkedList.print()

    linkedList.reverse()
    console.log " --- print reverse list --- "
    linkedList.print()
    linkedList.reverse()
    console.log " --- print double reverse list --- "
    linkedList.print()

    console.log linkedList.isCycled()
    console.log linkedList.isCycled2()
    console.log linkedList.isCycled3()
    linkedList.shuffle()
    console.log linkedList.isCycled()
    console.log linkedList.isCycled2()
    console.log linkedList.isCycled3()

    #try:
    #    linkedList.reverse()
    #except Exception as inst:
    #    print '[EXCEPTION] ', str(inst)

main()
