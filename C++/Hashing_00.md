========================================================================
                        HASHING IN C++ & DSA
========================================================================

1. INTRODUCTION
------------------------------------------------------------------------
Hashing is a technique used to map data (keys) to a fixed-size table 
(Hash Table) using a Hash Function. It allows for efficient data 
retrieval.

- Primary Goal: Achieve O(1) average time complexity for insertion, 
  deletion, and search.
- Hash Function: Converts a given Key into an integer index.
  Index = Hash(Key) % TableSize

2. C++ STL CONTAINERS
------------------------------------------------------------------------
C++ provides hash-based containers in <unordered_map> and <unordered_set>.

A. std::unordered_map<Key, Value>
   - Stores key-value pairs.
   - Keys are unique.
   - Elements are NOT sorted.
   - Implemented using Hash Tables (Chaining).

B. std::unordered_set<Key>
   - Stores unique keys only.
   - Used for membership checking (e.g., "Have I seen this item before?").

C. Difference from std::map
   | Feature          | unordered_map       | map                  |
   |------------------|---------------------|----------------------|
   | Structure        | Hash Table          | Red-Black Tree       |
   | Time Complexity  | O(1) Average        | O(log n)             |
   | Order            | Random              | Sorted by Key        |

3. COLLISION RESOLUTION TECHNIQUES
------------------------------------------------------------------------
A collision occurs when two different keys generate the same index.

A. Open Hashing (Separate Chaining) *Used by C++ STL*
   - Each bucket in the table points to a Linked List.
   - If a collision occurs, the new item is appended to the list at that index.
   - Pros: Simple, table never "fills up".
   - Cons: Cache unfriendly (jumping pointers), extra memory for nodes.

B. Closed Hashing (Open Addressing)
   - All elements are stored inside the array table.
   - If a collision occurs, find the next empty slot.
   
   Types of Probing:
   1. Linear Probing:    Index = (Hash(x) + i) % Size
   2. Quadratic Probing: Index = (Hash(x) + i*i) % Size
   3. Double Hashing:    Index = (Hash1(x) + i * Hash2(x)) % Size

4. LOAD FACTOR & REHASHING
------------------------------------------------------------------------
The Load Factor measures how full the hash table is.

   Formula: alpha = n / k
   
   n: Total number of elements.
   k: Total number of buckets.

- Low Load Factor (alpha < 0.5):
  Table is empty. Fast O(1) operations, but wastes memory.

- High Load Factor (alpha > 0.75):
  Table is crowded. Collisions increase, performance drops toward O(n).

- Rehashing:
  When alpha exceeds a threshold (default 1.0 in C++, typically 0.75 in theory), 
  the table resizes (usually doubles). All elements are re-inserted into 
  the new table.

5. COMMON HASH FUNCTIONS
------------------------------------------------------------------------
- Division Method:      h(k) = k % m
- Multiplication Method: h(k) = floor(m * (k * A % 1))
- Mid-Square Method:    Square k, take middle digits.