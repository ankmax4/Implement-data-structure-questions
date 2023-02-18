/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;
class Node{
    
    public :
    int data;
    Node* prev;
    Node *next;
    
    
    Node(int d){
        
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};


void nodecreation(Node * &head, int d){
    
    Node *new_node = new Node(d);
    Node *temp = head;
    
    if(head == NULL){
       head = new_node;
    }
    
    else {
        while(temp->next!= NULL){
            temp = temp->next;
            
        }
        
        temp->next = new_node;
            new_node->prev = temp;
        
    }
    
    
}

void printing (Node *head){
   int i =0;
    while(head!=NULL){

        cout <<"\nThe " <<i <<"Th node value is = "  <<head->data  <<endl;
        head = head->next;
        i++;
    }
}


void printing_backward_to_check (Node *head){
   int i =0;
    while(head->next!=NULL){
        head = head->next;
        i++;
    }
    
    while(head!=NULL){
        
        cout <<"\nThe " <<i <<"Th node value is = "  <<head->data  <<endl;
        head = head->prev;
        i--;
    }
}

void NodeInsertatstart(Node *&head, int val){
  
  Node *new_node = new Node(val);
  new_node->next = head;
  head->prev = new_node;
  head = new_node;

}

void NodeInsertatPos(Node *&head, int val, int pos){
  
  Node *temp = head;
  Node *temp_1 = head->next;
  Node *new_node = new Node(val);
  for(int i =1; i<pos-1;i++){
     temp  = temp->next;
     temp_1 = temp_1->next;
  }

  new_node->next = temp_1;
  temp_1->prev = new_node;
  temp->next = new_node;
  new_node->prev = temp;


}

void  NodeDeleteAtPos(Node * &head, int pos){
   Node *temp = head;
  Node *temp_1 = head->next;
  for(int i =1; i<pos-1;i++){
     temp  = temp->next;
     temp_1 = temp_1->next;
  }
  Node *removal = temp_1;

  temp->next = temp_1->next;
  temp_1->next->prev = temp;

  delete removal;
}



int main()
{
    Node *head  =NULL;
    int n;
    cin>>n;
    cout <<"The enter number of nodes are = "<<n <<endl;
    for(int i =0; i <n ;i++){

    nodecreation(head, i * 10);
}

NodeInsertatstart(head, 100000);

NodeInsertatPos(head, 200000,4);
printing(head);
printing_backward_to_check(head);


cout <<"Start deleting";
NodeDeleteAtPos(head, 4);

printing(head);
printing_backward_to_check(head);
    return 0;
}
