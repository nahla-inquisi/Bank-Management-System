#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main() {

    customer array_struct[100];
    int option=0,count=0,id=0,id_sender=0,id_receiver=0;
    double cash_out=0;
    while(option!=6)
    {
        main_menu();
        printf("Enter one of the above: ");
        scanf("%i",&option);
        switch(option)
        {
        case 1:
            create_new_customer(&array_struct[count],count);
            unique_id((array_struct+0),&array_struct[count].id,count);
            count++;
            break;
        case 2:
            print_customer(&array_struct[0],id,count);
            break;
        case 3:
            edit_customer(&array_struct[0],id,count);
            break;
        case 4:
            printf("Enter customer id: ");
            scanf("%i",&id);
            delete_customer(&array_struct[0],id,&count);
            break;
        case 5:
            printf("Enter cash you want to transfer: ");
            scanf("%lf",&cash_out);//from sender to receiver
            cash_transfer(&*(array_struct+0),id_sender,id_receiver,count,cash_out);
            break;
        case 6:
            exit(0);
        default:
            printf("This option is not available!");
        }
    }
    return 0;
}

