#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    void FindNumsAppearOnce(std::vector<int> data,int* num1,int *num2) {
        std::map<int, int> data_map;
        bool number_counter = false;
        for(int i = 0; i < data.size(); i++){
            data_map[data[i]]++;
        }

        //     for(std::map<int, int>::iterator iter = data_map.begin(); iter != data_map.end(); iter++)
        //         std::cout << iter->first << " " << iter->second << "\n";
        // std::cout << "size of map is: " << data_map.size() << "\n";
        for(int i = 0; i < data.size(); ++i){
            if(data_map[data[i]] == 1){
                if(!number_counter){
                    *num1 = data[i];
                    number_counter = !number_counter;
                    continue;
                }
                else{
                    *num2 = data[i];
                    return;
                }
            }
        }
    }
};