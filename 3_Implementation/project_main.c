#include <inventory_manager.h>

int main()
{
    int choice = 0 ;
    FILE *fp;
    struct item *itm = (struct item *)calloc(1, sizeof(struct item));

    system("cls");
    printf("/***************INVENTORY MANAGER***************/");
    printf("\nAuthor : Amrathesh             Guided by : LTTS\n\n\n");
    
    while(choice != 5)
    {
        printf("\n 1. ADD ITEM\n");
	    printf("\n 2. MODIFY ITEM\n");
	    printf("\n 3. SEARCH ITEM\n");
	    printf("\n 4. DELETE ITEM\n");
	    printf("\n 5. EXIT\n");

        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter the item name : ");
                scanf("%s",&itm->name);
                printf("\nEnter the manufacturer name : ");
                scanf("%s",&itm->manufacturer);
                printf("\nEnter the unit cost of the item : ");
                scanf("%d",&itm->unit_cost);
                printf("\nEnter no of units added to inventory : ");
                scanf("%d",itm->no_avail);

                fp = fopen(itm->name,"r");
                if(fp == NULL)
                   fp = fopen(itm->name,"w");
                else
                   printf("\n[INFO] Item already exists in inventory please consider modifiying it");
                additem(fp,itm);
                fclose(fp);
                break;

            case 2:
                printf("\nEnter item name that to be modified : ");
                scanf("%s",&itm->name);
                fp = fopen(itm->name,"r");
                if(fp == NULL)
                   printf("\n[INFO] Item doesn't exists in inventory.");
                else
                   fclose(fp);
                   fopen(itm->name, "rw");
                   modifyitem(fp);
                fclose(fp);
                break;

            case 3: 
                printf("\nEnter item name to be searched : ");
                scanf("%s",&itm->name);
                fp = fopen(itm->name,"r");
                if(fp == NULL)
                   printf("\n Item not found in inventory");
                else
                   printf("\n[INFO] Item found :: Details :: \n");
                   displayitem(fp);
                fclose(fp);
                break;

            case 4:
                fp = fopen(itm->name,"r");
                if(fp == NULL)
                   printf("\n Item not found in inventory");
                else
                   deleteitem(fp);
                fclose(fp);
                break;

            case 5:
                exit(0); 
                break;

            default:
                printf("\nPlease enter a valid choice!\n");


            
        }
 
    


    }

}