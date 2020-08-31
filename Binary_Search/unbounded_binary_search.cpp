/********** What is un bounded binary seach ? *****************************/
/*** If an sorted array has infinite number of elements then seaching for an element in this array is
 * called unbounded binary search because right bound is not known at all and we need to search an element 
 * in logarithmic time.
 *
 * Suppose array is as below: 
 * { 2, 5, 8, 10, 20,25.........................}
 *
 * Solution: We know the array is sorted so, we will try seaching from begining and will keep on doubling the
 * search length.
 *
 *bool binarysearch( arr, val, start, end) {
     ............
     return...
  }

bool unbound_binarysearch(arr, val) {
   int start_index = 0;
   int end_index = 2;

   while(1) {  //  as we know there is know limitation of index, always we get index by doubling
               // Don't think about the overflow of integer range
     if(val == arr[end_index]) {
        return true;
     } else if (val > arr[end_index]) {
       start_index = end_index+1;
       end_index = end_index*2;
     } else {
       return binarysearch(arr, val, start_index, end_index);
     }
  }
