/** 알고리즘 정렬 과제 ASSIGNMENT #1
 *	파일명: hw1_sorting_2.cpp
 *	학과: 소프트웨어학과
 *	학번: 2021041018
 *	이름: 장예서
 *	안내사항: txt파일명은 "Sample Data.txt"로 작성하였습니다. 퀵 정렬을 이용하였습니다. 벡터 클래스를 이용하였습니다.
 *	수정일: 2022-10-17
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;


int readFile(FILE*, vector<int>&);			// 텍스트 파일의 숫자를 읽어 배열로 만드는 함수(벡터 클래스 이용)
void arrayPrint(vector<int>&);				// 배열을 화면에 출력하는 함수
void sort(vector<int>&, int, int);			// 배열을 정렬하는 함수(퀵 정렬 이용)


int main() {
	FILE* fp = NULL;						// 파일 포인터
	vector<int> array;						// 숫자를 저장할 배열

	/* 원본 파일 배열 출력 */
	readFile(fp, array);
	printf("파일 내용을 출력합니다.\n");
	arrayPrint(array);

	/* 정렬된 배열 출력 */
	sort(array, 0, array.size() - 1);
	printf("\n\n정렬된 배열을 출력합니다.\n");
	arrayPrint(array);

	return 0;
}

/* 파일 내용을 읽어서 배열로 만듦 */
int readFile(FILE* fp, vector<int>& arr) {
	int n = 0;

	// 파일 열기
	fp = fopen("Sample Data.txt", "r");
	if (fp != NULL) {
		printf("파일 열기에 성공했습니다.\n");
		while (!feof(fp)) {				// 파일의 끝까지 숫자 하나씩 읽어서 배열에 저장
			fscanf(fp, "%d,", &n);		// 숫자 하나를 읽어 변수에 저장하고, 해당 원소를 벡터에 추가함
			arr.push_back(n);
		}
	}
	// 해당 파일이 없으면 프로그램 종료
	else {
		printf("파일 열기에 실패했습니다.\n");
		exit(1);
	}

	return 0;
}

/* 배열 출력 */
void arrayPrint(vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++)
		printf("%5d ", arr[i]);			// 숫자를 5칸에 맞춰서 배열 출력(0~99999)
	printf("\n");
}

/* 배열 정렬 - quick sort 이용 */
void sort(vector<int>& arr, int l, int r) {
	// pivot은 배열의 중간 지점으로 설정
	int pivot = arr[(l + r) / 2];
	int i = l; int j = r;
	int temp;

	// 첫번째 인덱스부터 시작한 arr[i]의 값이 pivot보다 커지기 전까지 i 증가
	// 마지막 인덱스부터 시작한 arr[j]의 값이 pivot보다 작아지기 전까지 j 증가
	// i와 j가 교차하기 전까지 arr[i], arr[j]의 값을 교환 -> 교차하면 교환 없이 루프 끝
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

	// 왼쪽에 정렬할 게 남아 있다면 0과 j를 양끝으로 하여 재귀 호출
	if (l < j)
		sort(arr, l, j);
	// 오른쪽에 정렬할 게 남아 있다면 i와 마지막 인덱스를 양끝으로 하여 재귀 호출
	if (r > i)
		sort(arr, i, r);
}
