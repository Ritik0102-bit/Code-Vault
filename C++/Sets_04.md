Types Of Sets:-

 ----------------------------------------------------------------------------------------------------------
 | Container               | Underlying Structure | Order  | Allow Duplicates? | Search/Insert/Delete (Avg) |
 |-------------------------|----------------------|--------|-------------------|----------------------------|
 | std::set                | BST (Tree)           | Sorted | No                | O(log n)                   |
 | std::unordered_set      | Hash Table           | Random | No                | O(1)                       |
 | std::multiset           | BST (Tree)           | Sorted | Yes               | O(log n)                   |
 | std::unordered_multiset | Hash Table           | Random | Yes               | O(1)                       |
 ----------------------------------------------------------------------------------------------------------


 ========================================================================================
                                 DETAILED COMPARISON
 ========================================================================================

 A. std::unordered_set
 ----------------------------------------------------------------------------------------
 Use this when you need maximum speed and do not care about the order of elements.

 - Header:       <unordered_set>
 - Key Behavior: If you insert 5, 1, 5, 2, the set will contain {1, 2, 5}.
                 (Order is undefined, duplicates are removed).
 - Best for:     Checking for existence (e.g., "Have I seen this ID before?").


 B. std::multiset
 ----------------------------------------------------------------------------------------
 Use this when you need to keep elements sorted but also need to store duplicates.

 - Header:       <set>
 - Key Behavior: If you insert 5, 1, 5, 2, the set will contain {1, 2, 5, 5}.
                 (Elements are always sorted).
 - Best for:     Frequency counts where order matters, or finding the 
                 "next greater element" in a collection that allows repeats.


 C. std::unordered_multiset
 ----------------------------------------------------------------------------------------
 Use this when you need to store duplicates and need fast access, but do not care 
 about order.

 - Header:       <unordered_set>
 - Key Behavior: Stores all duplicates via hashing.
 - Best for:     Counting frequency of elements rapidly without sorting overhead.
 
 ========================================================================================
