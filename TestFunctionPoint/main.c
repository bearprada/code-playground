//
//  main.c
//  TestFunctionPoint
//
//  Created by RD Team on 6/10/13.
//  Copyright (c) 2013 Aplix. All rights reserved.
//
#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int jimmy(char op, int (*func)(int, int)) {
    if (op == '+') {
        return (*func)(1, 2);
    }
    return -1;
}

void sort(int * array, int length, bool (*cmp)(int a,int b)){
    
}

int main(void) {
    int (*func)(int, int) = add;
    printf("%d\n", jimmy('+', func));
    return 0;
}

