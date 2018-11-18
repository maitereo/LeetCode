#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> GetLeastNumbers_Solution(std::vector<int> input, int k) {
        std::vector<int> output;
        if(input.size() < k) return output;
        
        std::sort(input.begin(), input.end());

        std::vector<int>::iterator iter = input.begin();
        output.assign(iter, iter+k);
        return output;
    }
};