 /*!\file pile.h
* \brief Biblioth`eque de gestion de (une) pile de taille fixe
* \author Far`es Belhadj amsi@ai.univ-paris8.fr
* \date October 02, 2013
*/
#ifndef _PILE_H
#define _PILE_H
/*!\brief taille de la pile (statique) */
#define PILE_MAX 256

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ratio ratio;

struct ratio{
int num;
int deno;
};


extern void push(int v);
extern float pop(void);
extern int vide(void);
extern void infixe2postfixe(char*,char*);
extern float miniCalculatrice(char *);
extern ratio fraction(float);
#ifdef __cplusplus
}
#endif

#endif
