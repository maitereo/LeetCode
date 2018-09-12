#include <iostream>
#include <stdlib.h>

//------------- Method 1------------------------
//void replaceSpace(char *str, int length)
//{
//	int old_length = 0, space_num = 0;
//	char *str_start = str;
//
//	while (*str != '\0')
//	{
//		if (*str == ' ') space_num++;
//		old_length++;
//		str++;
//	}
//	old_length++;
//
//	int new_length = old_length + space_num * 2;
//
//	char *buffer = (char*)malloc(new_length * sizeof(char));
//	char *buffer_move = buffer;
//
//	str = str_start;
//	while (*str != '\0')
//	{
//		if (*str != ' ') *buffer_move = *str;
//		else
//		{
//			*(buffer_move++) = '%';
//			*(buffer_move++) = '2';
//			*(buffer_move) = '0';
//		}
//		std::cout << *str << " " << *buffer_move << std::endl;
//		str++; buffer_move++;
//	}
//	*buffer_move = '\0';
//
//	buffer_move = buffer;
//	str = str_start;
//	while (*buffer_move != '\0')
//	{
//		*str = *buffer_move;
//		std::cout << *(str++) << " " 
//				<< *(buffer_move++) << std::endl;
//	}
//	*str = '\0';
//	std::cout << std::endl;
//
//	std::cout << "old_length: " << old_length << std::endl
//		<< "new_length: " << new_length << std::endl
//		<< "space_num: " << space_num << std::endl;
//
//	free(buffer);
//}
//

//--------------------- Method 2------------------------------
void replaceSpace(char *str, int length) {

	if ((str == NULL) || (length < 0)) return;

	int space_num = 0, string_length = 0;
	char *ptr_str = str;
	while (*ptr_str != '\0')
	{
		if (*(ptr_str++) == ' ')
		{
			space_num++;
		}
		string_length++;
	}

	int new_length = string_length + 2 * space_num;

	if (new_length > length) return;

	int ptr_old = string_length;
	int ptr_new = new_length;

	while (ptr_old>=0 && ptr_new>=0)
	{
		if (str[ptr_old] == ' ')
		{
			str[ptr_new--] = '0';
			str[ptr_new--] = '2';
			str[ptr_new] = '%';
		}
		else str[ptr_new] = str[ptr_old];
		ptr_new--; ptr_old--;

	}

}

int main()
{

	char string[100] = "we are happy";
	int length = 100;

	replaceSpace(string, length);

	std::cout << string << std::endl;

	system("pause");

	return 0;
}
