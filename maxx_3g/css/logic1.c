#include <stdio.h>
#include <stdlib.h>

typedef struct{
  char *data;
  int top;
  int size;
}Stack;


void push(Stack *sp, char value);
char pop(Stack *sp);
char peep(Stack *sp);
Stack* init(int size);
char valuation(char elements[],int length);
char binaryResult(char one,char oper,char two);
char unaryResult(char one);

int main(){

  int count=0,i=0,value=0;
  char temp[1000];
  printf("Enter propositional formula: ");
  scanf("%s",temp);
  while(5){
    if (temp[i]!='\0'){
    count++;
    i++;
  }else{
    break;
  }
  }

  char temp1[count],elements[count];
  for (int i=0;i<count;i++){
    temp1[i]=temp[i];
  }




elements=createValuation(temp1,count);


printf("%c",valuation(elements,count));


}

char* createValuation(char *temp1,int count){
      char elements[count];
      char truthValues[2][count];
      for (int i=0;i<count;i++){
        if (temp1[i]!='('&&temp1[i]!='>'&&temp1[i]!=')'&&temp1[i]!='^'&&temp1[i]!='V'&&temp1[i]!='~'){
           for(int j=0;j<count;j++){
             if (truthValues[0][j]==temp1[i]){
               value=1;
               break;
             }
           }
             if(value!=1){
               truthValues[0][i]=temp1[i];
             }else{
               value=0;
             }


           }
        }
        for(int i=0;i<count;i++){
          if(truthValues[0][i]!='\0'){
            printf("Enter valuation of %c(T/F):",truthValues[0][i]);
            scanf("%c",&truthValues[1][i]);
          }
        }

        for(int i=0;i<count;i++){
          if (temp1[i]=='('|temp1[i]==')'|temp1[i]=='V'|temp1[i]=='^'|temp1[i]=='>'|temp1[i]=='~'){
            elements[i]=temp1[i];
          }else{
            for(int j=0;j<count;j++){
              if (truthValues[0][j]==temp1[i]){
                elements[i]=truthValues[1][j];
                break;
              }
            }
          }
        }
        return elements;

}


char valuation (char elements[],int length){
  int pos=0,removed=0;
  char popFirst,popSecond,popOperator;
  Stack *operators=init(10);
  Stack *operand=init(10);
  do{
    if (elements[pos]==')'){
       do{
       removed=1;
       popOperator=pop(operators);
       if (popOperator=='^'||popOperator=='>'||popOperator=='V'){
         popFirst=pop(operand);
         popSecond=pop(operand);
         push(operand,binaryResult(popFirst,popOperator,popSecond));
       }else{
         popFirst=pop(operand);
         push(operand,unaryResult(popFirst));
       }
    }while(peep(operators)!='(');

  if (removed==1){
    pop(operators);
    removed=0;
  }

  }else{
       if (elements[pos]=='T'||elements[pos]=='F'){
           push(operand,elements[pos]);

       }else{
           push(operators,elements[pos]);


       }
 }
 if(pos<length-1){
 pos++;
}


}while(operators->top>-1);
  return pop(operand);
}


char unaryResult(char one){
  if (one=='T'){
    return 'F';
  }else{
    return 'T';
  }
}

char binaryResult(char one,char oper,char two){
  if (one=='T'&&two=='T'){
    if (oper=='V'){
      return 'T';
    }else if (oper=='^'){
      return 'T';
    }else{
      return 'T';
    }
  }else if(one =='T'&&two=='F'){
    if (oper=='V'){
      return 'T';
    }else if (oper=='^'){
      return 'F';
    }else{
      return 'T';
    }
  }else if (one=='F'&&two=='T'){
    if (oper=='V'){
      return 'T';
    }else if (oper=='^'){
      return 'F';
    }else{
      return 'F';
    }
  }else{
    if (oper=='V'){
      return 'F';
    }else if (oper=='^'){
      return 'F';
    }else{
      return 'T';
    }
  }
}


void push(Stack *sp, char value){
  if(sp->top==sp->size-1){
    char *temp = (char *)malloc(sizeof(char) * (sp->size)*2);
    int i=0;
    for (int i=0;i<sp->size;i++){
      temp[i]=sp->data[i];
    }
    free(sp->data);
    sp->data=temp;
    printf("Stage 5");
    sp->size*=2;
  }

  sp->data[++sp->top]=value;
}

char pop(Stack *sp){
    return sp->data[sp->top--];
}

char peep(Stack *sp){
  return sp->data[sp->top];
}

Stack* init(int size){
  Stack *sp=(Stack*)malloc(sizeof(Stack));
  sp->data=(char *)malloc(sizeof(char)*size);
  sp->top=-1;
  sp->size=size;

  return sp;
}
