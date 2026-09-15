/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* a, struct ListNode* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    if (a->val <= b->val) {
        a->next = mergeTwoLists(a->next, b);
        return a;
    } else {
        b->next = mergeTwoLists(a, b->next);
        return b;
    }
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0)
        return NULL;

    while (listsSize > 1) {
        int newSize = 0;

        for (int i = 0; i < listsSize; i += 2) {
            if (i + 1 < listsSize)
                lists[newSize++] = mergeTwoLists(lists[i], lists[i + 1]);
            else
                lists[newSize++] = lists[i];
        }

        listsSize = newSize;
    }

    return lists[0];
}