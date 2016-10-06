## Hashing
Gayle Laakmann says always think of hash tables while solving Algorithmic problems. There are more than expected to help in your quest.

Hashing essentially means arranging large data in a smart way which makes accessing them easy while keeping a beautiful arrangment.

There are two most important part of hashing.

**Hash Function**

* Hash-code maps
* Compression maps

**Open Addressing**

* Chaining - Think of an array pointing to a list of elements which has same hash code
* Linear Probing - Think of storing elements in an array if collision then iterate to next and put the element there
* Double Hashing - Same as Linear probing but instead of iterating to next in case of collision jump by a offset and put the element there if empty or repeate

An essential requirement of hash function is to map equal keys to equal indices everytime.

A **good** hash function minimizes the probability of collisions.

* hash code map : key -> integer
* compression map : integer -> [0, N-1]    N - size of hash table

Hash code map converts a key into integer, if the key is not integer then we convert it to integer. 

### Hash code map
**Integer cast** For numeric types with 32 bits or less, we can interpret the bits of number as an int.

**Component sum** for numeric type of more than 32 bit (eg. long, double) we can add the 32 bit components. eg take 4 bits each and add them till 32 bits

**Polynomial accumulation** for **strings** of a natural language, combine the charectar values (ASCII or Unnicode) A<sub>0</sub> A<sub>1</sub>...A<sub>n-1</sub> by viewing them as cofficients of a polynomial
```
A<sub>0</sub> + A<sub>1</sub>X + ... + A<sub>n-1<sub>X<sup>n-1</sup>
```

The polynomial is computed with Horner's rule, ignoring overflows. at a fixed value X.

The choice X = 33, 37, 39 or 41 gives at most 6 collisions on a vocabulary of 50000 English words.

### Compression maps
**Use the remainder**

h(k) = k mod m, k is the key and m is hash table size

**We need to choose m**

m = b^e **(bad)**

If m is power of 2, h(k) gives the e least significant bits of k. All keys with same ending go to the same place.

**m prime (good)**

Prime m helps ensure uniform distribution, also prime should not be too close to exact power of 2. eg for 2000 elements good m can be 701


**Use h(k) = ceiling(m(kA mod 1))**

k is the key, m is the size of table, and A is constant 0 < A < 1 (Fraction)

Here value of m is not critical, typically use m = 2^p | Optimal choice of A depends on the charectarstics of the data. Knuth says use A = (sqrt(5) - 1)/2 (Conjugate of golden ratio) - Fibonacci Hashing

**Use Multiply, Add, & Divide (MAD)**

h(k) = abs(ak + b) mod m

* Eliminates patterns provided **a** is not a multiple of m
* Same formula is used in linear congruential (pseudo) random number generators


