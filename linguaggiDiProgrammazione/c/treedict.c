//librerie standard di C
#include <stdio.h>
#include <stdlib.h>

//libreria di Visual Studio per Win32 - rimuovi se non sei su Visual Studio
#include "stdafx.h"

//header file per tredict
#include "treedict.h"


//struttura dell'albero
struct treedict {
  
  char * id; //id dell'albero
  node_ref root; //radice
  
  };

//struttura del nodo
struct node {
  
  node_ref root; //radice
  int key; //chiave
  void * val; //valore
  node_ref left; //nodo a sinistra
  node_ref right; //nodo a destra
  
  };

//definisco alcune delle funzioni dei nodi sopra in modo che possano essere usate dai metodi sottostanti
//crea un nuovo nodo
node_ref node_new(int key, void* val, node_ref left, node_ref right){
  
  //riferimento a un nuovo nodo
  node_ref new_nd = (node_ref) malloc(sizeof(struct node));
  
  //se il riferimento al nodo appena creato è null, allora non posso allocare memoria
  if (new_nd == NULL){
	fprintf(stderr, "treedict: node_new: cannot allocate memory.\n");
	exit(-2);
	}
  
  //"istanzio" le proprietà di struct node
  new_nd -> key = key;
  new_nd -> val = val;
  new_nd -> left = left;
  new_nd -> right = right;
  return new_nd;
  
  }


//funzione per inserire un nodo
node_ref node_insert(node_ref n, int k, void * v){
  
  //se il nodo di riferimento è nullo, vuol dire che devo fare un nuovo albero praticamente
  if (n == NULL) {
	return node_new(k, v, NULL, NULL);
	}
  
  //se la key data è maggiore del nodo a cui si punta, allora si inserisce il nodo nel sottoalbero destro
  //altrimenti se la key data è minore del nodo a cui si punta, allora si inserisce il nodo nel sottoalbero sinistro
  //altrimenti ritorno un nuovo nodo che è identico a quello dato come riferimento
  if (n->key < k)
	return node_new(n->key, n->val, n->left, node_insert(n->right, k, v));
	 else if (n -> key > k)
	   return node_new(n->key, n->val, node_insert(n->left, k, v), n->right);
	 else if (n -> key == k)
	   return node_new(n->key, n->val, n->left, n->right);
	 
	 //return "di sicurezza" perchè non dovrebbe mai arrivare qua
	 return NULL;
	 
  }

//Crea un nuovo albero
treedict_ref treedict_new(char * name){
  
  //Alloca un nuovo spazio di memoria per un treedict
  treedict_ref new_td = (treedict_ref) malloc(sizeof(struct treedict));
  
  //Se non può creare lo spazio di memoria:
  if (new_td == NULL) {
	fprintf(stderr, "treedict: treedict_new: cannot allocate memory.\n");
	exit(-1);
	}
  
  //"istanzia" i valori all'interno della struct
  new_td -> id = name;
  new_td -> root = NULL;
  
  return new_td;
  
  }


//inserisce un nodo all'interno di un albero con un dato key e valoree
treedict_ref treedict_insert(treedict_ref td, int key, void* val){
  
  //crea un nuovo albero "di appoggio"
  treedict_ref new_td = treedict_new(td -> id);
  
  //aggiungo all'inizio come root un nodo con node_insert
  //per verificare key etc., guarda "node_insert"
  new_td -> root = node_insert(td -> root, key, val);
  
  return new_td;
  }


//cerca, data una chiave, un nodo all'interno dell'albero
void* treedict_search(treedict_ref td, int key){
  
  //riferimento al nodo da cercare - inizio dalla radice
  node_ref n_found = node_search(td->root, key);
  
  //se quello che ho trovato non è null e ha la stessa chiave, allora è quello che ho trovato
  if (n_found != NULL)
	return n_found->val;
  else
	return NULL;
  }

//stampa l'albero partendo dalla radice
void* treedict_print(treedict_ref td) {
  
  if (td == NULL) return NULL;
  
  fprintf(stdout, "Dict (Tree) %s.\n", td -> id);
  node_print(td->root, 0);
  return td -> id;
  }

//distruggere un albero
treedict_ref treedict_delete(treedict_ref td, int key){
  
  //creazione di un nuovo albero appoggio
  treedict_ref new_td = treedict_new(td -> id);

  //se l'albero è vuoto, non c'è nulla da eliminare
  if (td == NULL || td->root == NULL){
	fprintf(stderr, "treedict: treedict_delete: tree is empty or null.\n");
	return td;
	}
  
  //elimino il nodo con la chiave specificata
  new_td->root = node_delete(td->root, key);
  
  return new_td;
  }

//node functions


//metodo per cercare un nodo dato un root e una chiave
node_ref node_search(node_ref n, int key){
  
  //se la reference è null, allora ritorniamo null
  if (n == NULL) return NULL;
  
  //se la root ha la stessa key di quello che stiamo cercando: root è il nodo che stiamo cercando
  if (n -> key == key) {
	return n;
	//altrimenti se la key data è minore rispetto alla key della root, allora dobbiamo vedere il sottoalbero sinistro
	} else if (key < n -> key) {
	return node_search(n -> left, key);
	//altrimenti se la key data è maggiore rispetto alla key della root, allora dobbiamo vedere il sottoalbero destro
	  } else if (key > n ->key){
	  return node_search(n -> right, key);
		}
	  
	  //return "di sicurezza)
	  return NULL;
  }

//stampa un nodo
void node_print(node_ref n, int level){
  if (n != NULL){
	printf("%*c", level, ' ');
	printf(" %d ==> '%s'\n", n->key, n->val);
	node_print(n->left, level+4);
	node_print(n->right, level+4);
	}
  }

//cancello un nodo
node_ref node_delete(node_ref n, int key) {

  //definisco che dovrò trovare il successore
	  node_ref successor = NULL;

  if (n == NULL) { return NULL; } //se il nodo è null, non c'è nulla da eliminare
  else if (key < n->key){
	//se la chiave da cercare è più piccola, allora è nel sottoalbero sinistro
	n->left = node_delete(n->left, key);
	} else if (key > n->key){
	//se la chiave da cercare è più grande, allora è nel sottoalbero destro
	n->right = node_delete(n->right, key);
	  } else {
	  //sostituisco il nodo con il successore più piccolo nel sottoalbero destro/sinistro
	  if (n->right == NULL) return n->left;
	  else if (n->left == NULL) return n-> right;
	  
	  //quando si elimina un nodo con due sottoalberi non vuoti, occorre trovare un successore
	  successor = node_find_successor(n->right);
	  	  n->key = successor->key;
	  n->val = successor->val;
	  n->right = node_delete(n->right, successor->key);
		}
	  return n;
  }

node_ref node_find_successor(node_ref n){
/*funzione ausiliaria per trovare il successore più piccolo di un nodo
se nodo ha sia parte destra che sinistra
  garantisce di mantenere l'ordine*/
  while (n->left != NULL) {
	n = n->left;
	}
  return n;
  }