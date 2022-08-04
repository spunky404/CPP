// Spell checker using Trie data structure
//Program to check spelling entered by the user
// Create a file database.txt which contains data of word before executing the code
#include<bits/stdc++.h>
#include<string.h>
#include<fstream>
using namespace std;
//define a structure trie to store correct spellings
struct trie
{
  struct trie *child[26];
  bool isend;
  //set up properties of trie when new trie is created
  //the pointer array must be set to NULL & end of string variable is false by default
  trie()
  {
    memset(child,0,sizeof(child));
    isend=false;
  }
};
//define the root node
struct trie *root;
//function for inserting new strings 6
void insert(string str)
{
 struct trie *current=root;
 for(uint16_t i=0;i<str.length();i++)
 {
  int index=str[i]-'a'; //finding the index of current character of string
                        //i.e. a=0, b=1, c=2... by subtraction
  if(current->child[index]==NULL)
  {
    current->child[index]=new trie; //if null create new edge
  }
  current=current->child[index];
 }
 current->isend=true; //end of string must be true
}
bool search( string str) //function for searching given string
{
 struct trie *current=root;
 for(uint16_t i=0;i<str.length();i++)
 {
  int index=str[i]-'a'; //finding index of current character of string 7
  if(current->child[index]==NULL)
    return false; //if no edge pointing to index then given string is not present
  current=current->child[index];
 }
 return current->isend; //if all edges match the character index check and return end of string
}
int main()
{
 root=new trie;
 bool output;
 string strr;
 fstream base;
 base.open("database.txt",ios::in);
 if (base.is_open())
 {
   string tp;
  while(getline(base, tp)) 8
  insert(tp);
 }
 base.close();
 cout<<" SPELL CHECKER\n";
 int i=1;
 while(i!=0)
 {
  cout<<"enter word\n";
  cin>>strr;
  output=search(strr);
  if(output==true)
    cout<<"correct spelling\n";
  else
    cout<<"incorrect spelling\n";
  cout<<"\n"<<"To continue using spell checker press (1) or press (0) to exit\n";
 cin>>i;
 }
 return 0;
}
