
#include <stdio.h>
#include <stdbool.h>

bool findPartiion(int arr[], int n)
{
	int sum = 0;
	int i, j;

	for (i = 0; i < n; i++)
		sum += arr[i];

	if (sum % 2 != 0)
		return false;

	bool part[sum / 2 + 1][n + 1];

	for (i = 0; i <= n; i++)
		part[0][i] = true;

	
	for (i = 1; i <= sum / 2; i++)
		part[i][0] = false;

	
	for (i = 1; i <= sum / 2; i++) {
		for (j = 1; j <= n; j++) {
			part[i][j] = part[i][j - 1];
			if (i >= arr[j - 1])
				part[i][j] = part[i][j]
							|| part[i - arr[j - 1]][j - 1];
		}
	}

	
	/*for (i = 0; i <= sum/2; i++)
	{
	for (j = 0; j <= n; j++)
		printf ("%4d", part[i][j]);
	printf("\n");
	} */

	return part[sum / 2][n];
}


int main()
{
	//int arr[] = { 3, 1, 1, 2, 2, 1 };
	printf("enter no of ele of array");
	scanf("%d",&)
	int n = sizeof(arr) / sizeof(arr[0]);

	// Function call
	if (findPartiion(arr, n) == true)
		printf(
			"Can be divided into two subsets of equal sum");
	else
		printf("Can not be divided into two subsets of "
			"equal sum");
	getchar();
	return 0;
}
