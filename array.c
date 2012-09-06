/* rotate n x n array by 90 degrees clockwise */

void *rotate(int n, char array[n][n])
{
	int nr, nc, t, m;

	nr = n % 2 ? n / 2 + 1 : n / 2;
	nc = n / 2;
	m = n - 1;

	for (int r = 0; r != nr; r++){
		for (int c = 0; c != nc; c++){
			t                   = array[r    ][c    ];
			array[r    ][c    ] = array[m - c][r    ];
			array[m - c][r    ] = array[m - r][m - c];
			array[m - r][m - c] = array[c    ][m - r];
			array[c    ][m - r] = t;
		}
	}
	return array;
}

/* print n x n array */

void print(int n, char array[n][n])
{
	for (int r = 0; r != n; r++){
		for (int c = 0; c != n; c++)
			printf("%d ", array[r][c]);
		printf("\n");
	}
}

/* main() */
#include <stdio.h>
int main(void)
{
	int n = 5;
	char array[n][n];
	for (int r = 0; r != n; r++)
		for (int c = 0; c != n; c++)
			array[r][c] = r * n + c + 1;

	print(n, array);

	rotate(n, array);
	printf("\n");

	print(n, array);
	return 0;
}
