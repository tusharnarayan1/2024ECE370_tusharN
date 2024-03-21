#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    T element;
    Node *next;

    Node(const T& e = T(), Node<T>* n = nullptr) : element(e), next(n) {}
};

template<class T>
class List {
private:
    Node<T> *head;

    Node<T>* findPrevious(const T& data) const { // This method should also be const
        Node<T>* p = head; // Now it is safe to start from the head as we have a dummy node
        while (p->next != nullptr) {
            if (p->next->element == data)
                return p;
            p = p->next;
        }
        return nullptr;
    }

public:
    List() : head(new Node<T>()) {} // Updated with dummy node as zeroth element

    List(const List& other) : head(new Node<T>()) {
        Node<T>* currentOther = other.head->next;
        Node<T>* currentThis = head;
        while (currentOther != nullptr) {
            currentThis->next = new Node<T>(currentOther->element);
            currentThis = currentThis->next;
            currentOther = currentOther->next;
        }
    }

    List& operator=(const List& other) {
        if (this != &other) {
            makeEmpty();
            Node<T>* newHead = new Node<T>();

            Node<T>* currentOther = other.head->next;
            Node<T>* currentThis = newHead;
            while (currentOther != nullptr) {
                currentThis->next = new Node<T>(currentOther->element);
                currentThis = currentThis->next;
                currentOther = currentOther->next;
            }

            delete head;
            head = newHead;
        }
        return *this;
    }

    ~List() {
        makeEmpty();
        delete head;
    }

    void insert(const T& data, Node<T>* p) {
        if (p == nullptr) { p = head; } // Zeroth node by default
        p->next = new Node<T>(data, p->next);
    }

    Node<T>* zeroth() const { return head; }

    Node<T>* first() const { return head->next; }

    void print() const {
        Node<T>* p = first();
        while (p != nullptr) {
            cout << p->element << endl;
            p = p->next;
        }
    }

    void remove(const T& data) {
        Node<T>* p = findPrevious(data);
        if (p != nullptr) {
            Node<T>* tmp = p->next;
            if (tmp != nullptr) {
                p->next = tmp->next;
                delete tmp;
            }
        }
    }

    void makeEmpty() {
        while (head->next != nullptr) {
            Node<T>* tmp = head->next;
            head->next = head->next->next;
            delete tmp;
        }
    }

    Node<T>* find(const T& data) const {
        Node<T>* p = first();
        while (p != nullptr && p->element != data) {
            p = p->next;
        }
        return p;
    }
};

int main() {
    List<int> list;
    Node<int>* p = list.zeroth();
    for (int i = 1; i <= 10; ++i) {
        list.insert(i, p);
        p = p->next;
    }
    cout << "Printing original list:" << endl;
    list.print();

    List<int> list2 = list;
    cout << "Printing copy constructed list:" << endl;
    list2.print();

    List<int> list3;
    list3 = list;
    cout << "Printing assigned list:" << endl;
    list3.print();

    list.makeEmpty();
    cout << "Printing emptied list:" << endl;
    list.print();

    for (int i = 0; i <= 10; ++i) {
        if (i % 2 == 0) {
            if (list2.find(i) == nullptr) {
                cout << "Could not find element " << i << endl;
            }
        } else {
            if (list2.find(i) != nullptr) {
                cout << "Found element " << i << endl;
            }
        }
    }
    return 0;
}