This is the basic elliptic curve setup for a bitcoin-esque blockchain from scratch.

Resources: Programming Bitcoin (python)
Ellip‐tic curve cryptography is required for understanding signing and verification, which
is at the heart of Bitcoin itself. 
We represented a field element in the Field Element class (.cpp, .h)
The class represents an element in FPrime
Field Series = F(p){0,1,2,...p-1)
F(P) is a finite field called field of P,. The numbers between {} are the elements within the field.
Field orders are always 1 more than the largest element. Every field has a prime order, fields must have an order which is the power of a prime number. 


In order to test Field Elements run the main class `(BlockChain.cpp)` without debugging in visual studio.
0 = points not on curve
1 = successful
