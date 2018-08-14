/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: becomin2
TASK: beads
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string m(int a){
	if(a==2)return "ABC";
	if(a==3)return "DEF";
	if(a==4)return "GHI";
	if(a==5)return "JKL";
	if(a==6)return "MNO";
	if(a==7)return "PRS";
	if(a==8)return "TUV";
	if(a==9)return "WXY";  }

int main() {
	int a ;
	cin>>a;
	string m;
	m+=to_string(123) ;
	m += to_string(a);
	m += "hiiiiiia";
	cout<<m<<endl;

	return 0;
	  
}
