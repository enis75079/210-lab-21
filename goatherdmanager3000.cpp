/*

lab21: goat herd manager 3000
COMSC-210
Naveen Islam
IDE: vscode

*/
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

const int SIZE = 15;

// goat class
class Goat {
  private:
    int age;
    string name;
    string color;
    string names[SIZE] = {"Senior", "Godlike", "Old", "Mature", "Teen", "Natasha", "Mabel", "Rebecca", "Lina", "Osman", "Donovan", "Abbie", "Madiha", "Keziah", "Sienna"};
    string colors[SIZE] = {"Red", "Orange", "Yellow", "Green", "Blue", "Purple", "Pink", "Brown", "White", "Black", "Gray", "Lime", "Salmon", "Azure", "Maroon"};
  
  public:
    // default constructor
    Goat() {
      age = (rand() % 20) + 1;
      name = names[rand() % 15];
      color = colors[rand() % 15];
    }
    // paramterized constructor with typical 3-element parameter setup
    Goat(int a, string n, string c) {
      age = a;
      name = n;
      color = c;
    }

    // displays the variables in Goat formatted
    void output() const {
      cout << "    " << name << " (" << color << ", " << age << ")" << endl;
    }
};

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class DoublyLinkedList {
private:
    struct Node {
        Goat data;
        Node* prev;
        Node* next;
        Node(Goat val, Node* p = nullptr, Node* n = nullptr) {
            data = val; 
            prev = p;
            next = n;
        }
    };

    Node* head;
    Node* tail;

public:
    // constructor
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    void push_back(Goat value) {
        Node* newNode = new Node(value);
        if (!tail)  // if there's no tail, the list is empty
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(Goat value) {
        Node* newNode = new Node(value);
        if (!head)  // if there's no head, the list is empty
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }

    }

    void insert_after(Goat value, int position) {
        if (position < 0) {
            cout << "Position must be >= 0." << endl;
            return;
        }

        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;

        if (!temp) {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        else
            tail = newNode; // Inserting at the end
        temp->next = newNode;
    }

    void print() {
        Node* current = head;
        if (!current) {
          cout << "List is empty" << endl;
          return;        
        }
        while (current) {
          current->data.output();
          current = current->next;
        }
    }

    void print_reverse() {
        Node* current = tail;
        if (!current) {
          cout << "List is empty" << endl;
          return;
        }
        while (current) {
            current->data.output();
            current = current->prev;
        }
        cout << endl;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Driver program
int main() {
    // to randomize after every run
    srand(time(0));

    DoublyLinkedList list;
    int size = (rand() % 16) + 5;

    for (int i = 0; i < size; ++i) {
      Goat newGoat;
      list.push_back(newGoat);
    } 

    cout << "forward: " << endl;
    // forward 
    list.print();

    cout << "\nbackward: " << endl;
    // print reversed
    list.print_reverse();
    return 0;
}
