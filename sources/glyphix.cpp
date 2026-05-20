#include<iostream>
#include "LetterFuncs.h"  // for functions A,B,C,....
#include "glyphix.h"
using namespace std;

static string generate(char ch, int size, int row, char style){
	
	// Function selector
	string (*letter[26])(int, int, char) = { A, B, C, D, E, F, G, H,I,  
											 J, K, L, M, N, O, P, Q, R, 
											 S, T, U, V, W, X, Y, Z };
											 
	ch = toupper(ch);
	if(style == '~') style = ch;
	
	int index = ch - 'A';
	if(ch >= 'A' && ch <= 'Z') return letter[index](size,row,style);
	else if(ch == ' ') return "   ";
	else return "ERROR";
} 

string glyphix(string str,int size,char style){
	int offset = 0 , n = 0;
	string out = "";
	while(offset < str.length()){
		for(int row = 1; row <= size; row++){
			for(n = offset; n < str.length() && str[n] != '\n'; n++)
				out += generate(str[n],size,row, style) + "  ";
			out.append("\n");
		}
		out.append("\n");
		offset = n+1;
	}
	return out;
}