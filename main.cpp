#include <iostream>
#include "RSA.h"
#include <stdlib.h>
#include <time.h>
#include <string>

//#define Select_Random

//24

using namespace std;

#ifdef Select_Random
template <typename E>
void Swap(E& a, E& b)
{
    E temp = a;
    a = b;
    b = temp;
}

void select()
{
    int number[3] = {1, 2, 3};
    char name[3] = {'R', 'Z', 'I'};

    srand(time(NULL));

    for(int i = 0; i < 10; i++)
    {
        int r1 = rand() % 3;
        int r2 = rand() % 3;
        Swap(number[r1], number[r2]);

    }

    for(int i = 0; i < 10; i++)
    {
        int r1 = rand() % 3;
        int r2 = rand() % 3;
        Swap(name[r1], name[r2]);
    }

    for(int i = 0; i < 3; i++)
    {
        switch (name[i])
        {
        case 'I':
            cout << "islam";
            break;
        case 'R':
            cout << "rady";
            break;
        case 'Z':
            cout << "aziz";
            break;
        }
        cout << " does " << number[i] << '\n';
    }
    return;
}
#endif // Select_Random


int main()
{
#ifdef Select_Random
    select();
#endif

    Interact();

    return 0;
}
