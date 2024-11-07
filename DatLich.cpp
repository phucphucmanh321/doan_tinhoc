#include "Header.h"

void initLich(NodePtrLich &lich) {
	lich = NULL;
} 
NodePtrLich taonodeLich(DatLich data) {
	NodePtrLich lich = new NODE_L;
	lich->datLich = data;
	lich->link = NULL;
	return lich;
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
	NodePtrLich p	= taonodeLich(lich_kh->datLich);
	if (ds == NULL)
	{
		ds = p;
		return;
	}
	if (ds->link == NULL)
	{
		ds->link = p;
		return;
	}
	else {
		NodePtrLich temp = ds;
		while (temp->link != NULL)
			temp = temp->link;
		temp->link = p;
	}
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
void Dat(NodePtrLich &Lich,Nodeptr kh) {
	NodePtrLich p = new NODE_L;
	p->link = NULL;
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
	InsertdatLich(Lich, p);
	luuLich("Lich.bin", Lich);
}
void hienThiThongTinDatLich(NodePtrLich kh) {
	int count = 0;
	NodePtrLich p = kh;
	while(p!=NULL)
	{
		cout << "\nSTT:" << count++;
		float thoigiandukien = 0;
		cout << "\nMa khach hang: " << p->datLich.maKH;
		cout << "\nCa da chon: " << p->datLich.ca;
		cout << "\nTinh trang: " << p->datLich.tinhTrang;
		cout << "\nTen xe: " << p->datLich.tenXe;
		cout << "\nDoi xe: " << p->datLich.doiXe;
		cout << "\nNgay dat: " << p->datLich.ngayDat.Ngay << "/"
			<< p->datLich.ngayDat.Thang << "/" << p->datLich.ngayDat.Nam;
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
		switch (p->datLich.trangThai)
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
		p = p->link;
	}
}

//Save-Open file
void luuLich(const char* filename, NodePtrLich lich) {
	ofstream ofs(filename, ios::binary);
	if (!ofs.is_open()) {
		cout << "\nKhong the ghi file!";
		return;
	}
	int count = 0;
	NodePtrLich p = lich;
	NodePtrLich temp = p;
	while (temp != NULL) {
		if (temp != NULL)
			count++;
		temp = temp->link;
	}
	ofs.write((char*)&count, sizeof(count));
	while (p != NULL) {
		ofs.write((char*)&p->datLich, sizeof(DatLich));
		p = p->link;
	}
	cout << "\nDa luu vao he thong !";
	ofs.close();
	cout << "\nGhi thanh cong!! ";
	system("pause");
}
void OpenLich(const char* filename, NodePtrLich &lich) {
	ifstream ifs(filename, ios::binary);
	if (!ifs.is_open()) {
		cout << "\nKhong doc duoc file!";
		return;
	}
	int count = 0;
	ifs.read((char*)&count, sizeof(count));
	for (int j = 0; j < count; j++) {
		DatLich lichKH;
		ifs.read((char*)&lichKH, sizeof(DatLich));
		NodePtrLich temp = new NODE_L;
		temp->datLich = lichKH;
		temp->link = NULL;
		InsertdatLich(lich, temp);
	}
	cout << "\nDoc thanh cong !";
	ifs.close();
}