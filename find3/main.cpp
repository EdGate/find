#include<stdio.h>
#include<stdlib.h>
typedef struct RedType {
	int key;
}RedType;
typedef struct SqList {
	RedType r[21];
	int Length;
}SqList;

int InitSort(int a[20], SqList *L) {
	L = (SqList*)malloc(sizeof(SqList));
	L->Length = 20;
	for (int i = 1;i < 21;i++) {
		L->r[i].key = a[i - 1];
	}
	return 0;
}
int InsertSort(SqList *L)
{
	int i = 0, j = 0;
	for (i = 2;i <= L->Length + 1;i++) {
		if (L->r[i].key < L->r[i - 1].key) {
			/*int index = L->r[i].key;
			L->r[i].key = L->r[i - 1].key;
			L->r[i - 1].key = index;*/
			L->r[0] = L->r[i];
			L->r[i] = L->r[i - 1];
			for (j = i - 2;L->r[0].key < L->r[j].key;j--) {
				int index = L->r[j].key;
				L->r[j].key = L->r[0].key;
				L->r[0].key = index;
				L->r[j + 1] = L->r[j];
			}
			L->r[j + 1] = L->r[0];
		}

	}
	return 0;
}
int CRdisplay(SqList *L) {
	for (int i = 1;i <= L->Length;i++) {
		printf("%d\n", L->r[i].key);
	}
	return 0;
}
int a[20] = { 12,45,55,66,82,45,13,64,58,24,66,32,46,43,51,15,62,26,35,53 };

void main()
{
	SqList *L=NULL;
	InitSort(a,L);
	InsertSort(L);
	printf("%d", L->Length);
	CRdisplay(L);
	system("pause");
}
