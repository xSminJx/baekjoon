#include <stdio.h>

int heap[100001];

void heap_up(int idx) {
	if (idx == 1) return;
	else if (heap[idx] < heap[idx / 2]) {
		int temp = heap[idx / 2];
		heap[idx / 2] = heap[idx];
		heap[idx] = temp;
		heap_up(idx / 2);
	}
}

void heap_down(int idx) {
	int midx;
	if (idx > 50000) return;
	if (heap[idx * 2] == 0 && heap[idx * 2 + 1] == 0) {
		return;
	}
	else if (heap[idx * 2] == 0 || heap[idx * 2 + 1] == 0) {
		midx = (heap[idx * 2] < heap[idx * 2 + 1]) ? idx * 2 + 1 : idx * 2;
	}
	else midx = (heap[idx * 2] > heap[idx * 2 + 1]) ? idx * 2 + 1 : idx * 2;

	if (heap[idx] > heap[midx]) {
		int temp = heap[midx];
		heap[midx] = heap[idx];
		heap[idx] = temp;
		heap_down(midx);
	}
}

int main(void) {
	int n, index = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int input;
		scanf("%d", &input);
		if (input != 0) {
			heap[index++] = input;
			heap_up(index - 1);
		}
		else {
			if (index > 1) {
				printf("%d\n", heap[1]);
				heap[1] = heap[index - 1];
				heap[index - 1] = 0;
				index--;
			}
			else printf("0\n");

			heap_down(1);
		}
	}

	return 0;
}
