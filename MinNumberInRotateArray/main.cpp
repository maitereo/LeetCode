#include <iostream>
#include <vector>

void printVector(std::vector<int> &input)
{
    for(std::vector<int>::iterator iter = input.begin(); iter != input.end(); iter++)
    {
        std::cout << *iter << " ";
    }
}

class Solution {
public:
    int minNumberInRotateArray(std::vector<int> &rotateArray) {
        if(rotateArray.empty()) return 0;

        for(std::vector<int>::iterator iter = rotateArray.end()-1; iter != rotateArray.begin(); iter--)
        {
            std::cout << "Comparing " << *(iter-1) << " and " << *iter << std::endl;
            if(*(iter-1) > *iter) return *iter;
        }

        return 0;
    }
};

int main()
{
    int array[] = {1,2,3,4,5}, rotateArray[] = {3,4,5,1,2};
    std::vector<int> vecArray(array, array + sizeof(array)/sizeof(int));
    std::vector<int> vecRotateArray(rotateArray, rotateArray + sizeof(rotateArray)/sizeof(int));

    std::cout << "Array is: { ";
    printVector(vecArray);
    std::cout << "}\n";

    std::cout << "rotateArray is: { ";
    printVector(vecRotateArray);
    std::cout << "}\n";

    Solution solution;
    int minNumber = solution.minNumberInRotateArray(vecRotateArray);
    std::cout << "\nMinimum number in rotate array is " << minNumber << std::endl;

    return 0;
}