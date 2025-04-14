#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Constants
const int MAX_BOOKS = 15;
int book_count = 0;

// Gloabal Variables
int book_isbn[MAX_BOOKS];
string book_title[MAX_BOOKS];
string book_author[MAX_BOOKS];

// function prototypes
void add_book();
void view_books();
void view_books_by_author_name();
void search_books_by_title();
int find_book(int isbn);
void edit_book();
void sort_books();
void count_books();
void clear_books();
void swap_books(int index1, int index2);
void display_menu();

int main()
{
    int choice;

    while (true)

    {
        display_menu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            add_book();
            break;
        case 2:
            view_books();
            break;
        case 3:
            view_books_by_author_name();
            break;
        case 4:
            search_books_by_title();
            break;
        case 5:
        {
            int isbn;
            cout << "Please enter the ISBN number of the book: ";
            cin >> isbn;
            int index = find_book(isbn);
            if (index != -1)
            {
                cout << "The book is at index " << index << endl;
            }
            else
            {
                cout << "Book not found.\n";
            }
            break;
        }
        case 6:
            edit_book();
            break;
        case 7:
            sort_books();
            break;
        case 8:
            count_books();
            break;
        case 9:
            clear_books();
            break;
        case 10:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

void display_menu()
{
    cout << "\n\t\t\t\t\t\tLibrary Management System\n\n\n";
    cout << "1. Add Book\n";
    cout << "2. View Books\n";
    cout << "3. View Books By Author Name \n";
    cout << "4. Search Books By Title \n";
    cout << "5. Find Book\n";
    cout << "6. Edit Book\n";
    cout << "7. Sort Books by ISBN\n";
    cout << "8. Count Books\n";
    cout << "9. Clear Books\n";
    cout << "10. Exit\n";
}

void add_book()
{
    if (book_count >= MAX_BOOKS)
    {
        cout << "Library is full. Cannot add more books.\n";
        return;
    }

    cout << "Enter ISBN: ";
    cin >> book_isbn[book_count];
    cin.ignore(); // Ignore leftover newline character

    cout << "Enter title: ";
    getline(cin, book_title[book_count]);

    cout << "Enter author: ";
    getline(cin, book_author[book_count]);

    book_count++;
    cout << "Book added successfully!\n";
}

void view_books()
{
    if (book_count == 0)
    {
        cout << "No books in the library.\n";
        return;
    }

    for (int i = 0; i < book_count; i++)
    {
        cout << "ISBN: " << book_isbn[i] << " | Title: " << book_title[i] << " | Author: " << book_author[i] << endl;
    }
}

int find_book(int isbn)
{
    for (int i = 0; i < book_count; i++)
    {
        if (book_isbn[i] == isbn)
        {
            return i; // Return the index of the book if found
        }
    }
    return -1; // Return -1 if the book is not found
}

void edit_book()
{
    int isbn;
    cout << "Enter book ISBN to edit: ";
    cin >> isbn;

    int index = find_book(isbn); // Pass ISBN to find_book
    if (index == -1)
    {
        cout << "Book not found.\n";
        return;
    }

    cout << "Current title: " << book_title[index] << endl;
    cout << "Enter new title: ";
    cin.ignore(); // Ignore leftover newline character
    getline(cin, book_title[index]);

    cout << "Current author: " << book_author[index] << endl;
    cout << "Enter new author: ";
    getline(cin, book_author[index]);

    cout << "Book details updated.\n";
}

void swap_books(int index1, int index2)
{
    swap(book_isbn[index1], book_isbn[index2]);     // Swap the ISBNs
    swap(book_title[index1], book_title[index2]);   // It Swaps titles
    swap(book_author[index1], book_author[index2]); // It Swaps authors
}
void sort_books()
{
    for (int i = 0; i < book_count - 1; i++)
    {
        for (int j = i + 1; j < book_count; j++)
        {
            if (book_isbn[i] > book_isbn[j])
            {
                swap_books(i, j);
            }
        }
    }

    view_books();

    cout << "Books sorted by ISBN.\n";
}

void count_books()
{
    cout << "The total number of books are : " << book_count;
}

void clear_books()
{
    book_count = 0;
    cout << "All the books have been removed from the Library !!! \n"
         << endl;
}

void view_books_by_author_name()
{
    string author;
    cout << "Please enter the name of the author to search for : " << endl;
    cin.ignore();
    getline(cin, author);

    bool found = false;
    for (int i = 0; i < book_count; i++)
    {
        if (book_author[i] == author)
        {
            cout << "ISBN: " << book_isbn[i] << " | Title: " << book_title[i] << " | Author: " << book_author[i] << endl;
            found = true;
        }
    }

    if (!found)
    {
        cout << "No Books found by that author name !!!" << endl;
    }
}

void search_books_by_title()
{
    string title;
    cout << "Please enter the title of the book : " << endl;
    cin.ignore();
    getline(cin, title);

    bool found = false;
    for (int i = 0; i < book_count; i++)
    {
        if (book_title[i] == title)
        {
            cout << "ISBN: " << book_isbn[i] << " | Title: " << book_title[i] << " | Author: " << book_author[i] << endl;
            found = true;
        }
    }

    if (!found)
    {
        cout << "No book found by that title !!!" << endl;
    }
}