


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int pivot_ind = 0;
        int pivot_num;
        int i = 0;
        vector<int> res;
    
        int k;
		for(i; i<nums.size(); i++){
            pivot_num = nums.at(i);
 			k = i + 1;
           
            for(k; k<nums.size(); k++){
                if(pivot_num + nums.at(k) == target){
                    res.push_back(pivot_ind);
                    res.push_back(k);
                    return res;
                }
            }
            pivot_ind++;
			pivot_num = 0;
        } 
    	return res;
	}
};

int main(){
	cout<< "main\n";
	
	Solution sol;
	vector<int> inputV{2,5,5,11};
	vector<int> outputV = sol.twoSum(inputV, 10);
	
	cout<<outputV[0]<<" "<<outputV[1];

	return 0;
}
