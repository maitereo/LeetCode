#include "function.h"

/* Idea:
1. Return 0 if input vector is empty

2. Set <reference> element to be the 1st in the <array>, and the
<current> element to be the one next to the <reference>. Default
value of <counter> is 1.

3. Compare <reference> and <current>, count up if match, otherwise
don't count. Move <current> to next element until reach the end of
the <array>. 

4. Return <reference> at any the moment that <counter>*2 is greater 
than size of the <array>.

5. Move <reference> to the next element until reach the middle
element position. If no return has been triggered, return 0.
*/
// int Solution::MoreThanHalfNum_Solution(std::vector<int> numbers)
// {
//     int n = numbers.size();
//     if (n == 0) return 0;
        
//     int counter, comp_ref;
//     for(int i1 = 0; i1*2 < n; i1++)
//     {
//         comp_ref = numbers[i1];
//         counter = 0;
//         for(int i2 = i1; i2 < n; i2++)
//         {
//             if(comp_ref == numbers[i2]) counter++;
//             if(counter*2 > n) return comp_ref;
//         }
//     }

//     return 0;

// }

/* Solution of O(n)
If any element in the array repeats more than half number of
the elements inside the array. This element must repeated next
to each other at somewhere. Therefore, count up if next element
is same to the previous and compare to the next one, otherwise 
count down, reset counter and set comparing reference to current
element. 
*/
int Solution::MoreThanHalfNum_Solution(std::vector<int> numbers)
{
    int n = numbers.size();
    if (n == 0) return 0;
        
    int num = numbers[0], count = 1;
    for (int i = 1; i < n; i++) {
        if (numbers[i] == num) count++;
        else count--;
        if (count == 0) {
            num = numbers[i];
            count = 1;
        }
    }
    // Verifying
    count = 0;
    for (int i = 0; i < n; i++) {
        if (numbers[i] == num) count++;
    }
    if (count * 2 > n) return num;
    return 0;

}