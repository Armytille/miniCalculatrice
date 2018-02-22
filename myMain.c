#include <miniCalculatrice.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

int main(void) {

    float i;
    ratio res;
    char * source, destination[MAX<<1];
    //source = "(((1+2)*3)+4*(((5+6)/7)+8))";
    do {
    if(!fgets(source, MAX, stdin)) break;
    infixe2postfixe(source, destination);
    i=miniCalculatrice(destination);
    res= fraction(i);
    printf("%s\n", destination);
    printf("%d / %d = %.3f",res.num,res.deno,i);
    } while(1);

    return 0;


}

