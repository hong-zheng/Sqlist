
//#define _CRT_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//
//void Sort_bubble(int* arr,int len){
//	for (int i = 0; i < len - 1;i++){
//		for (int j = 0; j < len - i - 1;j++){
//			if (*(arr + j + 1)>*(arr + j)){
//				int tmp = *(arr + j);
//				*(arr + j) = *(arr + j + 1);
//				*(arr + j + 1) = tmp;
//			}
//		}
//	}
//}
//void print(int* arr,int len){
//	for (int i=0; i < len;i++){
//		printf("%d ",*(arr+i));
//	}
//	printf("\n");
//}
//int findPos(int* arr,int len,int key){
//	for (int i = 0; i < len;i++){
//		if (key == *(arr+i)){
//			// �ҵ���������
//			return i;
//		}
//	}
//	// û�ҵ�������-1
//	return -1;
//}
//int insert(int* arr,int len,int key){
//	int pos = 0;
//	for (int i = len-1; i >= 0;i--){
//		if (key > *(arr + i) && key > *(arr + i + 1)){
//			pos = i+1;
//			break;
//		}
//	}
//	//           1 2 3 5 6 7 4
//	for (int i = 0; i < len - pos;i++){
//		arr[len + 1 - i] = arr[len - i];
//	}
//	arr[pos] = key;
//	return pos;
//}
////����һ�����������һ��Ŀ��ֵ��
////���������ҵ�Ŀ��ֵ����������������
////���Ŀ��ֵ�������������У�
////���������ᱻ��˳������λ�á�
////����Լ������������ظ�Ԫ�ء�
//int FIPos(int* arr, int len,int key){
//	int pos = findPos(arr,len,key);
//	if (-1 != pos){
//		return pos;
//	}
//	return insert(arr, len, key);
//}
//int main(){
//	int arr[] = {12,4,3,52,46,57,643,286,3,90,21,38,93,65};
//	int len = sizeof(arr) / sizeof(arr[0]);
//	print(arr, len);
//	Sort_bubble(arr,len);
//	print(arr, len);
//	printf("%d\n", FIPos(arr,len,29));
//	print(arr, len);
//	//printf("%d\n", findPos(arr,len,90));
//	//print(arr, len);
//	//Sort_bubble(arr,len);
//	//print(arr, len);
//	printf("end\n");
//	system("pause");
//	return 0;
//}