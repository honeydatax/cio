#include <stdlib.h>
#include <stdio.h>
#include <string.h>

class String{
	private:
		const char* strs;
		int len;
		int max;
	public:
		String(const char *strss){
			setstring(strss);
		}
		const char *getstring(){
			return strs;
		}
		void setstring(const char *strss){
			strs=strss;
		}
		void report(){	
			printf("%s\n",getstring());
		}		
};

class astrings{
	private:
		String *s[1025];
		int sizes;
		int current;
	public:
		astrings(){
			int i=0;
			sizes=1024;
			current=0;
		}
		void add(const char *strss){
			if(current<sizes){
				s[current]=new String(strss);
				current++;
			}
		}
		void report(){
			int i=0;
			for(i=0;i<current;i++)s[i]->report();
		}
};



int main(int argc,char *argv[]){
	const char *a[]={"arm","x86","x186","x286","x386","x486","x586"};
	const char *aa;
	int i=0;
	astrings *s1=new astrings();
	for(i=0;i<7;i++){
		aa=a[i];
		s1->add(aa);
	}
	s1->report();
}