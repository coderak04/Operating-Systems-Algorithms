#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BOOKS 100
typedef struct 
{
    int access_no;
    char author[50];
    char title[50];
    int flag;
} Book;

Book library[MAX_BOOKS];
int num_books = 0;

void display_book_info(Book book) 
{
    printf("\nAccess number: %d", book.access_no);
    printf("\nAuthor: %s", book.author);
    printf("\nTitle: %s", book.title);
    printf("\nFlag: %s", book.flag ? "Issued\n" : "Not issued\n");
}

void add_new_book() 
{
    if (num_books == MAX_BOOKS) 
    {
        printf("Library is full.\n");
        return;
    }
    printf("Enter book details:\n");
    printf("Access No: ");
    scanf("%d", &library[num_books].access_no);
    printf("Author: ");
    getchar();
    gets(library[num_books].author);
    printf("Title: ");
    gets(library[num_books].title);
    library[num_books].flag = 0;
    num_books++;
    printf("Book added successfully.\n");
}

void display_books_by_author() 
{
    char author_name[50];
    printf("\nEnter author name: ");
    getchar();
    gets(author_name);
    int count = 0;
    printf("Access No.\tAuthor\t\t\tTitle\t\t\tIssued\n");
    for (int i = 0; i < num_books; i++) {
        if (strcmp(library[i].author, author_name) == 0) {
            printf("%d\t\t%s\t\t%s\t\t%s\n", library[i].access_no, library[i].author, library[i].title, library[i].flag ? "Yes" : "No");
            count++;
        }
    }
    if (count == 0) 
    {
        printf("No books found for author '%s'.\n", author_name);
    } 
    else 
    {
        printf("Total books found for author '%s': %d\n", author_name, count);
    }
}

void display_total_books() 
{
    printf("\nTotal number of books in library: %d\n", num_books);
}
void display_books_by_title() 
{
    char title[50];
    printf("\nEnter book title: ");
    getchar();
    gets(title);
    int count = 0;
    for (int i = 0; i < num_books; i++) 
    {
        if (strcmp(library[i].title, title) == 0) 
        {
            count++;
        }
    }
    if (count == 0) 
    {
        printf("No books found for title '%s'.\n", title);
    } 
    else 
    {
        printf("Total books found for title '%s': %d\n", title, count);
    }
}
void issue_book() 
{
    int access_no;
    printf("\nEnter access no. of book to issue: ");
    scanf("%d", &access_no);
    for (int i = 0; i < num_books; i++) 
    {
        if (library[i].access_no == access_no) 
        {
            if (library[i].flag) 
            {
                printf("Book is already issued.\n");
            } 
            else 
            {
                library[i].flag = 1;
                printf("Book issued successfully.\n");
            }
            return;
        }
    }
    printf("Book not found.\n");
}
int main() {
    int choice;
    for(;;)
    {
        printf("\n1.Display book information\t2.Add a new book\n");
        printf("3.Display books by author\t4.Display total number of books\n");
        printf("5.Issue a book\t6.Display books by title\n");
        printf("0.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                if (num_books == 0) 
                {
                    printf("No books in the library!\n");
                } 
                else 
                {
                    printf("\nBook information:");
                    for (int i = 0; i < num_books; i++) 
                    {
                        display_book_info(library[i]);
                    }
                }
                break;
            case 2:
                add_new_book();
                break;
            case 3:
                display_books_by_author();
                break;
            case 4:
                display_total_books();
                break;
            case 5:
                issue_book();
                break;
            case 6:
                display_books_by_title();
                break;
        }
        if(choice==0)
        {
            break;
        }
    }

    return 0;
}