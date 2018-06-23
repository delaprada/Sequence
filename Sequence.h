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
private:
 int length;
 char array[100][100];
 int sumA;
 int sumT;
 int sumC;
 int sumG;
}
