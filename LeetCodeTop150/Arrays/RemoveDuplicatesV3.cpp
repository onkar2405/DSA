#include<iostream>
#include<vector>
using namespace std;


int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        int count=1;
        int k=1;
        int ind = 1;

        for(int i=1; i<nums.size(); i++) {
            if (nums[i]==nums[i-1] && k<2) {
                if(k<2) {
                    k++;
                    count++;
                    ind++;
                } 
            }
            else if (nums[i] != nums[i-1]) {
                k=1;
                nums[ind]=nums[i];
                ind++;
                count++;
            }
        }

        return count;
    }


  int main() {
    vector<int> arr = {0,0,1,1,1,1,2,3,3};

    return 0;
  }