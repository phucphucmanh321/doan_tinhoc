#include "Header.h"

void GiaoDienCH(HashTable& ds, Nodeptr p, NodePtrLich& lich) {
	system("cls");
	int choose;
	cout << "\nXin chao cua hang truong: " << p->KH.tenKH;
	cout << "\nSDT: " << p->KH.maKH;
	cout << "\n1. Xoa";
	cout << "\n2. Them";
	cout << "\n3. Dang Xuat";
	cout << "\n4. Xuat danh sach";
	cout << "\n5. Xuat lich khach hang";
	cout << "\n9. Thoat";
	cout << "\nChon chuc nang: ";
	cin >> choose;
	switch (choose) {
	case 1:
		if (xoa(ds)) {
			ghiStructVaoFile("file1.bin", ds);
			docStructTuFile("file1.bin", ds);
		}
		GiaoDienCH(ds, p,lich);
		break;
	case 2:
		break;
	case 3:
		system("cls");
		StartView(ds,lich);
		break;
	case 4:
		system("cls");
		Xuat(ds);
		break;
	case 5:
		hienThiThongTinDatLich(lich);
		break;
	case 9:
		exit(0);
	default:
		break;
	}
}