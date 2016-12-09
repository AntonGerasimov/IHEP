#include <stdio.h>
#include <stdlib.h>
int main(){
	int i;	
	char *str=(char*)malloc(72*sizeof(char));
	FILE *f=fopen("./vy.dum", "r");
	fgets(str,72,f);
	while(fgets(str,72,f)!=NULL){
//		fgets(str,32,f);
//		fscanf(f, "%s\n", str);
		char first[32];
		char c=str[0];
		int q=0;
		int o=0;
		while(c!=' '){
			first[q]=c;
			q++;
			o++;
			c = str[o];
		}
		first[o]='\0';
		printf("%s\n", first);
//		fgets(str,72,f);
	}
	fclose(f);
}
