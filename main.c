#include <stdio.h>
#include <stdlib.h>
struct node
{
    char  FullName[20];
    char  FullAddress[50];
    char NationalID[20] ;
    int Age;
    double BankAccountID;
    char Guardian[20];
    char GuardianNationalID[20];
    char AccountStatus[10];
    double Balance ;
    char Password[20];

    struct node *next;
};

int main()
{
    struct node c1;
    strcpy(c1.FullName,"Ahmed Mohammed");
    strcpy(c1.FullAddress,"5ahmedstreetcairo");
    strcpy(c1.NationalID,"1254524234565");
    c1.Age=15;
    strcpy(c1.Guardian,"Waheed Sameh");
    strcpy(c1.GuardianNationalID,"1863653156152");
    c1.Balance=15421458;
    strcpy(c1.Password,"1234");
    get_cash(c1);
    add_deposite(c1);
    make_transaction(c1,c1 );
    change_password(c1);
}
void get_cash(struct node client)
{
    int cash_amount;
    printf("\nPlease enter the amount of cash you want to withdraw: ");
    scanf("%d",&cash_amount);
    if (cash_amount <= client.Balance)
    {
        client.Balance=client.Balance-cash_amount;
        printf("Successful Operation your withdraw amount= %d",cash_amount );
        printf("\nAnd the remaining in your account = %f ",client.Balance);
    }
    else
        printf("Sorry can't perform this operation as the amount of money in your account is less than the required number");
}
void add_deposite(struct node client)
{
    int cash_amount;
    printf("\nPlease enter the amount of cash you want to add to your account: ");
    scanf("%d",&cash_amount);
    client.Balance=client.Balance+cash_amount;
    printf("Successful Operation your added the  amount= %d",cash_amount);
    printf("\nAnd your account now = %f",client.Balance );
}
//add the search for the receiver
void make_transaction(struct node client,struct node reciever ){
    int cash_amount;
printf("\nPlease enter the amount of cash you want to transfer: ");
    scanf("%d",&cash_amount);
    if (cash_amount <= client.Balance)
    {
        client.Balance=client.Balance-cash_amount;
        reciever.Balance=reciever.Balance+cash_amount;
        printf("Successful Operation your transfered amount= %d",cash_amount);
        printf("\nAnd the remaining in your account = %f",client.Balance);
        printf("\nTo the client : %s",reciever.FullName );
    }
else
        printf("Sorry can't perform this operation as the amount of money in your account is less than the required number");
}

void change_password(struct node client)
{
    char old_password[50];
    char new_password[50];
    int count=3;
    while (count>0){
    printf("Please enter your password to confirm: ");
    scanf("%s",&old_password);
    if (!strcmp(old_password,client.Password) )
    {
        printf("Please enter the new password: ");
        scanf("%s",new_password);
        strcpy(client.Password,new_password);
        break;
    }
else
        printf("The password you entered is not correct please try again");
        count--;
    }
    if (count==0)
        printf("You've run out of tring times. Your account has been locked please visit the the bank for activation ");
}
