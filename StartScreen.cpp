#include "Header.h">

void StartView(HashTable& ds) {
	

	int choose;
	cout << "\n1. Dang nhap";
	cout << "\n2. Dang ky";
	cout << "\nChon chuc nang: ";
	cin >> choose;
	switch (choose) {
	case 1:
		login(ds);
		break;
	case 2:
		Dangki(ds);
		system("cls");
		StartView(ds);
		break;
	default:
		break;
	}
}