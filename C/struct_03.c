#include<stdio.h>
#include<string.h>

// Pointer to structure

struct student{
    char name[50];
    int roll_no;
    float cgpa;
};

int main(){
    struct student s1;
    struct student *ptr;
    ptr=&s1;

    fgets(s1.name,sizeof(s1.name),stdin);
    s1.name[strcspn(s1.name,"\n")]='\0';
    scanf("%d",&s1.roll_no);
    scanf("%f",&s1.cgpa);

    printf("Details of student by dot opertor\n");
    printf("%s \n",(*ptr).name);
    printf("%d \n",(*ptr).roll_no);
    printf("%f \n",(*ptr).cgpa);

    printf("Details of student by arrow operator \n");
    printf("%s \n",ptr->name);
    printf("%d \n",ptr->roll_no);
    printf("%f \n",ptr->cgpa);
}