#include<iostream>
#include<string>
using namespace std;

string encrypt(string msg,int arr[],int row, int col)
{
  string cipher;
  char temp[row][col];
  int x=0;
  for(int i=0;i<row;i++)
  {
    for(int j=0;j<col;j++)
    {
      if(x>=msg.length())
      temp[i][j]='_';
      else temp[i][j] = msg[x];
      x++;
    }
  }
  x=1;
  while(x<=col)
  {
    for(int i=0;i<col;i++)
    {
      if(arr[i]==x)
      {
        x++;
        for(int j=0;j<row;j++)
        {
          cipher += temp[j][i];
        }
      } 
    }
  }
  return cipher;
}

string decrypt(string cipher,int arr[],int row,int col)
{
  string str;
  char temp[row][col];
  int x=1,count=0;
  while(x<=col)
  {
    for(int i=0;i<col;i++)
    {
      if(arr[i]==x)
      {
        x++;
        for(int j=0;j<row;j++)
        {
          temp[j][i] = cipher[count];
          count++;
        }
      }
    }
  }
  for(int i=0;i<row;i++)
  {
    for(int j=0;j<col;j++)
    {
      if(temp[i][j]!='_')
      str += temp[i][j];
    }
  }
  return str;
}

int main()
{
  string msg,key;
  cout<<endl<<"Message: ";
  cin>>msg;
  cout<<endl<<"Key: ";
  cin>>key;
  int len_key,len_msg,row;
  len_key=key.length();
  len_msg=msg.length();
  row = len_msg/len_key +1;
  int count=1,ind=-1;
  int arr[len_key]={0};
  while(count<=len_key)
  {
    int min =999;
    for(int i=0;i<len_key;i++)
    {
      if(min>key[i] && arr[i]==0)
      {
        min=key[i];
        ind = i;
      }
    }
    arr[ind]=count;
    count++;
  }
  string cipher = encrypt(msg,arr,row,len_key);
  cout<<endl<<"Cipher Text: "<<cipher;
  cout<<endl<<"Plain Text: "<<decrypt(cipher,arr,row,len_key);
  return 0;
}
