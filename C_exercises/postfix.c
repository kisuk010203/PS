#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 200

typedef struct charStack{
	int top;
	char data[MAX];
}charStack;


charStack *initCS(){
	charStack *cs = (charStack*)malloc(sizeof(charStack));
	cs->top = 0;
	return cs;
}
void push(charStack *cs, char letter){
	cs->data[cs->top++] = letter;
}
int isEmpty(charStack *s){
	return s->top == 0;
}
char pop(charStack *s){
	return isEmpty(s) ? '\0' : s->data[--s->top];
}
char topChar(charStack *s){
	return isEmpty(s) ? '\0' : s->data[s->top-1];
}
charStack *reverseStack(charStack *s){
	charStack *temp = initCS();
	while(!isEmpty(s)){
		push(temp, pop(s));
	}
	return temp;
}
void printStack(charStack *s){
	for(int i = 0 ; i<s->top; i++)
		printf("%c", s->data[i]);
	printf("\n");
}
void *changeSeq(charStack *s){
	charStack *temp = initCS();
	charStack *seq = initCS();

	for(int i = 0 ; s->data[i] ; i++){

		char c = s->data[i];
		switch(c){
			case '(' :
				push(temp, c);
				break;
			case '+' :
			case '-' :
				while(!isEmpty(temp) && topChar(temp) != '('){
					push(seq, pop(temp));
					push(seq, ' ');
				}
				push(temp, c);
				break;
			case '*' :
			case '/' :
				while(topChar(temp) == '*' || topChar(temp) == '/'){
					push(seq, pop(temp));
					push(seq, ' ');
				}
				push(temp, c);
				break;
			case ')' :
				while(topChar(temp) != '('){
					push(seq, pop(temp));
					push(seq, ' ');
				}
				pop(temp);
				break;
			default :
				push(seq, c);
				if(s->data[i+1] < '0' || s->data[i+1] > '9')
					push(seq, ' ');
		}
		//printStack(seq);
	}
	while(!isEmpty(temp)){
		push(seq, pop(temp));
	}
	strcpy(s->data, seq->data);
	s->top = seq->top;
}

int main(){
	char cal[15] = "2+3*(5-12)*3-5";
	charStack *cs = initCS();
	for(int i = 0 ; i<15 ; push(cs, cal[i++]));
	printf(" ���� �� : ");
	printStack(cs);
	changeSeq(cs);
	printf(" ���� ǥ�� : ");
	printStack(cs);
	printf(" ��� : ");
	printf("%d", calculate(cs));
}
