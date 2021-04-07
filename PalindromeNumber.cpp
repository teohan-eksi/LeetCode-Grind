#include <iostream>
#include <climits>

using namespace std;

bool isPalindrome(int x){

	if(x < 0){return false;}
	else if(x>= 10 && x%10 == 0){return false;}
	
	int tmp_x = x;
	int res = 0;
	int last_dig;
	while(tmp_x > 0){
		last_dig = tmp_x%10;
        
        if(res > INT_MAX/10 || (res == INT_MAX/10 && last_dig > 7)){
			return false;
		}
		tmp_x =(tmp_x - last_dig) / 10;
//		cout<<"tmp: "<<tmp_x<<"\n";
//		cout<<"l: "<<last_dig<<"\n";	
        res = res * 10 + last_dig;
//		cout<<res<<"\n";
    }
		
	if(res == x){
		return true;
	}else{
		return false;
	}    
}
	
int main(){
	cout<<"\n"<<isPalindrome(121); 
	
	return 0;
}
