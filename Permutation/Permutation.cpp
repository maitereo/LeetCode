#include <iostream>
#include "Permutation.h"

/* Idea: DFS with recursion
1. Return empty vector if string is empty;

2. Swap the first element in the string with any other 
element after it one by one if two elements are not the same.

3. Move to next element and do the same as 2.

4. Push the swapped <string> into <returnVector> if reaches the
last element (no element after current element).

*/

std::vector<std::string> Solution::Permutation(std::string str)
{
    if(!str.empty()) dfs(str, 0);
    return returnVector;
}



void Solution::dfs(std::string str, int index)
{
    // std::cout << str << std::endl;
    int str_size = str.size();
    if(index == str_size)
    {
        returnVector.push_back(str);
        return;
    }

    for(int i = index; i < str_size; ++i)
    {
        if( i!=index && str[i]==str[index]) continue;
        std::swap(str[index], str[i]);
        dfs(str, index+1);
    }
}