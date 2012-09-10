#include <stddef.h>

/* rotate n x n array by 90 degrees clockwise */
void *rotate(size_t n, int array[n][n])
{
	size_t nr, nc, m;
	int t;

	nr = n % 2 ? n / 2 + 1 : n / 2;
	nc = n / 2;
	m = n - 1;

	for (size_t r = 0; r != nr; r++){
		for (size_t c = 0; c != nc; c++){
			t                   = array[r    ][c    ];
			array[r    ][c    ] = array[m - c][r    ];
			array[m - c][r    ] = array[m - r][m - c];
			array[m - r][m - c] = array[c    ][m - r];
			array[c    ][m - r] = t;
		}
	}
	return array;
}

#include <stdio.h>

/* print array */
void print(size_t row, size_t col, int array[row][col])
{
	for (size_t r = 0; r != row; r++){
		for (size_t c = 0; c != col; c++)
			printf("%3d", array[r][c]);
		printf("\n");
	}
}

#include <stdio.h>

/* main() */
int main(void)
{
	size_t n = 9;
	int array[n][n];
	for (size_t r = 0; r != n; r++)
		for (size_t c = 0; c != n; c++)
			array[r][c] = r * n + c + 1;
	print(n, n, array);
	rotate(n, array);
	printf("\n");
	print(n, n, array);

	for (size_t r = 0; r != n; r++)
		for (size_t c = 0; c != n; c++){
			if (r < c)
				array[r][c] = -1;
			if (r == c)
				array[r][c] = 0;
			if (r > c)
				array[r][c] = 1;
		}
	printf("\n");
	print(n, n, array);
	rotate(n, array);
	printf("\n");
	print(n, n, array);

	return 0;
}
