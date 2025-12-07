void removeLoop(Node* head) {
    if (head == NULL || head->next == NULL) return;

    Node* slow = head;
    Node* fast = head;

    // Step 1: detect loop
    bool hasLoop = false;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            hasLoop = true;
            break;
        }
    }

    if (!hasLoop) return; // no loop

    // Step 2: move slow to head
    slow = head;

    // Step 3: find start of loop
    if (slow != fast) {
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;  // remove loop
    } 
    else {
        // Special case: loop starts at head
        while (fast->next != slow) {
            fast = fast->next;
        }
        fast->next = NULL;
    }
}