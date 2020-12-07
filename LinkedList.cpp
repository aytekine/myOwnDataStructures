#include <iostream>

template <typename T>
struct Node {
    T data;
    Node *next;
};

template <typename T>
class LinkedList {
public:
    int length_;
    Node<T> *head_;
    Node<T> *tail_;

    LinkedList();
    ~LinkedList();

    bool isEmpty() {
        return this->head_ == nullptr;
    }
    int length() {
        return this->length_;
    }
    void prependNode(T data);
    void appendNode(T data);
    void deleteNodeAt(int idx);
    void deleteNodesByValue(T value);
    void printSequence();
};

template <typename T>
LinkedList<T>::LinkedList() {
    this->length_ = 0;
    this->head_ = nullptr;
    this->tail_ = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    Node<T> *next = this->head_;
    Node<T> *curr = nullptr;
    while (next != nullptr) {
        curr = next;
        next = next->next;
        delete curr;
    }
    std::cout << "List deleted." << std::endl;
}

template <typename T>
void LinkedList<T>::prependNode(T data) {
    Node<T> *node = new Node<T>;
    node->data = data;
    node->next = this->head_;
    if (isEmpty()) {
        this->tail_ = node;
    }
    this->head_ = node;
    this->length_++;
}

template <typename T>
void LinkedList<T>::appendNode(T data) {
    Node<T> *node = nullptr;
    if (isEmpty()) {
        node = new Node<T>;
        this->head_ = node;
    } else {
        node = this->tail_;
        node->next = new Node<T>;
        node = node->next;
    }
    node->data = data;
    node->next = nullptr;
    this->tail_ = node;
    this->length_++;
}

template <typename T>
void LinkedList<T>::deleteNodeAt(int idx) {
    if ((idx < 0) || (idx >= this->length_)) {
        std::cout << "Index " << idx << " exceeds current list length of "
            << this->length_ << '.' << std::endl;
    } else {
        Node<T> *node = this->head_;
        if (idx == 0) {  // Update head
            this->head_ = node->next;
            delete node;
            if (isEmpty()) {
                this->tail_ = nullptr;
            }
        } else {
            for (int i = 0; i < idx - 1; i++) {
                node = node->next;
            }
            Node<T> *tmp = node->next;
            node->next = node->next->next;
            delete tmp;
            if (idx == this->length_ - 1) {  // Update tail to point to end node
                this->tail_ = node;
            }
        }
        this->length_--;
    }
}

template <typename T>
void LinkedList<T>::deleteNodesByValue(T value) {
    int num_deleted = 0;
    Node<T> *curr = this->head_;
    Node<T> *tmp;
    while (!isEmpty() && curr->data == value) {
        tmp = curr;
        this->head_ = curr->next;
        curr = curr->next;
        delete tmp;
        num_deleted++;
    }
    while(!isEmpty() && curr->next != nullptr) {
        if (curr->next->data == value) {
            tmp = curr->next;
            curr->next = curr->next->next;
            delete tmp;
            if (curr->next == nullptr) {  // Update tail
                this->tail_ = curr;
            }
            num_deleted++;
        }
        curr = curr->next;
    }
    if (isEmpty()) {
        this->tail_ = nullptr;
    }
    if (num_deleted) {
        std::cout << "Deleted " << num_deleted
            << " nodes with value " << value << '.' << std::endl;
    } else {
        if (!isEmpty()) {
            std::cout << "Value " << value << " not found in list."
                      << std::endl;
        } else {
            std::cout << "List is empty." << std::endl;
        }
    }
}

template <typename T>
void LinkedList<T>::printSequence() {
    if (isEmpty()) {
        std::cout << "List is empty." << std::endl;
    } else {
        Node<T> *node = this->head_;
        std::cout << "Singly linked list sequence:" << std::endl;
        while (node != nullptr) {
            std::cout << node->data << ' ';
            node = node->next;
        }
        std::cout << std::endl;
    }
}


template <typename T>
void checkTail(LinkedList<T> *list) {
    std::cout << "Tail is set to nullprt: "
        << (list->tail_ == nullptr) << std::endl;
}


template <typename T>
void checkHead(LinkedList<T> *list) {
    std::cout << "Head is set to nullprt: "
        << list->isEmpty() << std::endl;
}


int main() {
    LinkedList<int> *list1 = new LinkedList<int>;
    LinkedList<int> *list2 = new LinkedList<int>;
    LinkedList<int> *list3 = new LinkedList<int>;
    for (int i = 0; i < 10; i++) {
        list1->appendNode(i);
        list2->prependNode(i);
    }
    list1->printSequence();         // 0 1 2 3 4 5 6 7 8 9
    list1->deleteNodeAt(5);
    list1->printSequence();         // 0 1 2 3 4 6 7 8 9
    list1->deleteNodeAt(11);        // Index 11 exceeds current list length of 9.
    list1->printSequence();         // 0 1 2 3 4 6 7 8 9

    list2->printSequence();         // 9 8 7 6 5 4 3 2 1 0
    list2->deleteNodeAt(0);
    list2->printSequence();         // 8 7 6 5 4 3 2 1 0
    list2->deleteNodeAt(8);
    list2->printSequence();         // 8 7 6 5 4 3 2 1
    list2->appendNode(20);
    list2->printSequence();         // 8 7 6 5 4 3 2 1 20
    list2->deleteNodeAt(0);
    list2->deleteNodeAt(0);
    list2->deleteNodeAt(0);
    list2->deleteNodeAt(0);
    list2->printSequence();         // 4 3 2 1 20
    list2->deleteNodeAt(4);
    list2->printSequence();         // 4 3 2 1
    list2->appendNode(12);
    list2->printSequence();         // 4 3 2 1 12
    list2->deleteNodeAt(0);
    list2->deleteNodeAt(0);
    list2->deleteNodeAt(0);
    list2->deleteNodeAt(0);
    list2->deleteNodeAt(0);
    list2->printSequence();         // List is empty.
    checkTail(list2);               // Tail is set to nullprt: 1
    checkHead(list2);               // Head is set to nullprt: 1

    list3->appendNode(10);
    list3->prependNode(8);
    list3->prependNode(8);
    list3->appendNode(10);
    list3->appendNode(5);
    list3->appendNode(8);
    list3->appendNode(10);
    list3->appendNode(10);
    list3->prependNode(5);
    list3->prependNode(5);
    list3->printSequence();         // 5 5 8 8 10 10 5 8 10 10
    list3->deleteNodesByValue(5);   // Deleted 3 nodes with value 5.
    list3->printSequence();         // 8 8 10 10 8 10 10
    list3->deleteNodesByValue(7);   // Value 7 not found in list.
    list3->deleteNodesByValue(8);   // Deleted 3 nodes with value 8.
    list3->deleteNodesByValue(10);  // Deleted 4 nodes with value 10.
    list3->deleteNodesByValue(12);  // List is empty.
    list3->printSequence();         // List is empty.
    checkTail(list3);               // Tail is set to nullprt: 1
    checkHead(list3);               // Head is set to nullprt: 1

    delete list1;
    delete list2;
    delete list3;
}