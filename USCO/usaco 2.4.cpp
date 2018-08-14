/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: becomin2
TASK: palsquare
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;

int B ;

int len(string a){
	int c =0 ;
	while(a[c])
	c++ ;
	return c;
}

//abba
//12321
int is(string a){ // if  a== a[::-1] it returns  1 ; else returns 0 ;
	int k = 0 ;
	for(int i = 0 ; i < len(a) ; i++){
	if(a[i] == a[len(a)-1-i])
	k++ ;
	}
	if(k== len(a))return 1 ;
	return 0 ;
}



string base(int a){ // takes a from base 10 , convert is to base B ;
	string R = "";
	if(B == 10)
	return to_string(a) ;
	
	else if (B <10){
	int c = 0;
	while (a){
		R =  to_string(a%B ) + R ;
		a/= B ;
	}
	return R ;
	}
	int temp = 0 ;
	while(a){
	
		if(a%B >= 10){
			temp = a%B ;
			if( temp == 10)  R = 'A' +  R ;
			if( temp == 11)  R = 'B' +  R ;
 			if( temp == 12)  R = 'C' +  R ;
			if( temp == 13)  R = 'D' +  R ;
			if( temp == 14)  R = 'E' +  R ;
			if( temp == 15)  R = 'F' +  R ;
			if( temp == 16)  R = 'G' +  R ;
			if( temp == 17)  R = 'H' +  R ;
			if( temp == 18)  R = 'I' +  R ;
			if( temp == 19)  R = 'J' +  R ;
			if( temp == 20)  R = 'K' +  R ;
		}
		else R = to_string(a%B) +  R ;//needs review dude
		a/= B ;}
	return R;
}

int main() {
    ifstream fin ("palsquare.in");
	ofstream fout ("palsquare.out");
	fin>>B;
	for(int i = 1 ; i <=300 ; i++)
	if( is( base(i*i)))
	fout<<base(i)<<" "<<base(i*i)<<endl;	
	
    return 0;
}

