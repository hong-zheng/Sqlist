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

// 初始化线性表
void SqlInit(Sql* sl){
	if (NULL == sl){
		return;
	}
	// 初始化容量为4个
	sl->capacity = mod;
	// 为数组申请空间
	sl->arr = (int*)malloc(sizeof(int)*sl->capacity);
	// 初始大小为0
	sl->size = 0;
}

// 线性表插入
// 尾插
void insert_back(Sql* sl, int key){
	if (NULL == sl){
		return;
	}
	// 先判断插入一个元素是否会溢出,若溢出扩容
	if (isFull(sl)){
		sl->arr = exCapacity(sl);
	}
	sl->arr[sl->size++] = key;
	printf("尾插:添加第[%d]个数[%d]成功！\n", sl->size,key);
}
// 头插
void insert_head(Sql* sl, int key){
	if (NULL == sl){
		return;
	}
	
	// 先判断插入一个元素是否会溢出
	if (isFull(sl)){
		sl->arr = exCapacity(sl);
	}
	for (int i = 0; i < sl->size; i++){
		sl->arr[sl->size - i] = sl->arr[sl->size - i-1];
	}
	sl->arr[0] = key;
	sl->size++;
	printf("头插:添加第[%d]个数[%d]成功！\n", sl->size, key);
}

// 指定位置插入
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
	printf("在位置[%d]:添加第[%d]个数[%d]成功！\n", pos,sl->size, key);
}
//Initial linear table, framing

// 线性表删除

// 头删除
void del_head(Sql* sl){
	if (NULL == sl){
		return;
	}
	for (int i = 0; i < sl->size-1;i++){
		sl->arr[i] = sl->arr[i+1];
	}
	sl->size--;
	printf("已删除头\n");
}
// 尾删除
void del_back(Sql* sl){
	if (NULL == sl){
		return;
	}
	sl->size--;
	printf("已删除尾\n");
}
// 指定位置删除
void del_pos(Sql* sl, int pos){
	if (NULL == sl){
		return;
	}
	for (int i = pos - 1; i < sl->size-1;i++){
		sl->arr[i] = sl->arr[i + 1];
	}
	sl->size--;
	printf("已经删除第%d个元素\n",pos);
}

// 根据元素查找位置,返回位置pos
// 如果有多个，则返回第一个元素的位置
void get_pos(Sql* sl, int key){
	if (NULL == sl){
		return;
	}
	for (int i = 0; i < sl->size;i++){
		if (key == sl->arr[i]){
			printf("第[%d]元素为[%d]\n",i+1,key);
		}
	}
	printf("查找完毕\n");
}
// 根据位置返回元素
void get_element(Sql* sl, int pos){
	if (NULL == sl){
		return;
	}
	printf("位置[%d]的元素为[%d]\n", pos-1,sl->arr[pos - 1]);
	printf("查找完毕\n");
}

// 打印线性表
void PrintSql(Sql* sl){
	if (NULL == sl){
		return;
	}
	for (int i = 0; i < Size(sl);i++){
		printf("[%d]: %d \n",i+1,sl->arr[i]);
	}
	printf("输出完毕！\n");
}
//查看线性表中得元素个数
int Size(Sql* sl){
	if (NULL == sl){
		return;
	}
	return sl->size;
}
// 对线性表进行排序
void sortSql(Sql* sl){
	if (NULL == sl){
		return;
	}
}

// 判断增加元素时线性表是否会溢出
// 溢出返回1，否则返回0
int isFull(Sql* sl){
	if (sl->capacity == Size(sl)){
		// 溢出
		return 1;
	}
	// 不溢出
	return 0;
}
// 给线性表扩容
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