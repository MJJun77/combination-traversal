# combination-traversal
C++ code to traverse set's combination one by one.

* How to match all combination

There must be absolutely better refined or superior idea on somewhere, but I just wanted to make it as I wanted - no recursive, and one by one retrieval.
nCk (k Selection from n) can be represented as n length binary with k number of '1' and n-k number of '0'. 
The only problem is how to retrieve, or how to set the order of these number. 
If you imagine binary tree, this will be easy : Let's set the root as nCk. 
According to the binary's 1st digit(0 or 1), left child is n-1Ck and right child is n-1Ck-1. 
Then their subchildren are : n-2Ck, n-2Ck-1 and n-2Ck-1, n-2Ck-2 each. 
The tree branch stretches until n' == k' or k' == 0, and then it is 'terminal node' which represents same number of '0' or '1' at the end part.

So now, the problem is simply how to retrieve terminal node in this "binary tree" : Let's move left to right simply. 
To visit next terminal node, current node shall be moved to the parent until parent's branch represents '0'. 
And this happens when met first '0' after finding one or more '1' sequence. 
Then change the parent's 0 as 1, then rearrange its substring as n" C k" as minimum number. 

For example, if the number is 111000111000, coresponding terminal node is 3C0. 
Let's climb the binary tree until met the bigger parent : 11100x. 
After met the first '0' after one or more '1', change this as '1'.  Then rearrange the tail(111000, 6C3) as minimum number after decrementing k(6C2, 000011). 
So we moved from 111000111000 -> 111001000011. 
Consequently, these retreival is lexicographical order.
