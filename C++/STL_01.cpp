// LIST Container

#include <iostream>
#include <list>

using namespace std;

// Iterator functions

// list.begin() -> Iterator for the first element
// list.end() -> Iterator for the position after the last element
// list.rbegin() -> Iterator for the first element in reverse iteration
// list.rend() -> Iterator for the position after the last element in reverse iteration
// advance(itr, n) -> advances the itr by n places

// Inserting elements into a List

// list.insert(itr, value) -> insert value before the position of the itr.
// list.insert(itr, count, value) -> insert value count number of times before itr.
// list.insert(itr, str_itr, end_itr) -> insert values from str_itr.... end_itr before itr

// Deleting elements from a List

// list.erase(itr) -> delete the element pointed to by the itr.
// list.erase(str_itr, end_itr) -> delete elements from [str_itr .... end_itr)

// Other member functions of a List container

// push_front(val) -> insert val in the front of list
// pop_front() -> removes val from front of list
// push_back(val) -> insert val in the back of the list
// pop_back() -> removes val from back of list

int main()
{
    list<int> list1 = {1, 2, 6, 4};
    auto itr = list1.begin();

    cout << *itr << endl;

    advance(itr, 2);

    cout << *itr << endl;

    // Traversal using range based Loop
    for (auto num : list1)
    {
        cout << num << " ";
    }
    cout << endl;

    // Traversal using Iterators
    for(auto itr1=list1.begin() ; itr1!=list1.end();itr1++){
        cout << *itr1 << " ";
    }
    cout << endl;
    
    // Traversal in reverse order
    for(auto itr2 = list1.rbegin() ; itr2!=list1.rend() ; itr2++){
        cout << *itr2 << " ";
    }
    cout << endl;
    
    
    // Inserting element in a list
    list1.insert(itr,0);
    list1.insert(itr,3,8);

    // Deleteing element from list
    list1.erase(itr);
    
    for(auto itr1=list1.begin() ; itr1!=list1.end();itr1++){
        cout << *itr1 << " ";
    }
    cout << endl;
    return 0;
}