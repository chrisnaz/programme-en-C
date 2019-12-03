#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "listChaine.h"

/************************************************************************************/
liste addElemAtBegining (liste list, char word[], char def[]){
  element * newElement = (element *) malloc (sizeof (element));
  strcpy (newElement -> mot, word);
  strcpy (newElement -> definition, def);
  newElement -> next = list;
  return newElement;
}
/************************************************************************************/

liste addElemAtEnd (liste list, char word[], char def[]){
  element * newElement = (element *) malloc (sizeof (element));
  strcpy (newElement -> mot, word);
  strcpy (newElement -> definition, def);
  newElement -> next = NULL;

  if (list == NULL)
    return newElement; 
  else {
    element * temp = list;
    while (temp -> next != NULL)
      temp = temp -> next;
    temp -> next = newElement;
    return list;
  }
}
/***********************************************************************************/

liste addElemWithIndex (liste list, char word[], char def[], int pos){
  element * newElement = (element *) malloc (sizeof (element));
  strcpy (newElement -> mot, word);
  strcpy (newElement -> definition, def);

  if (list != NULL){
    newElement -> next = list -> next;
    list -> next = newElement;
  }
  else{
    newElement -> next = list;
  }
  return newElement;
}
/***********************************************************************************/

liste deleteHead (liste list){
  if (list != NULL){
    element * aDelete = list -> next;
    free (list);
    return aDelete;
  }
  else{
    return NULL;
  }
}
/**********************************************************************************/

liste deleteTail (liste list){
  if (list == NULL)
    return NULL;
	
  //List has one element
  if (list -> next == NULL){
    free (list);
    return NULL;
  }
	
  //List had at least two element
  element * tmp = list;
  element * ptmp = list;
	
  while (tmp -> next != NULL){
    ptmp = tmp;
    tmp = tmp -> next;
  }
	
  ptmp -> next = NULL;
  free (tmp);
  return list;	
}
/*********************************************************************************/

liste searhElement (liste list, char word []){
  element * tmp = list;

  while (tmp != NULL){
    if (strcmp (tmp -> mot, word) == 0)
      printf ("'%s' existe bien dans le dictionnaire", tmp -> mot);
      printf ("\n");
    
    tmp = tmp -> next;
  }
  return NULL;
  //string.h
}
/*********************************************************************************/

void showList (liste list){
  element * tmp = list;

  while (tmp != NULL){
    printf ("%s : ", tmp -> mot);
    printf ("%s", tmp -> definition);
    tmp = tmp -> next;
    printf("\n");
  }
}
/*********************************************************************************/

int nbrElement (liste list){
  int n = 0;
  element * tmp = list;

  while (tmp != NULL){
    n ++;
    tmp = tmp -> next;
  }
  return n;
}
