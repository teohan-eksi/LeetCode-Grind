
/* Implement strStr().

Return the index of the first occurrence of needle in haystack, 
or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? 
This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 
when needle is an empty string. 
This is consistent to C's strstr() and Java's indexOf().

Example 1:

	Input: haystack = "hello", needle = "ll"
	Output: 2

Example 2:

	Input: haystack = "aaaaa", needle = "bba"
	Output: -1

Example 3:

	Input: haystack = "", needle = ""
	Output: 0

Constraints:

    0 <= haystack.length, needle.length <= 5 * 104

	haystack and needle consist of only 
	lower-case English characters.
*/

/* How to solve:
 * return 0 if needle is empty.
 *
 * get the needle length and search the needle as
 * a substring in the haystack, if there is a match
 * return the beginning index otherwise -1.
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
		if(needle == ""){
			return 0;
		}	        

		int needleLength = needle.length();
		//cut the for loop needleLength number of loops
		//before it reaches the end of haystack, otherwise
		//index out of bound error happens.

		if(needleLength > haystack.length()){
			return -1;
		}

		int i;
		for(i = 0; i <= haystack.length() - needleLength; i++){
			if(haystack.substr(i, needleLength) == needle){
				return i;
			}

			cout<<haystack.substr(i, needleLength)<<"\n";
		}
		
		//cout<<haystack[0];

		return -1;
    }
};


int main(){
	cout << "main\n";

	Solution sol;

	string haystack = "leet";
	string needle = "deet";
	cout<<sol.strStr(haystack, needle);
	return 0;
}
