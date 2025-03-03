#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main()
{

    customer array_struct[100];
    int option=0,count=0;
    while(option!=6)
    {
        main_menu();
        printf("Press a Number[1,6] from one of these following Options: ");
        scanf("%i",&option);
        switch(option)
        {
        case 1:
            printf("<<CREATING NEW CUSTOMER!!>>\n");
            create_new_customer(&array_struct[0],count);
            unique_id((array_struct+0),&array_struct[count].id,count);
            count++;
            break;
        case 2:
            printf("<<PRINTING A SPECIFIC CUSTOMER!!>>\n");
            print_customer(&array_struct[0],count);
            break;
        case 3:
            printf("<<EDITING A SPECIFIC CUSTOMER!!>>\n");
            edit_customer(&array_struct[0],count);
            break;
        case 4:
            printf("<<DELETING A SPECIFIC CUSTOMER!!>>\n");
            delete_customer(&array_struct[0],&count);
            break;
        case 5:
            printf("<<CASH TRANSFER BETWEEN TWO SPECIFIC CUSTOMERS!!>>\n");
            cash_transfer(&*(array_struct+0),count);
            break;
        case 6:
            printf("<<EXIT PROGRAM SUCCESSFULLY!!>>\n");
            exit(0);
        default:
            printf("This option is not available!");
        }
    }
    return 0;
}

