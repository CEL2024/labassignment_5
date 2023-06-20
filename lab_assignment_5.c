#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head) {
    int i = 0;

    while(head->next != NULL) {
        head = head->next;
        i++;
    }

    return i;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head) {
    int i = 0;
    char* c = (char *) malloc(sizeof(char*)*length(head));

    while(head != NULL) {
        c[i] = head->letter;
        head = head->next;
        i++;
    }

    return c;

}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c) {

    node *t = *pHead;
    node * tmp = (struct node*) malloc(sizeof(struct node*));
    tmp->letter = c;
    tmp->next = NULL;

    if(*pHead == NULL) {
        *pHead = tmp;
    }
    else {
        while(t->next != NULL) {
            t = t->next;
        }
        t->next = tmp;
    }
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead){
    free(pHead);
    *pHead = NULL;
}

int main(void)
{
	int i, strLen, numInputs;
	int num = 0;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);

		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

        str = toCString(head);
		printf("String is : %s\n", str);


		free(str);
		deleteList(&head);

        if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}

	}


	fclose(inFile);
}
