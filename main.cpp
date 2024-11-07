#include "Header.h"


void main() {
	HashTable ds;
	initializeHashTable(ds);
	docStructTuFile("file1.bin", ds);
	NodePtrLich lich=new NODE_L;
	initLich(lich);
	/*Nodeptr p = new NODE;
	p->link = NULL;
	strcpy_s(p->KH.maKH, "0777508199");
	strcpy_s(p->KH.tenkh, "admin");
	strcpy_s(p->KH.matkhau, "admin");
	p->KH.quyen = admin;
	insert(ds, p);
	ghiStructVaoFile("file1.bin", ds);*/
	StartView(ds);
}