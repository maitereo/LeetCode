#include <iostream>
#include <stdlib.h>
#include <vector>

class Solution
{
public:
    void reOrderArray(std::vector<int> &array) 
    {
    	if(array.empty()) return;

    	int temp;
        for(std::vector<int>::iterator iter = array.begin(); iter != array.end()-1; iter++)
        {
            std::cout << "\nlooking for " << *iter << " and " << *(iter+1) << std::endl
            	<< "swap? ";
        	if(!(*iter%2) && (*(iter+1)%2))
        	{
        		std::cout << "yes\n";
        		temp = *iter; *iter = *(iter+1); *(iter+1) = temp;
        		if(iter != array.begin()) iter = iter-2;
        	}
        	else std::cout << "no\n";
        }
    }
};

int main(int argc, char* argv[])
{
	int iArray[argc-1], i;
	Solution solution;
	
	for(i = 1; i < argc; i++) iArray[i-1] = atoi(argv[i]);

	std::cout << "Original array: ";
	std::vector<int> array(iArray, iArray + sizeof(iArray)/sizeof(int));
	for(i = 1; i < argc; i++) std::cout << array[i-1] << " ";
	std::cout << "\n";

	solution.reOrderArray(array);
	std::cout << "Reordered array: ";
	for(i = 1; i < argc; i++) std::cout << array[i-1] << " ";
	std::cout << "\n";
	return 0;
}