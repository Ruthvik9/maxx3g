#include <stdio.h>
#define MAX 200

char arr1[MAX], arr2[MAX];
char answer[MAX*2];

int main(){

	scanf("%s%*c",arr1);
	scanf("%s",arr2);
	int i=0,j=0,k=0;
    while(arr1[i]!='\0' && arr2[j]!='\0'){
        if((int)(arr1[i]) > (int)(arr2[j])){
            answer[k] = arr1[i++];
        }
        else if((int)(arr1[i]) < (int)(arr2[j])){
            answer[k] = arr2[j++];
        }
		 else if((int)(arr1[i]) == (int)(arr2[j])){
			if ((int)(arr1[i+1]) > (int)(arr2[j+1])){
				answer[k] = arr1[i++];
			}
			else{
				answer[k] = arr2[j++];
			}
		}
        k++;
    }
    while(arr1[i] != '\0'){
        answer[k++] = arr1[i++];
    }
    while(arr2[j] != '\0'){
        answer[k++] = arr2[j++];
    }
	answer[k] = '\0';

    printf("%s",answer);
	printf("\n");

	return 0;
}
