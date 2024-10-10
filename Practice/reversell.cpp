#include<iostream>

struct node{
  int data;
  node* next;
}*head;

node* create_list(int num);
void display_list(node* list_ptr);
node* reverse(node* list_ptr);

int main(){

  int num;
  std::cout << "\nEnter The number of nodes in the linked list: ";
  std::cin >> num;

  node* list_ptr = create_list(num);
  std::cout << "\nList Before Reversing: ";
  display_list(list_ptr);
  list_ptr = reverse(list_ptr);
  std::cout << "\nList After Reversing: ";
  display_list(list_ptr);
  std::cout << std::endl;
  return 0;
}

node* create_list(int num){
  head = new node;
  head->data = 1;
  head->next = NULL;
  node *prev = head;
  for(int i=0;i<num-1;i++){
    node *temp = new node;
    temp->data = i+2;
    temp->next = NULL;
    prev->next = temp;
    prev = temp;
  }
  return head;
}

void display_list(node* list_ptr){
  for(node* temp = list_ptr;temp!=NULL;temp=temp->next){
    std::cout << temp->data << " ";
  }
}

node* reverse(node* list_ptr){
  node *rev_head,*last,*prev;
  int count = 0;
  for(node *temp=list_ptr;temp!=NULL;temp=temp->next){
    count++;
    last=temp;
  }
  rev_head = last;
  for(int i=1;i<count;i++){
    for(prev = list_ptr;prev->next!=last;prev=prev->next);
    last->next = prev;
    prev->next = NULL;
    last=prev;
  }
  return rev_head;
}
