#include<iostream>
using namespace std;

struct node {
    int id;
    char name[15];
    int qty;
    int price;
    node *nptr;
};

node *fptr = NULL;

void printLine() {
    cout << "\n*********************************************\n";
}

int main() {
    int x, c, d, j, i = 0;
    int p, s, n, k, v, r;
    int total = 0;

    for (;;) {
        printLine();
        cout << "Please choose an option:\n\n";
        cout << "1. ADD INVENTORY ITEM\n";
        cout << "2. MAKE AN INVENTORY SALE\n";
        cout << "3. BUY INVENTORY ITEM FROM SUPPLIER\n";
        cout << "4. CHECK STOCK\n";
        cout << "\nYour choice: ";
        cin >> d;

        if (d == 1) {
            i++;
            node *ptr = new node;

            cout << "\nEnter the data for inventory item " << i << ":\n";
            cout << "Name of product: ";
            cin >> ptr->name;
            cout << "ID: ";
            cin >> ptr->id;
            cout << "Quantity: ";
            cin >> ptr->qty;
            cout << "Price: ";
            cin >> ptr->price;

            if (fptr == NULL) {
                ptr->nptr = NULL;
                fptr = ptr;
            } else {
                node *currentptr = fptr;
                while (currentptr->nptr != NULL) {
                    currentptr = currentptr->nptr;
                }
                ptr->nptr = fptr;
                fptr = ptr;
            }
        } 
        else if (d == 2) {
            if (fptr == NULL) {
                cout << "\nSorry, no data exists yet.\n";
            } 
            else {
                node *currentptr = fptr;
                bool itemFound = false;

                cout << "\nPlease enter the ID of the item you want to sell: ";
                cin >> s;

                while (currentptr != NULL) {
                    if (currentptr->id == s) {
                        cout << "\nItem found: " << currentptr->name << "\n";
                        cout << "Available quantity: " << currentptr->qty << "\n";
                        cout << "Please enter the quantity to sell: ";
                        cin >> x;

                        if (currentptr->qty >= x) {
                            currentptr->qty -= x;
                            c = currentptr->price * x;
                            cout << "\nSale successful!\n";
                            cout << "Name: " << currentptr->name << "\n";
                            cout << "Quantity sold: " << x << "\n";
                            cout << "Total cost: " << c << "\n";
                            cout << "Remaining stock: " << currentptr->qty << "\n";
                        } 
                        else {
                            cout << "\nNot enough stock available.\n";
                        }

                        itemFound = true;
                        break;
                    }
                    currentptr = currentptr->nptr;
                }

                if (!itemFound) {
                    cout << "\nSorry, no item with ID " << s << " found.\n";
                }
            }
        } 
        else if (d == 3) {
            cout << "\nPlease enter the ID of the product to add quantity: ";
            cin >> k;

            if (fptr == NULL) {
                cout << "\nSorry, no data exists yet.\n";
            } 
            else {
                node *currentptr = fptr;
                bool itemFound = false;

                while (currentptr != NULL) {
                    if (currentptr->id == k) {
                        cout << "\nItem found: " << currentptr->name << "\n";
                        cout << "Current quantity: " << currentptr->qty << "\n";
                        cout << "Enter the quantity to add: ";
                        cin >> r;
                        currentptr->qty += r;
                        cout << "\nQuantity updated. New stock: " << currentptr->qty << "\n";
                        itemFound = true;
                        break;
                    }
                    currentptr = currentptr->nptr;
                }

                if (!itemFound) {
                    cout << "\nSorry, no item with ID " << k << " found.\n";
                }
            }
        } 
        else if (d == 4) {
            if (fptr == NULL) {
                cout << "\nSorry, no data exists yet.\n";
            } 
            else {
                node *currentptr = fptr;
                cout << "\nCurrent stock:\n";
                while (currentptr != NULL) {
                    cout << "\nName: " << currentptr->name;
                    cout << "\nID: " << currentptr->id;
                    cout << "\nQuantity: " << currentptr->qty;
                    cout << "\nPrice: " << currentptr->price << "\n";
                    currentptr = currentptr->nptr;
                }
            }
        } 
        else {
            cout << "\nInvalid option, please try again.\n";
        }
    }

    getchar();
    return 0;
}

