#include "Header.h">

void StartView(HashTable& ds, NodePtrLich& lich) {
	

	int choose;
	cout << "\n1. Dang nhap";
	cout << "\n2. Dang ky";
	cout << "\nChon chuc nang: ";
	cin >> choose;
	switch (choose) {
	case 1:
		login(ds,lich);
		break;
	case 2:
		Dangki(ds);
		system("cls");
		StartView(ds,lich);
		break;
	default:
		break;
	}
}