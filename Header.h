#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <filesystem>
using namespace std;
// Constants
const int MAX = 10;
const int SoTho = 10;
//DAY
struct DAY {
	int Gio;
	int Ngay;
	int Thang;
	int Nam;
};
enum DVVanChuyen {
	CHVanchuyen,
	KhachVanchuyen
};
enum TrangThai {
	Dangxuly,
	Hoanthanh
};
enum loaixe {
	tayga,
	xeso
};
struct DatLich {
	char maKH[11];
	int ca;
	char tinhTrang[50];
	char tenXe[50];
	int doiXe;
	loaixe loaiXe;
	DAY ngayDat;
	DVVanChuyen dichVuVanChuyen;
	int khoangcach;
	float thoiGianDuKien;
	TrangThai trangThai;
};
struct NODE_L {
	DatLich datLich;
	NODE_L* link;
};
typedef NODE_L* NodePtrLich;


// Enum for user permissions
enum PhanQuyen {
    admin,
    guess
};

// Struct definitions
struct Khachhang {
    char maKH[11];
    char tenKH[50];
    char matKhau[50];
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
void login(HashTable& ds, NodePtrLich& lich);
bool CheckPhoneNumExist(HashTable ds, const char sdt[]);
bool CheckPhoneNum(const char a[]);

// File handling functions
void ghiStructVaoFile(const char* filename, HashTable ds);
void docStructTuFile(const char* filename, HashTable& ds);

// Interface and Display functions
void GiaoDien(HashTable& ds, Nodeptr a, NodePtrLich& lich);
void GiaoDienCH(HashTable& ds, Nodeptr p, NodePtrLich& lich);
void Xuat(HashTable ds);

// View-related functions
void ViewInfo(Nodeptr p);
void StartView(HashTable& ds, NodePtrLich& lich);

//Lam viec voi lich trinh
void initLich(NodePtrLich &lich);
void InsertdatLich(NodePtrLich& ds, NodePtrLich lich_kh);
void Dat(NodePtrLich& Lich, Nodeptr kh);
void hienThiThongTinDatLich(NodePtrLich p);
void OpenLich(const char* filename, NodePtrLich& lich);
void luuLich(const char* filename, NodePtrLich lich);
NodePtrLich taonodeLich(DatLich data);