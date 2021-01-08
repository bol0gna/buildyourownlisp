/* linked list and list node classes */

typedef struct node* Node;
struct node {
	void* info;
	Node next;
};

extern Node new_Node(void* val);
extern void Node_printList(Node this);

typedef struct linkedlist* LinkedList;
struct linkedlist {
	Node head;
	Node tail;
	int length;
};

extern LinkedList new_LinkedList();
extern void LinkedList_prepend(LinkedList this, void* val);
extern void LinkedList_append(LinkedList this, void* val);

extern int LinkedList_length(LinkedList this);
extern void* LinkedList_first(LinkedList this);
extern void* LinkedList_last(LinkedList this);
extern void LinkedList_print(LinkedList this);
