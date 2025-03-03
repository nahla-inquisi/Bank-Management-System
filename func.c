#include <stdio.h>
#include <string.h>
#include "func.h"

void main_menu()
{
    printf("\n\nChoose one of these Options:\n");
    printf(" 1. Enter a new customer.\n");
    printf(" 2. Print customer data.\n");
    printf(" 3. Edit customer.\n");
    printf(" 4. Delete customer data.\n");
    printf(" 5. Cash transfer from customer to customer.\n");
    printf(" 6. Exit.\n\n");
}

void unique_id(customer *ptr,int *id,int count)
{
    int Id=*id;
    int flag;
    do
    {
        flag=0;
        for(int i=0; i<count; i++)
        {
            if(Id==(ptr+i)->id)
            {
                flag=1;
                printf("The id must be unique! Enter id again: ");
                scanf("%i",&Id);
                break;
            }
        }

    }
    while(flag);
    *id=Id;
}

void create_new_customer(customer *ptr,int count)
{
    printf("\n\nEnter customer %i name: ",count+1);
    scanf("%s",(ptr+count)->name);
    do  //check validity of cash
    {
        printf("Enter customer %i cash: ",count+1);
        scanf("%lf",&(ptr+count)->cash);
        if((ptr+count)->cash<0)
            printf("Cash must be positive! Enter your cash again: ");
    }
    while((ptr+count)->cash<0);
    printf("Enter customer %i type(debit or credit): ",count+1);
    scanf("%s",(ptr+count)->type);
    printf("Enter customer %i id: ",count+1);
    scanf("%i",&(ptr+count)->id);
}

int find_id(customer *ptr,int count)
{
    int flag=0,i=0,id=0;
    printf("Enter customer id: ");
    do
    {
        scanf("%i",&id);
        if(id<=0)
            return -1;
        for(i=0; i<count; i++)
        {
            if((ptr+i)->id==id)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("This id not found! Enter customer id again: ");
        }
    }
    while(flag==0);
    return i;
}

void edit_customer(customer *ptr,int count)
{
    int index=find_id(ptr,count);
    printf("index of edit=%i",index);
    create_new_customer(ptr,index);
    printf("Editing Customer Done Successfully!\n");
}


void print_customer(customer *ptr,int count)
{
    int index=find_id(ptr,count);
    if(index==-1)
        printf("No Customer data found!");
    else
    {
        printf("Customer %i name:%s\n",index+1,(ptr+index)->name);
        printf("Customer %i cash:%.2f\n",index+1,(ptr+index)->cash);
        printf("Customer %i type:%s\n",index+1,(ptr+index)->type);
        printf("Customer %i id:%i\n\n",index+1,(ptr+index)->id);
    }
}


void delete_customer(customer *ptr,int *count)
{
    int index=find_id(ptr,*count);
    for(int i=index; i<*count-1; i++)
    {
        strcpy((ptr + i)->name, (ptr + i + 1)->name);
        (ptr+i)->cash=(ptr+i+1)->cash;
        strcpy((ptr + i)->type, (ptr + i + 1)->type);
        (ptr+i)->id=(ptr+i+1)->id;
    }
    (*count)--;
    printf("Deleting Done Successfully!\n");
}


void cash_transfer(customer *ptr,int count)
{
    double cash_out=0;
    int flag=0;
    printf("Enter cash you want to transfer: ");
    scanf("%lf",&cash_out);//from sender to receiver
    printf("Sender, ");
    int index1=find_id(ptr,count);
    printf("Receiver, ");
    int index2=find_id(ptr,count);
    do
    {
        flag=0;
        if(cash_out<=(ptr+index1)->cash)
        {
            (ptr+index1)->cash-=cash_out;
            (ptr+index2)->cash+=cash_out;
        }
        else
        {
            printf("cash out is greater than cash sender, Please enter cash out again: ");
            scanf("%lf",&cash_out);
            flag=1;
        }
    }
    while(flag);
    printf("Cash Transfer Operation Done Successfully!\n");
}
