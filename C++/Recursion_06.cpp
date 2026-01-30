// In this code we are going to make a function for checking whether the number is palindrome or not using recursion

#include<iostream>

using namespace std;

bool check_Palindrome(int num, int *temp){
    if(num >=0 and num<=9){
        int last_digit_temp= (*temp)%10;
        (*temp)/=10;
        return (num==last_digit_temp);
    }

    bool result = (check_Palindrome(num/10,temp)  and (num%10 == (*temp)%10));
    
    (*temp)/=10;

    return result;
}

int main(){
    int num;
    
    cout << "Enter the number to compare : ";
    cin >> num;

    int num_copy = num;

    int *temp = &num_copy;

    cout << check_Palindrome(num, temp);

    return 0;
}