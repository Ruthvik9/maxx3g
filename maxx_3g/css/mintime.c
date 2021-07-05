#include <stdio.h>

long long int work(long long int *time, long long int i, long long int length){
	long long int sum = 0;
	for (long long int j = 0; j < length; j++){
		sum += time[j]/i;
	}
	return sum;
}

int main(void) {
	long long int n,k;
	scanf("%lld %lld",&n,&k);
	long long int time[n];
	for (long long int i = 0; i < n; i++){
		scanf("%lld",&time[i]);
	}
	long long int work_done[k];
	for (long long int i = 0; i < k; i++){
		work_done[i] = work(time,i,n);
	}

	for (long long int i = 0; i < k; i++){
		printf("%d ",work_done[i]);
	}
	return 0;
}
