## Linked List Concepts

### Insert node at specific location
```
/*
  Insert Node at a given position in a linked list 
  head can be NULL 
  First element in the linked list is at position 0
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* InsertNth(Node *head, int data, int position)
{
    Node *node = new Node;
    node->data = data;
    node->next = NULL;
    
    if(head == NULL) {
        head = node;
    } else {
        if(position == 0) {
            node->next = head;
            head = node;
        } else {
            Node *temp = head;
            while(position > 1) {
                head = head->next;
                position--;
            }
            
            node->next = head->next;
            head->next = node;
            
            head = temp;
        }
    }
    
    return head;
}
``` 

**Time Complexity** : O(n)  In worst case list has to be iterated till the end.

**Space Complexity** : O(1) Extra space is only used to create new node.
-----------------------------------------------------------------------

### Delete at Nth position
```
Node* Delete(Node *head, int position)
{
    Node *current;
    if(position == 0) {
        current = head->next;
        delete head;
        head = current;
    } else {
        Node *temp = head;
        while(position > 1) {
            head = head->next;
            position--;
        }
        
        current = head->next->next;
        delete head->next;
        head->next = current;
        
        head = temp;
    }
    
    return head;
}
```

**Time Complexity** : O(n)  In worst case list has to be iterated till the end.

**Space Complexity** : O(1) Extra space is only used to create new node.

### Reverse Print a LinkedList
Below code prints linked list By Iteration.

Time Complexity: O(n^2)

Space Complexity: O(1)
```
void ReversePrint(Node *head)
{
    if(head == NULL) {
        return;
    } else {
        int size = 0;
        Node* temp = head;
        
        while(head != NULL) {
            size++;
            head = head->next;
        }
        
        head = temp;
        
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < (size - i - 1); j++) {
                head = head->next;
            }
            cout << head->data << endl;
            head = temp;
        }
        
    }
}
```
**Reverse Printing list by Recursion**
```
void printReverse(Node* head) {
    Node* temp = head;

    if(head == NULL) {
        return;
    }

    printRevese(head->next);
    cout << head->data << " ";
}
```

**Reverse Printing list by Recursion with size**

```
void printReverse(Node* head, int size) {
    Node* temp = head;

    if(size == 1) {
        cout << head->data << endl;
        return;
    }

    for(int i = 0; i < (size - 1); i++) {
        head = head->next;
    }

    cout << head->data << " ";
    head = temp;
    printReverse(head, size-1);
}
```

### Reverse the Linked list by Iteration
**Time Complexity** : O(n)
**Space Complexity** : O(1)

```
Node* reverseList(Node* head) {
    Node *current, *prev, *next;
    current = head;
    prev = NULL;

    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    head = prev;

    return head;
}
```

### Reverse the Linked list by Recursion
```
Node* reverseList(Node* head) {
	if( head == NULL) return NULL; 		//If list is empty
	
	if(head->next == NULL) return head;		//when only one node present | Recursion exit strategy

	Node* rest = reverseList(head->next);	//Deviding list into first node and rest || returns new head
	head->next->next = head;				//Reversing two node list
	head->next = NULL;						//First node should be null in two node

	return rest;
}
```

Explained [Solution](http://stackoverflow.com/questions/14080758/reversing-a-linkedlist-recursively-in-c)
