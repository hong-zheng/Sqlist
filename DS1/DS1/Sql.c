#include "Sql.h"

void test(){
	Sql sl;
	SqlInit(&sl);
	insert_back(&sl, 1234);
	insert_back(&sl, 12);
	insert_back(&sl, 34);
	insert_head(&sl, 1);
	insert_head(&sl, 2);
	insert_head(&sl, 3);
	insert_pos(&sl, 1, 111);
	insert_pos(&sl, 1, 131);
	insert_pos(&sl, 1, 121);
	PrintSql(&sl);
	get_pos(&sl, 1234);
	del_head(&sl);
	del_head(&sl);
	PrintSql(&sl);
	del_back(&sl);
	PrintSql(&sl);
	del_pos(&sl, 2);
	PrintSql(&sl);
	del_pos(&sl, 1);
	PrintSql(&sl);
}

// ��ʼ�����Ա�
void SqlInit(Sql* sl){
	if (NULL == sl){
		return;
	}
	// ��ʼ������Ϊ4��
	sl->capacity = mod;
	// Ϊ��������ռ�
	sl->arr = (int*)malloc(sizeof(int)*sl->capacity);
	// ��ʼ��СΪ0
	sl->size = 0;
}

// ���Ա����
// β��
void insert_back(Sql* sl, int key){
	if (NULL == sl){
		return;
	}
	// ���жϲ���һ��Ԫ���Ƿ�����,���������
	if (isFull(sl)){
		sl->arr = exCapacity(sl);
	}
	sl->arr[sl->size++] = key;
	printf("β��:��ӵ�[%d]����[%d]�ɹ���\n", sl->size,key);
}
// ͷ��
void insert_head(Sql* sl, int key){
	if (NULL == sl){
		return;
	}
	
	// ���жϲ���һ��Ԫ���Ƿ�����
	if (isFull(sl)){
		sl->arr = exCapacity(sl);
	}
	for (int i = 0; i < sl->size; i++){
		sl->arr[sl->size - i] = sl->arr[sl->size - i-1];
	}
	sl->arr[0] = key;
	sl->size++;
	printf("ͷ��:��ӵ�[%d]����[%d]�ɹ���\n", sl->size, key);
}

// ָ��λ�ò���
void insert_pos(Sql* sl, int pos, int key){
	if (NULL == sl){
		return;
	}
	if (isFull(sl)){
		sl->arr = exCapacity(sl);
	}
	//        pos=3 size = 7
	//   7 63 9 7 6 7 3
	for (int i = 0; i < (sl->size - pos + 1); i++){
		sl->arr[sl->size - i] = sl->arr[sl->size - i - 1];
	}
	sl->arr[pos - 1] = key;
	sl->size++;
	printf("��λ��[%d]:��ӵ�[%d]����[%d]�ɹ���\n", pos,sl->size, key);
}
//Initial linear table, framing

// ���Ա�ɾ��

// ͷɾ��
void del_head(Sql* sl){
	if (NULL == sl){
		return;
	}
	for (int i = 0; i < sl->size-1;i++){
		sl->arr[i] = sl->arr[i+1];
	}
	sl->size--;
	printf("��ɾ��ͷ\n");
}
// βɾ��
void del_back(Sql* sl){
	if (NULL == sl){
		return;
	}
	sl->size--;
	printf("��ɾ��β\n");
}
// ָ��λ��ɾ��
void del_pos(Sql* sl, int pos){
	if (NULL == sl){
		return;
	}
	for (int i = pos - 1; i < sl->size-1;i++){
		sl->arr[i] = sl->arr[i + 1];
	}
	sl->size--;
	printf("�Ѿ�ɾ����%d��Ԫ��\n",pos);
}

// ����Ԫ�ز���λ��,����λ��pos
// ����ж�����򷵻ص�һ��Ԫ�ص�λ��
void get_pos(Sql* sl, int key){
	if (NULL == sl){
		return;
	}
	for (int i = 0; i < sl->size;i++){
		if (key == sl->arr[i]){
			printf("��[%d]Ԫ��Ϊ[%d]\n",i+1,key);
		}
	}
	printf("�������\n");
}
// ����λ�÷���Ԫ��
void get_element(Sql* sl, int pos){
	if (NULL == sl){
		return;
	}
	printf("λ��[%d]��Ԫ��Ϊ[%d]\n", pos-1,sl->arr[pos - 1]);
	printf("�������\n");
}

// ��ӡ���Ա�
void PrintSql(Sql* sl){
	if (NULL == sl){
		return;
	}
	for (int i = 0; i < Size(sl);i++){
		printf("[%d]: %d \n",i+1,sl->arr[i]);
	}
	printf("�����ϣ�\n");
}
//�鿴���Ա��е�Ԫ�ظ���
int Size(Sql* sl){
	if (NULL == sl){
		return;
	}
	return sl->size;
}
// �����Ա��������
void sortSql(Sql* sl){
	if (NULL == sl){
		return;
	}
}

// �ж�����Ԫ��ʱ���Ա��Ƿ�����
// �������1�����򷵻�0
int isFull(Sql* sl){
	if (sl->capacity == Size(sl)){
		// ���
		return 1;
	}
	// �����
	return 0;
}
// �����Ա�����
int* exCapacity(Sql* sl){
	sl->capacity += mod;
	int* src = sl->arr;
	sl->arr = (int*)malloc(sizeof(int)*sl->capacity);
	memcpy(sl->arr,src,sizeof(int)*Size(sl));
	return sl->arr;
}

int main(){
	test();
	system("pause");
	return 0;
}