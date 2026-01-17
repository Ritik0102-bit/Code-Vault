Map Basics & Characteristics

Definition: An STL (Standard Template Library) Container which stores key-value pairs.
Ordering: The elements are stored in ascending / descending order.
Uniqueness: Maps cannot have duplicate keys.
Implementation: Implemented through BST (Binary Search Tree) -> (specifically a Red-Black Tree)

Time Complexity :-

Insertion -> O(logn)
Deletion -> O(logn)
Retrieval/Search -> O(logn)

#include <map>

map < key_datatype, value_datatype > map_name
map < string, int > directory ;

Initialization Syntax :-

map < datatype1, datatype2 > map_name
     = { { key1, value1 },
         { key2, value2 },
         { key3, value3 }
       }


Insertion :-

directory.insert(make_pair("ABC", 379))
directory[key] = value
directory["ABC"] = 379

Printing Elements :-

for ( auto element : map1 ) {
    key = element.first;
    value = element.second;
    cout << key << ":" << value ;
}

Iterators & Modification Functions :-

Iterators: Used to traverse STL containers.

erase() Functions:-
By Iterator : m.erase(itr)  Time Complexity: O(log n)
By Key : m.erase(key)       Time Complexity: O(log n)
By Range : m.erase(start_itr, end_itr) Time Complexity: O(n)

swap() Function:Used to swap contents of two maps (m1, m2) of the same type.
Syntax: m1.swap(m2) or swap(m1, m2).

clear() Function:Removes all elements: 
m.clear().

Member Functions - Capacity :-

empty(): Checks if the map is empty.
Syntax: m.empty()
Returns 1 (true) if empty.

size(): Returns the number of elements in the map.
Syntax: m.size().

max_size(): Returns the maximum number of elements the map can hold.
Syntax: max_size().

Member Functions - OperationsSource :-

find(): Returns an iterator to the element if present, else it returns map.end().
Syntax: m.find(key)      
Time Complexity: O(log n)

count(): Returns the number of occurrences of a key.
Syntax: m.count(key)
Since maps have unique keys, this effectively returns 1 if found, 0 otherwise.

Member Functions - Operations (Bounds) :-

upper_bound(): Returns an iterator to the next greater element.
Example: If map has keys {10, 20, 30}, m.upper_bound(20) returns iterator to 30.

lower_bound(): Returns an iterator to the element if present, else returns iterator to the next greater element.
Example: If map has keys {10, 20, 30}, m.lower_bound(25) returns iterator to 30.