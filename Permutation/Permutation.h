#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    void cout_vector()
    {
        std::cout << "Size of vector is: " << returnVector.size() << std::endl;
        for(std::vector<std::string>::iterator iter = returnVector.begin(); 
            iter != returnVector.end();
            iter++)
        {
            std::cout << *iter << std::endl;
        }
    }
    std::vector<std::string> Permutation(std::string str);
    
private:
    std::vector<std::string> returnVector;
    void dfs(std::string str, int index);
};