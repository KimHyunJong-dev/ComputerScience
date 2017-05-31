// Hash.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

typedef int KeyType;
typedef int ValueType;

typedef struct tagNode
{
	KeyType   Key;
	ValueType Value;
}Node;


typedef struct tagHashTable 
{
	int TableSize;
	Node * Table;
}HashTable;

HashTable * CreateHashTable(int TableSize);
void Set(HashTable* HT, KeyType Key, ValueType Value);
ValueType Get(HashTable* HT, KeyType Key);
void DestroyHashTable(HashTable * HT);
int  Hash(KeyType key, int TableSize);


HashTable * CreateHashTable(int TableSize) 
{
	HashTable * HT = (HashTable*)malloc(sizeof(HashTable));

	HT->Table = (Node*)malloc(sizeof(Node));
	HT->TableSize = TableSize;

	return HT;
}


void Set(HashTable* HT, KeyType Key, ValueType Value)
{
	int Address = Hash(Key, HT->TableSize);

	HT->Table[Address].Key = Key;
	HT->Table[Address].Value = Value;
}


ValueType Get(HashTable* HT, KeyType Key)
{
	int Address = Hash(Key, HT->TableSize);
	return HT->Table[Address].Value;
}

void DestroyHashTable(HashTable * HT)
{
	free(HT->Table);
	free(HT);
}

int Hash(KeyType Key, int TableSize)
{
	return Key % TableSize;
}

int main()
{
	HashTable * HT = CreateHashTable(193);
	Set(HT, 418, 32114);
	Set(HT, 9, 514);
	Set(HT, 27, 8917);
	Set(HT, 1031, 286);

	printf("Key: %d , Value: %d\n", 418, Get(HT, 418));
	printf("Key: %d , Value: %d\n", 9, Get(HT, 9));
	printf("Key: %d , Value: %d\n", 27, Get(HT, 27));
	printf("Key: %d , Value: %d\n", 1031, Get(HT, 1031));

	char ch;
	printf("\n아무키나 누루세요~");
	ch = cin.get();

	DestroyHashTable(HT);
    return 0;
}

