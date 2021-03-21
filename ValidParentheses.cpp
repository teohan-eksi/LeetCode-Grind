
#include <iostream>

using namespace std;

bool isValid(string s) {
        
/* Given a string s containing just the characters
 *  '(', ')', '{', '}', '[', ']'
 *  determine if the input string is valid.

	An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.

		Example 1:
	
		Input: s = "()"
		Output: true
		
		Example 2:
	
		Input: s = "()[]{}"
		Output: true
		
		Example 3:
		
		Input: s = "(]"
		Output: false
		
		Example 4:
		
		Input: s = "([)]"
		Output: false
		
		Example 5:
		
		Input: s = "{[]}"
		Output: true
		
	Constraints:
	
    1 <= s.length <= 10^4
    s consists of parentheses only '()[]{}'.*/

	string open_p = "([{";
	string close_p = ")]}";

	if(s.length() % 2 != 0){return false;}
	else if(close_p.find(s.front()) != -1 ){return false;}
	else if(open_p.find(s.back()) != -1){return false;}

	int close_i;
	while(s.length() > 0){
        
        if(close_p.find(s.front()) != -1 ){return false;}
	    else if(open_p.find(s.back()) != -1){return false;}
        
		close_i = s.find_first_of(close_p);
		if(close_p.find(s[close_i]) == open_p.find(s[close_i -1])){
			s.erase(close_i - 1, 2);
		}else{
			return false;
		}

	}
	
	return true;
}

int main(){
	cout <<isValid("{{]}");

	return 0;
}
