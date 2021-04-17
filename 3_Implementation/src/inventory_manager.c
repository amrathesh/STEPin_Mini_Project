#include "inventory_manager.h"

int additem(FILE * fp, struct item* itm)
{
    int status = 0;
    status = fwrite(itm , 1 , sizeof(struct item) , fp );
    if(status != 0)
        return 0;
    else
        return -1;

}

int deleteitem(struct item* itm)
{
    remove(itm->name);
    printf("\nItem removed successfully");
    return 0;
}

int displayitem(FILE * fp)
{
    int status = 0;
    struct item *itm = (struct item *)calloc(1, sizeof(struct item));
    fread(itm, sizeof(struct item), 1, fp);
    printf("\nItem name : %s",itm->name);
    printf("\nManufacturer name : %s",itm->manufacturer);
    printf("\nUnit cost : %d",itm->unit_cost);
    printf("\nNo of units avaiable in inventory : %d",itm->no_avail);

}

int modifyitem(FILE * fp)
{
    int choice = 0;
    struct item *itm = (struct item *)calloc(1, sizeof(struct item));
    fread(itm, sizeof(struct item), 1, fp);

    while(choice !=4)
    printf("\nWhat you want to change ? ");
    printf("\n\t\t1. Manufacturer");
    printf("\n\t\t2. Unit cost");
    printf("\n\t\t3. No avaiable");
    printf("\n\t\t4. Done modifiying");
    printf("\nEnter your choice :");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1 :
            printf("\nEnter manufacturer name : ");
            scanf("%s",itm->manufacturer);
            break;
        case 2 :
            printf("\nEnter unit cost : ");
            scanf("%d",itm->unit_cost);
            break;
        case 3 :
            printf("\nEnter no of units");
            scanf("%d",itm->no_avail);
            break;
        case 4 :
            fseek(fp,0,SEEK_SET);
            fwrite(itm , 1 , sizeof(struct item) , fp );
            return 0 ;  
            break;
    }


}