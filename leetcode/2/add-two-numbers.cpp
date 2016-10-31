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
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		    ListNode* result = new ListNode(0);
		    ListNode* rpoint;
		    int sum;

		    if(l1==NULL&&l2!=NULL) return l2;
		    if(l2==NULL&&l1!=NULL) return l1;
		    if(l1==NULL&&l2==NULL) return result;

		    sum = l1->val+l2->val;
		    result->val = sum%10;
		    sum /= 10;
		    rpoint = result;

		    while(l1->next!=NULL||l2->next!=NULL){
		        if(l1->next!=NULL&&l2->next==NULL){
		            sum += l1->next->val;
		            l1 = l1->next;
		        }
		        else if(l1->next==NULL&&l2->next!=NULL){
		            sum += l2->next->val;
		            l2 = l2->next;
		        }
		        else if(l1->next!=NULL&&l2->next!=NULL){
		            sum += l1->next->val + l2->next->val;
		            l1 = l1->next; l2 = l2->next;
		        }
		        if(sum>=10){
		           ListNode *rnode = new ListNode(sum%10);
		            sum /= 10;
		            rpoint->next = rnode;
		            rpoint = rpoint->next;
		        }else{
		            ListNode *rnode = new ListNode(sum);
		            sum /= 10;
		            rpoint->next = rnode;
		            rpoint = rpoint->next;
		        }
		    }
		    if(sum!=0){
		        ListNode *rnode = new ListNode(sum);
		        rpoint->next = rnode;
		    }
			return result;
		}
};
