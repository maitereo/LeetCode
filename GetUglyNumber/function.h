#include <iostream>
#include <vector>

/* Brute Force 
Check every number from 1 to infinity.
Stop at N'th ugly number.
*/
// class Solution {
// public:
//     int GetUglyNumber_Solution(int index) 
//     {
//         if(index < 1) return 0;
//         else if(index == 1) return 1;
        
//         int i = 2, counter = 0;
//         for(i = 1; counter != index; i++)
//         {
//             if( isUgly(float(i)) ) counter++;
//             std::cout << "i = " << i << " counter = " << counter << std::endl;
//         }
//         return --i;
//     }
    
//     bool isUgly(float num)
//     {
//         // std::cout << "In isUgly(" << num << ")\n"; 
//         if(num == 1) return true;
//         if(num < 1) return false;
//         return isUgly(num/2) || isUgly(num/3) || isUgly(num/5);
//     }
// };

/* 
Calculate ugly number from 1st ugly number to Nth ugly number
*/

class Solution {
public:
    int GetUglyNumber_Solution(int index) 
    {
        if(index < 7) return index;
        std::vector<int> ugly_array(index);
        ugly_array[0] = 1;
        int p2=0, p3=0, p5=0;
        for(int i = 1; i < index; i++)
        {
            ugly_array[i] = std::min( ugly_array[p2]*2, std::min(ugly_array[p3]*3, ugly_array[p5]*5) );
            if(ugly_array[i] == ugly_array[p2]*2) p2++;
            if(ugly_array[i] == ugly_array[p3]*3) p3++;
            if(ugly_array[i] == ugly_array[p5]*5) p5++;
        }
        return ugly_array[index-1];
    }

};