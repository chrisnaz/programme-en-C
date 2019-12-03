typedef struct element element;
struct element{
  char mot [20];
  char definition [2000];
  struct element * precedent;
  struct element * next;
};
typedef element * liste;

liste addElemAtBegining (liste , char [] , char []);
liste addElemAtEnd (liste, char [], char []);
liste addElemWithIndex (liste, char [], char [], int);
liste deleteHead (liste);
liste deleteTail (liste);
liste searhElement (liste, char []);
void showList (liste);
int nbrElement (liste);
