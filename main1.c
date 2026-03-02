#include <stdio.h>

struct item{
    char name[30];
    int barcode;
    float price;
    int quantity;
    int daysToExpire;
};

void options();
void list();
void addition();
void delete();
void searching();
void lowinStock();
void modification();
void updateexp();

int main(){

    int option = 0;
while(1){   
    printf("\n---WELCOME TO WAIL'S STORE---\n");

    options();

    printf("enter your option (1 - 7): ");
    scanf("%d", &option);

    switch(option){
        case 1:
            list();
            break;
        case 2:
            addition();
            break;
        case 3:
            delete();
            break;
        case 4:
            modification();
            break;
        case 5:
            searching();
            break;
        case 6:
            lowinStock();
            break;
        case 7:
            updateexp();
            break; 
        case 8:
            printf("exiting program...\n");
            return 0;
        default:
            printf("you've entered an invalid option!");
    }
};
        return 0;
}

void list(){ 

FILE *pFile = fopen("C:\\Users\\SOMODAL\\Desktop\\list.txt", "r");

char buffer[1024] = {0};

if(pFile == NULL){
        printf("cannot open file\n");
    }

    printf("\n===========================THE LIST OF OBJECTS==========================\n");
    printf("\n");
    printf("NAME         BARCODE      PRICE          QUANTITY         DAYS TO EXPIRE\n");
    printf("------------------------------------------------------------------------\n");

    while(fgets(buffer, sizeof(buffer), pFile) != NULL){
        printf("%s", buffer);
    }

    fclose(pFile);
}

void addition(){

struct item newItem;

    printf("\nADDING AN ITEM\n");
    printf("\nenter item name: ");
    scanf("%s", &newItem.name);
    printf("enter item barcode: ");
    scanf("%d", &newItem.barcode);
    printf("enter item price: ");
    scanf("%f", &newItem.price);
    printf("enter item quantity: ");
    scanf("%d", &newItem.quantity);
    printf("enter item days to expire: ");
    scanf("%d", &newItem.daysToExpire);

    FILE *pFile = fopen("C:\\Users\\SOMODAL\\Desktop\\list.txt", "a");
    if(pFile == NULL){
        printf("cannot open file\n");
    }
    fprintf(pFile, "%-12s %-12d %-14.2f %-16d %-10d\n",
                    newItem.name,
                    newItem.barcode,
                    newItem.price,
                    newItem.quantity,
                    newItem.daysToExpire);
    fclose(pFile);
    if(pFile != NULL){
        printf("\nitem added successfully!\n");
    }
}

void delete(){

FILE *pFile = fopen("C:\\Users\\SOMODAL\\Desktop\\list.txt", "r");
FILE *pTemp = fopen("C:\\Users\\SOMODAL\\Desktop\\temp.txt", "w");

struct item item;
int found = 0;
int deletionCode = 0;

printf("\nDELETING A PRODUCT\n");
printf("\nEnter the barcode of the item you want to delete: ");
scanf("%d", &deletionCode);

while(fscanf(pFile, "%s %d %f %d %d",
                    &item.name,
                    &item.barcode,
                    &item.price,
                    &item.quantity,
                    &item.daysToExpire) != EOF){

    if(item.barcode != deletionCode){
        fprintf(pTemp, "%-12s %-12d %-14.2f %-16d %-10d\n",
                        item.name,
                        item.barcode,
                        item.price,
                        item.quantity,
                        item.daysToExpire);
    }
    else{
        found = 1;
    }
}
fclose(pFile);
fclose(pTemp);

remove("C:\\Users\\SOMODAL\\Desktop\\list.txt");
rename("C:\\Users\\SOMODAL\\Desktop\\temp.txt",
       "C:\\Users\\SOMODAL\\Desktop\\list.txt");

if(found == 1){
    printf("\nitem was deleted successfully!\n");
}
else{
    printf("item NOT found\n");
}
}

