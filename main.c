// Sources include:
// https://www.tutorialspoint.com/c_standard_library/time_h.htm
// https://www.tutorialspoint.com/c_standard_library/c_function_rand.htm
// https://www.tutorialspoint.com/data_structures_algorithms/linked_list_program_in_c.htm
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

struct node {
   int r;
   struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

void outputLL() {
   struct node *ptr = head;
   printf("\n[");

   //start from the beginning
   while(ptr != NULL) {
      printf("(%d)", ptr->r);
      ptr = ptr->next;
   }

   printf("]");
}

// insert a random amount of random ints
void insert() {

   srand ( time(NULL) );
   int p = rand() % 100;
   for (int i = 0; i < p; i++){
   //create a link

   int r = rand() % 100;
   struct node *link = (struct node*) malloc(sizeof(struct node));

   link->r = r;

   //point it to old first node
   link->next = head;

   //point first to new first node
   head = link;
   }}

//is list empty
bool isEmpty() {
   return head == NULL;
}

int length() {
   int length = 0;
   struct node *current;

   for(current = head; current != NULL; current = current->next) {
      length++;
   }

   return length;
}

void sort() {

   int i, j, k, tempKey, tempData;
   struct node *current;
   struct node *next;

   int size = length();
   k = size ;

   for ( i = 0 ; i < size - 1 ; i++, k-- ) {
      current = head;
      next = head->next;

      for ( j = 1 ; j < k ; j++ ) {

         if ( current->r > next->r ) {
            tempData = current->r;
            current->r = next->r;
            next->r = tempData;
         }

         current = current->next;
         next = next->next;
      }
   }
}

void main() {
   insert();

   printf("Linked list of random numbers: ");

   //print list
   outputLL();
   printf("\n");

   sort();

   printf("Sorted linked list: ");
   outputLL();
   return 0;
}
