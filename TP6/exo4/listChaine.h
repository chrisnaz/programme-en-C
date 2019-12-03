typedef struct element element;
struct element {
	char mot [20];
	char definition [3000];
	struct element * next;
};
typedef element * liste;

liste addElement (liste, char [], char []);
liste searchElement (liste, char []);
liste deleteHead (liste);