#include <iostream>
#include <string>

using namespace std;

class Library
{
    string book_name;
    int bookid;
    string author_name;
    int copies;

public:
    bool search_book(string);
    void set_data();
    void add_book();
    void issue_book();
    void return_book();
    void display_book();
};

bool Library::search_book(string bookname)
{
    return bookname == book_name;
}

void Library::set_data()
{
    cout << "Enter Book's Name: ";
    cin.ignore();
    getline(cin, book_name);

    cout << "Enter Author's Name: ";
    getline(cin, author_name);

    cout << "Enter Book ID: ";
    cin >> bookid;

    cout << "Enter Number of copies: ";
    cin >> copies;
}

void Library::add_book()
{
    int no;
    cout << "Enter number of copies to add: ";
    cin >> no;
    copies += no;
}

void Library::issue_book()
{
    if (copies > 0)
    {
        copies--;
        cout << "Book Issued Successfully!" << endl;
    }
    else
    {
        cout << "No copies available!" << endl;
    }
}

void Library::return_book()
{
    copies++;
    cout << "Book Returned Successfully!" << endl;
}

void Library::display_book()
{
    cout << "\nBook's Name: " << book_name << endl;
    cout << "Author: " << author_name << endl;
    cout << "Book ID: " << bookid << endl;
    cout << "Copies Available: " << copies << endl;
}

int main()
{
    int choice, t = 0, i;
    string input_book;
    Library book[10];

    while (true)
    {
        cout << "\n===== Library Menu =====" << endl;
        cout << "1. Set Book Data" << endl;
        cout << "2. Add Book" << endl;
        cout << "3. Issue Book" << endl;
        cout << "4. Return Book" << endl;
        cout << "5. Display Book" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            book[t].set_data();
            t++;
            break;

        case 2:
            cout << "Enter Book Name: ";
            cin.ignore();
            getline(cin, input_book);

            for (i = 0; i < t; i++)
            {
                if (book[i].search_book(input_book))
                {
                    book[i].add_book();
                    break;
                }
            }
            if (i == t)
                cout << "Book not found!" << endl;
            break;

        case 3:
            cout << "Enter Book Name: ";
            cin.ignore();
            getline(cin, input_book);

            for (i = 0; i < t; i++)
            {
                if (book[i].search_book(input_book))
                {
                    book[i].issue_book();
                    break;
                }
            }
            if (i == t)
                cout << "Book not found!" << endl;
            break;

        case 4:
            cout << "Enter Book Name: ";
            cin.ignore();
            getline(cin, input_book);

            for (i = 0; i < t; i++)
            {
                if (book[i].search_book(input_book))
                {
                    book[i].return_book();
                    break;
                }
            }
            if (i == t)
                cout << "Book not found!" << endl;
            break;

        case 5:
            cout << "Enter Book Name: ";
            cin.ignore();
            getline(cin, input_book);

            for (i = 0; i < t; i++)
            {
                if (book[i].search_book(input_book))
                {
                    book[i].display_book();
                    break;
                }
            }
            if (i == t)
                cout << "Book not found!" << endl;
            break;

        case 6:
            cout << "Visit Again!" << endl;
            return 0;

        default:
            cout << "Invalid Choice!" << endl;
        }
    }
}
