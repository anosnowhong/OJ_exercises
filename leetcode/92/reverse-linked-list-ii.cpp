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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        //if(m == n) return head;

        int count=0;
        ListNode* new_head = new ListNode(0);
        new_head->next = head;
        ListNode* pre = new_head;
        while(count+1 < m){
            pre = pre->next;
            count++;
        }
        ListNode* cur = pre->next;

        //how to make a loop
        /*  IF m = 3; n = 5;
        1->2->3->4->5->6
        1. stop at position 2.
        2. 3 point to 5
        3. 4 point to 3
        4. 2 point to 4

        5. 3 point to 6
        6. 5 point to 4
        7. 2 point to 5
        */

        while(count+1 < n){
            ListNode* tmp = cur->next;
            //out
            cur->next = tmp->next;
            //link
            tmp->next = pre->next;
            //in
            pre->next = tmp;

            count++;
        }
        return new_head->next;
    }
};
