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

// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         vector<int> num;
//         for(int i=0;i<lists.size();i++)
//         {
//             ListNode* temp=lists[i];
//             while(temp)
//             {
//                 num.push_back(temp->val);
//                 temp=temp->next;
//             }

//         }  
//         sort(num.begin(),num.end());
//         ListNode* ans=NULL;
//         ListNode* tail=NULL;
//         for(int i=0;i<num.size();i++)
//         {
//             if(ans==NULL)
//             {
//                 ListNode* newNode= new ListNode(num[i]);
//                 ans=newNode;
//                 tail=newNode;
//             }
//             else{
//                 ListNode* newNode= new ListNode(num[i]);
//                 tail->next=newNode;
//                 tail=tail->next;
//             }
//         }
//         return ans;
//     }
// };




class Solution {

    ListNode* mergeTwo(ListNode* l1,ListNode* l2) {

        if(!l1) return l2;
        if(!l2) return l1;

        if(l1->val <= l2->val) {
            
            l1->next = mergeTwo(l1->next,l2);
            return l1;
        }

        else{

            l2->next = mergeTwo(l1,l2->next);
            return l2;
        }

        return NULL;
    }

    ListNode* partition(int start,int end,vector<ListNode*>& lists) {

        if(start>end)   return NULL;

        if(start==end)  return lists[start];

        int mid = start + (end-start)/2;

        ListNode* L1 = partition(start,mid,lists);
        ListNode* L2 = partition(mid+1,end,lists);

        return mergeTwo(L1,L2);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        return partition(0,k-1,lists);
    }
};