#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

// Structure for inventory item
struct Item {
    char name[30];
    int barcode;
    float price;
    int quantity;
    int daysToExpire;
};

// Function prototypes
int loadInventory(struct Item items[]);
void saveInventory(struct Item items[], int count);
void displayInventory(struct Item items[], int count);
void addItem(struct Item items[], int *count);
void sellItem(struct Item items[], int count);

int main() {
    struct Item items[MAX_ITEMS];
    int itemCount;
    int choice;

    // Load inventory from file
    itemCount = loadInventory(items);

    do {
        printf("\n===== SUPERMARKET INVENTORY SYSTEM =====\n");
        printf("1. Display Inventory\n");
        printf("2. Add New Item\n");
        printf("3. Sell Item\n");
        printf("4. Save and Exit\n");
        printf("Choose option: ");
        scanf("%d", &choice);
 
        switch (choice) {
            case 1:
                displayInventory(items, itemCount);
                break;

            case 2:
                addItem(items, &itemCount);
                break;

            case 3:
                sellItem(items, itemCount);
                break;

            case 4:
                saveInventory(items, itemCount);
                printf("Inventory saved. Exiting program...\n");
                break;

            default:
                printf("Invalid option!\n");
        }

    } while (choice != 4);

    return 0;
}

// Load inventory from file
int loadInventory(struct Item items[]) {
    FILE *file = fopen("inventory.txt", "r");
    int count = 0;

    if (file == NULL) {
        printf("Inventory file not found. Starting with empty inventory.\n");
        return 0;
    }

    while (fscanf(file, "%s %d %f %d %d",
                  items[count].name,
                  &items[count].barcode,
                  &items[count].price,
                  &items[count].quantity,
                  &items[count].daysToExpire) != EOF) {
        count++;
    }

    fclose(file);
    return count;
}

// Save inventory to file
void saveInventory(struct Item items[], int count) {
    FILE *file = fopen("inventory.txt", "w");

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d %.2f %d %d\n",
                items[i].name,
                items[i].barcode,
                items[i].price,
                items[i].quantity,
                items[i].daysToExpire);
    }

    fclose(file);
}

// Display inventory
void displayInventory(struct Item items[], int count) {
    printf("\n---- INVENTORY LIST ----\n");

    for (int i = 0; i < count; i++) {
        printf("Name:  %s | Barcode:  %d | Price:  %.2f | Stock:  %d | Expire in:  %d days\n",
               items[i].name,
               items[i].barcode,
               items[i].price,
               items[i].quantity,
               items[i].daysToExpire);
    }
}

// Add new item
void addItem(struct Item items[], int *count) {
    if (*count >= MAX_ITEMS) {
        printf("Inventory full!\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", items[*count].name);

    printf("Enter barcode: ");
    scanf("%d", &items[*count].barcode);

    printf("Enter price: ");
    scanf("%f", &items[*count].price);

    printf("Enter quantity: ");
    scanf("%d", &items[*count].quantity);

    printf("Enter days until expiration: ");
    scanf("%d", &items[*count].daysToExpire);

    (*count)++;

    printf("Item added successfully!\n");
}

// Sell item
void sellItem(struct Item items[], int count) {
    int barcode, amount;

    printf("Enter barcode of item to sell: ");
    scanf("%d", &barcode);

    for (int i = 0; i < count; i++) {
        if (items[i].barcode == barcode) {

            printf("Enter quantity to sell: ");
            scanf("%d", &amount);

            if (items[i].quantity >= amount) {
                items[i].quantity -= amount;
                printf("Sale successful!\n");
            } else {
                printf("Not enough stock available!\n");
            }

            return;
        }
    }

    printf("Item not found!\n");
}
