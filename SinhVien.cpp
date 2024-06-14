#include <iostream>
#include <string>
#include  <iomanip>


using namespace std;

struct SinhVien
{
	string name, id;
	double gpa;
};

struct SV {
	SinhVien data;
	SV* next;
};

typedef struct SV* sv;

// cấp phát động cho node với kiểu dữ liệu là 1 số nguyên x
sv makeNode() {
	SinhVien data;
	cout << "Nhap thong tin sinh vien:\n";
	cout << "Nhap ID: "; cin >> data.id;
	cout << "Nhap ten: "; cin.ignore();
	getline(cin, data.name);
	cout << "Nhap GPA: "; cin >> data.gpa;
	sv tmp = new SV();
	tmp->data = data;
	tmp->next = NULL;
	return tmp;
}

//kiểm tra rỗng
bool rong(sv a) {
	return a == NULL;
}


//Đếm
int dem(sv a) {
	int cnt = 0;
	while (a != NULL) {
		++cnt;
		a = a->next; // gán địa chỉ node tiếp theo cho node hiện tại
	}
	return cnt;
}

//thêm vào đầu
void themdau(sv& a) {
	sv tmp = makeNode();
	if (a == NULL) {
		a = tmp;
	}
	else {
		tmp->next = a;
		a = tmp;
	}
}


//thêm vào cuối
void themcuoi(sv& a) {
	sv tmp = makeNode();
	if (a == NULL) {
		a = tmp;
	}
	else {
		sv p = a;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = tmp;
	}
}


//thêm vào bất kì đâu
void thembatki(sv& a, int pos) {
	int n = dem(a);
	if (pos <= 0 || pos > n + 1) {
		cout << "Vi tri them khong hop le!";
	}
	if (pos == 1) {
		themdau(a); return;
	}
	else if (pos == n + 1) {
		themcuoi(a); return;
	}
	sv p = a;
	for (int i = 1; i < pos - 1; i++) {
		p = p->next;
	}
	sv tmp = makeNode();
	tmp->next = p->next;
	p->next = tmp;
}

//xóa phần tử đầu
void xoadau(sv& a) {
	if (a == NULL) return;
	a = a->next;
}

void xoacuoi(sv& a) {
	if (a == NULL) return;
	sv truoc = NULL, sau = a;
	while (sau->next != NULL) {
		truoc = sau;
		sau = sau->next;
	}
	if (truoc == NULL) {
		a = NULL;
	}
	else {
		truoc->next = NULL;
	}
}

//xóa bất kì
void xoabatki(sv& a, int pos) {
	if (pos <= 0 || pos > dem(a)) return;
	sv truoc = NULL, sau = a;
	for (int i = 1; i < pos; i++) {
		truoc = sau;
		sau = sau->next;
	}
	if (truoc == NULL) {
		a = a->next;
	}
	else {
		truoc->next = sau->next;
	}
}


//sắp xếp
void sapxep(sv& a) {
	for (sv p = a; p->next != NULL; p = p->next) {
		sv min = p;
		for (sv q = p->next; q != NULL; q = q->next) {
			if (q->data.gpa < min->data.gpa) {
				min = q;	
			}
		}
		SinhVien tmp = min->data;
		min->data = p->data;
		p->data = tmp;
	}
}


void in(SinhVien data) {
	cout << "----------------------------------------------------\n";
	cout << "ID: " << data.id << endl;
	cout << "Ten: " << data.name << endl;
	cout << "Diem GPA: " << fixed << setprecision(2) << data.gpa << endl;
	cout << "----------------------------------------------------\n";
}
	
//in ra danh sach
void inds(sv a) {
	cout << "Danh sach sinh vien: \n";
	while (a != NULL) {
		in(a->data);
		a = a->next;
	}
	cout << endl;
}


//tìm kiếm theo tên
void timkiemTen(sv a, string x) {
	sv p = a;
	while (p != NULL) {
		if (p->data.name == x) {
			in(a->data);
			return;
		}
		p = p->next;
	}
	printf("Khong co trong danh sach\n");
}

int main(){
	sv head = NULL;
	while (1) {
		cout << "-----------------MENU---------------\n";
		cout << "1. Chen sinh vien vao dau danh sach\n";
		cout << "2. Chen sinh vien vao cuoi danh sach\n";
		cout << "3. Chen sinh vien vao bat ki dau trong danh sach\n";
		cout << "4. Xoa sinh vien o dau\n";
		cout << "5. Xoa sinh vien o cuoi\n";
		cout << "6. Xoa sinh vien o bat ki dau\n";
		cout << "7. Duyet danh sach sinh vien\n";
		cout << "8. Sap xep cac sinh vien trong dslk\n";
		cout << "9. Tim kiem cac sinh vien trong dslk\n";
		cout << "0. Thoat !\n";
		cout << "-------------------------------------\n";
		cout << "Nhap lua chon :";
		int lc; cin >> lc;
		if (lc == 1) {
			themdau(head);
		}
		else if (lc == 2) {
			themcuoi(head);
		}
		else if (lc == 3) {
			int pos; cout << "Nhap vi tri can them: "; cin >> pos;
			thembatki(head, pos);
		}
		else if (lc == 4) {
			xoadau(head);
		}
		else if (lc == 5) {
			xoacuoi(head);
		}
		else if (lc == 6) {
			int pos; cout << "Nhap vi tri can xoa: "; cin >> pos;
			xoabatki(head, pos);
		}
		else if (lc == 7) {
			inds(head);
		}
		else if (lc == 8) {
			sapxep(head);
		}
		else if (lc == 9) {
			string x;
			cout << "Nhap ten can tim: "; cin.ignore();
			getline(cin, x);
			timkiemTen(head, x);
		}
		else if (lc == 0) {
			break;
		}
	}
}