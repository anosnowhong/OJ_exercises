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
  typedef struct ListNode *PtrtoNode;
  typedef PtrtoNode List;
  typedef PtrtoNode Position;

  //by simply print out the list content you can find that this singly-linked list is implemented without a header
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    Position tmp1, tmp2,pnode, sum_node;
    List result;

    tmp1 = l1;
    tmp2 = l2;
    pnode = result;
    int up = 0, sum;
    //be careful to special input case such as [x,x,5]\n[x,x,5] at the end of each input the sum exceed 10
    while(true){
      //need check if malloc failed
      sum_node = malloc(sizeof(struct ListNode));
      if(tmp1->Next == NULL){
        if(tmp2->Next == NULL){
          break;
        }
        sum = tmp2->val;
      }
      else if(tmp2->Next == NULL){
        sum = tmp1->val;
      }
      else{
        sum = tmp1->val + tmp2->val;
      }

      sum += up;
      if(sum>=10){
        sum_node->val = sum%10;
        up = (sum - sum%10)/10;
      }
      else{
        sum_node->val = sum;
        up=0;
      }

      pnode->next = sum_node;
      pnode = sum_node;
      if(tmp1 != NULL)
        tmp1 = tmp1->next;
      if(tmp2 != NULL)
        tmp2 = tmp2->next;
      if(tmp1 == NULL && tmp2 == NULL && up!=0){
        sum_node = malloc(sizeof(struct ListNode));
        sum_node->val = up;
        pnode->next = sum_node;
      }
    }

    //remove the header of result list
    result = result->next;
    return result;
  }
};