void modification(){

FILE *pFile = fopen("C:\\Users\\SOMODAL\\Desktop\\list.txt", "r");
FILE *pTemp = fopen("C:\\Users\\SOMODAL\\Desktop\\temp.txt", "w");

int found = 0;
int choice = 0;
int barcodesearch = 0;
struct item item; 
char newname[30];
int newbarcode = 0, newquantity = 0, newexp = 0;
float newprice = 0.00;

    printf("\nwhat do you want to modify?\n");
    printf("1. name\n");
    printf("2. barcode\n");
    printf("3. price\n");
    printf("4. quantity\n");
    printf("5. daysToExpire\n");
    printf("enter your choice: ");
    scanf("%d", &choice);
    printf("\nnow enter item barcode: ");
    scanf("%d", &barcodesearch);

    switch(choice){
        case 1:
            while(fscanf(pFile, "%s %d %f %d %d",
                     item.name,
                    &item.barcode,
                    &item.price,
                    &item.quantity,
                    &item.daysToExpire) != EOF){

                if(item.barcode == barcodesearch){
                    printf("\nenter the new name: ");
                    scanf(" %s", &newname);
                    fprintf(pTemp, "%-12s %-12d %-14.2f %-16d %-10d\n",
                                    newname,
                                    item.barcode,
                                    item.price,
                                    item.quantity,
                                    item.daysToExpire);
                    found = 1;
                }
                else{
                    fprintf(pTemp, "%-12s %-12d %-14.2f %-16d %-10d\n",
                                    item.name,
                                    item.barcode,
                                    item.price,
                                    item.quantity,
                                    item.daysToExpire);
                }
            }
            break;
        case 2:
            while(fscanf(pFile, "%s %d %f %d %d",
                     item.name,
                    &item.barcode,
                    &item.price,
                    &item.quantity,
                    &item.daysToExpire) != EOF){

                if(item.barcode == barcodesearch){
                    printf("\nenter the new barcode: ");
                    scanf("%d", &newbarcode);
                    fprintf(pTemp, "%-12s %-12d %-14.2f %-16d %-10d\n",
                                    item.name,
                                    newbarcode,
                                    item.price,
                                    item.quantity,
                                    item.daysToExpire);
                    found = 1;
                }
                else{
                    fprintf(pTemp, "%-12s %-12d %-14.2f %-16d %-10d\n",
                                    item.name,
                                    item.barcode,
                                    item.price,
                                    item.quantity,
                                    item.daysToExpire);
                }
            }
            break;
        case 3:
            while(fscanf(pFile, "%s %d %f %d %d",
                     item.name,
                    &item.barcode,
                    &item.price,
                    &item.quantity,
                    &item.daysToExpire) != EOF){

                if(item.barcode == barcodesearch){
                    printf("\nenter the new price: ");
                    scanf("%f", &newprice);
                    fprintf(pTemp, "%-12s %-12d %-14.2f %-16d %-10d\n",
                                    item.name,
                                    item.barcode,
                                    newprice,
                                    item.quantity,
                                    item.daysToExpire);
                    found = 1;
                }
                else{
                    fprintf(pTemp, "%-12s %-12d %-14.2f %-16d %-10d\n",
                                    item.name,
                                    item.barcode,
                                    item.price,
                                    item.quantity,
                                    item.daysToExpire);
                }
            }
            break;
        case 4:
            while(fscanf(pFile, "%s %d %f %d %d",
                     item.name,
                    &item.barcode,
                    &item.price,
                    &item.quantity,
                    &item.daysToExpire) != EOF){

                if(item.barcode == barcodesearch){
                    printf("\nenter the new quantity: ");
                    scanf("%d", &newquantity);
                    fprintf(pTemp, "%-12s %-12d %-14.2f %-16d %-10d\n",
                                    item.name,
                                    item.barcode,
                                    item.price,
                                    newquantity,
                                    item.daysToExpire);
                    found = 1;
                }
                else{
                    fprintf(pTemp, "%-12s %-12d %-14.2f %-16d %-10d\n",
                                    item.name,
                                    item.barcode,
                                    item.price,
                                    item.quantity,
                                    item.daysToExpire);
                }
            }
            break;
        case 5:
            while(fscanf(pFile, "%s %d %f %d %d",
                     item.name,
                    &item.barcode,
                    &item.price,
                    &item.quantity,
                    &item.daysToExpire) != EOF){

                if(item.barcode == barcodesearch){
                    printf("\nenter the new expiration day: ");
                    scanf("%d", &newexp);
                    fprintf(pTemp, "%-12s %-12d %-14.2f %-16d %-10d\n",
                                    item.name,
                                    item.barcode,
                                    item.price,
                                    item.quantity,
                                    newexp);
                    found = 1;
                }
                else{
                    fprintf(pTemp, "%-12s %-12d %-14.2f %-16d %-10d\n",
                                    item.name,
                                    item.barcode,
                                    item.price,
                                    item.quantity,
                                    item.daysToExpire);
                }
                }

        default:
            printf("you've entered an invalid option!");
    
    }
        fclose(pFile);
        fclose(pTemp);

        remove("C:\\Users\\SOMODAL\\Desktop\\list.txt");
        rename("C:\\Users\\SOMODAL\\Desktop\\temp.txt",
               "C:\\Users\\SOMODAL\\Desktop\\list.txt");
                
        if(found == 0){
             printf("item not found");
        }
        else{
             printf("\nitem was modified successfully!\n");
        }
}

