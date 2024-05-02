#include<iostream>
#include<string>
#include<conio.h>
using namespace std;

int main()
{
  string Password = "Admin@123";
  int attempt = 3;
  while(attempt>0)
  {
    string Enter_Password;
    cout<<endl<<"Enter Password: ";
    while(true)
    {
      char ch = _getch();
      if(ch=='\r') break;
      Enter_Password.push_back(ch);
      cout<<"*";
    }
    if(Enter_Password==Password)
    {
      cout<<endl<<"Correct!!! You Have Enter The Correct Password.";
      break;
    }
    else cout<<endl<<"Incorrect!!! You Have Enter The Incorrect Password.";
    attempt--;
    cout<<endl<<"Remaining Attempts are "<<attempt;
    if(attempt==0) cout<<endl<<"Access Denied! You Have Enter The Maximum Number of Attempt.";
  }
  return 0;
}
