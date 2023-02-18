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
int main()
{
    Node *head  =NULL;
    int n;
    cin>>n;
    cout <<"The enter number of nodes are = "<<n <<endl;
    for(int i =0; i <n ;i++){

    nodecreation(head, i * 10);
}

printing(head);
printing_backward_to_check(head);
    return 0;
}