void searching(){

FILE *pFile = fopen("C:\\Users\\SOMODAL\\Desktop\\list.txt", "r");

struct item item;
int barcode = 0;
int found = 0;

if (pFile == NULL) {
        printf("Cannot open file!\n");
        return;
    }

printf("--searching engine--\n");
printf("enter barcode of product: ");
scanf("%d", &barcode);

while(fscanf(pFile, "%s %d %f %d %d",
                     item.name,
                    &item.barcode,
                    &item.price,
                    &item.quantity,
                    &item.daysToExpire) != EOF){

    if(item.barcode == barcode){
        printf("\nyour item has been found!\n");
        printf("\n==============================search result=============================\n");
        printf("\n");
        printf("NAME         BARCODE      PRICE          QUANTITY         DAYS TO EXPIRE\n");
        printf("------------------------------------------------------------------------\n");
        printf("%-12s %-12d %-14.2f %-16d %-10d\n",
                   item.name,
                   item.barcode,
                   item.price,
                   item.quantity,
                   item.daysToExpire);
        found = 1;
        break;
    }
}
 fclose(pFile);

 if (!found) {
        printf("Item NOT found\n");
    }

}

void lowinStock(){

FILE *pFile = fopen("C:\\Users\\SOMODAL\\Desktop\\list.txt", "r");

struct item item;
int found = 0;

if (pFile == NULL) {
        printf("Cannot open file!\n");
        return;
    }
    printf("\n============================low in stock items==========================\n");
    printf("\n");
    printf("NAME         BARCODE      PRICE          QUANTITY         DAYS TO EXPIRE\n");
    printf("------------------------------------------------------------------------\n");
while(fscanf(pFile, "%s %d %f %d %d",
                     item.name,
                    &item.barcode,
                    &item.price,
                    &item.quantity,
                    &item.daysToExpire) != EOF){

    if(item.quantity < 10){
        printf("%-12s %-12d %-14.2f %-16d %-10d\n",
                   item.name,
                   item.barcode,
                   item.price,
                   item.quantity,
                   item.daysToExpire);
        found = 1;
    }
}
 fclose(pFile);

 if (!found) {
        printf("No items are low in stock\n");
    }

}

void updateexp(){

FILE *pUpdate = fopen("C:\\Users\\SOMODAL\\Desktop\\list.txt", "r");
FILE *pTemp = fopen("C:\\Users\\SOMODAL\\Desktop\\temp.txt", "w");

struct item item;

if (pUpdate == NULL) {
        printf("Cannot open file!\n");
        return;
    }
while(fscanf(pUpdate, "%s %d %f %d %d",
                     item.name,
                    &item.barcode,
                    &item.price,
                    &item.quantity,
                    &item.daysToExpire) != EOF){
        fprintf(pTemp, "%-12s %-12d %-14.2f %-16d %-10d\n",
                                item.name,
                                item.barcode,
                                item.price,
                                item.quantity,
                                item.daysToExpire - 1);
    }; 
fclose(pUpdate);
fclose(pTemp);

remove ("C:\\Users\\SOMODAL\\Desktop\\list.txt");
rename ("C:\\Users\\SOMODAL\\Desktop\\temp.txt",
        "C:\\Users\\SOMODAL\\Desktop\\list.txt");
    
    printf("\nexpiration days updated successfully!\n");
};

void options(){
    printf("choose an option!\n");
    printf("1. list of items\n");
    printf("2. add an item\n");
    printf("3. delete an item\n");
    printf("4. modify an item\n");
    printf("5. search an item\n");
    printf("6. low in stock\n");
    printf("7. update expiration days\n");
    printf("8. exit\n");
}