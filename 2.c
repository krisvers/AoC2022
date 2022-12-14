#include <stdio.h>
#include <stdbool.h>

int score = 0;

void win(int p, int op)
{
	score += p;
	if ((p > op && !(p == 3 && op == 1)) || (p == 1 && op == 3))
	{
		score += 6;
	}
	else if (p == op)
	{
		score += 3;
	}
}

int main()
{
	int pmove, opmove = 0;

	FILE * fp = fopen("input2.txt", "r");

	for (int c = fgetc(fp); c != EOF; c = fgetc(fp))
	{
		if (c >= 'A' && c <= 'C')
		{
			opmove = c-'A'+1;
		}
		else if (c >= 'X' && c <= 'Z')
		{
			pmove = c-'X'+1;

			win(pmove, opmove);
		}
	}

	fclose(fp);

	printf("%i\n", score);

	return 0;
}
