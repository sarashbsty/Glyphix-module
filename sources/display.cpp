#include<iostream>
#include "generate.h"
#include "glyphix.h"
using namespace std;

void gly_display(string str,int size,char style,char choice){
	
    cout<<endl;
	int n,m = 0;
	switch(choice){
		case '1':	while(m < str.length()){
						for(int row = 1; row <= size; row++){
							for(n = m; str[n] != '\n'; n++)
								cout<<generate(str[n],size,row,'~')<<"  ";
							cout<<endl;
						}
						cout<<endl;
						m = n+1;
					}
					break;
					
		case '2':	while(m < str.length()){
						for(int row = 1; row <= size; row++){
							for(n = m; str[n] != '\n'; n++)
								cout<<generate(str[n],size,row,style)<<"  ";
							cout<<endl;
						}
						cout<<endl;
						m = n+1;
					}
					break;
					
		case '3':	while(m != str.length()){
						for(int row = 1; row <= size; row++){
							for(n = m; str[n] != '\n'; n++)
								cout<<generate(str[n],size,row,35+n)<<"  ";
							cout<<endl;
						}
						cout<<endl;
						m = n+1;
					}
					break;
	} 
}