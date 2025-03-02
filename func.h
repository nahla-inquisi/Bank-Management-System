#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

typedef struct
{
    char name[50];
    double cash;
    char type[7];
    int id;
}customer;

void main_menu();
void create_new_customer(customer *ptr,int count);
void unique_id(customer *ptr,int* id,int count);
void edit_customer(customer *ptr,int id,int count);
void print_customer(customer *ptr,int id,int count);
void delete_customer(customer *ptr,int id,int *count);
void cash_transfer(customer *ptr,int id_sender,int id_receiver,int count,double cash_out);
#endif // FUNC_H_INCLUDED
