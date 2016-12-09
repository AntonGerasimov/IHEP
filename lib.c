#include "./lib.h"
struct Particle{
	char *abbr;
	double mass;
	int id;
	int orrcode;
	int orcode[6];
	int parent; //ident for parent
};
void make_orcode(int orrcode, int orcode[6]){
	orcode[5]=orrcode%10;
	orrcode = orrcode/10;
	orcode[4]=orrcode%10;
	orrcode = orrcode/10;	
	orcode[3]=orrcode%10;
	orrcode = orrcode/10;
	orcode[2]=orrcode%10000;
	orrcode = orrcode/10000;
	orcode[1]=orrcode%10;
	orrcode =  orrcode/10;
	orcode[0]=orrcode;
}
void sort_abbr(struct Particle Particles[]){
        int i,j;
        struct Particle p;
        for (i=0; i<4400; i++){
                        for (j=1; j<i; j++){
                                if (strcmp(Particles[i].abbr, Particles[j].abbr)>0){
                                        p = Particles[i];
                                        Particles[i] = Particles[j];
                                        Particles[j] = p;
                                }
                        }
                }

}
void sort_orcode(struct Particle Particles[]){
        int i,j;
        struct Particle p;
        for (i=0; i<4400; i++){
                        for (j=1; j<i; j++){
                                if ((Particles[i].orrcode<Particles[j].orrcode)&&(strcmp(Particles[i].abbr, "")!=0)&&(strcmp(Particles[j].abbr, "")!=0)){
                                        p = Particles[i];
                                        Particles[i] = Particles[j];
                                        Particles[j] = p;
                                }
                        }
                }

}
double max_(double a, double b){
	if (a>b)
		return a;
	else
		return b;
}
int delta_m(struct Particle A, struct Particle B){
	int ret = -1;
	double delta = abs(A.orcode[2]-B.orcode[2]);
	double delta_ = abs(A.mass-B.mass);
//	printf("%lf\n",delta);
	if (((A.orcode[0]==10)&&(delta<(A.orcode[2]-1000)/2))||((A.orcode[0]>10)&&(A.orcode[0]<=14)&&(delta<(9000 - A.orcode [2])/2))
	)
//or((A.orcode[0]<10)and(delta==0))or((A.orcode[0]>14)and(delta==0)))
		ret=1;
	if ((A.orcode[0]<10)||(A.orcode[0]>14)){
		if(delta_<max_(A.mass,B.mass)/2){
			ret=1;
		}
	}
	return ret;
}
int cmp_orcode(struct Particle A, struct Particle B){
	int ret = -1;
	if (A.orcode[0]==B.orcode[0]){
		if (A.orcode[1]==B.orcode[1]){
			if (A.orcode[3]==B.orcode[3]){
				if (delta_m(A,B)==1){
					ret = 1;
					
				}
			}
		}
	}
	return ret;
}
int my_strcmp(struct Particle A, struct Particle B){ //Проверяет, что название частицы А полностью входит в начало названия частицы B
	int ret = 1;
	int i;
	for (i=0; i<strlen(A.abbr);i++){
		if (A.abbr[i]!=B.abbr[i])
			ret = -1;
	}
	int k = (int)strlen(B.abbr);
//	printf("%s %d %c%c%c\n",B.abbr.c_str(), k, B.abbr[k-3], B.abbr[k-2], B.abbr[k-1]);
//	printf("%c %c %c\n", B.abbr[k-3], B.abbr[k-2], B.abbr[k-1]);
	if ((B.abbr[k-1]=='R')&&(B.abbr[k-2]=='A')&&(B.abbr[k-3]=='B'))
		ret = -1;
	return ret;

}
void make_parent(struct Particle A[], int i){
	if ((cmp_orcode(A[i], A[i+1]))&&(A[i].abbr[0]==A[i].abbr[0])&&(strcmp(A[i].abbr, "")!=0)){
		int j=i+1;
		while (my_strcmp(A[i], A[j])==1){
			A[j].parent = A[i].id;	
			j++;	
		}
		i=j;
	}
}
void print_(struct Particle A[]){
	printf("Printing...\n");
	int i;
	for (i=0; i<4200; i++){
		make_parent(A, i);
	}
	for (i=0; i<4200; i++){
		if (A[i].parent!=-1){
			int j = A[i].parent;
		printf("Particle %s has a parent %s\n", A[i].abbr, A[j].abbr);
		}
//		if (cmp_orcode(A[i-1], A[i])==1)
//			printf("%d %d %d %d %d %d\n", A[i].orcode[0], A[i].orcode[1], A[i].orcode[2], A[i].orcode[3], A[i].orcode[4], A[i].orcode[5]);
//			printf("%s %s\n", A[i-1].abbr.c_str(), A[i].abbr.c_str());
	}
/*	for (int i=0; i<4200; i++){
		printf("%s %d %d\n", A[i].abbr.c_str(), A[i].id, i );
	}*/
}
struct Particle *make_part(){
	struct Particle *ret = (struct Particle*)malloc(4321*sizeof(struct Particle));

	struct Particle Particles[4321];

    	char *s = (char*)malloc(100*sizeof(char));
	FILE *f = fopen("./vy.dum", "r"); 
	int k=0;
    	while(1){ 
		fgets(s,100,f);
		if (strcmp(s,"*E\n")==0)
			k++;
		else{
			char first[32];
			char abbr[32];
			char ident[32];
			char orrcode[32];
			char m[32];
			int parent = -1;
			int orcode[6]={-1,-1,-1,-1,-1,-1};
			int id = -1;
			char c = s[0];
			int i = 0;
			double mass = -1.;
			Particles[k].mass=mass;
			int q=0;
			while(c!=' '){
				first[q]=c;
				q++;
				i++;
				c = s[i];
			}    
			first[i]='\0';
			if (strcmp(first,"ABBREVIATION")==0){
				i+=3;
				c = s[i];
				int q=0;
				
				Particles[k].abbr = (char*)malloc(32*sizeof(char));
				while(c!=';'){
					Particles[k].abbr[q]=c;
					q++;
					i++;
					c=s[i];		
				}  

			}
	
			if (strcmp(first,"IDENT")==0){
				i+=3;
				c = s[i];
				int q=0;
				while(c!=';'){
					ident[q]=c;
					q++;
					i++;
					c=s[i];
				}
				ident[q]='\0';
				id = atoi(ident);
				Particles[k].id=id;
			}
			if (strcmp(first,"MASS")==0){
		                i+=3;
		                c = s[i];
				int q=0;
		                while(c!=';'){
		                        m[q]=c;
					q++;
		                        i++;
		                        c=s[i];
		                }
				m[q]='\0';
		                mass = atof(m);
		                Particles[k].mass=mass;
			}
		        if (strcmp(first,"ORCODE")==0){
		                i+=3;
		                c = s[i];
				int q=0;
		                while(c!=';'){
		                        orrcode[q]=c;
					q++;
		                        i++;
		                        c=s[i];
		                }
				orrcode[q]='\0';
		                int o = atoi(orrcode);
		                Particles[k].orrcode=o;
				make_orcode(o, Particles[k].orcode);
				Particles[k].parent=parent;
		        }
		}
		
		if (k>4320)
			break;

    	}
	int l;
	for (l=0;l<4321;l++){
	printf("Abbr:%s Id:%d Orcode:%d\n", Particles[l].abbr, Particles[l].id, Particles[l].orrcode);
	}
	fclose(f);
    	ret = Particles;
	return ret;
}

