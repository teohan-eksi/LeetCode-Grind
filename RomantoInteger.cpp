#include <iostream>

using namespace std;

int romanToInt(string s) {
	/* Symbol       Value
		I             1
		V             5
		X             10
		L             50
		C             100
		D             500
		M             1000
	*
	*
	There are six instances where subtraction is used:

    I can be placed before V (5) and X (10) to make 4 and 9. 
    X can be placed before L (50) and C (100) to make 40 and 90. 
    C can be placed before D (500) and M (1000) to make 400 and 900.
	*
	* algo:
	*
	*/

	int res = 0;
	int s_len = s.length();

	while(s_len > 0){	

			if(s.back() == 'I'){//get last char
				res++;
				s.pop_back(); //pop last char
				s_len--;
			}else if(s_len >= 2 && s.substr(s_len -2, 2) == "IV"){ //get the last two chars
				res += 4;
				s.erase(s_len -2, 2);//erase the last two
				s_len -= 2;
			}else if(s.back() == 'V'){
				res += 5;
				s.pop_back();
				s_len--;
			}else if(s_len >= 2 && s.substr(s_len -2, 2) == "IX"){
				res += 9;
				s.erase(s_len -2, 2);//erase the last two
				s_len -= 2;
			}else if(s.back() == 'X'){
				res += 10;
				s.pop_back();
				s_len--;
			}else if(s_len >= 2 && s.substr(s_len -2, 2) == "XL"){
				res += 40;
				s.erase(s_len -2, 2);//erase the last two
				s_len -= 2;
			}else if(s_len >= 2 && s.substr(s_len -2, 2) == "XC"){
				res += 90;
				s.erase(s_len -2, 2);//erase the last two
				s_len -= 2;
			}else if(s_len >= 2 && s.substr(s_len -2, 2) == "CD"){
				res += 400;
				s.erase(s_len -2, 2);//erase the last two
				s_len -= 2;
			}else if(s_len >= 2 && s.substr(s_len -2, 2) == "CM"){
				res += 900;
				s.erase(s_len -2, 2);//erase the last two
				s_len -= 2;
			}else if(s.back() == 'L'){
				res += 50;
				s.pop_back();
				s_len--;
			}else if(s.back() == 'C'){
				res += 100;
				s.pop_back();
				s_len--;
			}else if(s.back() == 'D'){
				res += 500;
				s.pop_back();
				s_len--;
			}else if(s.back() == 'M'){
				res += 1000;
				s.pop_back();
				s_len--;
			}
	}
	
	return res;
}

int main(){

	cout<<romanToInt("MCMXCIV");
	return 0;
}
