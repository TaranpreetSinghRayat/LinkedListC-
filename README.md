# LinkedListC++
Linked List program using C++ . Menu Driven console based.

Operations supported : 
Insertion : insert at front, insert at end, insert at any point.

Deletion : delete at fron, delete at end, delete at any point.

(NOTE : There is also condition on deletion if there is any node exists in list then the process will continue otherwise print error message).

Display all nodes using traverse all nodes.

Search function also added to check weather that data value exists in node or not.

#Why Linked list better from array?

(1)The size of the arrays is fixed: So we must know the upper limit on the number of elements in advance. Also, generally, the allocated memory is equal to the upper limit irrespective of the usage, and in practical uses, upper limit is rarely reached.

(2)Inserting a new element in an array of elements is expensive, because room has to be created for the new elements and to create room existing elements have to shifted.

For example, suppose we maintain a sorted list of IDs in an array id[].

id[] = [1000, 1010, 1050, 2000, 2040, …..].

And if we want to insert a new ID 1005, then to maintain the sorted order, we have to move all the elements after 1000 (excluding 1000).

Deletion is also expensive with arrays until unless some special techniques are used. For example, to delete 1010 in id[], everything after 1010 has to be moved.

So Linked list provides following two advantages over arrays
1)Dynamic size
2)Ease of insertion/deletion
