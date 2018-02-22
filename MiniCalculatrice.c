#include <miniCalculatrice.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

 static int haut = -1;

 static float pile[PILE_MAX];


 void push(int v) {
 pile[++haut] = v;
 }

 float pop(void) {
 return pile[haut--];
 }

 int vide(void) {
 return haut < 0;
 }

void infixe2postfixe(char * s, char * d) {
    while(*s) {
        if(*s >= '0' && *s <= '9') {
            do {
                *d++ = *s++;
            }
            while( *s >= '0' && *s <= '9');
            *d++ = ' ';
            if(!*s) break;
        }
        if((*s == ')' && !vide())) { *d++ = (char)pop(); *d++ = ' '; }
        else if(*s == '+') push((int) *s);
        else if(*s == '*') push((int) *s);
        else if(*s == '/') push((int) *s);
        else if(*s == '-') push((int) *s);
        s++;
    }
    while(!vide()) {*d++ = (char)pop(); *d++ = ' '; }
        *d = '\0';
}



float miniCalculatrice(char *s){

    haut=-1;

    while(*s) {
    if (atof(s))push(atof(s));
    if(*s == '0') push(atof(s));
    if(*s == '*') {pile[haut-1]=((pile[haut]*pile[haut-1])); haut--;}
    if(*s == '+') {pile[haut-1]=((pile[haut]+pile[haut-1])); haut--;}
    if(*s == '/') { if(pile[haut] == 0){printf("Erreur ! Division par 0! \n"); return 0;}pile[haut-1]=((float)(pile[haut-1]/pile[haut])); haut--;}
    if(*s == '-') {pile[haut-1]=((pile[haut-1]-pile[haut])); haut--;}
     while(*s != ' '){
    s++;
    }
    s++;
    }
    return pop();

}

ratio fraction(float nb){
    ratio res;
    int tab[100],i=1,n,x,y,z;
    tab[0] = (int)nb;

    while((nb - (int)nb)> 0.01 && i < 10){

    nb = 1/((nb - (int)nb));
    tab[i]= (int) nb;
    i++;


    }
    n = i -1;
    x=1;
    y=tab[n];

    for(i=n;i>= 1;i--){
        z = y;
        y=tab[i-1] * y+x;
        x = z;
    }
    res.num = y;
    res.deno = x;

    return res;
}

