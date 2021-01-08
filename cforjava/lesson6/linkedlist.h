/* linked list and list node classes */

typedef struct node* Node;
extern Node new_Node(Employee val);
extern void Node_printList(Node this);

typedef struct linkedlist* LinkedList;
extern LinkedList new_LinkedList();
extern void LinkedList_prepend(LinkedList this, Employee val);
extern void LinkedList_append(LinkedList this, Employee val);
extern int LinkedList_length(LinkedList this);
extern Employee LinkedList_first(LinkedList this);
extern Employee LinkedList_last(LinkedList this);
extern void LinkedList_print(LinkedList this);
