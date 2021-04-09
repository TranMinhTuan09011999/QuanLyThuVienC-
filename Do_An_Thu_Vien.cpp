#include<iostream>
#include <windows.h> // Su dung cho ham do hoa
#include <conio.h> // su dung cho lenh bat phim
//#include <stdlib.h>
#include<iomanip>
//#include <map>
#include <ctime> // su dung cho ham lay thoi gian he thong
#include<fstream> // du dung cho do ghi file//
#include<sstream>  // su dung cho ham chuyen doi so thanh string
#include<unistd.h>
#define UP 72 // Gia tri 72 nhan phim len
#define DOWN 80 // Gia tri 80 nhan phim xuong
#define BACKSPACE 8 // Gia tri 8 nhan phim xoa Backspace
#define ENTER 13 // Gia tri 13 nhan phim enter
#define ESC 27 // Gia tri 27 nhan phim ESC
#define RIGHT 77 // Gia tri 77 nhan phim mui ten qua phai
#define LEFT 75  // Gia tri 75 nhan phim mui ten qua trai
#define boxx 75 //Vi tri x bat dau cua box
#define boxy 12 //Vi tri y bat dau cua box
#define boxs 60 //Box size
#define tabx 64// vi tri x bat dau cua table
#define taby 5 // vi tri y bat dau cua table
#define tabs 82 // table box
#define tabw 30 // table hight

#define taxx 5// vi tri x bat dau cua table
#define taxy 15 // vi tri y bat dau cua table
#define taxs 147 // table box
#define taxw 34 // table hight

#define F1 59 // Gia tri 59 nhan phim F1
#define F2 60 // Gia tri 60 nhan phim F2
#define F3 61 // Gia tri 61 nhan phim F3
#define F4 62 // Gia tri 62 nhan phim F4
#define F5 63 // Gia tri 63 nhan phim F5
#define F6 64 //Gia tri 64 nhan phim F6
#define MAX_DAUSACH 1000 // so luong dau sach toi da co the nhan la 1000 
#define MAX_QH 7 // so ngay qua han toi da 7 ngay
using namespace std;
void Menu();
string convertInt(int number) // Ham chuyen so kieu int sang kieu string
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}
void textcolor(int x)//Ham tao mau
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

void gotoxy(int column, int line)// Ham xac dinh toa do
{
  	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

 void resizeConsole(int width, int height)// ham chinh kich thuoc man hinh console
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
 ////////////////////
 void clrscr()
{
    COORD origin = {0, 0};
    unsigned long len;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    unsigned long size;
    void* handle = GetStdHandle(STD_OUTPUT_HANDLE);  
 
   
    GetConsoleScreenBufferInfo(handle, &csbi);
    size = csbi.dwSize.X * csbi.dwSize.Y;  
    FillConsoleOutputCharacter(handle, TEXT(' '), size, origin, &len); 
    FillConsoleOutputAttribute(handle, csbi.wAttributes, size, origin, &len);  
    SetConsoleCursorPosition(handle, origin);
}
 /////////////////////
 void Thu_Vien()
 {
 	gotoxy(67,7); cout<<"***************************    ****           ****    ****            ****";
	gotoxy(67,8); cout<<"***************************    ****           ****    ****            ****";
	gotoxy(67,9); cout<<"            ****               ****           ****    ****            ****";
	gotoxy(67,10); cout<<"            ****               ****           ****    ****            ****";
	gotoxy(67,11); cout<<"            ****               ****           ****    ****            ****";
	gotoxy(67,12); cout<<"            ****               *******************    ****            ****";
	gotoxy(67,13); cout<<"            ****               *******************    ****            ****";
	gotoxy(67,14); cout<<"            ****               ****           ****    ****            ****";
	gotoxy(67,15); cout<<"            ****               ****           ****    ****            ****";
	gotoxy(67,16); cout<<"            ****               ****           ****    ****            ****";
	gotoxy(67,17); cout<<"            ****               ****           ****     ******************" ;
	gotoxy(67,18); cout<<"            ****               ****           ****       **************"   ;
	
	gotoxy(66,21); cout<<"****                   ****   ****   *****************   *******         ****";
	gotoxy(66,22); cout<<" ****                 ****    ****   *****************   ********        ****";
	gotoxy(66,23); cout<<"  ****              ****      ****   ****                **** ****       ****";
	gotoxy(66,24); cout<<"   ****            ****       ****   ****                ****  ****      ****";
	gotoxy(66,25); cout<<"    ****          ****        ****   ****                ****   ****     ****";
	gotoxy(66,26); cout<<"     ****        ****         ****   *****************   ****    ****    ****";
	gotoxy(66,27); cout<<"      ****      ****          ****   *****************   ****     ****   ****";
	gotoxy(66,28); cout<<"       ****    ****           ****   ****                ****      ****  ****";
	gotoxy(66,29); cout<<"        ****  ****            ****   ****                ****       **** ****";
	gotoxy(66,30); cout<<"         ********             ****   ****                ****        ********";
	gotoxy(66,31); cout<<"          ******              ****   *****************   ****         *******";
	gotoxy(66,32); cout<<"           ****               ****   *****************   ****          ******";
 }
 
 void Giao_Dien() // Ve khung giao dien 
{
	gotoxy(3,1);
	for(int i=1; i<52; i++)
	{
		cout<<char(220);
	}
	
	for(int i=2; i<21; i++)
	{
		gotoxy(3,i);
		cout<<char(219);
		gotoxy(53,i);
		cout<<char(219);
	}
	
	gotoxy(4,20);
	for(int i=1; i<50; i++)
	{
		cout<<char(220);
	}
	//////////////
	gotoxy(3,21);
	for(int i=1; i<52; i++)
	{
		cout<<char(220);
	}
	
	for(int i=22; i<40; i++)
	{
		gotoxy(3,i);
		cout<<char(219);
		gotoxy(53,i);
		cout<<char(219);
	}
	
	gotoxy(4,39);
	for(int i=1; i<50; i++)
	{
		cout<<char(220);
	}
	////////////////////
	gotoxy(56,1);
	for(int i=1; i<100; i++)
	{
		cout<<char(220);
	}
	
	for(int i=2; i<40; i++)
	{
		gotoxy(56,i);
		cout<<char(219);
		gotoxy(154,i);
		cout<<char(219);
	}
	
	
	gotoxy(57,39);
	for(int i=1; i<98; i++)
	{
		cout<<char(220);
	}
	///////////////////
	gotoxy(1,0);
	for(int i=1; i<157; i++)
	{
		cout<<char(220);
	}
	for(int i=1; i<41; i++)
	{
		gotoxy(1,i);
		cout<<char(219);
		gotoxy(156,i);
		cout<<char(219);
	}
	gotoxy(2,40);
	for(int i=1; i<155; i++)
	{
		cout<<char(220);
	}
	gotoxy(24,23);
	cout<<"CHU THICH";
	gotoxy(20,24);
	cout<<"-----------------";
}
 ////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //**********************************  Khai Bao Danh Muc Sach   *******************************
 struct DanhMucSach 
{
	string maSach;
	int ttSach;
	int vitri;
};
struct DMSNode
{
	DanhMucSach data;
	DMSNode *pNext;
};
struct ListDMS
{
	DMSNode *pHead;
	DMSNode *pTail;
};
typedef struct ListDMS LDMS;
// ---------- Khoi tao ---------
void KhoitaoLDMS(LDMS &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

DMSNode* CreateDMS(DanhMucSach x)
{
	DMSNode *p = new DMSNode;
	if (p == NULL)
	{
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}
void AddTailDMS(LDMS &l, DMSNode *p)
{
	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = l.pHead;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}

void Xoa_DMS( LDMS &l, string a)
{
	if(l.pHead == NULL)
	{
		return;
	}
	else if(l.pHead->data.maSach == a)
	{
		DMSNode *p = l.pHead;
		l.pHead= l.pHead->pNext;
		delete p;
	}
	else
	{
		DMSNode *h = new DMSNode;
		for(DMSNode *k=l.pHead; k!=NULL; k= k->pNext)
		{
			if(k->data.maSach == a)
			{
				DMSNode *t = k;
				DMSNode *g = k->pNext;
				h->pNext=g;
				k=h;
				delete t;
			}
			h = k;
		}	
	}
}

int TimKiem_DMS(LDMS l, string a)
{
	for(DMSNode *k = l.pHead; k!=NULL; k = k->pNext)
	{
		if(k->data.maSach == a)
		{
			return 1;
		}
	}
	return 0;
}
 //*********************************   Khai Bao Dau Sach   ********************************
 struct dausach
{
	string tenSach;
	string ISBN;
	string tacGia;
	string theLoaiSach;
	string soTrang;
	string namSB;
	int solanmuon; // so lan sach duoc muon
	int n; // so luong sach trong dms
	LDMS sach;
};
typedef struct dausach DAUSACH;

struct ListDauSach
{
	int n;
	DAUSACH *DS[MAX_DAUSACH];
};
typedef struct ListDauSach LDS;

void KhoitaoDS(LDS &l)
{
	l.n = 0;
}

void themDS(LDS &l, DAUSACH *&data)
{
	if (l.n > MAX_DAUSACH)
	{
		return;
	}
	l.DS[l.n] = data;
	//l.n++;
}

void XoaDS(LDS &l, int x)
{
	for(int i=0; i<l.n; i++)
	{
		if(i == x)
		{
			for(int j= i; j < l.n-1; j++)
			{
				l.DS[j] = l.DS[j+1];
			}
			l.n--;
			break;
		}
	}
}

int TimKiemDS(LDS l, string a)
{
	for(int i=0; i<l.n ;i++)
	{
		if( l.DS[i]->ISBN == a)
			return i;
	}
	return -1;
}

int TimKiemTenSach(LDS l, string a)
{
	for(int i=0; i<l.n ;i++)
	{
		if( l.DS[i]->tenSach == a)
			return i;
	}
	return -1;
}

int DuyetDMS(LDMS l)
{
	int dem = 0;
	for (DMSNode *p = l.pHead; p != NULL; p = p->pNext)
	{
			dem++;
	}
	return dem;
}

void GhiFileDS(LDS &l)
{
	ofstream f("DauSach.txt");
	int n = 0;
	for (int i = 0; i < l.n; i++) // dem so luong doc gia
	{
		n++;
	}
	f << n << endl;
	for (int i = 0; i < n; i++)  // Ghi du lieu tung do gia vao file
	{
		f << l.DS[i]->ISBN << endl;
		f << l.DS[i]->tenSach << endl;
		f << l.DS[i]->tacGia << endl;
		f << l.DS[i]->theLoaiSach << endl;
		f << l.DS[i]->soTrang << endl;
		f << l.DS[i]->namSB << endl;
		f << l.DS[i]->solanmuon <<endl;
		f << l.DS[i]->n << endl;
		for(DMSNode *p = l.DS[i]->sach.pHead; p !=NULL; p=p->pNext)
		{
			f << p->data.maSach << endl;
			f << p->data.ttSach << endl;
			f << p->data.vitri << endl;
		}
	}
	f.close();
}

// --------- Load File ---------
void LoadFileDS(LDS &l)
{
	DanhMucSach s;
	int soluongds;
	ifstream fi;
	fi.open("DauSach.txt");
	fi >> soluongds; // Dem so luong dau sach
	string temp; // doc xuong dong
	getline(fi,temp);
	for(int j=0; j<soluongds; j++) // Doc du lieu tung doc gia
	{
		DAUSACH *data;
		data = new DAUSACH[MAX_DAUSACH];
		getline(fi, data->ISBN);
		getline(fi, data->tenSach);
		getline(fi, data->tacGia);
		getline(fi, data->theLoaiSach);
		getline(fi, data->soTrang);
		getline(fi, data->namSB);
		fi >> data->solanmuon; getline(fi,temp);
		fi >> data->n; getline(fi,temp);
		themDS(l,data);
		l.n++;
		 KhoitaoLDMS(l.DS[j]->sach);
		for(int i=0; i < data->n; i++)
		{
			getline(fi,s.maSach);
			fi >> s.ttSach; getline(fi,temp);
			fi >> s.vitri; getline(fi,temp);
			AddTailDMS(l.DS[j]->sach,CreateDMS(s));
		}
	}
	fi.close();
}
 
  //**********************************   Khai Bao Muon Tra  **********************************
 struct ngaythang
{
	unsigned int ngay; // ngay co mien gia tri tu 0 den 4294967295
	unsigned int thang;
	unsigned int nam;
};

void LayNgayHT(ngaythang &d)//lay ngay cua he thong.
{
    int ngay,thang,nam,SoNgay ;
    tm *today ;
    time_t ltime;
    time( &ltime );
    today = localtime( &ltime );
    d.ngay=today->tm_mday;
    d.thang=today->tm_mon+1;
    d.nam=today->tm_year+1900;
}

int songaymuon(ngaythang &nt1, ngaythang &nt2)
{
    unsigned int count1=0,count2=0,count;
    unsigned int i,j,k;
    for(i=(nt1.nam);i<=(nt2.nam);i++)
    {
        for(j=1;j<=12;j++)
        {
            for(k=1;k<=30;k++)
            {
                count1++;
                if(k==(nt2.ngay) && j==(nt2.thang) &&  i==(nt2.nam))
                    break;
            }
            if(k==(nt2.ngay) && j==(nt2.thang) &&  i==(nt2.nam))
                    break;
        }
        if(k==(nt2.ngay) && j==(nt2.thang) &&  i==(nt2.nam))
                    break;
    }
        for(i=1;i<=nt1.thang;i++)
        {
            for(j=1;j<=30;j++)
            {
            count2++;
            if(j==nt1.ngay && i==nt1.thang)
                break;
            }
            if(j==nt1.ngay && i==nt1.thang)
                break;
        }
    count = count1 - count2;
    return count;
}

struct Muontra
{
	string MASACH;
	ngaythang ngaymuon;
	ngaythang ngaytra;
	int trangthai;
};

struct NodeMuonTra
{
	Muontra data;
	struct NodeMuonTra *pLeft;
	struct NodeMuonTra *pRight;
};

struct ListMT
{
	NodeMuonTra *pHead;
	NodeMuonTra *pTail;
};
typedef struct ListMT LMT;


void KhoiTaoMT(LMT &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

NodeMuonTra *CreateNodeMT(Muontra x)
{
	NodeMuonTra *p = new NodeMuonTra;
	if (p == NULL)
	{
		return NULL;
	}
	p->data = x;
	p->pLeft = NULL;
	p->pRight = NULL;
	return p;
}

void AddTailMT(LMT &l,NodeMuonTra *p)
{
	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = p;
	}
	else
	{
		p->pLeft = l.pTail;
		l.pTail->pRight=p;
		l.pTail = p;
	}
}

void XOAMT(LMT &l, string n)
{
	NodeMuonTra *p = l.pHead;
	NodeMuonTra *truoc = NULL;
	while (p != NULL)
	{
		if (p->data.MASACH == n)
		{
			if (truoc == NULL)
			{
				l.pHead = l.pHead->pRight;
				l.pHead->pLeft = NULL;
				delete p;
			}
			else if (p == l.pTail)
			{
				l.pTail = truoc;
				truoc->pRight = NULL;
				delete p;
			}
			else
			{
				NodeMuonTra *g = p->pRight;
				truoc->pRight = g;
				g->pLeft = truoc;
				delete p;

			}
		}
		truoc = p;
		p = p->pRight;

	}
} 

NodeMuonTra *TimKiemMT(LMT l,string x)
{
	for(NodeMuonTra *p = l.pHead; p!=NULL; p=p->pRight)
	{
		if(p->data.MASACH == x)
			return p;
	}
	return 0;
}
 //**********************************   Khai Bao Doc Gia   *********************************
 struct DocGia
{
	int MADG;
	string ho;
	string ten;
	string gioitinh;
	int trangthaithe;
	int sosachmuon;
};
struct NodeDG
{
	DocGia DG;
	NodeDG *pLeft;
	NodeDG *pRight;
	LMT MT;
};
typedef NodeDG *Tree;


//---------- Khoi tao ------------

void KhoitaoDSDG(Tree &l)
{
	l = NULL;
}

int AddDSDG(Tree &k, DocGia x)
{
	if (k == NULL) {
		k = new NodeDG;
		k->DG = x;
		k->pLeft = NULL;
		k->pRight = NULL;
	}
	else if (k->DG.MADG > x.MADG)  AddDSDG(k->pLeft, x);
	else if (k->DG.MADG < x.MADG)  AddDSDG(k->pRight, x);
	else if (k->DG.MADG == x.MADG)
	{
		return 0;
	}
}

Tree timDG(Tree p, int x)
{
	while (p != NULL)
	{
		if (x < p->DG.MADG)
			p = p->pLeft;
		else if (p->DG.MADG == x)
			return p;
		else
			p = p->pRight;
	}
	return 0;
}

int delKey(Tree &T, int x)     // xoa nut co key x
{
    if (T==NULL) return 0;
    else if (T->DG.MADG > x) return delKey(T->pLeft, x);
    else if (T->DG.MADG < x) return delKey(T->pRight, x);
    else 
    {
        NodeDG *P = T;
        if (T->pLeft == NULL) T = T->pRight;    // Node chi co cay con phai
        else if (T->pRight == NULL) T = T->pLeft;   // Node chi co cay con trai
        else // Node co ca 2 con
        {
            NodeDG *S = T, *Q = S->pLeft;
            // S la cha cua Q, Q la Node phai nhat cua cay con trai cua P
            while (Q->pRight != NULL)
            {
                S = Q;
                Q = Q->pRight;
            }
            P->DG.MADG = Q->DG.MADG;
            S->pRight = Q->pLeft;
            delete Q;
        }
    }
    return 1;
}

int SoluongDG(Tree l)
{
	int n = 0;
	const int STACKSIZE = 100;
	Tree Stack[STACKSIZE];
	int sp = -1;
	do
	{
		while (l != NULL)
		{
			Stack[++sp] = l;
			l = l->pLeft;
		}
		if (sp != -1)
		{
			l = Stack[sp--];
			n++;
			l = l->pRight;
		}
		else break;
	} while (1);
	return n;
}

void Duyet_NLR(Tree t, Tree *&a, int &sp)
{
	if (t != NULL)
	{
		a[++sp] = t;
		Duyet_NLR(t->pLeft, a, sp);
		Duyet_NLR(t->pRight, a, sp);
	}
}

void Ghi(Tree &t, ofstream &f)
{
	if(t != NULL)
		{
			f << t->DG.MADG << endl;
			f << t->DG.ho << endl;
			f << t->DG.ten << endl;
			f << t->DG.gioitinh << endl;
			f << t->DG.trangthaithe << endl;
			f << t->DG.sosachmuon << endl;
			if(t->DG.sosachmuon > 0)
			{
				for(NodeMuonTra *p = t->MT.pHead; p!=NULL; p=p->pRight)
				{
					f << p->data.MASACH << endl;
					f << p->data.trangthai << endl;
					f << p->data.ngaymuon.ngay << endl;
					f << p->data.ngaymuon.thang << endl;
					f << p->data.ngaymuon.nam << endl;
					f << p->data.ngaytra.ngay << endl;
					f << p->data.ngaytra.thang << endl;
					f << p->data.ngaytra.nam << endl;	
				}
			}
			Ghi(t->pLeft,f);
			Ghi(t->pRight,f);
		}
}

void GhiFileDG(Tree &l)
{
	ofstream f("DocGia.txt");
	int n;
	n = SoluongDG(l);
	f << n << endl;
	Ghi(l, f);
}

void LoadtuFile_DSDG(Tree &l)
{
	ifstream f("DocGia.txt");
	Muontra t;
	DocGia s;
	int n = 0;
	f >> n;
	for (int j = 0; j < n; j++)
	{
			f >> s.MADG;
			f >> s.ho;
			f >> s.ten;
			f >> s.gioitinh;
			f >> s.trangthaithe;
			f >> s.sosachmuon;
			AddDSDG(l, s);
			Tree dg = timDG(l,s.MADG);
			KhoiTaoMT(dg->MT);
			for (int i = 0; i < s.sosachmuon; i++)
			{
				f >> t.MASACH; 
				f >> t.trangthai;
				f >> t.ngaymuon.ngay;
				f >> t.ngaymuon.thang;
				f >> t.ngaymuon.nam;
				f >> t.ngaytra.ngay;
				f >> t.ngaytra.thang;
				f >> t.ngaytra.nam;
				AddTailMT(dg->MT, CreateNodeMT(t));
			}
	}
	f.close();
}
//************************************ Chuc nang phu  *********************************
void Menu_Tam_Thoi(int a)
 {
 	char menu_text[11][100] = { " 1. NHAP DOC GIA ", " 2. IN DANH SACH DOC GIA ", " 3. NHAP DAU SACH ", " 4. SACH ", " 5. THONG TIN SACH ", " 6. MUON SACH ", " 7. TRA SACH " , " 8. THANH LY SACH", " 9. DANH SACH DOC GIA DANG MUON " , " 10. DANH SACH QUA HAN " ," 11. 10 SACH MUON NHIEU NHAT " };
    gotoxy(5, 3); cout <<     "             MENU QUAN LY THU VIEN "; 
    gotoxy(5,4); cout<<"          ---------------------------";
    for(int i=6; i<17; i++)
    {
    	textcolor(15);
    	if(i-5 == a)
    	{
    		textcolor(159);// nen mau xanh
    		gotoxy(9, i); cout << menu_text[i-6];
		}
    	gotoxy(9, i); cout << menu_text[i-6];
	}
 }
 
 void Khung_Chuc_Nang()
 {
 	gotoxy(12,26);
	for(int i=1; i<35; i++)
	{
		cout<<char(220);
	}
	
	gotoxy(12,36);
	for(int i=1; i<34; i++)
	{
		cout<<char(220);
	}
	for(int i=27; i<37; i++)
	{
		gotoxy(12,i);
		cout<<char(219);
		gotoxy(45,i);
		cout<<char(219);
	}
	for(int i=1; i<50; i++)
	{
		gotoxy(3+i,37);
		cout<<char(220);
	}
 }
 
  void Chuc_Nang_Phu()
 {
 	gotoxy(5,38);
	cout<<"F1: THEM";
	gotoxy(16,38);
	cout<<"F2: XOA";
	gotoxy(27,38);
	cout<<"F3: SUA";
	gotoxy(37,38);
	cout<<"F4: CHU THICH";
 }
 
 int Check_So(string t) // Ham kiem tra du lieu nhap vao co phai la so
{
	if(t == "")
	{
		return 1;
	}
	for(int i=0; i<t.length(); i++)
	{
		if((t[i] >= 'a' && t[i] <= 'z') || t[i] >= 'A' && t[i] <= 'Z' || t[i] == ' ')//Neu du lieu chua chu thi bi loi
			return 1;
	}
	return 0;
}


int Check_So_Trang_Thai(string t) // Ham kiem tra du lieu nhap vao co hop le voi yeu cau cua trang thai
{
	for(int i=0; i<t.length(); i++)
	{
		if((t[i] >= 'a' && t[i] <= 'z') || t[i] >= 'A' && t[i] <= 'Z' || t[i] == ' ' || t[i]>'1') // trang thai chi duoc 0 hoac 1
			return 1;
	}
	return 0;
}

int Check_chu(string t)
{
	if(t.length() != 0) 
	{
			for(short i = 0; i < t.length(); i++)
			{
				if(t[i] < 'A' || (t[i] <  'a' && t[i] >  'Z') || t[i] >'z' ) 
					return 1;
			}	
	}				
	return 0;
}

int Check_chu_tac_gia(string t)
{
	if(t.length() != 0) 
	{
			for(short i = 0; i < t.length(); i++)
			{
				if(t[i] < ' '|| (t[i] > ' ' && t[i] < 'A' ) || (t[i] <  'a' && t[i] >  'Z') || t[i] >'z' ) 
					return 1;
			}	
	}				
	return 0;
}

string Fix_Tensach(string t)// chuan hoa string
{
	if(t.length() == 1) // chuyen thanh ki tu hoa
	{
		if(t[0] >= 'a' && t[0] <= 'z')
		{
			t[0] -= 32;
		}
	}
	else if(t.length() != 0 && t.length() != 1) {                   // t co ki tu
		while(t[0] == ' ') t.erase(0, 1); //Xoa 1 khoang trang o dau
		while(t[t.length() - 1] == ' ') t.erase(t.length() - 1, 1); //Xoa khoang trang o cuoi
		if(t.length() > 3) //Xoa khoang trang thua o giua , vi 4 ki tu tro len moi tao ra 2khoang trang thua`
			for(short i = 1; i < t.length() - 2; i++)
				if(t[i] == ' ' && t[i+1] == ' ') {
					t.erase(i, 1);  i--;
				}
				for(short i = 0; i < t.length(); i++)
					if(t[i] >= 'A' && t[i] <= 'Z') t[i] += 32; //Chuyen chu hoa thanh chu thuong

				t[0] = t[0] - 32; //Chuyen ki tu dau thanh chu hoa
				for(int i = 1;i < t.length();i++) // In hoa chu cai dau tien sau moi khoang trang
				{
					if(t[i] == ' ')
					{
						if(t[i+1] >= 'a' && t[i+1] <= 'z')
						{
							t[i+1] -= 32;
							i = i+1;
						}
					}
				}
	}
	return t;
}

string Fix_ISBN(string t) 
{
	if(t.length() != 0) 
	{                   // t co ki tu              
		//Chuyen chu thuong thanh chu hoa  
		for(int i = 0; i < t.length(); i++)
			if(t[i] >= 'a' && t[i] <= 'z')
				t[i] -= 32;
	}
	return t;
}

void Print_Textfield(string t, int n, int x) // In du lieu vao man hinh console
 {
	gotoxy(boxx + x, boxy + n);
	if(t.length() >= boxs - x) {
		for(int i = 0; i < boxs - x; i++) cout << t[i];
	}
	else if(t.length() < boxs - x) {
		cout << t;
		for(int i = 0; i < boxs - x - t.length() ; i++) cout << " ";
	}
}

void Print_Error_DG(int k)// Ham bao loi Khi nhap sai du lieu
{
	string s;
	if(k == 1) s = "MA DOC GIA LA BAT BUOC!";
	else if(k == 2) s = "MA DOC GIA DA BI TRUNG!";
	else if(k == 3) s = "MA DOC GIA PHAI LA SO!";
	else if(k == 4) s = "HO DOC GIA LA BAT BUOC!";
	else if(k == 5) s = "HO DOC GIA KHONG VUOT QUA 9 KI TU";
	else if(k == 6) s = "TEN DOC GIA LA BAT BUOC!";
	else if(k == 7) s = "TEN DOC GIA KHONG VUOT QUA 9 KI TU";
	else if(k == 8) s = "PHAI DOC GIA LA BAT BUOC!!";
	else if(k == 9) s = "PHAI DOC GIA KHONG HOP LE!    ";
	else if(k == 10) s = "TRANG THAI THE PHAI LA SO! (0/1)     ";
	else if (k == 11) s = "TRANG THAI THE LA BAT BUOC!    ";
	else if(k == 12) s = "KHONG DUOC NHAP KI TU DAC BIET VA SO";
	gotoxy(boxx + 10 , 24); cout << "CANH BAO: "<< s;
}
 
 int XacNhanSaveFile()
{
		int x = 95, y = 19;
	gotoxy(90, 17);
	textcolor(112);
	cout << "                                ";
	gotoxy(90, 18); cout << "                                ";
	gotoxy(90, 19); cout << "  BAN CO MUON SAVE FILE KHONG?  ";
	gotoxy(90, 20); cout << "                                ";
	gotoxy(90, 21); cout << "     YES                NO      ";
	gotoxy(90, 22); cout << "                                ";
	int keyhit;
	do{
		gotoxy(98, 21);
		textcolor(121);
		switch(x)
		{
		case 95 : gotoxy(95, 21); cout << "YES"; break;
		case 114 : gotoxy(114, 21); cout << "NO"; break;
		}
		keyhit = getch();
		if(keyhit == LEFT)// phim mui ten qua trai
		{
			gotoxy(95, 21);
			textcolor(112);
			switch(x)
			{
			case 95 : gotoxy(95, 21); cout << "YES"; break;
			case 114 : gotoxy(114, 21); cout << "NO"; break;
			}
			x -= 19;
			if(x != 95)
			{
				x = 114;
			}
		}
		else if(keyhit == RIGHT)// phim mui ten qua phai
		{
			gotoxy(95, 21);
			textcolor(112);
			switch(x)
			{
			case 95 : gotoxy(95, 21); cout << "YES"; break;
			case 114 : gotoxy(114, 21); cout << "NO"; break;
			}
			x += 19;
			if(x != 114)
			{
				x = 95;
			}
		}
		else if(x == 95 && keyhit == ENTER)
		{
			textcolor(15);
			gotoxy(97, 24);
			cout << "LUU FILE THANH CONG";
			return 1;
		}
		else if(x == 114 && keyhit == ENTER)
		{
			return 0;
		}
	}while(true);
}

 //***********************************  Nhap Doc Gia   **********************************
 void frameChuThichDocGia(int x, int y)
{
	gotoxy(93, 15);
	textcolor(112);
	gotoxy(x, y - 1); 		cout << "                                ";
	gotoxy(x, y); 			cout << "           TRANG THAI           ";
	gotoxy(x, y + 1); 			cout << "                                ";
	gotoxy(x, y + 2);		cout << "  1: DANG HOAT DONG             ";
	gotoxy(x, y + 3);		cout << "  0: THE BI KHOA                ";
	gotoxy(x, y + 4);		cout << "                                ";
	gotoxy(x, y + 5);		cout << "          ESC: THOAT            ";
}

 void frameChuThichDanhMucSach(int x, int y)
{
	gotoxy(93, 15);
	textcolor(112);
	gotoxy(x, y - 1); 		cout << "           TRANG THAI           ";
	gotoxy(x, y); 			cout << "                                ";
	gotoxy(x, y + 1);		cout << "  0: CHO MUON DUOC              ";
	gotoxy(x, y + 2);		cout << "  1: DA CO DOC GIA MUON         ";
	gotoxy(x, y + 3);		cout << "  2: SACH DA THANH LY           ";
	gotoxy(x, y + 4);		cout << "                                ";
	gotoxy(x, y + 5);		cout << "          ESC: THOAT            ";
}
 
 
int CheckLoi_DG(string &t,int k,Tree l)// kiem tra cac loi nhap du lieu
{
	if(k == 2){
		if(Check_chu(t) == 1) return 12;
	}
	if(k == 3){
		if(Check_chu(t) == 1) return 12;
	}
	if(k == 2) t = Fix_Tensach(t);
	if(k == 3) t = Fix_Tensach(t);
	if(k == 4) t = Fix_Tensach(t);
	string Nam = "Nam";
	string Nu = "Nu";
	if(k == 1)
	{
		if(t == "") return 1;
		if(Check_So(t) != 0) return 3;
		if(timDG(l,atoi((char*)t.c_str())) != NULL) return 2;
		if(t.length() > 5) return 11;
	}
	if(k == 2)
	{
		if(t == "") return 4;
		else if(t.length() > 9) return 5;
	}
	if(k == 3)
	{
		if(t == "") return 6;
		else if(t.length() > 9) return 7;
	}
	if(k == 4)
	{
		if(t == "") return 8;
		if(Nam.compare(t) == 0 || Nu.compare(t) == 0)
		{
		    return 0;	
		}
		else
		{
			return 9;
		}
		if(t.length() > 5) return 9;
	}
	
	if(k == 5)
	{
		if(t == "") return 11;
		if(Check_So_Trang_Thai(t) != 0) return 10;
		//if(t != convertInt(0) || t != convertInt(1)) return 10;
		else if(t.length() > 5) return 10;
	}
	return 0;
}
void MN()
{
	char menu_text1[12][100] = { " 1. THEM DOC GIA", " 2. XOA DOC GIA ", " 3. SUA DOC GIA", " 4. THOAT "};
    gotoxy(15, 28); cout <<     "        MENU CHUC NANG "; 
    gotoxy(15,29); cout<<"    ---------------------";
    textcolor(159);// nen mau xanh
    gotoxy(18, 31); cout << menu_text1[0];
    textcolor(15);
	gotoxy(18, 32); cout << menu_text1[1];
	gotoxy(18, 33); cout << menu_text1[2];
	gotoxy(18, 34); cout << menu_text1[3];
	gotoxy(25,38);
	cout<<"ESC: THOAT";
}
void Box_NhapDG()
{        
	textcolor(15);
	gotoxy(boxx, boxy); cout << char(201);
	for(int i = 1; i < boxs + 1; i++) cout << char(205);
	cout << char(187);
	gotoxy(boxx, boxy + 1); cout << char(186);
	gotoxy(boxx + boxs + 1, boxy + 1); cout << char(186);
	gotoxy(boxx, boxy + 2); cout << char(186)<< "      NHAP MA DG: ";
	gotoxy(boxx + boxs + 1, boxy + 2); cout << char(186);
	gotoxy(boxx, boxy + 3); cout << char(186) ;
	gotoxy(boxx + boxs + 1, boxy + 3); cout << char(186);
	gotoxy(boxx, boxy + 4); cout << char(186)<< "      NHAP HO: ";
	gotoxy(boxx + boxs + 1, boxy + 4); cout << char(186);
	gotoxy(boxx, boxy + 5); cout << char(186);
	gotoxy(boxx + boxs + 1, boxy + 5); cout << char(186);
	gotoxy(boxx, boxy + 6); cout << char(186)<< "      NHAP TEN: ";
	gotoxy(boxx + boxs + 1, boxy + 6); cout << char(186);
	gotoxy(boxx, boxy + 7); cout << char(186);
	gotoxy(boxx + boxs + 1, boxy + 7); cout << char(186);
	gotoxy(boxx, boxy + 8); cout << char(186)<< "      NHAP PHAI: ";
	gotoxy(boxx + boxs + 1, boxy + 8); cout << char(186);
	gotoxy(boxx, boxy + 9); cout << char(186);
	gotoxy(boxx + boxs + 1, boxy + 9); cout << char(186);
	gotoxy(boxx, boxy + 10); cout << char(186)<< "      TRANG THAI THE: ";
	gotoxy(boxx + boxs + 1, boxy + 10); cout << char(186);
	gotoxy(boxx, boxy + 11); cout << char(200);
	for(int i = 1; i < boxs + 1; i++) cout << char(205);
	cout << char(188); 
}

void GhiFileRaDom(int a)// Ghi vao file Radom nhung ma doc gia da su dung, tranh tinh trang trung
{
	ofstream filein; // Khai bao file de mo ghi
	filein.open("Radom.txt", ios::app);// mo file va tiep tuc ghi du lieu vao
	filein<<a<<endl;// ghi vao tung dong
	filein.close(); // dong file lai
}

int LoadFileRaDom(int x) // Load file Radom de kiem tra ma doc gia
{
	int a;
	ifstream fileout("Radom.txt"); // Mo file de doc
	while(fileout.eof() == FALSE) // doc cho den dong cuoi cung
	{
		fileout>>a; // doc du lieu
		if(a == x) // neu ma doc gia da co thi return
		{
			return 1;
		}
		string temp; 
		getline(fileout,temp); // Doc lenh xuong dong
	}
	fileout.close();
	return 0;
}

void Huong_Dan_Nhap_Doc_Gia()
{
	gotoxy(73,28); cout<<"Huong dan:";
	gotoxy(73,29); cout<<"            Vi du: Tran Minh Tuan";
	gotoxy(73,30); cout<<"                      => Ho: Tran ";
	gotoxy(73,31); cout<<"                      => Ten: Tuan ";
	gotoxy(73,32); cout<<"                  Phai: Nam/Nu";
	gotoxy(73,33); cout<<"                  Trang Thai: ";
	gotoxy(73,34); cout<<"                      + 1: The Dang Hoat Dong";
	gotoxy(73,35); cout<<"                      + 0: The Bi Khoa";
}

void NhapDG(Tree &t)
{
	LoadtuFile_DSDG(t);
	Giao_Dien();
	Menu_Tam_Thoi(1);
	Khung_Chuc_Nang();
	MN();
	Huong_Dan_Nhap_Doc_Gia();
	DocGia data;
	Box_NhapDG();
	textcolor(15);                                        
	gotoxy(75,10);cout <<"                         NHAP DOC GIA ";
	int keyhit, x = 24;
	int demkitu;
	string text, field[5];
	field[0] = "";
	field[1] = "";
	field[2] = "";
	field[3] = "";
	field[4] = "";
	int a, b;
	int z = 0;
	while(1)
	{
		a = 1000 + rand() % (9999 + 1 - 1000);// sinh ra so ngau nhien
		b = LoadFileRaDom(a); // Kiem tra xem no co bi trung khong
		if(b == 0)
		{
			break;
		}
	}
	field[0] = convertInt(a); 
	Print_Textfield(convertInt(a), 2, 24); // in du lieu vao ma hinh o toa do tuy chinh
	for(int n = 4, k = 2; k<6; n +=2, k++)// Nhap du lieu theo yeu cau
	{
		keyhit = 0;
		demkitu = field[k-1].length();
		text = field[k-1];
	//	Print_Textfield("1",10,x); // o phan trang thai the qui dinh hoat dong
		while(keyhit != 13)// Nhap du lieu tuong ung bang cach bat phim ki tu, chinh sua du lieu
		{
			gotoxy(boxx + x, boxy +n);
			if(demkitu < boxs - x)
			{
				cout<<text;
				for(int i = 1 ;i < boxs - x - demkitu + 1 ; i++)
				{
					cout<<" ";
				}
			}
			if(demkitu < boxs -x)
			{
				gotoxy(boxx + x + demkitu,boxy + n);
			}
			keyhit = getch();// kiem tra bat phim
			if(keyhit == 224)
			{
				keyhit = getch();
					if(keyhit == UP)// di len
					{	
						gotoxy(76,24); cout<<"                                                           ";
						if(k == 1) text = Fix_ISBN(text);
						if(k == 2) text = Fix_Tensach(text);
						Print_Textfield(text, n, x);
						field[k - 1] = text;
						if(k > 1)
						{
							n -= 2;
							k--;
						}
						demkitu = field[k - 1].length();
						text = field[k -1];
					}
					else if(keyhit == DOWN)// di xuong
					{
						gotoxy(76,24); cout<<"                                                           ";
						if(CheckLoi_DG(text, k, t) != 0)
						{
							keyhit = 0;
							Print_Error_DG(CheckLoi_DG(text, k, t));// in loi ra man hinh
							Print_Textfield(text, n, x);// in du lieu ra man hinh
						}
						else
						{
							if(k == 2) text = Fix_Tensach(text);// chuan hoa text
							Print_Textfield(text, n, x);// in du lieu ra man hinh
							field[k - 1] = text;
							if(k < 5)
							{
								n += 2;
								k++;
							}
							demkitu = field[k - 1].length();// dem chieu dai field
							text = field[k -1];
							
							if(keyhit == DOWN)// di xuong
							{
								gotoxy(76,24); cout<<"                                                           ";
								Print_Textfield(text, n, x);
							}
						}	
					}
			}
			else if(keyhit == BACKSPACE)// xoa ki tu cuoi cung
			{
				gotoxy(76,24); cout<<"                                                           ";
				if(demkitu > 0)
					{
						demkitu--;
						text = text.substr(0, text.size() - 1);
					}
			}
			else if(keyhit == ENTER)// nhan phim enter
			{
				if(CheckLoi_DG(text, k, t) != 0)
					{
						keyhit = 0;
						Print_Error_DG(CheckLoi_DG(text, k, t));// in loi ra man hinh
						Print_Textfield(text, n, x);// in du lieu ra man hinh
					}
					else
					{
						if(k == 1) text = Fix_ISBN(text);// chuan hoa text
						if(k == 2) text = Fix_Tensach(text);// chuan hoa text
					}
			}
			else if(keyhit == ESC)//thoat
			{
				break;
			}
			else
			{
				gotoxy(76,24); cout<<"                                                           ";
				demkitu ++;
				text += char(keyhit);
			}
		}
		if(keyhit == ESC)//thoat
		{
			break;
		}
		Print_Textfield(text, n, x);// in du lieu ra man hinh
		field[k - 1] = text;
	}
	if(keyhit == ENTER)// Xac nhan nhap xong du lieu, kiem tra co muon luu khong
		{
			data.MADG = atoi((char*)field[0].c_str());
			data.ho = field[1];
			data.ten = field[2];
			data.gioitinh = field[3];
			data.trangthaithe = atoi((char*)field[4].c_str());
			data.sosachmuon = 0;
			int z = XacNhanSaveFile();
			if(z == 1)// xac nhan yes
			{
				AddDSDG(t,data);
				GhiFileDG(t);
				GhiFileRaDom(a);
			}
			textcolor(15);
		}
}

void frameDocGia(int x, int y)
{
	gotoxy(93, 15);
	textcolor(112);
	gotoxy(x, y - 1); 		cout << "                           ";
	gotoxy(x, y); 			cout << "    NHAP VAO MA DOC GIA    ";
	gotoxy(x, y + 1);		cout << " ";
	gotoxy(x + 1, y + 1); 	cout << "                         ";
	gotoxy(x + 26, y + 1); 	cout << " ";
	gotoxy(x, y + 2); 		cout << "                           ";
	gotoxy(x, y + 3); 		cout << "                           ";
	textcolor(15);
}

Tree CheckMaDG(Tree t, int &z) // Ham tra ve NodeDocGia tim duoc
{
DocGia:	
	frameDocGia(90, 15);// bang nhap doc gia
	int x = 93, y = 15;
	int keyhit, dem;
	string text, field;
	field = "";// khoi tao rong
	keyhit = 0;
	dem = field.length();
	text = field;
	while(1)// nhap doc gia va kiem tra du lieu
	{
		textcolor(253);
		gotoxy(x + 5, y + 1);
		if(dem < 9)
		{
			cout << text;
			for(int i = 1; i < 11 - dem; i++) cout << " ";
		}
		else
		{
			for(int i = dem - 9; i < dem; i++)
				cout << text[i];
		}
		if(dem < 9) gotoxy(x + 5 + dem, y + 1);
		keyhit = getch();
		if(keyhit == BACKSPACE)// xoa o vi tri cuoi cung
		{
			if(dem > 0)
			{
				dem--;
				text = text.substr(0, text.size() - 1);
			}
		}
		else if(keyhit == ENTER)// nhap phim enter
		{
			if(text == "")// text rong
			{
				textcolor(15);
				keyhit = 0;
				gotoxy(boxx + 15, 18);
				textcolor(112);
				cout << "(VUI LONG NHAP MA DOC GIA!)";
				int c = getch();
				gotoxy(boxx + 15, 18); cout<<"                          ";
				goto DocGia; 
			}
			else
			{
				textcolor(15);
				if(text.length() > 9) // chieu dai text qua 9 ki tu
				{
					gotoxy(boxx + 15, 18);
					textcolor(112);
					cout << "    (MA DOC GIA QUA DAI)  ";
					int c = getch();
					gotoxy(boxx + 15, 18); cout<<"                          ";
					goto DocGia; 
				}
				else
				{
					if(timDG(t, atoi((char*)text.c_str())) == 0)// tim xem trong danh sach sach doc gia co ma doc gia vua nhap hay khong
					{
						gotoxy(boxx +15, 18);
						textcolor(112);					
						cout << "(MA DOC GIA KHONG TON TAI)";
						int c = getch();
						gotoxy(boxx + 15, 18); cout<<"                          ";
						goto DocGia;
					}
					else
					{	
						Sleep(500);
						return timDG(t,atoi((char*)text.c_str()));				
					}
				}
			}
		}
		else if(keyhit == ESC)//thoat
		{
			z++;
			textcolor(15);
			Sleep(500);
			textcolor(15);
			clrscr();
			break;
		}
		else 
		{
			dem++;
			text += toupper((char)keyhit);// them ki tu vao cuoi text

		}
	}
}

int XacNhanXoa()
{
	int x = 93, y = 19;
	gotoxy(88, 14);
	textcolor(112);
	cout << "                                ";
	gotoxy(88, 15); cout << "                                ";
	gotoxy(88, 16); cout << "   BAN CO CHAC CHAN XOA KHONG?  ";
	gotoxy(88, 17); cout << "                                ";
	gotoxy(88, 18); cout << "     YES                NO      ";
	gotoxy(88, 19); cout << "                                ";
	int keyhit;
	do{
		gotoxy(98, 18);
		textcolor(121);
		switch(x)
		{
		case 93 : gotoxy(93, 18); cout << "YES"; break;
		case 112 : gotoxy(112, 18); cout << "NO"; break;
		}
		keyhit = getch();
		if(keyhit == LEFT)// phim mui ten qua trai
		{
			gotoxy(93, 18);
			textcolor(112);
			switch(x)
			{
			case 93 : gotoxy(93, 18); cout << "YES"; break;
			case 112 : gotoxy(112, 18); cout << "NO"; break;
			}
			x -= 19;
			if(x != 93)
			{
				x = 112;
			}
		}
		else if(keyhit == RIGHT)// phim mui ten qua phai
		{
			gotoxy(93, 21);
			textcolor(112);
			switch(x)
			{
			case 93 : gotoxy(93, 18); cout << "YES"; break;
			case 114 : gotoxy(112, 18); cout << "NO"; break;
			}
			x += 19;
			if(x != 112)
			{
				x = 93;
			}
		}
		else if(x == 93 && keyhit == ENTER)
		{
			textcolor(112);
			gotoxy(95, 21);
			cout << "LUU FILE THANH CONG";
			Sleep(500);
			return 1;
		}
		else if(x == 112 && keyhit == ENTER)
		{
			return 0;
		}
	}while(true);
}
void XoaDG(Tree &t) // Ham xoa doc gia theo yeu cau
{
	while(1)
	{	
	DG:
		int z = 0;
		LoadtuFile_DSDG(t);
		Tree dg = CheckMaDG(t,z); // Nhap ma doc gia
		if(z != 0)
		{
			return;
		}
		for(NodeMuonTra *k = dg->MT.pHead; k!=NULL; k = k->pRight) // duyet danh sach muon tra trong doc gia vua nhap
		{
			if(k->data.trangthai == 0) //neu trong danh muon tra con trang thai la khong thi k duoc xoa, phai tra het sach
			{
				gotoxy(boxx + 15, 18);
				textcolor(112);
				cout << "  (DOC GIA CHUA TRA SACH)";
				int keyhit = getch();
				gotoxy(boxx + 15, 18); cout<<"                          ";
				goto DG;
			}
		}
		int qq = XacNhanXoa();
			if(qq == 1)
			{
				if(delKey(t,dg->DG.MADG)==1)// Xoa doc gia
				{
					GhiFileDG(t);
					gotoxy(97, 20);
					cout << "XOA THANH CONG";
					Sleep(500);
					return;
				}
			}
			else
			{
				return;
			}
	}	
}

void Giao_Dien_Tam_Thoi()
{
	gotoxy(12,26);
	for(int i=1; i<35; i++)
	{
		cout<<char(220);
	}
	
	gotoxy(12,36);
	for(int i=1; i<34; i++)
	{
		cout<<char(220);
	}
	for(int i=27; i<37; i++)
	{
		gotoxy(12,i);
		cout<<char(219);
		gotoxy(45,i);
		cout<<char(219);
	}
	for(int i=1; i<50; i++)
	{
		gotoxy(3+i,37);
		cout<<char(220);
	}
	
	char menu_text[12][100] = { " 1. NHAP DOC GIA ", " 2. IN DANH SACH DOC GIA ", " 3. NHAP DAU SACH ", " 4. SACH ", " 5. THONG TIN SACH ", " 6. MUON SACH ", " 7. TRA SACH " , " 8. DANH SACH DOC GIA DANG MUON " , " 9. DANH SACH QUA HAN " ," 10. 10 SACH MUON NHIEU NHAT ", " 11. THOAT" };
    gotoxy(5, 3); cout <<     "             MENU QUAN LY THU VIEN "; 
    gotoxy(5,4); cout<<"          ---------------------------";
    textcolor(159);
    gotoxy(9, 6); cout << menu_text[0];
    textcolor(15);
	gotoxy(9, 7); cout << menu_text[1];
	gotoxy(9, 8); cout << menu_text[2];
	gotoxy(9, 9); cout << menu_text[3];
	gotoxy(9, 10); cout << menu_text[4];
	gotoxy(9, 11); cout << menu_text[5];
	gotoxy(9, 12); cout << menu_text[6];
	gotoxy(9, 13); cout << menu_text[7];
	gotoxy(9, 14); cout << menu_text[8];
	gotoxy(9, 15); cout << menu_text[9];
	gotoxy(9, 16); cout << menu_text[10];
	
	char menu_text1[12][100] = { " 1. THEM DOC GIA", " 2. XOA DOC GIA ", " 3. SUA DOC GIA", " 4. THOAT "};
    gotoxy(15, 28); cout <<     "        MENU CHUC NANG "; 
    gotoxy(15,29); cout<<"    ---------------------";
    textcolor(15);
    gotoxy(18, 31); cout << menu_text1[0];
	gotoxy(18, 32); cout << menu_text1[1];
	textcolor(159);
	gotoxy(18, 33); cout << menu_text1[2];
	textcolor(15);
	gotoxy(18, 34); cout << menu_text1[3];
}

void SuaDG(Tree &t)
{
	int z = 0;
	LoadtuFile_DSDG(t);
	Tree dg = CheckMaDG(t,z);
	if(z != 0)
	{
		return;
	}
	while(1)
	{
		clrscr();
		Giao_Dien();
		Giao_Dien_Tam_Thoi();
		gotoxy(25,38);
		cout<<"ESC: THOAT";
		Box_NhapDG();
		Huong_Dan_Nhap_Doc_Gia();
		textcolor(15);                                        
		gotoxy(73,10);cout <<"                            NHAP DOC GIA    ";
		int keyhit, x = 24;
		int demkitu;
		string text, field[5];// tao mang gom 5 phan tu de nhap du lieu
		field[0] = "";
		field[1] = "";
		field[2] = "";
		field[3] = "";
		field[4] = "";
		
		for(int n = 4, k = 2; k < 6; n += 2, k++)// nhap du lieu
		{
			keyhit = 0;
			demkitu = field[k - 1].length();
			text = field[k - 1];
			Print_Textfield(convertInt(dg->DG.MADG),2,x);// in du lieu ra man hinh
			//Print_Textfield("1",10,x);// in du lieu ra man hinh
			while(keyhit != 13)// nhap phim, dung khi nhan enter
			{
				gotoxy(boxx + x, boxy + n);
				if(demkitu < boxs - x)
				{
					cout << text;
					for(int i = 1; i < boxs - x + 1 - demkitu; i++)
						cout << " ";
				}
				if(demkitu < boxs - x)
					gotoxy(boxx + x + demkitu, boxy + n);
				keyhit = getch();
				if(keyhit == 224)
				{
					keyhit = getch();
					if(keyhit == UP)//di len
					{
						gotoxy(76,24); cout<<"                                                           ";
						if(k == 1) text = Fix_ISBN(text);// chuan hoa text
						if(k == 2) text = Fix_Tensach(text);
						Print_Textfield(text, n, x);//in du lieu ra man hinh
						field[k - 1] = text;
						if(k > 2)
						{
							n -= 2;
							k--;
						}
						demkitu = field[k - 1].length();
						text = field[k -1];
					}
					else if(keyhit == DOWN)// di xuong
					{
						gotoxy(76,24); cout<<"                                                           ";
						if(CheckLoi_DG(text, k, t) != 0)// check loi nhap
						{
							keyhit = 0;
							Print_Error_DG(CheckLoi_DG(text, k, t));// in loi ra man hinh
							Print_Textfield(text, n, x);// in du lieu ra man hinh
						}
						else
						{
							if(k == 1) text = Fix_ISBN(text);// chuan hoa text
							if(k == 2) text = Fix_Tensach(text);//chuan hoa text
							Print_Textfield(text, n, x);// in du lieu ra man hinh
							field[k - 1] = text;
							if(k < 5)
							{
								n += 2;
								k++;
							}
							demkitu = field[k - 1].length();
							text = field[k -1];
							
							if(keyhit == DOWN)// di xuong
							{
								gotoxy(76,24); cout<<"                                                           ";
								Print_Textfield(text, n, x);// in du lieu ra man hinh
							}
						}	
					}
				}
				else if(keyhit == BACKSPACE)// xoa ki tu cuoi cung
				{
					gotoxy(76,24); cout<<"                                                           ";
					if(demkitu > 0)
					{
						demkitu--;
						text = text.substr(0, text.size() - 1);//xoa ki tu
					}
				}
				else if(keyhit == ESC)//thoat
				{
					break;
				}
				else if(keyhit == ENTER)// nhan phim enter
				{
					if(CheckLoi_DG(text, k, t) != 0)// check loi
					{
						keyhit = 0;
						Print_Error_DG(CheckLoi_DG(text, k, t));// in loi ra man hinh
						Print_Textfield(text, n, x);// in du lieu ra man hinh
						Sleep(500);
					}
					else
					{
						if(k == 1) text = Fix_ISBN(text);// chuan hoa text
						if(k == 2) text = Fix_Tensach(text);// chuan hoa text
					}
				}
				else 
				{
					demkitu++;
					text += char(keyhit);// them ki tu vao cuoi text
				}
			}
			if(keyhit == ESC)// thoat
			{
					return;
			}
			Print_Textfield(text, n, x);// in du lieu ra man hinh
			field[k - 1] = text;
		}
		if(keyhit == ENTER)
		{
			textcolor(15);
				Sleep(500);
				int a = XacNhanSaveFile();
				if(a == 1)// xac nhan yes
				{
					dg->DG.MADG = dg->DG.MADG;
			        dg->DG.ho = field[1];
			        dg->DG.ten = field[2];
			        dg->DG.gioitinh = field[3];
			        dg->DG.trangthaithe = atoi((char*)field[4].c_str());;
		        	dg->DG.sosachmuon = dg->DG.sosachmuon;
			        GhiFileDG(t);
					Sleep(500);
					return;
				}
				else 
				{
					return;
				}
		}
	}
}


void Sap_Xep_Ho_Ten(Tree *a, int sp) // Ham sap xep ds theo ho ten
{
	for (int i = 0; i <= sp; i++)
	{
		for (int j = i+1; j <= sp; j++)
		{
			if (a[i]->DG.ten > a[j]->DG.ten)// sap xep theo ten
			{
				Tree tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
			else
			{
				if (a[i]->DG.ten == a[j]->DG.ten)// neu ten trung, sap xep theo ho
				{
					if (a[i]->DG.ho > a[j]->DG.ho)
					{
						Tree tmp = a[i];
	        			a[i] = a[j];
	        			a[j] = tmp;
					}
				}
			}
		}
	}
}

void Xuat(Tree *a, int sp)
{
	for(int i=0; i<=sp; i++)
	{
		cout<<"Ho: "<<a[i]->DG.ho;
		cout<<endl;
		cout<<"Ten: "<<a[i]->DG.ten;
		cout<<endl;
	}
}

void Box_NhapDS()
{        
	textcolor(15);
	gotoxy(boxx, boxy); cout << char(201);
	for(int i = 1; i < boxs + 1; i++) cout << char(205);
	cout << char(187);
	gotoxy(boxx, boxy + 1); cout << char(186);
	gotoxy(boxx + boxs + 1, boxy + 1); cout << char(186);
	gotoxy(boxx, boxy + 2); cout << char(186)<< "	ISBN: ";
	gotoxy(boxx + boxs + 1, boxy + 2); cout << char(186);
	gotoxy(boxx, boxy + 3); cout << char(186) ;
	gotoxy(boxx + boxs + 1, boxy + 3); cout << char(186);
	gotoxy(boxx, boxy + 4); cout << char(186)<< "	Ten Sach: ";
	gotoxy(boxx + boxs + 1, boxy + 4); cout << char(186);
	gotoxy(boxx, boxy + 5); cout << char(186);
	gotoxy(boxx + boxs + 1, boxy + 5); cout << char(186);
	gotoxy(boxx, boxy + 6); cout << char(186)<< "	Tac Gia: ";
	gotoxy(boxx + boxs + 1, boxy + 6); cout << char(186);
	gotoxy(boxx, boxy + 7); cout << char(186) ;
	gotoxy(boxx + boxs + 1, boxy + 7); cout << char(186);
	gotoxy(boxx, boxy + 8); cout << char(186)<< "	The loai: ";
	gotoxy(boxx + boxs + 1, boxy + 8); cout << char(186);
	gotoxy(boxx, boxy + 9); cout << char(186) ;
	gotoxy(boxx + boxs + 1, boxy + 9); cout << char(186);
	gotoxy(boxx, boxy + 10); cout << char(186)<< "	So trang: ";
	gotoxy(boxx + boxs + 1, boxy + 10); cout << char(186);
	gotoxy(boxx, boxy + 11); cout << char(186) ;
	gotoxy(boxx + boxs + 1, boxy + 11); cout << char(186);
	gotoxy(boxx, boxy + 12); cout << char(186)<< "	Nam SB: ";
	gotoxy(boxx + boxs + 1, boxy + 12); cout << char(186);
	gotoxy(boxx, boxy + 13); cout << char(186);
	gotoxy(boxx + boxs + 1, boxy + 13); cout << char(186);
	gotoxy(boxx, boxy + 14); cout << char(200);
	for(int i = 1; i < boxs + 1; i++) cout << char(205);
	cout << char(188); 
}

int CheckLoi_DS(string &t,int k,LDS l)// kiem tra loi khi nhap du lieu
{
	if(k == 4) t = Fix_ISBN(t);
	if(k == 3) t = Fix_Tensach(t);
	char temp[31];
	strcpy(temp,t.c_str());
	
	if(k == 1)
	{
		if(t == "") return 1;
		if(Check_So(t) == 1) return 12;
		if(TimKiemDS(l,t) != -1) return 2; 
		else if(t.length() > 13) return 13;
	}
	
	if(k == 2)
	{
		if(t == "") return 3;
		else if(t.length() > 40) return 14;
	}
	
	if(k == 3)
	{
		if(t == "") return 4;
		else if(t.length() > 30) return 15;
		if(Check_chu_tac_gia(t) == 1) return 19;
	}
	
	if(k == 4)
	{
		if(t == "") return 5;
		else if(t.length() > 30) return 16;
	}
	if(k == 5)
	{
		if(t == "") return 7;
		if(Check_So(t) != 0) return 8;
		else if(t.length() > 7) return 17;
	}
	if(k == 6)
	{
		if(t == "") return 9;
		if(Check_So(t) != 0) return 10;
		else if(t.length() > 5) return 18;
	}
	
	return 0;
}

void Print_Error_DS(int k) // Kiem tra loi Nhap du lieu
{
	string s;
	if(k == 1) s = "MA ISBN LA BAT BUOC!                    ";
	else if(k == 2) s = "MA ISBN DA BI TRUNG!               ";
	else if(k == 3) s = "TEN SACH LA BAT BUOC!              ";
	else if(k == 4) s = "TEN TAC GIA LA BAT BUOC!           ";
	else if(k == 5) s = "THE LOAI LA BAT BUOC!              ";
	else if(k == 6) s = "NHAP TEN THE LOAI KHONG HOP LE!    ";
	else if(k == 7) s = "NHAP SO TRANG LA BAT BUOC!         ";
	else if(k == 8) s = "SO TRANG PHAI LA SO!               ";
	else if(k == 9) s = "NHAP NAM XUAT BAN LA BAT BUOC!     ";
	else if(k == 10) s = "NAM XUAT BAN PHAI LA SO!          ";
	else if(k == 11) s = "QUA DAI!                          ";
	else if (k == 12) s = "MA ISBN PHAI LA SO!              ";
	else if(k == 13) s = "MA ISBN KHONG QUA 13 SO";
	else if(k == 14) s = "TEN SACH KHONG QUA 40 KI TU";
	else if(k == 15) s = "TAC GIA KHONG QUA 30 KI TU";
	else if(k == 16) s = "THE LOAI SACH KHONG QUA 30 KI TU";
	else if(k == 17) s = "SO TRANG KHONG QUA 7 SO";
	else if(k == 18) s = "NAM XUAT BAN KHONG QUA 5 SO";
	else if(k == 19) s = "KHONG DUOC NHAP KI TU DAC BIET";
	gotoxy(boxx + 14 , 28); cout << "CANH BAO: "<< s;
}
 
void Trang_Sau_Truoc()
{
	gotoxy(125,37);
	for(int i=1; i<30; i++)
	{
		cout<<char(220);
	}
	gotoxy(125,38);
	cout<<char(221);
	gotoxy(135,38);
	cout<<"PgDn: TRANG SAU";
	gotoxy(57,37);
	for(int i=1; i<30; i++)
	{
		cout<<char(220);
	}
	gotoxy(85,38);
	cout<<char(222);
	gotoxy(64,38);
	cout<<"PgUp: TRANG TRUOC";
}
 ///////////////////////
 void TableDG1(Tree t, int &dem, int &v, int &m)
{	
	gotoxy(tabx,taby+2);

	for(int i = m; i< v; i++)
	{
		if(i %2 == 1)
		{
			gotoxy(tabx,taby+i +1);
			for(int k = 1; k<tabs + 1; k++)
			{
				cout << char(196);
			}
			gotoxy(tabx,taby+i+1);
			cout<<char(195);
			gotoxy(tabx + 15,taby+i+1);
			cout<<char(197);
			gotoxy(tabx + 31,taby+i+1);
			cout<<char(197);
			gotoxy(tabx + 47,taby+i+1);
			cout<<char(197);
			gotoxy(tabx + 58,taby+i+1);
			cout<<char(197);
			gotoxy(tabx + 82,taby+i+1);
			cout<<char(180);
			gotoxy(tabx, taby +i + 2); cout << char(179);
			gotoxy(tabx + 15, taby + i+2); cout << char(179);
			gotoxy(tabx + 31, taby + +i+2); cout << char(179);
			gotoxy(tabx + 47, taby + i+2); cout << char(179);
			gotoxy(tabx + 58, taby + i +2); cout << char(179);
			gotoxy(tabx + 82, taby + i+2); cout << char(179);
			gotoxy(70, 8 + dem);cout << t->DG.MADG; 
			gotoxy(86, 8 + dem);cout << t->DG.ho; 
			gotoxy(102, 8 + dem);cout << t->DG.ten; 
			gotoxy(116, 8 + dem);cout << t->DG.gioitinh;
			gotoxy(134, 8 + dem);cout <<t->DG.trangthaithe;
		/*	if(t->DG.trangthaithe == 1)
			{
				gotoxy(130, 8 + dem);cout << "HOAT DONG";
			}
			else if(t->DG.trangthaithe == 0)
			{
				gotoxy(130, 8 + dem);cout << "KHOA";
			}*/
			dem = dem +2;
			m = v;
			Sleep(50);
		}
	}
}
 void NhapDocGia(Tree &t)
{
	int a =1;
	int b =14;
	int d;
	while(1)
	{
Menu:
		int v = 0;
		int m = 1;
		d = 0;
	     LoadtuFile_DSDG(t);
	     textcolor(15);
	     clrscr();
	     textcolor(15);
	     Giao_Dien();
	     Khung_Chuc_Nang();
	     Chuc_Nang_Phu();
	     Trang_Sau_Truoc();
	     Menu_Tam_Thoi(1);
	     int dem = 0;;
	     const int STACKSIZE = 100;
		Tree Stack[STACKSIZE];// khoi tao mang stack
		int sp = -1;
			gotoxy(100,3);
			cout << "DANH SACH DOC GIA";
			gotoxy(tabx, taby);
			cout << char(218);
			for(int i = 1; i < tabs; i++)
			{
				cout << char(196);
			}
			cout << char(191);
			gotoxy(tabx + 15, taby); cout << char(194);
			gotoxy(tabx + 31, taby); cout << char(194);
			gotoxy(tabx + 47, taby); cout << char(194);
			gotoxy(tabx + 58, taby); cout << char(194);
			gotoxy(tabx , taby + 1); cout << char(179);
			gotoxy(tabx + 15, taby + 1); cout << char(179);
			gotoxy(tabx + 3, taby + 1); cout << "MA DOC GIA";
			gotoxy(tabx + 31, taby + 1); cout << char(179);
			gotoxy(tabx + 19, taby + 1); cout << "HO DOC GIA";
			gotoxy(tabx + 47, taby + 1); cout << char(179);
			gotoxy(tabx + 34, taby + 1); cout << "TEN DOC GIA";
			gotoxy(tabx + 58, taby + 1); cout << char(179);
			gotoxy(tabx + 51, taby + 1); cout << "PHAI";
			gotoxy(tabx + 82, taby + 1); cout << char(179);
			gotoxy(tabx + 62, taby + 1); cout << "TRANG THAI THE";
		do // Duyet danh theo Phuong phap Stack
		{
			while (t != NULL)
			{
				Stack[++sp] = t;
				t = t->pLeft;
			}
			if (sp != -1)
			{
				t = Stack[sp--];
				d++;
				if(d>=a && d <= b)
				{
					v = v +2;
					TableDG1(t,dem,v,m);
				}
				t = t->pRight;
			}
			else break;
		} while (1);
		if(v <= 28)
		{
			gotoxy(tabx, taby + v+2);
			cout << char(192);
			for(int i = 1; i < tabs; i++)
			{
				cout << char(196);
			}
			cout << char(191);
			gotoxy(tabx + 15, taby +v +2); cout << char(193);
			gotoxy(tabx + 31, taby +v +2); cout << char(193);
			gotoxy(tabx + 47, taby+v+2); cout << char(193);
			gotoxy(tabx + 58, taby+v+2); cout << char(193);
			gotoxy(tabx + tabs, taby +v+2); cout << char(217);
		}
		Giao_Dien();
	int x = 18;
	int y = 31;
	int keyhit;
	// Tao menu dong chon chuc nang
	char menu_text[12][100] = { " 1. THEM DOC GIA", " 2. XOA DOC GIA ", " 3. SUA DOC GIA", " 4. THOAT "};
    gotoxy(15, 28); cout <<     "        MENU CHUC NANG "; 
    gotoxy(15,29); cout<<"    ---------------------";
    gotoxy(x, 31); cout << menu_text[0];
	gotoxy(x, 32); cout << menu_text[1];
	gotoxy(x, 33); cout << menu_text[2];
	gotoxy(x, 34); cout << menu_text[3];
	do{
		gotoxy(x, y);
		textcolor(159);// nen mau xanh
		switch (y)
		{
		case 31: gotoxy(x, 31); cout << menu_text[0]; break;
		case 32: gotoxy(x, 32); cout << menu_text[1]; break;
		case 33: gotoxy(x, 33); cout << menu_text[2]; break;
		case 34: gotoxy(x, 34); cout << menu_text[3]; break;
		}
		keyhit = getch(); // Kiem Tra Nhan Lenh Ban Phim
		if (keyhit == UP) // Di Len
		{
			gotoxy(x, y);
			textcolor(15); // Doi thanh mau chu mau trang
			switch (y)
			{
			case 31: gotoxy(x, 31); cout << menu_text[0]; break;
			case 32: gotoxy(x, 32); cout << menu_text[1]; break;
			case 33: gotoxy(x, 33); cout << menu_text[2]; break;
			case 34: gotoxy(x, 34); cout << menu_text[3]; break;
			}
			y--;
			if (y < 31)
			{
				y = 34;
			}
		}
		else if (keyhit == DOWN) // di xuong
		{
			gotoxy(x, y);
			textcolor(15);
			switch (y)
			{
			case 31: gotoxy(x, 31); cout << menu_text[0]; break;
			case 32: gotoxy(x, 32); cout << menu_text[1]; break;
			case 33: gotoxy(x, 33); cout << menu_text[2]; break;
			case 34: gotoxy(x, 34); cout << menu_text[3]; break;
			}
			y++;
			if (y > 34)
			{
				y = 31;
			}
		}
	if (y == 31 && keyhit == ENTER || keyhit == 59) // Chuc nang them doc gia
		{
			textcolor(15);
			clrscr();
			NhapDG(t);
			goto Menu;
		}
	else if( y == 32 && keyhit == ENTER || keyhit == 60) // chuc nang xoa doc gia
	{
		XoaDG(t);
		goto Menu;
	}
	else if( y == 33 && keyhit == ENTER || keyhit == 61)// chuc nang sua doc gia
	{
		SuaDG(t);
		goto Menu;
	}
	else if( y == 34 && keyhit == ENTER ) // Thoat
	{
		textcolor(15);
		clrscr();
	    break;
	}
	else if(keyhit == 27) // thoat
	{
		textcolor(15);
		clrscr();
	    break;
	}
	else if(keyhit == 62)
	{
		frameChuThichDocGia(13,29);
		int f = getch();
		if(f == 27)
		{
			textcolor(15);
			clrscr();
			goto Menu;
		}
	}
	else if(keyhit == 81) // xem trang sau
	{
		if(d <= b)
		{
			textcolor(15);
			clrscr();
			goto Menu;
		}
		a = b+1;
		b = b +14;
		textcolor(15);
		clrscr();
		goto Menu;
	}
	else if(keyhit == 73)// xem trang truoc
	{
		if(a==1 && b ==14)
		{
			textcolor(15);
			clrscr();
			goto Menu;
		}
		a = a-14;
		b = b-14;
		textcolor(15);
		clrscr();
		goto Menu;
	}
	}while(true);
	break;
	}
}
 
 //**********************************  Xuat Danh Sach Doc Gia   ************************************
 int XacNhanDanhSachDG()
{
	Menu_Tam_Thoi(2);
    Giao_Dien();
    Khung_Chuc_Nang();
	int x = 95, y = 17;
	gotoxy(90, 13);
	textcolor(112);
	cout << "                                 ";
	gotoxy(90, 14); cout << "                                 ";
	gotoxy(90, 15); cout << "        DANH SACH DOC GIA        ";
	gotoxy(90, 16); cout << "                                 ";
	gotoxy(90, 17); cout << "     TEN_DG            MA_DG     ";
	gotoxy(90, 18); cout << "                                 ";
	int keyhit;
	do{
		gotoxy(95, 17);
		textcolor(121);
		switch(x)
		{
		case 95 : gotoxy(95, 17); cout << "TEN_DG"; break;
		case 113 : gotoxy(113, 17); cout << "MA_DG"; break;
		}
		keyhit = getch(); // Kiem tra nhan lenh ban phim
		if(keyhit == LEFT) // qua trai
		{
			gotoxy(95, 17);
			textcolor(112);
			switch(x)
			{
			case 95 : gotoxy(95, 17); cout << "TEN_DG"; break;
			case 113 : gotoxy(113, 17); cout << "MA_DG"; break;
			}
			x -= 18;
			if(x != 95)
			{
				x = 113;
			}
		}
		else if(keyhit == RIGHT)// qua phai
		{
			gotoxy(95, 17);
			textcolor(112);
			switch(x)
			{
			case 95 : gotoxy(95, 17); cout << "TEN_DG"; break;
			case 113 : gotoxy(113, 17); cout << "MA_DG"; break;
			}
			x += 18;
			if(x != 113)
			{
				x = 95;
			}
		}
		else if(x == 95 && keyhit == ENTER) // nhan chuc nang sap xep theo ten doc gia
		{
			return 1;
		}
		else if(x == 113 && keyhit == ENTER) // Nhan chuc nang sap xep theo ma dg
		{
			return 0;
		}
		else if(x == 95 && keyhit == ESC || x == 113 && keyhit == ESC) // Thoat
		{
			textcolor(15);
			clrscr();
			Menu();
		}
	}while(true);
}
 
 void XuatDanhSachDG(Tree t)
{
	Giao_Dien();
	Menu_Tam_Thoi(2);
	gotoxy(25,38);
	cout<<"ESC: THOAT";
	int a = XacNhanDanhSachDG(); // xac nhan muon xem danh sach teho thu tu ten hay ma doc gia
	if( a == 1) // xem danh sach theo ten
	{
		int c =1;
		int d =14;
		textcolor(15);
   		clrscr();
		while(1)
		{
	Menu:
		int v = 0;
		int m = 1;
		int e =0;
	  	LoadtuFile_DSDG(t);
        Giao_Dien();
        Menu_Tam_Thoi(2);
    	Trang_Sau_Truoc();
    	gotoxy(15,38);
 		cout<<"ESC: THOAT";
 		gotoxy(30,38);
 		cout<<"F4: CHU THICH";
 		gotoxy(4,37);
 		for(int i=1; i<=49; i++)
 		{
 			cout<<char(220);
		 }
		 gotoxy(100,3);
		cout << "DANH SACH DOC GIA";
		gotoxy(tabx, taby);
		cout << char(218);
		for(int i = 1; i < tabs; i++)
		{
			cout << char(196);
		}
		cout << char(191);
		gotoxy(tabx + 15, taby); cout << char(194);
		gotoxy(tabx + 31, taby); cout << char(194);
		gotoxy(tabx + 47, taby); cout << char(194);
		gotoxy(tabx + 58, taby); cout << char(194);
		gotoxy(tabx , taby + 1); cout << char(179);
		gotoxy(tabx + 15, taby + 1); cout << char(179);
		gotoxy(tabx + 3, taby + 1); cout << "MA DOC GIA";
		gotoxy(tabx + 31, taby + 1); cout << char(179);
		gotoxy(tabx + 19, taby + 1); cout << "HO DOC GIA";
		gotoxy(tabx + 47, taby + 1); cout << char(179);
		gotoxy(tabx + 34, taby + 1); cout << "TEN DOC GIA";
		gotoxy(tabx + 58, taby + 1); cout << char(179);
		gotoxy(tabx + 51, taby + 1); cout << "PHAI";
		gotoxy(tabx + 82, taby + 1); cout << char(179);
		gotoxy(tabx + 62, taby + 1); cout << "TRANG THAI THE";
    	int dem = 0;;
    	const int STACKSIZE = 100;
    	int sp = -1;
    	Tree *n = new Tree[STACKSIZE]; // Khai bao 1 mang de chua ds doc gia
    	Duyet_NLR(t, n, sp); // duyet ds doc gia dua vao mang m
		Sap_Xep_Ho_Ten(n, sp); // sap xep
		for(int i=0; i<=sp; i++) // duyet mang
		{
			e++;
			if(e>=c && e <= d)
				{
					v = v +2;
					TableDG1(n[i],dem,v,m);
				}
		}
		if(v <= 28)
		{
			gotoxy(tabx, taby + v+2);
			cout << char(192);
			for(int i = 1; i < tabs; i++)
			{
				cout << char(196);
			}
			cout << char(191);
			gotoxy(tabx + 15, taby +v +2); cout << char(193);
			gotoxy(tabx + 31, taby +v +2); cout << char(193);
			gotoxy(tabx + 47, taby+v+2); cout << char(193);
			gotoxy(tabx + 58, taby+v+2); cout << char(193);
			gotoxy(tabx + tabs, taby +v+2); cout << char(217);
		}
		int keyhit = getch();
        if(keyhit == 27)
    	{
    		textcolor(15);
    	    clrscr();
    	    break;
    	}
    	else if(keyhit == 224 ) // xem trang sau
		{
			int f = getch();
			if(f == 81)
			{
				if(e<=d)
				{
					textcolor(15);
					clrscr();
					goto Menu;
				}
				c = d+1;
				d = d +14;
				textcolor(15);
				clrscr();
				goto Menu;	
			}
			else if(f == 73)// xem trang truoc
			{
				if(c == 1 && d == 14)
				{
					textcolor(15);
					clrscr();
					goto Menu;
				}
				c = c-14;
				d = d-14;
				textcolor(15);
				clrscr();
				goto Menu;
			}
		}
		else if(keyhit == 0 )
		{
			int f = getch();
			if(f == 62)
			{
				frameChuThichDocGia(13, 27);
				int u = getch();
				if(u == 27)
				{
					textcolor(15);
					clrscr();
					goto Menu;
				}
				else if(u == 0)
				{
					int f = getch();
					textcolor(15);
					clrscr();
					goto Menu;
				}
				else
				{
					textcolor(15);
					clrscr();
					goto Menu;
				}
			}
			else
			{
				textcolor(15);
				clrscr();
				goto Menu;
			}
		}
		else
		{
			textcolor(15);
			clrscr();
			break;
		}
		}
	}
	else if(a == 0) // Xem danh sach theo ma doc gia
	{
		int c =1;
		int d = 14;
		textcolor(15);
    	clrscr();
		while(1)
    	{
    	Menu2:
    		int v = 0;
			int m = 1;
    		int e =0;
    	     LoadtuFile_DSDG(t);
    	     Trang_Sau_Truoc();
    	     gotoxy(4,37);
 			for(int i=1; i<=49; i++)
 			{
 				cout<<char(220);
		 	}
		 	gotoxy(15,38);
 			cout<<"F4: CHU THICH";
    	     gotoxy(35,38);
			cout<<"ESC: THOAT";
    		Menu_Tam_Thoi(2);
    		Giao_Dien();
    		 gotoxy(100,3);
			cout << "DANH SACH DOC GIA";
			gotoxy(tabx, taby);
			cout << char(218);
			for(int i = 1; i < tabs; i++)
			{
				cout << char(196);
			}
			cout << char(191);
			gotoxy(tabx + 15, taby); cout << char(194);
			gotoxy(tabx + 31, taby); cout << char(194);
			gotoxy(tabx + 47, taby); cout << char(194);
			gotoxy(tabx + 58, taby); cout << char(194);
			gotoxy(tabx , taby + 1); cout << char(179);
			gotoxy(tabx + 15, taby + 1); cout << char(179);
			gotoxy(tabx + 3, taby + 1); cout << "MA DOC GIA";
			gotoxy(tabx + 31, taby + 1); cout << char(179);
			gotoxy(tabx + 19, taby + 1); cout << "HO DOC GIA";
			gotoxy(tabx + 47, taby + 1); cout << char(179);
			gotoxy(tabx + 34, taby + 1); cout << "TEN DOC GIA";
			gotoxy(tabx + 58, taby + 1); cout << char(179);
			gotoxy(tabx + 51, taby + 1); cout << "PHAI";
			gotoxy(tabx + 82, taby + 1); cout << char(179);
			gotoxy(tabx + 62, taby + 1); cout << "TRANG THAI THE";
    	     int dem = 0;;
    	     const int STACKSIZE = 100;
    		 Tree Stack[STACKSIZE];
    	   	int sp = -1;
    		do
    		{
    			while (t != NULL)
    			{
    				Stack[++sp] = t;
    				t = t->pLeft;
    			}
    			if (sp != -1)
    			{
    				t = Stack[sp--]; // lay t xong roi moi giam sp
    				e++;
				if(e>=c && e <= d)
				{
				
					v = v +2;
					TableDG1(t,dem,v,m);
				}
    				t = t->pRight;
    			}
    			else break;
    		} while (1);
    		if(v <= 28)
			{
				gotoxy(tabx, taby + v+2);
				cout << char(192);
				for(int i = 1; i < tabs; i++)
				{
					cout << char(196);
				}
				cout << char(191);
				gotoxy(tabx + 15, taby +v +2); cout << char(193);
				gotoxy(tabx + 31, taby +v +2); cout << char(193);
				gotoxy(tabx + 47, taby+v+2); cout << char(193);
				gotoxy(tabx + 58, taby+v+2); cout << char(193);
				gotoxy(tabx + tabs, taby +v+2); cout << char(217);
			}
			int keyhit = getch();
	        if(keyhit == 27)
	    	{
	    		textcolor(15);
	    	    clrscr();
	    	    Menu();
	    	}
	    	else if(keyhit == 224 ) // xem trang sau
			{
				int f = getch();
				if(f == 81)
				{
					if(e<=d)
					{
						textcolor(15);
						clrscr();
						goto Menu2;
					}
					c = d+1;
					d = d +14;
					textcolor(15);
					clrscr();
					goto Menu2;	
				}
				else if(f == 73)// xem trang truoc
				{
					if(c == 1 && d == 14)
					{
						textcolor(15);
						clrscr();
						goto Menu2;
					}
					c = c-14;
					d = d-14;
					textcolor(15);
					clrscr();
					goto Menu2;
				}
			}
			else if(keyhit == 0 )
			{
				int f = getch();
				if(f == 62)
				{
					frameChuThichDocGia(13, 27);
					int u = getch();
					if(u == 27)
					{
						textcolor(15);
						clrscr();
						goto Menu2;
					}
					else if(u == 0)
					{
						int f = getch();
						textcolor(15);
						clrscr();
						goto Menu2;
					}
					else
					{
						textcolor(15);
						clrscr();
						goto Menu2;
					}
				}
				else
				{
					textcolor(15);
					clrscr();
					goto Menu2;
				}
			}
			else
			{
				textcolor(15);
				clrscr();
				goto Menu2;
			}
		}	
	}
}
 //**********************************   Nhap Danh Sach Dau Sach  ********************************
 void Trang_Sau_Truoc_DMS()
{
	gotoxy(135,37);
	for(int i=1; i<20; i++)
	{
		cout<<char(220);
	}
	gotoxy(135,38);
	cout<<char(221);
	gotoxy(137,38);
	cout<<"PgDn: TRANG SAU";
	gotoxy(57,37);
	for(int i=1; i<20; i++)
	{
		cout<<char(220);
	}
	gotoxy(75,38);
	cout<<char(222);
	gotoxy(58,38);
	cout<<"PgUp: TRANG TRUOC";
}
 void Box_NhapDMS()
{        
	textcolor(15);
	gotoxy(boxx, boxy); cout << char(201);
	for(int i = 1; i < boxs + 1; i++) cout << char(205);
	cout << char(187);
	gotoxy(boxx, boxy + 1); cout << char(186);
	gotoxy(boxx + boxs + 1, boxy + 1); cout << char(186);
	gotoxy(boxx, boxy + 2); cout << char(186)<< "	Nhap Ma Sach: ";
	gotoxy(boxx + boxs + 1, boxy + 2); cout << char(186);
	gotoxy(boxx, boxy + 3); cout << char(186) ;
	gotoxy(boxx + boxs + 1, boxy + 3); cout << char(186);
	gotoxy(boxx, boxy + 4); cout << char(186)<< "	Nhap Trang Thai: ";
	gotoxy(boxx + boxs + 1, boxy + 4); cout << char(186);
	gotoxy(boxx, boxy + 5); cout << char(186);
	gotoxy(boxx + boxs + 1, boxy + 5); cout << char(186);
	gotoxy(boxx, boxy + 6); cout << char(186)<< "	Nhap Vi Tri: ";
	gotoxy(boxx + boxs + 1, boxy + 6); cout << char(186);	
	gotoxy(boxx, boxy + 7); cout << char(200);
	for(int i = 1; i < boxs + 1; i++) cout << char(205);
	cout << char(188); 
}
int XacNhanThemDMS()
{
		int x = 95, y = 19;
	gotoxy(90, 17);
	textcolor(112);
	cout << "                                ";
	gotoxy(90, 18); cout << "                                ";
	gotoxy(90, 19); cout << "  BAN CO CHAC CHAN THEM KHONG?  ";
	gotoxy(90, 20); cout << "                                ";
	gotoxy(90, 21); cout << "     YES                NO      ";
	gotoxy(90, 22); cout << "                                ";
	int keyhit;
	do{
		gotoxy(98, 21);
		textcolor(121);
		switch(x)
		{
		case 95 : gotoxy(95, 21); cout << "YES"; break;
		case 114 : gotoxy(114, 21); cout << "NO"; break;
		}
		keyhit = getch();
		if(keyhit == LEFT)// phim mui ten qua trai
		{
			gotoxy(95, 21);
			textcolor(112);
			switch(x)
			{
			case 95 : gotoxy(95, 21); cout << "YES"; break;
			case 114 : gotoxy(114, 21); cout << "NO"; break;
			}
			x -= 19;
			if(x != 95)
			{
				x = 114;
			}
		}
		else if(keyhit == RIGHT)// phim mui ten qua phai
		{
			gotoxy(95, 21);
			textcolor(112);
			switch(x)
			{
			case 95 : gotoxy(95, 21); cout << "YES"; break;
			case 114 : gotoxy(114, 21); cout << "NO"; break;
			}
			x += 19;
			if(x != 114)
			{
				x = 95;
			}
		}
		else if(x == 95 && keyhit == ENTER)
		{
			textcolor(15);
			gotoxy(97, 24);
			cout << "LUU FILE THANH CONG";
			return 1;
		}
		else if(x == 114 && keyhit == ENTER)
		{
			return 0;
		}
	}while(true);
}


void Table_DMS(DMSNode *&k, int &dem, int &v, int &m)
{
		gotoxy(tabx + 12,taby+8);
	for(int i = m; i< v; i++)
	{
		if(i %2 == 1)
		{
			gotoxy(tabx + 12,taby+i +7);
			for(int j = 1; j<tabs -23; j++)
			{
				cout << char(196);
			}
			gotoxy(tabx +12,taby+i+7);
			cout<<char(195);
			gotoxy(tabx + 31,taby+i+7);
			cout<<char(197);
			gotoxy(tabx + 51,taby+i+7);
			cout<<char(197);
			gotoxy(tabx + 70,taby+i+7);
			cout<<char(180);
			gotoxy(tabx + 12, taby +i + 8); cout << char(179);
			gotoxy(tabx + 31, taby + i+8); cout << char(179);
			gotoxy(tabx + 51, taby + +i+8); cout << char(179);
			gotoxy(tabx + 70, taby + i+8); cout << char(179);		
			gotoxy(boxx +8, boxy +2+ dem ); cout<<k->data.maSach;
			gotoxy(boxx + 28, boxy +2+ dem ); cout<<k->data.ttSach;
	   	/*	if(k->data.ttSach == 0)
	   		{
	   				gotoxy(boxx + 25, boxy +2+ dem ); cout<<"DUOC MUON";
			}
			else if(k->data.ttSach == 1)
			{
				gotoxy(boxx + 25, boxy +2+ dem ); cout<<"DA MUON";
			}
			else if(k->data.ttSach == 2)
			{
				gotoxy(boxx + 25, boxy +2+ dem ); cout<<"THANH LY";
			}*/
		   	gotoxy(boxx + 49, boxy + 2+dem);cout<<k->data.vitri;
			dem = dem +2;
			m = v;
			Sleep(30);
		}
	}
}
 
 void frameViTriSach(int x, int y)
{
	gotoxy(40, 15);
	textcolor(112);
	gotoxy(x, y - 1); 		cout << "                           ";
	gotoxy(x, y); 			cout << "      VI TRI DAT SACH      ";
	gotoxy(x, y + 1);		cout << " ";
	gotoxy(x + 1, y + 1); 	cout << "                         ";
	gotoxy(x + 26, y + 1); 	cout << " ";
	gotoxy(x, y + 2); 		cout << "                           ";
	textcolor(15);
}

void NhapDMS(LDMS &l, DAUSACH *DS, int &z, int &n)
{
DMS:
	frameViTriSach(93, 20); // bang nhap vi tri sach
	int x = 97, y = 20; // vi tri toa do de lam moc
	int keyhit, dem;
	string text1, field;
	field = "";  // Khoi tao field rong de nhap du lieu
	keyhit = 0; 
	dem = field.length();
	text1 = field;
	while(1)//Nhap vi tri sach va kiem tra du lieu
	{
		textcolor(253);
		gotoxy(x + 5, y + 1);
		if(dem < 9) // neu chieu dai text1 nho hon 9
		{
			cout << text1; 
			for(int i = 1; i < 11 - dem; i++) cout << " "; // chieu dai khong gian de nhap du lieu
		}
		else // chieu dai text1 >= 9
		{
			for(int i = dem - 9; i < dem; i++)  // neu nhap qua chieu dai khong gian nhap du lieu thi no se day du lieu qua ben phai
				cout << text1[i];
		}
		if(dem < 9) gotoxy(x + 5 + dem, y + 1); // ki tu duoc nhap tiep theo nam o vi tri sau ke tiep text1
		keyhit = getch(); // Kiem tra bat ban phim
		if(keyhit == BACKSPACE) // Nhan phim backspace de xoa ki tu cuoi cung
		{
			if(dem > 0)
			{
				dem--;
				text1 = text1.substr(0, text1.size() - 1); // Xoa ki tu cuoi cung
			}
		}
		else if(keyhit == ENTER)
		{
			if(text1 == "")// du lieu nhap bi rong 
			{
				textcolor(15);
				keyhit = 0;
				gotoxy(boxx + 17, 25);
				textcolor(112);
				cout << "    (VUI LONG NHAP VI TRI)   ";
				int keyhit = getch();
				textcolor(15);
				gotoxy(boxx + 17, 25); cout<<"                                        ";
				goto DMS; 
			}
			else
			{
				int m =Check_So(text1); // kiem tra xem du lieu nhap co phai la so
				if(m == 1) // dieu kien bi sai
				{
					textcolor(112);
					gotoxy( 95,25); cout<<"VI TRI SACH PHAI LA SO";
					int keyhit = getch();
					textcolor(15);
					gotoxy( 95,25); cout<<"                                    ";
					goto DMS;
				}
				else //nhap du lieu dung
				{
					 int h = atoi((char*)text1.c_str()); // doi du lieu kieu string sang int
					 for(int i=1; i<=z; i++)// tu dong nhap ma sach
					{
						DanhMucSach data;
						string MS= DS->ISBN;
						string str = convertInt(i); // chuyen doi i tu kieu int sang string
						string MS1= MS.append("-"); // MS1 gom 2 phan: phan ben trai "-" la ISBN, ben phai "-" la ma sach
       					MS1.append(str);
						data.maSach = MS1;
						data.ttSach = 0;
						data.vitri = h;
						AddTailDMS(l,CreateDMS(data)); // them vao dms
					}
					break;
				}
			}
		}
		else if(keyhit == ESC) // nhan phim ESC de thoat
		{
			n++;
			textcolor(15);
			clrscr();
			break;
		}
		else //nhap ki tu tiep theo cho text1
		{
			dem++;
			text1 += toupper((char)keyhit);

		}
	}
}
 
 void Khung_Dau_Sach()
 {
 	gotoxy(80,2);cout<<char(201);
 	for(int i=1; i<50; i++)
 	{
 		gotoxy(80+i,2);cout<<char(205);
	 }
	 gotoxy(130,2); cout<<char(187);
	 for(int i=1; i<7; i++)
	 {
	 	gotoxy(80, 2+i);  cout<<char(186);
	 	gotoxy(130, 2+i); cout<<char(186);
	 }
	 gotoxy(80,9);cout<<char(200);
 	for(int i=1; i<50; i++)
 	{
 		gotoxy(80+i,9);cout<<char(205);
	 }
	 gotoxy(130,9); cout<<char(188);
 }
 
 void frameSoLuongSach(int x, int y)
{
	gotoxy(40, 15);
	textcolor(112);
	gotoxy(x, y - 1); 		cout << "                           ";
	gotoxy(x, y); 			cout << "   SO LUONG SACH HIEN CO   ";
	gotoxy(x, y + 1);		cout << " ";
	gotoxy(x + 1, y + 1); 	cout << "                         ";
	gotoxy(x + 26, y + 1); 	cout << " ";
	gotoxy(x, y + 2); 		cout << "                           ";
	textcolor(15);
}
 
int XemMDS(LDS &l, DAUSACH *&DS, int &n)
{
	textcolor(15);
	clrscr();
DMS:	
 	Giao_Dien();
	Menu_Tam_Thoi(3);
	Khung_Chuc_Nang();
	gotoxy(23,38); cout<<"ESC: THOAT";
	frameSoLuongSach(93, 20); // bang nhap so luong sach
	int x = 97, y = 20;// vi tri toa do de lam moc
	int keyhit, dem;
	string text, field;
	field = ""; // Khoi tao field rong de nhap du lieu
	keyhit = 0;
	dem = field.length();
	text = field;
	while(1)//Nhap vi tri sach va kiem tra du lieu
	{
		textcolor(253);
		gotoxy(x + 5, y + 1);
		if(dem < 9) // neu chieu dai text1 nho hon 9
		{
			cout << text;
			for(int i = 1; i < 11 - dem; i++) cout << " ";// chieu dai khong gian de nhap du lieu
		}
		else
		{
			for(int i = dem - 9; i < dem; i++)// neu nhap qua chieu dai khong gian nhap du lieu thi no se day du lieu qua ben phai
				cout << text[i];
		}
		if(dem < 9) gotoxy(x + 5 + dem, y + 1);// ki tu duoc nhap tiep theo nam o vi tri sau ke tiep text1
		keyhit = getch();// Kiem tra bat ban phim
		if(keyhit == BACKSPACE)// Nhan phim backspace de xoa ki tu cuoi cung
		{
			if(dem > 0)
			{
				dem--;
				text = text.substr(0, text.size() - 1);// Xoa ki tu cuoi cung
			}
		}
		else if(keyhit == ENTER)
		{
			if(text == "")// du lieu nhap bi rong 
			{
				textcolor(15);
				keyhit = 0;
				gotoxy(boxx + 20, 25);
				textcolor(112);
				gotoxy(boxx + 17, 25);
				cout << "(VUI LONG NHAP SO LUONG SACH)";
				int keyhit = getch();
				textcolor(15);
				gotoxy(boxx + 17, 25);
				cout << "                                          ";
				goto DMS; 
			}
			else
			{
				int m =Check_So(text);// kiem tra xem du lieu nhap co phai la so
				if(m == 1) // dieu kien bi sai
				{
					textcolor(112);
					gotoxy( 93,25); cout<<"     SO LUONG SACH LA SO     ";
					textcolor(15);
					int keyhit = getch();
					textcolor(15);
					gotoxy( 93,25); cout<<"                                     ";
					goto DMS;
				}
				else//nhap du lieu dung
				{
					int z = atoi((char*)text.c_str());// doi du lieu kieu string sang int
					NhapDMS(DS->sach,DS,z, n);
					break;
				}
			}
		}
		else if(keyhit == ESC)// nhan phim ESC de thoat
		{ 
			n++;
			textcolor(15);
			clrscr();
			break;
		}
		else //nhap ki tu tiep theo cho text1
		{
			dem++;
			text += toupper((char)keyhit);

		}
	}
	int k = atoi((char*)text.c_str());// doi du lieu kieu string sang int
	return k; // ket qua ham tra ve so luong sach trong dms
}
 
 void NhapDS(LDS &l, int &m)
{
	DAUSACH *data; // Khoi tao con tro data thuoc kieu du lieu DAUSACH
	data = new DAUSACH[MAX_DAUSACH];//Cap phat vung nho
	while(1) //Thuc hien vong lap
	{
		clrscr();
		Box_NhapDS();
		Menu_Tam_Thoi(3);
		Khung_Chuc_Nang();
		gotoxy(23,38); cout<<"ESC: THOAT";
    	Giao_Dien();
		textcolor(15);                                        
		gotoxy(70,10);cout <<"                               NHAP DAU SACH";
	
		int keyhit, x = 18;
		int demkitu;
		string text, field[6]; // Tao 1 mang gom 6 phan tu de nhap du lieu, cho tat ca deu rong
		field[0] = "";
		field[1] = "";
		field[2] = "";
		field[3] = "";
		field[4] = "";
		field[5] = "";
		for(int n = 2, k = 1; k < 7; n += 2, k++)// thuc hien vong lap cho tung phan tu trong mang field
		{
			keyhit = 0;
			demkitu = field[k - 1].length();
			text = field[k - 1];
			while(keyhit != 13)// thuc hien vong lap nhap ki tu den khi nao nhan phim enter
			{
				gotoxy(boxx + x, boxy + n); // Vi tri toa do bat dau nhap du lieu
				if(demkitu < boxs - x) //con trong pham vi nhap
				{
					cout << text;
					for(int i = 1; i < boxs - x + 1 - demkitu; i++)//che du lieu nhap du
						cout << " ";
				}
				if(demkitu < boxs - x)
					gotoxy(boxx + x + demkitu, boxy + n);//chuyen sang vi tri tiep theo de nhap ki tu tiep theo
				keyhit = getch();//kiem tra bat ban phim
				if(keyhit == 224)
				{
					keyhit = getch(); // Kiem tra lenh bat phim
					if(keyhit == UP)// di len
					{
						gotoxy(80,28); cout<<"                                                     ";
						if(k == 1) text = Fix_ISBN(text);  // chuan hoa du lieu
						if(k == 2) text = Fix_Tensach(text); // Chuan hoa du lieu
						if(k == 3) text = Fix_Tensach(text); // Chuan hoa du lieu
						Print_Textfield(text, n, x); // In du lieu ra man hinh
						field[k - 1] = text;
						if(k > 1) 
						{
							n -= 2;
							k--;
						}
						demkitu = field[k - 1].length();// dem chieu dai field
						text = field[k -1]; // gan field cho text
					}
					else if(keyhit == DOWN)//di xuong
					{
						gotoxy(80,28); cout<<"                                                     ";
						keyhit = 0;
						if(CheckLoi_DS(text, k, l) != 0) //check loi nhap doc gia
						{
							keyhit = 0;
							Print_Error_DS(CheckLoi_DS(text, k, l)); // In loi ra man hinh
							Print_Textfield(text, n, x); // In du lieu ra man hinh
						}
						else
						{
							if(k == 1) text = Fix_ISBN(text); // chuan hoa du lieu
							if(k == 2) text = Fix_Tensach(text); // chuan hoa du lieu
							if(k == 3) text = Fix_Tensach(text);
							Print_Textfield(text, n, x); // in du lieu ra man hinh
							field[k - 1] = text;
							if(k < 6)
							{
								n += 2;
								k++;
							}
							demkitu = field[k - 1].length(); // dem chieu dai field
							text = field[k -1]; // gan field cho text
							
							if(keyhit == DOWN) // di xuong
							{
								gotoxy(80,28); cout<<"                                                     ";
								Print_Textfield(text, n, x); // in du lieu ra man hinh
							}
						}	
					}
				}
				else if(keyhit == BACKSPACE)//xoa ki tu cuoi cung
				{
					gotoxy(80,28); cout<<"                                                     ";
					if(demkitu > 0) // truong hop text khong rong
					{
						demkitu--;
						text = text.substr(0, text.size() - 1); // su dung ham substr de xoa ki tu
					}
				}
				else if(keyhit == ESC)//thoat
				{
					break;
				}
				else if(keyhit == ENTER)//nhan phim enter
				{
					gotoxy(80,28); cout<<"                                                     ";
					if(CheckLoi_DS(text, k, l) != 0) // check loi nhap du lieu
					{
						keyhit = 0;
						Print_Error_DS(CheckLoi_DS(text, k, l)); // In loi ra man hinh
						Print_Textfield(text, n, x); // In du lieu ra man hinh
						Sleep(500);
					}
					else
					{
						if(k == 1) text = Fix_ISBN(text); // chuan hoa du lieu
						if(k == 2) text = Fix_Tensach(text); // chuan hoa du lieu
					}
				}
				else 
				{
					gotoxy(80,28); cout<<"                                                     ";
					demkitu++;
					text += char(keyhit); // Nhap them ki tu vao text
				}
			}
			if(keyhit == ESC) //thoat
			{
				textcolor(15);
			    clrscr();
				break;
			}
			Print_Textfield(text, n, x); // in du lieu ra man hinh
			field[k - 1] = text;
		}
		if(keyhit == ENTER) // bat phim enter de gan du lieu vao cac bien tuong ung
		{
			textcolor(15);
			data->ISBN = field[0];
			data->tenSach = field[1];
			data->tacGia = field[2];
			data->theLoaiSach = field[3];
			data->soTrang = field[4];
			data->namSB = field[5];
			data->n = 0;
			data->solanmuon = 0;
			themDS(l,data);
			KhoitaoLDMS(l.DS[l.n]->sach);
			int n =0;
			int k = XemMDS(l,l.DS[l.n],n); // ham nhap danh muc sach
			if(n != 0)//danh dau de thoat
			{
				break;
			}
			int a = XacNhanThemDMS();
			if(a == 1) // truong hop yes
			{
				m++;
				l.DS[l.n]->n = k; // so luong dms
				l.n++; // tang dau sach len 1
			}
		}
		break;
	}
}
 
 void TableDS1(LDS l, int j, int &dem, int &v, int &m)
 {
	gotoxy(taxx,taxy+2);
	for(int i = m; i< v; i++)
	{
		if(i %2 == 1)
		{
			gotoxy(taxx + 1,taxy+i +1);
			for(int k = 1; k<taxs; k++)
			{
				cout << char(196);
			}
			gotoxy(taxx,taxy+i+1);
			cout<<char(195);
			gotoxy(taxx + 15,taxy+i+1);
			cout<<char(197);
			gotoxy(taxx +57,taxy+i+1);
			cout<<char(197);
			gotoxy(taxx +89,taxy+i+1);
			cout<<char(197);
			gotoxy(taxx +121,taxy+i+1);
			cout<<char(197);
			gotoxy(taxx +131,taxy+i+1);
			cout<<char(197);
			gotoxy(taxx +139,taxy+i+1);
			cout<<char(197);
			gotoxy(taxx + 147,taxy+i+1);
			cout<<char(180);
			gotoxy(taxx, taxy +i + 2); cout << char(179);
			gotoxy(taxx + 15, taxy + i+2); cout << char(179);
			gotoxy(taxx + 57, taxy + +i+2); cout << char(179);
			gotoxy(taxx + 89, taxy + i+2); cout << char(179);
			gotoxy(taxx + 121, taxy + i +2); cout << char(179);
			gotoxy(taxx + 131, taxy + i+2); cout << char(179);
			gotoxy(taxx + 139, taxy + i+2); cout << char(179);
			gotoxy(taxx + 147, taxy + i+2); cout << char(179);
			gotoxy(taxx + 1, 18 + dem); cout << l.DS[j]->ISBN;
			gotoxy(taxx + 16, 18 + dem); cout <<l.DS[j]->tenSach;
			gotoxy(taxx + 58, 18 + dem); cout << l.DS[j]->tacGia;
			gotoxy(taxx + 90, 18 + dem); cout << l.DS[j]->theLoaiSach;
			gotoxy(taxx + 125, 18 + dem); cout << l.DS[j]->soTrang;
			gotoxy(taxx + 134, 18 + dem); cout << l.DS[j]->namSB;
			gotoxy(taxx + 142, 18 + dem); cout << l.DS[j]->solanmuon;
			dem = dem + 2;
			m = v;
			Sleep(50);
		}
	}
 }
 
 void frameDauSach(int x, int y)
{
	gotoxy(40, 15);
	textcolor(112);
	gotoxy(x, y - 1); 		cout << "                           ";
	gotoxy(x, y); 			cout << "       NHAP VAO ISBN       ";
	gotoxy(x, y + 1);		cout << " ";
	gotoxy(x + 1, y + 1); 	cout << "                         ";
	gotoxy(x + 26, y + 1); 	cout << " ";
	gotoxy(x, y + 2); 		cout << "                           ";
	gotoxy(x, y + 3); 		cout << "                           ";
	textcolor(15);
}
 
 void frameMaSach(int x, int y)
{
	gotoxy(4, 15);
	textcolor(112);
	gotoxy(x, y - 1); 		cout << "                           ";
	gotoxy(x, y); 			cout << "      NHAP VAO MA SACH     ";
	gotoxy(x, y + 1);		cout << " ";
	gotoxy(x + 1, y + 1); 	cout << "                         ";
	gotoxy(x + 26, y + 1); 	cout << " ";
	gotoxy(x, y + 2); 		cout << "                           ";
	textcolor(15);
}


void XoaDanhMucSach( DAUSACH *&DS)
{
	textcolor(15);
	clrscr();
	int a =1;
	int b = 12;
	while(1)
	{
X:
	int m = 1;
	int v = 0;
		int d = 0;
	   Giao_Dien();
	   Menu_Tam_Thoi(3);
	   Trang_Sau_Truoc_DMS();
	   for(int i=1; i<50; i++)
	   {
		gotoxy(3+i,37);
		cout<<char(220);
		}
		gotoxy(25,38); cout<<"F4: CHU THICH";
		gotoxy(40,38); cout<<"ESC: THOAT";
    	gotoxy(6,38); cout<<"F1: NHAP MA SACH";
	   Khung_Dau_Sach();
	   gotoxy(82,3);
    	cout<<"TEN SACH: ";
	gotoxy(82,4);
	 cout<<"ISBN: ";
	gotoxy(82,5);
	cout<<"TAC GIA: ";
	gotoxy(82,6);
	cout<<"THE LOAI: ";
	gotoxy(82,7);
	cout<<"SO TRANG: ";
	gotoxy(82,8);
	cout<<"NAM XUAT BAN: ";
	gotoxy(95,10);
	cout << "DANH MUC SACH";
	gotoxy(tabx + 12 , taby + 6);
	cout << char(218);
	for(int i = 1; i < tabs - 24; i++)
	{
		cout << char(196);
	}
	cout << char(191);
	gotoxy(tabx + 31, taby + 6); cout << char(194);
	gotoxy(tabx + 51, taby + 6); cout << char(194);
	gotoxy(tabx + 12, taby + 7); cout << char(179);
	gotoxy(tabx + 31, taby + 7); cout << char(179);
	gotoxy(tabx + 18, taby + 7); cout << "MA SACH";
	gotoxy(tabx + 51, taby + 7); cout << char(179);
	gotoxy(tabx + 36, taby + 7); cout << "TRANG THAI";
	gotoxy(tabx + 70, taby + 7); cout << char(179);
	gotoxy(tabx + 58, taby + 7); cout << "VI TRI";
	   textcolor(15);
	   int dem = 0;
	   gotoxy(92, 3);cout<<DS->tenSach;
	   gotoxy(88, 4);cout<<DS->ISBN;
	   gotoxy(91, 5);cout<<DS->tacGia;
	   gotoxy(92,6);cout<<DS->theLoaiSach;
	   gotoxy(92,7);cout<<DS->soTrang;
	   gotoxy(96,8);cout<<DS->namSB;
	   for(DMSNode *k = DS->sach.pHead; k!=NULL; k = k->pNext)
	   {
	   		d++;
	   		if(d >= a && d <= b)
	   		{
	   			v = v+2;
	   			Table_DMS(k,dem,v,m);		
			}
		}
		if(v <= 24)
		{
			gotoxy(tabx + 12, taby + 6 + v+2);
			cout << char(192);
			for(int i = 1; i < tabs - 23; i++)
			{
				cout << char(196);
			}
			gotoxy(tabx + 31, taby + 6 +v +2); cout << char(193);
			gotoxy(tabx + 51, taby + 6 +v +2); cout << char(193);
			gotoxy(tabx + 70, taby +6+v+2); cout << char(217);
		}
		int c = getch(); // kiem tra lenh bat phim
		if(c == 27) // Phim ESC de thoat
		{
			break;
		}
		else if(c == 224)
		{
			int f = getch();
			if(f == 81) // Phim PgUn de xem trang sach 
			{
				if(d <= b)
				{
					textcolor(15);
					clrscr();
					goto X;
				}
				a = b+1;
				b = b+12;
				textcolor(15);
				clrscr();
				goto X;
			}
			else if(f == 73) // Phim PgUp de xem trang truoc
			{
				if(a == 1 && b == 12)
				{
					textcolor(15);
					clrscr();
					goto X;
				}
				a = a - 12;
				b = b - 12;
				textcolor(15);
				clrscr();
				goto X;
			}
		}
		else if(c == 0) // Nhan Phim F1 
		{
			int f = getch();
			if(f == 59)
			{
				H:
				frameMaSach(15, 29);// bang nhap ma sach
				int x = 19, y = 29;// vi tri toa do de lam moc
				int keyhit, dem;
				string text, field;
				field = "";	// Khoi tao field rong de nhap du lieu
				keyhit = 0;
				dem = field.length();
				text = field;
				while(1)//Nhap vi tri sach va kiem tra du lieu
				{
					textcolor(253);
					gotoxy(x + 5, y + 1);
					if(dem < 9)// neu chieu dai text nho hon 9
					{
						cout << text;
						for(int i = 1; i < 11 - dem; i++) cout << " ";// chieu dai khong gian de nhap du lieu
					}
					else
					{
						for(int i = dem - 9; i < dem; i++)// neu nhap qua chieu dai khong gian nhap du lieu thi no se day du lieu qua ben phai
						cout << text[i];
					}
					if(dem < 9) gotoxy(x + 5 + dem, y + 1);// ki tu duoc nhap tiep theo nam o vi tri sau ke tiep text
					keyhit = getch();// Kiem tra bat ban phim
					if(keyhit == BACKSPACE)// Nhan phim backspace de xoa ki tu cuoi cung
					{
						if(dem > 0)
						{
							dem--;
							text = text.substr(0, text.size() - 1);// Xoa ki tu cuoi cung
						}
					}
					else if(keyhit == ESC)//Nhan phim enter
					{
						textcolor(15);
						Sleep(500);
						clrscr();
						break;
					}
					else if(keyhit == ENTER)// Nhan phim enter
			 		{
						if(text == "")// du lieu nhap bi rong 
						{
							textcolor(15);
							keyhit = 0;
							gotoxy(16, 33);
							textcolor(112);
							cout << "(VUI LONG NHAP MA SACH!)";// bi Table_DMS chen len tren
							int keyhit1 = getch();
							textcolor(15);
							gotoxy(16, 33); cout<<"                             ";
							goto H;
						}
						else
						{
							textcolor(15);
							if(text.length() > 15) // neu chieu dai text lon hon 15
							{
								gotoxy(16, 33);
								textcolor(112);
								cout << "     MA SACH QUA DAI     ";
								int keyhit1 = getch();
								textcolor(15);
								gotoxy(16, 33); cout<<"                                 ";
								goto H;
							}
							else
							{
								
								if(TimKiem_DMS(DS->sach, text) == 0) // Kiem tra xem ma sach nhap co ton tai
								{
									gotoxy(16,33);
									textcolor(112);					
									cout << "  MA SACH KHONG TON TAI  ";
									int keyhit1 = getch();
									textcolor(15);
									gotoxy(16,33); cout<<"                                 ";
									goto H;
								}
								else
								{	
									Sleep(500);
									Xoa_DMS(DS->sach,text);// ham xoa danh muc sach
									DS->n--;
									break;	
								}
							}
						}
					}
					else 
					{
						dem++;
						text += toupper((char)keyhit);// nhap them ki tu vao cuoi text 
					}
				}
				textcolor(15);
				clrscr();
				goto X;	
			}
			else if(f == 62)
			{
				frameChuThichDanhMucSach(13, 28);
				int u = getch();
				if(u == ESC)
				{
					textcolor(15);
					clrscr();
					goto X;	
				}
			}	
		}
	}
}
 
 int Xoa_DauSach(LDS &l)
{
DauSach:	
	frameDauSach(70, 29);// bang nhap dau sach
	int x = 74, y = 29;// vi tri toa do de lam moc
	int keyhit, dem;
	string text, field;
	field = "";// Khoi tao field rong de nhap du lieu
	keyhit = 0;
	dem = field.length();
	text = field;
	while(1)//Nhap vi tri sach va kiem tra du lieu
	{
		textcolor(253);
		gotoxy(x + 5, y + 1);
		if(dem < 9)// neu chieu dai text nho hon 9
		{
			cout << text;
			for(int i = 1; i < 11 - dem; i++) cout << " ";// chieu dai khong gian de nhap du lieu
		}
		else
		{
			for(int i = dem - 9; i < dem; i++)// neu nhap qua chieu dai khong gian nhap du lieu thi no se day du lieu qua ben phai
				cout << text[i];
		}
		if(dem < 9) gotoxy(x + 5 + dem, y + 1);// ki tu duoc nhap tiep theo nam o vi tri sau ke tiep text
		keyhit = getch();// Kiem tra bat ban phim
		if(keyhit == BACKSPACE)// Nhan phim backspace de xoa ki tu cuoi cung
		{
			if(dem > 0)
			{
				dem--;
				text = text.substr(0, text.size() - 1);// Xoa ki tu cuoi cung
			}
		}
		else if(keyhit == ENTER)//Nhan phim enter
		{
			if(text == "")// du lieu nhap bi rong 
			{
				textcolor(15);
				keyhit = 0;
				gotoxy(72, 32);
				textcolor(112);
				cout << "(VUI LONG NHAP MA ISBN!)";
				int f =getch();
				goto DauSach; 
			}
			else
			{
				textcolor(15);
				if(text.length() > 13)// chieu dai text dai hon 13 ki tu
				{
					gotoxy(72, 32);
					textcolor(112);
					cout << "   (MA ISBN QUA DAI)";
					int f =getch();
					goto DauSach; 
				}
				else
				{
					if(Check_chu(text) == 0)
					{
						gotoxy(72, 32);
						textcolor(112);
						cout << " (MA ISBN PHAI LA SO)";
						int f =getch();
						goto DauSach; 
					}
					else
					{
						if(TimKiemDS(l, text) == -1)// kiem tra xem ma sach co ton tai khong
						{
							gotoxy(72, 32);
							textcolor(112);					
							cout << "(MA ISBN KHONG TON TAI)";
							int f =getch();
							goto DauSach;
						}
						else
						{	
							Sleep(500);
							return TimKiemDS(l,text);// Ham tra ve thu tu dau sach		
						}	
					}
				}
			}
		}
		else if(keyhit == ESC)// thoat
		{
			textcolor(15);
			return -2;
		}
		else 
		{
			dem++;
			text += toupper((char)keyhit);// nhap them ki tu vao cuoi text 

		}
	}
}
 
 int XacNhanXoaDauSach()
{
	int x = 72, y = 25;
	gotoxy(67, 21);
	textcolor(112);
	cout << "                                 ";
	gotoxy(67, 22); cout << "                                 ";
	gotoxy(67, 23); cout << "           BAN MUON XOA          ";
	gotoxy(67, 24); cout << "                                 ";
	gotoxy(67, 25); cout << "     DAU_SACH         DM_SACH    ";
	gotoxy(67, 26); cout << "                                 ";
	int keyhit;
	do{
		gotoxy(72, 25);
		textcolor(121);
		switch(x)
		{
		case 72 : gotoxy(72, 25); cout << "DAU_SACH"; break;
		case 89 : gotoxy(89, 25); cout << "DM_SACH"; break;
		}
		keyhit = getch();
		if(keyhit == LEFT)
		{
			gotoxy(72, 25);
			textcolor(112);
			switch(x)
			{
			case 72 : gotoxy(72, 25); cout << "DAU_SACH"; break;
			case 89 : gotoxy(89, 25); cout << "DM_SACH"; break;
			}
			x -= 17;
			if(x != 72)
			{
				x = 89;
			}
		}
		else if(keyhit == RIGHT)
		{
			gotoxy(72, 25);
			textcolor(112);
			switch(x)
			{
			case 72 : gotoxy(72, 25); cout << "DAU_SACH"; break;
			case 89 : gotoxy(89, 25); cout << "DM_SACH"; break;
			}
			x += 17;
			if(x != 89)
			{
				x = 72;
			}
		}
		else if(x == 72 && keyhit == ENTER)
		{
			return 1;
		}
		else if(x == 89 && keyhit == ENTER)
		{
			return 0;
		}
		else if(x == 72 && keyhit == ESC || x == 89 && keyhit == ESC)
		{
			return 2;
		}
	}while(true);
}
 
 
 int XacNhanThemDauSach()
{
	int x = 72, y = 25;
	gotoxy(67, 21);
	textcolor(112);
	cout << "                                 ";
	gotoxy(67, 22); cout << "                                 ";
	gotoxy(67, 23); cout << "           BAN MUON THEM         ";
	gotoxy(67, 24); cout << "                                 ";
	gotoxy(67, 25); cout << "     DAU_SACH         DM_SACH    ";
	gotoxy(67, 26); cout << "                                 ";
	int keyhit;
	do{
		gotoxy(72, 25);
		textcolor(121);
		switch(x)
		{
		case 72 : gotoxy(72, 25); cout << "DAU_SACH"; break;
		case 89 : gotoxy(89, 25); cout << "DM_SACH"; break;
		}
		keyhit = getch();
		if(keyhit == LEFT)
		{
			gotoxy(72, 25);
			textcolor(112);
			switch(x)
			{
			case 72 : gotoxy(72, 25); cout << "DAU_SACH"; break;
			case 89 : gotoxy(89, 25); cout << "DM_SACH"; break;
			}
			x -= 17;
			if(x != 72)
			{
				x = 89;
			}
		}
		else if(keyhit == RIGHT)
		{
			gotoxy(72, 25);
			textcolor(112);
			switch(x)
			{
			case 72 : gotoxy(72, 25); cout << "DAU_SACH"; break;
			case 89 : gotoxy(89, 25); cout << "DM_SACH"; break;
			}
			x += 17;
			if(x != 89)
			{
				x = 72;
			}
		}
		else if(x == 72 && keyhit == ENTER)
		{
			return 1;
		}
		else if(x == 89 && keyhit == ENTER)
		{
			return 0;
		}
		else if(x == 72 && keyhit == ESC || x == 89 && keyhit == ESC)
		{
			return 2;
		}
	}while(true);
}
 
 void frameSoLuongSachNhapThem(int x, int y)
{
	gotoxy(40, 15);
	textcolor(112);
	gotoxy(x, y - 1); 		cout << "                           ";
	gotoxy(x, y); 			cout << "  SO LUONG SACH NHAP THEM  ";
	gotoxy(x, y + 1);		cout << " ";
	gotoxy(x + 1, y + 1); 	cout << "                         ";
	gotoxy(x + 26, y + 1); 	cout << " ";
	gotoxy(x, y + 2); 		cout << "                           ";
	textcolor(15);
}
 
 void NhapDMSThem(LDMS &l, DAUSACH *DS, int &z, int &n, int &diem)
{
DMS:
	frameViTriSach(93, 20);// bang nhap vi tri sach
	int x = 97, y = 20;// vi tri toa do de lam moc
	int keyhit, dem;
	string text1, field;
	field = "";// Khoi tao field rong de nhap du lieu
	keyhit = 0;
	dem = field.length();
	text1 = field;
	while(1)//Nhap vi tri sach va kiem tra du lieu
	{
		textcolor(253);
		gotoxy(x + 5, y + 1);
		if(dem < 9)// neu chieu dai text nho hon 9
		{
			cout << text1;
			for(int i = 1; i < 11 - dem; i++) cout << " ";// chieu dai khong gian de nhap du lieu
		}
		else
		{
			for(int i = dem - 9; i < dem; i++)// neu nhap qua chieu dai khong gian nhap du lieu thi no se day du lieu qua ben phai
				cout << text1[i];
		}
		if(dem < 9) gotoxy(x + 5 + dem, y + 1);// ki tu duoc nhap tiep theo nam o vi tri sau ke tiep text
		keyhit = getch();// Kiem tra bat ban phim
		if(keyhit == BACKSPACE)// Nhan phim backspace de xoa ki tu cuoi cung
		{
			if(dem > 0)
			{
				dem--;
				text1 = text1.substr(0, text1.size() - 1);// Xoa ki tu cuoi cung
			}
		}
		else if(keyhit == ENTER)// nhan phim enter
		{
			if(text1 == "")// du lieu nhap bi rong 
			{
				textcolor(15);
				keyhit = 0;
				gotoxy(boxx + 20, 25);
				textcolor(112);
				cout << "(VUI LONG NHAP VI TRI)";
				int keyhit = getch();
				textcolor(15);
				gotoxy(boxx + 20, 25); cout<<"                                           ";
				goto DMS; 
			}
			else
			{
				int m =Check_So(text1); //check du lieu phai la so
				if(m == 1)
				{
					textcolor(112);
					gotoxy( 93,25); cout<<"  VI TRI SACH PHAI LA SO  ";
					int keyhit = getch();
					textcolor(15);
					gotoxy( 93,25); cout<<"                                            ";
					goto DMS;
				}
				else
				{
					 int h = atoi((char*)text1.c_str()); // chuyen du lieu keu string sang int
					 for(int i=diem + 1; i<=diem + z; i++) // Tu dong nhap them dms vao
					{
						DanhMucSach data;
						string MS= DS->ISBN;
						string str = convertInt(i);// ma sach la so thu tu duoc ghep voi ISBN de tao ma sach
						string MS1= MS.append("-");
       					MS1.append(str);// them str vao MS1
						data.maSach = MS1;
						data.ttSach = 0;
						data.vitri = h;
						AddTailDMS(l,CreateDMS(data)); //Them dms
						DS->n++;// tang so luong dau sach len 1 don vi
					}
					break;
				}
			}
		}
		else if(keyhit == ESC)//thoat
		{
			n++;
			break;
		}
		else 
		{
			dem++;
			text1 += toupper((char)keyhit);// nhap them ki tu vao cuoi text 

		}
	}
}
 
void Nhap_Them_DMS(LDMS &l,DAUSACH *&DS, int &diem,int &n)
{
	textcolor(15);
	clrscr();
DMS:	
 	Giao_Dien();
	Menu_Tam_Thoi(3);
	Khung_Chuc_Nang();
	gotoxy(20,38); cout<<"ESC: THOAT";
	frameSoLuongSachNhapThem(93, 20);// bang nhap so luong sach nhap them
	int x = 97, y = 20;// vi tri toa do de lam moc
	int keyhit, dem;
	string text, field;
	field = "";// Khoi tao field rong de nhap du lieu
	keyhit = 0;
	dem = field.length();
	text = field;
	while(1)//Nhap vi tri sach va kiem tra du lieu
	{
		textcolor(253);
		gotoxy(x + 5, y + 1);
		if(dem < 9)// neu chieu dai text nho hon 9
		{
			cout << text;
			for(int i = 1; i < 11 - dem; i++) cout << " ";// chieu dai khong gian de nhap du lieu
		}
		else
		{
			for(int i = dem - 9; i < dem; i++)// neu nhap qua chieu dai khong gian nhap du lieu thi no se day du lieu qua ben phai
				cout << text[i];
		}
		if(dem < 9) gotoxy(x + 5 + dem, y + 1);// ki tu duoc nhap tiep theo nam o vi tri sau ke tiep text
		keyhit = getch();// Kiem tra bat ban phim
		if(keyhit == BACKSPACE)// Nhan phim backspace de xoa ki tu cuoi cung
		{
			if(dem > 0)
			{
				dem--;
				text = text.substr(0, text.size() - 1);// Xoa ki tu cuoi cung
			}
		}
		else if(keyhit == ENTER)// nhan phim enter
		{
			if(text == "")// du lieu nhap bi rong 
			{
				textcolor(15);
				keyhit = 0;
				gotoxy(boxx + 18, 25);
				textcolor(112);
				cout << "(VUI LONG NHAP SO LUONG SACH)";
				int keyhit = getch();
				textcolor(15);
				gotoxy(boxx + 18, 25); cout<<"                                     ";
				goto DMS; 
			}
			else
			{
				int m =Check_So(text);//check du lieu phai la so
				if(m == 1)
				{
					textcolor(112);
					gotoxy( 97,25); cout<<"SO LUONG SACH LA SO";
					int keyhit = getch();
					textcolor(15);
					gotoxy(boxx + 18, 25); cout<<"                                     ";
					goto DMS;
				}
				else
				{
					int z = atoi((char*)text.c_str());// chuyen du lieu keu string sang int
					NhapDMSThem(DS->sach,DS,z,n,diem); // ham nhap them dms
					break;
				}
			}
		}
		else if(keyhit == ESC)//thoat
		{ 
			n++;
			break;
		}
		else 
		{
			dem++;
			text += toupper((char)keyhit);// nhap them ki tu vao cuoi text 

		}
	}
}
void Nhap_DMS(LDS &l)
{
	int a = Xoa_DauSach(l); 
	if(a == -2)//truong hop nhan phim ESC trong ham Xoa_DauSach
	{
		textcolor(15);
		clrscr();
		return;
	}
	int c =1;
	int d = 12;
	int diem;
	int demsach;
	textcolor(15);
	clrscr();
	while(1)
	{
DMS:
	int v = 0;
	int m = 1;
	diem = 0;
	int e =0;
	   Giao_Dien();
	   Menu_Tam_Thoi(3);
		for(int i=1; i<50; i++)
		{
			gotoxy(3+i,37);
			cout<<char(220);
		}
		gotoxy(20,38); cout<<"F4: CHU THICH";
    	gotoxy(37,38); cout<<"ESC: THOAT";
    	gotoxy(8,38); cout<<"F1: THEM";
	   Trang_Sau_Truoc_DMS();
	   Khung_Dau_Sach();
	   gotoxy(82,3);
	cout<<"TEN SACH: ";
	gotoxy(82,4);
	cout<<"ISBN: ";
	gotoxy(82,5);
	cout<<"TAC GIA: ";
	gotoxy(82,6);
	cout<<"THE LOAI: ";
	gotoxy(82,7);
	cout<<"SO TRANG: ";
	gotoxy(82,8);
	cout<<"NAM XUAT BAN: ";
	gotoxy(95,10);
	cout << "DANH MUC SACH";
	gotoxy(tabx + 12 , taby + 6);
	cout << char(218);
	for(int i = 1; i < tabs - 24; i++)
	{
		cout << char(196);
	}
	cout << char(191);
	gotoxy(tabx + 31, taby + 6); cout << char(194);
	gotoxy(tabx + 51, taby + 6); cout << char(194);
	gotoxy(tabx + 12, taby + 7); cout << char(179);
	gotoxy(tabx + 31, taby + 7); cout << char(179);
	gotoxy(tabx + 18, taby + 7); cout << "MA SACH";
	gotoxy(tabx + 51, taby + 7); cout << char(179);
	gotoxy(tabx + 36, taby + 7); cout << "TRANG THAI";
	gotoxy(tabx + 70, taby + 7); cout << char(179);
	gotoxy(tabx + 58, taby + 7); cout << "VI TRI";
	   textcolor(15);
	   int dem = 0;
	   gotoxy(92, 3);cout<<l.DS[a]->tenSach;
	   gotoxy(88, 4);cout<<l.DS[a]->ISBN;
	   gotoxy(91, 5);cout<<l.DS[a]->tacGia;
	   gotoxy(92,6);cout<<l.DS[a]->theLoaiSach;
	   gotoxy(92,7);cout<<l.DS[a]->soTrang;
	   gotoxy(96,8);cout<<l.DS[a]->namSB;
	   for(DMSNode *k = l.DS[a]->sach.pHead; k!=NULL; k = k->pNext)// in dms ra man hinh
	   {
	   		diem++;
	   		e++;
	   		if(e>=c && e<=d)
	   		{
	   			v = v +2;
				Table_DMS(k,dem,v,m);
			}
	   }
	   if(v <= 24)
		{
			gotoxy(tabx + 12, taby + 6 + v+2);
			cout << char(192);
			for(int i = 1; i < tabs - 23; i++)
			{
				cout << char(196);
			}
			gotoxy(tabx + 31, taby + 6 +v +2); cout << char(193);
			gotoxy(tabx + 51, taby + 6 +v +2); cout << char(193);
			gotoxy(tabx + 70, taby +6+v+2); cout << char(217);
		}
	   int keyhit = getch();//Kiem tra lenh ban phim
        if(keyhit == 27)//thoat
		{
			break;
		}
		else if(keyhit == 0)//Phim F1
		{
			int f = getch();
			if(f == 59)
			{
				int n = 0;
				textcolor(15);
				clrscr();
				Nhap_Them_DMS(l.DS[a]->sach,l.DS[a], diem,n);
				if(n == 0)
				{
					int x = XacNhanThemDMS();
					if(x == 1)// xac nhan yes
				   {
					   	GhiFileDS(l);
					   	textcolor(15);
					   	clrscr();
					   	goto DMS;
					}
					textcolor(15);
					clrscr();
					goto DMS;		
				}
				else
				{
					textcolor(15);
				 	clrscr();
					goto DMS;
				}
			}
			else if(f == 62)
			{
				frameChuThichDanhMucSach(12, 28);
				int u = getch();
				if(u == ESC)
				{
					textcolor(15);
				 	clrscr();
					goto DMS;
				}
			}
		}
		else if(keyhit == 224)
		{
			int f = getch();
			if(f == 81)// Phim PgDn de xem trang sau ds
			{
				if(e <= d)
				{
					textcolor(15);
					clrscr();
					goto DMS;
				}
				c = d+1;
				d = d +12;
				textcolor(15);
				clrscr();
				goto DMS;
			}
			else if(f == 73)//Phim PgUp de xem trang truoc ds
			{
				if(c == 1 && d == 12)
				{
					textcolor(15);
					clrscr();
					goto DMS;
				}
				c = c-12;
				d = d-12;
				textcolor(15);
				clrscr();
				goto DMS;
			}
		}
	}
}
 
 int XacNhanSuaDauSach()
{
		int x = 72, y = 25;
	gotoxy(67, 21);
	textcolor(112);
	cout << "                                 ";
	gotoxy(67, 22); cout << "                                 ";
	gotoxy(67, 23); cout << "           BAN MUON SUA          ";
	gotoxy(67, 24); cout << "                                 ";
	gotoxy(67, 25); cout << "     DAU_SACH         DM_SACH    ";
	gotoxy(67, 26); cout << "                                 ";
	int keyhit;
	do{
		gotoxy(72, 25);
		textcolor(121);
		switch(x)
		{
		case 72 : gotoxy(72, 25); cout << "DAU_SACH"; break;
		case 89 : gotoxy(89, 25); cout << "DM_SACH"; break;
		}
		keyhit = getch();
		if(keyhit == LEFT)
		{
			gotoxy(72, 25);
			textcolor(112);
			switch(x)
			{
			case 72 : gotoxy(72, 25); cout << "DAU_SACH"; break;
			case 89 : gotoxy(89, 25); cout << "DM_SACH"; break;
			}
			x -= 17;
			if(x != 72)
			{
				x = 89;
			}
		}
		else if(keyhit == RIGHT)
		{
			gotoxy(72, 25);
			textcolor(112);
			switch(x)
			{
			case 72 : gotoxy(72, 25); cout << "DAU_SACH"; break;
			case 89 : gotoxy(89, 25); cout << "DM_SACH"; break;
			}
			x += 17;
			if(x != 89)
			{
				x = 72;
			}
		}
		else if(x == 72 && keyhit == ENTER)
		{
			return 1;
		}
		else if(x == 89 && keyhit == ENTER)
		{
			return 0;
		}
		else if(x == 72 && keyhit == ESC || x == 89 && keyhit == ESC)
		{
			return 2;
		}
	}while(true);
}

int XacNhanSua()
{
	int x = 93, y = 19;
	gotoxy(88, 20);
	textcolor(112);
	cout << "                                 ";
	gotoxy(88, 21); cout << "                                 ";
	gotoxy(88, 22); cout << "  BAN CO CHAC CHAN SUA HAY KHONG?";
	gotoxy(88, 23); cout << "                                 ";
	gotoxy(88, 24); cout << "     YES                NO       ";
	gotoxy(88, 25); cout << "                                 ";
	int keyhit;
	do{
		gotoxy(93, 29);
		textcolor(121);
		switch(x)
		{
		case 93 : gotoxy(93, 24); cout << "YES"; break;
		case 112 : gotoxy(112, 24); cout << "NO"; break;
		}
		keyhit = getch();
		if(keyhit == LEFT)
		{
			gotoxy(93, 24);
			textcolor(112);
			switch(x)
			{
			case 93 : gotoxy(93, 24); cout << "YES"; break;
			case 112 : gotoxy(112, 24); cout << "NO"; break;
			}
			x -= 19;
			if(x != 93)
			{
				x = 112;
			}
		}
		else if(keyhit == RIGHT)
		{
			gotoxy(93, 24);
			textcolor(112);
			switch(x)
			{
			case 93 : gotoxy(93, 24); cout << "YES"; break;
			case 112 : gotoxy(112,24); cout << "NO"; break;
			}
			x += 19;
			if(x != 112)
			{
				x = 93;
			}
		}
		else if(x == 93 && keyhit == ENTER)
		{
			return 1;
		}
		else if(x == 112 && keyhit == ENTER)
		{
			return 0;
		}
	}while(true);
}


void Sua_DauSach(LDS &l)
{
	int a = Xoa_DauSach(l);
	if( a == -2)// nhan phim ESC trong ham Xoa_DauSach
	{
		return;
	}
	DAUSACH data;
	int demlop = 0;
	int d = 0;
	while(1)
	{
		textcolor(15);
		clrscr();
		textcolor(15);
		Menu_Tam_Thoi(3);
		Khung_Chuc_Nang();
		gotoxy(23,38); cout<<"ESC: THOAT";
    	Giao_Dien();
		Box_NhapDS();
		textcolor(15);                                        
		gotoxy(72,10);cout <<"                         	NHAP DAU SACH ";
		
		int keyhit, x = 22;
		int demkitu;
		string text, field[6];// Tao 1 mang gom 6 phan tu de nhap du lieu, cho tat ca deu rong
		field[0] = "";
		field[1] = "";
		field[2] = "";
		field[3] = "";
		field[4] = "";
		field[5] = "";

		for(int n = 4, k = 2; k < 7; n += 2, k++)// thuc hien vong lap cho tung phan tu trong mang field
		{
			keyhit = 0;
			demkitu = field[k - 1].length();
			text = field[k - 1];
			Print_Textfield(l.DS[a]->ISBN,2,x); //In ISBN
			while(keyhit != 13)// thuc hien vong lap nhap ki tu den khi nao nhan phim enter
			{
				gotoxy(boxx + x, boxy + n);// Vi tri toa do bat dau nhap du lieu
				if(demkitu < boxs - x)//con trong pham vi nhap
				{
					cout << text;
					for(int i = 1; i < boxs - x + 1 - demkitu; i++)
						cout << " ";
				}
				if(demkitu < boxs - x)
					gotoxy(boxx + x + demkitu, boxy + n);//chuyen sang vi tri tiep theo de nhap ki tu tiep theo
				keyhit = getch();//kiem tra bat ban phim
				if(keyhit == 224)
				{
					keyhit = getch();//Kiem tra lenh bat phim
					if(keyhit == UP)// di len
					{
						if(k == 1) text = Fix_ISBN(text); //Chuan hoa du lieu
						if(k == 2) text = Fix_Tensach(text); // Chuan hoa du lieu
						if(k == 3) text = Fix_Tensach(text);
						Print_Textfield(text, n, x);// in du lieu ra man hinh
						field[k - 1] = text;
						if(k > 2)
						{
							n -= 2;
							k--;
						}
						demkitu = field[k - 1].length();// dem chieu dai field
						text = field[k -1]; // Gan field cho text
					}
					else if(keyhit == DOWN)// di xuong
					{
						keyhit = 0;
						if(CheckLoi_DS(text, k, l) != 0)
						{
							keyhit = 0;
							Print_Error_DS(CheckLoi_DS(text, k, l));// in loi du lieu ra man hinh
							Print_Textfield(text, n, x);// in du lieu ra man hinh
						}
						else
						{
							if(k == 1) text = Fix_ISBN(text);// chuan hoa du lieu
							if(k == 2) text = Fix_Tensach(text); // chuan hoa du lieu
							if(k == 3) text = Fix_Tensach(text);
							Print_Textfield(text, n, x);// in du lieu ra man hinh
							field[k - 1] = text;
							if(k < 6)
							{
								n += 2;
								k++;
							}
							demkitu = field[k - 1].length(); // chieu dai field
							text = field[k -1];// gan field cho text
							
							if(keyhit == DOWN) // di xuong
							{
								Print_Textfield(text, n, x);// in du lieu ra man hinh
							}
						}	
					}
				}
				else if(keyhit == BACKSPACE)// xoa ki tu cuoi cung
				{
					if(demkitu > 0)
					{
						demkitu--;
						text = text.substr(0, text.size() - 1);// ham xoa ki tu cuoi cung
					}
				}
				else if(keyhit == ESC)//thoat
				{
						d++;
						break;
				}
				else if(keyhit == ENTER)// nhan phim enter
				{
					if(CheckLoi_DS(text, k, l) != 0) // check loi du lieu
					{
						keyhit = 0;
						Print_Error_DS(CheckLoi_DS(text, k, l)); // in loi ra man hinh
						Print_Textfield(text, n, x);// in du lieu ra man hinh
						Sleep(500);
					}
					else
					{
						if(k == 1) text = Fix_ISBN(text);// chuan hoa du lieu
						if(k == 2) text = Fix_Tensach(text); // chuan hoa du lieu
					}
				}
				else 
				{
					demkitu++;
					text += char(keyhit);// nhap them ki tu vao cuoi text
				}
			}
			if(keyhit == ESC)//thoat
			{
				textcolor(15);
				Sleep(500);
				break;
			}
			Print_Textfield(text, n, x);// in du lieu ra man hinh
			field[k - 1] = text;
			if(d!=0)
			{
				break;
			}
		}
		if(keyhit == ENTER)// nhan phim enter
		{
			int z = XacNhanSua();// ham xac nhan
			if(z == 1)// nhan gia trij yes
			{
				textcolor(15);
		    	l.DS[a]->ISBN = l.DS[a]->ISBN;
		    	l.DS[a]->tenSach = field[1];
		    	l.DS[a]->tacGia = field[2];
		    	l.DS[a]->theLoaiSach = field[3];
		      	l.DS[a]->soTrang = field[4];
			    l.DS[a]->namSB = field[5];
			    l.DS[a]->n = l.DS[a]->n;
				GhiFileDS(l);
				gotoxy(boxx + 24 , 19); cout << "SUA THANH CONG";
			}
			Sleep(500);
			break;
		}
		break;
	}
}
 
 void SuaDMS(LDS &l, DAUSACH *&DS, string a)
{
	DanhMucSach data;
	int demlop = 0;
	while(1)
	{
		clrscr();
		Menu_Tam_Thoi(3);
    	Giao_Dien();
    	Khung_Chuc_Nang();
    	gotoxy(23,38); cout<<"ESC: THOAT";
		Box_NhapDMS();
		textcolor(15);                                       
		gotoxy(80,9);cout <<"                  DANH MUC SACH";   
		int keyhit, x = 22;
		int demkitu;
		string text, field[4];// Tao 1 mang gom 3 phan tu de nhap du lieu, cho tat ca deu rong
		field[0] = "";
		field[1] = "";
		field[2] = "";
		for(int n = 6, k = 3; k < 4; n += 2, k++)// thuc hien vong lap cho tung phan tu trong mang field
		{
			keyhit = 0;
			demkitu = field[k - 1].length();// chieu dai cua field
			text = field[k - 1];// gan field cho text
			Print_Textfield(a,2,x);// in du lieu ra man hinh
			Print_Textfield(convertInt(0),4,x);// in du lieu ra man hinh
			while(keyhit != 13)// nhan lenh phim, dung khi nhan phim enter
			{
				gotoxy(boxx + x, boxy + n);// Vi tri toa do bat dau nhap du lieu
				if(demkitu < boxs - x) // con trong pham vi nhap
				{
					cout << text;
					for(int i = 1; i < boxs - x + 1 - demkitu; i++)
						cout << " ";
				}
				if(demkitu < boxs - x)
					gotoxy(boxx + x + demkitu, boxy + n);//chuyen sang vi tri tiep theo de nhap ki tu tiep theo
				keyhit = getch();// kiem tra bat ban phim
				if(keyhit == BACKSPACE)// Xoa ki tu cuoi cung cua text
				{
					if(demkitu > 0)
					{
						demkitu--;
						text = text.substr(0, text.size() - 1);// Ham xoa ki tu cuoi
					}
				}
				else if(keyhit == ESC)//thoat
				{
					break;
				}
				else if(keyhit == ENTER)//nhan phim enter
				{
					if(Check_So(text) != 0)// check du lieu co phai la so
					{
						keyhit = 0;
						gotoxy(boxx + 20 , 22); cout << "VI TRI PHAI LA SO";
						Print_Textfield(text, n, x);// in du lieu ra man hinh
					}
				}
				else 
				{
					demkitu++;
					text += char(keyhit);
				}
			}
			if(keyhit == ESC)
			{
				textcolor(15);
					break;
			}
			Print_Textfield(text, n, x);// in du lieu ra man hinh
			field[k - 1] = text;
		}
		if(keyhit == ESC)// thoat
		{
			break;
		}
		if(keyhit == ENTER)// nha phim enter
		{
			int m =XacNhanSua();
			if(m == 1)
			{
			    for(DMSNode *p = DS->sach.pHead; p!=NULL; p=p->pNext)// duyet danh muc sach
		     	{
			    	if(p->data.maSach == a)
				    {
				    	p->data.maSach= a;
				    	p->data.ttSach = atoi((char*)field[1].c_str());// chuyen field tu string sang int
				    	p->data.vitri = atoi((char*)field[2].c_str());// chuyen field tu string sang int
			    	}
		     	}
		     	GhiFileDS(l);	
				textcolor(15);
				gotoxy(boxx + 24 , 32); cout << "SUA THANH CONG";
				Sleep(500);
		    	break;	
			}
			break;
		}
		break;
			}
}

void Sua_DMS(LDS &l)
{
	int a = Xoa_DauSach(l); // a la thu tu dau sach
	if(a == -2)// nha duoc phim ESC trong ham Sua
	{
		textcolor(15);
		clrscr();
		return;
	}
	textcolor(15);
	clrscr();
	int q =1;
	int n = 12;
	while(1)// vong lap in danh sach
	{
DMS:
	int v = 0;
	int m = 1;
	int p = 0;
	   textcolor(15);
	 //  LoadFileDS(l);
	   Menu_Tam_Thoi(3);
	   Khung_Dau_Sach();
	   Trang_Sau_Truoc_DMS();
	   for(int i=1; i<50; i++)
		{
			gotoxy(3+i,37);
			cout<<char(220);
		}
		gotoxy(25,38); cout<<"F4: CHU THICH";
    	gotoxy(40,38); cout<<"ESC: THOAT";
    	gotoxy(6,38); cout<<"F1: NHAP MA SACH";
    	Giao_Dien();
    	gotoxy(82,3);
	cout<<"TEN SACH: ";
	gotoxy(82,4);
	cout<<"ISBN: ";
	gotoxy(82,5);
	cout<<"TAC GIA: ";
	gotoxy(82,6);
	cout<<"THE LOAI: ";
	gotoxy(82,7);
	cout<<"SO TRANG: ";
	gotoxy(82,8);
	cout<<"NAM XUAT BAN: ";
	gotoxy(95,10);
	cout << "DANH MUC SACH";
	gotoxy(tabx + 12 , taby + 6);
	cout << char(218);
	for(int i = 1; i < tabs - 24; i++)
	{
		cout << char(196);
	}
	cout << char(191);
	gotoxy(tabx + 31, taby + 6); cout << char(194);
	gotoxy(tabx + 51, taby + 6); cout << char(194);
	gotoxy(tabx + 12, taby + 7); cout << char(179);
	gotoxy(tabx + 31, taby + 7); cout << char(179);
	gotoxy(tabx + 18, taby + 7); cout << "MA SACH";
	gotoxy(tabx + 51, taby + 7); cout << char(179);
	gotoxy(tabx + 36, taby + 7); cout << "TRANG THAI";
	gotoxy(tabx + 70, taby + 7); cout << char(179);
	gotoxy(tabx + 58, taby + 7); cout << "VI TRI";
	   textcolor(15);
	   int dem = 0;
	   gotoxy(92, 3);cout<<l.DS[a]->tenSach;
	   gotoxy(88, 4);cout<<l.DS[a]->ISBN;
	   gotoxy(91, 5);cout<<l.DS[a]->tacGia;
	   gotoxy(92, 6);cout<<l.DS[a]->theLoaiSach;
	   gotoxy(92, 7);cout<<l.DS[a]->soTrang;
	   gotoxy(96, 8);cout<<l.DS[a]->namSB;
	   for(DMSNode *k = l.DS[a]->sach.pHead; k!=NULL; k = k->pNext)// in danh muc sach
	   {
	   	p++;
	   	if(p>=q && p<=n)
	   	{
	   		v = v +2;
			Table_DMS(k,dem,v,m);	
		}
	   }
	   if(v <= 24)
		{
			gotoxy(tabx + 12, taby + 6 + v+2);
			cout << char(192);
			for(int i = 1; i < tabs - 23; i++)
			{
				cout << char(196);
			}
			gotoxy(tabx + 31, taby + 6 +v +2); cout << char(193);
			gotoxy(tabx + 51, taby + 6 +v +2); cout << char(193);
			gotoxy(tabx + 70, taby +6+v+2); cout << char(217);
		}
	   int c = getch();// kiem tra bat phim
		if(c == 224)
		{
			int f = getch();
			if(f == 81)//phim PgDn de xem trang sau
			{
				if(p <= n)
				{
					textcolor(15);
					clrscr();
					goto DMS;
				}
				q = n+1;
				n = n+12;
				textcolor(15);
				clrscr();
				goto DMS;
			}
			else if(f == 73)// Phim PgUp de xem trang truoc
			{
				if(q == 1 && n == 12)
				{
					textcolor(15);
					clrscr();
					goto DMS;
				}
				q = q - 12;
				n = n - 12;
				textcolor(15);
				clrscr();
				goto DMS;
			}
		}
		else if(c == 27)//thoat
		{
			textcolor(15);
			clrscr();
			break;
		}
		else if(c == 0)//Phim F1
		{
			int f = getch();
			if(f == 59)
			{
			G:
				frameMaSach(15,28);// bang nhap ma sach
				int x = 19, y = 28;// vi tri toa do de lam moc
				int keyhit, dem;
				string text, field;
				field = "";	// Khoi tao field rong de nhap du lieu
				keyhit = 0;
				dem = field.length();
				text = field;
				while(1)//Nhap vi tri sach va kiem tra du lieu
				{
					textcolor(253);
					gotoxy(x + 5, y + 1);
					if(dem < 9)// neu chieu dai text nho hon 9
					{
						cout << text;
						for(int i = 1; i < 11 - dem; i++) cout << " ";// chieu dai khong gian de nhap du lieu
					}
					else
					{
						for(int i = dem - 9; i < dem; i++)// neu nhap qua chieu dai khong gian nhap du lieu thi no se day du lieu qua ben phai
						cout << text[i];
					}
					if(dem < 9) gotoxy(x + 5 + dem, y + 1);// ki tu duoc nhap tiep theo nam o vi tri sau ke tiep text
					keyhit = getch();// Kiem tra bat ban phim
					if(keyhit == BACKSPACE)// Nhan phim backspace de xoa ki tu cuoi cung
					{
						if(dem > 0)
						{
							dem--;
							text = text.substr(0, text.size() - 1);// Xoa ki tu cuoi cung
						}
					}
					else if(keyhit == ESC)//Nhan phim thoat
					{
						textcolor(15);
						clrscr();
						break;
					}
					else if(keyhit == ENTER)//Nhan phim enter
			 		{
						if(text == "")// du lieu nhap bi rong 
						{
							textcolor(15);
							gotoxy(17, 32);
							textcolor(112);
							cout << "(VUI LONG NHAP MA SACH!)";// bi Table_DMS chen len tren
							int keyhit1 = getch();
							textcolor(15);
							gotoxy(17, 32);cout<< "                         ";
							goto G;
						}
						else
						{
							textcolor(15);
							if(text.length() > 25)//chieu dai text > 25
							{
								gotoxy(21, 32);
								textcolor(112);
								cout << "(MA SACH QUA DAI)";
								int keyhit1 = getch();
								textcolor(15);
						    	gotoxy(21, 32);cout<< "                         ";
								goto G;	
							}
							else
							{
								if(TimKiem_DMS(l.DS[a]->sach, text) == 0)//kiem tra ma sach duoc nhap co ton tai khong
								{
									gotoxy(17, 32);
									textcolor(112);					
									cout << "(MA SACH KHONG TON TAI)";
									int keyhit1 = getch();
									textcolor(15);
						        	gotoxy(17, 32);cout<< "                         ";
									goto G;
								}
								else
								{	
									Sleep(500);
								    SuaDMS(l,l.DS[a],text);// ham sua dms
									textcolor(15);
									clrscr();
								    goto DMS;
								}
							}
						}
					}
					else 
					{
						dem++;
						text += toupper((char)keyhit);// nhap them ki tu vao cuoi text
					}
				}
			}
			else if(f == 62)
			{
				frameChuThichDanhMucSach(13, 28);
				int u = getch();
				if(u == ESC)
				{
					textcolor(15);
					clrscr();
					goto DMS;	
				}
			}	
		}
	}
}

void Giao_DienDS() // Ve khung giao dien 
{
	///////////////////
	gotoxy(1,0);
	for(int i=1; i<157; i++)
	{
		cout<<char(220);
	}
	for(int i=1; i<41; i++)
	{
		gotoxy(1,i);
		cout<<char(219);
		gotoxy(156,i);
		cout<<char(219);
	}
	gotoxy(2,40);
	for(int i=1; i<155; i++)
	{
		cout<<char(220);
	}
}

void Khung_Chuc_Nang_DS()
 {
 	gotoxy(67,2);
	for(int i=1; i<35; i++)
	{
		cout<<char(220);
	}
	
	gotoxy(67,12);
	for(int i=1; i<34; i++)
	{
		cout<<char(220);
	}
	for(int i=3; i<13; i++)
	{
		gotoxy(67,i);
		cout<<char(219);
		gotoxy(100,i);
		cout<<char(219);
	}
 }

void Trang_Sau_Truoc_DS()
{
	gotoxy(2,38);
	for(int i=1; i<30; i++)
	{
		cout<<char(220);
	}
	gotoxy(127,39);
	cout<<char(221);
	gotoxy(134,39);
	cout<<"PgDn: TRANG SAU";
	gotoxy(127,38);
	for(int i=1; i<30; i++)
	{
		cout<<char(220);
	}
	gotoxy(30,39);
	cout<<char(222);
	gotoxy(7,39);
	cout<<"PgUp: TRANG TRUOC";
	gotoxy(55,38);
	for(int i=1; i<47; i++)
	{
		cout<<char(220);
	}
	gotoxy(55,39);
	cout<<char(221);
	gotoxy(100,39);
	cout<<char(222);
	gotoxy(57,39);
	cout<<"F1: THEM";
	gotoxy(68,39);
	cout<<"F2: XOA";
	gotoxy(79,39);
	cout<<"F3: SUA";
	gotoxy(88,39);
	cout<<"ESC: THOAT";
}

 void NhapDanhSachDS(LDS &l)
{
	int a = 1;
	int b = 10;
	textcolor(15);
	clrscr();
	while(1)
	{
Xuat :
		int v = 0;
		int m = 1;
		int d = 0;
		textcolor(15);
		Khung_Chuc_Nang_DS();
		Trang_Sau_Truoc_DS();
    	Giao_DienDS();
    	
    	int x = 70;
		int y = 7;
		int keyhit;
		char menu_text[12][100] = { " 1. THEM DAU SACH", " 2. XOA DAU SACH ", " 3. SUA DAU SACH", " 4. THOAT "};
	    gotoxy(69, 4); cout <<     "        MENU CHUC NANG "; 
	    gotoxy(69,5); cout<<"    ---------------------";
	    gotoxy(x, 7); cout << menu_text[0];
		gotoxy(x, 8); cout << menu_text[1];
		gotoxy(x, 9); cout << menu_text[2];
		gotoxy(x, 10); cout << menu_text[3];
		gotoxy(75,14);
		cout << "DANH SACH DAU SACH";
		gotoxy(taxx, taxy);
		cout << char(218);
		for(int i = 1; i < taxs; i++)
		{
			cout << char(196);
		}
		cout << char(191);
		gotoxy(taxx + 15, taxy); cout << char(194);
		gotoxy(taxx + 57, taxy); cout << char(194);
		gotoxy(taxx + 89, taxy); cout << char(194);
		gotoxy(taxx + 121, taxy); cout << char(194);
		gotoxy(taxx + 131, taxy); cout << char(194);
		gotoxy(taxx + 139, taxy); cout << char(194);
		gotoxy(taxx , taxy + 1); cout << char(179);
		gotoxy(taxx + 6 , taxy + 1); cout << "ISBN";
		gotoxy(taxx + 15, taxy + 1); cout << char(179);
		gotoxy(taxx + 31, taxy + 1); cout << "TEN SACH";
		gotoxy(taxx + 57, taxy + 1); cout << char(179);
		gotoxy(taxx + 70, taxy + 1); cout << "TAC GIA";
		gotoxy(taxx + 89, taxy + 1); cout << char(179);
		gotoxy(taxx + 102, taxy + 1); cout << "THE LOAI";
		gotoxy(taxx + 121, taxy + 1); cout << char(179);
		gotoxy(taxx + 122, taxy + 1); cout << "SO TRANG";
		gotoxy(taxx + 131, taxy + 1); cout << char(179);
		gotoxy(tabx + 133, taxy + 1); cout << "NAM XB";
		gotoxy(taxx + 139, taxy + 1); cout << char(179);
		gotoxy(tabx + 141, taxy + 1); cout << "SL MUON";
		gotoxy(taxx + 147, taxy + 1); cout << char(179);
		int dem = 0;
		textcolor(15);
		for(int i = 0; i < l.n; i++)// vong lap in danh sach Dau sach
		{
			d++;
			if(d>=a && d <= b)
			{
				v = v +2;
				TableDS1(l,i,dem,v,m);	
			}
		}
		if(v <= 20)
		{
			gotoxy(taxx, taxy + v+2);
			cout << char(192);
			for(int i = 1; i < taxs; i++)
			{
				cout << char(196);
			}
			cout << char(217);
			gotoxy(taxx + 15, taxy +v +2); cout << char(193);
			gotoxy(taxx + 57, taxy+v +2); cout << char(193);
			gotoxy(taxx + 89, taxy+v +2); cout << char(193);
			gotoxy(taxx + 121, taxy+v +2); cout << char(193);
			gotoxy(taxx + 131, taxy+v +2); cout << char(193);
			gotoxy(taxx + 139, taxy+v +2); cout << char(193);
		}
	do{
		gotoxy(x, y);
		textcolor(159);// nen mau xanh
		switch (y)
		{
		case 7: gotoxy(x, 7); cout << menu_text[0]; break;
		case 8: gotoxy(x, 8); cout << menu_text[1]; break;
		case 9: gotoxy(x, 9); cout << menu_text[2]; break;
		case 10: gotoxy(x, 10); cout << menu_text[3]; break;
		}
		keyhit = getch(); // Kiem Tra Nhan Lenh Ban Phim
		if (keyhit == UP) // Di Len
		{
			gotoxy(x, y);
			textcolor(15); // Doi thanh mau chu mau trang
			switch (y)
			{
			case 7: gotoxy(x, 7); cout << menu_text[0]; break;
			case 8: gotoxy(x, 8); cout << menu_text[1]; break;
			case 9: gotoxy(x, 9); cout << menu_text[2]; break;
			case 10: gotoxy(x,10); cout << menu_text[3]; break;
			}
			y--;
			if (y < 7)
			{
				y = 10;
			}
		}
		else if (keyhit == DOWN)
		{
			gotoxy(x, y);
			textcolor(15);
			switch (y)
			{
			case 7: gotoxy(x, 7); cout << menu_text[0]; break;
			case 8: gotoxy(x, 8); cout << menu_text[1]; break;
			case 9: gotoxy(x, 9); cout << menu_text[2]; break;
			case 10: gotoxy(x,10); cout << menu_text[3]; break;
			}
			y++;
			if (y > 10)
			{
				y = 7;
			}
		}
	if (y == 7 && keyhit == ENTER)//Them
		{
			int k;
			k = XacNhanThemDauSach();
			if(k == 2)// nhan phim ESC
			{
				textcolor(15);
			    clrscr();
				goto Xuat;
			}
			else if(k == 1) // Them Dau sach
			{
				textcolor(15);
				int m = 0;
				NhapDS(l,m);
				if(m != 0)
				{
					GhiFileDS(l);
				}
				textcolor(15);
				clrscr();
				goto Xuat;
			}
			else if(k == 0)//Them DMS
			{
			    Nhap_DMS(l);
				textcolor(15);
			    clrscr();
			    goto Xuat;
			}
		}
	else if( y == 8 && keyhit == ENTER)//Xoa
	{
			int k;
			k = XacNhanXoaDauSach();
			if(k == 2)//Nhan ESC
			{
				textcolor(15);
			    clrscr();
				goto Xuat;
			}
			else if(k == 1)//xoa dau sach
			{
				int x;
				x = Xoa_DauSach(l);
				if(x == -2)
				{
					textcolor(15);
				    clrscr();
					goto Xuat;
				}
				int b = XacNhanXoa();
				if(b == 1)//nhan yes
				{
					XoaDS(l,x);
					GhiFileDS(l);
				}
				
			}
			else//Xoa DMS
			{
				int x;
				x = Xoa_DauSach(l);
				if(x == -2)
				{
					textcolor(15);
				    clrscr();
					goto Xuat;
				}
				XoaDanhMucSach(l.DS[x]);
				int y = XacNhanSaveFile();
				if(y == 1)// nhan yes
				{
					GhiFileDS(l);
				}
				textcolor(15);
			    clrscr();
			    goto Xuat;
			}
			textcolor(15);
			clrscr();
			goto Xuat;
	}
	
	else if( y == 9 && keyhit == ENTER)//Sua 
	{
		int k;
			k = XacNhanSuaDauSach();
			if(k == 2)//nhan ESC
			{
				textcolor(15);
			    clrscr();
				goto Xuat;
			}
			else if(k == 1)//Sua Dau Sach
			{
				Sua_DauSach(l);
			}
			else//Sua DMS
			{
				Sua_DMS(l);
				goto Xuat;
			}
			textcolor(15);
			clrscr();
			goto Xuat;
	}
	else if( y == 10 && keyhit == ENTER)//thoat
	{
		textcolor(15);
		clrscr();
	    Menu();
	}
	else if(keyhit == 59)//Nhan Phim F1 de them
		{
			int k;
			k = XacNhanThemDauSach();
			if(k == 2)//ESC
			{
				textcolor(15);
			    clrscr();
				goto Xuat;
			}
			else if(k == 1)//Them Dau sach
			{
				int m =0;
				textcolor(15);
				NhapDS(l,m);
				if(m != 0)
				{
					GhiFileDS(l);
				}
				textcolor(15);
				clrscr();
				goto Xuat;
			}
			else if(k == 0)//Them DMS
			{
			    Nhap_DMS(l);
			    textcolor(15);
			    clrscr();
			    goto Xuat;
			}
		}
		else if(keyhit == 60)
		{
			int k;
			k = XacNhanXoaDauSach();
			if(k == 2)//Nhan ESC
			{
				textcolor(15);
			    clrscr();
				goto Xuat;
			}
			else if(k == 1)//xoa dau sach
			{
				int x;
				x = Xoa_DauSach(l);
				if(x == -2)
				{
					textcolor(15);
				    clrscr();
					goto Xuat;
				}
				int b = XacNhanXoa();
				if(b == 1)//nhan yes
				{
					XoaDS(l,x);
					GhiFileDS(l);
				}
				
			}
			else//Xoa DMS
			{
				int x;
				x = Xoa_DauSach(l);
				if(x == -2)
				{
					textcolor(15);
				    clrscr();
					goto Xuat;
				}
				XoaDanhMucSach(l.DS[x]);
				int y = XacNhanSaveFile();
				if(y == 1)// nhan yes
				{
					GhiFileDS(l);
				}
				
			}
			textcolor(15);
			clrscr();
			goto Xuat;
			goto Xuat;
		}
		else if(keyhit == 61)
		{
				int k;
			k = XacNhanSuaDauSach();
			if(k == 2)//nhan ESC
			{
				textcolor(15);
			    clrscr();
				goto Xuat;
			}
			else if(k == 1)//Sua Dau Sach
			{
				Sua_DauSach(l);
			}
			else//Sua DMS
			{
				Sua_DMS(l);
				goto Xuat;
			}
			textcolor(15);
			clrscr();
			goto Xuat;
		}		
		else if(keyhit == 27)//Thoat
		{
			textcolor(15);
			clrscr();
		    Menu();
		}
		else if(keyhit == 81)//Nhan Phim PgDn de xem trang sau
		{
			if(d<=b)
			{
				textcolor(15);
				clrscr();
				goto Xuat;
			}
			a = b+1;
			b = b +10;
			textcolor(15);
			clrscr();
			goto Xuat;
		}
		else if(keyhit == 73)//Nhan Phim PgUp de xem trang truoc
		{
			if(a == 1 && b == 10)
			{
				textcolor(15);
				clrscr();
				goto Xuat;
			}
			a = a-10;
			b = b-10;
			textcolor(15);
			clrscr();
			goto Xuat;
		}
	}while(true);
	}
}
 //**********************************  Xuat Danh Sach Sach   ********************************
 void TableDS2(DAUSACH *arr[], int j, int &dem, int &v, int &m)
 {
	gotoxy(taxx,taxy - 12);
	for(int i = m; i< v; i++)
	{
		if(i %2 == 1)
		{
			gotoxy(taxx + 1,taxy+i - 11);
			for(int k = 1; k<taxs; k++)
			{
				cout << char(196);
			}
			gotoxy(taxx,taxy+i -11);
			cout<<char(195);
			gotoxy(taxx + 15,taxy+i - 11);
			cout<<char(197);
			gotoxy(taxx +57,taxy+i-11);
			cout<<char(197);
			gotoxy(taxx +89,taxy+i-11);
			cout<<char(197);
			gotoxy(taxx +121,taxy+i-11);
			cout<<char(197);
			gotoxy(taxx +131,taxy+i-11);
			cout<<char(197);
			gotoxy(taxx +139,taxy+i-11);
			cout<<char(197);
			gotoxy(taxx + 147,taxy+i-11);
			cout<<char(180);
			gotoxy(taxx, taxy +i -10); cout << char(179);
			gotoxy(taxx + 15, taxy + i -10); cout << char(179);
			gotoxy(taxx + 57, taxy + +i -10); cout << char(179);
			gotoxy(taxx + 89, taxy + i-10); cout << char(179);
			gotoxy(taxx + 121, taxy + i -10); cout << char(179);
			gotoxy(taxx + 131, taxy + i-10); cout << char(179);
			gotoxy(taxx + 139, taxy + i-10); cout << char(179);
			gotoxy(taxx + 147, taxy + i-10); cout << char(179);
			gotoxy(taxx + 1, 6 + dem); cout << arr[j]->ISBN;
			gotoxy(taxx + 16, 6 + dem); cout <<arr[j]->tenSach;
			gotoxy(taxx + 58, 6 + dem); cout << arr[j]->tacGia;
			gotoxy(taxx + 90, 6 + dem); cout << arr[j]->theLoaiSach;
			gotoxy(taxx + 125, 6 + dem); cout << arr[j]->soTrang;
			gotoxy(taxx + 134, 6 + dem); cout << arr[j]->namSB;
			gotoxy(taxx + 142, 6 + dem); cout << arr[j]->solanmuon;
			dem = dem + 2;
			m = v;
			Sleep(50);
		}
	}
 }
 
 void Trang_Sau_Truoc_DS1()
{
	gotoxy(2,38);
	for(int i=1; i<30; i++)
	{
		cout<<char(220);
	}
	gotoxy(127,39);
	cout<<char(221);
	gotoxy(134,39);
	cout<<"PgDn: TRANG SAU";
	gotoxy(127,38);
	for(int i=1; i<30; i++)
	{
		cout<<char(220);
	}
	gotoxy(30,39);
	cout<<char(222);
	gotoxy(7,39);
	cout<<"PgUp: TRANG TRUOC";
	gotoxy(55,38);
	for(int i=1; i<47; i++)
	{
		cout<<char(220);
	}
	gotoxy(55,39);
	cout<<char(221);
	gotoxy(100,39);
	cout<<char(222);
	gotoxy(73,39);
	cout<<"ESC: THOAT";
}
 
void Sap_Xep_Theo_The_Loai(LDS &l, string a)
{
   /* for(int i=1; i<50; i++)
	{
		gotoxy(3+i,37);
		cout<<char(220);
	}*/
  //  gotoxy(23,38); cout<<"ESC: THOAT";
	textcolor(15);
	DAUSACH *arr[500];//Tao mang arr
	int sp = -1;// Khoi tao so luong ban dau
	for(int i=0; i<l.n; i++)// dua danh sach dau sach co cung the loai sach vao mang arr
	{
		if(l.DS[i]->theLoaiSach == a)
		{
			arr[++sp] = l.DS[i];
		}
	}
	for(int i=0; i<=sp; i++)//duyet mang arr
	{
		for(int j= i+1; j<=sp; j++)
		{
			if(arr[i]->tenSach > arr[j]->tenSach)
			{
				//Hoan doi thu tu
				DAUSACH *temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	int c = 1;
	int d = 15;
	while(1)
	{
		Xuat:
			int v = 0;
			int m = 1;
			int e = 0;
			int dem = 0;
			Giao_DienDS();
 			Trang_Sau_Truoc_DS1();
 		  	gotoxy(70,2);
			cout << "DANH SACH DAU SACH";
			gotoxy(taxx, taxy - 12);
			cout << char(218);
			for(int i = 1; i < taxs; i++)
			{
				cout << char(196);
			}
			cout << char(191);
			gotoxy(taxx + 15, taxy - 12); cout << char(194);
			gotoxy(taxx + 57, taxy - 12); cout << char(194);
			gotoxy(taxx + 89, taxy -12); cout << char(194);
			gotoxy(taxx + 121, taxy -12); cout << char(194);
			gotoxy(taxx + 131, taxy -12); cout << char(194);
			gotoxy(taxx + 139, taxy -12); cout << char(194);
			gotoxy(taxx , taxy - 11); cout << char(179);
			gotoxy(taxx +5, taxy - 11); cout << "ISBN";
			gotoxy(taxx + 15, taxy - 11); cout << char(179);
			gotoxy(taxx + 30, taxy - 11); cout << "TEN SACH";
			gotoxy(taxx + 57, taxy - 11); cout << char(179);
			gotoxy(taxx + 69, taxy - 11); cout << "TAC GIA";
			gotoxy(taxx + 89, taxy - 11); cout << char(179);
			gotoxy(taxx + 101, taxy - 11); cout << "THE LOAI";
			gotoxy(taxx + 121, taxy - 11); cout << char(179);
			gotoxy(taxx + 123, taxy - 11); cout << "SO TRANG";
			gotoxy(taxx + 131, taxy - 11); cout << char(179);
			gotoxy(taxx + 132, taxy - 11); cout << "NAM XB";
			gotoxy(taxx + 139, taxy - 11); cout << char(179);
			gotoxy(taxx + 140, taxy - 11); cout << "SL MUON";
			gotoxy(taxx + 147, taxy - 11); cout << char(179);
			textcolor(15);
			for(int i = 0; i <= sp; i++) //In danh sach theo the loai sach
			{
				e++;	
					if(e>=c && e <= d)
					{
						v = v +2;
						TableDS2(arr,i,dem,v,m);	
					}
			}
			if(v <= 30)
			{
				gotoxy(taxx, taxy + v - 10);
				cout << char(192);
				for(int i = 1; i < taxs; i++)
				{
					cout << char(196);
				}
				cout << char(217);
				gotoxy(taxx + 15, taxy +v -10); cout << char(193);
				gotoxy(taxx + 57, taxy+v -10); cout << char(193);
				gotoxy(taxx + 89, taxy+v -10); cout << char(193);
				gotoxy(taxx + 121, taxy+v -10); cout << char(193);
				gotoxy(taxx + 131, taxy+v -10); cout << char(193);
				gotoxy(taxx + 139, taxy+v -10); cout << char(193);
			}
			int keyhit = getch();//Kiem tra Bat phim
	        if(keyhit == 27)//Thoat
			{
				clrscr();			
				textcolor(15);
				clrscr();
				break;
			}	
			else if(keyhit == 224)
			{
				int f = getch();
				if(f == 81)//Phim PgDn de xem trang sau
				{
					if(e<=d)
					{
						textcolor(15);
						clrscr();
						goto Xuat;
					}
					c = d+1;
					d = d +15;
					textcolor(15);
					clrscr();
					goto Xuat;
				}
				else if(f == 73)//Phim PgUp de xem trang truoc
				{
					if(c == 1 && d == 15)
					{
						textcolor(15);
						clrscr();
						goto Xuat;
					}
					d = c-15;
					d = d-15;
					textcolor(15);
					clrscr();
					goto Xuat;
				}	
			}
	}
}


int Tim_Kiem_The_Loai_Sach(LDS l, string a)//Ham tim kiem the loai sach
{
	for(int i=0; i<l.n; i++)//duyet danh sach
	{
		if(l.DS[i]->theLoaiSach == a)// neu the loai co trong danh sach thi return 1
		{
			return 1;
		}
	}
	return 0;
}

void frameTheLoai(int x, int y)
{
	gotoxy(4, 15);
	textcolor(112);
	gotoxy(x, y - 1); 		cout << "                           ";
	gotoxy(x, y); 			cout << "     NHAP VAO THE LOAI     ";
	gotoxy(x, y + 1);		cout << " ";
	gotoxy(x + 1, y + 1); 	cout << "                         ";
	gotoxy(x + 26, y + 1); 	cout << " ";
	gotoxy(x, y + 2); 		cout << "                           ";
	textcolor(15);
}
 /////////////////////////////////////////////////
 void Bang_The_Loai(string theloai,int &dem, int &v, int &m,int &dem1)
 {
	
	gotoxy(tabx + 15,taby + 2);
	for(int i = m; i< v; i++)
	{
		if(i %2 == 1)
		{
			gotoxy(tabx + 10,taby+i);
			for(int j = 1; j<tabs -18; j++)
			{
				cout << char(196);
			}
			gotoxy(tabx +9,taby+i);
			cout<<char(195);
			gotoxy(tabx + 25,taby+i);
			cout<<char(197);
			gotoxy(tabx + 73,taby+i);
			cout<<char(180);
			gotoxy(tabx + 9, taby +i + 1); cout << char(179);
			gotoxy(tabx + 25, taby +i + 1); cout << char(179);
			gotoxy(tabx + 73, taby +i + 1); cout << char(179);
			gotoxy(boxx +31, taby + 2 + dem ); cout<<theloai;
			gotoxy(boxx +6, taby + 2 + dem ); cout<<dem1;
			dem = dem +2;
			m = v;
			Sleep(30);
		}
	}
 }
 ///////////////////////////////////////////////////
 void XuatDSSach(LDS l)
{
	int a = 1;
	int b = 15;
	textcolor(15);
	clrscr();
TheLoai:
	int m =1;
	int v = 0;
	int d = 0;
		Menu_Tam_Thoi(4);
    	Giao_Dien();
    	for(int i=1; i<50; i++)
		{
			gotoxy(3+i,37);
			cout<<char(220);
		}
		gotoxy(12,38); cout<<"F1: NHAP THE LOAI";
    	gotoxy(35,38); cout<<"ESC: THOAT";
    	Trang_Sau_Truoc();
    	gotoxy(85,3); cout<<"CAC THE LOAI SACH HIEN CO TRONG THU VIEN";
		gotoxy(tabx + 9, taby -1);
		cout << char(218);
		for(int i = 1; i < tabs - 18 ; i++)
		{
			cout << char(196);
		}
		cout << char(191);
		gotoxy(tabx + 25, taby - 1); cout << char(194);
		gotoxy(tabx +9, taby); cout << char(179);
		gotoxy(tabx + 25, taby); cout << char(179);
		gotoxy(tabx + 16, taby); cout << "STT";
		gotoxy(tabx + 73, taby); cout << char(179);
		gotoxy(tabx + 45, taby); cout << "THE LOAI";
    	int dem = 0;
    	int dem1 = 0;
    	string *theloai = new string[1000];
    	int sp = 0;
		theloai[sp] = "";
    	for(int i=0; i<l.n; i++)
    	{
    		for(int j=0; j<=sp; j++)
    		{
    			if(theloai[j] == l.DS[i]->theLoaiSach)//de in ra bang the loai cho doc gia nhap
    			{
    				break;
				}
				if( j == sp)
				{
					theloai[++sp] = l.DS[i]->theLoaiSach;
				}
			}
		}
		for(int i = 1; i<=sp; i++)
		{
			d++;
			dem1++;
			if(d>=a && d <= b)
			{
				v = v + 2; 
				Bang_The_Loai(theloai[i],dem,v,m,dem1);
			}
		}
		if(v <= 30)
		{
			gotoxy(tabx + 9, taby + v+1);
			cout << char(192);
			for(int i = 1; i < tabs -18; i++)
			{
				cout << char(196);
			}
			cout << char(217);
			gotoxy(tabx + 25, taby +v +1); cout << char(193);
		}
    	////////////////////////
    	int c = getch();
    	if(c == 27)
    	{
    		textcolor(15);
    		clrscr();
    		return;
		}
    	else if(c == 224)
    	{
    		int f = getch();
    		if(f == 81)
    		{
    			if(d<=b)
				{
					textcolor(15);
					clrscr();
					goto TheLoai;
				}
				a = b+1;
				b = b +15;
				textcolor(15);
				clrscr();
				goto TheLoai;
			}
			else if(f == 73)
			{
				if(a == 1 && b == 15)
				{
					textcolor(15);
					clrscr();
					goto TheLoai;
				}
				a = a-15;
				b = b-15;
				textcolor(15);
				clrscr();
				goto TheLoai;
			}
		}
		else if(c == 0)
		{
			int f = getch();
			if(f == 59)
			{
				G:
				frameTheLoai(15,29);// bang nhap the loai sach
		    	int x = 18, y = 29;// vi tri toa do de lam moc
				int keyhit, dem;
				string text, field;
				field = "";	// Khoi tao field rong de nhap du lieu
				keyhit = 0;
				dem = field.length();
				text = field;
				while(1)//Nhap vi tri sach va kiem tra du lieu
				{
					textcolor(253);
					gotoxy(x + 5, y + 1);
					if(dem < 9)// neu chieu dai text nho hon 9
					{
						cout << text;
						for(int i = 1; i < 11 - dem; i++) cout << " ";// chieu dai khong gian de nhap du lieu
					}
					else
					{
						for(int i = dem - 9; i < dem; i++)// neu nhap qua chieu dai khong gian nhap du lieu thi no se day du lieu qua ben phai
						cout << text[i];
					}
					if(dem < 9) gotoxy(x + 5 + dem, y + 1);// ki tu duoc nhap tiep theo nam o vi tri sau ke tiep text
					keyhit = getch();// Kiem tra bat ban phim
					if(keyhit == BACKSPACE)// Nhan phim backspace de xoa ki tu cuoi cung
					{
						if(dem > 0)
						{
							dem--;
							text = text.substr(0, text.size() - 1);// Xoa ki tu cuoi cung
						}
					}
					else if(keyhit == ESC)//Nhan phim thoat
					{
						textcolor(15);
						Sleep(500);
						clrscr();
						goto TheLoai;
					}
					else if(keyhit == ENTER)//Nhan phim enter
			 		{
						if(text == "")// du lieu nhap bi rong 
						{
							textcolor(15);
							keyhit = 0;
							gotoxy(16, 33);
							textcolor(112);
							cout << "(VUI LONG NHAP THE LOAI!)";// bi Table_DMS chen len tren
							int keyhit1 = getch();
							textcolor(15);
							gotoxy(16, 33);cout<<"                            ";
							goto G;
						}
						else
						{
							textcolor(15);
							if(text.length() > 25)//chieu dai text > 25
							{
								gotoxy(16,33);
								textcolor(112);
								cout << "(THE LOAI SACH QUA DAI)";
								int keyhit1 = getch();
								textcolor(15);
								gotoxy(16, 33);cout<<"                            ";
								goto G;	
							}
							else
							{
								if(Tim_Kiem_The_Loai_Sach(l,text) == 0)//kiem tra the loai sach duoc nhap co ton tai khong
								{
									gotoxy(14,33);
									textcolor(112);					
									cout << "(THE LOAI SACH KHONG TON TAI)";
									int keyhit1 = getch();
									textcolor(15);
									gotoxy(14, 33);cout<<"                             ";
									goto G;
								}
								else
								{	
									Sleep(500);
									textcolor(15);
									clrscr();
								    Sap_Xep_Theo_The_Loai(l, text);// Sap xep dau sach the loai
								    goto TheLoai;
								}
							}
						}
					}
					else 
					{
						dem++;
						text += toupper((char)keyhit);// nhap them ki tu vao cuoi text
					}
				}	
			}
		}
		else
		{
			textcolor(15);
    		clrscr();
    		goto TheLoai;
		}
}
 
 //**********************************   Thong Tin Sach  *********************************
 void TableDS()
{
	gotoxy(75,2); cout<<"DANH SACH DAU SACH";
	gotoxy(taxx, taxy - 12);
	cout << char(218);
	for(int i = 1; i < taxs ; i++)
	{
		cout << char(196);
	}
	cout << char(191);
	for(int i = 1; i < taxw; i++)
	{
		gotoxy(taxx, taxy -12 + i);
		cout << char(179);
	}

	for(int i = 1; i < taxw; i++)
	{
		gotoxy(taxx + taxs, taxy - 12 + i);
		cout << char(179);
	}
	gotoxy(taxx, taxy -12+ taxw);
	cout << char(192);
	for(int i = 1; i < taxs; i++)
	{
		gotoxy(taxx + i, taxy -12 + taxw);
		cout << char(196);
	}
	gotoxy(taxx + taxs, taxy - 12 + taxw);
	cout << char(217);

	// ISBN
	gotoxy(taxx + 5, taxy - 12 + 1); cout << "ISBN";
	gotoxy(taxx + 15, taxy - 12); cout << char(194);
	for(int i = 1; i < taxw; i++)
	{
		gotoxy(taxx + 15, taxy - 12 + i); cout << char(179);
	}
	gotoxy(taxx, taxy -10);
	cout << char(195);
	for(int i = 1; i < taxs; i++)
	{
		gotoxy(taxx + i, taxy -12 + 2);
		cout << char(196);
	}
	gotoxy(taxx + 15, taxy -12+ 2); cout << char(197);
	gotoxy(taxx + taxs, taxy -12+ 2); cout << char(180);
	gotoxy(taxx + 15, taxy -12+ taxw); cout << char(193);

	// Ten Sach
	gotoxy(taxx + 32, taxy -12 + 1); cout << "TEN SACH";
	gotoxy(taxx + 57, taxy -12); cout << char(194);
	for(int i = 1; i < taxw ; i++)
	{
		gotoxy(taxx + 57, taxy -12 + i); cout << char(179);
	}
	gotoxy(taxx + 57, taxy -12+ 2); cout << char(197);
	gotoxy(taxx + 57, taxy -12+ taxw); cout << char(193);

	// Tac Gia
	gotoxy(taxx + 70, taxy -12 + 1); cout << "TAC GIA";
	gotoxy(taxx + 89, taxy -12); cout << char(194);
	for(int i = 1; i < taxw; i++)
	{
		gotoxy(taxx + 89, taxy -12 + i); cout << char(179);
	}
	gotoxy(taxx + 89, taxy -12+ 2); cout << char(197);
	gotoxy(taxx + 89, taxy -12+ taxw ); cout << char(193);
	
	//The loai
	gotoxy(taxx + 101, taxy -12+ 1); cout << "THE LOAI";
	gotoxy(taxx + 121, taxy -12); cout << char(194);
	for(int i = 1; i < taxw; i++)
	{
		gotoxy(taxx + 121, taxy -12 + i); cout << char(179);
	}
	gotoxy(taxx + 121, taxy - 12+ 2); cout << char(197);
	gotoxy(taxx + 121, taxy -12+ taxw); cout << char(193);
	
	//So trang
	gotoxy(taxx + 122, taxy -12+ 1); cout << "SO TRANG";
	gotoxy(taxx + 131, taxy -12); cout << char(194);
	for(int i = 1; i < taxw; i++)
	{
		gotoxy(taxx + 131, taxy -12 + i); cout << char(179);
	}
	gotoxy(taxx + 131, taxy  -12+ 2); cout << char(197);
	gotoxy(taxx + 131, taxy -12+ taxw); cout << char(193);
	
	//Nam XB
	gotoxy(taxx + 132, taxy -12+ 1); cout << "NAM XB";
	gotoxy(taxx + 139, taxy -12); cout << char(194);
	for(int i = 1; i < taxw; i++)
	{
		gotoxy(taxx + 139, taxy -12 + i); cout << char(179);
	}
	gotoxy(taxx + 139, taxy -12 + 2); cout << char(197);
	gotoxy(taxx + 139, taxy -12+ taxw); cout << char(193);
	// So lan muon
	gotoxy(taxx + 140, taxy -12+ 1); cout << "SL MUON";
	//
	
	gotoxy(taxx,taxy -12);
	for(int i=1; i<taxw; i++)
	{
		if(i%2==0)
		{
			for(int j=1; j<taxs; j++)
			{
				gotoxy(taxx+j,taxy - 12 +i);
				cout<<char(196);
			}	
		}
	}
//	gotoxy(tabx,taby+4);
	for(int i=1; i<taxw-1; i++)
	{
		if(i%2==1)
		{
			gotoxy(taxx + 15,taby  - 1 +i);
			cout<<char(197);
			gotoxy(taxx + 57,taby -1 +i);
			cout<<char(197);
			gotoxy(taxx + 89,taby -1 +i);
			cout<<char(197);
			gotoxy(taxx + 121,taby -1+i);
			cout<<char(197);
			gotoxy(taxx + 131,taby -1+i);
			cout<<char(197);
			gotoxy(taxx + 139,taby -1+i);
			cout<<char(197);
		}
	}
//	gotoxy(taxx, taxy + 4);
	for(int i=1; i<taxw - 2; i++)
	{
		if(i%2 == 0)
		{
			gotoxy(taxx,taxy - 10 + i); cout<<char(195);	
			gotoxy(taxx + taxs,taxy - 10 + i); cout<<char(180);
		}
	}
}
 
 
 void frameTenSach(int x, int y)
{
	gotoxy(40, 15);
	textcolor(112);
	gotoxy(x, y - 1); 		cout << "                                     ";
	gotoxy(x, y); 			cout << "          NHAP VAO TEN SACH          ";
	gotoxy(x, y + 1);		cout << " ";
	gotoxy(x + 1, y + 1); 	cout << "                                    ";
	gotoxy(x + 26, y + 1); 	cout << " ";
	gotoxy(x, y + 2); 		cout << "                                     ";
	textcolor(15);
}


void XuatTenSach(LDS l, string b)
{
	int a = TimKiemTenSach(l,b);//tim duoc thu tu sach
	textcolor(15);
	clrscr();
	int c = 1;
	int d = 12;
	while(1)
	{
X:
	int v = 0;
	int m = 1;
	int e =0;
	   textcolor(15);
	   Menu_Tam_Thoi(5);
		Trang_Sau_Truoc_DMS();
	   for(int i=1; i<50; i++)
		{
			gotoxy(3+i,37);
			cout<<char(220);
		}
		gotoxy(13,38); cout<<"F4: CHU THICH";
    	gotoxy(30,38); cout<<"ESC: THOAT";
   		Giao_Dien();
   		Khung_Dau_Sach();
   		gotoxy(82,3);
		cout<<"TEN SACH: ";
		gotoxy(82,4);
		cout<<"ISBN: ";
		gotoxy(82,5);
		cout<<"TAC GIA: ";
		gotoxy(82,6);
		cout<<"THE LOAI: ";
		gotoxy(82,7);
		cout<<"SO TRANG: ";
		gotoxy(82,8);
		cout<<"NAM XUAT BAN: ";
		gotoxy(95,10);
		cout << "DANH MUC SACH";
		gotoxy(tabx + 12 , taby + 6);
		cout << char(218);
		for(int i = 1; i < tabs - 24; i++)
		{
			cout << char(196);
		}
		cout << char(191);
		gotoxy(tabx + 31, taby + 6); cout << char(194);
		gotoxy(tabx + 51, taby + 6); cout << char(194);
		gotoxy(tabx + 12, taby + 7); cout << char(179);
		gotoxy(tabx + 31, taby + 7); cout << char(179);
		gotoxy(tabx + 18, taby + 7); cout << "MA SACH";
		gotoxy(tabx + 51, taby + 7); cout << char(179);
		gotoxy(tabx + 36, taby + 7); cout << "TRANG THAI";
		gotoxy(tabx + 70, taby + 7); cout << char(179);
		gotoxy(tabx + 58, taby + 7); cout << "VI TRI";
	   textcolor(15);
	   int dem = 0;
	   gotoxy(92, 3);cout<<l.DS[a]->tenSach;
	   gotoxy(88, 4);cout<<l.DS[a]->ISBN;
	   gotoxy(91, 5);cout<<l.DS[a]->tacGia;
	   gotoxy(92, 6);cout<<l.DS[a]->theLoaiSach;
	   gotoxy(92, 7);cout<<l.DS[a]->soTrang;
	   gotoxy(96, 8);cout<<l.DS[a]->namSB;
	   for(DMSNode *k = l.DS[a]->sach.pHead; k!=NULL; k = k->pNext)//in danh muc sach ra man hinh
	   {
	   		e++;
	   		if(e>=c && e <= d)
	   		{
	   			v = v + 2;
	   			Table_DMS(k, dem, v, m);
			}
	   }
	   if(v <= 24)
		{
			gotoxy(tabx +12, taby + v+8);
			cout << char(192);
			for(int i = 1; i < tabs - 24; i++)
			{
				cout << char(196);
			}
			cout << char(217);
			gotoxy(tabx + 31, taby+v +8); cout << char(193);
			gotoxy(tabx + 51, taby+v +8); cout << char(193);
		}
	   int keyhit = getch();//Nhan lenh ban phim
	   if(keyhit == 224)
	   {
	   		int f = getch();
	   		if(f == 27)//thoat
			{
				clrscr();
				break;
			}
			else if(f == 81)//Phim PgDn de xem trang sau
			{
				if(e<=d)
				{
					textcolor(15);
					clrscr();
					goto X;
				}
				c = d+1;
				d = d +12;
				textcolor(15);
				clrscr();
				goto X;
			}
			else if(f == 73)//Phim PgUp de xem trag truoc
			{
				if(c == 1 && d == 12)
				{
					textcolor(15);
					clrscr();
					goto X;
				}
				c = c-12;
				d = d-12;
				textcolor(15);
				clrscr();
				goto X;
			}
	   }
	   else if(keyhit == ESC)
	   {
	   		textcolor(15);
			clrscr();
			break;
	   }
	   else if(keyhit == 0)
	   {
	   		int f = getch();
	   		if(f == 62)
	   		{
	   			frameChuThichDanhMucSach(13, 28);
				int u = getch();
				if(u == ESC)
				{
					textcolor(15);
					clrscr();
					goto X;	
				}	
			}
	   }
	}
}

string Fix(string t)
{
	if(t.length() == 1)
	{
		if(t[0] >= 'A' && t[0] <= 'Z')// chuyen chu hoa thanh chu thuong
		{
			t[0] += 32;
		}
	}
	if(t.length() != 0 && t.length() != 1) {                   // t co ki tu
		while(t[0] == ' ') t.erase(0, 1); //Xoa 1 khoang trang o dau
		while(t[t.length() - 1] == ' ') t.erase(t.length() - 1, 1); //Xoa khoang trang o cuoi
		for(short i =1; i<t.length()-1; i++)// Xoa het cac khoang trang o giua
		{
			if(t[i] == ' ')
			{
				t.erase(i,1); i--;
			}
		}
		for(short i = 0; i < t.length(); i++)
		{
			if(t[i] >= 'A' && t[i] <= 'Z') t[i] += 32; //Chuyen chu hoa thanh chu thuong	
		}
	}
	return t;
}

void Tim_Kiem_Sach(LDS &l, string a, string text2)
{
	textcolor(15);
	clrscr();
	int x = a.length();
	string str1;
	int c = 1;
	int d = 16;
	while(1)
	{
	X:
		int e = 0;
		TableDS();
   		 Giao_DienDS();
		Trang_Sau_Truoc_DS1();
		int dem = 0;
		for(int i=0; i<l.n; i++)
		{
			e++;
			int t = -1;
			string str = Fix(l.DS[i]->tenSach);// chuan hoa ten sach
			for(int j=0; j<str.length(); j++)
			{
				t++;
				if(str[j] == a[0])
				{
					str1 = "";//tao str1 de chua so luong ki tu x, de kiem tra xem no co trung voi chuoi a
					for(int k = j; k<t+x; k++)
					{
						if(k > str.length())
						{
							break;
						}
						str1.push_back(str[k]);
					}
					if(str1 == a)// in danh sach tim duoc
					{
						if(e>=c && e <= d)
						{
							int b = l.DS[i]->tenSach.find(text2);
							if(b == -1)
							{
								break;
							}
							gotoxy(21, 6 + dem); cout <<l.DS[i]->tenSach;
							textcolor(12);
							gotoxy(21 + b, 6 + dem); cout <<text2;		
							textcolor(15);
							gotoxy(6, 6 + dem); cout << l.DS[i]->ISBN;
							gotoxy(63, 6 + dem); cout << l.DS[i]->tacGia;
							gotoxy(95, 6 + dem); cout << l.DS[i]->theLoaiSach;
							gotoxy(127, 6 + dem); cout << l.DS[i]->soTrang;
							gotoxy(137, 6 + dem); cout << l.DS[i]->namSB;
							gotoxy(146, 6 + dem); cout << l.DS[i]->solanmuon;
							dem = dem + 2;
							break;	
						}
					}
				}
			}
		}
		int keyhit = getch();// nhan bat ban phim
		if(keyhit == 81)//Phim PgDn de xem trang sau
		{
			if(e<=d)
			{
				textcolor(15);
				clrscr();
				goto X;
			}
			c = d+1;
			c = d +16;
			textcolor(15);
			clrscr();
			goto X;
		}
		else if(keyhit == 73)//Phim PgUp de xem trang truoc
		{
			if(c == 1 && d == 16)
			{
				textcolor(15);
				clrscr();
				goto X;
			}
			c = c-16;
			d = d-16;
			textcolor(15);
			clrscr();
			goto X;
		}
		else if(keyhit == 27)//thoat
		{
			return;
		}
	}
}

void Tim_Kiem_Thong_Tin_Sach(LDS l)
{
	TenSach:
		Menu_Tam_Thoi(5);
   		 Giao_Dien();
   		 for(int i=1; i<50; i++)
		{
			gotoxy(3+i,37);
			cout<<char(220);
		}
    	gotoxy(23,38); cout<<"ESC: THOAT";
		frameTenSach(10,27);// bang nhap ten sach
    	int x = 8, y = 27;// vi tri toa do de lam moc
		int keyhit, dem;
		string text, field;
		field = "";	// Khoi tao field rong de nhap du lieu
		keyhit = 0;
		dem = field.length();
		text = field;
		while(1)//Nhap ten sach va kiem tra du lieu
		{
			textcolor(253);
			gotoxy(x + 5, y + 1);
			if(dem < 32)// neu chieu dai text nho hon 9
			{
				cout << text;
				for(int i = 1; i < 32 - dem; i++) cout << " ";// chieu dai khong gian de nhap du lieu
			}
			else
			{
				for(int i = dem - 32; i < dem; i++)// neu nhap qua chieu dai khong gian nhap du lieu thi no se day du lieu qua ben phai
				cout << text[i];
			}
			if(dem < 32) gotoxy(x + 5 + dem, y + 1);// ki tu duoc nhap tiep theo nam o vi tri sau ke tiep text
			keyhit = getch();// Kiem tra bat ban phim
			if(keyhit == BACKSPACE)// Nhan phim backspace de xoa ki tu cuoi cung
			{
				if(dem > 0)
				{
					dem--;
					text = text.substr(0, text.size() - 1);// Xoa ki tu cuoi cung
				}
			}
			else if(keyhit == ESC)//Nhan phim thoat
			{
				textcolor(15);
				clrscr();
				break;
			}
			else if(keyhit == ENTER)//Nhan phim enter
	 		{
				if(text == "")// du lieu nhap bi rong 
				{
					textcolor(15);
					keyhit = 0;
					gotoxy(15, 31);
					textcolor(112);
					cout << "(VUI LONG NHAP TEN SACH!)";
					int keyhit1 = getch();
					textcolor(15);
					gotoxy(15, 31); cout<<"                             ";
					goto TenSach;
				}
				else
				{
					textcolor(15);
					if(text.length() > 40)//chieu dai text > 30
					{
						gotoxy(13, 31);
						textcolor(112);
						cout << "(TEN SACH KHONG QUA 40 KI TU)";
						int keyhit1 = getch();
						textcolor(15);
						gotoxy(13, 31); cout<<"                              ";
						goto TenSach;	
					}
					else
					{
						string text1 = Fix_Tensach(text);//chuan hoa text1
						if(TimKiemTenSach(l,text1) != -1)//kiem tra xem co ton tai ten sach vua nhap hay khong
						{
							XuatTenSach(l,text1);//Xuat
							textcolor(15);
							clrscr();
							goto TenSach;
						}
						else
						{
							string text1 = Fix(text);//chuan hoa text1
							string text2 = Fix_Tensach(text);//chuan hoa text2
							Tim_Kiem_Sach(l, text1, text2);	//tim sach
							textcolor(15);
							clrscr();
							goto TenSach;
						}
					}
				}
			}
			else 
			{
				dem++;
				text += toupper((char)keyhit);// nhap them ki tu vao cuoi text
			}
		}
}
 //**********************************   Muon Sach   ***********************************
 void Table_Muon_Sach(NodeMuonTra *&k, int &dem, int &v, int &m)
{
	gotoxy(tabx + 5, taby + 5);
	cout << char(218);
	for(int i = 1; i < tabs - 10; i++)
	{
		cout << char(196);
	}
	cout << char(191);	
	gotoxy(tabx + 22, taby + 5); cout << char(194);
	gotoxy(tabx + 42, taby + 5); cout << char(194);
	gotoxy(tabx + 60, taby + 5); cout << char(194);
	gotoxy(tabx + 5, taby + 6); cout << char(179);
	gotoxy(tabx + 22, taby + 6); cout << char(179);
	gotoxy(tabx + 10, taby + 6); cout << "MA SACH";
	gotoxy(tabx + 42, taby + 6); cout << char(179);
	gotoxy(tabx + 27, taby + 6); cout << "NGAY MUON";
	gotoxy(tabx + 60, taby + 6); cout << char(179);
	gotoxy(tabx + 48, taby + 6); cout << "NGAY TRA";
	gotoxy(tabx + 77, taby + 6); cout << char(179);
	gotoxy(tabx + 65, taby + 6); cout << "TRANG THAI";
	
	gotoxy(tabx + 5,taby+7);
	for(int i = m; i< v; i++)
	{
		if(i %2 == 1)
		{
			gotoxy(tabx + 6,taby+i +6);
			for(int j = 1; j<tabs -10; j++)
			{
				cout << char(196);
			}
			gotoxy(tabx +5,taby+i+6);
			cout<<char(195);
			gotoxy(tabx + 22,taby+i+6);
			cout<<char(197);
			gotoxy(tabx + 42,taby+i+6);
			cout<<char(197);
			gotoxy(tabx + 60,taby+i+6);
			cout<<char(197);
			gotoxy(tabx + 77,taby+i+6);
			cout<<char(180);
			gotoxy(tabx + 5, taby +i + 7); cout << char(179);
			gotoxy(tabx + 22, taby + i+7); cout << char(179);
			gotoxy(tabx + 42, taby + +i+7); cout << char(179);
			gotoxy(tabx + 60, taby + i+7); cout << char(179);
			gotoxy(tabx + 77, taby + i+7); cout << char(179);
			gotoxy(75, 13 + dem); cout<<k->data.MASACH;
			gotoxy(93, 13 + dem); cout<<k->data.ngaymuon.ngay<<"-"<<k->data.ngaymuon.thang<<"-"<<k->data.ngaymuon.nam;
			gotoxy(112, 13 + dem); cout<<k->data.ngaytra.ngay<<"-"<<k->data.ngaytra.thang<<"-"<<k->data.ngaytra.nam;
			gotoxy(135,13+dem); cout<<"0";
			dem = dem + 2;
			m = v;
			Sleep(30);
		}
	}
}
Tree Check_Ma_Doc_Gia(Tree &t, int &z)
{
	LoadtuFile_DSDG(t);
CheckMaDG:
	frameDocGia(15,28);// bang nhap doc gia
	int x = 18, y = 28;// vi tri toa do de lam moc
	int keyhit, dem;
	ngaythang n1;
	string text, field;
	field = "";// Khoi tao field rong de nhap du lieu
	char temp[10];
	keyhit = 0;
	dem = field.length();
	text = field;
	while(1)//Nhap doc gia va kiem tra du lieu
	{
		textcolor(253);
		gotoxy(x + 5, y + 1); 
		if(dem < 9)// neu chieu dai text nho hon 9
		{
			cout << text;
			for(int i = 1; i < 11 - dem; i++) cout << " ";// chieu dai khong gian de nhap du lieu
		}
		else
		{
			for(int i = dem - 9; i < dem; i++)// neu nhap qua chieu dai khong gian nhap du lieu thi no se day du lieu qua ben phai
				cout << text[i];
		}
		if(dem < 9) gotoxy(x + 5 + dem, y + 1);// ki tu duoc nhap tiep theo nam o vi tri sau ke tiep text
		keyhit = getch();// Kiem tra bat ban phim
		if(keyhit == BACKSPACE)// Nhan phim backspace de xoa ki tu cuoi cung
		{
			if(dem > 0)
			{
				dem--;
				text = text.substr(0, text.size() - 1);// Xoa ki tu cuoi cung
			}
		}
		else if(keyhit == ENTER)//Nhan phim enter
		{
			if(text == "")// du lieu nhap bi rong 
			{
				textcolor(15);
				keyhit = 0;
				gotoxy(16, 33);
				textcolor(112);	
				cout << "VUI LONG NHAP MA DOC GIA";
				int f = getch();
				textcolor(15);
				gotoxy(16, 33); cout << "                             ";
				goto CheckMaDG;
			}
			else
			{
				textcolor(15);
				if(text.length() > 9)//chieu dai text > 9
				{
					gotoxy(16, 33);
					textcolor(112);	
					cout << "   MA DOC GIA QUA DAI";
					int f = getch();
					textcolor(15);
					gotoxy(16, 33); cout << "                       ";
				}
				else
				{
					const int STACKSIZE = 100;
					Tree *a;//Khoi tao mang a
					a =new Tree[STACKSIZE];
					int sp = -1;
					Duyet_NLR(t, a, sp);//duyet cay dua cac phan tu vao mang a
					for(int i=0; i<sp; i++)//duyet mang a
					{
						if(a[i]->DG.MADG == atoi((char*)text.c_str()))//neu ma doc gia trung
						{
							if(a[i]->DG.trangthaithe == 0)
							{
								gotoxy(16, 33);
								textcolor(112);	
								cout << "    THE DOC GIA BI KHOA";
								int f = getch();
								textcolor(15);
								gotoxy(16, 33); cout << "                            ";
								goto CheckMaDG;
							}	
						}
					}
					if(timDG(t, atoi((char*)text.c_str())) == 0)//kiem tra ma doc gia co ton tai khong
					{
						gotoxy(16, 33);
						textcolor(112);	
						cout << " MA DOC GIA KHONG TON TAI ";
						int f = getch();
						textcolor(15);
					    gotoxy(16, 33); cout << "                            ";
						goto CheckMaDG;
					}
					else
					{	
						return 	timDG(t, atoi((char*)text.c_str()));//Ham tra ve 1 node doc gia		
					}
				}
			}
		}
		else if(keyhit == ESC)//thoat
		{
			z++;
			Sleep(500);
			break;
		}
		else 
		{
			dem++;
			text += toupper((char)keyhit);// nhap them ki tu vao cuoi text
		}
	}
}

int Kiem_Tra(Tree &tt, Tree &t, string text)
{
	const int STACKSIZE = 100;
	Tree Stack[STACKSIZE];//Tao mang Stack de chua cac node doc gia
	int sp = -1;
	do //duyet doc gia
	{
		while (tt != NULL)
		{
			Stack[++sp] = tt;
			tt = tt->pLeft;
		}
		if (sp != -1)
		{
			tt = Stack[sp--];
			if(tt->DG.MADG == t->DG.MADG)
			{
				for(NodeMuonTra *k = tt->MT.pHead; k!=NULL; k=k->pRight)
				{
					string str1 =k->data.MASACH;
					string str=""; // khoi tao chuoi str rong
					for(int i=0; i<str1.length(); i++)// loc lay ma ISBN
					{
						if(str1[i] == '-')// khi gap ki tu "-" se dung
						{
							break;
						}
						str.push_back(str1[i]);
					}
					if(str == text && k->data.trangthai == 0)
					{
						return 0;
					}
					if(str == text && k->data.trangthai == 1)
					{
						ngaythang nt;
						LayNgayHT(nt);// lay ngay thang nam tu he thong
						if(nt.ngay == k->data.ngaymuon.ngay && nt.thang == k->data.ngaymuon.thang && nt.nam == k->data.ngaymuon.nam)
						{
							return 2;
						}
					}
				}
			}
			tt = tt->pRight;
		}
		else break;
	} while (1);
	return 1;
}

int Check_Ma_Sach(Tree &tt, Tree &t, LDS l, int &z)
{
	DauSach:
	frameDauSach(15, 28); // bang nhap dau sach
	int x = 19, y = 28;// vi tri toa do de lam moc 
	int keyhit, dem;
	string text, field;
	field = "";// Khoi tao field rong de nhap du lieu
	keyhit = 0;
	dem = field.length();
	text = field;
	while(1)//Nhap dau sach va kiem tra du lieu
	{
		textcolor(253);
		gotoxy(x + 5, y + 1);
		if(dem < 9)// neu chieu dai text nho hon 9 
		{
			cout << text;
			for(int i = 1; i < 11 - dem; i++) cout << " ";// chieu dai khong gian de nhap du lieu
		}
		else
		{
			for(int i = dem - 9; i < dem; i++)// neu nhap qua chieu dai khong gian nhap du lieu thi no se day du lieu qua ben phai 
				cout << text[i];
		}
		if(dem < 9) gotoxy(x + 5 + dem, y + 1);// ki tu duoc nhap tiep theo nam o vi tri sau ke tiep text
		keyhit = getch();// Kiem tra bat ban phim
		if(keyhit == BACKSPACE)// Nhan phim backspace de xoa ki tu cuoi cung
		{
			if(dem > 0)
			{
				dem--;
				text = text.substr(0, text.size() - 1);// Xoa ki tu cuoi cung
			}
		}
		else if(keyhit == ENTER)//nhan phim enter
		{
			if(text == "")// du lieu nhap bi rong 
			{
				textcolor(15);
				keyhit = 0;
				gotoxy(6,32);
				textcolor(112);
				cout << "    (VUI LONG NHAP MA ISBN!)    ";
				goto DauSach; 
			}
			else
			{
				textcolor(15);
				if(text.length() > 9)// chieu dai text > 9
				{
					gotoxy(6,32);
					textcolor(112);
					cout << "     MA ISBN QUA DAI     ";
					goto DauSach; 
				}
				else
				{
					if(TimKiemDS(l,text) == -1) // kiem tra xem dau sach co ton tai hay khng
					{
						gotoxy(6,32);
						textcolor(112);					
						cout << "    MA ISBN KHONG TON TAI!    ";
						goto DauSach;
					}
					else
					{	
						int a = Kiem_Tra(tt,t,text); // kiem tra xem dau sach nay ban co dang muon hay k the muon ngay hom nay
						if(a == 0)
						{
							gotoxy(6,32);
							textcolor(112);
							cout<<"    BAN DA MUON DAU SACH NAY    ";
						}
						else if(a == 2)
						{
							gotoxy(8,32);
							textcolor(112);
							cout<<"BAN KHONG THE MUON SACH NAY NGAY HOM NAY";
						}
						else
						{
							return TimKiemDS(l,text);	//thu tu vi tri dau sach
						}			
					}
				}
			}
		}
		else if(keyhit == ESC)// Thoat
		{
			z++;
			textcolor(15);
			clrscr();
			break;
		}
		else 
		{
			dem++;
			text += toupper((char)keyhit);// nhap them ki tu vao cuoi text 

		}
	}	
}

void Khoi_Tao_MT(Tree &t)// Khoi tao Muon tra
{
	if (t != NULL)
	{
		if(t->MT.pHead == NULL)
		{
				Khoi_Tao_MT(t);
		}
		Khoi_Tao_MT(t->pLeft);
		Khoi_Tao_MT(t->pRight);
	}
}

void Sach_Muon(Tree &tt, Tree &dg, string text, LDS &l,int &b)
{
	LoadtuFile_DSDG(tt);// do file DocGia
	int sp = -1;
	Tree *a; 
	a = new Tree[MAX_DAUSACH];// Khoi tao mang a
	Duyet_NLR(tt, a, sp);// duyet cay dua cac node vao mag a
	for(int i=0; i<=sp; i++)//duyet danh sach
	{
		if(a[i]->DG.MADG == dg->DG.MADG)
		{
			int h = XacNhanSaveFile();
			if(h == 1)// xac nhan yes
			{
				Muontra MT;
			MT.MASACH = text;
			LayNgayHT(MT.ngaymuon);
			MT.ngaytra.ngay = 0;// cho ngay, thang, nam muon la 0
			MT.ngaytra.thang = 0;
			MT.ngaytra.nam = 0;
			MT.trangthai = 0;
			NodeMuonTra *p = CreateNodeMT(MT);
			AddTailMT(a[i]->MT, p);// them vao danh sach muon tra
			a[i]->DG.sosachmuon++;// tang so sach muon len 1 don vi
			for(int i=0; i<l.n; i++)// duyet danh sach dau sach
			{
				if(i == b)
				{
					l.DS[i]->solanmuon++;
				}
				for(DMSNode *k = l.DS[i]->sach.pHead; k!=NULL; k=k->pNext)// duyet danh muc sach
				{
					if(k->data.maSach == text)
					{
						k->data.ttSach = 1;
					}
				}
			}
				GhiFileDS(l);
		    	GhiFileDG(tt);
		    	break;
			}
			else
			{
				break;
			}		
		}
	}
}

void Muon_Sach(Tree &tt ,Tree &dg, LDS &l, int &g)
{
	DMS:
			frameMaSach(15,28);// bang nhap ma sach
			int x = 19, y = 28;// vi tri toa do de lam moc 
			int keyhit, dem;
			string text, field;
			field = "";	// Khoi tao field rong de nhap du lieu
			keyhit = 0;
			dem = field.length();
			text = field;
			while(1)//Nhap ma sach va kiem tra du lieu
			{
				textcolor(253);
				gotoxy(x + 5, y + 1);
				if(dem < 9)// neu chieu dai text nho hon 9 
				{
					cout << text;
					for(int i = 1; i < 11 - dem; i++) cout << " ";// chieu dai khong gian de nhap du lieu
				}
				else
				{
					for(int i = dem - 9; i < dem; i++)// neu nhap qua chieu dai khong gian nhap du lieu thi no se day du lieu qua ben phai 
					cout << text[i];
				}
				if(dem < 9) gotoxy(x + 5 + dem, y + 1);// ki tu duoc nhap tiep theo nam o vi tri sau ke tiep text
				keyhit = getch();// kiem tra bat ban phim
				if(keyhit == BACKSPACE)// Nhan phim backspace de xoa ki tu cuoi cung
				{
					if(dem > 0)
					{
						dem--;
						text = text.substr(0, text.size() - 1);//xoa ki tu cuoi cung
					}
				}
				else if(keyhit == ESC)//thoat
				{
					g++;
					textcolor(15);
					Sleep(500);
					clrscr();
					break;
				}
				else if(keyhit == ENTER)// nhan phim enter
		 		{
					if(text == "")//// du lieu nhap bi rong 
					{
						textcolor(15);
						keyhit = 0;
						gotoxy(16, 32);
						textcolor(112);
						cout << "(VUI LONG NHAP MA SACH!)";// bi Table_DMS chen len tren
						int keyhit1 = getch();
						textcolor(15);
						gotoxy(16, 32);cout << "                          ";
						goto DMS;
					}
					else
					{
						textcolor(15);
						if(text.length() > 25)//chieu dai text > 25
						{
							gotoxy(20, 32);
							textcolor(112);
							cout << "(MA SACH QUA DAI)";
							int keyhit1 = getch();
						    textcolor(15);
						    gotoxy(20, 32);cout << "                          ";
							goto DMS;	
						}
						else
						{
							string str1 = "";// tao chuoi str rong
							for(int k = 0; k<text.length(); k++)//Cat lay ma ISBN
							{
								if(text[k] == '-')
								{
									break;
								}
								str1.push_back(text[k]);
							}
							int a = Kiem_Tra(tt,dg,str1);
							if(a == 0)
							{
								gotoxy(15,32);
								textcolor(112);
								cout<<"(BAN DA MUON DAU SACH NAY)";
								int keyhit = getch();
								textcolor(15);
						        gotoxy(15, 32);cout << "                          ";
								goto DMS;
							}
							else if(a == 2)
							{
								gotoxy(8,32);
								textcolor(112);
								cout<<"BAN KHONG THE MUON SACH NAY NGAY HOM NAY";
								int keyhit = getch();
								textcolor(15);
						        gotoxy(8, 32);cout << "                                           ";
								goto DMS;
							}
							int b = TimKiemDS(l, str1);//Kiem tra ma sach co ton tai khong
							if( b == -1)
							{
								gotoxy(16, 32);
								textcolor(112);					
								cout << "(MA SACH KHONG TON TAI)";
								int keyhit = getch();
								textcolor(15);
						        gotoxy(16, 32);cout << "                               ";
								goto DMS;
							}
							else
							{
								
								if(TimKiem_DMS(l.DS[b]->sach, text) == 0) // Kiem tra ma sach co ton tai
								{
									gotoxy(17, 32);
									textcolor(112);					
									cout << "        .MA SACH KHONG TON TAI!.        ";
									int keyhit = getch();
								    textcolor(15);
						           gotoxy(17, 32);cout << "                               ";
									goto DMS;
								}
								else 
								{
									for(DMSNode *k = l.DS[b]->sach.pHead; k!=NULL; k=k->pNext)// duyet danh muc sach
									{
										if(k->data.maSach == text)
										{
											if(k->data.ttSach == 0)
											{
												Sleep(500);
									    	    Sach_Muon(tt,dg,text,l,b);		
												g++;
												break;	
											}
											else
											{
												keyhit = 0;
												gotoxy(20, 32);
												textcolor(112);
											 	cout<<"DA CO DOC GIA MUON";
											 	int keyhit1 = getch();
								                textcolor(15);
						                        gotoxy(20, 32);cout << "                               ";
												goto DMS;
											}
										}
									}
								 } 
							}
							break;
						}
					}
				}
				else 
				{
					dem++;
					text += toupper((char)keyhit);// nhap them ki tu vao cuoi text 
				}
				
			}
}

void Kiem_Tra_Sach(Tree &tt, Tree &t, LDS &l, int &x, int &y)
{
	if(tt != NULL)
	{
		if(tt->DG.MADG == t->DG.MADG)
		{
			for(NodeMuonTra *k = tt->MT.pHead; k!=NULL; k=k->pRight)// duyet danh sach muon tra
			{
				if(k->data.trangthai == 0)
				{
					x++;
				}
				if(k->data.ngaytra.ngay == 0 &&  k->data.ngaytra.thang == 0 && 	k->data.ngaytra.nam == 0)
				{
					ngaythang nt;
					LayNgayHT(nt);
					int z = songaymuon(k->data.ngaymuon,nt);// kiem tra so ngay muon
					if(z > MAX_QH)
					{
						y++;	
					}	
				}
			}
		}
		Kiem_Tra_Sach(tt->pLeft, t, l, x, y);
		Kiem_Tra_Sach(tt->pRight, t, l, x, y);
	}
}

void Nhap_Doc_Gia(Tree &t, LDS &l)
{
	int z = 0;
	Tree dg = Check_Ma_Doc_Gia(t,z);
	if(z != 0)
	{
		return;
	}
	int s = 1;
	int b = 12;
	textcolor(15);
	clrscr();
	while(1)
	{
		Xuat:
			int v = 0;
			int m = 1;
			LoadtuFile_DSDG(t);
			int d =0;
			Menu_Tam_Thoi(6);
			for(int i=1; i<50; i++)
			{
				gotoxy(3+i,37);
				cout<<char(220);
			}
			gotoxy(6,38); cout<<"F1: NHAP MA SACH";
			gotoxy(25,38); cout<<"F4: CHU THICH";
		    gotoxy(42,38); cout<<"ESC: THOAT";
		//	Table_Muon_Sach();
			Giao_Dien();
			Trang_Sau_Truoc();
			Khung_Dau_Sach();
			gotoxy(boxx+7, 3);
			cout<<"MA THE: ";
			gotoxy(boxx+7, 4);
			cout<<"HO: ";
			gotoxy(boxx+7, 5);
			cout<<"TEN: ";
			gotoxy(boxx+7, 6);
			cout<<"GIOI TINH: ";
			gotoxy(boxx+7,7);
			cout<<"TRANG THAI: ";
			gotoxy(boxx+7,8);
			cout<<"SO LUONG SACH: ";
			///////////////////
			int sp = -1;
        	Tree *a; 
	        a = new Tree[MAX_DAUSACH];// Khoi tao mang a
	        Duyet_NLR(t, a, sp);// duyet cay dua cac node vao mag a
	        for(int i = 0; i<=sp; i++)
	        {
	        	if(a[i]->DG.MADG == dg->DG.MADG)
	        	{
	        		textcolor(15);
			int dem = 0;
			gotoxy(98,3);cout << a[i]->DG.MADG; 
			gotoxy(98,4);cout << a[i]->DG.ho; 
			gotoxy(98,5);cout << a[i]->DG.ten; 
			gotoxy(98,6);cout << a[i]->DG.gioitinh;
			gotoxy(98,8);cout << a[i]->DG.sosachmuon;
			
			if(a[i]->DG.trangthaithe == 0)
			{
				gotoxy(98,7);cout << "KHOA";
			}
			else if(a[i]->DG.trangthaithe == 1)
			{
				gotoxy(98,7);cout << "HOAT DONG";
			}
			  		gotoxy(tabx + 5, taby + 5);
					cout << char(218);
					for(int j = 1; j < tabs - 10; j++)
					{
						cout << char(196);
					}
					cout << char(191);	
					gotoxy(tabx + 22, taby + 5); cout << char(194);
					gotoxy(tabx + 42, taby + 5); cout << char(194);
					gotoxy(tabx + 60, taby + 5); cout << char(194);
					gotoxy(tabx + 5, taby + 6); cout << char(179);
					gotoxy(tabx + 22, taby + 6); cout << char(179);
					gotoxy(tabx + 10, taby + 6); cout << "MA SACH";
					gotoxy(tabx + 42, taby + 6); cout << char(179);
					gotoxy(tabx + 27, taby + 6); cout << "NGAY MUON";
					gotoxy(tabx + 60, taby + 6); cout << char(179);
					gotoxy(tabx + 48, taby + 6); cout << "NGAY TRA";
					gotoxy(tabx + 77, taby + 6); cout << char(179);
					gotoxy(tabx + 65, taby + 6); cout << "TRANG THAI";
			for(NodeMuonTra *k = a[i]->MT.pHead; k!=NULL; k = k->pRight)// duyet node muon tra
			{
					if(k->data.trangthai == 0)
					{
						d++;
						if(d>=s && d <= b)
						{
						    v = v +2;
						    Table_Muon_Sach(k, dem, v, m);	
						}
					}
			}
				}
			}
			//////////////////
			if(v <= 24)
			{
				gotoxy(tabx + 5, taby + v+7);
				cout << char(192);
				for(int i = 1; i < tabs - 10; i++)
				{
					cout << char(196);
				}
				gotoxy(tabx + 22, taby +v +7); cout << char(193);
				gotoxy(tabx + 42, taby +v +7); cout << char(193);
				gotoxy(tabx + 60, taby+v+7); cout << char(193);
				gotoxy(tabx + 5 + tabs - 10, taby +v+7); cout << char(217);
			}
			int keyhit = getch();// kiem tra bat phim
			if(keyhit == 224)
			{
				int f = getch();
				if(f == 81)//Phim PgDn de xem trang sau
				{
					if(d <= b)
					{
						textcolor(15);
						clrscr();
						goto Xuat;
					}
					s = b+1;
					b = b +12;
					textcolor(15);
					clrscr();
					goto Xuat;
				}
				else if(f == 73)//Phim PgUp de xem trang truoc
				{
					if(s == 1 && b == 12)
					{
						textcolor(15);
						clrscr();
						goto Xuat;
					}
					s = s-12;
					b = b-12;
					textcolor(15);
					clrscr();
					goto Xuat;
				}
			}
			else if(keyhit == 27)//thoat (ESC)
			{
				break;
			}
			else if(keyhit == 0)
			{
				int f = getch();
				if(f == 59)// nhan phim F1
					{
						LoadtuFile_DSDG(t);
						int x = 0;
							int  y=0;
							Kiem_Tra_Sach(t,dg,l,x, y);// kiem tra cac dieu kien muon sach
							if(x >= 3)
							{
								textcolor(112);
								gotoxy(12,27); cout << "                                   ";
								gotoxy(12,28); cout << "              CHU Y                ";
								gotoxy(12,29);   cout<<"    KHONG MUON QUA 3 CUON SACH     ";
								gotoxy(12,30); cout << "                                   ";
								int c = getch();
								break;
							}
						if(y != 0)
						{
							textcolor(112);
							gotoxy(12,27); cout << "                                   ";
							gotoxy(12,28); cout << "              CHU Y                ";
							gotoxy(12,29);   cout<<"     CO SACH MUON QUA GIOI HAN     ";
							gotoxy(12,30); cout << "                                   ";
							int c = getch();
							break;
						}
						int g = 0;
						Muon_Sach(t,dg, l, g);
						textcolor(15);
						clrscr();
						goto Xuat;	
				}
				else if(f == 62)
				{
					frameChuThichDanhMucSach(13, 28);
					int u = getch();
					if(u == ESC)
					{
						textcolor(15);
						clrscr();
						goto Xuat;	
					}
				}
			}
	}
}

void Doc_Gia_Muon_Sach(Tree &l, LDS &t)
{
	int a = 1;
	int b = 14;
	textcolor(15);
	clrscr();
	while(1)
	{
Xuat:
	int v = 0;
	int m = 1;
	int d =0;
	LoadtuFile_DSDG(l);
	textcolor(15);
	Menu_Tam_Thoi(6);
	Trang_Sau_Truoc();
	for(int i=1; i<50; i++)
	{
		gotoxy(3+i,37);
		cout<<char(220);
	}
	gotoxy(6,38); cout<<"F1: NHAP DOC GIA";
	gotoxy(25,38); cout<<"F4: CHU THICH";
    gotoxy(42,38); cout<<"ESC: THOAT";
	Giao_Dien();
	gotoxy(100,3);
	cout << "DANH SACH DOC GIA";
	gotoxy(tabx, taby);
	cout << char(218);
	for(int i = 1; i < tabs; i++)
	{
		cout << char(196);
	}
	cout << char(191);
	gotoxy(tabx + 15, taby); cout << char(194);
	gotoxy(tabx + 31, taby); cout << char(194);
	gotoxy(tabx + 47, taby); cout << char(194);
	gotoxy(tabx + 58, taby); cout << char(194);
	gotoxy(tabx , taby + 1); cout << char(179);
	gotoxy(tabx + 15, taby + 1); cout << char(179);
	gotoxy(tabx + 3, taby + 1); cout << "MA DOC GIA";
	gotoxy(tabx + 31, taby + 1); cout << char(179);
	gotoxy(tabx + 19, taby + 1); cout << "HO DOC GIA";
	gotoxy(tabx + 47, taby + 1); cout << char(179);
	gotoxy(tabx + 34, taby + 1); cout << "TEN DOC GIA";
	gotoxy(tabx + 58, taby + 1); cout << char(179);
	gotoxy(tabx + 51, taby + 1); cout << "PHAI";
	gotoxy(tabx + 82, taby + 1); cout << char(179);
	gotoxy(tabx + 62, taby + 1); cout << "TRANG THAI THE";
	int dem = 0;
	textcolor(15);
	const int STACKSIZE = 100;
	Tree Stack[STACKSIZE];// kkoi tao mang stack 
	int sp = -1;
	do // lan luot dua cac node vao mang stack
		{
			while (l != NULL)
			{
				Stack[++sp] = l;
				l = l->pLeft;
			}
			if (sp != -1)
			{
				l = Stack[sp--];
				d++;
				if(d>=a && d <= b)
				{
					v = v +2;
					TableDG1(l,dem,v,m);
				}
				l = l->pRight;
			}
			else break;
		} while (1);
		if(v <= 28)
		{
			gotoxy(tabx, taby + v+2);
			cout << char(192);
			for(int i = 1; i < tabs; i++)
			{
				cout << char(196);
			}
			cout << char(191);
			gotoxy(tabx + 15, taby +v +2); cout << char(193);
			gotoxy(tabx + 31, taby +v +2); cout << char(193);
			gotoxy(tabx + 47, taby+v+2); cout << char(193);
			gotoxy(tabx + 58, taby+v+2); cout << char(193);
			gotoxy(tabx + tabs, taby +v+2); cout << char(217);
		}
		int keyhit = getch();// kiem tra bat phim
		if(keyhit == 224 ) // xem trang sau
		{
			int f = getch();
			if(f == 81)
			{
				if(d<=b)
				{
					textcolor(15);
					clrscr();
					goto Xuat;
				}
				a = b+1;
				b = b +14;
				textcolor(15);
				clrscr();
				goto Xuat;	
			}
			else if(f == 73)// xem trang truoc
			{
				if(a == 1 && b == 14)
				{
					textcolor(15);
					clrscr();
					goto Xuat;
				}
				a = a-14;
				b = b-14;
				textcolor(15);
				clrscr();
				goto Xuat;
			}
		}
		else if(keyhit == 27)//ESC de thoat
		{
			textcolor(15);
			clrscr();
			break;
		}
		else if(keyhit == 0)// Phim F1
		{
			int f = getch();
			if(f == 59)
			{
				Nhap_Doc_Gia(l, t);	
				textcolor(15);
				clrscr();
				goto Xuat;
			}
			else if(f == 62)
			{
				frameChuThichDocGia(13, 28);
				int u = getch();
				if(u == ESC)
				{
					textcolor(15);
					clrscr();
					goto Xuat;	
				}
			}
		}
	}
}

//************************************   Tra Sach   ***************************************
void Table_Tra_Sach()
{
	Giao_Dien();
	Khung_Dau_Sach();
	gotoxy(boxx+7, 3);
	cout<<"MA THE: ";
	gotoxy(boxx+7, 4);
	cout<<"HO: ";
	gotoxy(boxx+7, 5);
	cout<<"TEN: ";
	gotoxy(boxx+7, 6);
	cout<<"GIOI TINH: ";
	gotoxy(boxx+7,7);
	cout<<"TRANG THAI: ";
	gotoxy(boxx+7,8);
	cout<<"SO LUONG SACH: ";
	gotoxy(tabx + 5, taby + 5);
	cout << char(218);
	for(int i = 1; i < tabs - 10; i++)
	{
		cout << char(196);
	}
	cout << char(191);
	for(int i = 1; i < 6; i++)
	{
		gotoxy(tabx + 5, taby +5+ i);
		cout << char(179);
	}

	for(int i = 1; i < 6; i++)
	{
		gotoxy(tabx +5+ tabs - 10, taby +5+ i);
		cout << char(179);
	}
	gotoxy(tabx + 5, taby+5 + 6);
	cout << char(192);
	for(int i = 1; i < tabs - 10; i++)
	{
		gotoxy(tabx+5 + i, taby +5+6);
		cout << char(196);
	}
	gotoxy(tabx +5+ tabs - 10, taby +5+6);
	cout << char(217);

	// Ma Sach
	gotoxy(tabx + 10, taby + 6); cout << "Ma Sach";
	gotoxy(tabx + 23, taby+5); cout << char(194);
	for(int i = 1; i < 2; i++)
	{
		gotoxy(tabx + 23, taby + 5 + i); cout << char(179);
	}
	gotoxy(tabx + 5, taby + 7);
	cout << char(195);
	for(int i = 1; i < tabs - 10; i++)
	{
		gotoxy(tabx + 5 + i, taby + 7);
		cout << char(196);
	}
	gotoxy(tabx + 23, taby + 7); cout << char(193);

	// Ten Sach
	gotoxy(tabx + 5 + 25, taby + 5 + 1); cout << "Ngay Muon";
	gotoxy(tabx + 5 +38, taby+5); cout << char(194);
	for(int i = 1; i < 2; i++)
	{
		gotoxy(tabx + 5 + 38, taby + 5+ i); cout << char(179);
	}
	gotoxy(tabx + 5+ 38, taby+ 5+ 2); cout << char(193);

	// Trang thai
	gotoxy(tabx +5+ 45, taby +5+ 1); cout << "Ngay Tra";
	gotoxy(tabx-2 +5+ 60, taby+5); cout << char(194);
	for(int i = 1; i < 2; i++)
	{
		gotoxy(tabx-2+5 + 60, taby +5+ i); cout << char(179);
	}
	gotoxy(tabx -2+5+ 60, taby+5 + 2); cout << char(193);
	
	// Vi tri
	gotoxy(tabx+ 66, taby +5+ 1); cout << "Trang Thai";
}


int Check_Muon_Sach(Tree &tt, Tree &t, string &text)
{
	const int STACKSIZE = 100;
	Tree *Stack = new Tree[STACKSIZE];// khoi tao mang Stack
	int sp = -1;
	Duyet_NLR(tt, Stack, sp);// duyet cay de dua cac node vao mang Satck
	for(int i=0; i<sp; i++)// duyet stack
	{
		if(Stack[i]->DG.MADG == t->DG.MADG)
		{
			for(NodeMuonTra *k = Stack[i]->MT.pHead; k!= NULL; k=k->pRight)// duyet Danh sach muon tra
					{
						if(k->data.MASACH == text && k->data.trangthai == 0)
						{
							return 1;
						}
					}
		}
	}
	return 0;
}

int XacNhanTra()
{
	int x = 93, y = 19;
	gotoxy(88, 12);
	textcolor(112);
	cout << "                                 ";
	gotoxy(88, 13); cout << "                                 ";
	gotoxy(88, 14); cout << " BAN CO CHAC CHAN TRA SACH KHONG?";
	gotoxy(88, 15); cout << "                                 ";
	gotoxy(88, 16); cout << "     YES                NO       ";
	gotoxy(88, 17); cout << "                                 ";
	int keyhit;
	do{
		gotoxy(93, 29);
		textcolor(121);
		switch(x)
		{
		case 93 : gotoxy(93, 16); cout << "YES"; break;
		case 112 : gotoxy(112, 16); cout << "NO"; break;
		}
		keyhit = getch();
		if(keyhit == LEFT)
		{
			gotoxy(93, 16);
			textcolor(112);
			switch(x)
			{
			case 93 : gotoxy(93, 16); cout << "YES"; break;
			case 112 : gotoxy(112, 16); cout << "NO"; break;
			}
			x -= 19;
			if(x != 93)
			{
				x = 112;
			}
		}
		else if(keyhit == RIGHT)
		{
			gotoxy(93, 16);
			textcolor(112);
			switch(x)
			{
			case 93 : gotoxy(93, 16); cout << "YES"; break;
			case 112 : gotoxy(112,16); cout << "NO"; break;
			}
			x += 19;
			if(x != 112)
			{
				x = 93;
			}
		}
		else if(x == 93 && keyhit == ENTER)
		{
			return 1;
		}
		else if(x == 112 && keyhit == ENTER)
		{
			return 0;
		}
	}while(true);
}

void Nhap_Doc_Gia_Tra_Sach(Tree &t, LDS &l, int &n)
{
	int z = 0;
	Tree dg = Check_Ma_Doc_Gia(t,z);
	if(z != 0)
	{
		textcolor(15);
		clrscr();
		Menu();
	}
	textcolor(15);
	clrscr();
	while(1)
	{
			Menu_Tam_Thoi(7);
			for(int i=1; i<50; i++)
			{
				gotoxy(3+i,37);
				cout<<char(220);
			}
			gotoxy(13,38); cout<<"F4: CHU THICH";
		    gotoxy(31,38); cout<<"ESC: THOAT";
			Table_Tra_Sach();
			textcolor(15);
			int dem = 0;
			gotoxy(98,3);cout << dg->DG.MADG; 
			gotoxy(98,4);cout << dg->DG.ho; 
			gotoxy(98,5);cout << dg->DG.ten; 
			gotoxy(98,6);cout << dg->DG.gioitinh;
			gotoxy(98,8);cout << dg->DG.sosachmuon;
			gotoxy(98,7);cout << dg->DG.trangthaithe;
		/*	if(dg->DG.trangthaithe == 0)
			{
				gotoxy(98,7);cout << "KHOA";
			}
			else if(dg->DG.trangthaithe == 1)
			{
				gotoxy(98,7);cout << "HOAT DONG";
			}*/
			int x =0;
			int f,h,e;
			for(NodeMuonTra *k = dg->MT.pHead; k!=NULL; k = k-> pRight)// duyet danh sach muon tra
			{
				if(k->data.trangthai == 0)
				{
					x++;
				}
			}
			if(x == 0)// doc gia k muon dau sach nao
			{	
			P:
				gotoxy(95,14);cout << "DOC GIA KHONG MUON SACH";
				int c = getch();
				if(c == ESC)
				{
					break;
				}
				else
				{
					goto P;
				}
			}
			else if(x == 1)// doc gia muon 1 sach
			{
				string ms;
				string str = "";
				f = 0;
				for(NodeMuonTra *k = dg->MT.pHead; k!=NULL; k = k->pRight)// duyet Danh sach mun tra
				{
					if(k->data.trangthai == 0)
					{
						ms = k->data.MASACH;
						str.append("       ");
						str.append(k->data.MASACH);
						str.append("           ");
						str.append(convertInt(k->data.ngaymuon.ngay));
						str.append("/");
						str.append(convertInt(k->data.ngaymuon.thang));
						str.append("/");
						str.append(convertInt(k->data.ngaymuon.nam));
						str.append("         ");
						str.append(convertInt(k->data.ngaytra.ngay));
						str.append("/");
						str.append(convertInt(k->data.ngaytra.thang));
						str.append("/");
						str.append(convertInt(k->data.ngaytra.nam));
						str.append("         ");
						str.append("         0    ");	
					}
				}
			X:
				gotoxy(70,13);
				textcolor(159);cout<<str;
				int keyhit = getch();
				if(keyhit == ENTER)
				{
					if(f == 0)
					{
						const int STACKSIZE = 100;
						Tree *a;
						a = new Tree[STACKSIZE];// khoi tao mang a
						int sp = -1;
						Duyet_NLR(t, a, sp);// duyet cay de dua cac node vao mang a
						for(int i=0; i<=sp; i++)// duyet mang a
						{
							if(a[i]->DG.MADG == dg->DG.MADG)
							{
								for(NodeMuonTra *k = a[i]->MT.pHead; k!= NULL; k=k->pRight)// duyet danh sach muon tra
								{
									if(k->data.MASACH == ms && k->data.trangthai == 0)
									{
										k->data.trangthai = 1;
										LayNgayHT(k->data.ngaytra);
										str="";
										str.append("       ");
										str.append(k->data.MASACH);
										str.append("           ");
										str.append(convertInt(k->data.ngaymuon.ngay));
										str.append("/");
										str.append(convertInt(k->data.ngaymuon.thang));
										str.append("/");
										str.append(convertInt(k->data.ngaymuon.nam));
										str.append("         ");
										str.append(convertInt(k->data.ngaytra.ngay));
										str.append("/");
										str.append(convertInt(k->data.ngaytra.thang));
										str.append("/");
										str.append(convertInt(k->data.ngaytra.nam));
										str.append("         ");
										str.append("      1    ");
										f = 1;
										for(int j=0; j<l.n; j++)// duyet dau sach
										{
											for(DMSNode *k = l.DS[j]->sach.pHead; k!=NULL; k = k->pNext )
											{
												if(k->data.maSach == ms)
												{
													k->data.ttSach = 0;
												}
											}
										}
										goto X;
									}
								}
							}
						}	
					}
					else if(f == 1)
					{
						const int STACKSIZE = 100;
						Tree *a;
						a = new Tree[STACKSIZE];
						int sp = -1;
						Duyet_NLR(t, a, sp);
						for(int i=0; i<=sp; i++)
						{
							if(a[i]->DG.MADG == dg->DG.MADG)
							{
								for(NodeMuonTra *k = a[i]->MT.pHead; k!= NULL; k=k->pRight)// duyet danh sach muon tra
								{
									if(k->data.MASACH == ms)
									{
										k->data.trangthai = 0;
										k->data.ngaytra.ngay =0;
										k->data.ngaytra.thang =0;
										k->data.ngaytra.nam =0;
										str = "";
										str.append("       ");
										str.append(k->data.MASACH);
										str.append("           ");
										str.append(convertInt(k->data.ngaymuon.ngay));
										str.append("/");
										str.append(convertInt(k->data.ngaymuon.thang));
										str.append("/");
										str.append(convertInt(k->data.ngaymuon.nam));
										str.append("         ");
										str.append(convertInt(k->data.ngaytra.ngay));
										str.append("/");
										str.append(convertInt(k->data.ngaytra.thang));
										str.append("/");
										str.append(convertInt(k->data.ngaytra.nam));
										str.append("         ");
										str.append("         0    ");
										f = 0;
										for(int j=0; j<l.n; j++)// duyet dau sach
										{
											for(DMSNode *k = l.DS[j]->sach.pHead; k!=NULL; k = k->pNext )
											{
												if(k->data.maSach == ms)
												{
													k->data.ttSach = 1;
												}
											}
										}
										goto X;
									}
								}
							}
						}	
					}
				}
				else if(keyhit == ESC)// thoat
				{
					break;
				}
				else if(keyhit == 0)
				{
					int f = getch();
					if(f == 62)
					{
						frameChuThichDocGia(13, 28);
						int u = getch();
						if(u == ESC)
						{
							textcolor(15);
							clrscr();
							goto X;	
						}	
					}
				}
			}
			else if(x == 2)// doc gia mun 2 cuon sach
			{
				int tt = 0;
				string ms1, ms2;
				string str = "";
				string str1 = "";
				f = 0,h =0;
				for(NodeMuonTra *k = dg->MT.pHead; k!=NULL; k = k->pRight)
					{
						if(k->data.trangthai == 0)
						{
							tt++;
							if(tt == 1)
							{
								ms1 = k->data.MASACH;
								str.append("       ");
								str.append(k->data.MASACH);
								str.append("           ");
								str.append(convertInt(k->data.ngaymuon.ngay));
								str.append("/");
								str.append(convertInt(k->data.ngaymuon.thang));
								str.append("/");
								str.append(convertInt(k->data.ngaymuon.nam));
								str.append("         ");
								str.append(convertInt(k->data.ngaytra.ngay));
								str.append("/");
								str.append(convertInt(k->data.ngaytra.thang));
								str.append("/");
								str.append(convertInt(k->data.ngaytra.nam));
								str.append("         ");
								str.append("         0    ");
							}
							else if(tt == 2)
							{
								ms2 = k->data.MASACH;
								str1.append("       ");
								str1.append(k->data.MASACH);
								str1.append("           ");
								str1.append(convertInt(k->data.ngaymuon.ngay));
								str1.append("/");
								str1.append(convertInt(k->data.ngaymuon.thang));
								str1.append("/");
								str1.append(convertInt(k->data.ngaymuon.nam));
								str1.append("         ");
								str1.append(convertInt(k->data.ngaytra.ngay));
								str1.append("/");
								str1.append(convertInt(k->data.ngaytra.thang));
								str1.append("/");
								str1.append(convertInt(k->data.ngaytra.nam));
								str1.append("         ");
								str1.append("         0    ");
							}
						}
					}
				int x = 70;
				int y = 13;
				V:
					int keyhit;
					gotoxy(70, 13); cout << str;
					gotoxy(70, 14); cout << str1;
					do{
						textcolor(159);// nen mau xanh
						switch (y)
						{
						case 13: gotoxy(x, 13); cout << str; break;
						case 14: gotoxy(x, 14); cout << str1; break;
						}
						keyhit = getch(); // Kiem Tra Nhan Lenh Ban Phim
						if (keyhit == UP) // Di Len
						{
							gotoxy(x, y);
							textcolor(15); // Doi thanh mau chu mau trang
							switch (y)
							{
							case 13: gotoxy(x, 13); cout << str; break;
							case 14: gotoxy(x, 14); cout << str1; break;
							}
							y--;
							if (y < 13)
							{
								y = 14;
							}
						}
						else if (keyhit == DOWN)
						{
							gotoxy(x, y);
							textcolor(15);
							switch (y)
							{
							case 13: gotoxy(x, 13); cout << str; break;
							case 14: gotoxy(x, 14); cout << str1; break;
							}
							y++;
							if (y > 14)
							{
								y = 13;
							}
						}
						else if (y == 13 && keyhit == ENTER)
						{
							if(f == 0)
							{
								textcolor(15); // Doi thanh mau chu mau trang
								switch (y)
								{
									case 13: gotoxy(x, 13); cout << str; break;
									case 14: gotoxy(x, 14); cout << str1; break;
								}	
								const int STACKSIZE = 100;
								Tree *a;
								a = new Tree[STACKSIZE];
								int sp = -1;
								Duyet_NLR(t, a, sp);
								for(int i=0; i<=sp; i++)
								{
									if(a[i]->DG.MADG == dg->DG.MADG)
									{
										for(NodeMuonTra *k = a[i]->MT.pHead; k!= NULL; k=k->pRight)
										{
											if(k->data.MASACH == ms1 && k->data.trangthai == 0)
											{
												k->data.trangthai = 1;
												LayNgayHT(k->data.ngaytra);
												str="";
												str.append("       ");
												str.append(k->data.MASACH);
												str.append("           ");
												str.append(convertInt(k->data.ngaymuon.ngay));
												str.append("/");
												str.append(convertInt(k->data.ngaymuon.thang));
												str.append("/");
												str.append(convertInt(k->data.ngaymuon.nam));
												str.append("         ");
												str.append(convertInt(k->data.ngaytra.ngay));
												str.append("/");
												str.append(convertInt(k->data.ngaytra.thang));
												str.append("/");
												str.append(convertInt(k->data.ngaytra.nam));
												str.append("         ");
												str.append("      1   ");
												f = 1;
												for(int j=0; j<l.n; j++)
												{
													for(DMSNode *k = l.DS[j]->sach.pHead; k!=NULL; k = k->pNext )
													{
														if(k->data.maSach == ms1)
														{
															k->data.ttSach = 0;
														}
													}
												}
												goto V;
											}
										}
									}
								}
							}
							else if(f == 1)
							{
								textcolor(15); // Doi thanh mau chu mau trang
								switch (y)
								{
									case 13: gotoxy(x, 13); cout << str; break;
									case 14: gotoxy(x, 14); cout << str1; break;
								}	
								const int STACKSIZE = 100;
								Tree *a;
								a = new Tree[STACKSIZE];
								int sp = -1;
								Duyet_NLR(t, a, sp);
								for(int i=0; i<=sp; i++)
								{
									if(a[i]->DG.MADG == dg->DG.MADG)
									{
										for(NodeMuonTra *k = a[i]->MT.pHead; k!= NULL; k=k->pRight)
										{
											if(k->data.MASACH == ms1)
											{
												k->data.trangthai = 0;
												k->data.ngaytra.ngay =0;
												k->data.ngaytra.thang =0;
												k->data.ngaytra.nam =0;
												str = "";
												str.append("       ");
												str.append(k->data.MASACH);
												str.append("           ");
												str.append(convertInt(k->data.ngaymuon.ngay));
												str.append("/");
												str.append(convertInt(k->data.ngaymuon.thang));
												str.append("/");
												str.append(convertInt(k->data.ngaymuon.nam));
												str.append("         ");
												str.append(convertInt(k->data.ngaytra.ngay));
												str.append("/");
												str.append(convertInt(k->data.ngaytra.thang));
												str.append("/");
												str.append(convertInt(k->data.ngaytra.nam));
												str.append("         ");
												str.append("         0    ");
												f = 0;
												for(int j=0; j<l.n; j++)
												{
													for(DMSNode *k = l.DS[j]->sach.pHead; k!=NULL; k = k->pNext )
													{
														if(k->data.maSach == ms1)
														{
															k->data.ttSach = 1;
														}
													}
												}
												goto V;
											}
										}
									}
								}	
							}
						}
						else if( y == 14 && keyhit == ENTER)
						{
							if(h == 0)
							{
								textcolor(15); // Doi thanh mau chu mau trang
								switch (y)
								{
									case 13: gotoxy(x, 13); cout << str; break;
									case 14: gotoxy(x, 14); cout << str1; break;
								}	
								const int STACKSIZE = 100;
								Tree *a;
								a = new Tree[STACKSIZE];
								int sp = -1;
								Duyet_NLR(t, a, sp);
								for(int i=0; i<=sp; i++)
								{
									if(a[i]->DG.MADG == dg->DG.MADG)
									{
										for(NodeMuonTra *k = a[i]->MT.pHead; k!= NULL; k=k->pRight)
										{
											if(k->data.MASACH == ms2 && k->data.trangthai == 0)
											{
												k->data.trangthai = 1;
												LayNgayHT(k->data.ngaytra);
												str1="";
												str1.append("       ");
												str1.append(k->data.MASACH);
												str1.append("           ");
												str1.append(convertInt(k->data.ngaymuon.ngay));
												str1.append("/");
												str1.append(convertInt(k->data.ngaymuon.thang));
												str1.append("/");
												str1.append(convertInt(k->data.ngaymuon.nam));
												str1.append("         ");
												str1.append(convertInt(k->data.ngaytra.ngay));
												str1.append("/");
												str1.append(convertInt(k->data.ngaytra.thang));
												str1.append("/");
												str1.append(convertInt(k->data.ngaytra.nam));
												str1.append("         ");
												str1.append("      1   ");
												h = 1;
												for(int j=0; j<l.n; j++)
												{
													for(DMSNode *k = l.DS[j]->sach.pHead; k!=NULL; k = k->pNext )
													{
														if(k->data.maSach == ms2)
														{
															k->data.ttSach = 0;
														}
													}
												}
												const int STACKSIZE = 100;
												Tree Stack[STACKSIZE];// kkoi tao mang stack 
												int sp = -1;
												goto V;
											}
										}
									}
								}	
							}
						else if(h == 1)
							{
								textcolor(15); // Doi thanh mau chu mau trang
								switch (y)
								{
									case 13: gotoxy(x, 13); cout << str; break;
									case 14: gotoxy(x, 14); cout << str1; break;
								}	
								const int STACKSIZE = 100;
								Tree *a;
								a = new Tree[STACKSIZE];
								int sp = -1;
								Duyet_NLR(t, a, sp);
								for(int i=0; i<=sp; i++)
								{
									if(a[i]->DG.MADG == dg->DG.MADG)
									{
										for(NodeMuonTra *k = a[i]->MT.pHead; k!= NULL; k=k->pRight)
										{
											if(k->data.MASACH == ms2)
											{
												k->data.trangthai = 0;
												k->data.ngaytra.ngay =0;
												k->data.ngaytra.thang =0;
												k->data.ngaytra.nam =0;
												str1="";
												str1.append("       ");
												str1.append(k->data.MASACH);
												str1.append("           ");
												str1.append(convertInt(k->data.ngaymuon.ngay));
												str1.append("/");
												str1.append(convertInt(k->data.ngaymuon.thang));
												str1.append("/");
												str1.append(convertInt(k->data.ngaymuon.nam));
												str1.append("         ");
												str1.append(convertInt(k->data.ngaytra.ngay));
												str1.append("/");
												str1.append(convertInt(k->data.ngaytra.thang));
												str1.append("/");
												str1.append(convertInt(k->data.ngaytra.nam));
												str1.append("         ");
												str1.append("         0    ");
												h = 0;
												for(int j=0; j<l.n; j++)
												{
													for(DMSNode *k = l.DS[j]->sach.pHead; k!=NULL; k = k->pNext )
													{
														if(k->data.maSach == ms2)
														{
															k->data.ttSach = 1;
														}
													}
												}
												goto V;
											}
										}
									}
								}	
							}
						}
						else if(keyhit == ESC)
						{
							break;
						}
						else if(keyhit == 0)
						{
							int f = getch();
							if(f == 62)
							{
								frameChuThichDocGia(13, 28);
								int u = getch();
								if(u == ESC)
								{
									textcolor(15);
									clrscr();
									goto V;	
								}	
							}
						}
					}while(1);
				}
				else if(x == 3)// doc gia muon 3 cuon
				{
					int tt = 0;
					string ms1, ms2, ms3;
					string str = "";
					string str1 = "";
					string str2 = "";
					f = 0, h =0, e=0;
					for(NodeMuonTra *k = dg->MT.pHead; k!=NULL; k = k->pRight)
						{
							if(k->data.trangthai == 0)
							{
								tt++;
								if(tt == 1)
								{
									ms1 = k->data.MASACH;
									str.append("       ");
									str.append(k->data.MASACH);
									str.append("           ");
									str.append(convertInt(k->data.ngaymuon.ngay));
									str.append("/");
									str.append(convertInt(k->data.ngaymuon.thang));
									str.append("/");
									str.append(convertInt(k->data.ngaymuon.nam));
									str.append("         ");
									str.append(convertInt(k->data.ngaytra.ngay));
									str.append("/");
									str.append(convertInt(k->data.ngaytra.thang));
									str.append("/");
									str.append(convertInt(k->data.ngaytra.nam));
									str.append("         ");
									str.append("         0    ");
								}
								else if(tt == 2)
								{
									ms2 = k->data.MASACH;
									str1.append("       ");
									str1.append(k->data.MASACH);
									str1.append("           ");
									str1.append(convertInt(k->data.ngaymuon.ngay));
									str1.append("/");
									str1.append(convertInt(k->data.ngaymuon.thang));
									str1.append("/");
									str1.append(convertInt(k->data.ngaymuon.nam));
									str1.append("         ");
									str1.append(convertInt(k->data.ngaytra.ngay));
									str1.append("/");
									str1.append(convertInt(k->data.ngaytra.thang));
									str1.append("/");
									str1.append(convertInt(k->data.ngaytra.nam));
									str1.append("         ");
									str1.append("         0    ");
								}
								else if(tt == 3)
								{
									ms3 = k->data.MASACH;
									str2.append("       ");
									str2.append(k->data.MASACH);
									str2.append("           ");
									str2.append(convertInt(k->data.ngaymuon.ngay));
									str2.append("/");
									str2.append(convertInt(k->data.ngaymuon.thang));
									str2.append("/");
									str2.append(convertInt(k->data.ngaymuon.nam));
									str2.append("         ");
									str2.append(convertInt(k->data.ngaytra.ngay));
									str2.append("/");
									str2.append(convertInt(k->data.ngaytra.thang));
									str2.append("/");
									str2.append(convertInt(k->data.ngaytra.nam));
									str2.append("         ");
									str2.append("         0    ");
								}
							}
						}
						int x = 70;
						int y = 13;
						T:
							int keyhit;
							gotoxy(70, 13); cout << str;
							gotoxy(70, 14); cout << str1;
							gotoxy(70, 15); cout << str2;
							do{
								textcolor(159);// nen mau xanh
								switch (y)
								{
								case 13: gotoxy(x, 13); cout << str; break;
								case 14: gotoxy(x, 14); cout << str1; break;
								case 15: gotoxy(x, 15); cout << str2; break;
								}
								keyhit = getch(); // Kiem Tra Nhan Lenh Ban Phim
								if (keyhit == UP) // Di Len
								{
									gotoxy(x, y);
									textcolor(15); // Doi thanh mau chu mau trang
									switch (y)
									{
									case 13: gotoxy(x, 13); cout << str; break;
									case 14: gotoxy(x, 14); cout << str1; break;
									case 15: gotoxy(x, 15); cout << str2; break;
									}
									y--;
									if (y < 13)
									{
										y = 15;
									}
								}
								else if (keyhit == DOWN)
								{
									gotoxy(x, y);
									textcolor(15);
									switch (y)
									{
									case 13: gotoxy(x, 13); cout << str; break;
									case 14: gotoxy(x, 14); cout << str1; break;
									case 15: gotoxy(x, 15); cout << str2; break;
									}
									y++;
									if (y > 15)
									{
										y = 13;
									}
								}
								else if (y == 13 && keyhit == ENTER)
								{
									if(f == 0)
									{
										textcolor(15); // Doi thanh mau chu mau trang
										switch (y)
										{
											case 13: gotoxy(x, 13); cout << str; break;
											case 14: gotoxy(x, 14); cout << str1; break;
											case 15: gotoxy(x, 15); cout << str2; break;
										}	
										const int STACKSIZE = 100;
										Tree *a;
										a = new Tree[STACKSIZE];
										int sp = -1;
										Duyet_NLR(t, a, sp);
										for(int i=0; i<=sp; i++)
										{
											if(a[i]->DG.MADG == dg->DG.MADG)
											{
												for(NodeMuonTra *k = a[i]->MT.pHead; k!= NULL; k=k->pRight)
												{
													if(k->data.MASACH == ms1 && k->data.trangthai == 0)
													{
														k->data.trangthai = 1;
														LayNgayHT(k->data.ngaytra);
														str="";
														str.append("       ");
														str.append(k->data.MASACH);
														str.append("           ");
														str.append(convertInt(k->data.ngaymuon.ngay));
														str.append("/");
														str.append(convertInt(k->data.ngaymuon.thang));
														str.append("/");
														str.append(convertInt(k->data.ngaymuon.nam));
														str.append("         ");
														str.append(convertInt(k->data.ngaytra.ngay));
														str.append("/");
														str.append(convertInt(k->data.ngaytra.thang));
														str.append("/");
														str.append(convertInt(k->data.ngaytra.nam));
														str.append("         ");
														str.append("      1    ");
														f = 1;
														for(int j=0; j<l.n; j++)
														{
															for(DMSNode *k = l.DS[j]->sach.pHead; k!=NULL; k = k->pNext )
															{
																if(k->data.maSach == ms1)
																{
																	k->data.ttSach = 0;
																}
															}
														}
														goto T;
													}
												}
											}
										}
									}
									else if(f == 1)
									{
										textcolor(15); // Doi thanh mau chu mau trang
										switch (y)
										{
											case 13: gotoxy(x, 13); cout << str; break;
											case 14: gotoxy(x, 14); cout << str1; break;
											case 15: gotoxy(x, 15); cout << str2; break;
										}	
										const int STACKSIZE = 100;
										Tree *a;
										a = new Tree[STACKSIZE];
										int sp = -1;
										Duyet_NLR(t, a, sp);
										for(int i=0; i<=sp; i++)
										{
											if(a[i]->DG.MADG == dg->DG.MADG)
											{
												for(NodeMuonTra *k = a[i]->MT.pHead; k!= NULL; k=k->pRight)
												{
													if(k->data.MASACH == ms1)
													{
														k->data.trangthai = 0;
														k->data.ngaytra.ngay =0;
														k->data.ngaytra.thang =0;
														k->data.ngaytra.nam =0;
														str = "";
														str.append("       ");
														str.append(k->data.MASACH);
														str.append("           ");
														str.append(convertInt(k->data.ngaymuon.ngay));
														str.append("/");
														str.append(convertInt(k->data.ngaymuon.thang));
														str.append("/");
														str.append(convertInt(k->data.ngaymuon.nam));
														str.append("         ");
														str.append(convertInt(k->data.ngaytra.ngay));
														str.append("/");
														str.append(convertInt(k->data.ngaytra.thang));
														str.append("/");
														str.append(convertInt(k->data.ngaytra.nam));
														str.append("         ");
														str.append("         0    ");
														f = 0;
														for(int j=0; j<l.n; j++)
														{
															for(DMSNode *k = l.DS[j]->sach.pHead; k!=NULL; k = k->pNext )
															{
																if(k->data.maSach == ms1)
																{
																	k->data.ttSach = 1;
																}
															}
														}
														goto T;
													}
												}
											}
										}	
									}
								}
								else if (y == 14 && keyhit == ENTER)
								{
									if(h == 0)
									{
										textcolor(15); // Doi thanh mau chu mau trang
										switch (y)
										{
											case 13: gotoxy(x, 13); cout << str; break;
											case 14: gotoxy(x, 14); cout << str1; break;
											case 15: gotoxy(x, 15); cout << str2; break;
										}	
										const int STACKSIZE = 100;
										Tree *a;
										a = new Tree[STACKSIZE];
										int sp = -1;
										Duyet_NLR(t, a, sp);
										for(int i=0; i<=sp; i++)
										{
											if(a[i]->DG.MADG == dg->DG.MADG)
											{
												for(NodeMuonTra *k = a[i]->MT.pHead; k!= NULL; k=k->pRight)
												{
													if(k->data.MASACH == ms2 && k->data.trangthai == 0)
													{
														k->data.trangthai = 1;
														LayNgayHT(k->data.ngaytra);
														str1="";
														str1.append("       ");
														str1.append(k->data.MASACH);
														str1.append("           ");
														str1.append(convertInt(k->data.ngaymuon.ngay));
														str1.append("/");
														str1.append(convertInt(k->data.ngaymuon.thang));
														str1.append("/");
														str1.append(convertInt(k->data.ngaymuon.nam));
														str1.append("         ");
														str1.append(convertInt(k->data.ngaytra.ngay));
														str1.append("/");
														str1.append(convertInt(k->data.ngaytra.thang));
														str1.append("/");
														str1.append(convertInt(k->data.ngaytra.nam));
														str1.append("         ");
														str1.append("      1    ");
														h = 1;
														for(int j=0; j<l.n; j++)
														{
															for(DMSNode *k = l.DS[j]->sach.pHead; k!=NULL; k = k->pNext )
															{
																if(k->data.maSach == ms2)
																{
																	k->data.ttSach = 0;
																}
															}
														}
														goto T;
													}
												}
											}
										}
									}
									else if(h == 1)
									{
										textcolor(15); // Doi thanh mau chu mau trang
										switch (y)
										{
											case 13: gotoxy(x, 13); cout << str; break;
											case 14: gotoxy(x, 14); cout << str1; break;
											case 15: gotoxy(x, 15); cout << str2; break;
										}	
										const int STACKSIZE = 100;
										Tree *a;
										a = new Tree[STACKSIZE];
										int sp = -1;
										Duyet_NLR(t, a, sp);
										for(int i=0; i<=sp; i++)
										{
											if(a[i]->DG.MADG == dg->DG.MADG)
											{
												for(NodeMuonTra *k = a[i]->MT.pHead; k!= NULL; k=k->pRight)
												{
													if(k->data.MASACH == ms2)
													{
														k->data.trangthai = 0;
														k->data.ngaytra.ngay =0;
														k->data.ngaytra.thang =0;
														k->data.ngaytra.nam =0;
														str1 = "";
														str1.append("       ");
														str1.append(k->data.MASACH);
														str1.append("           ");
														str1.append(convertInt(k->data.ngaymuon.ngay));
														str1.append("/");
														str1.append(convertInt(k->data.ngaymuon.thang));
														str1.append("/");
														str1.append(convertInt(k->data.ngaymuon.nam));
														str1.append("         ");
														str1.append(convertInt(k->data.ngaytra.ngay));
														str1.append("/");
														str1.append(convertInt(k->data.ngaytra.thang));
														str1.append("/");
														str1.append(convertInt(k->data.ngaytra.nam));
														str1.append("         ");
														str1.append("         0    ");
														h = 0;
														for(int j=0; j<l.n; j++)
														{
															for(DMSNode *k = l.DS[j]->sach.pHead; k!=NULL; k = k->pNext )
															{
																if(k->data.maSach == ms2)
																{
																	k->data.ttSach = 1;
																}
															}
														}
														goto T;
													}
												}
											}
										}	
									}
								}
								else if (y == 15 && keyhit == ENTER)
								{
									if(e == 0)
									{
										textcolor(15); // Doi thanh mau chu mau trang
										switch (y)
										{
											case 13: gotoxy(x, 13); cout << str; break;
											case 14: gotoxy(x, 14); cout << str1; break;
											case 15: gotoxy(x, 15); cout << str2; break;
										}	
										const int STACKSIZE = 100;
										Tree *a;
										a = new Tree[STACKSIZE];
										int sp = -1;
										Duyet_NLR(t, a, sp);
										for(int i=0; i<=sp; i++)
										{
											if(a[i]->DG.MADG == dg->DG.MADG)
											{
												for(NodeMuonTra *k = a[i]->MT.pHead; k!= NULL; k=k->pRight)
												{
													if(k->data.MASACH == ms3 && k->data.trangthai == 0)
													{
														k->data.trangthai = 1;
														LayNgayHT(k->data.ngaytra);
														str2="";
														str2.append("       ");
														str2.append(k->data.MASACH);
														str2.append("           ");
														str2.append(convertInt(k->data.ngaymuon.ngay));
														str2.append("/");
														str2.append(convertInt(k->data.ngaymuon.thang));
														str2.append("/");
														str2.append(convertInt(k->data.ngaymuon.nam));
														str2.append("         ");
														str2.append(convertInt(k->data.ngaytra.ngay));
														str2.append("/");
														str2.append(convertInt(k->data.ngaytra.thang));
														str2.append("/");
														str2.append(convertInt(k->data.ngaytra.nam));
														str2.append("         ");
														str2.append("      1    ");
														e = 1;
														for(int j=0; j<l.n; j++)
														{
															for(DMSNode *k = l.DS[j]->sach.pHead; k!=NULL; k = k->pNext )
															{
																if(k->data.maSach == ms3)
																{
																	k->data.ttSach = 0;
																}
															}
														}
														goto T;
													}
												}
											}
										}
									}
									else if(e == 1)
									{
										textcolor(15); // Doi thanh mau chu mau trang
										switch (y)
										{
											case 13: gotoxy(x, 13); cout << str; break;
											case 14: gotoxy(x, 14); cout << str1; break;
											case 15: gotoxy(x, 15); cout << str2; break;
										}	
										const int STACKSIZE = 100;
										Tree *a;
										a = new Tree[STACKSIZE];
										int sp = -1;
										Duyet_NLR(t, a, sp);
										for(int i=0; i<=sp; i++)
										{
											if(a[i]->DG.MADG == dg->DG.MADG)
											{
												for(NodeMuonTra *k = a[i]->MT.pHead; k!= NULL; k=k->pRight)
												{
													if(k->data.MASACH == ms3)
													{
														k->data.trangthai = 0;
														k->data.ngaytra.ngay =0;
														k->data.ngaytra.thang =0;
														k->data.ngaytra.nam =0;
														str2 = "";
														str2.append("       ");
														str2.append(k->data.MASACH);
														str2.append("           ");
														str2.append(convertInt(k->data.ngaymuon.ngay));
														str2.append("/");
														str2.append(convertInt(k->data.ngaymuon.thang));
														str2.append("/");
														str2.append(convertInt(k->data.ngaymuon.nam));
														str2.append("         ");
														str2.append(convertInt(k->data.ngaytra.ngay));
														str2.append("/");
														str2.append(convertInt(k->data.ngaytra.thang));
														str2.append("/");
														str2.append(convertInt(k->data.ngaytra.nam));
														str2.append("         ");
														str2.append("         0    ");
														e = 0;
														for(int j=0; j<l.n; j++)
														{
															for(DMSNode *k = l.DS[j]->sach.pHead; k!=NULL; k = k->pNext )
															{
																if(k->data.maSach == ms3)
																{
																	k->data.ttSach = 1;
																}
															}
														}
														goto T;
													}
												}
											}
										}	
									}
								}
								else if(keyhit == ESC)
								{
									break;
								}
								else if(keyhit == 0)
								{
									int f = getch();
									if(f == 62)
									{
										frameChuThichDocGia(13, 28);
										int u = getch();
										if(u == ESC)
										{
											textcolor(15);
											clrscr();
											goto T;	
										}	
									}
								}
					}while(1);
				}
				break;
			}
}

void Tra_Sach(Tree &l, LDS &t)
{
	int a = 1;
	int b = 14;
	textcolor(15);
	clrscr();
	while(1)
	{
Xuat:
	int v = 0;
	int m = 1;
	int d =0;
	LoadtuFile_DSDG(l);
	textcolor(15);
	Menu_Tam_Thoi(7);
	Trang_Sau_Truoc();
	for(int i=1; i<50; i++)
	{
		gotoxy(3+i,37);
		cout<<char(220);
	}
	gotoxy(6,38); cout<<"F1: NHAP DOC GIA";
	gotoxy(25,38); cout<<"F4: CHU THICH";
    gotoxy(42,38); cout<<"ESC: THOAT";
	Giao_Dien();
	gotoxy(100,3);
	cout << "DANH SACH DOC GIA";
	gotoxy(tabx, taby);
	cout << char(218);
	for(int i = 1; i < tabs; i++)
	{
		cout << char(196);
	}
	cout << char(191);
	gotoxy(tabx + 15, taby); cout << char(194);
	gotoxy(tabx + 31, taby); cout << char(194);
	gotoxy(tabx + 47, taby); cout << char(194);
	gotoxy(tabx + 58, taby); cout << char(194);
	gotoxy(tabx , taby + 1); cout << char(179);
	gotoxy(tabx + 15, taby + 1); cout << char(179);
	gotoxy(tabx + 3, taby + 1); cout << "MA DOC GIA";
	gotoxy(tabx + 31, taby + 1); cout << char(179);
	gotoxy(tabx + 19, taby + 1); cout << "HO DOC GIA";
	gotoxy(tabx + 47, taby + 1); cout << char(179);
	gotoxy(tabx + 34, taby + 1); cout << "TEN DOC GIA";
	gotoxy(tabx + 58, taby + 1); cout << char(179);
	gotoxy(tabx + 51, taby + 1); cout << "PHAI";
	gotoxy(tabx + 82, taby + 1); cout << char(179);
	gotoxy(tabx + 62, taby + 1); cout << "TRANG THAI THE";
	int dem = 0;
	textcolor(15);
	const int STACKSIZE = 100;
	Tree Stack[STACKSIZE];// khoi tao mang stack
	int sp = -1;
	do
		{
			while (l != NULL)
			{
				Stack[++sp] = l;
				l = l->pLeft;
			}
			if (sp != -1)
			{
				l = Stack[sp--];
				d++;
				if(d>=a && d <= b)
				{
					v = v +2;
					TableDG1(l,dem,v,m);	
				}
				l = l->pRight;
			}
			else break;
		} while (1);
		if(v <= 28)
		{
			gotoxy(tabx, taby + v+2);
			cout << char(192);
			for(int i = 1; i < tabs; i++)
			{
				cout << char(196);
			}
			cout << char(191);
			gotoxy(tabx + 15, taby +v +2); cout << char(193);
			gotoxy(tabx + 31, taby +v +2); cout << char(193);
			gotoxy(tabx + 47, taby+v+2); cout << char(193);
			gotoxy(tabx + 58, taby+v+2); cout << char(193);
			gotoxy(tabx + tabs, taby +v+2); cout << char(217);
		}
		int keyhit = getch();// kiem tra bat phim
		if(keyhit == 224 ) // xem trang sau
		{
			int f = getch();
			if(f == 81)
			{
				if(d<=b)
				{
					textcolor(15);
					clrscr();
					goto Xuat;
				}
				a = b+1;
				b = b +14;
				textcolor(15);
				clrscr();
				goto Xuat;	
			}
			else if(f == 73)// xem trang truoc
			{
				if(a == 1 && b == 14)
				{
					textcolor(15);
					clrscr();
					goto Xuat;
				}
				a = a-14;
				b = b-14;
				textcolor(15);
				clrscr();
				goto Xuat;
			}
		}
		else if(keyhit == 27)//thoat
		{
			textcolor(15);
			clrscr();
			break;
		}
		else if(keyhit == 0)// Phim F1
		{
			int f = getch();
			if(f == 59)
			{
				int n =0;
				Nhap_Doc_Gia_Tra_Sach(l, t, n);
				int s = XacNhanTra();
				if(s ==1)// xac nhan yes
				{
					GhiFileDS(t);
					GhiFileDG(l);
					textcolor(15);
					clrscr();	
				}
				else
				{
					textcolor(15);
					clrscr();	
				}
				if(n!=0)
				{
					break;
				}		
			}
			else if(f == 62)
			{
				frameChuThichDocGia(13, 28);
				int u = getch();
				if(u == ESC)
				{
					textcolor(15);
					clrscr();
					goto Xuat;	
				}
			}
		}
	}
}

///***********************************  THANH LY SACH  **************************************
int XacNhanDenSach()
{
		int x = 95, y = 19;
	gotoxy(90, 20);
	textcolor(112);
	cout << "                                ";
	gotoxy(90, 21); cout << "                                ";
	gotoxy(90, 22); cout << "   DOC GIA CO DEN SACH KHONG?   ";
	gotoxy(90, 23); cout << "                                ";
	gotoxy(90, 24); cout << "     YES                NO      ";
	gotoxy(90, 25); cout << "                                ";
	int keyhit;
	do{
		gotoxy(98, 24);
		textcolor(121);
		switch(x)
		{
		case 95 : gotoxy(95, 24); cout << "YES"; break;
		case 114 : gotoxy(114, 24); cout << "NO"; break;
		}
		keyhit = getch();
		if(keyhit == LEFT)
		{
			gotoxy(95, 24);
			textcolor(112);
			switch(x)
			{
			case 95 : gotoxy(95, 24); cout << "YES"; break;
			case 114 : gotoxy(114, 24); cout << "NO"; break;
			}
			x -= 19;
			if(x != 95)
			{
				x = 114;
			}
		}
		else if(keyhit == RIGHT)
		{
			gotoxy(95, 24);
			textcolor(112);
			switch(x)
			{
			case 95 : gotoxy(95, 24); cout << "YES"; break;
			case 114 : gotoxy(114, 24); cout << "NO"; break;
			}
			x += 19;
			if(x != 114)
			{
				x = 95;
			}
		}
		else if(x == 95 && keyhit == ENTER)
		{
			textcolor(15);
			gotoxy(97, 27);
			cout << "LUU FILE THANH CONG";
			Sleep(1000);
			return 1;
		}
		else if(x == 114 && keyhit == ENTER)
		{
			return 0;
		}
		else if(keyhit == ESC)
		{
			return 2;
		}
	}while(true);
}

void Mat_Sach(Tree &tt, Tree &t,LDS &l, string &text, string &str, int &d)
{
	if(tt!=NULL)
	{
		if(tt->DG.MADG == t->DG.MADG)
		{
			if(d == 1)
			{
				tt->DG.trangthaithe = 0;
			}
			for(NodeMuonTra *k = tt->MT.pHead; k!=NULL; k=k->pRight)
			{
				if(k->data.MASACH == text)
				{
					k->data.trangthai = 2;
				}
			}
		}
		for(int i=0; i<l.n; i++)
		{
			if(l.DS[i]->ISBN == str)
			{
				for(DMSNode *k = l.DS[i]->sach.pHead; k!=NULL; k = k->pNext)
				{
					if(k->data.maSach == text)
					{
						k->data.ttSach = 2;
					}
				}
			}
		}
		Mat_Sach(tt->pLeft, t,l, text,str,d);
		Mat_Sach(tt->pRight, t,l, text,str,d);
	}
}

void Nhap_Ma_Sach_Mat(Tree &tt ,Tree &t, LDS &l,int &g,int &k)
{
	int v = 0;
	DMS:
		if(v != 0)
		{
			return;
		}
	textcolor(15);
	frameMaSach(13,28);// bang nhap ma sach
		int x = 17, y = 28;
		int keyhit, dem;
		string text, field;
		field = "";	
		keyhit = 0;
		dem = field.length();
		text = field;
		while(1)
		{
			textcolor(253);
			gotoxy(x + 5, y + 1);
			if(dem < 9)
			{
				cout << text;
				for(int i = 1; i < 11 - dem; i++) cout << " ";
			}
			else
			{
				for(int i = dem - 9; i < dem; i++)
				cout << text[i];
			}
			if(dem < 9) gotoxy(x + 5 + dem, y + 1);
			keyhit = getch();
			if(keyhit == BACKSPACE)
			{
				if(dem > 0)
				{
					dem--;
					text = text.substr(0, text.size() - 1);
				}
			}
			else if(keyhit == ESC)
			{
				k++;
				textcolor(15);
				clrscr();
				break;
			}
			else if(keyhit == ENTER)
	 		{
				if(text == "")
				{
					textcolor(15);
					keyhit = 0;
					gotoxy(15, 32);
					textcolor(112);
					cout << "(VUI LONG NHAP MA SACH!)";// bi Table_DMS chen len tren
					int keyhit1 = getch();
					textcolor(15);
					gotoxy(15, 32); cout<<"                             ";
					goto DMS;
				}
				else
				{
					textcolor(15);
					if(text.length() > 25)
					{
						gotoxy(17, 32);
						textcolor(112);
						cout << "(MA SACH QUA DAI)";
						int keyhit1 = getch();
						textcolor(15);
						gotoxy(17, 32);cout << "                             ";
						goto DMS;	
					}
					else
					{
						string str="";
						int j = -1;
						for(int i=0; i<text.length(); i++)
						{
							if(text[i] == '-')
							{
								break;
							}
							str.push_back(text[i]);
						}
						for(int i=0; i<l.n; i++)
						{
							if(l.DS[i]->ISBN == str)
							{
								if(TimKiem_DMS(l.DS[i]->sach, text) == 0)
								{
									gotoxy(15, 32);
									textcolor(112);					
									cout << "MA SACH KHONG TON TAI";
									int keyhit1 = getch();
									textcolor(15);
									gotoxy(15, 32); cout<<"                           ";
									goto DMS;
								}
								else
								{
									const int STACKSIZE = 100;
									Tree *a;
									a =new Tree[STACKSIZE];
									int sp = -1;
									Duyet_NLR(tt, a, sp);
									for(int i=0; i<=sp; i++)
									{
										if(a[i]->DG.MADG == t->DG.MADG)
											{
												for(NodeMuonTra *k = a[i]->MT.pHead; k != NULL; k = k->pRight)
												{
													if(k->data.MASACH == text && k->data.trangthai == 0)
													{
														int a = XacNhanDenSach();
														{
															if(a == 2)
															{
																v++;
																textcolor(15);
																clrscr();
																goto DMS;
															}
															else if(a == 1)
															{
																v++;
																int d = 0;
																Mat_Sach(tt,t,l,text,str,d);
																GhiFileDG(tt);
																GhiFileDS(l);
																textcolor(15);
																clrscr();
																goto DMS;
															}
															else
															{
																v++;
																int d = 1;
																Mat_Sach(tt,t,l,text,str,d);
																GhiFileDG(tt);
																GhiFileDS(l);
																textcolor(15);
																clrscr();
																goto DMS;
															}
														}
													}
													if(k->pRight == NULL)
													{
														gotoxy(10, 32);
														textcolor(112);					
														cout << ".KHONG CO TRONG DANH SACH MUON.";
														int keyhit1 = getch();
														goto DMS;
													}
												}
											}
										}
										break;
									}
								}
								else if(i == l.n -1)
								{
									gotoxy(15, 32);
									textcolor(112);					
									cout << "MA SACH KHONG TON TAI";
									int keyhit1 = getch();
									textcolor(15);
									gotoxy(15, 32); cout<<"                           ";
									goto DMS;
								}
							}
							break;
						}
					}
			}
			else 
			{
				dem++;
				text += toupper((char)keyhit);
			}
		}
}

void Nhap_Doc_Gia_Lam_Mat_Sach(Tree &t, LDS &l, int &n)
{
	int z = 0;
	Tree dg = Check_Ma_Doc_Gia(t,z);
	if(z != 0)
	{
		textcolor(15);
		clrscr();
		Menu();
	}
	while(1)
	{
		Doc_Gia:
			int v =0;
			int m = 1;
			textcolor(15);
			clrscr();
			Menu_Tam_Thoi(8);
			for(int i=1; i<50; i++)
			{
				gotoxy(3+i,37);
				cout<<char(220);
			}
			gotoxy(6,38); cout<<"F1: NHAP MA SACH";
			gotoxy(25,38); cout<<"F4: CHU THICH";
		    gotoxy(42,38); cout<<"ESC: THOAT";
			Giao_Dien();
			Khung_Dau_Sach();
			gotoxy(boxx+7, 3);
			cout<<"MA THE: ";
			gotoxy(boxx+7, 4);
			cout<<"HO: ";
			gotoxy(boxx+7, 5);
			cout<<"TEN: ";
			gotoxy(boxx+7, 6);
			cout<<"GIOI TINH: ";
			gotoxy(boxx+7,7);
			cout<<"TRANG THAI: ";
			gotoxy(boxx+7,8);
			cout<<"SO LUONG SACH: ";
			textcolor(15);
			int dem = 0;
			gotoxy(98,3);cout << dg->DG.MADG; 
			gotoxy(98,4);cout << dg->DG.ho; 
			gotoxy(98,5);cout << dg->DG.ten; 
			gotoxy(98,6);cout << dg->DG.gioitinh;
			gotoxy(98,8);cout << dg->DG.sosachmuon;
			
			if(dg->DG.trangthaithe == 0)
			{
				gotoxy(98,7);cout << "KHOA";
			}
			else if(dg->DG.trangthaithe == 1)
			{
				gotoxy(98,7);cout << "HOAT DONG";
			}
			gotoxy(tabx + 5, taby + 5);
	cout << char(218);
	for(int i = 1; i < tabs - 10; i++)
	{
		cout << char(196);
	}
	cout << char(191);	
	gotoxy(tabx + 22, taby + 5); cout << char(194);
	gotoxy(tabx + 42, taby + 5); cout << char(194);
	gotoxy(tabx + 60, taby + 5); cout << char(194);
	gotoxy(tabx + 5, taby + 6); cout << char(179);
	gotoxy(tabx + 22, taby + 6); cout << char(179);
	gotoxy(tabx + 10, taby + 6); cout << "MA SACH";
	gotoxy(tabx + 42, taby + 6); cout << char(179);
	gotoxy(tabx + 27, taby + 6); cout << "NGAY MUON";
	gotoxy(tabx + 60, taby + 6); cout << char(179);
	gotoxy(tabx + 48, taby + 6); cout << "NGAY TRA";
	gotoxy(tabx + 77, taby + 6); cout << char(179);
	gotoxy(tabx + 65, taby + 6); cout << "TRANG THAI";
			for(NodeMuonTra *k = dg->MT.pHead; k!=NULL; k = k->pRight)
			{
				if(k->data.trangthai == 0)
				{
					v = v +2;
					Table_Muon_Sach(k, dem, v, m);	
				}
			}
			if(v <= 6)
			{
				gotoxy(tabx + 5, taby + v+7);
				cout << char(192);
				for(int i = 1; i < tabs - 10; i++)
				{
					cout << char(196);
				}
				gotoxy(tabx + 22, taby +v +7); cout << char(193);
				gotoxy(tabx + 42, taby +v +7); cout << char(193);
				gotoxy(tabx + 60, taby+v+7); cout << char(193);
				gotoxy(tabx + 5 + tabs - 10, taby +v+7); cout << char(217);
			}
			int keyhit = getch();
			if(keyhit == 0)
			{
				int f = getch();
				if(f == 59)
				{
					int k = 0;
					int g = 0;
					Nhap_Ma_Sach_Mat(t,dg, l,g,k);
					if(g != 0)
					{
						goto Doc_Gia;
					}
					if(k != 0)
					{
						break;
					}	
				}
				else if(f == 62)
				{
					frameChuThichDanhMucSach(13, 28);
					int u = getch();
					if(u == ESC)
					{
						textcolor(15);
						clrscr();
						goto Doc_Gia;	
					}
				}
			}
			else
			{
				textcolor(15);
				clrscr();
				break;
			}
	}
}

void Thanh_Ly_Sach(Tree &l, LDS &t)
{
	int a = 1;
	int b = 14;
	textcolor(15);
	clrscr();
	while(1)
	{
Xuat:
	int v = 0;
	int m = 1;
	int d =0;
	LoadtuFile_DSDG(l);
	textcolor(15);
	Menu_Tam_Thoi(8);
	Trang_Sau_Truoc();
	for(int i=1; i<50; i++)
	{
		gotoxy(3+i,37);
		cout<<char(220);
	}
	gotoxy(6,38); cout<<"F1: NHAP DOC GIA";
	gotoxy(25,38); cout<<"F4: CHU THICH";
    gotoxy(42,38); cout<<"ESC: THOAT";
	Giao_Dien();
	 gotoxy(100,3);
		cout << "DANH SACH DOC GIA";
		gotoxy(tabx, taby);
		cout << char(218);
		for(int i = 1; i < tabs; i++)
		{
			cout << char(196);
		}
		cout << char(191);
		gotoxy(tabx + 15, taby); cout << char(194);
		gotoxy(tabx + 31, taby); cout << char(194);
		gotoxy(tabx + 47, taby); cout << char(194);
		gotoxy(tabx + 58, taby); cout << char(194);
		gotoxy(tabx , taby + 1); cout << char(179);
		gotoxy(tabx + 15, taby + 1); cout << char(179);
		gotoxy(tabx + 3, taby + 1); cout << "MA DOC GIA";
		gotoxy(tabx + 31, taby + 1); cout << char(179);
		gotoxy(tabx + 19, taby + 1); cout << "HO DOC GIA";
		gotoxy(tabx + 47, taby + 1); cout << char(179);
		gotoxy(tabx + 34, taby + 1); cout << "TEN DOC GIA";
		gotoxy(tabx + 58, taby + 1); cout << char(179);
		gotoxy(tabx + 51, taby + 1); cout << "PHAI";
		gotoxy(tabx + 82, taby + 1); cout << char(179);
		gotoxy(tabx + 62, taby + 1); cout << "TRANG THAI THE";
	int dem = 0;
	textcolor(15);
	const int STACKSIZE = 100;
	Tree Stack[STACKSIZE];
	int sp = -1;
	do
		{
			while (l != NULL)
			{
				Stack[++sp] = l;
				l = l->pLeft;
			}
			if (sp != -1)
			{
				l = Stack[sp--];
				d++;
				if(d>=a && d <= b)
				{
					v = v +2;
					TableDG1(l,dem,v,m);	
				}
				l = l->pRight;
			}
			else break;
		} while (1);
		if(v <= 28)
		{
			gotoxy(tabx, taby + v+2);
			cout << char(192);
			for(int i = 1; i < tabs; i++)
			{
				cout << char(196);
			}
			cout << char(191);
			gotoxy(tabx + 15, taby +v +2); cout << char(193);
			gotoxy(tabx + 31, taby +v +2); cout << char(193);
			gotoxy(tabx + 47, taby+v+2); cout << char(193);
			gotoxy(tabx + 58, taby+v+2); cout << char(193);
			gotoxy(tabx + tabs, taby +v+2); cout << char(217);
		}
		int keyhit = getch();
		if(keyhit == 224 ) // xem trang sau
		{
			int f = getch();
			if(f == 81)
			{
				if(d<=b)
				{
					textcolor(15);
					clrscr();
					goto Xuat;
				}
				a = b+1;
				b = b +14;
				textcolor(15);
				clrscr();
				goto Xuat;	
			}
			else if(f == 73)// xem trang truoc
			{
				if(a == 1 && b == 14)
				{
					textcolor(15);
					clrscr();
					goto Xuat;
				}
				a = a-14;
				b = b-14;
				textcolor(15);
				clrscr();
				goto Xuat;
			}
		}
		else if(keyhit == 0)
		{
			int f = getch();
			if(f == 59)
			{
				int n =0;
				Nhap_Doc_Gia_Lam_Mat_Sach(l, t, n);
				if(n!=0)
				{
					break;
				}	
			}
			else if(f == 62)
			{
				frameChuThichDocGia(13, 28);
				int u = getch();
				if(u == ESC)
				{
					textcolor(15);
					clrscr();
					goto Xuat;	
				}
			}	
		}
		else if(keyhit == 27)
		{
			textcolor(15);
			clrscr();
			break;
		}
	}
}
//***********************************   DANH SACH DOC GIA DANG MUON   ********************************
void Danh_Sach_Dang_Muon_(Tree &t, LDS &l,int &n)
{
	int  z= 0;
	Tree dg = Check_Ma_Doc_Gia(t,z);
	if(z != 0)
	{
		textcolor(15);
		clrscr();
		Menu();
	}
	while(1)
	{
		Doc_Gia:
			int v = 0; 
			int m = 1;
			textcolor(15);
			clrscr();
			Menu_Tam_Thoi(9);
			for(int i=1; i<50; i++)
		   {
				gotoxy(3+i,37);
				cout<<char(220);
			}
			gotoxy(14,38); cout<<"F4: CHU THICH";
		    gotoxy(31,38); cout<<"ESC: THOAT";
			textcolor(15);
			Giao_Dien();
			Khung_Dau_Sach();
			gotoxy(boxx+7, 3);
			cout<<"MA THE: ";
			gotoxy(boxx+7, 4);
			cout<<"HO: ";
			gotoxy(boxx+7, 5);
			cout<<"TEN: ";
			gotoxy(boxx+7, 6);
			cout<<"GIOI TINH: ";
			gotoxy(boxx+7,7);
			cout<<"TRANG THAI: ";
			gotoxy(boxx+7,8);
			cout<<"SO LUONG SACH: ";
			textcolor(15);
			gotoxy(98,3);cout << dg->DG.MADG; 
			gotoxy(98,4);cout << dg->DG.ho; 
			gotoxy(98,5);cout << dg->DG.ten; 
			gotoxy(98,6);cout << dg->DG.gioitinh;
			gotoxy(98,8);cout << dg->DG.sosachmuon;
			
			if(dg->DG.trangthaithe == 0)
			{
				gotoxy(98,7);cout << "KHOA";
			}
			else if(dg->DG.trangthaithe == 1)
			{
				gotoxy(98,7);cout << "HOAT DONG";
			}
			gotoxy(tabx + 5, taby + 5);
        	cout << char(218);
	         for(int i = 1; i < tabs - 10; i++)
        	{
        		cout << char(196);
          	}
        	cout << char(191);	
          	gotoxy(tabx + 22, taby + 5); cout << char(194);
        	gotoxy(tabx + 42, taby + 5); cout << char(194);
        	gotoxy(tabx + 60, taby + 5); cout << char(194);
         	gotoxy(tabx + 5, taby + 6); cout << char(179);
         	gotoxy(tabx + 22, taby + 6); cout << char(179);
        	gotoxy(tabx + 10, taby + 6); cout << "MA SACH";
	        gotoxy(tabx + 42, taby + 6); cout << char(179);
         	gotoxy(tabx + 27, taby + 6); cout << "NGAY MUON";
        	gotoxy(tabx + 60, taby + 6); cout << char(179);
         	gotoxy(tabx + 48, taby + 6); cout << "NGAY TRA";
	        gotoxy(tabx + 77, taby + 6); cout << char(179);
	        gotoxy(tabx + 65, taby + 6); cout << "TRANG THAI";
			int dem = 0;
			const int STACKSIZE = 100;
			Tree *Stack = new Tree[STACKSIZE];
			int sp = -1;
			Duyet_NLR(t, Stack, sp);
			for(int i=0; i<sp; i++)
			{
				if(Stack[i]->DG.MADG == dg->DG.MADG)
				{
					for(NodeMuonTra *k = Stack[i]->MT.pHead; k!= NULL; k=k->pRight)
					{
						if(k->data.trangthai == 0)
						{
							v = v + 2;
							Table_Muon_Sach(k, dem,v, m);
						}
					}
				}
			}
			if(v <= 6)
			{
				gotoxy(tabx + 5, taby + v+7);
				cout << char(192);
				for(int i = 1; i < tabs - 10; i++)
				{
					cout << char(196);
				}
				gotoxy(tabx + 22, taby +v +7); cout << char(193);
				gotoxy(tabx + 42, taby +v +7); cout << char(193);
				gotoxy(tabx + 60, taby+v+7); cout << char(193);
				gotoxy(tabx + 5 + tabs - 10, taby +v+7); cout << char(217);
			}
			int c = getch();
			if(c == ESC)
			{
				textcolor(15);
				clrscr();
				break;
			}
			else if(c == 0)
			{
				int f = getch();
				if(f == 62)
				{
					frameChuThichDanhMucSach(13, 28);
					int u = getch();
					if(u == ESC)
					{
						textcolor(15);
						clrscr();
						goto Doc_Gia;	
					}
				}
			}
	}
}

void Danh_Sach_Dang_Muon(Tree &l, LDS &t)
{
	int a = 1;
	int b = 14;
	textcolor(15);
	clrscr();
	while(1)
	{
Xuat:
	int v = 0;
	int m = 1;
	int z;
	int d =0;
	LoadtuFile_DSDG(l);
	textcolor(15);
	Menu_Tam_Thoi(9);
	for(int i=1; i<50; i++)
	{
		gotoxy(3+i,37);
		cout<<char(220);
	}
	gotoxy(6,38); cout<<"F1: NHAP DOC GIA";
	gotoxy(25,38); cout<<"F4: CHU THICH";
    gotoxy(42,38); cout<<"ESC: THOAT";
	Trang_Sau_Truoc();
	Giao_Dien();
	gotoxy(100,3);
	cout << "DANH SACH DOC GIA";
	gotoxy(tabx, taby);
	cout << char(218);
	for(int i = 1; i < tabs; i++)
	{
		cout << char(196);
	}
	cout << char(191);
	gotoxy(tabx + 15, taby); cout << char(194);
	gotoxy(tabx + 31, taby); cout << char(194);
	gotoxy(tabx + 47, taby); cout << char(194);
	gotoxy(tabx + 58, taby); cout << char(194);
	gotoxy(tabx , taby + 1); cout << char(179);
	gotoxy(tabx + 15, taby + 1); cout << char(179);
	gotoxy(tabx + 3, taby + 1); cout << "MA DOC GIA";
	gotoxy(tabx + 31, taby + 1); cout << char(179);
	gotoxy(tabx + 19, taby + 1); cout << "HO DOC GIA";
	gotoxy(tabx + 47, taby + 1); cout << char(179);
	gotoxy(tabx + 34, taby + 1); cout << "TEN DOC GIA";
	gotoxy(tabx + 58, taby + 1); cout << char(179);
	gotoxy(tabx + 51, taby + 1); cout << "PHAI";
	gotoxy(tabx + 82, taby + 1); cout << char(179);
	gotoxy(tabx + 62, taby + 1); cout << "TRANG THAI THE";
	int dem = 0;
	textcolor(15);
	const int STACKSIZE = 100;
	Tree Stack[STACKSIZE];
	int sp = -1;
	do
		{
			while (l != NULL)
			{
				Stack[++sp] = l;
				l = l->pLeft;
			}
			if (sp != -1)
			{
				l = Stack[sp--];
				for(NodeMuonTra *k = l->MT.pHead; k!=NULL; k= k->pRight)
				{
					if(k->data.trangthai == 0)
					{
						d++;
						if(d>=a && d <= b)
						{
							v = v +2;
					       	TableDG1(l,dem,v,m);
							break;	
						}
					}	
				}	
				l = l->pRight;
			}
			else break;
		} while (1);
		if(v <= 28)
		{
			gotoxy(tabx, taby + v+2);
			cout << char(192);
			for(int i = 1; i < tabs; i++)
			{
				cout << char(196);
			}
			cout << char(191);
			gotoxy(tabx + 15, taby +v +2); cout << char(193);
			gotoxy(tabx + 31, taby +v +2); cout << char(193);
			gotoxy(tabx + 47, taby+v+2); cout << char(193);
			gotoxy(tabx + 58, taby+v+2); cout << char(193);
			gotoxy(tabx + tabs, taby +v+2); cout << char(217);
		}
		int keyhit = getch();
		if(keyhit == 224 ) // xem trang sau
		{
			int f = getch();
			if(f == 81)
			{
				if(d<=b)
				{
					textcolor(15);
					clrscr();
					goto Xuat;
				}
				a = b+1;
				b = b +14;
				textcolor(15);
				clrscr();
				goto Xuat;	
			}
			else if(f == 73)// xem trang truoc
			{
				if(a == 1 && b == 14)
				{
					textcolor(15);
					clrscr();
					goto Xuat;
				}
				a = a-14;
				b = b-14;
				textcolor(15);
				clrscr();
				goto Xuat;
			}
		}
		else if(keyhit == 27)
		{
			textcolor(15);
			clrscr();
			break;
		}
		else if(keyhit == 0)
		{
			int f = getch();
			if(f == 59)
			{
				int n = 0;
				Danh_Sach_Dang_Muon_(l,t,n);
				if(n!=0)
				{
					break;
				}	
			}	
			else if(f == 62)
			{
				frameChuThichDocGia(13, 28);
				int u = getch();
				if(u == ESC)
				{
					textcolor(15);
					clrscr();
					goto Xuat;	
				}
			}
		}
	}
} 

//***********************************  DANH SACH QUA HAN  ************************************
void Table_Qua_Han()
{
	Giao_Dien();
	Khung_Dau_Sach();
	gotoxy(boxx+7, 3);
	cout<<"MA THE: ";
	gotoxy(boxx+7, 4);
	cout<<"HO: ";
	gotoxy(boxx+7, 5);
	cout<<"TEN: ";
	gotoxy(boxx+7, 6);
	cout<<"GIOI TINH: ";
	gotoxy(boxx+7,7);
	cout<<"TRANG THAI: ";
	gotoxy(boxx+7,8);
	cout<<"SO LUONG SACH: ";
	gotoxy(tabx + 5, taby + 5);
	cout << char(218);
	for(int i = 1; i < tabs - 10; i++)
	{
		cout << char(196);
	}
	cout << char(191);
	for(int i = 1; i < tabw -2; i++)
	{
		gotoxy(tabx + 5, taby +5+ i);
		cout << char(179);
	}

	for(int i = 1; i < tabw -2; i++)
	{
		gotoxy(tabx +5+ tabs - 10, taby +5+ i);
		cout << char(179);
	}
	gotoxy(tabx + 5, taby+5 + tabw-2);
	cout << char(192);
	for(int i = 1; i < tabs - 10; i++)
	{
		gotoxy(tabx+5 + i, taby +5+ tabw-2);
		cout << char(196);
	}
	gotoxy(tabx +5+ tabs - 10, taby +5+ tabw-2);
	cout << char(217);

	// Ma Sach
	gotoxy(tabx + 10, taby + 6); cout << "Ma Sach";
	gotoxy(tabx + 23, taby+5); cout << char(194);
	for(int i = 1; i < tabw -2; i++)
	{
		gotoxy(tabx + 23, taby + 5 + i); cout << char(179);
	}
	gotoxy(tabx + 5, taby + 7);
	cout << char(195);
	for(int i = 1; i < tabs - 10; i++)
	{
		gotoxy(tabx + 5 + i, taby + 7);
		cout << char(196);
	}
	gotoxy(tabx + 23, taby + 7); cout << char(197);
	gotoxy(tabx + 5 + tabs - 10, taby + 7); cout << char(180);
	gotoxy(tabx + 5 + 18, taby + 5 + tabw-2); cout << char(193);

	// Ten Sach
	gotoxy(tabx + 5 + 25, taby + 5 + 1); cout << "Ngay Muon";
	gotoxy(tabx + 5 +38, taby+5); cout << char(194);
	for(int i = 1; i < tabw -2; i++)
	{
		gotoxy(tabx + 5 + 38, taby + 5+ i); cout << char(179);
	}
	gotoxy(tabx + 5+ 38, taby+ 5+ 2); cout << char(197);
	gotoxy(tabx +5+ 38, taby +5+ tabw-2); cout << char(193);

/*	// Trang thai
	gotoxy(tabx +5+ 45, taby +5+ 1); cout << "Ngay Tra";
	gotoxy(tabx-2 +5+ 60, taby+5); cout << char(194);
	for(int i = 1; i < tabw-2; i++)
	{
		gotoxy(tabx-2+5 + 60, taby +5+ i); cout << char(179);
	}
	gotoxy(tabx -2+5+ 60, taby+5 + 2); cout << char(197);
	gotoxy(tabx -2+5+ 60, taby +5+ tabw-2); cout << char(193);*/
	
	// Vi tri
	gotoxy(tabx+ 50, taby +5+ 1); cout << "SO NGAY MUON QUA HAN";
	//
	gotoxy(tabx + 5, taby +7);
	for(int i=1; i<tabw-4; i++)
	{
		if(i%2 == 0)
		{
			gotoxy(tabx+5,taby +7+ i); cout<<char(195);	
		}
	}
   gotoxy(tabx +5 + tabs -10,taby +7);
	for(int i=1; i<tabw-4; i++)
	{
		if(i%2 == 0)
		{
			gotoxy(tabx +5+ tabs-10,taby +7+ i); cout<<char(180);	
		}
	}
	gotoxy(tabx+5,taby+7);
	for(int i=1; i<tabw -3; i++)
	{
		if(i%2==0)
		{
			for(int j=1; j<tabs-10; j++)
			{
				gotoxy(tabx+5+j,taby+7+i);
				cout<<char(196);
			}	
		}
	}
	
	gotoxy(tabx+5,taby+7);
	for(int i=1; i<tabw - 4; i++)
	{
		if(i%2==0)
		{
			gotoxy(tabx +5 + 18,taby+7+i);
			cout<<char(197);
			gotoxy(tabx +5+ 38,taby+7+i);
			cout<<char(197);
		//	gotoxy(tabx +5+ 58,taby+7+i);
	//		cout<<char(197);
		}
	}
	gotoxy(tabx+23,taby + tabw+ 3);cout<<char(193);
	gotoxy(tabx+43,taby + tabw + 3);cout<<char(193);
//	gotoxy(tabx + 63, taby+tabw+3);cout<<char(193);
}

struct QuaHan
{
    int MADG;
    int songayquahan;
    string MASACH;
	string ho;
	string ten;
	string gioitinh;
};    
QuaHan dv[100];
QuaHan temp;

void TableQH(QuaHan dv[], int j, int &dem, int &v, int &m)
{
	gotoxy(100,3);
	cout << "DANH SACH DOC GIA";
	gotoxy(tabx, taby);
	cout << char(218);
	for(int i = 1; i < tabs; i++)
	{
		cout << char(196);
	}
	cout << char(191);
	gotoxy(tabx + 15, taby); cout << char(194);
	gotoxy(tabx + 31, taby); cout << char(194);
	gotoxy(tabx + 47, taby); cout << char(194);
	gotoxy(tabx + 58, taby); cout << char(194);
	gotoxy(tabx , taby + 1); cout << char(179);
	gotoxy(tabx + 15, taby + 1); cout << char(179);
	gotoxy(tabx + 3, taby + 1); cout << "MA DOC GIA";
	gotoxy(tabx + 31, taby + 1); cout << char(179);
	gotoxy(tabx + 19, taby + 1); cout << "HO DOC GIA";
	gotoxy(tabx + 47, taby + 1); cout << char(179);
	gotoxy(tabx + 34, taby + 1); cout << "TEN DOC GIA";
	gotoxy(tabx + 58, taby + 1); cout << char(179);
	gotoxy(tabx + 51, taby + 1); cout << "PHAI";
	gotoxy(tabx + 82, taby + 1); cout << char(179);
	gotoxy(tabx + 59, taby + 1); cout << "SO NGAY QUA HAN";
	
	gotoxy(tabx,taby+2);

	for(int i = m; i< v; i++)
	{
		if(i %2 == 1)
		{
			gotoxy(tabx,taby+i +1);
			for(int k = 1; k<tabs + 1; k++)
			{
				cout << char(196);
			}
			gotoxy(tabx,taby+i+1);
			cout<<char(195);
			gotoxy(tabx + 15,taby+i+1);
			cout<<char(197);
			gotoxy(tabx + 31,taby+i+1);
			cout<<char(197);
			gotoxy(tabx + 47,taby+i+1);
			cout<<char(197);
			gotoxy(tabx + 58,taby+i+1);
			cout<<char(197);
			gotoxy(tabx + 82,taby+i+1);
			cout<<char(180);
			gotoxy(tabx, taby +i + 2); cout << char(179);
			gotoxy(tabx + 15, taby + i+2); cout << char(179);
			gotoxy(tabx + 31, taby + +i+2); cout << char(179);
			gotoxy(tabx + 47, taby + i+2); cout << char(179);
			gotoxy(tabx + 58, taby + i +2); cout << char(179);
			gotoxy(tabx + 82, taby + i+2); cout << char(179);
			gotoxy(70, 8 + dem); cout << dv[j].MADG; 
			gotoxy(85, 8 + dem); cout << dv[j].ho; 
			gotoxy(101, 8 + dem); cout << dv[j].ten; 
			gotoxy(115, 8 + dem);cout << dv[j].gioitinh;
			gotoxy(133, 8 + dem); cout << dv[j].songayquahan - 7;
			dem = dem + 2;
			m = v;
			Sleep(50);
		}
	}
}

Tree Check_Ma_Qua_Han(Tree &t, int &z)
{
	LoadtuFile_DSDG(t);
CheckMaDG:
	frameDocGia(15,28);// bang nhap do gia
	int x = 18, y = 28;
	int keyhit, dem;
	ngaythang n1;
	string text, field;
	field = "";
	char temp[10];
	keyhit = 0;
	dem = field.length();
	text = field;
	while(1)
	{
		textcolor(253);
		gotoxy(x + 5, y + 1);
		if(dem < 9)
		{
			cout << text;
			for(int i = 1; i < 11 - dem; i++) cout << " ";
		}
		else
		{
			for(int i = dem - 9; i < dem; i++)
				cout << text[i];
		}
		if(dem < 9) gotoxy(x + 5 + dem, y + 1);
		keyhit = getch();
		if(keyhit == BACKSPACE)
		{
			if(dem > 0)
			{
				dem--;
				text = text.substr(0, text.size() - 1);
			}
		}
		else if(keyhit == ENTER)
		{
			if(text == "")
			{
				gotoxy(16, 33);
				textcolor(112);	
				cout << "(VUI LONG NHAP MA DOC GIA)";
				int f = getch();
				gotoxy(16, 33);
				textcolor(15);	
				cout << "                            ";
				goto CheckMaDG;
			}
			else
			{
				textcolor(15);
				if(text.length() > 9)
				{
					gotoxy(17, 33);
					textcolor(112);	
					cout << "(MA DOC GIA QUA DAI)";
					int f = getch();
			    	gotoxy(17, 33);
			    	textcolor(15);	
			    	cout << "                            ";
			    	goto CheckMaDG;
				}
				else
				{
					if(timDG(t, atoi((char*)text.c_str())) == 0)
					{
						gotoxy(16, 33);
						textcolor(112);	
						cout << "(MA DOC GIA KHONG TON TAI)";
						int f = getch();
			        	gotoxy(16, 33);
			        	textcolor(15);	
			        	cout << "                            ";
			        	goto CheckMaDG;
					}
					else
					{	
						return 	timDG(t, atoi((char*)text.c_str()));
					}
				}
			}
		}
		else if(keyhit == ESC)
		{
			z++;
			Sleep(500);
			break;
		}
		else 
		{
			dem++;
			text += toupper((char)keyhit);
		}
	}
}

void Danh_Sach_Sach_QH(int &n,Tree &t)
{
	Y:
	int  z= 0;
	Tree dg = Check_Ma_Qua_Han(t,z);
	for(int j=0;j<n;j++)
	{
		if(dv[j].MADG == dg->DG.MADG)
		{
			break;
		}
		if(j == n -1)
		{
			gotoxy(16,32);
			cout<<"KHONG CO SACH QUA HAN";
			int c = getch();
			gotoxy(16,32);
			cout<<"                     ";
			goto Y;
		}
	}
	if(z != 0)
	{
		return;
	}
	while(1)
	{
Muon_Tra:
	LoadtuFile_DSDG(t);
	textcolor(15);
	clrscr();
	textcolor(15);
	Menu_Tam_Thoi(10);
	Giao_Dien();
	for(int i=1; i<50; i++)
	{
		gotoxy(3+i,37);
		cout<<char(220);
	}
	gotoxy(13,38); cout<<"F4: CHU THICH";
    gotoxy(35,38); cout<<"ESC: THOAT";
	Table_Qua_Han();
	int dem = 0;
	textcolor(15);
	const int STACKSIZE = 100;
	Tree Stack[STACKSIZE];
	int sp = -1;
	do
		{
			while (t != NULL)
			{
				Stack[++sp] = t;
				t = t->pLeft;
			}
			if (sp != -1)
			{
				t = Stack[sp--];
				gotoxy(98,3);cout << dg->DG.MADG; 
				gotoxy(98,4);cout << dg->DG.ho; 
				gotoxy(98,5);cout << dg->DG.ten; 
				gotoxy(98,6);cout << dg->DG.gioitinh;
				gotoxy(98,8);cout << dg->DG.sosachmuon;
				gotoxy(98,7);cout << dg->DG.trangthaithe;
			/*	if(dg->DG.trangthaithe == 0)
				{
					gotoxy(98,7);cout << "KHOA";
				}
				else if(dg->DG.trangthaithe == 1)
				{
					gotoxy(98,7);cout << "HOAT DONG";
				}*/
				if(t->DG.MADG == dg->DG.MADG)
				{
					for(NodeMuonTra *k = t->MT.pHead; k!=NULL; k= k->pRight)
					{
						if(k->data.ngaytra.ngay == 0 && k->data.ngaytra.thang == 0 && k->data.ngaytra.nam == 0)
						{
							LayNgayHT(k->data.ngaytra); 
							int songayquahan = songaymuon(k->data.ngaymuon,k->data.ngaytra);
							if(songayquahan > MAX_QH)
							{
								gotoxy(75, 13 + dem); cout<<k->data.MASACH;
								gotoxy(93, 13 + dem); cout<<k->data.ngaymuon.ngay<<"-"<<k->data.ngaymuon.thang<<"-"<<k->data.ngaymuon.nam;
								gotoxy(125, 13 + dem); cout<<songayquahan-7;
								dem = dem + 2;
							}
						}
					}	
				}
				t = t->pRight;
			}
			else break;
		} while (1);
		int c = getch();
	if(c == ESC)
	{
		break;
	}
	else if(c == 0)
	{
		int f = getch();
		if(f == 62)
		{
			frameChuThichDocGia(13, 28);
			int u = getch();
			if(u == ESC)
			{
				textcolor(15);
				clrscr();
				goto Muon_Tra;	
			}
		}
	}
	}
}

void DSQuaHan(Tree t)
{
	LoadtuFile_DSDG(t);
	int n = 0;
    const int STACKSIZE=100;
	Tree Stack[STACKSIZE];
	int sp=-1;
    do
    {
        while(t!=NULL)
        {
            Stack[++sp]=t;
            t=t->pLeft;
        }
        if(sp!=-1)
        {
            t=Stack[sp--];
            for(NodeMuonTra *p= t->MT.pHead;p!=NULL;p=p->pRight)
            {
            	if(p->data.ngaytra.ngay == 0 && p->data.ngaytra.thang == 0 && p->data.ngaytra.nam ==0)
            	{
            		n++;
      	            dv[n-1].MADG = t->DG.MADG; 
      	            dv[n-1].MASACH = p->data.MASACH;
					dv[n - 1].ho = t->DG.ho;
					dv[n - 1].ten = t->DG.ten;
					dv[n - 1].gioitinh = t->DG.gioitinh;
                	LayNgayHT(p->data.ngaytra);
               		dv[n-1].songayquahan = songaymuon(p->data.ngaymuon,p->data.ngaytra);	
				}
            }
            t=t->pRight;
        } else break;
    }while(1);
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(dv[i].songayquahan > dv[j].songayquahan)// doi vi tri
            {
                temp = dv[i];
                dv[i]=dv[j];
                dv[j]=temp;
            }
        }
    }
    int a = 1;
	int b = 14;
	textcolor(15);
	clrscr();
	while(1)
	{
	Xuat:
		int v = 0;
		int m = 1;
		int z;
		int d =0;
		textcolor(15);
		Menu_Tam_Thoi(10);
		Trang_Sau_Truoc();
		Giao_Dien();
		for(int i=1; i<50; i++)
		{
			gotoxy(3+i,37);
			cout<<char(220);
		}
		gotoxy(12,38); cout<<"F1: NHAP DOC GIA";
	    gotoxy(33,38); cout<<"ESC: THOAT";
		int dem = 0;
		textcolor(15);
		gotoxy(100,3);
	cout << "DANH SACH DOC GIA";
	gotoxy(tabx, taby);
	cout << char(218);
	for(int i = 1; i < tabs; i++)
	{
		cout << char(196);
	}
	cout << char(191);
	gotoxy(tabx + 15, taby); cout << char(194);
	gotoxy(tabx + 31, taby); cout << char(194);
	gotoxy(tabx + 47, taby); cout << char(194);
	gotoxy(tabx + 58, taby); cout << char(194);
	gotoxy(tabx , taby + 1); cout << char(179);
	gotoxy(tabx + 15, taby + 1); cout << char(179);
	gotoxy(tabx + 3, taby + 1); cout << "MA DOC GIA";
	gotoxy(tabx + 31, taby + 1); cout << char(179);
	gotoxy(tabx + 19, taby + 1); cout << "HO DOC GIA";
	gotoxy(tabx + 47, taby + 1); cout << char(179);
	gotoxy(tabx + 34, taby + 1); cout << "TEN DOC GIA";
	gotoxy(tabx + 58, taby + 1); cout << char(179);
	gotoxy(tabx + 51, taby + 1); cout << "PHAI";
	gotoxy(tabx + 82, taby + 1); cout << char(179);
	gotoxy(tabx + 59, taby + 1); cout << "SO NGAY QUA HAN";
		for(int k=0; k<n; k++)
		{
			if(dv[k].songayquahan > MAX_QH)
			{
				d++;
				if(d>=a && d <= b)
				{
					v = v + 2;
				    TableQH(dv,k, dem, v, m);	
				}
			}	
		}
		if(v <= 30)
		{
			gotoxy(tabx, taby + v+2);
			cout << char(192);
			for(int i = 1; i < tabs; i++)
			{
				cout << char(196);
			}
			cout << char(191);
			gotoxy(tabx + 15, taby +v +2); cout << char(193);
			gotoxy(tabx + 31, taby +v +2); cout << char(193);
			gotoxy(tabx + 47, taby+v+2); cout << char(193);
			gotoxy(tabx + 58, taby+v+2); cout << char(193);
			gotoxy(tabx + tabs, taby +v+2); cout << char(217);
		}
		int keyhit = getch();
		if(keyhit == 224)
		{
			int f = getch();
			if(f == 81)// Phim PgUp
			{
				if(d <= b)
				{
					textcolor(15);
					clrscr();
					goto Xuat;
				}
				a = b+1;
				b = b +14;
				textcolor(15);
				clrscr();
				goto Xuat;
			}
			else if(f == 73)// Phim PgDn
			{
				if(a == 1 && b == 14)
				{
					textcolor(15);
					clrscr();
					goto Xuat;
				}
				a = a-14;
				b = b-14;
				textcolor(15);
				clrscr();
				goto Xuat;
			}
		}
		else if(keyhit == 27)//thoat
		{
			textcolor(15);
			clrscr();
			break;
		}
		else if(keyhit == 0)// Phim F1
		{
			int f = getch();
			if(f == 59)
			{
				Danh_Sach_Sach_QH(n,t);
				textcolor(15);
				clrscr();
				goto Xuat;
			}
		}
	}
}
//********************************** Top 10 sach ************************************
void TableDS3(LDS l, int j, int &dem, int &v, int &m)
 {
	gotoxy(taxx,taxy - 12);
	for(int i = m; i< v; i++)
	{
		if(i %2 == 1)
		{
			gotoxy(taxx + 1,taxy+i - 11);
			for(int k = 1; k<taxs; k++)
			{
				cout << char(196);
			}
			gotoxy(taxx,taxy+i -11);
			cout<<char(195);
			gotoxy(taxx + 15,taxy+i - 11);
			cout<<char(197);
			gotoxy(taxx +57,taxy+i-11);
			cout<<char(197);
			gotoxy(taxx +89,taxy+i-11);
			cout<<char(197);
			gotoxy(taxx +121,taxy+i-11);
			cout<<char(197);
			gotoxy(taxx +131,taxy+i-11);
			cout<<char(197);
			gotoxy(taxx +139,taxy+i-11);
			cout<<char(197);
			gotoxy(taxx + 147,taxy+i-11);
			cout<<char(180);
			gotoxy(taxx, taxy +i -10); cout << char(179);
			gotoxy(taxx + 15, taxy + i -10); cout << char(179);
			gotoxy(taxx + 57, taxy + +i -10); cout << char(179);
			gotoxy(taxx + 89, taxy + i-10); cout << char(179);
			gotoxy(taxx + 121, taxy + i -10); cout << char(179);
			gotoxy(taxx + 131, taxy + i-10); cout << char(179);
			gotoxy(taxx + 139, taxy + i-10); cout << char(179);
			gotoxy(taxx + 147, taxy + i-10); cout << char(179);
			gotoxy(taxx + 1, 6 + dem); cout << l.DS[j]->ISBN;
			gotoxy(taxx + 16, 6 + dem); cout <<l.DS[j]->tenSach;
			gotoxy(taxx + 58, 6 + dem); cout << l.DS[j]->tacGia;
			gotoxy(taxx + 90, 6 + dem); cout << l.DS[j]->theLoaiSach;
			gotoxy(taxx + 125, 6 + dem); cout <<l.DS[j]->soTrang;
			gotoxy(taxx + 134, 6 + dem); cout << l.DS[j]->namSB;
			gotoxy(taxx + 142, 6 + dem); cout << l.DS[j]->solanmuon;
			dem = dem + 2;
			m = v;
			Sleep(50);
		}
	}
 }

void Top10Sach(LDS l)
{
	textcolor(15);
	clrscr();
	while(1)
	{
Xuat :
		int v = 0;
		int m = 1;
		textcolor(15);
		Giao_DienDS();
		gotoxy(70,2);
		cout << "DANH SACH TOP 10";
		gotoxy(taxx, taxy - 12);
		cout << char(218);
		for(int i = 1; i < taxs; i++)
		{
			cout << char(196);
		}
		cout << char(191);
		gotoxy(taxx + 15, taxy - 12); cout << char(194);
		gotoxy(taxx + 57, taxy - 12); cout << char(194);
		gotoxy(taxx + 89, taxy -12); cout << char(194);
		gotoxy(taxx + 121, taxy -12); cout << char(194);
		gotoxy(taxx + 131, taxy -12); cout << char(194);
		gotoxy(taxx + 139, taxy -12); cout << char(194);
		gotoxy(taxx , taxy - 11); cout << char(179);
		gotoxy(taxx +5, taxy - 11); cout << "ISBN";
		gotoxy(taxx + 15, taxy - 11); cout << char(179);
		gotoxy(taxx + 30, taxy - 11); cout << "TEN SACH";
		gotoxy(taxx + 57, taxy - 11); cout << char(179);
		gotoxy(taxx + 69, taxy - 11); cout << "TAC GIA";
		gotoxy(taxx + 89, taxy - 11); cout << char(179);
		gotoxy(taxx + 101, taxy - 11); cout << "THE LOAI";
		gotoxy(taxx + 121, taxy - 11); cout << char(179);
		gotoxy(taxx + 123, taxy - 11); cout << "SO TRANG";
		gotoxy(taxx + 131, taxy - 11); cout << char(179);
		gotoxy(taxx + 132, taxy - 11); cout << "NAM XB";
		gotoxy(taxx + 139, taxy - 11); cout << char(179);
		gotoxy(taxx + 140, taxy - 11); cout << "SL MUON";
		gotoxy(taxx + 147, taxy - 11); cout << char(179);
		int dem = 0;
		textcolor(15);
		for(int i=0; i<l.n; i++)// duyet dau sach
		{
			for(int j=i+1; j<l.n; j++)
			{
				if(l.DS[j]->solanmuon > l.DS[i]->solanmuon)
				{
					DAUSACH *temp;
					temp = l.DS[i];
					l.DS[i] = l.DS[j];
					l.DS[j] = temp;
				}
			}
		}
		if(l.n < 10)
		{
			for (int i=0; i<l.n; i++)// duyet dau sach
			{
				if(l.DS[i]->solanmuon != 0)
				{
					v = v + 2;
					TableDS3(l, i, dem, v, m);		
				}
			}
		}
		else
		{
			for (int i=0; i<10; i++)// duyet dau sach
			{
				if(l.DS[i]->solanmuon != 0)
				{
					v = v + 2;
					TableDS3(l, i, dem, v, m);		
				}
			}	
		}
		if(v <= 30)
		{
			gotoxy(taxx, taxy + v - 10);
			cout << char(192);
			for(int i = 1; i < taxs; i++)
			{
				cout << char(196);
			}
			cout << char(217);
			gotoxy(taxx + 15, taxy +v -10); cout << char(193);
			gotoxy(taxx + 57, taxy+v -10); cout << char(193);
			gotoxy(taxx + 89, taxy+v -10); cout << char(193);
			gotoxy(taxx + 121, taxy+v -10); cout << char(193);
			gotoxy(taxx + 131, taxy+v -10); cout << char(193);
			gotoxy(taxx + 139, taxy+v -10); cout << char(193);
		}
		gotoxy(55,38);
		for(int i=1; i<47; i++)
		{
			cout<<char(220);
		}
		gotoxy(55,39);
		cout<<char(221);
		gotoxy(100,39);
		cout<<char(222);
		gotoxy(73,39);
		cout<<"ESC: THOAT";
		int c = getch();// kiem tra bat phim
		if(c == 27)// thoat
		{
			Sleep(500);
			textcolor(15);
			clrscr();
			break;
		}
	}
}

 //**********************************   Menu   ***************************************
 void Menu()
{
	LDS l;
	Tree t;
	KhoitaoDSDG(t);
	KhoitaoDS(l);
	LoadFileDS(l);
	LoadtuFile_DSDG(t);
Menu:
	Giao_Dien();
	gotoxy(7,26); cout<<"DUNG CHUOT NHAN DAU \"x\" TREN MAN HINH CONSOLE ";
	gotoxy(7,27); cout<<"         DE THOAT CHUONG TRINH";
	Thu_Vien();
	int x = 9;
	int y = 6;
	int keyhit;
	char menu_text[11][100] = { " 1. NHAP DOC GIA ", " 2. IN DANH SACH DOC GIA ", " 3. NHAP DAU SACH ", " 4. SACH ", " 5. THONG TIN SACH ", " 6. MUON SACH ", " 7. TRA SACH " , " 8. THANH LY SACH", " 9. DANH SACH DOC GIA DANG MUON " , " 10. DANH SACH QUA HAN " ," 11. 10 SACH MUON NHIEU NHAT " };
    gotoxy(5, 3); cout <<     "             MENU QUAN LY THU VIEN "; 
    gotoxy(5,4); cout<<"          ---------------------------";
    gotoxy(x, 6); cout << menu_text[0];
	gotoxy(x, 7); cout << menu_text[1];
	gotoxy(x, 8); cout << menu_text[2];
	gotoxy(x, 9); cout << menu_text[3];
	gotoxy(x, 10); cout << menu_text[4];
	gotoxy(x, 11); cout << menu_text[5];
	gotoxy(x, 12); cout << menu_text[6];
	gotoxy(x, 13); cout << menu_text[7];
	gotoxy(x, 14); cout << menu_text[8];
	gotoxy(x, 15); cout << menu_text[9];
	gotoxy(x, 16); cout << menu_text[10];
	do{
		gotoxy(x, y);
		textcolor(159);// nen mau xanh
		switch (y)
		{
		case 6: gotoxy(x, 6); cout << menu_text[0]; break;
		case 7: gotoxy(x, 7); cout << menu_text[1]; break;
		case 8: gotoxy(x, 8); cout << menu_text[2]; break;
		case 9: gotoxy(x, 9); cout << menu_text[3]; break;
		case 10: gotoxy(x, 10); cout << menu_text[4]; break;
		case 11: gotoxy(x, 11); cout << menu_text[5]; break;
		case 12: gotoxy(x, 12); cout << menu_text[6]; break;
		case 13: gotoxy(x, 13); cout << menu_text[7]; break;
		case 14: gotoxy(x, 14); cout << menu_text[8]; break;
		case 15: gotoxy(x, 15); cout << menu_text[9]; break;
		case 16: gotoxy(x, 16); cout << menu_text[10]; break;
		}
		keyhit = getch(); // Kiem Tra Nhan Lenh Ban Phim
		if (keyhit == UP) // Di Len
		{
			gotoxy(x, y);
			textcolor(15); // Doi thanh mau chu mau trang
			switch (y)
			{
			case 6: gotoxy(x, 6); cout << menu_text[0]; break;
			case 7: gotoxy(x, 7); cout << menu_text[1]; break;
			case 8: gotoxy(x, 8); cout << menu_text[2]; break;
			case 9: gotoxy(x, 9); cout << menu_text[3]; break;
			case 10: gotoxy(x, 10); cout << menu_text[4]; break;
			case 11: gotoxy(x, 11); cout << menu_text[5]; break;
			case 12: gotoxy(x, 12); cout << menu_text[6]; break;
			case 13: gotoxy(x, 13); cout << menu_text[7]; break;
			case 14: gotoxy(x, 14); cout << menu_text[8]; break;
			case 15: gotoxy(x, 15); cout << menu_text[9]; break;
			case 16: gotoxy(x, 16); cout << menu_text[10]; break;
			}
			y--;
			if (y < 6)
			{
				y = 16;
			}
		}
		else if (keyhit == DOWN)// di xuong
		{
			gotoxy(x, y);
			textcolor(15);
			switch (y)
			{
			case 6: gotoxy(x, 6); cout << menu_text[0]; break;
			case 7: gotoxy(x, 7); cout << menu_text[1]; break;
			case 8: gotoxy(x, 8); cout << menu_text[2]; break;
			case 9: gotoxy(x, 9); cout << menu_text[3]; break;
			case 10: gotoxy(x, 10); cout << menu_text[4]; break;
			case 11: gotoxy(x, 11); cout << menu_text[5]; break;
			case 12: gotoxy(x, 12); cout << menu_text[6]; break;
			case 13: gotoxy(x, 13); cout << menu_text[7]; break;
			case 14: gotoxy(x, 14); cout << menu_text[8]; break;
			case 15: gotoxy(x, 15); cout << menu_text[9]; break;
			case 16: gotoxy(x, 16); cout << menu_text[10]; break;
			}
			y++;
			if (y > 16)
			{
				y = 6;
			}
		}
		if(keyhit == ESC)
		{
			return;
		}
		else if (y == 6 && keyhit == ENTER)
		{
			textcolor(15);
			NhapDocGia(t);
			goto Menu;
		}
		else if (y == 7 && keyhit == ENTER)
		{
			textcolor(15);
			clrscr();	
			XuatDanhSachDG(t);
			textcolor(15);
			clrscr();
			goto Menu;
		}
		else if (y == 8 && keyhit == ENTER)
		{
			textcolor(15);
			clrscr();
			NhapDanhSachDS(l);
			goto Menu;
		}
		else if (y == 9 && keyhit == ENTER)
		{
			textcolor(15);
			clrscr();
			XuatDSSach(l);
			goto Menu;
		}
		else if (y == 10 && keyhit == ENTER)
		{
			textcolor(15);
			clrscr();
			Tim_Kiem_Thong_Tin_Sach(l);
			goto Menu;
		}
		else if (y == 11 && keyhit == ENTER)
		{
			textcolor(15);
			clrscr();
			Doc_Gia_Muon_Sach(t,l);
			goto Menu;
		}
		else if (y == 12 && keyhit == ENTER)
		{
			textcolor(15);
			clrscr();
			Tra_Sach(t,l);
			goto Menu;
		}
		else if(y == 13 && keyhit == ENTER)
		{
			textcolor(15);
			clrscr();
			Thanh_Ly_Sach(t,l);
			goto Menu;
		}
		else if (y == 14 && keyhit == ENTER)
		{
			textcolor(15);
			clrscr();
			Danh_Sach_Dang_Muon(t,l);
			goto Menu;
		}
		else if (y == 15 && keyhit == ENTER)
		{
			textcolor(15);
			clrscr();
			DSQuaHan(t);
			textcolor(15);
			clrscr();
			goto Menu;
		}
		else if (y == 16 && keyhit == ENTER)
		{
			textcolor(15);
			clrscr();
			Top10Sach(l);
			textcolor(15);
			clrscr();
			goto Menu;
		}
	}while(true);
}
 //**********************************   Main   ***************************************
 int main()
{
	resizeConsole(1300, 700);
	Menu();
	return 0;
}
 
 
