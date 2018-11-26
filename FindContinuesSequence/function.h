#include <vector>

class Solution {
public:
    std::vector<std::vector<int> > FindContinuousSequence(int sum) {
        std::vector<std::vector<int> > res;
        std::vector<int> temp;
        if(sum < 3) return res;
        for(int i = 1; i < sum; i++){
            temp = getSequence(sum, i);
            if(!temp.empty())
                res.push_back(temp);
        }
        
        return res;
    }
    
    std::vector<int> getSequence(int sum, int num){
        std::vector<int> sequence, emp;
        while(sum > 0){
            sequence.push_back(num);
            sum -= num;
            num++;
        }
        if(sum == 0) return sequence;
        else return emp;
    }
};