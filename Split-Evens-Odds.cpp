#include <iostream>
#include "unorderedLinkedList.h" // Assumes this header file also includes linkedList.h

// Extended class for splitting lists
template <class Type>
class extendedLinkedList : public unorderedLinkedList<Type> {
public:
    void splitEvensOddsList(extendedLinkedList<Type>& evensList, extendedLinkedList<Type>& oddsList) {
        nodeType<Type>* current = this->first;
        while (current != nullptr) {
            nodeType<Type>* nextNode = current->link; // Save next node to move forward in the list
            if (current->info % 2 == 0) { // Even
                evensList.insertLast(current->info);
            }
            else { // Odd
                oddsList.insertLast(current->info);
            }
            current = nextNode; // Move to next node
        }

        // Clearing original list to fulfill the requirement of ending up with an empty list
        this->initializeList();
    }
};

int main() {
    // Example usage
    extendedLinkedList<int> list, evensList, oddsList;

    // Inserting elements into the list
    list.insertLast(1);
    list.insertLast(2);
    list.insertLast(3);
    list.insertLast(4);
    list.insertLast(5);

    // Splitting the list into evens and odds
    list.splitEvensOddsList(evensList, oddsList);

    std::cout << "Even numbers list: ";
    evensList.print();
    std::cout << std::endl << "Odd numbers list: ";
    oddsList.print();
    std::cout << std::endl;

    return 0;
}
