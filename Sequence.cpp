#include<iostream>
#include<fstream>
#include<string>
#include<cassert>
#include"Sequence.h"
using namespace std;

Sequence::Sequence(string filename)
{
 ifstream infile;
 infile.open(filename);
 assert(infile.is_open());
 string h;
 getline(infile,array);
 while(!infile.eof())
{
 getline(infile,h);
 array+=h;
}
 infile.close();
}

int Sequence::length()
{
 return array.length();
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
         if(array[i]=='A')
         {
            sumA++;
         }
    }
    return sumA;
}

  else if(base='T')
  {
    for(int i=0;i<100;++i)
    {
         if(array[i]=='T')
         {
            sumT++;
         } 
    }
    return sumT;
}

  else if(base=='C')
  { 
    for(int i=0;i<100;++i)
    {
        if(array[i]=='C')
        {
           sumC++;
        }
    }
    return sumC;
  }

  else if(base=='G')
  {
    for(int i=0;i<100;++i)
    {
        if(array[i]=='G')
        {
          sumG++;
        }
    }
   return sumG;
  }

string Sequence::longestConsecutive()
{
   int max=0;
   int flag1;
   int constring=0;
   for(int i=0;i<array.length();++i)
   {
        while(array[i][j]==array[i][j+1])
       {
           constring++;
           i++;
       }
        if(constring>max)
       {
           max=constring;
           flag1=i;
       }
       constring=0;
   }
   return array.substr((flag1-max+1),max);
}

string Sequence::longestRepeated()
{
   int length=array.length();
   int longest=length-1;
   for(longest;longest>0;--longest)
   {
      string *sub;
      sub=new string[length-longest+1];
      for(int i=0;i<length-longest+1;++i)
      {
         sub[i]=array.substr(i,longest);
      }
      for(int i=0;i<length-longest+1;++i)
      {
         for(int j=i+1;j<length-longest+1;++j)
         {
            if(sub[i]=sub[j])
            {
               return sub[i];
            }
         }
      }
      delete [] sub;
   }
   return NULL;
}





















