#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>
#include <intrin.h>

#define SIZE 1000
#define RAND_MAX 10000
#pragma warning(disable:4996)

uint64_t rdtsc() {
	return __rdtsc();
}
int main(){
	FILE *fi = fopen("i.csv", "w"), *fc = fopen("cycle.csv", "w"), *fu = fopen("u.csv", "w");
	int m = 0, n = 0, p = 0, q = 0, i, j, k, sum = 0, input = 0, count = 1;
	char ch;
	static int first[SIZE][SIZE], second[SIZE][SIZE], multiply[SIZE][SIZE];
	printf("Randomize matrix?(y/n)\n");
	scanf(" %c", &ch);
	if (ch == 'y') {
		for (i = 0; i < SIZE; i++) {
			for (j = 0; j < SIZE; j++) {
				first[i][j] = rand() % RAND_MAX + 0;
				second[i][j] = rand() % RAND_MAX + 0;
			}
		}
	}
	else {
		printf("Enter the elements of first matrix\n");
		for (i = 0; i < SIZE; i++) {
			for (j = 0; j < SIZE; j++) {
				scanf("%d", &first[i][j]);
			}
		}
		printf("Enter the elements of second matrix\n");
		for (i = 0; i < p; i++) {
			for (j = 0; j < q; j++) {
				scanf("%d", &second[i][j]);
			}
		}
	}
	printf("How do you want to run your iteratons? 1: ijk 2: kji 3: kij 4: jik 5: jki 6: ikj\n");
	scanf(" %d", &input);
	unsigned __int64 x, x0, diff;
	while (m < SIZE) {
		switch (input) {
		case 1:
			x0 = __rdtsc();
			for (i = 0; i < m; i++) {
				for (j = 0; j < q; j++) {
					for (k = 0; k < p; k++) {
						sum = sum + first[i][k] * second[k][j];
					}
					multiply[i][j] = sum;
					sum = 0;
				}
			}
			x = __rdtsc();
			diff = x - x0;
			printf("It took %I64d cycles to finish process #%d.\n", diff, count);
			fprintf(fu, "%I64d\n", diff);
			break;
		case 2:
			x0 = __rdtsc();
			for (k = 0; k < m; k++) {
				for (j = 0; j < q; j++) {
					for (i = 0; i < p; i++) {
						sum = sum + first[i][j] * second[i][k];
					}
					multiply[i][j] = sum;
					sum = 0;
				}
			}
			x = __rdtsc();
			diff = x - x0;
			printf("It took %I64d cycles to finish process #%d.\n", diff, count);
			fprintf(fu, "%I64d\n", diff);
			break;
		case 3:
			x0 = __rdtsc();
			for (k = 0; k < m; k++) {
				for (i = 0; i < q; i++) {
					for (j = 0; j < p; j++) {
						sum = sum + first[i][k] * second[k][j];
					}
					multiply[i][j] = sum;
					sum = 0;
				}
			}
			x = __rdtsc();
			diff = x - x0;
			printf("It took %I64d cycles to finish process #%d.\n", diff, count);
			fprintf(fu, "%I64d\n", diff);
			break;
		case 4:
			x0 = __rdtsc();
			for (j = 0; j < m; j++) {
				for (i = 0; i < q; i++) {
					for (k = 0; k < p; k++) {
						sum = sum + first[i][k] * second[k][j];
					}
					multiply[i][j] = sum;
					sum = 0;
				}
			}
			x = __rdtsc();
			diff = x - x0;
			printf("It took %I64d cycles to finish process #%d.\n", diff, count);
			fprintf(fu, "%I64d\n", diff);
			break;
		case 5:
			x0 = __rdtsc();
			for (j = 0; j < m; j++) {
				for (k = 0; k < q; k++) {
					for (i = 0; i < p; i++) {
						sum = sum + first[i][k] * second[k][j];
					}
					multiply[i][j] = sum;
					sum = 0;
				}
			}
			x = __rdtsc();
			diff = x - x0;
			printf("It took %I64d cycles to finish process #%d.\n", diff, count);
			fprintf(fu, "%I64d\n", diff);
			break;
		case 6:
			x0 = __rdtsc();
			for (i = 0; i < m; i++) {
				for (k = 0; k < q; k++) {
					for (j = 0; j < p; j++) {
						sum = sum + first[i][k] * second[k][j];
					}
					multiply[i][j] = sum;
					sum = 0;
				}
			}
			x = __rdtsc();
			diff = x - x0;
			printf("It took %I64d cycles to finish process #%d.\n", diff, count);
			fprintf(fu, "%I64d\n", diff);

			break;
		defualt:
			printf("\ninvalid input!\n");
			return 1;
		}
		m += 50, p += 50, q += 50, n += 50;
		count++;
	}
	for (i = 0; i <= m; i += 50) {
		fprintf(fi, "%d\n", i);
	}
	fclose(fu);
	fclose(fi);
	fclose(fc);
	system("cls");
	printf("\nDone!\n");
	return 0;
}