#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
const int MAX = 10;
struct Khachhang {
	int maKH;
	char tenkh[50];
	char taikhoan[50];
	char matkhau[10];
};
struct NODE {
	Khachhang KH;
	NODE* link;
};
typedef NODE* Nodeptr;
struct HashTable {
	Nodeptr HashTable[MAX];
};
void Xuat(HashTable ds);
int hash_funct(int data);
void insert(HashTable& table, Nodeptr kh);
Nodeptr find(HashTable table, int data);
bool CheckPhoneNum(int a);
void Dangki(HashTable& ds);
void ghiStructVaoFile(const char* filename, HashTable ds);
void docStructTuFile(const char* filename, HashTable& ds);
void initializeHashTable(HashTable& ds);
//View
void ViewInfo(Nodeptr p);
void StartView(HashTable &ds);