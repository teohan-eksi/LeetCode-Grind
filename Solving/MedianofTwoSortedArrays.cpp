//merge to working

/* Given two sorted arrays nums1 and nums2 of size m and n respectively,
 * return the median of the two sorted arrays.

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Example 3:

Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000

Example 4:

Input: nums1 = [], nums2 = [1]
Output: 1.00000

Example 5:

Input: nums1 = [2], nums2 = []
Output: 2.00000

Constraints:

    nums1.length == m
    nums2.length == n
    0 <= m <= 1000
    0 <= n <= 1000
    1 <= m + n <= 2000
    -106 <= nums1[i], nums2[i] <= 106

 
Follow up: The overall run time complexity should be O(log (m+n)).
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if(nums1.empty()){
			return findMedian(nums2);
		}else if(nums2.empty()){
			return findMedian(nums1);
		}else if(nums1.empty() && nums2.empty()){
			return 0;
		}else{
			//sort them and find the median of the sorted list.
			int i = 0;
			int k = 0;
			int nextElem;
			vector<int> nums;
			while(true){
				if(i < nums1.size()){
					nextElem = nums1.at(i);	
				}else{
					nextElem = nums2.at(k);
					k++;
				}
				
				if(k < nums2.size()){
					if(nextElem < nums2.at(k)){
						i++;		
					}else{
						nextElem = nums2.at(k);
						k++;
					}
				}else{
					i++;
				}
				
				nums.push_back(nextElem);
				cout<<nextElem<<"\n";	
				if(i >= nums1.size() && k >= nums2.size()){
					break;	
				}
			}
				
			return findMedian(nums);
		}
    }

	double findMedian(vector<int>& nums){
		if(nums.size() % 2 == 0){
			return (((double) nums.at((nums.size()/2)-1)) + ((double) nums.at(nums.size()/2)))/2;
		}else{
			return ((double) nums.at((nums.size()-1)/2));
		}
	}
};


int main(){
	cout << "main\n";

	Solution sol;

	vector<int> nums1{1,3};
	vector<int> nums2{2};
	
	cout<<sol.findMedianSortedArrays(nums1, nums2)<<"\n";
	return 0;
}
