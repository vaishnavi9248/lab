<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node *prev;
  struct node *next;
};

struct node *head = NULL, *end=NULL;
static int size = 0;

void insert_head(int data){
  struct node *node;
  node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->next = head;
  node->prev = NULL;
  if(head != NULL)
  {
    head->prev = node;
    head = node;
  }
  else
  {
    head = node;
    end = node;
  }
  size++;
}

void insert_end(int data){
  struct node *node;
  node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->next = NULL;
  node->prev = NULL;
  if(end == NULL)
  {
    head = node;
    end = node;
  }
  else{
    node->prev = end;
    end->next = node;
    end = node;
  }
  size++;
}

void insert(int data, int pos){
  int count=1;
  struct node *node, *temp;
  temp = head;
  node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  do{
    if(count == pos){
      node->next = temp->next;
      (temp->next)->prev = node;
      node->prev = temp;
      temp->next = node;
      size++;
      break;
    }
    else{
      count++;
      temp = temp->next;
    }
  }while(count<=pos);
}

void delete_head(){
  struct node *temp;
  if(head != NULL){
      printf("\n\t\tNode deleted: %d", head->data);
      temp = head;
      head = head->next;
      if(head!=NULL)
        head->prev = NULL;
      else
        end = NULL;
      free(temp);
      size--;
  }
  else
    printf("\n\t\tLinked List is Empty!!");
}

void delete_end(){
  if(head == NULL)
    printf("\t\tLinked list is empty!!");
  else{
    printf("\n\t\tNode deleted: %d", end->data);
    struct node *temp,*nxt_temp;
    temp = end;
    end = end->prev;
    if(end == NULL)
      head = NULL;
    else
      end->next = NULL;
    free(temp);
    size--;
  }
}

void delete(int pos){
  int count = 1;
  struct node *temp, *next_temp;
  temp = head;
  next_temp = temp->next;
  do{
    if(count==pos){
      temp->next = next_temp->next;
      (next_temp->next)->prev = temp;
      printf("\n\t\tNode deleted: %d", next_temp->data);
      free(next_temp);
      size--;
      break;
    }
    else{
      count++;
      temp = next_temp;
      next_temp = next_temp->next;
    }
  }while(count<=pos);
}

void display_forward(){
  if(head == NULL)
    printf("\n\t\tLinked List is Empty!!");
  else{
    struct node *link = head;
    printf("\t\t");
    while(link->next != NULL){
      printf("%d ", link->data);
      link = link->next;