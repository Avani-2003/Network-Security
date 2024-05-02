#include<iostream>
#include<string>
using namespace std;

string encrypt(string msg,int key)
{
  string cipher;
  for(int i=0;i<msg.length();i++)
  { 
    char ch = isupper(msg[i]) ? 'A' : 'a';
    cipher += (msg[i] + key - ch) % 26 + ch;
  }
  return cipher;
}

string decrypt(string cipher,int key)
{
  return encrypt(cipher , 26 - key);
}

int main()
{
  string msg;
  cout<<endl<<"Enter The Message: ";
  cin>>msg;
  int key;
  cout<<endl<<"Enter Key (3 for Ceaser Cipher): ";
  cin>>key;
  string cipher = encrypt(msg,key);
  cout<<endl<<"Cipher Text: "<<cipher;
  cout<<endl<<"Plain Text: "<<decrypt(cipher,key);
  return 0;
}
