/* Idea: Sort
If a vector contains elements {12, 2, 21}.
2   <  12
122 < 212
then choose 122

2   < 21
221 > 212
then choose 212

Therefore, numbers A and B cannot be sorted with
their values. Sorting strategy must be AB < BA,
NOT A+B < B+A.
*/

#include <stdlib.h>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    static bool comp(int a, int b)
    {
        std::string A = std::to_string(a) + std::to_string(b);
        std::string B = std::to_string(b) + std::to_string(a);
        return std::stoi(A) < std::stoi(B);
    }
    
    std::string PrintMinNumber(std::vector<int> numbers) {
        if(numbers.empty()) return "";
        std::sort(numbers.begin(), numbers.end(), comp);
        std::string res = "";
        for(std::vector<int>::iterator iter = numbers.begin(); iter!=numbers.end(); iter++)
        {
            res += std::to_string(*iter);
        }
        return res;
    }
};