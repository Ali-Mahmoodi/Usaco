/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: becomin2
TASK: gift1
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>   

using namespace std;

int joini[10][10] ; // every single one is joined to sb or not 
int acc[10] ; // current money of every account
int money[10] ; // amount of money ppl wanna gift
string temp ,t[10] ; // temperary for taking ...
string name[10] ;
int rep ;
int num ,nump ;

ifstream fin ("gift1.in");
ofstream fout ("gift1.out");

int taker(string k){
	for (int i = 0 ; i< num ; i++)
	if( name[i] == k)
	return i ;
		
}
/*
int lop(int times){
	for (int i = 0 ; i < times ; i++){
		fin>>t[i] ;
	}
	
	
}
*/
int count(int k){
	int c = 0 ;
	for (int i = 0 ; i < num ; i++)
	if (joini[k][i] )
	c++ ;
	return c ;
}


int main() {
	int dd = 0 ;
	ifstream fin ("gift1.in");
    ofstream fout ("gift1.out");
	for (int i = 0 ; i < 10 ; i++){
	for (int j = 0 ; j < 10 ; j++ )joini[i][j] = 0 ;
    acc[i]   = 0 ; }

 	fin >> num ;  
	nump = num ; 
	
   	for (int i =0 ; i < num ; i++){
	   fin>> name[i] ; }
	   
	   
	int rep2 = 0 ;
	nump = num ;
	while(nump){
		fin>>temp ;
		nump-- ;
		fin>>money[taker(temp)] >> rep ;
		rep2 = rep ;
		while(rep2){
			rep2-- ;
			fin>>t[rep2] ;
			joini[taker(temp)][taker(t[rep2])] = 1 ;
		}
		
		
	}
/*	{
		fin >> temp ;
		nump-- ;
		fin>> money[taker(temp)] >> rep ;
		if (rep ){
			fout<<temp<<rep<<"\n" ;
		//	lop(rep) ;	
			for (int i = 0 ; i <rep ; i++){
				joini[taker(temp)][taker(t[i])] = 1 ;
				}}
//				fout<<"~~~"<<t[i] <<" "<<taker(t[i]) <<" "<< taker(temp) <<"\n";
			
	}
*/	/*
		for(int x = 0 ; x < num ; x++){
		fout<<" ==== "<<name[x] << " " <<money[x] << " " <<count(x) <<"\n" ;
} */
/*
	for(int i = 0 ; i<num ; i++) {
		fout<<joini[0][i]<<" ";
	}
*/	
	for (int i = 0 ; i <num ; i++ ){
		if(count(i)){
	
		acc[i]=acc[i] - ( money[i]/count(i) ) *count(i) ;
	//	fout<<acc[i] - ( money[i]/count(i) ) *count(i) <<"\n" ;
	}	
	}
	for (int i = 0 ; i <num ; i++ ){
		for(int j = 0 ; j < num ; j++){
			if(joini[i][j] && count(i)) 
			acc[j] += money[i]/count(i) ; 
			

		}
	}
	for(int i = 0 ; i < num ; i++)
	fout<<name[i] << " "<<acc[i]<<"\n";   
 //   fout << a+b <<endl;
    return 0;
/*  
int joini[10][10] ; // every single one is joined to sb or not 
int acc[10] ; // current money of every account
int money[10] ; // amount of money ppl wanna gift
string temp ,t[10] ; // temperary for taking ...
string name[10] ;
int rep ;
int num ,nump ;
  
  */  
  
  
  
  
  
}
