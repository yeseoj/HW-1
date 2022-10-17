/** �˰��� ���� ���� ASSIGNMENT #1
 *	���ϸ�: hw1_sorting_2.cpp
 *	�а�: ����Ʈ�����а�
 *	�й�: 2021041018
 *	�̸�: �忹��
 *	�ȳ�����: txt���ϸ��� "Sample Data.txt"�� �ۼ��Ͽ����ϴ�. �� ������ �̿��Ͽ����ϴ�. ���� Ŭ������ �̿��Ͽ����ϴ�.
 *	������: 2022-10-17
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;


int readFile(FILE*, vector<int>&);			// �ؽ�Ʈ ������ ���ڸ� �о� �迭�� ����� �Լ�(���� Ŭ���� �̿�)
void arrayPrint(vector<int>&);				// �迭�� ȭ�鿡 ����ϴ� �Լ�
void sort(vector<int>&, int, int);			// �迭�� �����ϴ� �Լ�(�� ���� �̿�)


int main() {
	FILE* fp = NULL;						// ���� ������
	vector<int> array;						// ���ڸ� ������ �迭

	/* ���� ���� �迭 ��� */
	readFile(fp, array);
	printf("���� ������ ����մϴ�.\n");
	arrayPrint(array);

	/* ���ĵ� �迭 ��� */
	sort(array, 0, array.size() - 1);
	printf("\n\n���ĵ� �迭�� ����մϴ�.\n");
	arrayPrint(array);

	return 0;
}

/* ���� ������ �о �迭�� ���� */
int readFile(FILE* fp, vector<int>& arr) {
	int n = 0;

	// ���� ����
	fp = fopen("Sample Data.txt", "r");
	if (fp != NULL) {
		printf("���� ���⿡ �����߽��ϴ�.\n");
		while (!feof(fp)) {				// ������ ������ ���� �ϳ��� �о �迭�� ����
			fscanf(fp, "%d,", &n);		// ���� �ϳ��� �о� ������ �����ϰ�, �ش� ���Ҹ� ���Ϳ� �߰���
			arr.push_back(n);
		}
	}
	// �ش� ������ ������ ���α׷� ����
	else {
		printf("���� ���⿡ �����߽��ϴ�.\n");
		exit(1);
	}

	return 0;
}

/* �迭 ��� */
void arrayPrint(vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++)
		printf("%5d ", arr[i]);			// ���ڸ� 5ĭ�� ���缭 �迭 ���(0~99999)
	printf("\n");
}

/* �迭 ���� - quick sort �̿� */
void sort(vector<int>& arr, int l, int r) {
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
