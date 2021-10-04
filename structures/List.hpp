struct Node {
    int value;
    Node *next;
    Node(int v) : value(v), next(nullptr) {}
};

class List {
  private:
    Node *listStart = new Node(1);
    Node *listEnd = nullptr;

  public:
    void addToList(int v) {
        Node *n = new Node(v);
        if (listStart->next == nullptr) {
            n->next = listStart;
            listStart = n;
            return;
        }
        Node *parent = listStart;
        while (parent->next->next != nullptr) {
            parent = parent->next;
        }
        n->next = parent->next;

        parent->next = n;
    }

    Node *getByIndex(int i) {
        Node *result = listStart;
        while (i) {
            result = result->next;
            --i;
        }
        return result;
    }

    void insert(Node *n, int v) {
        Node *node = new Node(v);
        node->next = n->next;
        n->next = node;
    }

    void insert(int position, int v) {
        Node *n = new Node(v);
        if (!position) {
            n->next = listStart;
            listStart = n;
            return;
        }

        Node *current = listStart;
        while (position - 1) {
            current = current->next;
            position--;
        }
        insert(current, v);
    }
    void remove(Node *n) {
        n->value = n->next->value;
        Node *tmp = n->next;
        n->next = n->next->next;
        delete tmp;
    }
    void remove(int v) {
        Node *current = listStart;
        while (current->next && current->value != v) {
            current = current->next;
        }
        if (current->next) {
            remove(current);
        }
    }
};