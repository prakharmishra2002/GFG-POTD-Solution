class Solution {
 public:
  Node* rotate(Node* head, int k) {
    if (!head || !head->next || !k) return head;
    int len = 1;
    Node* tail = head;
    while (tail->next) tail = tail->next, len++;
    k %= len;
    if (!k) return head;
    Node* newTail = head;
    for (int i = 1; i < k; i++) newTail = newTail->next;
    Node* newHead = newTail->next;
    newTail->next = nullptr;
    tail->next = head;
    return newHead;
  }
};
