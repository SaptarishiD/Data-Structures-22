#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
	int val;
	struct node * next;	
};

typedef struct node * nodeAddress;


void swap(int *x, int *y);

int * generateArray(int n);
nodeAddress linkedListFromArray(int * a, int n);
void freeLinkedList(nodeAddress head);

void printArray(int * a, int n);
void printLinkedList(nodeAddress head);
int findIndexOfMax(int *a, int n);
void selectionSort(int *a, int n);

void selsortLL(nodeAddress head);
void dataswap(nodeAddress min, nodeAddress temp);
nodeAddress findMinValNode(nodeAddress forward, nodeAddress min);







int main(int argc, char **argv) 
{
	int * a;
	int n;
    printf("Size of array: ");
    scanf("%d", &n);
	//int maxindex;
	//int p, q;
	nodeAddress list;

	srand(time(NULL));

	a = generateArray(n);
	list = linkedListFromArray(a,n);

	printArray(a,n);
	selectionSort(a,n);
    printf("Sorted ");
	printArray(a,n);

    printLinkedList(list);    
    selsortLL(list);
    printf("Sorted ");
    printLinkedList(list);


	free(a);
	freeLinkedList(list);

	return 0;
}




void swap(int *x, int *y) 
{
	int t;
	t = *x;
	*x = *y;
	*y = t;
}


int * generateArray(int n) 
{
	int * t = malloc( n * sizeof(int) );
	if(t) 
    {
		for(int i=0; i<n; i++) 
        {
            t[i] = rand()%1000;
        }
	}
	return t;
}

nodeAddress linkedListFromArray(int * a, int n) 
{
	int i;
	nodeAddress head = NULL;
	nodeAddress temp = NULL;

	// special case for head
	if(n>0) 
    {
		head = malloc( sizeof(struct node) );
		head->val  = a[0];
		head->next = NULL;
		temp = head;
	}


	for(i=1; i<n; i++) 
    {
		temp->next = malloc( sizeof(struct node) );
		temp = temp->next;
		temp->val = a[i];
		temp->next = NULL;
	}

	return head;
}

void freeLinkedList(nodeAddress head) 
{
	nodeAddress prev;
	while(head) 
    {
		prev = head;
		head = head->next;
		free(prev);
	}
}



void printArray(int *a, int n) 
{
    printf("Array = ");
	for(int i=0; i<n; i++) 
    {
		if (i == 0)
        {
            printf(" %d", a[i]);
	    }
        else
        {
            printf(", %d ", a[i]);
        }
    }
    printf("\n");
    printf("\n");
}

void printLinkedList(nodeAddress head) 
{
	nodeAddress c;
	printf("Linked List = ");
	for(c=head; c!=NULL; c=c->next) 
    {
		printf( c==head?"%d":", %d", c->val);
	}
	printf("\n");
    printf("\n");
}


int findIndexOfMax(int *a, int n) 
{
	int imax; // this will contain the address of the largest element encountered.
	int i;

	// error case if there are no elements in the list
	if(n<1) {return -1;}

	imax = 0; // I am assuming that a[0] is the max element
	for(i=1; i<n; i++) 
    {
		if( a[i] > a[imax] ) 
        {
			imax = i;
		}
	}

	return imax;
}

void selectionSort(int *a, int n) 
{
	int i, imax, t;

	for(i=n; i>1; i=i-1) 
    {
		imax = findIndexOfMax(a, i);
		t = a[imax]; 
        a[imax] = a[i-1];
        a[i-1] = t;
	}
}




void dataswap(nodeAddress min, nodeAddress temp)
{
    int tempint = min->val;
    min->val = temp->val;
    temp->val = tempint;
    temp = temp->next;
}



nodeAddress findMinValNode(nodeAddress forward, nodeAddress min)
{
    while(forward)                      // finds the minimum element
        {
            if (forward->val < min->val)
            {
                min = forward;
            }
            forward = forward->next;
        }
    return min;
}



void selsortLL(nodeAddress head)
{
    //do the max version
    
    nodeAddress temp = head;


    while (temp)
    {
        nodeAddress min = temp;
        nodeAddress forward = temp->next;

        min = findMinValNode(forward, min);

        // 5->4->2->3->1
        // at end of while loop min points to 1 so the min element is found
        
        //==========================================
        //this is data swapping one

        int tempint = min->val;
        min->val = temp->val;
        temp->val = tempint;

        temp = temp->next;

    }
}
