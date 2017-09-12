/* 调整一个整数数组，
使得所有的奇数位于数组前半部分，所有的偶数位于数组后半部分
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <math.h>
// #include <stdbool.h>
// #include <stdint.h>
// #include <time.h>
// #include <float.h>
// #include <ctype.h>

#define BOOL int
#define TRUE 1
#define FLASE 0

#define STR_NUM_MAX 50
#define STR_LEN_MAX 20

#define INT_ROW_MAX 50  // 行
#define INT_COL_MAX 50  // 列

#define DIMENSION1 10
#define DIMENSION2 10
#define DIMENSION3 10

static void adjustOrder(int *pData, int length);
static void test();

static int dataTest[DIMENSION1][DIMENSION2] = { 
		{0,1,2,3,4,5,6,7,8,9},
		{0,0,0,0,0,1,1,1,1,1},
		{1,1,1,1,1,2,2,2,2,2},
		{1,1,1,1,1,1,1,1,1,1},
		{2,2,2,2,2,2,2,2,2,2},		
	};
static int dataTestDim1 = 6, dataTestDim2 = 10; 

int main()
{
	test();
	
	//system("pause");
	return 0;
}

static void test()
{	
	
	for(int i1 = 0; i1 < dataTestDim1; i1++) {
		printf("input:");
		for(int i2 = 0; i2 < dataTestDim2; i2++) { printf("%d ",dataTest[i1][i2]); }
		
		adjustOrder(dataTest[i1], dataTestDim2);
		
		printf("\toutput:");
		for(int i2 = 0; i2 < dataTestDim2; i2++) { printf("%d ",dataTest[i1][i2]); }
		printf("\n");
	}
	
	return ;
}

static void adjustOrder(int *pData, int length)
{
	if(pData == NULL || length <= 0) { return ; }
	
	int *pHead = pData;
	int *pTail = pData + length - 1;
	
	while(pHead < pTail) {
		while(pHead < pTail && (*pHead & 0x1) == 1) {
			pHead++;
		}
		while(pHead < pTail && (*pTail & 0x1) == 0) {
			pTail--;
		}
		if(pHead < pTail) {
			int tmp = *pHead;
			*pHead = *pTail;
			*pTail = tmp;
		}
	}	
	return ;
}















