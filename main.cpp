#include<iostream>
#include"Sequence.h"
using namespace std;

int main()
{
  Sequence a("dna.txt");
  cout<<"序列的长度为："<<a.length()<<endl;
  cout<<"A碱基的数目为："<<a.numberOf('A')<<endl;
  cout<<"T碱基的数目为："<<a.numberOf('T')<<endl;
  cout<<"C碱基的数目为："<<a.numberOf('C')<<endl;
  cout<<"G碱基的数目为："<<a.numberOf('G')<<endl;
  cout<<"最长连续的碱基序列为："<<a.longestConsecutive()<<endl;
  cout<<a.longestRepeated();
  return 0;
}
