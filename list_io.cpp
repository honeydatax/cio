#include <stdlib.h>
#include <stdio.h>
#include <string.h>
class list{
	private: 
		int current;
		int sizes;
		const char *c[1025]; 
	public :
		list(int ssizes){
			current=0;
			sizes=0;
		}
		void add(const char *cc){
			if (sizes<1024){
				c[sizes]=cc;
				sizes++;
			}
		}
		int getsizes(){
			return current;
		}
		void report(){
			int i=0;
			for(i=0;i<sizes;i++)printf("%s\n",c[i]);
		}
};

int main(){
	const char *a[]={"arm",
		"x86","x8086","x80186","x80286","x80386","x80486","x80586","\0"};
	const char *c;
	int i=0;
	list *l1=new list(1024);
	for(i=0;i<8;i++){
		c=a[i];
		l1->add(c);
	}
	l1->report();
}