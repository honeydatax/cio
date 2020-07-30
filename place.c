#include <stdio.h>
#include <stdlib.h>
#include <string.h>


	char  *getfile(char *value){
		char *getss;
		getss=value;
		if(strchr(value,'\\')!=NULL){
			getss=strrchr(value,'\\')+1;;
		}
		return getss;
	}



	void getpat(char *value){
		if(strchr(value,'\\')==NULL){
			value[0]=0;
		}else{
			strrchr(value,'\\')[0]=0;
		}

	}







struct arglist{
	int size;
	char separator;
	char *args[2048];
};

struct table{
	char name[14];
	char path[140];
	long start;
	long size;
	int delete;

};

struct storage{
	long sizesof;
	int size;
	long current;
	struct table tables[100];
};

void startarglist(struct arglist *arglists,char *s2){
	char s1[2048];
	char *p1=NULL;
	char *p2=NULL;
	arglists->size=0;
	strncpy(s1,s2,2047);
	s1[2047]=0;
	p1=s1;
	arglists->args[arglists->size]=s1;
	arglists->size++;
	while(p1!=NULL){
		p2=strchr(p1,arglists->separator);
		if(p2!=NULL){
			arglists->args[arglists->size]=p2+1;
			p1=arglists->args[arglists->size];
			p2[0]=0;
			arglists->size++;
		}else{
			p1=p2;
		}
		

	}
}





long storagegetfilesize(struct storage *store1,char *file){
	long filesize=0;
	FILE *f1;
	f1=fopen(file,"r");
	fseek(f1,0,SEEK_SET);
	fseek(f1,0,SEEK_END);
	filesize=ftell(f1);
	fclose(f1);
	return filesize;

}

void storagesave(struct storage *store1,char *filestorage,char *modes){
	FILE *f1;
	f1=fopen(filestorage,modes);
	fseek(f1,0,SEEK_SET);
	fwrite(store1,store1->sizesof,1,f1);
	fclose(f1);
}

void storageload(struct storage *store1,char *filestorage){
	FILE *f1;
	f1=fopen(filestorage,"r");
	fseek(f1,0,SEEK_SET);
	fread(store1,store1->sizesof,1,f1);
	fclose(f1);
}

void startstorage(struct storage *store1,char *filestorage){
	FILE *f1;
	store1->size=0;
	store1->current=store1->sizesof+1;
	storagesave(store1,filestorage,"w");
}

long filecopys1 (char *f1,char *f2,long pos1,long pos2){
	char buffer[1025];
	long l=0;
	FILE *fs1;
	FILE *fs2;
	fs1=fopen(f1,"r");
	fs2=fopen(f2,"r+");
	fseek(fs1,pos1,SEEK_SET);
	fseek(fs2,pos2,SEEK_SET);
	while(feof(fs1)==0){
		l=fread(&buffer,1,1024,fs1);
		fwrite(&buffer,1,l,fs2);
	}
	l=ftell(fs1);
	fclose(fs1);
	fclose(fs2);
	return l;

}


void filecopyss (char *f1,char *f2,long pos1,long pos2,long size){
	char buffer[2049];
	int i=0;
	int ii=0;
	long l=2048;
	long ll=size;
	long lll=0;
	FILE *fs1;
	FILE *fs2;
	if(pos2==-1){
		fs2=stdout;
	}else{
		fs2=fopen(f2,"w");
		fseek(fs2,pos2,SEEK_SET);

	}
	fs1=fopen(f1,"r+");
	fseek(fs1,pos1,SEEK_SET);
	lll=ll/2048;
	ii=(int) lll;
	lll=ll-(lll*2048);
	for(i=0;i<ii;i++){
		fread(&buffer,1,l,fs1);
		fwrite(&buffer,1,l,fs2);
	}
		l=lll;		
		if(l>0){
			fread(&buffer,1,l,fs1);
			fwrite(&buffer,1,l,fs2);
		}
		fclose(fs1);
	if(pos2!=-1)fclose(fs2);
}

void fileexitstore(struct storage *store1,char *filestorage,char *name,char *file){
	long filesize=0;
	int ssize=0;
	int ii=-1;
	int iii=-1;
	int iiii=0;
	long start=0;
	struct table *table1;
	ii=storagefilename(store1,name);
		if(ii!=-1){
			table1=&store1->tables[ii];
			start=table1->start;
			iiii=0;
			if(strcmp("stdout",file)==0)iiii=-1;
			filecopyss(filestorage,file,start,iiii,table1->size);
		
		}else{
			printf("error no more table files\n");
		}
		
}




void filesavestore(struct storage *store1,char *filestorage,char *name,char *file){
	long filesize=0;
	char temsvar[191];
	int ssize=0;
	int ii=-1;
	int iii=-1;
	long start=0;
	struct table *table1;
	strncpy(temsvar,file,189);
	temsvar[189]=0;
	filesize=storagegetfilesize(store1,getfile(temsvar));
	strncpy(temsvar,file,189);
	temsvar[189]=0;
	ii=storagefilename(store1,getfile(temsvar));
	if(ii==-1){
		iii=-1;
		iii=storagesize(store1,filesize);
		if(iii==-1 && store1->size<99){
			iii=store1->size;
			store1->size++;
			table1=&store1->tables[iii];
			table1->start=store1->current;
			store1->current=store1->current+filesize;
			table1->delete=-1;
		}
		if(iii!=-1){
			table1=&store1->tables[iii];
			strncpy(temsvar,file,189);
			temsvar[189]=0;
			getpat(temsvar);
			strncpy(table1->path,temsvar,138);
			strncpy(temsvar,file,189);
			temsvar[189]=0;
			strncpy(table1->name,getfile(temsvar),11);
			table1->name[11]=0;
			table1->path[138]=0;
			table1->size=filesize;
			table1->delete=0;
			filecopys1(name,filestorage,0,table1->start);
		}else{
			printf("error no more table files\n");
		}
		

	}
	storagesave(store1,filestorage,"r+");
	
}

