#include <iostream>
#include <stdlib.h>
#include "LinkedListMethods.h"

int main(){
    int selection;
    struct node *header;
    header = new node();
    header->data = 0;
    header->link = NULL;
    cout << "Make a choice : "<<endl;
    cout << "[1] Insertion Menu"<<endl;
    cout << "[2] Deletion Menu"<<endl;
    cout << "[3] Exit"<<endl;
    cin >>  selection;
    switch(selection){
    case 1:
         _LinkedListMethods.insertDataMenu(&header);
    break;
    case 2:
         _LinkedListMethods.deleteDataMenu(&header);
    break;
    case 3:
            return 1;
    break;
        default:
                main();
        break;
    }
    return 0;
}
