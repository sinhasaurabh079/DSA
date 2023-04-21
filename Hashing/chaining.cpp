#include <iostream>
using namespace std;

// Linked List node

class Node
{
public:
    int data;
    Node *next;
};

// Hash Table
class HashTable
{
public:
    Node **HT;
    HashTable();
    int hash(int ke);
    void Insert(int key);
    int Search(int key);
    ~HashTable();
};

HashTable::HashTable()
{
    HT = new Node *[10];
    for (int i = 0; i < 10; i++)
    {
        HT[i] = nullptr;
    }
}

int HashTable::hash(int key)
{
    return key % 10;
}

void HashTable::Insert(int key)
{
    int hidx = hash(key);
    Node *t = new Node;
    t->data = key;
    t->next = NULL;

    // case : no nodes in linked list
    if (HT[hidx] == nullptr)
        HT[hidx] = t;
    else
    {
        Node *p = HT[hidx];
        Node *q = HT[hidx];
        // traverse to find insert position
        while (p && p->data < key)
        {
            q = p;
            p = p->next;
        }
        // case: insert position is first
        if (q == HT[hidx])
        {
            t->next = HT[hidx];
            HT[hidx] = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int HashTable ::Search(int key)
{
    int hIdx = hash(key);
    Node *p = HT[hIdx];
    while (p)
    {
        if (p->data == key)
        {
            return p->data;
        }
        p = p->next;
    }
    return -1;
}

HashTable::~HashTable() {
	for (int i=0; i<10; i++){
		Node* p = HT[i];
		while (HT[i]){
			HT[i] = HT[i]->next;
			delete p;
			p = HT[i];
		}
	}
	delete [] HT;
}

int main() {
	int A[] = {16, 12, 25, 39, 6, 122, 5, 68, 75};
	int n = sizeof(A)/sizeof(A[0]);
	HashTable H;
	for (int i=0; i<n; i++){
		H.Insert(A[i]);
	}
	cout << "Successful Search" << endl;
	int key = 6;
	int value = H.Search(key);
	cout << "Key: " << key << ", Value: " << value << endl;
	cout << "Unsuccessful Search" << endl;
	key = 95;
	value = H.Search(key);
	cout << "Key: " << key << ", Value: " << value << endl;

	return 0;
}
