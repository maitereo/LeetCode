#include <iostream>
#include "function.h"

int main()
{
    int array[] = {2,4,3,6,3,2,5,5}, *num1, *num2;
    std::vector<int> array_vec(array, array + sizeof(array)/sizeof(int));

    Solution solution;
    solution.FindNumsAppearOnce(array_vec, num1, num2);

    std::cout << "Input array is: \n";
    for(int i = 0; i < array_vec.size(); i++)
        std::cout << array_vec[i] << "  ";
    std::cout << std::endl << "number 1 is: " 
        << *num1 << "\nnumber 2 is: " << *num2 << std::endl;

    return 0;
}
