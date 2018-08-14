/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: becomin2
TASK: friday
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>   
using namespace std;
ifstream fin ("friday.in");
ofstream fout ("friday.out");
// %%%%%%% this programme takes N then tells u from 1900 till 1900+n-1 year , how many Friday was in 13th day of year .
/*
1900 / 1 / 1 == January  Monday
1 January - 31 days
2 February - 28 days in a common year and 29 days in leap years , if (n%400  || ( n%4 && n%100 != 0) )
3 March - 31 days
4 April - 30 days
5 May - 31 days
6 June - 30 days
7 July - 31 days
8 August - 31 days
9 September - 30 days
10 October - 31 days
11 November - 30 days
12 December - 31 days
*/

int acircle = 1; // Monday-1 
int a[7] ;  // a[0]till a[6] = {Saturday , Sunday , Monday , Tuesday , Wednesday , Thursdays , Friday ]


int day(int y , int m){ // day maker
	if( (m == 1) || (m== 3) || (m==5 ) || (m==7 ) || (m== 8) || (m==10 ) || (m ==12 )  )
	return 31 ;
	
	if( (m == 4) || (m== 6) || (m== 9 ) || (m==11 ) )
	return 30 ;	
	
	if( m== 2 ){
		if( ( (y%4== 0 )&& (y%100 != 0) ) || (y%400 == 0) )
		return 29 ;
		else
		return 28 ;
	}
	
	cout<<"IM BUG"<<endl;
	
}

int circle(){
	acircle++ ;
	acircle%= 7 ;
	return acircle;
}

int main() {
//	int k ;
//	k = 36+ 33+ 34 +33+ 35+ 35+ 34 ;
//	cout<<k<<endl<<k/20. <<endl;
    int n , k=0;
    fin >> n;
    n = n+1900-1 ;
	//Saturday, Sunday, Monday, Tuesday, ..., Friday.
//	int a[7] ;  // a[0]till a[6] = {Saturday , Sunday , Monday , Tuesday , Wednesday , Thursdays , Friday ]
	for(int y = 1900 ; y <= n ; y++){ //n = inp  ,fin
		for(int m=1 ; m <= 12 ; m++){
			for(int d=1 ; d <= (day(y,m)) ; d++ ){ //number of days of a month
			k = circle() ; 
			if( d == 13 )
			a[k]++ ;
			}
		} 
	}

	for(int i =0 ; i < 6 ; i++)
	fout<<a[i]<<" ";
	fout<<a[6]<<"\n";
	return 0;}
  
  
  
  

