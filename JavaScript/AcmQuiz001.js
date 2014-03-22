function quiz3Nplus1(n, sum) {
    if (n <= 1) {
        return sum;
    } else if (n%2 == 1) {
        return quiz3Nplus1(n*3+1, ++sum);
    } else {
        return quiz3Nplus1(n/2, ++sum);
    }
}

function main() {
    var max = 0;
    for (var i = 1 ; i < 10 ; i++) {
        var tmp = quiz3Nplus1(i, 1);
        if (tmp > max) {
            max = tmp;
        }
    }
    console.log("max len : " + max);
}

main();
