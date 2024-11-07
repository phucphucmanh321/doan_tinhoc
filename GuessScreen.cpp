#include "Header.h"

void login(HashTable &ds, NodePtrLich& lich) {
	Nodeptr p = new NODE;
	cout << "Nhap SDT: ";
	cin >> p->KH.maKH;
	cout << "Mat khau: ";
	cin >> p->KH.matKhau;
	p->link = NULL;
	Nodeptr a = find(ds, p);
	if (a != NULL && a->KH.quyen == guess)
		GiaoDien(ds, a,lich);
	else if (a != NULL && a->KH.quyen == admin)
		GiaoDienCH(ds, a,lich);
	else { 
		cout << "Sai mat khau"; 
		system("pause");
		login(ds,lich);
	}
}
void GiaoDien(HashTable &ds,Nodeptr p, NodePtrLich& lich) {
	system("cls");
	int choose;
	cout << "\nXin chao: " << p->KH.tenKH;
	cout << "\nSDT: "<<p->KH.maKH;
	cout << "\n1. Doi mat khau";
	cout << "\n2. Doi SDT";
	cout << "\n3. Dang Xuat";
	cout << "\n4. Dat lich hen";
	cout << "\nChon chuc nang: ";
	cin >> choose;
	switch (choose) {
	case 1:
		break;
	case 2:
		break;
	case 3:
		system("cls");
		StartView(ds,lich);
		break;
	case 4:
		Dat(lich,p);
		StartView(ds, lich);
		break;
	default:
		break;
	}
}