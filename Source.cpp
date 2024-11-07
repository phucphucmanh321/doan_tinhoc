#include "Header.h"

// Helper Functions
int hash_funct(const char* data) {
    return data[9] - '0';
}

bool CheckPhoneNum(const char a[]) {
    for (int i = 0; i < 10; i++)
        if (!isdigit(a[i]))
            return false;
    return true;
}

// Hash Table Utilities
void initializeHashTable(HashTable& ds) {
    for (int i = 0; i < MAX; i++)
        ds.HashTable[i] = NULL;
}

bool CheckPhoneNumExist(HashTable ds, const char sdt[]) {
    int index = hash_funct(sdt);
    Nodeptr p = ds.HashTable[index];
    while (p != NULL) {
        if (strcmp(p->KH.maKH, sdt) == 0)
            return true;
        p = p->link;
    }
    return false;
}

bool insert(HashTable& table, Nodeptr kh) {
    int index = hash_funct(kh->KH.maKH);
    Nodeptr p = table.HashTable[index];
    if (p == NULL) {
        table.HashTable[index] = kh;
        return true;
    }
    while (p->link != NULL)
        p = p->link;
    p->link = kh;
    return true;
}

Nodeptr find(HashTable table, Nodeptr p) {
    int index = hash_funct(p->KH.maKH);
    Nodeptr p1 = table.HashTable[index];
    while (p1 != NULL) {
        if (!strcmp(p1->KH.maKH, p->KH.maKH) && !strcmp(p1->KH.matkhau, p->KH.matkhau)) {
            p1->link = NULL;
            return p1;
        }
        p1 = p1->link;
    }
    return NULL;
}

bool xoa(HashTable& ds) {
    char sdt[11];
    cout << "\nNhap sdt can xoa: ";
    cin >> sdt;
    if (!CheckPhoneNum(sdt)) {
        cout << "\nNhap sai so dien thoai, vui long nhap lai !";
        return xoa(ds); // gọi đệ quy nếu nhập sai
    }
    int index = hash_funct(sdt);
    Nodeptr& head = ds.HashTable[index];
    Nodeptr p = head;
    Nodeptr prev = NULL;

    if (p == NULL) {
        cout << "\nKhong tim thay sdt trong danh sach.";
        return false;
    }

    if (strcmp(p->KH.maKH, sdt) == 0) {
        head = p->link;
        delete p;
        cout << "\nXoa thanh cong !!";
        return true;
    }

    while (p->link != NULL) {
        if (strcmp(p->link->KH.maKH, sdt) == 0) {
            Nodeptr temp = p->link;
            p->link = p->link->link;
            delete temp;
            cout << "\nXoa thanh cong !!";
            return true;
        }
        p = p->link;
    }

    cout << "\nKhong tim thay sdt trong danh sach.";
    return false;
}

// User Management
void Dangki(HashTable& ds) {
    Nodeptr kh = new NODE;
    kh->link = NULL;
    cout << "So dien thoai: ";
    cin >> kh->KH.maKH;
    while (!CheckPhoneNum(kh->KH.maKH)) {
        system("cls");
        cout << "Nhap lai so dien thoai 10 so: ";
        cin >> kh->KH.maKH;
    }
    if (CheckPhoneNumExist(ds, kh->KH.maKH)) {
        cout << "\nSDT da ton tai !!!";
        system("pause");
        return; // tránh việc gọi StartView ở đây
    }
    cin.ignore();
    cout << "Nhap ho ten: ";
    cin.getline(kh->KH.tenkh, 50);
    cout << "Mat khau: ";
    cin >> kh->KH.matkhau;
    kh->KH.quyen = guess;
    if (insert(ds, kh)) {
        ghiStructVaoFile("file1.bin", ds);
        docStructTuFile("file1.bin", ds);
    }
}

// File Handling
void ghiStructVaoFile(const char* filename, HashTable ds) {
    ofstream ofs(filename, ios::binary);
    if (!ofs.is_open()) {
        cout << "\nKhong the ghi file!";
        return;
    }
    for (int i = 0; i < MAX; i++) {
        int count = 0;
        Nodeptr p = ds.HashTable[i];
        Nodeptr temp = p;
        while (temp != NULL) {
            count++;
            temp = temp->link;
        }
        ofs.write((char*)&count, sizeof(count));
        while (p != NULL) {
            ofs.write((char*)&p->KH, sizeof(Khachhang));
            p = p->link;
        }
    }
    ofs.close();
    cout << "\nGhi thanh cong!! ";
    system("pause");
}

void docStructTuFile(const char* filename, HashTable& ds) {
    ifstream ifs(filename, ios::binary);
    if (!ifs.is_open()) {
        cout << "\nKhong doc duoc file!";
        return;
    }
    for (int i = 0; i < MAX; i++) {
        int count = 0;
        ifs.read((char*)&count, sizeof(count));
        for (int j = 0; j < count; j++) {
            Khachhang kh;
            ifs.read((char*)&kh, sizeof(Khachhang));
            Nodeptr p = new NODE;
            p->KH = kh;
            p->link = NULL;
            insert(ds, p);
        }
    }
    ifs.close();
}

// Display Functions
void ViewInfo(Nodeptr p) {
    cout << "\nSDT: " << p->KH.maKH;
    cout << "\nHo ten khach hang: " << p->KH.tenkh;
    cout << "\nMat khau: " << p->KH.matkhau;
    system("pause");
}

void Xuat(HashTable ds) {
    cout << "\nDanh sach khach hang: "<<endl;
    cout << setw(20) << left << "SDT" << "|\t" <<setw(30) << left << "Ho ten KH" << "|\t" << setw(30) << right << "MatKhau" << endl;
    for (int i = 0; i < MAX; i++) {
        Nodeptr p = ds.HashTable[i];
        while (p != NULL) {
            cout << setw(20)<< left << p->KH.maKH  ;
            cout <<"|\t"<< setw(30) << left << p->KH.tenkh;
            cout<< "|\t"<<setw(30) << right << p->KH.matkhau;
            p = p->link;
        }
    }
}