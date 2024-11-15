#include <iostream>
using namespace std;

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
 
    List() : head(nullptr), tail(nullptr) {}


    ~List() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    
    void push_back(const T& value) {
        Node* newNode = new Node(value);
        if (!tail) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

   
    List operator+(const List& other) const {
        List result;
        for (Node* curr = head; curr; curr = curr->next)
            result.push_back(curr->data);
        for (Node* curr = other.head; curr; curr = curr->next)
            result.push_back(curr->data);
        return result;
    }

   
    List operator*(const List& other) const {
        List result;
        for (Node* curr = head; curr; curr = curr->next) {
            for (Node* otherCurr = other.head; otherCurr; otherCurr = otherCurr->next) {
                if (curr->data == otherCurr->data) {
                    result.push_back(curr->data);
                    break;
                }
            }
        }
        return result;
    }

  
    void print() const {
        for (Node* curr = head; curr; curr = curr->next)
            cout << curr->data << " ";
        cout << endl;
    }
};

int main() {
    List<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);

    List<int> list2;
    list2.push_back(3);
    list2.push_back(4);
    list2.push_back(5);

    List<int> sumList = list1 + list2;
    List<int> intersectList = list1 * list2;

    cout << "List 1: ";
    list1.print();

    cout << "List 2: ";
    list2.print();

    cout << "Sum of lists (+): ";
    sumList.print();

    cout << "Intersection of lists (*): ";
    intersectList.print();

}
