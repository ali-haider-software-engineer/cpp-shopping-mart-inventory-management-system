#include <iostream>
#include<iomanip>
using namespace std;

// Maximum number of products
const int MAX = 50;

// Function declarations
void displayMenu();
int addProduct(int ids[], string names[], float prices[], int quantities[], int &count);
int showProducts(int ids[], string names[], float prices[], int quantities[], int count);
int searchProduct(int ids[], string names[], float prices[], int quantities[], int count);
int updateProduct(int ids[], string names[], float prices[], int quantities[], int count);
int deleteProduct(int ids[], string names[], float prices[], int quantities[], int &count);
int sellProduct(int ids[], string names[], float prices[], int quantities[], int count);

int main() {
    // Arrays to store product information
    int ids[MAX];
    string names[MAX];
    float prices[MAX];
    int quantities[MAX];
    
    int count = 0; // Current number of products
    int choice;
    
    // Add some sample products
    ids[0] = 101; names[0] = "Milk"; prices[0] = 160; quantities[0] = 50;
    ids[1] = 102; names[1] = "Bread"; prices[1] = 120; quantities[1] = 30;
    ids[2] = 103; names[2] = "Egg"; prices[2] = 30; quantities[2] = 100;
    count = 3;
    
    cout << "=======================================\n";
    cout << "SUPERMARKET INVENTORY MANAGEMENT SYSTEM\n";
    cout << "=======================================\n";
    displayMenu();
    // Main program loop
    do {
        cout <<endl<< "Select what you want to perform from(1-6) in main menu: ";
        cin >> choice;
        
        // Use switch for menu selection
        switch(choice) {
            case 1:
                addProduct(ids, names, prices, quantities, count);
                break;
            case 2:
                showProducts(ids, names, prices, quantities, count);
                break;
            case 3:
                searchProduct(ids, names, prices, quantities, count);
                break;
            case 4:
                updateProduct(ids, names, prices, quantities, count);
                break;
            case 5:
                deleteProduct(ids, names, prices, quantities, count);
                break;
            case 6:
                cout << "\nThank you for using the system!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
        
    } while(choice != 6);
    
    return 0;
}

void displayMenu() {
    cout << "\n===== MAIN MENU =====\n";
    cout << "1. Add New Product\n";
    cout << "2. Show All Products\n";
    cout << "3. Search Product\n";
    cout << "4. Update Product\n";
    cout << "5. Delete Product\n";
    cout << "6. Exit\n";
    cout << "=====================\n";
}

int addProduct(int ids[], string names[], float prices[], int quantities[], int &count) {
    if(count >= MAX) {
        cout << "\nInventory is full! Cannot add more products.\n";
        return 0;
    }
    
    cout << "\n--- ADD NEW PRODUCT ---\n";
    
    // Get product ID
    int newId;
    cout << "Enter Product ID: ";
    cin >> newId;
    
    // Check if ID already exists
    for(int i = 0; i < count; i++) {
        if(ids[i] == newId) {
            cout << "Error: This ID already exists!\n";
            return 0;
        }
    }
    
    // Get product details
    ids[count] = newId;
    
    cout << "Enter Product Name: ";
    cin.ignore(); // Clear input buffer
    getline(cin, names[count]);
    
    cout << "Enter Product Price: Rs.";
    cin >> prices[count];
    
    // Validate price
    if(prices[count] <= 0) {
        cout << "Error: Price must be greater than 0!\n";
        return 0;
    }
    
    cout << "Enter Product Quantity: ";
    cin >> quantities[count];
    
    // Validate quantity
    if(quantities[count] < 0) {
        cout << "Error: Quantity cannot be negative!\n";
        return 0;
    }
    
    count++;
    cout << "\nProduct added successfully!\n";
    return 0;
}

int showProducts(int ids[], string names[], float prices[], int quantities[], int count) {
    if(count == 0) {
        cout << "\nNo products available in the inventory.\n";
        return 0;
    }
    
    cout << "\n----------------------- PRODUCT INVENTORY -----------------------\n";
    cout <<left<<setw(15)<<"ID"<<setw(15)<<"Name"<<setw(15)<<"Price"<<setw(15)<<"Quantity"<<endl;
    cout << "------------------------------------------------------------------\n";
    
    // Loop through all products
    for(int i = 0; i < count; i++) {
        cout <<setw(15)<< ids[i] <<setw(15)
             << names[i] << setw(15)
             << prices[i] << setw(15)
             << quantities[i] << endl;
    }
    return 0;
}

int searchProduct(int ids[], string names[], float prices[], int quantities[], int count) {
    if(count == 0) {
        cout << "\nNo products to search.\n";
        return 0;
    }
    
    int searchId;
    cout << "\nEnter Product ID to search: ";
    cin >> searchId;
    
    // Search for product
    for(int i = 0; i < count; i++) {
        if(ids[i] == searchId) {
            cout << "\nProduct Found!\n";
            cout << "ID: " << ids[i] << endl;
            cout << "Name: " << names[i] << endl;
            cout << "Price: Rs." << prices[i] << endl;
            cout << "Quantity: " << quantities[i] << endl;
            return 0;
        }
    }
    
    cout << "\nProduct with ID " << searchId << " not found.\n";
    return 0;
}

int updateProduct(int ids[], string names[], float prices[], int quantities[], int count) {
    if(count == 0) {
        cout << "\nNo products to update.\n";
        return 0;
    }
    
    int updateId;
    cout << "\nEnter Product ID to update: ";
    cin >> updateId;
    
    // Find product to update
    for(int i = 0; i < count; i++) {
        if(ids[i] == updateId) {
            cout << "\nCurrent Information:\n";
            cout << "Name: " << names[i] << endl;
            cout << "Price: Rs." << prices[i] << endl;
            cout << "Quantity: " << quantities[i] << endl;
            
            cout << "\nEnter new price: Rs.";
            cin >> prices[i];
            
            cout << "Enter new quantity: ";
            cin >> quantities[i];
            
            cout << "\nProduct updated successfully!\n";
            return 0;
        }
    }
    
    cout << "\nProduct not found!\n";
    return 0;
}

int deleteProduct(int ids[], string names[], float prices[], int quantities[], int &count) {
    if(count == 0) {
        cout << "\nNo products to delete.\n";
        return 0;
    }
    
    int deleteId;
    cout << "\nEnter Product ID to delete: ";
    cin >> deleteId;
    
    // Find product to delete
    for(int i = 0; i < count; i++) {
        if(ids[i] == deleteId) {
            cout << "\nDeleting product: " << names[i] << endl;
            
            // Shift all products after this one
            for(int j = i; j < count - 1; j++) {
                ids[j] = ids[j + 1];
                names[j] = names[j + 1];
                prices[j] = prices[j + 1];
                quantities[j] = quantities[j + 1];
            }
            
            count--;
            cout << "Product deleted successfully!\n";
            return 0;
        }
    }
    
    cout << "\nProduct not found!\n";
    return 0;
}


