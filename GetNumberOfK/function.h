#include <vector>

class Solution {
public:
    int GetNumberOfK(std::vector<int> data ,int k){
        if(data.empty()) return 0;
        int res = 0;
        int firstK = getFirstK(data, k, 0, data.size()-1);
        int lastK = getLastK(data, k, 0, data.size()-1);
        if(firstK > -1 && lastK > -1) res = lastK - firstK + 1;
        return res;
    }
    
    int getFirstK(std::vector<int> data, int k, int lb, int rb){
        if(lb > rb) return -1;
        int mid = (rb + lb)/2;
        if(data[mid] == k)
        {
            if((mid == lb) || (data[mid-1] != k)) return mid;
            else rb = mid - 1;
        }
        if(data[mid] > k) rb = mid - 1;
        if(data[mid] < k) lb = mid + 1;
        return getFirstK(data, k, lb, rb);
    }
    
    int getLastK(std::vector<int> data, int k, int lb, int rb){
        if(lb > rb) return -1;
        int mid = (rb + lb)/2;
        if(data[mid] == k)
        {
            if((mid == rb) || (data[mid+1] != k)) return mid;
            else lb = mid + 1;
        }
        if(data[mid] > k) rb = mid - 1;
        if(data[mid] < k) lb = mid + 1;
        return getLastK(data, k, lb, rb);
    }
    
};

// Brute Force
/*
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        return count(data.begin(), data.end(), k);
    }
}
*/