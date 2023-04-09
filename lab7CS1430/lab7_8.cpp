/********* YOUR ARE NOT ALLOWED TO CHANGE ANYTHING FROM HERE TO LINE 71***********/
#include "Helper.h"
using namespace std;

//Merge two sorted linked lists in place for task I
Node * mergeList(Node * l1Head, Node * l2Head);
//Removes all the nodes in a sorted list that have the targeted value
Node * removeTargets(Node * head, int val);
//Remove duplicatesd nodes such that node with the same value only appears once
Node * removeDuplicates(Node * head);
//Find the middle node in a given linked list
Node * findMiddle(Node * head);

//Your program will be tested with the following command:
//./lab7_8 test_case.txt NUMBER_HERE(Replace with real number),
//where lab7_8 is your executable name after compilation, 
//test_case.txt is a txt file that has two lines of numbers for creating two lists,
//NUMBER_HERE is a specific target number for task II.
//Note that (1) NUMBER_HERE can be any number when running the command.
//For example, a real command in practice could be "./lab7_8 test_case.txt 6".
//(2) lines could be empty in test_case.txt, which means empty list could be created
int main(int argc, char * argv[]){
    //Preparation. I get this done so that you can focus on the following three tasks.
    //create a list using the first line in the input file
    Node * l1Head = createListFromFile(argv[1], 1);
    //create a list using the second line in the input file
    Node * l2Head = createListFromFile(argv[1], 2);
    // printList(l1Head);
    // printList(l2Head);

    //Your task I: merge the above two sorted lists and keep the merged list sorted.
    //the merge should be in-place. That is, you are not allowed to create a new list,
    //in which node values are copied from two given lists.
    //Instead, you should change the pointers of each existing node properly 
    //to chain the existing nodes in both lists together.
    Node * listHeadAfterTaskI = mergeList(l1Head, l2Head);
    printList(listHeadAfterTaskI);

    //Your task II: find the middle node in the linked list generated after task I
    //If there are two middle nodes, return the first middle nodes.
    //For example, if the list is head->1->2->3->null, the middle node will be 2;
    //if the list is head->1->2->3->4->null, there are will be two middle 
    //nodes (i.e., 2 and 3), your function should return the *first* one, i.e., 2.
    Node * middleNode = findMiddle(listHeadAfterTaskI);
    if (middleNode){
        cout << "The value of the middle node is " << middleNode->value << endl;
    }else{
        cout << "No middle node in an empty list." << endl;
    }

    //Your task III: remove all the nodes in a sorted list that have the targeted value.
    //For example, assuming the targeted value is 6, and the merged list after task I
    //is head->2->2->6->6->7->7->7->7->8->9->null, 
    //after this task III the list will become head->2->2->7->7->7->7->8->9->null
    int targetVal = stoi(argv[2]);
    Node * listHeadAfterTaskIII = removeTargets(listHeadAfterTaskI, targetVal);
    printList(listHeadAfterTaskIII);

    //Your task IV: remove all the duplicated nodes (such that node with the same value
    // only appears once) in the merged list after task III.
    //Since the list remains sorted (non-descending) after task III, 
    //the final list will be strictly ascending as we removed all the duplicated values.
    //Continuing the previous example in taskIII, 
    //if the list returned by taskIII is head->2->2->7->7->7->7->8->9->null,
    //after this taks IV, it will become head->2->7->8->9->null
    Node * listHeadAfterTaskIV = removeDuplicates(listHeadAfterTaskIII);
    printList(listHeadAfterTaskIV);

    return 0;
}
/********* YOUR ARE NOT ALLOWED TO CHANGE ANYTHING FROM Line 1 TO HERE ***********/



/********* YOU SHOULD IMPLEMENT THREE FUNCTIONS AFTER THIS LINE **********/
Node * mergeList(Node * l1Head, Node * l2Head){
  Node * mergedHead = nullptr;
  Node * curr = nullptr;
  //If one of the list is empty, return the opposing list.
  //I.e. if List1 is empty, then list 2 would be the merged list.
  if(!l1Head){
    return l2Head;
  }else if(!l2Head){
    return l1Head;
  }
  if(l1Head->value < l2Head->value){
    mergedHead = l1Head;
    l1Head = l1Head->next; //original list heads will now be used to "traverse" it's list into the next node.
  }else{
    mergedHead = l2Head;
    l2Head = l2Head->next;
  }
  curr = mergedHead;
  //while loop will find the next smallest value from the list via if statement
  while(l1Head != nullptr && l2Head != nullptr){
    //If statements will compare both lists and their current value.
    //This means that one list can be further into another, which isn't a problem unless one is larger than the other.
    if(l1Head->value < l2Head->value){
      //If List 1's current node is less than list 2's, then make that the merged lists next node
      curr->next = l1Head;
      l1Head = l1Head->next;
    }else{
      //else, make list 2's current node the next node in the merged list.
      curr->next = l2Head;
      l2Head = l2Head->next;
    }
    curr = curr->next;
  }
  //Edge case: if the lists don't have the same amount of nodes
  if(l1Head){
    curr->next = l1Head;
  }else if (l2Head){
    curr->next = l2Head;
  }
  return mergedHead;
}

Node * findMiddle(Node * head){
  int length = 0;
  Node * travel = nullptr; //will be used solely to travel through the linked list, and add 1 to length
  Node * middle = nullptr;
  travel = head;
  while(travel != nullptr){
    //while loop to find the entire length of the list
    length++;
    travel = travel->next;
  }
  if(length%2 == 0){ //This means there are two middle nodes, and we want the very first middle one.
    length = (length/2)-1;
  }else{
    length = length/2;
  }
  middle = head;
  for(int i = 0; i < length; i++){
    middle = middle->next; //traversing the list until we reach the middle, which was found previously
    }
  return middle;
}

Node * removeTargets(Node * head, int val) { //very similar to deleting a single node function.
  Node * curr = nullptr;
  Node * prev = nullptr;
  if(!head){
    cout << endl << "Empty list";
    return head;
  }else{
    while(head != nullptr && head->value == val){
      //If the head's value is equal to the target, the next node (that isn't the target) had to be head 
      curr = head->next;
      delete head;
      head = curr;
    }
    curr = head;
    while(curr){
      if(curr->value == val){
        //if the current node's value is the target
        prev->next = curr->next;
        delete curr;
        curr = prev->next;
      }else{
        prev = curr;
        curr = curr->next;
      }
    }
  }
  return head;
}

Node * removeDuplicates(Node * head) {
  Node * curr = nullptr;
  Node * prev = nullptr;
  if(!head){
    cout << endl << "Empty List.";
    return head;
  }else{
    curr = head;
    while(curr != nullptr && curr->next != nullptr){
      //Since the list is organized, both a node and the next node must NOT be nullptr, since that's what's being compared.
      if(curr->value == curr->next->value){
        //If the current node and it's next node are duplicates, delete one of them (current one)
        prev->next = curr->next;
        delete curr;
        curr = prev;
      }
      prev = curr;
      curr = curr->next;
    }
  }
  return head;
}

