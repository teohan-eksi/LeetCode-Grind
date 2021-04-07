
#include <iostream>

using namespace std;

/* Merge two sorted linked lists 
 * and return it as a sorted list. 
 * The list should be made by 
 * splicing together the nodes of the first two lists.
 *
 * 1->2->4 +  1->3->4
 *
 * 1->1->2->3->4->
 *
 *
	Constraints:

    The number of nodes in both lists is in the range [0, 50].
    -100 <= Node.val <= 100
    Both l1 and l2 are sorted in non-decreasing order.
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printLL(ListNode *head){
	cout<<"printing starts: \n";
	while(head != 0){		
		cout<<head->val<<"\n";
		head = head->next;
	}
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

		ListNode *head = new ListNode();
		head = nullptr;

		if(l1 == 0 && l2 == 0){
				return head;
		}else if(l1 != 0 && l2 == 0){
			head = l1;
			return head;
		}else if(l1 == 0 && l2 != 0){
			head = l2;
			return head;
		}// else continue to the while loop with two heads that are not null.

		head = new ListNode(); //initialize first to fill it.
		//since they are in non decreasing order, 
		//their first elements is automatically the smallest in the list.
		ListNode *prev_node = new ListNode();
		if(l1->val <= l2->val){
			head->val = l1->val; //first value in the ordered list
			l1 = l1->next;//no need to compare the smallest number again.
		}else{
			head->val = l2->val; //first value in the ordered list
			l2 = l2->next;
		}
		prev_node = head;
		//now that we got the smallest number,
		//go on and search for the second smallest number or equal number 
		//compared to the first smallest number.
		//insert your findings to the list that will be returned.
		ListNode *current_node;
		while(true){
			if(l1 != 0 && l2 != 0){
				current_node = new ListNode();
				prev_node->next = current_node;
				if(l1->val <= l2->val){
					current_node->val = l1->val;
					l1 = l1->next;
				}else{
				current_node->val = l2->val;
					l2 = l2->next;
				}
				prev_node = current_node;
			}else if(l1 != 0 && l2 == 0){
				current_node = new ListNode();
				prev_node->next = current_node;
				current_node->val = l1->val;
				l1 = l1->next;
				prev_node = current_node;
			}else if(l1 == 0 && l2 != 0){
				current_node = new ListNode();
				prev_node->next = current_node;
				current_node->val = l2->val;
				l2 = l2->next;
				prev_node = current_node;
			}else{//both nodes are tails, so they point to nullptr.
				prev_node->next = nullptr;
				return head;
			}
		}
    }
};

ListNode* populateLL(int val_arr[], int size){
	ListNode *pop_ll_head;
	
	if(size == 0){
		pop_ll_head = nullptr;
		return pop_ll_head;
	}

	ListNode *pop_node_current;
	ListNode *pop_node_prev;

	int i = 0;
	for(i; i<size; i++){
		pop_node_current = new ListNode(val_arr[i]);
		
		if(i==0){
			pop_ll_head = pop_node_current;
		//	cout<<pop_ll_head->val<<"\n";
			pop_node_prev = pop_ll_head;
		}else{
			pop_node_prev->next = pop_node_current;
			pop_node_prev = pop_node_current;
		//	cout<<pop_node_current->val<<"\n";
		}	
	
	}
	//defining the tail as:
	pop_node_current->next = nullptr;

	return pop_ll_head;
}


int main(){

	int val_arr[] = {};
	int val_arr2[] = {0};

	ListNode *l1 = populateLL(val_arr, 0);
	ListNode *l2 = populateLL(val_arr2, 1);

	Solution sol;
	printLL(sol.mergeTwoLists(l1, l2));		
//	sol.mergeTwoLists(l1, l2);
	
	return 0;
}
