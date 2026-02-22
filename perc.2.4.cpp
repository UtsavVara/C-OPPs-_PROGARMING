#include <iostream>
#include <string>
using namespace std;

class Inventory
{
    string name;
    int id;
    float price;
    int quantity;

public:
    Inventory()
    {
        name = "null";
        id = -1;
        price = 0;
        quantity = 0;
    }

    Inventory(string name_input, int id_input, float price_input, int quantity_input)
    {
        name = name_input;
        id = id_input;
        price = price_input;
        quantity = quantity_input;
    }

    void sell()
    {
        int sell_qty;
        cout << "Enter Quantity to Sell: ";
        cin >> sell_qty;

        if (sell_qty > 0 && sell_qty <= quantity)
        {
            quantity -= sell_qty;
            cout << "Item Sold Successfully!" << endl;
        }
        else
        {
            cout << "Insufficient Quantity!" << endl;
        }
    }

    void add_stock()
    {
        int add_qty;
        cout << "Enter Quantity to Add: ";
        cin >> add_qty;

        if (add_qty > 0)
        {
            quantity += add_qty;
            cout << "Stock Added Successfully!" << endl;
        }
        else
        {
            cout << "Invalid Quantity!" << endl;
        }
    }

    void view_item_info()
    {
        cout << "\nItem ID: " << id
             << " | Name: " << name
             << " | Price: " << price
             << " | Quantity: " << quantity << endl;
    }
};

int main()
{
    int choice, i;
    int t = 0;
    int item_no;
    string name;
    float price;
    int quantity;

    Inventory item[10];

    while (true)
    {
        cout << "\n===== Inventory Menu =====" << endl;
        cout << "1. Add Item" << endl;
        cout << "2. View Item Summary" << endl;
        cout << "3. Add Stock" << endl;
        cout << "4. Sell Item" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (t < 10)
            {
                cout << "Enter Item Name: ";
                cin.ignore();
                getline(cin, name);

                cout << "Enter Item Price: ";
                cin >> price;

                cout << "Enter Item Quantity: ";
                cin >> quantity;

                item[t] = Inventory(name, t, price, quantity);
                t++;
            }
            else
            {
                cout << "Inventory Full!" << endl;
            }
            break;

        case 2:
            for (i = 0; i < t; i++)
                item[i].view_item_info();
            break;

        case 3:
            cout << "Enter Item ID: ";
            cin >> item_no;

            if (item_no >= 0 && item_no < t)
                item[item_no].add_stock();
            else
                cout << "Invalid Item ID!" << endl;
            break;

        case 4:
            cout << "Enter Item ID: ";
            cin >> item_no;

            if (item_no >= 0 && item_no < t)
                item[item_no].sell();
            else
                cout << "Invalid Item ID!" << endl;
            break;

        case 5:
            cout << "Thank You! Visit Again." << endl;
            return 0;

        default:
            cout << "Invalid Choice! Try Again." << endl;
        }
    }
}
