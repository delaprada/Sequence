#include<iostream>
#include<fstream>
#include<string>
#include<cassert>
#include"Sequence.h"
using namespace std;

Sequence::Sequence(string filename)
{
 ifstream infile;
 infile.open("dna.txt");
 char *ptr=&array[0][0];
 while(!infile.eof())
{
 infile>>*ptr;
 ptr++;
}
 infile.close();
}

int Sequence::length()
{
 length=0;
 for(int i=0;i<100;++i)
 {
   for(int j=0;j<100;++j)
   {
     if(array[i][j]=='A'||array[i][j]=='T'||array[i][j]=='C'||array[i][j]=='G')
      {
        length++;
      }
   }
 }
}

int Sequence::numberOf(char base)
{
  sumA=0;
  sumT=0;
  sumC=0;
  sumG=0;
  if(base=='A')
  {
    for(int i=0;i<100;++i)
    {
       for(int j=0;j<100;++j)
       {
         if(array[i][j]=='A')
         {
            sumA++;
         }
       }
    }
    return sumA;
}

  else if(base='T')
  {
    for(int i=0;i<100;++i)
    {
       for(int j=0;j<100;++j)
       {
         if(array[i][j]=='T')
         {
            sumT++;
         } 
       }
    }
    return sumT;
}

  else if(base=='C')
  { 
    for(int i=0;i<100;++i)
    {
      for(int j=0;j<100;++j)
      {
        if(array[i][j]=='C')
        {
           sumC++;
        }
      } 
    }
    return sumC;
  }
  else if(base=='G')
  {
    for(int i=0;i<100;++i)
    {
      for(int j=0;j<100;++j)
      {
        if(array[i][j]=='G')
        {
          sumG++;
        }
      }
    }
   return sumG;
  }

string Sequence::longestConsecutive()
{
   int max=0;
   int flag1;
   int flag2;
   int constring=0;
   for(int i=0;i<100;++i)
   {
       for(int j=0;j<100;++j)
       {
          while(array[i][j]==array[i][j+1])
          {
             constring++;
             j++;
          }
          if(constring>max)
          {
             max=constring;
             flag1=i;
             flag2=j;
          }
       }
   }
   for(int k=0;k<constring;++k)
   {
       cout<<array[flag1][flag2];
   }
}

  



