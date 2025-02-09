#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_ITEMS = 100;

class Stationary_Shop {
private:
    string items[MAX_ITEMS];
    double prices[MAX_ITEMS];
    int item_count;

public:
    Stationary_Shop() : item_count(0) {}

    void add_item() {
        if (item_count >= MAX_ITEMS) {
            cout << "Shop is full! Cannot add more items.\n";
            return;
        }
        cout << "Enter item name: ";
        cin.ignore();
        getline(cin, items[item_count]);
        cout << "Enter item price: ";
        cin >> prices[item_count];
        item_count++;
        cout << "Item added successfully!\n";
    }

    void fetch_items() {
        if (item_count == 0) {
            cout << "No items in the shop yet.\n";
            return;
        }
        cout << "Items available:\n";
        for (int i = 0; i < item_count; i++) {
            cout << i + 1 << ". " << items[i] << endl;
        }
    }

    void edit_price() {
        fetch_items();
        if (item_count == 0) return;
        
        int index;
        cout << "Enter item number to update price: ";
        cin >> index;
        
        if (index < 1 || index > item_count) {
            cout << "Invalid item number!\n";
            return;
        }
        
        cout << "Enter new price for " << items[index - 1] << ": ";
        cin >> prices[index - 1];
        cout << "Price updated successfully!\n";
    }

    void view_all_items() {
        if (item_count == 0) {
            cout << "No items in the shop yet.\n";
            return;
        }
        cout << "Items and Prices:\n";
        cout << left << setw(20) << "Item Name" << setw(10) << "Price\n";
        cout << "------------------------------\n";
        for (int i = 0; i < item_count; i++) {
            cout << left << setw(20) << items[i] << " $" << fixed << setprecision(2) << prices[i] << endl;
        }
    }
};

int main() {
    Stationary_Shop shop;
    int choice;

    while (true) {
        cout << "\n--- Stationary Shop Menu ---\n";
        cout << "1. Add Item\n";
        cout << "2. Fetch Items\n";
        cout << "3. Edit Item Price\n";
        cout << "4. View All Items and Prices\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: shop.add_item(); break;
            case 2: shop.fetch_items(); break;
            case 3: shop.edit_price(); break;
            case 4: shop.view_all_items(); break;
            case 5: cout << "Exiting program...\n"; return 0;
            default: cout << "Invalid choice! Please try again.\n";
        }
    }
}
