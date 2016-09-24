/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/
int FindMergeNode(Node *headA, Node *headB)
{
    // Complete this function
    // Do not write the main method. 
    if(headA == NULL || headB == NULL) {
        return 0;
    }
    
    Node *list1 = headA, *list2 = headB;
    int length1 = 0, length2 = 0, diff = 0;
    
    while(list1 != NULL) {
        length1++;
        list1 = list1->next;
    }
    
    while(list2 != NULL) {
        length2++;
        list2 = list2->next;
    }
    
    if(length1 > length2) {
        diff = length1 - length2;
        
        while(diff != 0) {
            headA = headA->next;
            diff--;
        }
    } else if(length2 > length1) {
        diff = length2 - length1;
        
        while(diff != 0) {
            headB = headB->next;
            diff--;
        }
    }
    
    while(headA != NULL && headB != NULL) {
        if(headA == headB) {
            return headA->data;
        }
        
        headA = headA->next;
        headB = headB->next;
    }
    
    return 0;
}

