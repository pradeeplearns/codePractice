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
