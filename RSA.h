#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

//#define debugging

using namespace std;

void debug_print(string str);


class RSA
{
private:
    int p, q, n, phi, d, e;
public:
    RSA()
    {
        //this will set p, q, n, phi
        set_values();


        //this will set e
        select_e();

        //this will set d based on values of p, q, n, phi, e
        get_d();
    }

    ///1
    //set p, q, n, phi
    //use prime() function
    void set_values();/*mid*/

    ///1
    //use gcd()
    void select_e(); /*small*/

    ///1
    //use mul_inv()
    void get_d(); /*small*/

    ///1
    //print all values
    //used in main()
    void print_all();/*small*/

    ///2
    //set private and public keys
    //using e, d, n
    void set_keys(); /*small*/

    ///3
    //check need_reset and ((user_e = user_n) == 0)  if true
    //call reset_all(int M)  where  M = text.size() and use private data
    //else if user != 0 use user input
    //else use private data
    //continue the encryption
    ///keep need_reset valid
    void encrpt(string , int user_e = 0, int user_n = 0);/*large*/

    ///3
    //check need_reset and ((user_d = user_n) == 0)  if true
    //call reset_all(int M)  where  M = text.size() and use private data
    //else if user != 0 use user input
    //else use private data
    //continue the decryption
    ///keep need_reset valid
    string decrpt(string , int user_d = 0, int user_n = 0);/*large*/
};

//2
int prime(int lower = 1000, int upper = 10000);

//from old projects
int gcd(int a, int b);

typedef int64_t Elem;
Elem pow_mod(Elem base, Elem power, Elem n);

///1
//a*c = 1 mod b
//return c
int mult_inv(int a, int b); /*large*/

void Interact();

