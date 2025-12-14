#include <fstream>
#include <iostream>
#include <string>


class Node
{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class CircularDoublyLinkedList
{
public:
    Node* head;

    CircularDoublyLinkedList() : head(nullptr) {}

    void insert(int val)
    {
        Node* newNode = new Node(val);
        if(!head)
        {
            head = newNode;
            head->next = head;
            head->prev = head;
        }
        else
        {
            Node* tail = head->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
    }

void setHeadToValue(Node*& head, int value)
{
    if (!head) return;

    Node* curr = head;

    do
    {
        if(curr->data == value)
        {
            head = curr;
            return;
        }
        curr = curr->next;
    } 
    while(curr != head);
}

    void display()
    {
        if(!head)
        {
          std::cout<<"Nothing to diplay!\n";
          return;
        }
        Node* temp = head;
        do {
            std::cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        std::cout << std::endl;
    }
    void move_forward(Node* head)
    {
      if(!head) return 0;
      
      Node* curr = head;

      do
      {
        std::cout<<curr<<"\n";
        curr=curr->next;
      }
      while(curr->next!=head);
    }

    void move_backwards(Node* head)
    {

    }
};


int main()
{


  //creating our lock using CircularDoublyLinkedList
  CircularDoublyLinkedList list;
  for (int i = 1; i <= 99; i++) 
  {
    list.insert(i);
  }


  //Reading our lock code from the profided input
  std::ifstream inf{FILE_PATH};

  if (!inf)
  {
    std::cerr<<"The provided file is not found or cant be opened"<<"\n";
    return -1;
  }


  //Reading Each line from the file 
  std::string strInput{};
  while (inf >> strInput)
  {
    char direction = strInput[0]
    char steps = strInput.substr(1);
     
  }

  list.setHeadToValue(head,50);
  list.move_forward(head);

  return 0;
}
