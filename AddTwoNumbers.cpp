/*
  --------------------QUESTION STATEMENT---------------------
  You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains 
  a single digit. Add the two numbers and return the sum as a linked list.

  You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/



/**************************************This Solution is correct only for LinkedList of 34 length********************************************/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int countL1 = 0;
        int countL2 = 0;
        ListNode* head = l1;
        while(head != NULL){
            ++countL1;
            head = head->next;
        }
        head = l2;
        while(head != NULL){
            ++countL2;
            head = head->next;
        }
        // cout<<countL1<<" "<<countL2;
        // if(countL1 == 1 && countL2 == 1){
        //  head = new ListNode(l1->val + l2->val);
        //  return head;   
        // }
        int arr1[countL1];
        int arr2[countL2];

        head = l1;
        int index = 0;
        while(head && index < countL1){
            arr1[index] = head->val;
            ++index;
            head = head->next;
        }
        index = 0;
        head = l2;
        while(head && index < countL2){
            arr2[index] = head->val;
            ++index;
            head = head->next;
        }
        // cout<<arr1[0]<<" "<<arr2[0];
        long long int firstValue = 0;
        if(countL1 == 1) {
            firstValue = arr1[0];
        }
        else{
            for(int i = countL1 - 1; i > 0; i--){
                firstValue =  firstValue + arr1[i];
                firstValue = firstValue * 10;
                if(i == 1){ firstValue += arr1[0]; }
            }

        }
        long long int secondValue = 0;
        if(countL2 == 1){
            secondValue = arr2[0];
        }
        else{
            for(int i = countL2 - 1; i > 0; i--){
                secondValue += arr2[i];
                secondValue *= 10;
                if(i == 1){ secondValue += arr2[0]; }
            }
        }
        
        // cout<<firstValue<<" "<<secondValue;
        long long int finalValue = firstValue + secondValue;
        cout<<finalValue;

        ListNode *temp;
        head = NULL;
        int testVal = finalValue;
        if(finalValue != 0){
            while(finalValue){
            int rem = finalValue % 10;
            // cout<<finalValue<<" ";

            if(head == NULL){
                head = new ListNode(rem);
                temp = head;
            }
            else{
                ListNode *test = new ListNode(rem);
                temp->next = test;
                temp = test;
            }
            finalValue = finalValue / 10;
            }
        }
        else if(finalValue >= 0 && finalValue <= 9){
            // cout<<finalValue;
            head = new ListNode(finalValue);
        }
        
        return head;
    }
        
    
};
