#include <iostream>
#include <vector>

/* Idea: loop
1. > forward until reaches boundary 
2. v downward until reaches boundary
3. < backward until reaches boundary
4. ^ upward until reaches doundary
*/
// class Solution 
// {
// public:
//     std::vector<int> printMatrix(std::vector< std::vector<int> > matrix) 
//     {
//     	std::vector<int> result(0);
//     	// if( (matrix.size()==1)  return matrix[0];
//     	int leftBound = 0, rightBound = matrix[0].size()-1,
//     		topBound = 0, bottomBound = matrix.size()-1,
//     		currentR = 0, currentC = -1, counter = 0;
//     	int numMembers = matrix[0].size() * matrix.size();
//     	bool forward = true, downward = true;

//     	std::cout 
// 			<< "leftBound: " << leftBound
// 			<< " rightBound: " << rightBound
// 			<< " topBound: " << topBound
// 			<< " bottomBound: " << bottomBound
// 			<< std::endl;

//     	while( counter < numMembers )
//     	{
//     		if(forward)
//     		{
//     			while(currentC < rightBound) 
//     			{
//     				result.push_back(matrix[currentR][++currentC]);
//     				std::cout << "pushing: " << matrix[currentR][currentC] << "\n";
//     				counter++;
//     			}
// 				topBound++;    			
//     		}
//     		else
//     		{
//     			while(currentC > leftBound) 
//     			{
//     				result.push_back(matrix[currentR][--currentC]);
//     				std::cout << "pushing: " << matrix[currentR][currentC] << "\n";
//     				counter++;
//     			}
//     			rightBound--;
//     		}
//     		forward = !forward;

//     		if(downward)
//     		{
//     			while(currentR < bottomBound) 
//     			{
//     				result.push_back(matrix[++currentR][currentC]);
//     				std::cout << "pushing: " << matrix[currentR][currentC] << "\n";
//     				counter++;
//     			}
//     			bottomBound--;
//     		}
//     		else
//     		{
//     			while(currentR > topBound) 
// 				{
//     				result.push_back(matrix[--currentR][currentC]);
//     				std::cout << "pushing: " << matrix[currentR][currentC] << "\n";
//     				counter++;
// 				}
// 				leftBound++;
//     		}
//     		downward = !downward;

//     		std::cout 
//     			<< "leftBound: " << leftBound
//     			<< " rightBound: " << rightBound
//     			<< " topBound: " << topBound
//     			<< " bottomBound: " << bottomBound
//     			<< std::endl;

//     	}
    	
//     	return result;

//     }
// };

class Solution 
{
public:
    std::vector<int> printMatrix(std::vector< std::vector<int> > matrix) 
    {
    	std::vector<int> result(0);
    	// if( (matrix.size()==1)  return matrix[0];
    	int leftBound = 0, rightBound = matrix[0].size()-1,
    		topBound = 0, bottomBound = matrix.size()-1;

    	while( (leftBound <= rightBound) && (topBound <= bottomBound) )
    	{
	    	for(int i = leftBound; i <= rightBound; ++i)
	    		result.push_back(matrix[topBound][i]);

	    	for(int i = topBound+1; i <= bottomBound; ++i)
	    		result.push_back(matrix[i][rightBound]);

	    	if(topBound != bottomBound)
		    	for(int i = rightBound-1; i >= leftBound; --i)
		    		result.push_back(matrix[bottomBound][i]);

		    if(leftBound != rightBound)
		    	for(int i = bottomBound-1; i > topBound; --i)
		    		result.push_back(matrix[i][leftBound]);

			leftBound++; topBound++; rightBound--; bottomBound--;    	
		}
    	
    	return result;

    }
};

int main()
{
	int r, c, size_r = 1, size_c = 5;
	std::vector< std::vector<int> > matrix;

	std::cout << "Create matrix\n";
	matrix.resize(size_r);
	for(r = 0; r < size_r; r++)
	{
		matrix[r].resize(size_c);
		for(c = 0; c < size_c; c++)
		{
			matrix[r][c] = r*size_c + c + 1;
			std::cout << matrix[r][c] << "\t";
		}
		std::cout << std::endl;
	}

	Solution solution;
	std::vector<int> result = solution.printMatrix(matrix);

	for(std::vector<int>::iterator iter = result.begin(); iter != result.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;
	

	return 0;
}