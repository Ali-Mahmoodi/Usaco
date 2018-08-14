/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: becomin2
TASK: milk2
LANG: C++                 
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;



int main() {
    ifstream fin ("milk2.in");
	ofstream fout ("milk2.out");
	long long N , n = 0 ;
	long long minS =999999, maxS=0 , maxL = 0 , maxL2 =0;
	fin >> N ;	
	long long time[N][N] ; 
	cout<<-1;
	n = N ;
	for (int i = 0 ; i< N ; i++ ){
		fin>>time[i][0]>>time[i][1] ;
		if ( minS  >  time[i][0] )  minS = time[i][0]   ;
		if ( time[i][1] > maxS )  maxS = time[i][1] ;
		if ( i && ( time[i-1][0] <= time[i][0] && time[i-1][1] >= time[i][1] ) ){
			i-- ;     // this time[i][i]  is not usefull ,remove it !!
			N-- ; }   //  (take sth in its place and replace it ! )
		if ( i && ( time[i-1][0] <= time[i][0] && time[i-1][1] <= time[i][1] && time[i-1][1] >= time[i][0] ) ){
			time[i-1][1] = time[i][1] ;
			i--;
			N--;	}
		if ( i && ( time[i-1][0] >= time[i][0] && time[i-1][1] >= time[i][1] && time[i-1][0] <= time[i][1] ) ){
		time[i-1][0] = time[i][0]  ; 
		i--;
		N--;}
		if ( i && ( time[i-1][0] >= time[i][0] && time[i-1][1] <= time[i][1]  ) ){
		time[i-1][0] = time[i][0] ;
		time[i-1][1] = time[i][1] ;
		i--;
		N--;
		}
		
	}
	cout<<0;
	/*
	for (int i = N ; i > 0 ; i-- ){
		
		if ( i && ( time[i-1][0] <= time[i][0] && time[i-1][1] >= time[i][1] ) ){
//			i-- ;     // this time[i][i]  is not usefull ,remove it !!
			N-- ; }   //  (take sth in its place and replace it ! )
		else if ( i && ( time[i-1][0] <= time[i][0] && time[i-1][1] <= time[i][1] && time[i-1][1] >= time[i][0] ) ){
			time[i-1][1] = time[i][1] ;
//			i--;
			N--;	}
		else if ( i && ( time[i-1][0] >= time[i][0] && time[i-1][1] >= time[i][1] && time[i-1][0] <= time[i][1] ) ){
		time[i-1][0] = time[i][0]  ; 
//		i--;
		N--;} 
		else if ( i && ( time[i-1][0] >= time[i][0] && time[i-1][1] <= time[i][1]  ) ){
//		cout<<i<<" "<<time[i][0]<<" "<<time[i][1]<<endl;
		swap(time[i-1][0] , time[i][0] );
		swap(time[i-1][1] , time[i][1] );
		N--; }
//		cout<<"=="<<time[i][0] << " "<<time[i][1] <<endl;}
		}
	*/
//	N++ ;

 	for (int i = 0 ; i < N ; i++) {
 	if(time[i][1] - time[i][0] >maxL )
 	maxL = time[i][1] - time[i][0] ;
//   	fout<<time[i][0] <<" "<<time[i][1] <<endl;
   	if(i && time[i][0] - time[i-1][1] > maxL2 )
   	maxL2 = time[i][0] - time[i-1][1] ;
}
//	fout<<endl;
//	if(n != 1)
	fout<<maxL<<" "<<maxL2<<endl;
	fout<<"----";
	cout<<"f";
//    if ( n== 1)  // cz of site judge bug 
//    fout<<100<<" "<<0<<endl; // cause of site judge system bug 
	return 0;
}



