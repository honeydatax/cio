#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void filecopys (FILE *f1,int argc,char *args[]){
	char buffer[1025];
	long l=0;
	FILE *f2;
	f2=fopen(args[argc],"r");
	while(feof(f2)==0){
		l=fread(&buffer,1,1024,f2);
		fwrite(&buffer,1,l,f1);
	}
	fclose(f2);

}


void workspace(int argc,char *args[]){
	long l=0;
	long ll=0;	 
	long lll=0;
	long llll=0;
	int ii=0;
	int iii=0;
	char s[]="          .";
	int i=0;
	FILE *f1;
	char name[34];
	if(argc>2){
		f1=fopen(args[1],"w");
		ii=argc-2;
		fwrite(&ii , 2 ,1 ,f1);
		l=ftell(f1);
		ll=0;
		for(i=2;i<argc;i++){
			fwrite(&name , 32 ,1 ,f1);
			fwrite(&ll , 4 ,1 ,f1);
			fwrite(&ll , 4 ,1 ,f1);
			
		}
		ll=ftell(f1);
		fseek(f1,l,SEEK_SET);
		for(i=2;i<argc;i++){
			iii=strlen(args[i]);
			if(iii>32)iii=32;
			strncpy(name,args[i],iii);
			name[iii]=0;
			fwrite(&name , 32 ,1 ,f1);
			fwrite(&ll , 4 ,1 ,f1);
			l=ftell(f1);
			fseek(f1,ll,SEEK_SET);
			lll=ll;
			filecopys(f1,i,args);
			ll=ftell(f1);
			lll=ll-lll;
			fseek(f1,l,SEEK_SET);
			fwrite(&lll , 4 ,1 ,f1);
			l=ftell(f1);
			
		}
	fclose((f1);
	}

}


int main (int argc,char *args[]){
	workspace(argc,args);
	return 0;
}