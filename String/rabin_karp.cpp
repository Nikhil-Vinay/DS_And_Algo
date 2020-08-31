/* Rabin-Karp Method of string matching */
/* This method is based on rolling hash mechanism.
 * Simple Example: a-1, b-2, c-3, d-4, e-5, f-6, g-7, h-8, i-9, j-10
 * string - "abbcdabcabbcd", pattern - "abb"
 * hash of pattern = (1+2+2) = 5. If has pattern match then verify with pattern.
 * Draw back: there could be multiple spurious hits (hash collision).
 * We need a strong hash pattern for the same.
 *
 * we will make a hash for above pattern as = (1*10^2 + 2*10^1 + 2*10^0)
 * Suppose length of pattern is m then hash val will be = c.m-1 * 10^m-1 + c.m-2 * 10^m-2......c.0 * 10^0.
 *
    c.m-1 = (m-1)th character val

 * Note: 10 is base value here..it could be any value based on the string character range. here there are
 * 10 character so, 10 (base value)is taken. 
 *
 * Note: hash value could be very big which cant be held in an integer so we need to use mod technique for this.
 * We can do mod operation by 2^32 in case of integer.
 *
 * (a+b) mod n = ((a mod n) + (b mod n))mod n
 * ..

   Suppose base is taken as 10 and there are 3 characters then hash value is:
   c2 * 10^2 + c1 * 10^1 + c0 * 10^0  =  hash

   find next window hash by previous hash by rolling hash technique

   ((hash - c2 * 10^2) * 10 ) + new_char_val * 10^0    // we use mod technique to reduce the val

   
 */ 
