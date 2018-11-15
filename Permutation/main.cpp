#include <iostream>
#include "Permutation.h"

int main(int argc, char* argv[])
{
    std::string input_str = argv[1];
    std::cout << "Input string: " << input_str << std::endl;

    Solution solution;
    solution.Permutation(input_str);

    std::cout << "Permutation:\n";
    solution.cout_vector();

    return 0;
}