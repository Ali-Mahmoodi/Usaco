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



int main() {
    ifstream fin ("beads.in");
	ofstream fout ("beads.out");
    
    int a, b;
    fin >> a >> b;
    fout << a+b <<endl;
    return 0;
}




