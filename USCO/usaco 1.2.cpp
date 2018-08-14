/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: becomin2
TASK: ride 
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int f(char a) {

	return ( int(a)-64 ) ;
}

int len(string a) {
	int k = 0 ;
	while(a[k])
	k++ ;
	return k ;
}


int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a, b;
    int x = 1 , y = 1 ;
	fin >> a >> b;  
	for (int i = 0 ; i < len(a) ; i++){
		x*=f(a[i]) ;
	}

	for (int j = 0 ; j < len(b) ; j++)
		y*=f(b[j]) ;
	
	if( (x%47) == (y%47))  
	fout<<"GO"<<endl;
	else
	fout<<"STAY"<<endl;
	
    return 0;
}
