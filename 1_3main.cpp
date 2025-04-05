#include <iostream>
#include <vector>
using namespace std;

struct Product {
    string name;
    double price;
    int quantity;
};

void addProduct(vector<Product>& inventory) {
    Product p;
    cout << "Enter product name: ";
    cin.ignore();
    getline(cin, p.name);
    cout << "Enter product price: ";
    cin >> p.price;
    cout << "Enter quantity in stock: ";
    cin >> p.quantity;
    inventory.push_back(p);
    cout << "Product added.\n";
}

void updateQuantity(vector<Product>& inventory) {
    string productName;
    int newQuantity;
    cout << "Enter product name to update: ";
    cin.ignore();
    getline(cin, productName);

    for (auto& p : inventory) {
        if (p.name == productName) {
            cout << "Enter new quantity: ";
            cin >> newQuantity;
            p.quantity = newQuantity;
            cout << "Quantity updated.\n";
            return;
        }
    }
    cout << "Product not found.\n";
}

void displayProducts(const vector<Product>& inventory) {
    if (inventory.empty()) {
        cout << "No products in inventory.\n";
        return;
    }
    for (const auto& p : inventory) {
        cout << "Name: " << p.name
             << ", Price: $" << p.price
             << ", Quantity: " << p.quantity << endl;
    }
}

int main() {
    vector<Product> inventory;
    int choice;

    do {
        cout << "\n1. Add product\n2. Update quantity\n3. Display products\n4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addProduct(inventory);
            break;
            case 2:
                updateQuantity(inventory);
            break;
            case 3:
                displayProducts(inventory);
            break;
            case 4:
                cout << "Exiting...\n";
            break;
            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}
