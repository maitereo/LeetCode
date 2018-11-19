/* Idea: Traverse from 1 to n, count number of 1's of traversal.
1. Loop from 1 to n

2. If (number mod 10) == 1, means last digit is 1, count up.

3. Shift the number a digit to the right, and check last digit.
Repeat 2.

4. Return counter.
*/

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int counter = 0, num;
        for(int i = 1; i <= n; i++)
        {
            num = i;
            while(num)
            {
                if(num % 10 == 1) counter++;
                num /= 10;
            }
        }
        return counter;
    }
};