#include "Header.h"

void initLich(NodePtrLich lich) {
	lich = NULL;
}
//void XuLyLichTrinhTrongNgay(NodePtrLich lichCH) {
//	string tinhtrang;
//	if()
//	cout << setw(10) << left << "Ca"<< setw(10) << left << "Tinh trang";
//	for (int i = 1; i <= 4; i++) {
//		cout << setw(10) << left << "\t" << i;
//		cout << setw(10) << left << "\t" << i;
//	}
//}
void InsertdatLich(NodePtrLich& ds, NodePtrLich lich_kh) {
	NodePtrLich p = ds;
	if (p == NULL) {
		p = lich_kh;
	}
	while (p->link != NULL)
		p = p->link;
	p->link = lich_kh;
}
DAY getCurrentDate() {
	// Lấy thời gian hiện tại
	time_t now = time(0);
	struct tm ltm;
	localtime_s(&ltm, &now);

	// Lưu vào cấu trúc DAY
	DAY currentDate;
	currentDate.Gio = ltm.tm_hour + 1;
	currentDate.Ngay = ltm.tm_mday;
	currentDate.Thang = ltm.tm_mon + 1;
	currentDate.Nam = ltm.tm_year + 1900;

	return currentDate;
}
int chiphivanchuyen(int kc) {
	if (kc < 5)
		return 0;
	else {
		int kc_thua = kc - 5;
		int giatien = (kc / 5) * 70000;
		if (kc % 5 > 0)
			giatien += 70000;
		return giatien;
	}
}
void Dat(Nodeptr kh) {
	NodePtrLich p = new NODE_L;
	//XuLyLichTrinhTrongNgay(ds);
	strcpy_s(p->datLich.maKH,kh->KH.maKH);
	cout << "\nChon ca: ";
	cin >> p->datLich.ca;
	cout << "\nNhap loai xe 1=Tay ga, 2=Xe so: ";
	int input;
	cin >> input;
	p->datLich.loaiXe = static_cast<loaixe>(input);
	cout << "\nNhap ten xe: ";
	cin.ignore();
	cin.getline(p->datLich.tenXe, 50);
	cout << "\nNhap doi xe: ";
	cin >> p->datLich.doiXe;
	cout << "\nMo ta tinh trang: ";
	cin.ignore();
	cin.getline(p->datLich.tinhTrang, 50);
	p->datLich.ngayDat = getCurrentDate();
	p->datLich.trangThai = Dangxuly;

	cout << "\nChon dich vu van chuyen xe tan noi? (Y/N)";
	char choose;
	cin >> choose;
	if (choose == 'y' || choose == 'Y')
	{
		int kc;
		cout << "\nNhap khoang cach (km): ";
		cin >> kc;
		cout<<"\nChi phi van chuyen la: "<<chiphivanchuyen(kc);
		cout << "\nDong y/Huy bo(y/n)";
		cin >> choose;
		if (choose == 'y' || choose == 'Y')
		{
			p->datLich.khoangcach = kc;
			p->datLich.dichVuVanChuyen = CHVanchuyen;
		}
	}
	else
		p->datLich.dichVuVanChuyen = KhachVanchuyen;
	hienThiThongTinDatLich(p);
}
void hienThiThongTinDatLich(NodePtrLich p) {
	float thoigiandukien=0;
	cout << "\nMa khach hang: " << p->datLich.maKH;
	cout << "\nCa da chon: " << p->datLich.ca;
	cout << "\nTinh trang: " << p->datLich.tinhTrang;
	cout << "\nTen xe: " << p->datLich.tenXe;
	cout << "\nDoi xe: " << p->datLich.doiXe;
	cout << "\nNgay dat: " << p->datLich.ngayDat.Ngay<<"/"
		<<p->datLich.ngayDat.Thang<<"/"<< p->datLich.ngayDat.Nam;
	cout << "\nDich vu van chuyen: ";
	switch (p->datLich.dichVuVanChuyen) {
	case CHVanchuyen:
		cout << "\nCua hang van chuyen.";
		break;
	default:
		cout << "\nLoi bien dich";
		break;
	}
	if (p->datLich.dichVuVanChuyen == CHVanchuyen)
	{
		cout << "\nKhoang cach van chuyen: " << p->datLich.khoangcach;
		cout << "\nChi phi van chuyen: " << chiphivanchuyen(p->datLich.khoangcach);
	}
	cout << "\nThoi gian du kien:" << thoigiandukien;
	cout << "\nTrang thai: ";
	switch(p->datLich.trangThai)
	{
	case Dangxuly:
			cout << "He thong dang xu ly";
			break;
		case Hoanthanh:
			cout << "Da xu ly xong !";
			break;
		default:
			cout << "Loi";
			break;
	}
}