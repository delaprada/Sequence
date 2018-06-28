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
private:
 int sumA;
 int sumT;
 int sumC;
 int sumG;
};
