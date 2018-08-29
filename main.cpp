#include <assert.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <list>
#include "LinkedList.h"

using namespace std;
void options() {
   cout << endl;
   cout << "Enter a command" << endl;
   cout << "Example: push A" << endl;
   cout << endl;
   cout << "command list:" << endl;
   cout << "push, append, delete, printList, getLength, KthToLast" << endl;
   cout << "removeDups, isPalidrome, createList, loopDetection, options, quit " << endl;
   cout << endl;
}

int main(int argc, char **argv) {
   
   string command, arg, commandLine;
   char value;
   int Kth;
   shared_ptr<LinkedList> current = make_shared<LinkedList>();

   options();

   while (cin >> command && !cin.eof()) {
      try {
         
         if(command.compare("push") == 0) {
            cin >> value;
            current->push(value);
            
         } else if (command.compare("append") == 0) {
            cin >> value;
            current->append(value);

         } else if (command.compare("delete") == 0) {
            cin >> value;
            current->deleteNode(value);

         } else if(command.compare("getLength") == 0) {
            cout << "There are " << current->getLength() << " nodes in list" << endl;

         } else if (command.compare("printList") == 0) {
            cout << endl;
            current->printList();

         } else if (command.compare("removeDups") == 0) {
            current->removeDups();

         } else if (command.compare("KthToLast") == 0) {
            cin >> Kth;
            cout << "The " << Kth << " node from the last is "
             << current->KthToLast(Kth) << endl;

         } else if (command.compare("isPalidrome") == 0) {
            if(current->isPalidrome()) {
               cout << "Current list is a palidrome" << endl;
            } else {
               cout << "Current list is not a palidrome" << endl;
            }
         } else if (command.compare("createList") == 0) {
            getline(cin, arg);
            current->CreateList(arg);
         } else if (command.compare("loopDetection") == 0) {
            char start = current->LoopDetection();
            if(start != ' ') {
               cout << "The beginning of loop was at: " << start << endl;
            } else {
               cout << "There was no loop" << endl;
            }
         } else if (command.compare("options") == 0) {
            options();
         }
         else if (command.compare("quit") == 0) {
            break;
         }

      } catch (const std::exception& e) {
         cout << e.what() << endl;
      }
      cout << endl;
   }
   return 0;
}