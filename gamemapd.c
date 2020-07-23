#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

struct maparrayhead{
	long signature;
	int sizesof;
	int x;
	int y;
	long arraysize;
	int mapslevel;
};

void reportmap(char *map1,int xx,int yy){
	int x=0;
	int y=0;
	char xxxx[xx+2];
	printf("\n");
		for(y=0;y<yy;y++){
			strncpy(&xxxx[0],&map1[y*xx],xx);
			xxxx[xx]=0;
			printf("%s\n",xxxx);
		}
	printf("\n");
}


void savearrayindex(struct maparrayhead *filehead1,long index,char *name,char *arrays){
	FILE *f1;
	int errs=0;
	f1=fopen(name,"r+");
	fseek(f1,((long)index*filehead1->arraysize)+filehead1->sizesof+1,SEEK_SET);
	fwrite(arrays,filehead1->arraysize,1,f1);
	fclose(f1);
}





void loadarrayindex(struct maparrayhead *filehead1,int index,char *name,char *arrays){
	FILE *f1;
	f1=fopen(name,"r+");
	fseek(f1,(index*filehead1->arraysize)+filehead1->sizesof+1,SEEK_SET);
	fread(arrays,filehead1->arraysize,1,f1);
	fclose(f1);
}


void saveheadfilearray(struct maparrayhead *filehead1,char *name,char *mode){
	FILE *f1;
	f1=fopen(name,mode);
	fwrite(filehead1,filehead1->sizesof,1,f1);
	fclose(f1);
} 

void loadheadfilearray(struct maparrayhead *filehead1,int x,int y,char *name){
	FILE *f1;
	struct maparrayhead filehead2;
	f1=fopen(name,"r");
	fread(&filehead2,filehead1->sizesof,1,f1);
	fclose(f1);
	filehead1->signature=999999999;
		filehead1->signature=999999999;
		filehead1->x=x;
		filehead1->y=y;
		filehead1->arraysize=(long)x*y;;
		filehead1->mapslevel=0;
	if(filehead1->signature==filehead2.signature && filehead2.x==x && filehead2.y==y){
		filehead1->mapslevel=filehead2.mapslevel;
	}else{
		filehead1->mapslevel=0;
		printf("file is not a array map\n");
	}

} 





void startfilearray(struct maparrayhead *filehead1,int x,int y,char *name){
	filehead1->signature=999999999;
	filehead1->x=x;
	filehead1->y=y;
	filehead1->arraysize=(long)x*y;
	filehead1->mapslevel=0;
	saveheadfilearray(filehead1,name,"w");
}


void setarray(char *map1,int x,int y,int xx,char value){
	map1[y*xx+x]=value;
}

char getarray(char *map1,int x,int y,int xx){
	char c=map1[y*xx+x];
	return c;
}



void startmap(char *map1,int xx,int yy,int index){
	int x=0;
	for(x=0;x<xx*yy;x++){
		map1[x]=index;
	}
}

void arrayindexfileadd(struct maparrayhead *filehead1,char *name, char *arrays){
	savearrayindex(filehead1,filehead1->mapslevel,name,arrays);
	filehead1->mapslevel++;
	saveheadfilearray(filehead1,name,"r+");

}

int FileExists(char *name){
	int i=0;
	FILE *f1;
	f1=fopen(name,"r");
	if(f1==NULL){
		i=-1;
		//printf("error :%s dont exists or damage\n",name);
	}else{
		i=0;		
		fclose(f1);
	}
	return i;
}

void filearraymaploadlevel(struct maparrayhead *filehead1,char *name, char *arrays,char *filefrom){
	char xxxx[1025];
	int i=0;
	FILE *f1;
	f1=fopen(filefrom,"r");
	for(i=0;i<filehead1->y;i++){
		fgets(xxxx,filehead1->x,f1);
		strncpy(&arrays[i*filehead1->x],xxxx, filehead1->x);
		if(feof(f1))i=filehead1->y+2;
	}
	fclose(f1);
}

void filearraymapsavelevel(struct maparrayhead *filehead1,char *name, char *arrays,int index,char *fileout){
	char xxxx[1025];
	int i=0;
	FILE *f1;
	loadarrayindex(filehead1,index,name,arrays);
	if (strcmp(fileout,"stdout")==0){
		f1=stdout;
	}else{
		f1=fopen(fileout,"w");
	}
	for(i=0;i<filehead1->y;i++){
		strncpy(xxxx,&arrays[i*filehead1->x], filehead1->x);
		xxxx[filehead1->x]=0;
		fprintf(f1,"%s\n",xxxx);
	}
	if (strcmp(fileout,"stdout")!=0)fclose(f1);
}




int main(int argc,char *argv[]){
	int i=0;
	struct maparrayhead filehead1;
	filehead1.sizesof=sizeof(filehead1);
	char map1[12*12+1];
	if(FileExists("array.dat")==-1){
	startfilearray(&filehead1,12,12,"array.dat");
		for(i=0;i<10;i++){
			startmap(&map1[0],filehead1.x,filehead1.y,48+i);
			arrayindexfileadd(&filehead1,"array.dat",&map1[0]);
		}


	}else{
		loadheadfilearray(&filehead1,12,12,"array.dat");
	}
	i=filehead1.mapslevel;
	filearraymaploadlevel(&filehead1,"array.dat", &map1[0],"fileout.txt");
	startmap(&map1[0],filehead1.x,filehead1.y,33);
	loadarrayindex(&filehead1,0,"array.dat",&map1[0]);
	reportmap(&map1[0],filehead1.x,filehead1.y);

}