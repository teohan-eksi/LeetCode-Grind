#include <iostream>
#include <math.h>
using namespace std;


class Solution {
public:
    int reverse(int x) {

		/* create an integer pointer to use as
		 * an integer array.
		 * allocate a memory block worth 10 integers,
		 * because the input is a 32-bit signed integer
		 * max = -2^31, 2^31 -1
		 *
		 * separate the digits of the input and store
		 * them in the pointer array.
		 * 123 -> [3, 2, 1]
		 *
		 * by counting how many times the while loop turned,
		 * we can get the digit count of the input.
		 * i -> digit count-1
		 * i = 2 for 123, because i starts from 0.
		 *
		 * reassign x = 0, so that we can start over
		 * and create our reversed number.
		 *
		 * take the first digit from the reversed order
		 * array and multply it with pow(10, i)
		 * decrement i by one.
		 *
		 * 123 -> [3,2,1]
		 * i = 2
		 * we want to get 321
		 * 321 = 3 * pow(10, i) + 2*pow(10, i-1) ...
		 * do it with a for loop
		 * BUT if i = 9, meaning the input is a 10 digit number,
		 * check if reverse of the input is bigger than the max 32-bit signed 
		 * integer values.
		 *
		 */

		int* res = (int*) malloc(sizeof(int)*10);
		
		int i = 0;
		int last_dig;
		while(x >= 10 || x <= -10){
			last_dig = x%10;
			*(res + i) = last_dig;
			i++;

			x = (x - last_dig)/10;
		}
		*(res+i) = x;
		x=0;

	
		int pos_max[10] = {2,1,4,7,4,8,3,6,4,7};
		int k = 0;
		if(i == 9){
			for(k; k<=i; k++){
				if(*(res+k) > 0 && *(res+k) > pos_max[k]){
					return 0;
				}else if(*(res+k) > 0 && *(res+k) < pos_max[k]){
					break;
				}else if(*(res+k) < 0 && *(res+k) < -pos_max[k]){
					return 0;
				}else if(*(res+k) < 0 && *(res+k) > -pos_max[k]){
					break;
				}
			}
		
		}
	
		int order_coeff = pow(10,i);	
		k = 0;
		for(k; k<=i; k++){
			x += *(res+k) * order_coeff;
			order_coeff /= 10;
		}
			       
        return x;
    }
};


int main(){

	Solution sol;
	cout<<sol.reverse(-2147483412);
	
	return 0;
}
