/* -*- Mode: C -*-

  /* treedict.h
  * interface for Treedict library.
*/

#ifndef _TREEDICT_H
#define _TREEDICT_H 
//se ho già definito treedict, non ridefinirlo un'altra volta

struct node; //struttura nodo
struct treedict; //struttura treedict

typedef struct node * node_ref; //riferimento a nodo
typedef struct treedict * treedict_ref; //crea un nuovo tipo di dato definito da utente chiamato treedict_ref = puntatore a struttura dati

//interfacce di treedict
extern treedict_ref treedict_new(char * id);
extern treedict_ref treedict_insert(treedict_ref, int, void *);
extern void * treedict_search(treedict_ref, int);
extern void * treedict_print(treedict_ref);
extern treedict_ref treedict_delete(treedict_ref, int);

//interfacce di nodo
extern node_ref node_insert(node_ref, int, void*);
extern node_ref node_search(node_ref, int);
extern void node_print(node_ref, int);
extern node_ref node_new(int, void*, node_ref, node_ref);
extern node_ref node_delete(node_ref, int);
extern node_ref node_find_successor(node_ref);

//interfaccia pubblica dei metodi

//interfacce di metodi di test
extern void* read_string_from_stream(FILE*);
extern int read_int_from_stream(FILE*);

#endif

/* end of file - treedict.h */ 