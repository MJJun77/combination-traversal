# combination-traversal
C++ code to traverse set's combination one by one.

* How to match all combination

There must be absolutely better refined or superior idea on somewhere, but I just wanted to make it as I wanted - no recursive, and one by one retrieval.
nCk (k Selection from n) can be represented as n length binary with k number of '1' and n-k number of '0'. 
The only problem is how to retrieve, or how to set the order of these number. 

Here, I used boolean for selection flag.  For example, 7C4 can be represented as 1111000 or 0001111.

In ascending order option, means 7 digit binary value is smaller -> bigger, the vector will be retrieved as this order :
0001111 -> 0010111 -> 0011011 -> ... -> 1111000

In descending order option, means 7 digit binary value is bigger -> smaller, the vector will be retrieved as this order :
1111000 -> 1110100 -> 1110010 -> ... -> 0001111
