class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        // Create a dummy node to serve as the starting point of the merged list
        Node dummy(0);
        Node* tail = &dummy;

        // Traverse both lists and merge them in sorted order
        while (head1 != NULL && head2 != NULL) {
            if (head1->data <= head2->data) {
                tail->next = head1;
                head1 = head1->next;
            } else {
                tail->next = head2;
                head2 = head2->next;
            }
            tail = tail->next;
        }

        // If either list has remaining nodes, append them to the merged list
        if (head1 != NULL) {
            tail->next = head1;
        } else {
            tail->next = head2;
        }

        // Return the head of the merged list
        return dummy.next;
    }
};
