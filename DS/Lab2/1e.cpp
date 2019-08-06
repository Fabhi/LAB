#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
   char str[20],a[20];
   int i, n, l, pos;

   cout<<"Enter the string\n";
   cin>>str;
   fflush(stdin);

   cout<<"Enter the substring to be deleted\n";
   cin>>a;
   fflush(stdin);
   
   n=strlen(a);
   l=strlen(str);
   
   for(i = pos + n; i < l; i++)
   {
      str[i - n] = str[i];
   }
   str[i - n] = '\0';
   cout<<"The string is"<<str;
}