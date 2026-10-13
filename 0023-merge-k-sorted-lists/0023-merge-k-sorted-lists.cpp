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
    ListNode* sortedMerge(ListNode* head1, ListNode* head2) {
        if (!head1) {
            return head2;
        }
        if (!head2) {
            return head1;
        }

        ListNode* head = new ListNode(0);
        ListNode* tail = head;
        while (head1 && head2) {
            if (head1->val <= head2->val) {
                tail->next = head1;
                head1 = head1->next;
                tail = tail->next;
                tail->next = NULL;

            } else {
                tail->next = head2;
                head2 = head2->next;
                tail = tail->next;
                tail->next = NULL;
            }
        }
        if (!head1) {
            tail->next = head2;

        } else {
            tail->next = head1;
        }

        ListNode* temp = head;
        head = head->next;
        delete temp;

        return head;
    }

    ListNode* merge(vector<ListNode*>& arr, int start, int end) {

        if (start == end) {
            return arr[start];
        }

        int mid = start + (end - start) / 2;
        ListNode* head1 = merge(arr, start, mid);
        ListNode* head2 = merge(arr, mid + 1, end);

        return sortedMerge(head1, head2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if (!lists.size()) {
            return NULL;
        }

        return merge(lists, 0, lists.size() - 1);
    }
};