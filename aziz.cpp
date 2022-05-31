#include "RSA.h"


//for debugging
void debug_print(string str)
{
    #ifdef debugging
    cout << str << endl;
    #endif // debugging
}

///2
//base M,  power e or d
//Elem is int64 as overflow doesn't happen
Elem pow_mod(Elem base, Elem power, Elem n)
{
    Elem ans = 1;
    while(power)
    {
        if(power % 2)
            ans = (ans * base) % n;

        base = (base * base) % n;
        power /= 2;
    }
    return ans;
}

//from old project
int gcd(int a, int b)
{
    int c = 1;
    if(b > a) //make a start bigger
    {
        int temp = a;
        a = b;
        b = temp;
    }

    while(true)
    {
        c = a % b;
        if(!c) //c == 0
            return b;
        a = b;
        b = c;
    }
}

bool miller_rabin(int n, int a)
{
    int q = n - 1, k = 0;

    //while not odd
    while(q % 2 != 1)
    {
        q /= 2;
        k ++;
    }
    //note k is always >= 1

    if(pow_mod(a, q, n) == 1)
    {
        return true;
    }

    //if k = 1
    //won't loop
    while(--k)
    {
        if(pow_mod(a, q, n) == n-1)
            return true;
        q *= 2;
    }
    return false;
}

int prime(int lower, int upper)
{
    int p, a;
    p = rand() % (upper - lower) + lower; // 1000 < p < 10000
    //p is even
    if(p % 2 == 0)
        p ++;

    for(int i = 0; i < 10; i++)
    {
        a = (rand() % (p-3)) + 2; // 1 < a < n-1
        if(miller_rabin(p, a) == false)
        {
            //restart and choose another prime to test
            i = 0;
            p = rand() % (upper - lower) + lower;
            if(p % 2 == 0)
                p ++;
        }
    }
    return p;
}

void Interact()
{
    srand(time(NULL));
    RSA* rsa = new RSA();
    string text;
    int choose, user_d, user_e, user_n;

    cout << "[0] to quit\n";

    while(true)
    {
        cout    << "[1] Generate random key\n"
                << "[2] Enter your key\n"
                << "[3] Same as last choice (random if 1) / (same key if 2)\n";

        cin >> choose;

        if(choose == 1)
        {
            user_d = 0; user_e = 0; user_n = 0;

            delete rsa;
            rsa = new RSA();
            cout << "\n\n\nKeys and prime numbers used:\n";
            rsa->print_all();
        }
        if(choose == 2)
        {
            cout << "Enter prime number e: "; cin >> user_e;
            cout << "Enter prime number d: "; cin >> user_d;
            cout << "Enter n: "; cin >> user_n;
        }
        else if(choose == 0)
            break;

        cin.ignore();
        cout << "\nEnter text\n";
        getline(cin, text);

        cout << "\n\n\n[1] Encrypt text\n[2] Decrypt text\n";
        cin >> choose;
        if(choose == 1)
        {
            cout << "Encryption:\n" ;
            rsa->encrpt(text, user_e, user_n);
            cout << endl;
        }
        else if(choose == 2)
            cout << "Decryption:\n" << rsa->decrpt(text, user_d, user_n) << endl;
        else if(choose == 0)
            break;
    }
    delete rsa;
    return;
}
