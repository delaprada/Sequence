#include<iostream>
#include<fstream>
#include<string>
#include<cassert>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"Sequence.h"
using namespace std;

#define MAXCHAR 2000000
char c[MAXCHAR], *a[MAXCHAR];


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
    for(int i=0;i<array.length();++i)
    {
         if(array[i]=='A')
         {
            sumA++;
         }
    }
    return sumA;
}

  else if(base=='T')
  {
    for(int i=0;i<array.length();++i)
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
    for(int i=0;i<array.length();++i)
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
    for(int i=0;i<array.length();++i)
    {
        if(array[i]=='G')
        {
          sumG++;
        }
    }
   return sumG;
  }
}
string Sequence::longestConsecutive()
{
   int max=0;
   int flag1;
   int constring=0;
   for(int i=0;i<array.length();++i)
   {
        while(array[i]==array[i+1])
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
   return array.substr((flag1-max),(max+1));
}

void Sequence::readTxt(string filename)
{
  int n=0;
  ifstream infile;
  infile.open(filename.data());
  assert(infile.is_open());
  while(!infile.eof())
 {
   infile>>c[n];
   a[n]=&c[n];
   n++;
 }
}

int Sequence::comlen(char *p,char *q)
{
  int i=0;
  while(*p &&(*p++==*q++))
  {
    ++i;
  }
  return i;
}

int pstrcmp(const void *p1,const void *p2)
{
  return strcmp(*(char* const*)p1,*(char* const*)p2);
}


string Sequence::longestRepeated()
{
   readTxt("dna.txt");
   int i,temp;
   int maxlen=0,maxi=0;
   qsort(a,array.length(),sizeof(char*),pstrcmp);
   for(i=0;i<array.length()-1;++i)
  {
    temp=comlen(a[i],a[i+1]);
    if(temp>maxlen)
    {
      maxlen=temp;
      maxi=i;
    }
  }
   string c;
   c.assign(a[maxi],maxlen);
   return c;
  
}





















