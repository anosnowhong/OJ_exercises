/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 

class Solution {
public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode(INT_MIN);
    ListNode* headbk=head;

    while(l1&&l2){//if one of the list is finished, we don't need to check further
      if(l1->val<l2->val){
        head->next=l1;
        l1 = l1->next;
      }
      else{
        head->next=l2;
        l2 = l2->next;
      }
      head = head->next;
    }
    //once a list has been traversed(listnode==NULL),we still need to link head and the remainning list.
    if(l1) head->next = l1;
    else head->next = l2;

    return headbk->next;
  }
};
