#include "Header.h">

void StartView(HashTable& ds){
	int choose;
	cout << "\n1. Dang nhap";
	cout << "\n2. Dang ky";
	cout << "\n3. Tim kiem";
	cout << "\n4. Save file";
	cout << "\n5. Open file";
	cout << "\nChon chuc nang: ";
	cin >> choose;
	switch (choose) {
	case 1:
		Xuat(ds);
		StartView(ds);
		break;
	case 2:
		Dangki(ds);
		system("cls");
		StartView(ds);
		break;
	case 3:
		int a;
		cout << "Nhap so dien thoai khach hang: ";
		cin >> a;
		ViewInfo(find(ds, a));
		system("cls");
		StartView(ds);
		break;
	case 4:
		ghiStructVaoFile("file1.bin", ds);
		system("cls");
		StartView(ds);
		break;
	case 5:
		docStructTuFile("file1.bin", ds);
		system("cls");
		StartView(ds);
		break;
	default:
		break;
	}
}