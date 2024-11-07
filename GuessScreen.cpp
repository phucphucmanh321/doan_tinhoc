#include "Header.h"

void login(HashTable &ds) {
	Nodeptr p = new NODE;
	cout << "Nhap SDT: ";
	cin >> p->KH.maKH;
	cout << "Mat khau: ";
	cin >> p->KH.matKhau;
	p->link = NULL;
	Nodeptr a = find(ds, p);
	if (a != NULL && a->KH.quyen == guess)
		GiaoDien(ds, a);
	else if (a != NULL && a->KH.quyen == admin)
		GiaoDienCH(ds, a);
	else { 
		cout << "Sai mat khau"; 
		system("pause");
		login(ds);
	}
}
void GiaoDien(HashTable &ds,Nodeptr p) {
	system("cls");
	int choose;
	cout << "\nXin chao: " << p->KH.tenKH;
	cout << "\nSDT: "<<p->KH.maKH;
	cout << "\n1. Doi mat khau";
	cout << "\n2. Doi SDT";
	cout << "\n3. Dang Xuat";
	cout << "\nChon chuc nang: ";
	cin >> choose;
	switch (choose) {
	case 1:
		break;
	case 2:
		break;
	case 3:
		system("cls");
		StartView(ds);
		break;
	case 4:
		Dat(p);
		break;
	default:
		break;
	}
}