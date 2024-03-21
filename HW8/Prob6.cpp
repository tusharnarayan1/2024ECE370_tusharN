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
public:
    List() : head(NULL) {}

    void insert(const T& data, Node<T>* p) {
        if (p != nullptr) {
            Node<T>* newNode = new Node<T>(data, p->next);
            p->next = newNode;
        } else {
            Node<T>* newNode = new Node<T>(data);
            newNode->next = head;
            head = newNode;
        }
    }

    Node<T>* zeroth() {
        return head;
    }

    Node<T>* first() {
        return head->next;
    }

    void print() const {
        Node<T>* p = head;
        while (p) {
            cout << p->element << endl;
            p = p->next;
        }
    }
};

int main() { 
 List<int> list; 
 list.insert(0, list.zeroth()); 
 Node<int>* p = list.first(); 
 for (int i = 1; i <= 10; ++i) 
 { 
 list.insert(i, p); 
 p = p->next; 
 } 
 std::cout << "printing original list" << std::endl; 
 list.print();
}