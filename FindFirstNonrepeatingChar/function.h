/* Idea: Use map to store characters followed by counter.
*/

#include <iostream>
#include <map>
#include <string>

class Solution {
public:
    int FirstNotRepeatingChar(std::string str) {
        if(str.empty()) return -1;

        std::map<char, int> char_map;
        for(int i = 0, size = str.size(); i < size; i++) char_map[str[i]]++;

        for(int i = 0, size = str.size(); i < size; i++)
        {
            if(char_map[str[i]] == 1) return i;
        }

        return -1;

    }
};