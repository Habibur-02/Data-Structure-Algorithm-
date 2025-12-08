Node* mergeTwoLists(Node* a, Node* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    if (a->data <= b->data) {
        a->next = mergeTwoLists(a->next, b);
        return a;
    } else {
        b->next = mergeTwoLists(a, b->next);
        return b;
    }
}