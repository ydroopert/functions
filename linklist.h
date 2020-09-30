/*linked list.h*/
typedef struct node
{
	/*mod */
	int data;
	struct node *next;
}
NODE;

NODE *createlist(int *, int);
void printlist(NODE *);
void freelist(NODE *);
void insertnode(NODE *, int);
NODE *searchnode(NODE *, int);
NODE *deletenode (NODE *, NODE *);

NODE *createlist(int *arr, int len) 		/*mod + prototype*/ 
{
	int i;
	NODE *first,*current,*prev;
	for(i=0;i<len;i++)
	{
		current=(NODE *)malloc(sizeof(NODE));
		current->data=arr[i];			/*add data */
		if(i==0)
			first=current;
		else
			prev->next=current;
		current->next=NULL;
		prev=current;
	}
	return first;						/*returns ptr to node */
}

void printlist (NODE *first)
{
	NODE* node=first; 					/*set a new ptr to first node */
	if(first==NULL)
		printf("List empty\n");
	else
	{
		while(node!=NULL)
		{
			printf("%3d",node->data);	/*print out node data*/
			node=node->next;			/*set ptr to next node*/
		}
		printf("\n");
	}
}

void freelist(NODE* first)
{
	NODE *current,*tmp;
	current=first;						/*set current ptr to first */
	while (current!=NULL)
	{
		tmp=current;					/*set tem node */
		current=current->next;			/*move current ptr to next */
		free(tmp);						/*free node */
	}
}

NODE *searchnode(NODE* first, int item)	/* returns address of nodes matching item */
{
	NODE *node=first;
	while(node!=NULL)
	{
		if(node->data==item)			/*if node data match item */
			return node;				/*return node or mod here */
		else
			node=node->next;			/* if not search next */
	}
	return NULL;						/*if no match return NULL */
}

void insertnode (NODE *node, int item)
{
	NODE *newnode;						
	newnode=(NODE *) malloc(sizeof(NODE));
	newnode->data=item;					/*put item into new node data */
	newnode->next=node->next;			/*new node point to where node was pointing */
	node->next=newnode;					/*node point to new node */ 
}

NODE *deletenode(NODE *first, NODE *node)
{
	NODE *ptr=first;
	if(first==NULL)
	{
		printf("All good\n");
		return NULL;
	}
	if(node==first)						/* if deleting the first node */
		first=first->next;				/*point first to next node */
	else
	{
		while(ptr->next!=node)			/*loop to find prev of node */
			ptr=ptr->next;
		ptr->next=node->next;			/* set prev ptr to next of node */
	}
	free(node);
	return first;
}


