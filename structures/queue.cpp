#include "queue.hpp"

template <class T> QueueLinkedList<T>::~QueueLinkedList() {
    while (size > 0) {
        PopFront();
    }
};

template <class T> void QueueLinkedList<T>::PushBack(const T &value) {
    Node *newNode = new Node(value, tail);
    if (size == 0) {
        head = newNode;
    } else {
        tail->next = newNode;
    }
    tail = newNode;
    ++size;
}

template <class T> T QueueLinkedList<T>::PopFront() {
    if (size == 0) {
        std::cout << "List is empty" << std::endl;
        return T();
    }

    Node *temp = head;
    T key = temp->value;
    head = head->next;
    delete temp;
    if (size == 1) {
        tail = nullptr;
    }
    size--;
    return key;
}

template <typename T>
QueueLinkedList<T>::QueueLinkedList(const std::initializer_list<T> &list)
    : QueueLinkedList() {
    for (T value : list) {
        PushBack(value);
    }
}

template <class T>
QueueLinkedList<T>::QueueLinkedList(const QueueLinkedList<T> &queue) {
    size = 0;
    head = tail = nullptr;
    for (Node *cur = queue.head; cur; cur = cur->next) {
        PushBack(cur->value);
    }
}

template <class T>
QueueLinkedList<T>::QueueLinkedList(QueueLinkedList<T> &&queue) {
    size = queue.size;
    head = queue.head;
    tail = queue.tail;
    queue.size = 0;
    queue.head = nullptr;
    queue.tail = nullptr;
}