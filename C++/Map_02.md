UNORDERED MAP IN C++ STL

INTRODUCTION
* Definition: An STL container that stores key-value pairs.
* Ordering: Elements are NOT ordered (unlike std::map).
* Uniqueness: Keys must be unique.

TIME COMPLEXITY (Average Case)
* Insertion: O(1)
* Deletion: O(1)
* Retrieval/Search: O(1)

---------------------------------------------------------

MEMBER FUNCTIONS

1. ELEMENT ACCESS
These functions allow you to access or modify values associated with keys.

* operator[]
  - Purpose: Accesses or inserts an element.
  - Behavior: If the key exists, it returns a reference to its mapped value. If the key DOES NOT exist, it inserts a new element with that key and a default value.
  - Example: map[key] = value;

* at(key)
  - Purpose: Accesses an element with bounds checking.
  - Behavior: Returns a reference to the mapped value. If the key is NOT FOUND, it throws an 'out_of_range' exception. It is safer than [] if you only want to read.

2. CAPACITY
These functions tell you about the storage status of the map.

* empty()
  - Returns 'true' if the map is empty, 'false' otherwise.

* size()
  - Returns the number of elements currently in the map.

3. MODIFIERS
These functions change the contents of the map.

* insert({key, value})
  - Purpose: Inserts a new element.
  - Note: It will NOT overwrite the value if the key already exists (unlike []).

* erase(key)
  - Purpose: Removes the element with the specific key.
  - Returns: 1 if the element was removed, 0 if it wasn't found.

* erase(iterator)
  - Purpose: Removes the element at the specified position.

* clear()
  - Purpose: Removes ALL elements from the map.

4. LOOKUP (SEARCH)
These are critical for checking if a key exists without modifying the map.

* find(key)
  - Purpose: Searches for the key.
  - Returns: An iterator to the element if found, or map.end() if not found.
  - Usage: if (map.find(key) != map.end()) { /* found */ }

* count(key)
  - Purpose: Returns the number of elements with the key.
  - Note: In an unordered_map, keys are unique, so this function only returns 1 (found) or 0 (not found). It is often used as a simpler alternative to find() for boolean checks.

5. HASH POLICY (ADVANCED)
Since unordered_map uses a hash table, these help manage performance.

* load_factor()
  - Returns the average number of elements per bucket (size / bucket_count).

* bucket_count()
  - Returns the total number of buckets.

* rehash(n)
  - Sets the number of buckets to n or more.