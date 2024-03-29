/*
 * main.c
 *
 *  Created on: 18 Dec 2021
 *      Author: jd
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_number(int min, int max) {
	int num = rand() % (max-min) + min;
	return num;
}

void print_array(int l, int *a, char t[]) {
	printf("Print List\n");
	for (int i = 0; i < l; i += 1) {
		printf("%s %4d ", t, a[i]);
	}
	printf("\n");
}

void create_array(int l, int a[]) {
	for (int i=0; i<l; i+=1) {
		a[i] = random_number(0, 100);
	}
}

void copy_array(int *from, int *to, int start, int end) {
    for (int i = start; i <= end; i+= 1) {
        from[i] = to[i];
    }
}

void merge_sort(int i, int j, int *a, int *b) {
    if (j <= i) {
    	return;
    }
    int mid = (i + j) / 2;

    merge_sort(i, mid, a, b);
    merge_sort(mid + 1, j, a, b);

    int pointer_left = i;
    int pointer_right = mid + 1;
    int k;

    for (k = i; k <= j; k++) {
        if (pointer_left == mid + 1) {
            b[k] = a[pointer_right];
            pointer_right++;
        } else if (pointer_right == j + 1) {
            b[k] = a[pointer_left];
            pointer_left++;
        } else if (a[pointer_left] < a[pointer_right]) {
            b[k] = a[pointer_left];
            pointer_left++;
        } else {
            b[k] = a[pointer_right];
            pointer_right++;
        }
    }

    // print_array(j-i, a, "a");
    // print_array(j-i, b, "b");

    copy_array(a, b, i, j);
}

int main(void) {
	printf("merge sort\n");
	int input = 16, a[64], b[64];

	srand(time(NULL));

	create_array(input, a);

	print_array(input, a, "");

	merge_sort(0, input-1, a, b);

	print_array(input, b, "");

	return 0;
}
