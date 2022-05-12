#include <stdio.h>
#include <stdlib.h>

struct client
{
    char  FullName[20];
    char  FullAddress[20];
    char NationalID[20] ;
    int Age;
    char BankAccountID[20];
    char Guardian[20];
    char GuardianNationalID[20];
    char AccountStatus[10];
    double Balance ;
    char Password[20];

   struct node *next;
};

struct admin
{
    char BankAccountID[20];
    char Password[20];


} admins[]={

 { .BankAccountID = "123", .Password = '9898' },
    { .BankAccountID = "123", .Password = '7878' },

};




struct list
{
struct node *head;
int size;

};

void create_list(struct list *l);
void creatClient(struct list *l,char FullName[],char FullAddress[],char NationalID[],int Age,char BankAccountID[],char Guardian[],
                 char GuardianNationalID[],double Balance,char Password[]);
void print_list(struct list *l);



int main(void)
{
    char  FullName[20];
    char  FullAddress[20];
    char NationalID[20] ;
    int Age;
    char BankAccountID[20];
    char Guardian[20];
    char GuardianNationalID[20];
    char AccountStatus[10];
    double Balance ;
    char Password[20];

    printf("hello from main\n");
    printf("enter the Client BankAccountID \n");
    scanf("%s",&BankAccountID);
    puts(BankAccountID);
    puts(admins[1].BankAccountID);
   //admin list_2[]={{BankAccountID:"1234",Password:"ab"},{.BankAccountID="1234",.Password="abb"},};
  if(strcmp(BankAccountID,admins[1].BankAccountID) == 0){
    printf("the admin user name is ");
    puts(admins[1].BankAccountID);


}else{
printf("the no admin user name is ");
}


    // creating database for all our clients
	struct list l1;
	create_list(&l1);
	creatClient(&l1,"sarah","naserstreet","876543",23,"99999","manar","111111",7777,"abc");
	creatClient(&l1,"zahra","naserstreet","876542",26,"99998","hager","111110",7776,"abca");
	creatClient(&l1,"shahed","naserstreet","876541",26,"99997","Omar","111112",7775,"abcc");
    printf("size of list is %d\n",l1.size);
    // print_list(&l1);




	return 0;
}


void create_list(struct list *l){

l->head=NULL;
l->size=0;
printf("done list is created\n");
}

void creatClient(struct list *l,char FullName[],char FullAddress[],char NationalID[],int Age,char BankAccountID[],char Guardian[],
                 char GuardianNationalID[],double Balance,char Password[]){

struct client *n=(struct client*)malloc(sizeof(struct client));
  strcpy(n->FullName,FullName);
  strcpy(n->FullAddress,FullAddress);
  strcpy(n->NationalID,NationalID);
  n->Age=Age;
  strcpy(n->BankAccountID,BankAccountID);
  strcpy(n->Guardian,Guardian);
  strcpy(n->GuardianNationalID,GuardianNationalID);
  strcpy(n->AccountStatus,"Active");
  n->Balance=Balance;
  strcpy(n->Password,Password);






  n->next=NULL;
if(l->head==NULL){
  l->head=n;
}else{
 struct client *current =l->head;
  while(current->next!=NULL){
    current=current->next;
  }

  current->next=n;

}
(l->size)++;
printf("done node is added to the list\n");

}



void print_list(struct list *l){

struct client *current =l->head;
int i=1;

while(current!=NULL){


     printf("data of Client %d are:\n",i);
     printf("the Client full name is ");
     puts(current->FullName);

     printf("the Client FullAddress is ");
     puts(current->FullAddress);

     printf("the Client NationalID is ");
     puts(current->NationalID);


     printf("the Client Age is %d\n",current->Age);

     printf("the Client BankAccountID is ");
     puts(current->BankAccountID);

     printf("the Client GuardianNationalID is ");
     puts(current->GuardianNationalID);

     printf("the Client Guardian is ");
     puts(current->Guardian);

     printf("the Client AccountStatus is ");
     puts(current->AccountStatus);

     printf("the Client Balance is %f\n",current->Balance);

     printf("the Client Password is ");
     puts(current->Password);

    current=current->next;
    i++;





}


}

