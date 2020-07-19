#include <stdlib.h>
#include <stdio.h>
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



int main(int argc, char *argv[]){
	int i=0;
	struct stacksss stack;
	startstack(&stack);
	for(i=0;i<16;i++)push(&stack,i);
	reportStack(&stack);	
	printf("\n");
	for(i=0;i<16;i++)printf("%d,",pop(&stack));
	printf("\n");
}
