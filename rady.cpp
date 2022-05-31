#include "RSA.h"
#include <string>

void RSA::encrpt(string text , int user_e, int user_n )
{
    if (user_e==0&&user_n==0)//show this process use our prime number or user prime number
    {
        user_e=e;
        user_n=n;
    }
    int siz=text.size();
    if (siz%2==1)//because we use every 2 char as one integer cipher
        {
            text+='.';
            siz++;
        }

    unsigned int M;//M for plan_text &C for cipher
    char a,b;//uses in convert between char and integer
    int* con;//pointer to array that use save cipher number
    con=new int[siz/2];
    for (int i=0,j=0;i<siz;i+=2)
    {
        a = text[i];
        b = text[i+1];
        M=(a * 256)|b;//convert 2 char to integer number
        con[j++] = pow_mod(M, user_e, user_n);//M^e mod n
    }

    for (int i=0;i<(siz/2);i++)//print cipher
    {
        cout<<con[i]<<' ';
    }

    delete[] con;

    return ;
}

string RSA::decrpt(string text, int user_d , int user_n )
{
    if (user_d == 0 && user_n == 0)//show this process use our prime number or user prime number
    {
        user_d=d;
        user_n=n;
    }
    text += ' '; // add the separator to the end
    int numb = 0;
    int* con;//pointer to array that use to save cipher number
    string plan_text;//use to save plan text

    for(unsigned int i=0;i < text.size(); i++)//Find out how many numbers are in the cipher
    {
        if(text[i]==' ')
            numb ++;
    }
    con = new int[numb];
    int opr = 0;

    for(unsigned int j = 0,i = 0; j<text.size(); j++)//convert number from char form to int form and put them in con array
    {
        if(text[j]!=(' '))
        {
            opr*=10;
            opr+=(text[j]-48);
        }
        else
        {
            con[i]=opr;
            i++;
            opr = 0;
        }
    }
    int M=0;//plan text
    for(int i=0;i<numb;i++)
    {
        M=pow_mod(con[i], user_d, user_n);//C^d mod n

        plan_text += M >> 8;//save first char in string
        plan_text += M;// save second char in string
    }

    delete[] con;

    return plan_text;
}
