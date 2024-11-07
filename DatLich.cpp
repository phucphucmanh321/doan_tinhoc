#include "Header.h"

void initLich(NodePtrLich lich) {
	lich = NULL;
}
void XuLyLichTrinhTrongNgay(HashTable ds) {
	int count = 0;
	for (int i = 0; i < MAX; i++)
	{
		Nodeptr p = ds.HashTable[i];
		while (p != NULL) {
			if(p->KH)
				đặt lịch sửa xe,
				khoảng cách xe gần dắt tới, xa hơn thì đề xuất,
				đội ngũ đưa xe đến chi phí bao nhiêu,

			p = p->link;
		}
	}
}
bool InsertDatLich(NodePtrLich lich,int ca) {
	int count = 0;
	
}
void Dat(HashTable& ds,NodePtrLich kh) {
	NodePtrLich p = new NODE_L;
	XuLyLichTrinhTrongNgay(ds);
	cout << "\nChon ca: ";
	cin >> p->datlich.Ca;
	cout << "\nNhap loai xe 1=Tay ga, 2=Xe so: ";
	int input;
	cin >> input;
	p->datlich.loaixe = static_cast<loaixe>(input);
	cout << "\nNhap ten xe: ";
	cin.ignore();
	cin.getline(p->datlich.tenxe,50);
	cout << "\nNhap doi xe: ";
	cin >> p->datlich.doixe;
	cout << "\nMo ta tinh trang: ";
	cin.ignore();
	cin.getline(p->datlich.tinhtrang, 50);
	time_t now = time(nullptr);
	tm* localTime = localtime(&now);
}