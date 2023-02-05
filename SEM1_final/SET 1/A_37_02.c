#include <stdio.h>
int main()
{
	int amount, choice, n100=0, n50=0, n20=0, n10=0;
	printf("Enter amount:\n");
	scanf("%d", &amount);
	if(amount == 0)
	{
		printf("All 0");
		return 0;
	}
	if(amount >= 100)
	{
		n100 = amount/100;
		amount = amount%100;
		if(amount == 0)
		{
			printf("100x%d, rest 0\n", n100);
			return 0;
		}
	}
	
	if(amount < 100 && amount >= 50)
	{
		n50 = amount/50;
		amount = amount%50;
		if(amount == 0 && n100 == 0)
		{
			printf("50x%d, rest 0\n", n50);
			return 0;
		}
	}
	if(amount < 50 && amount >= 20)
	{
		n20 = amount/20;
		amount = amount%20;
		if(amount == 0 && n50 == 0 && n100 == 0)
		{
			printf("20x%d, rest 0\n", n20);
			return 0;
		}
	}
	if(amount < 20 && amount >= 10)
	{
		n10 = amount/10;
		amount = amount%10;
		if(amount == 0 && n100 == 0 && n50 == 0 && n20 == 0)
		{
			printf("10x%d, rest 0\n", n10);
			return 0;
		} 
	}
	if(amount != 0)
	{
		printf("NOT Possible\n");
		return 0;
	}
	printf("100x%d, 50x%d, 20x%d, 10x%d\n", n100, n50, n20, n10);
	return 0;
}