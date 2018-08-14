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



int len(string a){
	int n = 0;
	while(a[++n]);
	return n ;
}

int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    int rC = 0 , bC = 0 , wC = 0 , sumC = 0 ;
	string st , st1= "" ;
    string m[5] ;
    char s[10] ;
    int aaa ;
    fin >> aaa >>st ;
//	cin >>st ;
	bool t = true , t2 = true ;
	for(int i = 0 ; i < len(st) ; i++){
	if ( st[i] != 'w' && t ){
		t = false ;
		s[0] = st[i] ;
	}

	if(st[i] != 'w' && st[i] != s[0] && t2 == true ){
		t2 = false ;
	}
	if(t== false && t2==false && st[i]==s[0] ){
		st1 = st;
		for (int z = 0 ; z < i ; z++)
		st1 += st[z] ;
		break ;
	}

//	if (st[i] != 'w' && st[i] != s[0] && t== false && t2 == true ){
//	st1 = st ;
//	for (int z = 0 ; z < i ; z++)
//	st1 += st[z] ;
//	break ;
//	}
}
	// now st1 is our main , actually we included Cirle ability in it 

	int i = 0 ;
	t = true ; 
	bool t1 = true ;
	t2 = true ;
	// wrwwwwb 
	s[1] = s[0] ;
	
	int data[100] ;
	for (int i = 0 ; i<100 ; i++) data[i] = 0 ;
	if (st1=="" ) {
		t2 = false ;
		sumC = len(st) ;
//		cout<<"fuc";
	}
	
	
	int col[6] ;	
	while( i < len(st1) && t2)
		
		{
		if ( st1[i] == s[0] ){  // s[0] == r  , rC ha
			if( bC + rC + wC > sumC && t1 )
			sumC = bC+rC + wC ;
			
			if ( t1 ){	
			rC = 0 ;
			rC +=wC ;
			wC = 0 ;}
			
			if(t){
			rC+=wC ;
			wC = 0 ;	}
			
			t = true ;  // past and current before is S0
			t1 = false ; // past and current before is not !S0
			rC++ ;
	//		wC = 0 ;	
		}
		
		else if ( st1[i] == 'w')
		wC++ ;

		else {
			if(bC + wC + rC > sumC && t ) // bC ha
			sumC = bC + rC + wC;
			
			if(t){	
			bC = 0 ;
			bC += wC ;
			wC = 0 ;}
			
			if(t1) {
			bC+=wC ;
			wC = 0;	}			

			bC++ ;		
			t = false ;
			t1 = true ;	}
			
		i++;
		}
	fout<<sumC <<endl;

    return 0;
}