int storagefilename(struct storage *store1,char *name){
	int i=0;
	int ii=-1;
	struct table *table1;
	for(i=0;i<store1->size;i++){
		table1=&store1->tables[i];
		if(strcmp(name,table1->name)==0){
			ii=i;
			i=store1->size+2;
		}
	}
	return ii;
}

int storagesize(struct storage *store1,long size){
	int i=0;
	int ii=-1;
	long sizes=0;
	struct table *table1;
	for(i=0;i<store1->size;i++){
		table1=&store1->tables[i];
	    if(table1->delete!=0){
		sizes=(table1->size)-size;
		if(size>-1 && sizes<65){
			ii=i;
			i=store1->size+2;
		}
	   }
	}
	return ii;
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

void storegedeletefile(struct storage *store1,char *filestorage,char *name){
	int ii;
	struct table *table1;
	ii=storagefilename(store1,name);
	if(ii!=-1){
			table1=&store1->tables[ii];
			table1->name[0]=0;
			table1->delete=-1;

		}else{
			printf("error no find file in table files\n");
		}

	storagesave(store1,filestorage,"r+");
}

void storegeloadtable(struct storage *store1,char *filestorage){
	FILE *f1;
	int i=0;
	long filesizeof=store1->sizesof;
	struct storage store2;
	struct storage *store3;
	store3=&store2;
	store1->size=0;
	store1->current=store1->sizesof+1;
	f1=fopen(filestorage,"r");
	fread(store3,store1->sizesof-1,1,f1);
	fclose(f1);
	if(store1->sizesof==store3->sizesof){
		storageload(store1,filestorage);
	}else{
		printf("this is not a storege file or not same version\n");
	}
}

void storeprinttable (struct storage *store1){
	int i=0;
	struct table *table1;
	for(i=0;i<store1->size;i++){
			table1=&store1->tables[i];
			if(table1->delete!=-1)printf("%15s|%12d|%12d|%7d| %s\n",table1->name,table1->start,table1->size,table1->delete,table1->path);
	}
}

void storeprinttablelist (struct storage *store1,char *path){
	int i=0;
	struct table *table1;
	for(i=0;i<store1->size;i++){
			table1=&store1->tables[i];
			if(table1->delete!=-1 && strcmp(path,table1->path)==0)printf("%15s|%12d|%12d|%7d| %s\n",table1->name,table1->start,table1->size,table1->delete,table1->path);
	}
}


void storagemacrosave(struct storage *store1,char *filestorage,char *key){
	int i=0;
	struct arglist arglists;
	char separator=';';
	arglists.separator=separator;
	startarglist(&arglists,key);
	for(i=0;i<arglists.size;i++){
		if(FileExists(arglists.args[i])==0){	
			filesavestore(store1,filestorage,arglists.args[i],arglists.args[i]);
		}else{
			printf("error : %s file not find\n",arglists.args[i]);
		}
	}
}

void storagemacroexits(struct storage *store1,char *filestorage,char *key){
	int i=0;
	struct arglist arglists;
	char separator=';';
	arglists.separator=separator;
	startarglist(&arglists,key);
	for(i=0;i<arglists.size;i++){
			fileexitstore(store1,filestorage,arglists.args[i],arglists.args[i]);
	}
}



void storedeletefiletable (struct storage *store1,char *file,char *path){
	int i=0;
	struct table *table1;
	for(i=0;i<store1->size;i++){
			table1=&store1->tables[i];
			if(table1->delete!=-1 && strcmp(path,table1->path)==0)storegedeletefile(store1,file,table1->name);
	}
}

void storedeletetreefiletable (struct storage *store1,char *file,char *path){
	int i=0;
	struct table *table1;
	for(i=0;i<store1->size;i++){
			table1=&store1->tables[i];
			if(table1->delete!=-1 && strncmp(path,table1->path,strlen(path))==0)storegedeletefile(store1,file,table1->name);
	}
}



int main (int argc,char *argv[]){
	struct storage store1;
	store1.sizesof=sizeof(store1);
	if(FileExists("my.dat")!=0){
		startstorage(&store1,"my.dat");

		if(FileExists("file1.txt")==0){	
			filesavestore(&store1,"my.dat","file1.txt","windows\\command\\file1.txt");
		}


		if(FileExists("file2.txt")==0){	
			filesavestore(&store1,"my.dat","file2.txt","windows\\command\\file2.txt");
		}


		if(FileExists("file2.txt")==0){	
			filesavestore(&store1,"my.dat","file2.txt","windows\\file3.txt");
		}

		if(FileExists("file2.txt")==0){	
			filesavestore(&store1,"my.dat","file2.txt","windows\\file4.txt");
		}

		if(FileExists("file2.txt")==0){	
			filesavestore(&store1,"my.dat","file2.txt","dos\\file5.txt");
		}

		if(FileExists("file2.txt")==0){	
			filesavestore(&store1,"my.dat","file2.txt","dos\\file6.txt");
		}




	}else{
		storegeloadtable(&store1,"my.dat");
	}
	
	storedeletetreefiletable(&store1,"my.dat","windows");
	storeprinttable(&store1);
	return 0;

}


