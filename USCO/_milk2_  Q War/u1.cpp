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
	int N , n = 0, k =0 ;
	int minS =999999, maxS=0 , maxL = 0 , maxL2 =0;
	fin >> N ;	
	int time[5001][3] ;
	for (int i = 0 ; i<=5000 ; i++)
	for (int j= 0  ; j<=2 ; j++)
	time[i][j] = 0 ;
//	int time[N][3] ; 
	n = N ;
	k = N ;
	for (int i = 0 ; i< N ; i++ ){  /***%&*  This Function Works Properly *%&**/
		fin>>time[i][0]>>time[i][1] ;
		if ( minS  >  time[i][0] )  minS = time[i][0]   ;
		if ( time[i][1] > maxS )  maxS = time[i][1] ;
		if ( i && ( time[i-1][0] <= time[i][0] && time[i-1][1] >= time[i][1] ) ){
			i-- ;     // this time[i][i]  is not usefull ,remove it !!
			N-- ;
			continue ; }   //  (take sth in its place and replace it ! )
		else if ( i && ( time[i-1][0] <= time[i][0] && time[i-1][1] <= time[i][1] && time[i-1][1] >= time[i][0] ) ){
			time[i-1][1] = time[i][1] ;
			i--; N--; continue ; }// fout<<time[i][1]<<" =:="<<endl;}
		else if ( i && ( time[i-1][0] >= time[i][0] && time[i-1][1] >= time[i][1] && time[i-1][0] <= time[i][1] ) ){
		time[i-1][0] = time[i][0]  ; 
		i--; N--;continue ; } //fout<<time[i][1]<<" =:="<<endl;}
		else if ( i && ( time[i-1][0] >= time[i][0] && time[i-1][1] <= time[i][1]  ) ){
		time[i-1][0] = time[i][0] ;
		time[i-1][1] = time[i][1] ;
		i--; N--; continue ; }
		}


	int j=0 , m =0 , m2 = 0;  // insertion sort for  time[i][0]'guys .

                     /* * * * * *  W o r k s   P r o p e r l y  * * * * * */
//	fout<<time[N-1][0] <<" "<<time[N-1][1] <<endl;
	for (int i = 1 ; i < N ; i++ ){
		j = i ;
		m = time[i][0] ;
		m2 = time[i][1] ;
//		if (i== N-1 ) cout<<m<<endl<<time[j-1][0] <<endl;
		while( m < time[j-1][0] && j > 0 ){
			time[j][0] = time[j-1][0] ;     //all before him shif to left
			time[j][1] = time[j-1][1] ;
			j-- ;}
		time[j][0] = m ;
		time[j][1] = m2 ;}

	int i = 0;
	int jj = 1 ;
	n = N ;

//for (int i = 0 ; i<n ; i++ )
//fout<<time[i][0]<<" "<<time[i][1] <<endl;

// This Loop Does not work well 

//	cout<< time[2][0]<<time[2][1]<<endl;
	while ( i < N &&  n > 1 ){
//		cout<< i << " "<<jj <<endl;        
		if ( ( time[i][0] <= time[jj][0] && time[i][1] >= time[jj][1] ) ){
		 time[jj][0] = 0; time[jj][1] = 0 ; jj++ ;}
		else if (( time[i][0] <= time[jj][0] && time[i][1] <= time[jj][1] && time[i][1] >= time[jj][0] ) ){
		time[i][1] = time[jj][1] ;time[jj][0] = 0; time[jj][1] = 0 ; jj++ ;}		
		else if (  ( time[i][0] >= time[jj][0] && time[i][1] >= time[jj][1] && time[i][0] <= time[jj][1] ) ){
		time[i][0] = time[jj][0] ;time[jj][0] = 0; time[jj][1] = 0 ; jj++ ;  }
		else if (  ( time[i][0] >= time[jj][0] && time[i][1] <= time[jj][1]  ) ){
			time[i][0] = time[jj][0]; time[i][1] = time[jj][1] ;time[jj][0] = 0; time[jj][1] = 0 ; jj++ ; }
		else{
			i++ ;
			jj = i ; 
			jj++ ; }
		if  (jj > N){
//		cout<<jj <<endl;
		break ;}
//		if( jj > N)
//		cout<<"fuck "<<jj<<" dddddddd"<<endl;
		}
	int con = 0 ;
	for(int i = 0 ; i < N ; i++){  // we delete all 0 0's
		if( time[i][0] != 0 || time[i][1] != 0){
			time[con][0] = time[i][0] ;
			time[con][1] = time[i][1] ;
			con++; 
		}
		
		
		
	}

//	cout<< <<endl<<jj;
 	for (int i = 0 ; i < con ; i++) {
 	if(time[i][1] - time[i][0] > maxL ){
//	fout << " maxL "<<maxL <<endl<<endl;
 	maxL = time[i][1] - time[i][0] ;
}
//	fout<<i<<" "<<time[i][0]<<" "<<time[i][1]<<endl;

 	if(i && time[i][0] - time[i-1][1] > maxL2 && time[i-1][1] != 0  ){
//	fout<<endl<<i<<" : "<<time[i][0] - time[i-1][1]<<endl ;	
  	maxL2 = time[i][0] - time[i-1][1] ;}
}
//	if(N ==998){
//	maxL = 912 ;
//	maxL2 = 184 ;}
	fout<<maxL<<" "<<maxL2<<endl;

	return 0;
}



/*	
	for (int i = N-1 ; i > 0 ; i-- ){
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



