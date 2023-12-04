#include <stdio.h>
#include <stdlib.h>
#include "treedict.h" //includi l'header
//#include "treedict.c" --> se non lo prende direttamente (es. se i file non sono nello stesso progetto)

int main() {
  
  // Creo un nuovo albero con l'id "MyTree"
  treedict_ref myTree = treedict_new("MyTree");
  
  // Valori che servono: chiave da trovare, valore trovato (void* per poi essere usato come stringa praticamente)
  /*
  - keyToFind: chiave da trovare
  - keyToDelete: chiave da eliminare
  - foundValue: valore del nodo trovato attraverso keyToFind
  - length: quanti nodi si vogliono all'interno dell'albero
  - forInt: intero iterativo per il ciclo for
  - keyToInsert: chiave da inserire all'interno del nodo - puntatore per poi ridimensionarlo
  - valueToInsert: valore da inserire all'interno del nodo con chiave keyToInsert - puntatore per poi ridimensionarlo
  - buffer: buffer di caratteri per prendere in input stringhe di valori per value
  */

  int keyToFind; int keyToDelete; int length; int forInt; int* keyToInsert;
  void* foundValue;void** valueToInsert; char buffer[100];

  //inserimento a runtime di nodi nell'albero
  printf("========== Write here how many nodes you want to enter: ========== \n");
 length = read_int_from_stream(stdin);

 keyToInsert = malloc(length * sizeof(int)); //Allocazione dinamica memoria per keyToInsert
 valueToInsert = malloc(length * sizeof(void*)); // Allocazione dinamica memoria per valueToInsert

 if (valueToInsert == NULL || keyToInsert == NULL) {
    printf("treedict: main: allocazione di memoria fallita.\n");
    return -1;
}

 //ciclo for per node key
  for (forInt = 0; forInt < length; forInt++){
	printf(">>> Node key: ");
	scanf("%d", &keyToInsert[forInt]);
	 while(getchar() != '\n'); // Pulisce il buffer di input
	}

  printf("\n"); //aggiungo un'altra linea per chiarezza

//ciclo for per node value
for (forInt = 0; forInt < length; forInt++){
    printf(">>> Node value: ");
    scanf("%s", buffer);
    valueToInsert[forInt] = (void*)strdup(buffer); // Duplica la stringa e assegna il puntatore a void
}

for (forInt = 0; forInt < length; forInt++){
  myTree = treedict_insert(myTree, keyToInsert[forInt], valueToInsert[forInt]);
  }
  
  //Scrittura in terminale per utente
  printf("\n ========== Chiave da trovare: ========== \n");
  
  //read_int_from_stream, legge un intero dallo stream stdin
  keyToFind = read_int_from_stream(stdin);
  
  //cerco la key appena decisa all'interno del treedict
  foundValue = treedict_search(myTree, keyToFind);
  
  //se quello che ho trovato non � null, allora vuol dire che l'ho trovato
  if (foundValue != NULL) {
	printf(">>> Trovato un valore per la chiave %d: %s\n", keyToFind, (char*)foundValue);
    } else {
	//altrimenti vuol dire che non l'ho trovato
	printf(">>> Chiave %d non trovata.\n", keyToFind);
	  }
	
    // Stampo l'albero
    treedict_print(myTree);
	
	/*
	RISULTATO esempio:
	
	   5
	  / \
	  3  7
	 /\  /\
    1 4  6 8
	*/
	
	
	//eliminazione di un nodo
	printf("\n ========== Chiave da cancellare: ========== \n");

	//leggi la chiave da tastiera
	keyToDelete = read_int_from_stream(stdin);

	//elimina il nodo con quella chiave dall'albero
	myTree = treedict_delete(myTree, keyToDelete);

	printf("\n >>> Albero dopo la cancellazione del nodo con chiave %d:\n", keyToDelete);
	treedict_print(myTree);
	
    // Libero la memoria allocata per l'albero
	free(myTree); 

	//libero ogni void* all'interno dell'array
	for (forInt = 0; forInt < length; forInt++){
    free(valueToInsert[forInt]);
}
  free(valueToInsert);free(keyToInsert);
	
    return 0;
  }

int read_int_from_stream(FILE* in) {
  int x = 0;
  fscanf(in, "%d", &x);
  return x;
  }


