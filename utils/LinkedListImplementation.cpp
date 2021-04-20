

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
 	ListNode *next;
 	ListNode() : val(0), next(nullptr) {}
 	ListNode(int x) : val(x), next(nullptr) {}
 	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* createLinkedList(vector<int> vals){
	ListNode* head = new ListNode();
	ListNode* current = new ListNode();

	head = current;
	
	int i;	
	for(i = 0; i<vals.size(); i++){
		current->val = vals.at(i);
		ListNode* newNode = new ListNode();	
		current->next = newNode;
		current = newNode;
	}

	return head;
}

void printLL(ListNode* h){
	ListNode* curr = new ListNode();

	curr = h;
	
	while(curr->next != nullptr){
		cout<<curr->val<<"\n";
		curr = curr->next;
	}
}
