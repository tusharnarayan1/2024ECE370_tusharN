#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    T element;
    Node *next;

    Node(const T& e = T(), Node<T>* n = nullptr)
        : element(e), next(n) {}
};

template<class T>
class List {
private:
    Node<T> *head;

    Node<T>* findPrevious(const T& data) {
        Node<T>* p = zeroth();
        while (p->next) {
            if (p->next->element == data)
                return p;
            p = p->next;
        }
        return NULL;
    }

public:
    List() : head(nullptr) {}

    List(const List& other) : head(nullptr) {
        Node<T>** lastPtr = &head;
        for (Node<T>* current = other.head; current != nullptr; current = current->next) {
            *lastPtr = new Node<T>(current->element);
            lastPtr = &((*lastPtr)->next);
        }
    }

    List& operator=(const List& other) {
        if (this != &other) {
            makeEmpty();
            Node<T>** lastPtr = &head;
            for (Node<T>* current = other.head; current != nullptr; current = current->next) {
                *lastPtr = new Node<T>(current->element);
                lastPtr = &((*lastPtr)->next);
            }
        }
        return *this;
    }

    ~List() {
        makeEmpty();
    }

    void insert(const T& data, Node<T>* p) {
        if (p != nullptr) {
            Node<T>* newNode = new Node<T>(data, p->next);
            p->next = newNode;
        } else {
            head = new Node<T>(data, head);
        }
    }

    Node<T>* zeroth() {
        return head;
    }

    Node<T>* first() {
        return head ? head->next : nullptr;
    }

    void print() const {
        Node<T>* p = head;
        while (p != nullptr) {
            cout << p->element << endl;
            p = p->next;
        }
    }

    void remove(const T& data){
        Node<T>* p = findPrevious(data);
        if (p != nullptr && p->next != nullptr) {
            Node<T>* tmp = p->next;
            p->next = tmp->next;
            delete tmp;
        }
    } // Missing closing brace is now added.

    void makeEmpty() {
        while (head != nullptr) {
            Node<T>* current = head;
            head = head->next;
            delete current;
        }
    }
};

int main() { 
    List<int> list;
    list.insert(0, list.zeroth());
    Node<int>* p = list.zeroth();
    for (int i = 1; i <= 10; ++i) {
        list.insert(i, p);
        p = p->next;
    }
    cout << "printing original list" << endl;
    list.print();


    List<int> list2 = list; // This now invokes the copy constructor.
    cout << "printing copy constructed list" << endl;
    list2.print();

    List<int> list3;
    list3 = list; // This now invokes the copy assignment operator.
    cout << "printing assigned list" << endl;
    list3.print();

    list.makeEmpty(); // This empties the list.
    cout << "printing emptied list" << endl;
    list.print();

    return 0;
}