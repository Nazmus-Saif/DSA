#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

// Node structure of the skip list
struct Node {
    int value;
    Node** forward;
    Node(int level, int value) {
        this->value = value;
        forward = new Node*[level + 1];
        for (int i = 0; i <= level; i++) {
            forward[i] = nullptr;
        }
    }
};

// Skip List class
class SkipList {
    int maxLevel;
    float probability;
    int level;
    Node* header;

public:
    SkipList(int maxLevel, float probability);
    int randomLevel();
    Node* createNode(int value, int level);
    void insertElement(int value);
    void displayList();
};

// Constructor
SkipList::SkipList(int maxLevel, float probability) {
    this->maxLevel = maxLevel;
    this->probability = probability;
    level = 0;
    header = new Node(maxLevel, -1);
}

// Create random level for node
int SkipList::randomLevel() {
    int lvl = 0;
    while (((float)std::rand() / RAND_MAX) < probability && lvl < maxLevel) {
        lvl++;
    }
    return lvl;
}

// Create new node
Node* SkipList::createNode(int value, int level) {
    Node* n = new Node(level, value);
    return n;
}

// Insert element into skip list
void SkipList::insertElement(int value) {
    Node* current = header;
    Node* update[maxLevel + 1];
    for (int i = level; i >= 0; i--) {
        while (current->forward[i] != nullptr && current->forward[i]->value < value) {
            current = current->forward[i];
        }
        update[i] = current;
    }

    current = current->forward[0];

    if (current == nullptr || current->value != value) {
        int rlevel = randomLevel();

        if (rlevel > level) {
            for (int i = level + 1; i < rlevel + 1; i++) {
                update[i] = header;
            }
            level = rlevel;
        }

        Node* n = createNode(value, rlevel);

        for (int i = 0; i <= rlevel; i++) {
            n->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = n;
        }

        cout << "Successfully inserted key " << value << "\n";
    }
}

// Display the skip list
void SkipList::displayList() {
    cout << "\n*****Skip List*****" << "\n";
    for (int i = 0; i <= level; i++) {
        Node* node = header->forward[i];
        cout << "Level " << i << ": ";
        while (node != nullptr) {
            cout << node->value << " ";
            node = node->forward[i];
        }
        cout << "\n";
    }
}

// Main function
int main() {
    srand((unsigned)time(0));

    SkipList lst(3, 0.5);

    lst.insertElement(3);
    lst.insertElement(6);
    lst.insertElement(7);
    lst.insertElement(9);
    lst.insertElement(12);
    lst.insertElement(19);
    lst.insertElement(17);
    lst.insertElement(26);
    lst.insertElement(21);
    lst.insertElement(25);

    lst.displayList();

    return 0;
}
