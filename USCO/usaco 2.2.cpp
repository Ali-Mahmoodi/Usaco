/* Use the slash-star style comments or the system won't see your
   identification information */
/*
ID: becomin2
TASK: transform
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int t[10][10] ,f[10][10] ,fake[10][10] ,bt[10][10] ,bt2[10][10] , bt3[10][10] ;// t = table 
int bt4[10][10] , bt5_1[10][10] , bt5_2[10][10] , bt5_3[10][10] ,bt6[10][10] ;
int m1(int n){ //move number one ;  // Rotate 90 degrees clockwise .
	int C = 0;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			bt[j][n-i-1] = t[i][j] ;
			if (bt[j][n-i-1] == f[j][n-i-1])
			C++ ;}}
	if ( C== n*n) return 1; return 0; }
int m2(int n){
	int C = 0 ;
	for (int i = 0 ; i <n ; i++ ){
		for(int j = 0 ; j <n ; j++){
			bt2[j][n-i-1] = bt[i][j] ;
			if(f[j][n-i-1] == bt2[j][n-i-1] )
			C++ ;}}
	if ( C == n*n)return 2; return 0;}
int m3(int n){
	int C = 0;	
		for (int i = 0 ; i <n ; i++ ){
		for(int j = 0 ; j <n ; j++){
			bt3[j][n-i-1] = bt2[i][j] ;
			if(f[j][n-i-1] == bt3[j][n-i-1] )
			C++ ;}}
	if ( C == n*n) return 3; return 0;}
int m4(int n){ // mirrro function
	int C = 0 ;
	for(int i=0 ; i < n ; i++){
		for(int j=0 ; j < n ; j++){
			bt4[i][n-1-j] = t[i][j] ;
			if ( bt4[i][n-1-j] == f[i][n-1-j])
			C++ ;}}
	if(C== n*n)return 4; return 0; }
int m5_1(int n){
	int C = 0;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			bt5_1[j][n-i-1] = bt4[i][j] ; // bt4 lefts , i mean , #4 happens then #1 happens .combained . 
			if (bt5_1[j][n-i-1] == f[j][n-i-1])
			C++ ;}}
	if ( C== n*n) return 5; return 0; }
int m5_2(int n){
	int C = 0;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			bt5_2[j][n-i-1] = bt5_1[i][j] ;
			if (bt5_2[j][n-i-1] == f[j][n-i-1])
			C++ ;}}
	if ( C== n*n) return 5; return 0;}
int m6(int n){
	int C = 0 ;
	for (int i = 0 ; i < n ; i++)
	for (int j = 0 ; j < n ; j++)
	if ( t[i][j] == f[i][j]) C++ ;
	if (C== n*n) return 6; return 0;}
int m5_3(int n){
	int C = 0;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			bt5_3[j][n-i-1] = bt5_2[i][j] ;
			if (bt5_3[j][n-i-1] == f[j][n-i-1])
			C++ ;}}
	if ( C== n*n) return 5; return 0; }
int main() {
    ifstream fin ("transform.in");
	ofstream fout ("transform.out");    
    int n;
    char tempi ;
    fin >> n;
    //int t[n][n] , f[n][n] ,fake[n][n] ,bt[n][n] ;  // table   i like ... no no ! i dont like start from 1 ! 
    // bt = Bigtempi ; f = final desition ,final desteny of u dear table of mine ~_~ ;
    for(int i =0 ; i < n ; i++){
    	for(int j=0 ; j < n ; j++){
    		fin>>tempi ;
    		if(tempi == '@')
    		t[i][j] = 1 ;
    		else if(tempi == '-')
    		t[i][j] = 0 ;
    		else cout<<"FUCK IM ERROR FUCK SYNTAX @- OR STH"<<endl;}
	}
    for(int i =0 ; i < n ; i++){
    	for(int j=0 ; j < n ; j++){
    		fin>>tempi ;
    		if(tempi == '@')
    		f[i][j] = 1 ;
    		else if(tempi == '-')
    		f[i][j] = 0 ;
    		else cout<<"FUCK IM ERROR FUCK SYNTAX @- OR STH"<<endl;}
	}
	// #1 , #2 , #3  , #4 , #5 , #6 , #7
	// fuck ! there is no calculation and naverdaee ,
	// just with one Move u Can , or Cant ! there is no multi-combinaed move !

	if (m1(n))
	fout<<m1(n)<<endl ;
	else if (m2(n))
	fout<<m2(n)<<endl ;
	else if (m3(n))
	fout<<m3(n)<<endl ;
	else if (m4(n))
	fout<<m4(n)<<endl ;
	else if (m5_1(n))
	fout<<m5_1(n)<<endl;
	else if (m5_2(n))
	fout<<m5_2(n)<<endl;
	else if (m5_3(n))
	fout<<m5_3(n)<<endl;
	else if (m6(n))
	fout<<m6(n)<<endl;
	else
	fout<<7<<endl ;
    return 0;
}


