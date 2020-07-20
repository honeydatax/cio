#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct stacksss{
	int size;
	int stacks[1024];
};


void startstack(struct stacksss *stack){
	stack->size=0;
}
int push(struct stacksss *stack,int value){
	int i=0;
	i=stack->size;
	stack->stacks[stack->size]=value;
	stack->size++;
	return i;
}
int pop(struct stacksss *stack){
	int i=0;
	i=-1;
	if(stack->size>0){
		stack->size--;
		i=stack->stacks[stack->size];
	}
	return i;
}

void reportStack(struct stacksss *stack){
	int i=0;
	printf("\n");
	for(i=0;i<stack->size;i++){
		printf("%d",stack->stacks[i]);
		if(i!=stack->size-1){
			printf(",");
		}else{
			printf("\n");			
		}
	}
	
}

struct node{
	char caption[32];
	char text[32];
	int back;
	int nexts;
	int parent;
	int sun;
	int delete;
};

struct trees{
	int size;
	int roots;
	struct node nodes[1024];
};

int starttree(struct trees *tree1){
	tree1->size=0;
	tree1->roots=-1;
}

int newnode(struct trees *tree1,char *caption,char *text){
	int i=tree1->size;
	int n=strlen(caption);
	struct node *nnode;
	nnode=&tree1->nodes[tree1->size];
	if(n>31)n=31;
	strncpy(nnode->caption,caption,n);
	n=strlen(text);
	if(n>31)n=31;
	strncpy(nnode->text,text,n);
	nnode->back=-1;
	nnode->nexts=-1;
	nnode->parent=-1;
	nnode->sun=-1;
	nnode->delete=0;
	tree1->size++;
	return i;
}
void reporttree(struct trees *tree1,int node0){
	int b=0;
	int tabs=0;
	int current=node0;
	int pr=0;
	int i=0;
	int counter=0;
	struct stacksss stack;
	struct node *nnode;
	startstack(&stack);
	nnode=&tree1->nodes[node0];
	b=node0;	
	while (b!=-1){
		counter=0;
		pr=0;
		for(i=0;i<tabs;i++)printf("    ");
		printf("%s,%s\n",nnode->caption,nnode->text);
		if(nnode->sun!=-1){
			tabs++;
			push(&stack,current);
			current=nnode->sun;
			nnode=&tree1->nodes[current];
			b=current;
			pr=-1;
		}
		if (pr==0){
			b=nnode->nexts;
			if(b!=-1){
				current=nnode->nexts;
				nnode=&tree1->nodes[current];
				b=current;
				pr=-1;
			}
			if (stack.size > 0 && b==-1){
				b=-1;
				counter=0;
				while(stack.size>0 && b==-1){
					current=pop(&stack);
					tabs--;
					nnode=&tree1->nodes[current];
					counter++;
					b=nnode->nexts;
				}
				if(nnode->nexts != -1){
					current=nnode->nexts;
					nnode=&tree1->nodes[current];
					
				}				
			}
	
			

		}
		if(stack.size < 1 && pr==0){
			b=nnode->nexts;
		}else{
			b=current;
		}

	}

}

void setfather(struct trees *tree1,int node0,int nodeme){
	int i=0;
	int b=0;
	struct node *nnode;
	nnode=&tree1->nodes[node0];
	if(nnode->sun==-1){
		nnode->sun=nodeme;
		nnode=&tree1->nodes[nodeme];
		nnode->parent=node0;
		nnode->nexts=-1;
	}else{
		b=nnode->sun;
		nnode=&tree1->nodes[b];
		while(b!=-1){
			b=nnode->nexts;
			if(b==-1){
				nnode->nexts=nodeme;
				nnode=&tree1->nodes[nodeme];
				nnode->back=b;
				nnode->nexts=-1;
				b=-1;
			}else{
				b=nnode->nexts;
				nnode=&tree1->nodes[b];

			}
		}
	}
}

void settreeRoot(struct trees *tree1,int node0){
	tree1->roots=node0;
}


int main(int argc,char *argv[]){
	struct trees tree1;
	int roots=-1;
	int ARM=-1;
	int X86=-1;
	int APPLE=-1;
	int subnode=-1;
	starttree(&tree1);
	roots=newnode(&tree1,"PC","pcs");
	settreeRoot(&tree1,roots);
	ARM=newnode(&tree1,"ARM","arm");
	X86=newnode(&tree1,"X86","x86");
	APPLE=newnode(&tree1,"APPLE","apple");
	setfather(&tree1,roots,ARM);
	setfather(&tree1,roots,X86);
	setfather(&tree1,roots,APPLE);
	subnode=newnode(&tree1,"ARM6","arm6");
	setfather(&tree1,ARM,subnode);	
	subnode=newnode(&tree1,"ARM7","arm7");
	setfather(&tree1,ARM,subnode);	
	subnode=newnode(&tree1,"X8086","8086");
	setfather(&tree1,X86,subnode);	
	subnode=newnode(&tree1,"X80186","80186");
	setfather(&tree1,X86,subnode);	
	subnode=newnode(&tree1,"X80286","80286");
	setfather(&tree1,X86,subnode);	
	subnode=newnode(&tree1,"X80386","80386");
	setfather(&tree1,X86,subnode);	
	subnode=newnode(&tree1,"X80486","80486");
	setfather(&tree1,X86,subnode);	
	subnode=newnode(&tree1,"X80586","80586");
	setfather(&tree1,X86,subnode);	
	subnode=newnode(&tree1,"MAC","mac");
	setfather(&tree1,APPLE,subnode);	
	reporttree(&tree1,tree1.roots);
}
