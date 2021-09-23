#pragma once
#include <iostream>
#include <string>
template <class T> class QueueLinkedList {
  public:
    struct Node {
        T value;

      private:
        Node *previous;
        Node *next;
        Node() = default;
        Node(const T &_value, Node *_previous = nullptr, Node *_next = nullptr)
            : value(_value), previous(_previous), next(_next) {}

      public:
        ~Node() = default;
        friend struct QueueLinkedList;
    };

    QueueLinkedList() : size(0), head(nullptr), tail(nullptr) {}
    ~QueueLinkedList();
    QueueLinkedList(const std::initializer_list<T> &list);
    QueueLinkedList(const QueueLinkedList<T> &);
    QueueLinkedList(QueueLinkedList<T> &&);

    void PushBack(const T &value);
    T PopFront();
    bool IsEmpty() { return size == 0; };

    Node *operator[](size_t);
    QueueLinkedList<T> &operator=(const QueueLinkedList<T> &);
    QueueLinkedList<T> &operator=(QueueLinkedList<T> &&);

  private:
    size_t size;
    Node *head;
    Node *tail;
};
