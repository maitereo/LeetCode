#include <vector>

class Solution {
public:
    int InversePairs(std::vector<int> data){
        int p = 0, size = data.size();
        for(int i = 1; i < size; ++i)
            for(int j = 0; j < i; ++j) if(data[j] > data[i]) ++p;
        return p%1000000007;
    }
};