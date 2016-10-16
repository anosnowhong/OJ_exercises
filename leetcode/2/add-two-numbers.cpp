/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {} //Init a listnode with a val and null pointer.
 * };
 */
class Solution {
	public:
		//by simply print out the list content you can find that this singly-linked list is implemented without a header
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			ListNode* result = new ListNode(0);//header has a value 0
			ListNode* tmp = new ListNode(0);
			ListNode* tmp2 = new ListNode(0);
			ListNode* tmp3 = new ListNode(0);

			tmp = l1;//->next;
			tmp2 = l2;//->next;
			tmp3 = result;
			int up = 0;
			int sum;
			ListNode* sum_node;

			//be careful to special input case such as [x,x,5]\n[x,x,5] at the end of each input the sum exceed 10
			do{
				if(tmp == NULL)
					sum = tmp2->val;
				else if(tmp2 == NULL)
					sum = tmp->val;
				else
					sum = tmp->val + tmp2->val;

				sum += up;

				if(sum >= 10){
					sum_node = new ListNode(sum%10);
					up = (sum - sum%10) / 10;
				}
				else{
					sum_node = new ListNode(sum);
					up=0;
				}
				tmp3->next = sum_node;
				tmp3 = sum_node;

				//be careful that NULL doesn't has "next" property
				if(tmp != NULL)
					tmp = tmp->next;
				if(tmp2 != NULL)
					tmp2 = tmp2->next;
				if(tmp == NULL && tmp2 == NULL && up!=0){
					sum_node = new ListNode(up);
					tmp3->next = sum_node;
				}

			}while(tmp != NULL || tmp2 != NULL);

			//remove the header of result list
			result = result->next;
			return result;
		}
};