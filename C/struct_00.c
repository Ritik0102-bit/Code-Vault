#include<stdio.h>
#include<string.h>

struct student{
    char name[50];
    int roll_no;
    float cgpa;
};

int main(){
    struct student s1={"Ritik",33,9.0};
    struct student s2={0};
    struct student s3;

    fgets(s3.name,sizeof(s3.name),stdin);
    s3.name[strcspn(s3.name,"\n")]='\0';
    scanf("%d",&s3.roll_no);
    scanf("%f",&s3.cgpa);

    printf("Details of student 1\n");
    printf("%s \n",s1.name);
    printf("%d \n",s1.roll_no);
    printf("%f \n",s1.cgpa);

    printf("Details of student 2 \n");
    printf("%s \n",s2.name);
    printf("%d \n",s2.roll_no);
    printf("%f \n",s2.cgpa);

    printf("Details of student 3 \n");
    printf("%s \n",s3.name);
    printf("%d \n",s3.roll_no);
    printf("%f \n",s3.cgpa);
}