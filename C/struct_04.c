#include<stdio.h>
#include<string.h>

// Structure array

struct address{
    int block;
    int house_no;
    char city[50];
    char state[50];
};

// function to print address of the person
void printaddress(struct address add){
    printf("Address of the person is %d, %d, %s, %s .\n",add.block,add.house_no,add.city,add.state);
}

int main(){
    // array of structure to store address of 3 persons
    struct address add[3];

    printf("Enter the address of Person 1: \n");
    scanf("%d",&add[0].block);
    scanf("%d",&add[0].house_no);
    scanf("%s",&add[0].city);
    scanf("%s",&add[0].state);
    printf("Enter the address of Person 2: \n");
    scanf("%d",&add[1].block);
    scanf("%d",&add[1].house_no);
    scanf("%s",&add[1].city);
    scanf("%s",&add[1].state);
    printf("Enter the address of Person 3: \n");
    scanf("%d",&add[2].block);
    scanf("%d",&add[2].house_no);
    scanf("%s",&add[2].city);
    scanf("%s",&add[2].state);

    printaddress(add[0]);
    printaddress(add[1]);
    printaddress(add[2]);
}