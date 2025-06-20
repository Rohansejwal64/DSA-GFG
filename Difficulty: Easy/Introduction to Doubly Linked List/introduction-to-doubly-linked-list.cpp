// User function Template for C++

/*
class Node{
public:
    Node* prev;
    int data;
    Node* next;

    Node()
    {
        prev = NULL;
        data = 0;
        next = NULL;
    }

    Node(int value)
    {
        prev = NULL;
        data = value;
        next = NULL;
    }
};*/

class Solution {
  public:
     Node* constructDLL(vector<int>& arr) {
        if (arr.empty()) return nullptr; // handle empty array

        Node* head = new Node(arr[0]); // create first node
        Node* temp = head;

        for (int i = 1; i < arr.size(); i++) {
            Node* newNode = new Node(arr[i]); // create new node
            temp->next = newNode;             // link current to new
            newNode->prev = temp;             // link new to current
            temp = newNode;                   // move temp to new
        }

        return head;
    }
};