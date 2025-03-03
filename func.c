#include <stdio.h>
#include <string.h>
#include "func.h"

void main_menu()
{
    printf("\n\nChoose one of these options:\n1. Enter a new customer.\n2. Print customer data.\n3. Edit customer.\n4. Delete customer data.\n5. Cash transfer from customer to customer.\n6. Exit.\n\n");
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

    }while(flag);
    *id=Id;
}

void create_new_customer(customer *ptr,int count)
{
    printf("\n\nEnter customer name: ");
    scanf("%s",ptr->name);
    do{ //check validity of cash
    printf("Enter customer cash: ");
    scanf("%lf",&ptr->cash);
    if(ptr->cash<0)
        printf("Cash must be positive! Enter your cash again: ");
    }while(ptr->cash<0);
    printf("Enter customer type(debit or credit): ");
    scanf("%s",ptr->type);
    printf("Enter customer id: ");
    scanf("%i",&ptr->id);
}

int find_id(customer *ptr,int id,int count)
{
    int flag=0,i=0;
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

void edit_customer(customer *ptr,int id,int count)
{
    find_id(ptr,id,count);
    create_new_customer(ptr,count);
}


void print_customer(customer *ptr,int id,int count)
{
    int index=find_id(ptr,id,count);
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


void delete_customer(customer *ptr,int id,int *count)
{
    int index=find_id(ptr,id,*count);
    for(int i=index; i<*count-1; i++)
            {
                strcpy((ptr + i)->name, (ptr + i + 1)->name);
                (ptr+i)->cash=(ptr+i+1)->cash;
                strcpy((ptr + i)->type, (ptr + i + 1)->type);
                (ptr+i)->id=(ptr+i+1)->id;
            }
            (*count)--;
}


void cash_transfer(customer *ptr,int id_sender,int id_receiver,int count,double cash_out)
{
    int flag=0;
    printf("Sender, ");
    int index1=find_id(ptr,id_sender,count);
    printf("Receiver, ");
    int index2=find_id(ptr,id_receiver,count);
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
}
