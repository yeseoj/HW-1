/** �˰��� ���� ���� ASSIGNMENT #1
*	���ϸ�: hw1_sorting_1.cpp
*	�а�: ����Ʈ�����а�
*	�й�: 2021041018
*	�̸�: �忹��
*	�ȳ�����: txt���ϸ��� "Sample Data.txt"�� �ۼ��Ͽ����ϴ�. �� ������ �̿��Ͽ����ϴ�.
*	������: 2022-10-17
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int* readFile(FILE*, int*, int*);	// �ؽ�Ʈ ������ ���ڸ� �о� �迭�� �����, �迭�� ��ȯ�ϴ� �Լ�
void arrayPrint(int*, int);			// �迭�� ȭ�鿡 ����ϴ� �Լ�
void sort(int*, int, int);			// �迭�� �����ϴ� �Լ�(�� ���� �̿�)


int main() {
	FILE* fp = NULL;						// ���� ������
	int* array = NULL;						// �迭�� ������ ����Ű�� ������
	int index = 0;							// ���Ͽ� ����� ���� ������ ���� ����

	array = (int*)malloc(sizeof(int));		// int �ϳ���ŭ�� ������ ���� �Ҵ�

	/* ���� ���� �迭 ��� */
	array = readFile(fp, array, &index);
	printf("���� ������ ����մϴ�.\n");
	arrayPrint(array, index);
	
	/* ���ĵ� �迭 ��� */
	sort(array, 0, index-1);
	printf("\n\n���ĵ� �迭�� ����մϴ�.\n");
	arrayPrint(array, index);

	free(array);							// ���� �Ҵ� ����
}


/* ������ �о �迭�� ���� �� ��ȯ */
int* readFile(FILE* fp, int* array, int* index) {
	// ���� ����
	fp = fopen("Sample Data.txt", "r");
	if (fp != NULL) {
		printf("���� ���⿡ �����߽��ϴ�.\n");
		while (!feof(fp)) {												// ������ ������ ���� �ϳ��� �о �迭�� ����
			array = (int*)realloc(array, sizeof(int) * ((*index)+1));	// �ѹ� ������ �� ������ int �ϳ�����ŭ ũ�⸦ Ű�� ���Ҵ�
			fscanf(fp, "%d,", &array[*index]);							// ���ڸ� ������ ����
			(*index)++;
		}
	}
	// �ش� ������ ������ ���α׷� ����
	else {
		printf("���� ���⿡ �����߽��ϴ�.\n");
		exit(1);
	}
	fclose(fp);
	
	// ���ڰ� ����� �迭 ��ȯ
	return array;
}

/* �迭 ��� */
void arrayPrint(int* array, int index) {
	for (int i = 0; i < index; i++)
		printf("%5d ", array[i]);			// ���ڸ� 5ĭ�� ���缭 �迭 ���(0~99999)
	printf("\n");
}

/* �迭 ���� - quick sort �̿� */
void sort(int* arr, int l, int r) {
	// pivot�� �迭�� �߰� �������� ����
	int pivot = arr[(l + r) / 2];
	int i = l; int j = r;
	int temp;

	// ù��° �ε������� ������ arr[i]�� ���� pivot���� Ŀ���� ������ i ����
	// ������ �ε������� ������ arr[j]�� ���� pivot���� �۾����� ������ j ����
	// i�� j�� �����ϱ� ������ arr[i], arr[j]�� ���� ��ȯ -> �����ϸ� ��ȯ ���� ���� ��
	do {
		while (arr[i] < pivot) i++;
		while (arr[j] > pivot) j--;

		if (i <= j) {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++; j--;
		}

	} while (i <= j);
	
	// ���ʿ� ������ �� ���� �ִٸ� 0�� j�� �糡���� �Ͽ� ��� ȣ��
	if (l < j)
		sort(arr, l, j);
	// �����ʿ� ������ �� ���� �ִٸ� i�� ������ �ε����� �糡���� �Ͽ� ��� ȣ��
	if (r > i)
		sort(arr, i, r);
}