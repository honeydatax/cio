#include<stdlib.h>
#include<stdio.h>

void filecopyss (FILE *f1,long ll,char *args){
	
	char buffer[2049];
	int i=0;
	int ii=0;
	long l=2048;
	long lll=0;
	FILE *f2;
	f2=fopen(args,"w");
	lll=ll/2048;
	ii=(int) lll;
	lll=ll-(lll*2048);
	for(i=0;i<ii;i++){
		fread(&buffer,1,l,f1);
		fwrite(&buffer,1,l,f2);
	}
		l=lll;		
		if(l>0){
			fread(&buffer,1,l,f1);
			fwrite(&buffer,1,l,f2);
		}

}

 
void unpack(int argc,char *args[]){
	long l=0;
	long ll=0;	 
	long lll=0;
	long llll=0;
	char name[33];
	int ii=0;
	char s[]="          .";
	int i=0;
	FILE *f1;
	if(argc>1){
		f1=fopen(args[1],"r");
		ii=argc-2;
		fread(&ii , 2 ,1 ,f1);
		l=ftell(f1);
		for(i=0;i<ii;i++){
			fread(&name,1,32,f1);
			fread(&ll , 1 ,4 ,f1);
			fread(&lll , 1 ,4 ,f1);
			l=ftell(f1);
			fseek(f1,ll,SEEK_SET);
			printf("%s\n",name);
			filecopyss(f1,lll,name);
			fseek(f1,l,SEEK_SET);
		}
	feof(f1);
	}

}


int main (int argc,char *args[]){
	unpack(argc,args);
	return 0;
}