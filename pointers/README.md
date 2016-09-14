# Pointer in C
--------------
Pointers are **strongly typed** meaning if you want to assign address of an integer to a pointer then you have to declare
int* for your pointer simillarly for char/double etc.

In case you assign a char* to a int* like
```
int a = 1025;
int* p = &a;
char *p1 = p;
```

then print *p1 would fetch the value of first byte from the 4 byte integer because char is of size 1 byte.
so any arithmatic like *p1 + 1 would denote next byte from integer's value.

Best resource to refresh pointers would be to watch [video series](https://www.youtube.com/playlist?list=PL2_aWCzGMAwLZp6LMUKI3cc7pgGsasm2_)

## Pointer to Pointer
---------------------
![](p2p.png)

## Pointers as function argument

Essentially when we set an argument as 
```
function foo(int* p) {}
```

We are saying that this function needs to be passed with a **&arg** because int* is also a representation to &a if a was an intger.

## Arrays and Pointer

Arrays are very simmilar to the concept of pointers. for example

```
int arr[] = {1,2,3,4,5};
printf("%d\n", arr);
printf("%d\n", &arr[0]);
printf("%d\n", arr[1]);
printf("%d\n", *(arr+1));
```

Here first two lines would print the same value which is address of the array.
Last two lines will print the value of next element i.e. **2** 
So what this means is that when we say arr[1] it also means *(arr+1) 
so lets take an example of reverting an array, we would need to swap left and right elements with each other
so the code would be as below

```
//Returns pointer to the new array
int* reverse() {
  int arr[] = {1, 2, 3, 4, 5};
  int start = 0, length = 5; //just because length is static for the example
  
  while(start < length) {
    swap(arr[start++], arr[--length]);  //Passing array elements without using &
  }
  
  return arr;
}

//Swap function using XOR for swapping
void swap(int *a, int *b) {
  *a = *a ^ *b;
  *b = *a ^ *b;
  *a = *a ^ *b;
}
```
Did you notice how I could simply pass array elements withou using & in the swap function. This is only possible because arrays are pass by reference not pass by value.
