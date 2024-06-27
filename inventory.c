//
//  main.c
//  Inventory 3
//
//  Created by User One on 27/06/2024.
//

#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100
struct item{
    char name[50];
    int quantity;
    float price;
};

struct item inventory[MAX_ITEMS];
int numItems = 0;

void addItem(void);
void displayInventory(void);
void updateItem(void);
float calculateTotalValue(void);

int main(void){
    int choice;
    
    do {
        printf("\nInventory Management System\n");
        printf("1.Add Item\n");
        printf("2.Display Inventory\n");
        printf("3.Update Item\n");
        printf("4.Calculate Total Value\n");
        printf("5.Exit\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                addItem();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                updateItem();
                break;
            case 4:{
                float totalValue = calculateTotalValue();
                printf("Total Inventory Value:%.2f", totalValue);
            }
                break;
            case 5:
                printf("Exiting.....");
                break;
            default:
                printf("invalid option.Enter number between 1 and 5.\n");
                break;
        }
    }while (choice != 5);
    
    return 0;
}

void addItem(void){
    if(numItems > MAX_ITEMS){
        printf("Cannot add item.Invenentory full.");
        return;
    }
    struct item new_item;
    
    printf("Item name: \n");
    scanf("%s",new_item.name);
    printf("Quantity: \n");
    scanf("%d", &new_item.quantity);
    printf("price per unit: \n");
    scanf("%f", &new_item.price);
    
    inventory[numItems++] = new_item;
    printf("Item has been added succesfully\n");
        
    }
void displayInventory(void){
    if(numItems == 0 ){
        printf("inventory is empty.\n");
        return;
    }
    printf("inventory:\n");
    for(int i = 0; i < numItems; i++){
        printf("%s - quantity:%d price per unit:%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}
void updateItem(void){
    if (numItems == 0){
        printf("inventory is empty.can't update\n");
        return;
    }
    
    char itemName[50];
    int newQuantity;
    
    printf("item name to update: \n");
    scanf("%s", itemName);
    
    int found = 0;
        for (int i = 0; i < numItems; ++i) {
            if (strcmp(itemName, inventory[i].name) == 0) {
                printf("New quantity: ");
                scanf("%d", &newQuantity);
                inventory[i].quantity = newQuantity;
                printf("Item updated successfully!\n");
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Item not found in inventory.\n");
        }
    }

float calculateTotalValue(void) {
        float totalValue = 0.0;
        for (int i = 0; i < numItems; ++i) {
            totalValue += inventory[i].quantity * inventory[i].price;
        }
        return totalValue;
    }
    
