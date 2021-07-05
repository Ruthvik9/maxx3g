#include <stdio.h>

int main()
{
	int n;
	long long int k,min_time;
	scanf("%d%lld",&n,&k);
	long long int time[n];

	for(int i=0;i<n;i++)
	{
		scanf("%lld",&time[i]);
	}

	long long int low=1;
	long long int high=1e18;

	while(low <= high)
	{
		long long int mid = (low+high)/2;
		long long int completed = 0;
		for(int i=0;i<n;i++)
		{
			completed += mid/time[i];
			if(completed >= k)
				break;
		}
		if(completed >= k)
		{
			high = mid-1;
			min_time = mid;
		}
		else{
			low = mid+1;
		}
	}
	printf("%lld",min_time);
}
