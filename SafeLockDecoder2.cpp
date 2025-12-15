#include <fstream>
#include <iostream>
#include <string>
#define FILE_PATH "./misc_files/SafeInput.txt"

int flag = 0;

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
    void move_forward(Node*& head, int turns)
    {
      if(!head) return ;
      
      Node* curr = head;

      for(int i = 0 ; i < turns ; i++)
      {
      if(curr->data==0)
      {
        std::cout<<curr->data<<"\n";  
        flag++;
      }
        curr=curr->next;
      }
      head=curr;
      
    }

    void move_backwards(Node*& head , int turns)
    {
       if(!head) return ;
      
      Node* curr = head;

      for(int i = 0 ; i < turns ; i++)
      {
      if(curr->data==0)
      {
        std::cout<<curr->data<<"\n";  
        flag++;
      }
        curr=curr->prev;
      }
     
      head=curr;
      

    }

    void setHeadToValue(Node*& head, int value) {
    if (!head) return;

    Node* curr = head;

    do {
        if (curr->data == value) {
            head = curr;
            return;
        }
        curr = curr->next;
    } while (curr != head);
}

};



int main()
{


  //creating our lock using CircularDoublyLinkedList
  CircularDoublyLinkedList list;
  for (int i = 0; i < 100; i++) 
  {
    list.insert(i);
  }
  list.setHeadToValue(list.head, 50);


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
    char direction = strInput[0];
    int turns = std::stoi(strInput.substr(1));
    if(direction == 'R')
    {
      std::cout<<"direction :"<<direction<<" turns :"<<turns<<"\n";
      list.move_forward(list.head,turns);
    }
    if(direction == 'L'){
      std::cout<<"direction :"<<direction<<" turns :"<<turns<<"\n";
      list.move_backwards(list.head,turns);
    }
     
  }

 std::cout <<"flag : "<<flag<<"\n";
  return 0;
}
