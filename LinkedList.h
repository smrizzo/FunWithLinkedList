#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <stdlib.h>
#include <set>
#include <vector>
#include <memory>
#include <string.h>
#include <iomanip> 
#include <fstream>
#include <string>
#include <list>

using namespace std;

class LinkedList {
public:

   struct Node {
      char data;
      bool discovered;
      shared_ptr<Node> next;
      Node(int data) : data(data), discovered(false) , next(nullptr) {};
   };

   LinkedList() : lengthOfList(0) {};
   ~LinkedList() {}

   //setting head to static so only have one copy that should
   //always be pointing to head of list
   static shared_ptr<Node> head;
   int lengthOfList;//keep track of the length

   void push(char data);//will push in the beginning of list
   void append(char data);
   void deleteNode(char data);//delete node form list and adjust accordingly
   int getLength(){ return lengthOfList; };//Just return length of current linked list
   void printList();//print all the contents from list
   char KthToLast(int kth);
   void removeDups();
   shared_ptr<Node> reverseList();//reverse the list and return a copy of it
   bool isPalidrome();
   void CreateList(string &src);
   char LoopDetection();
   bool findLoop(char letter);

};
#endif
