## Stack & Queue

### Stack
A stack is a container of objects that are inserted and removed according to the last-in first-out **(LIFO)** principle. In the pushdown stacks only two operations are allowed: **push** the item into the stack, and **pop** the item out of the stack. A stack is a limited access data structure - elements can be added and removed from the stack **only at the top**. **push** adds an item to the top of the stack, **pop** removes the item from the top. A helpful analogy is to think of a stack of books; you can remove only the top book, also you can add a new book on the top.

A stack is a **recursive** data structure. Here is a structural definition of a Stack:

a stack is either empty or
it consistes of a top and the rest which is a stack;

### Applications

The simplest application of a stack is to reverse a word. You push a given word to stack - letter by letter - and then pop letters from the stack.

Another application is an "undo" mechanism in text editors; this operation is accomplished by keeping all text changes in a stack.

### Backtracking
	This is a process when you need to access the most recent data element in a series of elements. Think of a labyrinth or maze - how do you find a way from an entrance to an exit?
Once you reach a dead end, you must backtrack. But backtrack to where? to the previous choice point. Therefore, at each choice point you store on a stack all possible choices. Then backtracking simply means popping a next choice from the stack.

### Language processing:
* space for parameters and local variables is created internally using a stack.
* compiler's syntax check for matching braces is implemented by using stack.
* support for recursion

```
public interface StackInterface<AnyType>
{
   public void push(AnyType e);

   public AnyType pop();

   public AnyType top();

   public boolean isEmpty();
}
```
[Good Source](https://www.cs.cmu.edu/~adamchik/15-121/lectures/Stacks%20and%20Queues/Stacks%20and%20Queues.html)

### Infix Postfix Prefix Notation
[Tutorial video](https://www.youtube.com/watch?v=jos1Flt21is&index=19&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P)

**Infix** <operand> <operator> <operand>   eg: a+b  or (a+b)*(c+d)

**Order of Operation**

1. Parantheses

2. Exponents	(right to left) (Exponents are also called Powers or Indices.)

3. Multiplication & division (If in between these two then go from left to right)

4. Addition & substraction (If in between these two then go from left to right)

	eg: 4 - 2 + 1  => apply form left to right so 4-2 then +1 = 3

4 + 2 * 3 = 4 + (2*3) = 10


2 * 6 / 2 - 3 + 7 = (2*6)/2 - 3 + 7 = 6 - 3 + 7 = 10

**Prefix or Polish** <operator> <operand> <operand>   eg: +ab  or *+ab+cd

**Prefix or Reverse Polish** <operand> <operand> <operator>  eg: ab+  or ab+cd+*

**Infix** is best for human readable but **Prefix & Postfix** are good for machines.

### Infix to Postfix
While we iterate through the Infix expression every Operand will be appended to the result Postfix expression and when we see an Operator we will push it on stack but before we push it on Stack we must check if stack already has some Operators in case if it has then we compare with the Stack top and see if the stack top Operator is bigger(preffered) than  the current one then we pop all the operators and append it to result and then push the current operator on the stack, we continue till we reach the end of Infix operation then we just pop any Operator left in stack and append it to result Postfix expression. Check the code in file InfixToPostfix.cpp.

**Expression with Paranthesis** If Infix expression also has paranthesis then in that case we will follow similar strategy with just one modification. We push every open paranthesis till we hit a close paranthesis in that case we will pop all the operators and append to result till we find an Open Paranthesis in the stack then we break the loop an pop that open paranthesis from stack. Repeat.

------------------------------------------------------------
### Queue
A queue is a container of objects (a linear collection) that are inserted and removed according to the first-in first-out (FIFO) principle. An excellent example of a queue is a line of students in the food court of the UC. New additions to a line made to the back of the queue, while removal (or serving) happens in the front. In the queue only two operations are allowed enqueue and dequeue. Enqueue means to insert an item into the back of the queue, dequeue means removing the front item. The picture demonstrates the FIFO access.

### Implementation

In the standard library of classes, the data type queue is an adapter class, meaning that a queue is built on top of other data structures. The underlying structure for a queue could be an array, a Vector, an ArrayList, a LinkedList, or any other collection. Regardless of the type of the underlying data structure, a queue must implement the same functionality. This is achieved by providing a unique interface.

```
interface QueueInterface‹AnyType>
{
   public boolean isEmpty();

   public AnyType getFront();

   public AnyType dequeue();

   public void enqueue(AnyType e);

   public void clear();
}
```

Each of the above basic operations must run at constant time O(1).

### Circular Queue
While implementing queue using Array data structure, we run into a problem where we have reached the end of the array but we have some empty space at the front of the array. So to utilize that space the concept of circular array was evolved which is a theratical concept while array is still the same but we start setting as follows so that we can always use empty space at the front of the array.

```
//Here N is size of array so below formula ensures once we reach the end of array it restarts from the 0th index.
rear = (rear+1)%N
```

### Applications

The simplest two search techniques are known as Depth-First Search(DFS) and Breadth-First Search (BFS). These two searches are described by looking at how the search tree (representing all the possible paths from the start) will be traversed.

**Deapth-First Search with a Stack**

In depth-first search we go down a path until we get to a dead end; then we backtrack or back up (by popping a stack) to get an alternative path.

```
Create a stack
Create a new choice point
Push the choice point onto the stack
while (not found and stack is not empty)
Pop the stack
Find all possible choices after the last one tried
Push these choices onto the stack
Return
```

**Breadth-First Search with a Queue**

In breadth-first search we explore all the nearest possibilities by finding all possible successors and enqueue them to a queue.

```
Create a queue
Create a new choice point
Enqueue the choice point onto the queue
while (not found and queue is not empty)
Dequeue the queue
Find all possible choices after the last one tried
Enqueue these choices onto the queue
Return
```
