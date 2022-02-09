#include "TChar.h"
#include "stdio.h"
#include "conio.h"
#include <iostream>
using namespace std;

const int lim = 25;
void getline(char* str, int lim)
{
    int c, i;
    c = 1;
    for (i = 0; (i < lim - 1) && (c != (int)'\n'); i++)
    {
        c = getchar();
        str[i] = c;
    }
    str[i] = '\0';
}

struct Book
{
    int UDK;
    char FIO[40];
    char Bookname[40];
    int year;
    int Number;
    Book* next;
};
Book* firstbook = new Book;
Book* lastbook = firstbook;
bool isFirst = true;


int main(int argc, _TCHAR* argv[])
{

    int a, b, c;

    int zapros;
    char* str;
    printf("Napishite obshee kolichestvo knig v biblioteki\n");
    cin >> a;

    for (int i = 0; i <= a - 1; i++)
    {
        if (isFirst) isFirst = false;
        else
        {
            lastbook->next = new Book;
            lastbook = lastbook->next;
        }
        printf("Kniga #%d\n", i + 1);
        printf("UDK: ");
        cin >> lastbook->UDK;
        putchar((int)'\n');
        fflush(stdin);
        printf("Autor: ");
        str = &lastbook->FIO[0];
        cin.ignore();
        getline(str, lim);
        putchar((int)'\n');
        printf("BookName: ");
        str = &lastbook->Bookname[0];
        getline(str, lim);
        putchar((int)'\n');
        printf("Year: ");
        cin >> lastbook->year;
        putchar((int)'\n');
        printf("Number: ");
        cin >> lastbook->Number;
        lastbook->next = NULL;
    }
   while(true)
   {
        fflush(stdin);
        printf("Vibor operacii\n");
        cout << "1 - Vidacha knig" << endl;
        cout << "2 - Sdacha knig" << endl;
        cout << "3 - Info pro knigi v biblioteke" << endl;
        cout << "4 - Exit" << endl;

        cin >> b;

        while (true)
        {
            if (b > 4)
            {
      cout << " Nepravilnoe chislo, poshalusrta vvedite pravilnoe:" << endl;
      cin >> b;
            }
            else break;
        }
        switch (b)
        {
        case 1:
            printf("Vvedite zapros UDK: ");
            cin >> zapros;
            c = 0;
            for (Book* t = firstbook; t != NULL; t = t->next)
            {
                if (zapros == t->UDK)
                {
                    if (t->Number != 0)
                    {
                        t->Number = t->Number - 1;
                        break;
                    }
                    else
                    {
                        printf("Kniga vudana\n");
                        break;
                    }
                }
                if (c == a - 1) printf("Takoy knigi net v biblioteke\n");
                c++;
            }
            break;
        case 2:
            printf("Vedite zapros UDK: ");
            cin >> zapros;
            c = 0;
            for (Book* t = firstbook; t != NULL; t = t->next)
            {
                if (zapros == t->UDK)
                {
                    t->Number = t->Number + 1;
                    break;
                }
                if (c == a - 1) printf("takoy knigi net v biblioteke\n");
                t = t->next;
                c++;
            }
            break;
        case 3:
            printf("UDK | AUTOR     | NAMEBOOK    | YEAR | NUMBER\n");
            for (Book* t = firstbook; t != NULL; t = t->next)
            {
                printf("%d      ", t->UDK);
                for (int i = 0; t->FIO[i] != 10; i++)
                    cout << t->FIO[i];
                cout << "    ";
                for (int i = 0; t->Bookname[i] != 10; i++)
                    cout << t->Bookname[i];
                cout << "    ";
                printf("%d  ", t->year);
                printf("%d\n", t->Number);
            }
            break;
        case 4:

            return false;

   
        }

    }
    delete firstbook;

}



