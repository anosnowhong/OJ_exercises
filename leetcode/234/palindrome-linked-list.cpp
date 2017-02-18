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
    ListNode* reverseList(ListNode* head){
        ListNode* end = nullptr;
        while(head){
            ListNode* tmp  = head->next;
            head->next = end;
            end = head;
            head = tmp;
        }
        return end;
    }

    bool isPalindrome(ListNode* head) {
        if(head == nullptr||head->next == nullptr) return true;

        ListNode* new_head = new ListNode(0);
        new_head->next = head;
        ListNode* ptr1 = new_head;
        ListNode* ptr2 = new_head;

        while(ptr2->next){
            ptr2 = ptr2->next;
            if(ptr2->next)
                ptr2 = ptr2->next;
            ptr1 = ptr1->next;
        }

        ptr1 = ptr1->next;
        ptr1 = reverseList(ptr1);


        ptr2 = head;
        while(ptr1){
            if(ptr1->val == ptr2->val){
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            else
                return false;
        }

        return true;
    }
};
