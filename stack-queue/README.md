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
space for parameters and local variables is created internally using a stack.

compiler's syntax check for matching braces is implemented by using stack.

support for recursion

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




