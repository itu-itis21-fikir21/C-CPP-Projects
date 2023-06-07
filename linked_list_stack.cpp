#include <iostream>

using namespace std;

/*struct node{
    int data;
    node *next;
};

struct node *head=NULL;
void insert(int data){
    node *new_node = new node();
    new_node->data=data;
    new_node->next=head;
    head=new_node;
}
void reverse(){
    node *next=NULL, *prev=NULL, *current=head;
    while(current!=NULL){
    next=current->next;
    current->next=prev;
    prev=current;
    current=next;}
    head=prev;
}


int main(){
    insert(3);
    insert(4);
    insert(5);
    reverse();
    struct node *temp=head; 
    
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;

    }

    return 0;
} */

/* STACK SOLUTION 1


 struct stack{
    int num;
    stack *top=NULL;
};

struct stack *head;

void create_stack(int data){
    stack *new_node=new stack();
    new_node->num=data;
    new_node->top=head;
    head=new_node;    
}

void pop(){
    stack *new_stack=head;
    int pop=new_stack->num;
    cout<<"popped element is "<<pop<<endl;
    new_stack=new_stack->top;
    head=new_stack;   
}
void display_stack(){
    stack *temp=head;
    while(temp!=NULL){
        cout<<temp->num<<" ";
        temp=temp->top;
    }
}

int main(){
    create_stack(1);
    create_stack(5);
    create_stack(10);

    display_stack();
    cout<<endl;
    pop();
    display_stack();
    cout<<endl;
    pop();
    display_stack();
    return 0;
} */
class Node{
    public:
    int data;
    Node *next;
};

class Stack{
private:
    Node *top;
public:
    Stack(){
        top=NULL;
    }
    bool is_empty(){
        return (top==NULL);
    }
    void push(int num){
        Node *new_node=new Node();
        new_node->data=num;
        new_node->next=top;
        top=new_node;
    }
    void push_stk(Node** topRef, int data) {
    // Allocate memory for new node
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = *topRef;

    // Set the new node as the top of the stack
    *topRef = newNode;
}    
    void sort() {
      Node* prev = NULL;
      Node* current = top;
      Node* next = NULL;

     while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

     // Sort from the top of the stack by reversing the stack
     top = prev;

    // Now we can use a temporary stack to sort the elements
     Node* tempStack = NULL;
     while (top != NULL) {
        int temp = (top)->data;
        top = top->next;

        while (tempStack != NULL && tempStack->data > temp) {
        // Pop elements from the temporary stack to the original stack 
		// until we find a position for the current element.
            push_stk(&top, tempStack->data);
            tempStack = tempStack->next;
        }

        push_stk(&tempStack, temp);
    }
    // Set the original stack to the elements that were sorted.  
     top = tempStack;
    }
     
    void pop(){
        Node *temp=top;
        cout<<"popped element is "<<top->data<<endl;
        top=top->next;
        delete temp;
    }
    void display_stack(){
        Node *new_node=top;
        cout<<"stack: ";
        while(new_node!=NULL){
            cout<<new_node->data<<" ";
            new_node=new_node->next;
        }
        cout<<endl;
    }
    int stack_size(){
        Node *node=top;
        int counter=0;
        while(node!=NULL){
            node=node->next;
            counter++;
        }
       return counter;
    }
};

int main(){
    Stack stack;
    stack.push(8);
    stack.push(15);
    stack.push(4);
    cout<<"size is: "<<stack.stack_size()<<endl;
    stack.display_stack();
    stack.sort();
    stack.display_stack();
    stack.pop();
    stack.display_stack();
    stack.pop();
    stack.display_stack();
    cout<<"size is: "<<stack.stack_size()<<endl;
    cout<<"stack is empty: " <<stack.is_empty();

    return 0;
}