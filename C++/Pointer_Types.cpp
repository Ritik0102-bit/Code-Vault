// Types of Pointer
// 1. Wild Pointer
// 2. Null Pointer
// 3. Dangling Pointer 
// 4. Void / Generic Pointer

#include<iostream>

using namespace std;

int main(){
    int *ptr1; // Wild Pointer (only declared)
    cout << ptr1 << endl;

    
    int *ptr2 = NULL;  //Null Pointer (All Three)
    int *ptr3 = 0;  
    int *ptr4 = '\0';  // This will generate a warning , but we declare like this also
    cout << ptr2 << ' ' << ptr3 << ' ' << ptr4 << endl;


    int *ptr5; // Dangling Pointer
    {
        int x=10;
        ptr5=&x;
    }
    cout << ptr5 << endl;



    void *ptr6; // Void Pointer / Generic Pointer
    // Now in this pointer we can store address of any type of variable
    int x=2;
    ptr6=&x;
    cout << ptr6 << endl;
    // We can't dereference the void pointer
    // For dereferencing we need to type cast that pointer
    cout << *(int *)ptr6 << endl;
    float y=3.0;
    ptr6 = &y;
    cout << *(float *)ptr6 << endl;

    
    return 0;
}