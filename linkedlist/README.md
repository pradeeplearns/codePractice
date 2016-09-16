### Linked List Concepts

## Insert node at specific location
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
  // Complete this method only
  // Do not write main function. 
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
