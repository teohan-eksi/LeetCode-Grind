

/* 
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

	Input: strs = ["flower","flow","flight"]
	Output: "fl"

Example 2:

	Input: strs = ["dog","racecar","car"]
	Output: ""
Explanation: There is no common prefix among the input strings.

Constraints:

    0 <= strs.length <= 200
    0 <= strs[i].length <= 200
    strs[i] consists of only lower-case English letters.
 */

/* My approach:
 * let me first find the shortest word.
 * assuming that i will stumble upon a common prefix,
 * compare the last letter of the shortest word with the corresponding
 * letter of the words in the rest of the vector.
 * if no match is found between the words, immediately look for another match
 * with the previous letter until all of them matches or no matches found in 
 * that case return "", otherwise return the prefix.
 * */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		
		if(strs.size() == 0 || strs[0] == ""){
			return "";
		}

		//finding the shortest word
		int i;
		int indexShortestWord = 0;
		for(i = 1; i < strs.size(); i++){
			if(strs[i] == ""){
				return"";
			}

			if(strs[i].size() < strs[i-1].size()){
				indexShortestWord = i;
			}
		}
		string shortestWord = strs[indexShortestWord];
		
		//find the common prefix
		i = 0;
		int lookUpInd = shortestWord.size() - 1;
		int lastMatch = lookUpInd;
		while(i < strs.size()){
			if(strs[i][lookUpInd] != shortestWord[lookUpInd]){
				lastMatch = lookUpInd - 1;
			}
			lookUpInd--;
		
			if(lookUpInd == -1){
				i++;
				lookUpInd = shortestWord.size() - 1;
			}

			if(lastMatch < 0){
				return "";
			}
		}

		return shortestWord.substr(0, lastMatch + 1);
	}
};

int main(){
	cout << "main\n";

	Solution sol;

	vector<string> strs = {"dog","racecar","car"};

	cout<<sol.longestCommonPrefix(strs);

	return 0;
}


