#include<stdio.h>
#include<string.h>

// typedef is used to create a short nickname of any structure OR any datatype
typedef struct computersciencestudent{
    char name[50];
    int roll_no;
    float cgpa;
} coe;

// function to print info of students
void printinfo(coe s1){
    printf("Details of student: \n");
    printf("%s \n",s1.name);
    printf("%d \n",s1.roll_no);
    printf("%f \n",s1.cgpa);
}

int main(){
    coe s1;

    fgets(s1.name,sizeof(s1.name),stdin);
    s1.name[strcspn(s1.name,"\n")]='\0';
    scanf("%d",&s1.roll_no);
    scanf("%f",&s1.cgpa);

    printinfo(s1);
}