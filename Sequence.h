#include<iostream>
#include<string>
using namespace std;

class Sequence
{
public:
 Sequence(string filename);
 int length();
 int numberOf(char base);
 string longestConsecutive();
 string longestRepeated();
 string array;
 void readTxt(string filename);
 int comlen(char *p,char *q);
private:
 int sumA;
 int sumT;
 int sumC;
 int sumG;
};


int pstrcmp(const void *p1,const void *p2);


