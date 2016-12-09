#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){

	FILE *f = fopen("./vy.dum", "r");
	char *s=(char*)malloc(100*sizeof(char));
	int k=0;
    	while(1){
		fgets(s, 100, f);
		if (strcmp(s,"*E\n")==0){
			k++; 
//			printf("YES");
		}
 //       	while(strcmp(s,"*E")!=0){
//			char *first=(char*)malloc(20*sizeof(char));
//			char *abbr=(char*)malloc(20*sizeof(char));
			char first[32];
			char abbr[32];

			char c = s[0];
			int i = 0;
			int q = 0;
			while(c!=' '){
				first[q]=c;
				q++;
				i++;
				c = s[i];
			}    
			first[i]='\0';
			if (strcmp(first,"ABBREVIATION")==0){ 	
				k++;	
				i+=3;
				c = s[i];
				q=0;
				while(c!=';'){
					abbr[q]=c;
					q++;
					i++;
					c=s[i];		
				}  
				printf("%s\n", abbr);
			}
//			printf("%s\n", s);
			fgets(s,100,f);
//		}
		if (k>4320)
			break;
	}
	fclose(f);
}
