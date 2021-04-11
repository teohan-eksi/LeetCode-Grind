#include <iostream>
#include <vector>

using namespace std;

int* findHighest(vector<int>& v, int size){
	int *highest = (int*) malloc(sizeof(int)*2);
	*(highest+1) = 0;

	for(int i = 0; i<size; i++){
		if(v[i] > *(highest + 1)){
			*highest = i; 
			*(highest + 1) = v[i];
		}
	}
	return highest;//index, value.
}

int* findLowest(vector<int>& v, int size){
	int *lowest = (int*) malloc(sizeof(int)*2);
	*(lowest+1) = v[0];
	for(int i = 1; i<size; i++){
		if(v[i] < *(lowest + 1)){
			*lowest = i; 
			*(lowest + 1) = v[i];
		}
	}
	return lowest;//index, value.
}

int profitFinder(vector<int>& prices, int *highest, int *lowest){
	int p1 = 0;
	int p2 = 0;
	int p3 = 0;
	int size = prices.size();

	if(*highest > *lowest){
		return *(highest+1) - *(lowest+1);
			free(highest);
			free(lowest);

	}else if(*highest < *lowest){
		if(*highest >= 1){
			vector <int> v1(prices.begin(), prices.begin() + *(highest) + 1);
			p1 = profitFinder(v1, findHighest(v1, *highest+1), findLowest(v1, *highest+1));
			free(highest);
			free(lowest);
			//			cout<<"p1: "<<v1[2]<<"\n";
		}
		if((*lowest - *highest) > 2){
			vector <int> v2(prices.begin()+ (*highest) + 1, prices.begin() + (*lowest));
			p2 = profitFinder(v2, findHighest(v2, *lowest - *highest -1), findLowest(v2, *lowest - *highest -1));
//			cout<<"p2: "<<p2<<"\n";
			free(highest);
			free(lowest);

		}
		if((size - *lowest) >= 2){
			vector <int> v3(prices.begin()+ (*lowest), prices.begin() + size);
			p3 = profitFinder(v3, findHighest(v3, size - *lowest), findLowest(v3, size - *lowest));
//			cout<<"p3: "<<v3[2]<<"\n";
			free(highest);
			free(lowest);
		}
	}

	return max(max(p1,p2), p3);
}

int maxProfit(vector<int>& prices) {
	int profit = 0;
	int size = prices.size();
	
	if(size == 1){
		return profit;
	}

	int *highest = findHighest(prices, size);
	int *lowest = findLowest(prices,size);

	profit = profitFinder(prices, highest, lowest);

	return profit;
}

int main(){
	
	vector <int> v {4,1,2};

	cout<<maxProfit(v)<<"\n";
	return 0;
}
