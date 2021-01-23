#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct replaceList{
	int size;
	char separator[2048];
	char replacer[2048];	
	char s[2048];
	char ss[2048];
	char *args[2048];
};

void startarglist(struct replaceList *arglists){
	int ll=0;
	int ssizes=0;
	int i=0;
	int ii=0;
	char *s1=NULL;
	char *p1=NULL;
	char *p2=NULL;
	ll=strlen(arglists->separator);
	arglists->size=0;
	arglists->ss[0]=0;
	arglists->s[2046]=0;
	arglists->ss[2046]=0;
	p1=arglists->s;
	arglists->args[0]=arglists->s;
	arglists->size=1;
	while(p1!=NULL){
		p2=strstr(p1,arglists->separator);
		if(p2!=NULL){
			arglists->args[arglists->size]=p2+ll;
			p1=arglists->args[arglists->size];
			p2[0]=0;
			arglists->size++;
			ssizes++;
		}else{
			p1=p2;
		}
		

	}

	for(i=0;i<arglists->size;i++){
		strcat(arglists->ss,arglists->args[i]);
		if(ssizes>0)strcat(arglists->ss,arglists->replacer);
		ssizes--;
	}
}



int main(int argc,char *argv[]){
	struct replaceList replaceLists;
	strcpy(replaceLists.s,"c:\\windows\\dos\\command");
	printf("%s\n",replaceLists.s);
	strcpy(replaceLists.ss,"");
	strcpy(replaceLists.separator,"\\");
	strcpy(replaceLists.replacer,"<--->");
	startarglist(&replaceLists);
	printf("%s\n",replaceLists.ss);

}