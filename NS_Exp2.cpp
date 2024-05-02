#include<iostream>
#include<string>
using namespace std;

string encrypt(int row, int col, string msg, int arr[])
{
  int x=0,count=1;
  char cipher[row][col];
  for(int i=0;i<row;i++)
  {
    for(int j=0;j<col;j++)
    {
      if(x>=msg.length())
      cipher[i][j] = '_';
      else cipher[i][j] = msg[x];
      x++;
    }
  }
  string ans;
  while(count<=col)
  {
    for(int i=0;i<col;i++)
    {
      if(count==arr[i])
      {
        for(int j=0;j<row;j++)
        ans += cipher[j][i];
        break;
      }
    }
    count++;
  }
  return ans;
}

string decrypt(int row, int col, string cipher, int arr[])
{
  int x=0,count=1;
  char matrix[row][col];
  while(count<=col)
  {
    for(int i=0;i<col;i++)
    {
      if(count==arr[i])
      {
        for(int j=0;j<row;j++)
        {
          matrix[j][i] = cipher[x];
          x++;
        }
        break;
      }
    }
    count++;
  }
  string ans;
  for(int i=0;i<row;i++)
  {
    for(int j=0;j<col;j++)
    {
      if(matrix[i][j]!='_')
      ans += matrix[i][j];
    }
  }
  return ans;
}

int main()
{
  string msg,Key;
  cout<<endl<<"Enter Message: ";
  cin>>msg;
  cout<<endl<<"Enter Key: ";
  cin>>Key;
  int len_key=Key.length(),len_msg=msg.length();
  int ind=-1,row = len_msg/len_key+1 , count=1;
  int arr[len_key]={0};
  while(count<=len_key)
  {
    int min=999;
    for(int i=0;i<len_key;i++)
    {
      if(min>Key[i] && arr[i]==0)
      {
        min = Key[i];
        ind = i;
      }
    }
    arr[ind] = count;
    count++;
  }
  string cipher = encrypt(row,len_key,msg,arr);
  cout<<endl<<"Cipher Text: "<<cipher;
  cout<<endl<<"Plain Text: "<<decrypt(row,len_key,cipher,arr);
  return 0;
}
