#include <assert.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <list>
#include <sstream>
#include <stack>
#include <time.h>
#include <unistd.h>
#include "LinkedList.h"

shared_ptr<LinkedList::Node> LinkedList::head = nullptr;

void LinkedList::push(char data) {
   shared_ptr<Node> newNode = make_shared<Node>(data);
   shared_ptr<Node> temp;
   lengthOfList++;
   if(head == nullptr) {
      head = newNode;
   } else {
      newNode->next = head;
      head = newNode;
   }
   
}

void LinkedList::append(char data) {
   shared_ptr<Node> newNode = make_shared<Node>(data);
   shared_ptr<Node> target;
   lengthOfList++;

   if(head == nullptr) {
      head = newNode;
   } else {
      target = head;
      while (target->next != nullptr) {
         target = target->next;
      }
      target->next = newNode;
   }
}
//This assumes its data is unique so could make another 
//function that deletes based on Node position or index
//could write our own overloaded brackets operator function 
void LinkedList::deleteNode(char data) {
   shared_ptr<Node> prev;
   shared_ptr<Node> target = head;
   lengthOfList--;

   if (head->next == nullptr) {
      head = nullptr;
      return;
   }
   
   while (target->data != data && target->next != nullptr) {
      prev = target;
      target = target->next;
   }

   if (target->next == nullptr) {
      prev->next = nullptr;
      target = nullptr;
   } else {
      prev->next = target->next;
      target = nullptr;
   }
}

void LinkedList::printList() {
   shared_ptr<Node> temp = head;
   time_t endwait;
   time_t start = time(NULL);
   time_t seconds = 1;
   endwait = start + seconds;

   if(head == nullptr) {
      cout << "list is empty" << endl;
      return;
   }
   while(temp != nullptr && start < endwait) {
      cout << temp->data << " -> ";
      temp = temp->next;
      start = time(NULL);
   }
   cout << "null";
   cout << endl;
}

char LinkedList::KthToLast(int kth) {
   shared_ptr<Node> target = head;
   int length = getLength();
   int nodeToFind = length - kth;
   int counter = 1;

   if(kth > length || head == nullptr) {
      return -1;
   } else if (nodeToFind == counter) {
      return target->data;
   } else {
      while(counter < nodeToFind) {
      target = target->next;
      counter++;
      }
      return target->data;
   }
}

void LinkedList::removeDups() {
   shared_ptr<Node> current = head;
   shared_ptr<Node> target, temp;

   while(current != nullptr) {
      target = current;
      while(target->next != nullptr) {
         if(target->next->data == current->data) {
            temp = target->next;
            target->next = target->next->next;
            temp = nullptr;
         } else {
            target = target->next;
         }
      }
      current = current->next;
   }
}

shared_ptr<LinkedList::Node> LinkedList::reverseList() {
   shared_ptr<Node> newHead = nullptr;
   shared_ptr<Node> current = nullptr;

   current = head;

   while(current != nullptr) {
      shared_ptr<Node> newNode = make_shared<Node>(current->data);
      newNode->next = newHead;
      newHead = newNode;
      current = current->next;
   }
   return newHead;
}

bool LinkedList::isPalidrome() {
   shared_ptr<Node> newHead = reverseList();

   shared_ptr<Node> current = head;
   while(current != nullptr && newHead != nullptr) {
      if(current->data != newHead->data) {
         return false;
      }
      current = current->next;
      newHead = newHead->next;
   }
   return true;
}

bool LinkedList::findLoop(char letter) {
   shared_ptr<Node> lastNode = head;
   shared_ptr<Node> temp = head;
   bool foundLoop = false;

   if(head != nullptr) {
      while(lastNode->next != nullptr) {
         lastNode = lastNode->next;
      }
   } else {
      return false;
   }
   
   while(temp != nullptr) {
      if(temp->data == letter) {
         lastNode->next = temp;
         foundLoop = true;
         break;
      } else {
         temp = temp->next;
      }
   }
   return foundLoop;
}

void LinkedList::CreateList(string &src) {
   char tkn, tkn2;
   bool atNode = true;
   stringstream ss(src);

   do {
      if(atNode) {
         ss >> skipws >> tkn;
         if(!findLoop(tkn)) {
            append(tkn);
         }

         atNode = false;
      } else {
         ss >> skipws >> tkn >> tkn2;
         atNode = true;
      }

   } while(ss.peek(),!ss.eof());
}

char LinkedList::LoopDetection() {
   shared_ptr<Node> temp = head;

   while(temp->next != nullptr) {
      if(temp->discovered == false) {
         temp->discovered = true;
         temp = temp->next;
      } else if (temp->discovered == true) {
         return temp->data;
      }  
   }
   return ' ';
   
}

