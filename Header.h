#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
enum loaixe {
	tayga,
	xeso
};
struct DatLich {
	char maKH[11];
	int Ca;
	time_t NgayDat;
	char tinhtrang[50];
	char tenxe[50];
	int doixe;
	loaixe loaixe;
	float thoigiandukien;
};
struct NODE_L {
	DatLich datlich;
	NODE_L* link;
};
typedef NODE_L* NodePtrLich;
// Constants
const int MAX = 10;

// Enum for user permissions
enum PhanQuyen {
    admin,
    guess
};

// Struct definitions
struct Khachhang {
    char maKH[11];
    char tenkh[50];
    char matkhau[50];
    PhanQuyen quyen;
};

struct NODE {
    Khachhang KH;
    NODE* link;
};

// Type aliases for clarity
typedef NODE* Nodeptr;

struct HashTable {
    Nodeptr HashTable[MAX];
};

// Core Function Declarations
void initializeHashTable(HashTable& ds);
int hash_funct(char data);
bool insert(HashTable& table, Nodeptr kh);
Nodeptr find(HashTable table, Nodeptr p);
bool xoa(HashTable& ds);

// User management functions
void Dangki(HashTable& ds);
void login(HashTable& ds);
bool CheckPhoneNumExist(HashTable ds, const char sdt[]);
bool CheckPhoneNum(const char a[]);

// File handling functions
void ghiStructVaoFile(const char* filename, HashTable ds);
void docStructTuFile(const char* filename, HashTable& ds);

// Interface and Display functions
void GiaoDien(HashTable& ds, Nodeptr a);
void GiaoDienCH(HashTable& ds, Nodeptr p);
void Xuat(HashTable ds);

// View-related functions
void ViewInfo(Nodeptr p);
void StartView(HashTable& ds);

//Lam viec voi lich trinh
void initLich(NodePtrLich lich);