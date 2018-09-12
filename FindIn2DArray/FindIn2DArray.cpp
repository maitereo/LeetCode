#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> format_array(int size_col, int size_row)
{
	vector<vector<int>> array(size_col);
	static int loop_offset = 0;
	for (vector<vector<int>>::iterator iter = array.begin(); iter != array.end(); iter++)
	{
		
		iter->resize(size_row);
		int temp_int = 1 + (loop_offset++)*size_col;

		for (vector<int>::iterator temp_iter = iter->begin(); temp_iter != iter->end(); temp_iter++)
		{
			*temp_iter = temp_int++;
		}

	}

	return array;
}

void print_array(vector<vector<int>> array)
{

	for (vector<vector<int>>::iterator iter = array.begin(); iter != array.end(); iter++)
	{

		for (vector<int>::iterator temp_iter = iter->begin(); temp_iter != iter->end(); temp_iter++)
		{
			cout << *temp_iter << "\t";
		}
		cout << endl;

	}

}

bool find(int target, vector<vector<int>> array)
{
	if (array.empty()) return false;

	int row_max = array.size()-1,
		col_max = array[0].size()-1,
		col = 0,
		row = row_max;

	int i = 0;
	while ((row >= 0) && (col <= col_max))
	{
		cout << "step " << i++ << "\t at: " << array[row][col] << endl;
		if (target < array[row][col]) row--;
		else if (target > array[row][col]) col++;
		else
		{
			cout << "\nTarget found at: colomn " << col << "\t row " << row << endl;
			return true;
		}

		if ((row >= 0) && (col <= col_max)) cout << "next move: " << array[row][col] << endl;
	}

	cout << "\nTarget not found!" << endl;
	return false;
}

int main()
{
	int target = 20;
	vector<vector<int>> array = format_array(4,5), array_empty;
	
	cout << "Find target int " << target << "in binary array:" << endl;
	print_array(array);
	cout << endl;

	bool b = find(target, array);

	cout << "returned value is " << b << endl;
	system("pause");

	return 0;
}
