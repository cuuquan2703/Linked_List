#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime> 
using namespace std;
struct Sinhvien
{
	char Hoten[30];
	int MSSV;
	float Diem;
};
struct node
{
	Sinhvien key;
	node* next;
};
struct List
{
	node* pHead;
	node* pTail;
};
void initList(List& l) //Khởi tạo danh sách rỗng
{
	l.pHead=l.pTail = NULL;
}
int checkEmpty(List& l) //Kiểm tra danh sách rỗng
{
	if ((l.pHead == NULL)and(l.pTail==NULL)) return 1;
	else return 0;
}

node* getnode(Sinhvien p)//Tạo node
{
	node* k;
	k = new node;
	if (k == NULL) cout << "Khong du bo nho";
	k->key = p;
	k->next = NULL;
	return k;
}

void addFirst(List& l, Sinhvien k)//Thêm 1 node  vào đầu
{
	node* p = getnode(k);
	if (l.pHead= NULL)
		l.pHead = l.pTail = p;
	else {
		p->next = l.pHead;
		l.pHead = p;
	}
}
void addTail(List& l, Sinhvien k)//Thêm 1 node vào cuối
{
	node* temp = l.pHead;
	node* q = getnode(k);
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = q;
}
void addafterFirst(List& l, Sinhvien k)//Thêm 1 node vào sau node đầu
{
	node* q = getnode(k);
	node* temp = l.pHead;
	if (temp != NULL)
	{
		q->next = temp->next;
		temp->next = q;
	}
}
void addbeforeTail(List& l, Sinhvien k)//Thêm 1 node vào trước node cuối
{
	node* q = getnode(k);
	node* temp = l.pHead;
	node* temp2 = temp->next;
	while (temp2->next != NULL)
	{
		temp = temp->next;
		temp2 = temp->next;
	};
	q->next = temp->next;
	temp->next = q;
}

void Input(Sinhvien& p)//Nhập sinh viên
{
	cout << "Nhap ten: ";
	cin.ignore();
	cin.getline(p.Hoten, 30);
	cout << "Nhap maso: ";
	cin >> p.MSSV;
	cout << "Nhap diem: ";
	cin >> p.Diem;
}
void randomdata(Sinhvien& k)
{
	
	char box[100] = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm" ;
	int box_length = strlen(box);
	for (int i = 0; i < 15; i++)
	{
		srand(time(0));
		k.Hoten[i] = box[rand() % box_length];
		
	};
	k.Hoten[15] = '\0';
	k.MSSV = rand() % (20120999 - 20120000 + 1) + 20120000;
	k.Diem = rand() % (10 - 1 + 1) + 1;
	
}
void printList(List l)//In ra tất cả node
{
	node * p;
	if (l.pHead == NULL)
		cout << "danh sach trong";
	else
		for (p = l.pHead; p; p = p->next)
		{
			cout << p->key.Hoten << endl;
			cout << p->key.MSSV << endl;
			cout << p->key.Diem<<endl;
		}
}
void deleteFirst(List& l)//Xóa node đầu tiên
{
	if (l.pHead == NULL)
	{
		cout << "Khong co phan tu dau";
	}
	else {
		node* temp = l.pHead;
		l.pHead = l.pHead->next;
		temp->next = NULL;
		delete temp;
		temp = NULL;
	}
}
void deletenodeafter(List& l, node* f) //Xóa node sau node cho trước
{
	node* temp = f->next;
	if (temp->next == NULL) {
		f->next = NULL;
		delete temp;
	}
	else {
		f->next = f->next->next;
		delete temp;
	}
}

void deleteTail(List& l)//Xóa node cuối cùng
{
	if (l.pHead->next == NULL)
	{
		deleteFirst(l);
	}
	else
	{
		node* temp = l.pHead;
		while (temp->next->next != NULL)
		{
			temp = temp->next;
		}
		deletenodeafter(l, temp);
	}
}
void reversenode(List& l)//Đảo ngược node
{
	node* temp=l.pHead;
	node* prev = NULL; node* next = NULL;
	while (temp !=  NULL)
	{
		next = temp->next;
		temp->next = prev;
		prev = temp;
		temp = next;
		
	}
	l.pHead = prev;
}
void addnoderandom(List& l, Sinhvien k,int& n)
{
	cout << "Nhap so node can them: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		randomdata(k);
		cout << k.Hoten << "      " << k.Diem << "         " << k.MSSV << endl;
		//addFirst(l, k);

	}
}
void swapnode(List& l, node* node1, node* node2)//hoán đổi vị trí 2 node
{
	Sinhvien temp;
	temp = node1->key;
	node1->key = node2->key;
	node2->key = temp;
}
void sort(List& l)//sắp xếp
{
	node* temp = l.pHead;
	while (temp != NULL)
	{
		node* temp2 = temp->next;
		while (temp2 != NULL)
		{
			if (temp->key.Diem > temp2->key.Diem)
				swapnode(l, temp, temp2);
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
		
}
List find(List& l, char n)// Tìm sinh viên có chữ cái đầu theo yêu cầu
{
	List a;
	initList(a);
	int k = 1;
	node* temp = l.pHead;
	while (temp != NULL)
	{
		if (temp->key.Hoten[0] == n)
			if (k == 1)
			{
				addFirst(a, temp->key);
				k++;
			}
			else if (k > 1)
			{
				addTail(a, temp->key);
				k++;
			}
		temp = temp->next;
	}
	return a;
}
void update_node(List& l,Sinhvien k)// update các node 
{
	node* q = getnode(k);
	node* temp = l.pHead;
	while (temp != NULL)
	{
		if (temp->key.MSSV == k.MSSV)
		{
			temp->key.Diem = k.Diem;
			for (int i = 0; i < 50; i++)
			{
				temp->key.Hoten[i] = k.Hoten[i];
			};
		}
		temp = temp->next;
	}

}

int main()
{
	Sinhvien k;
	List l, l_find;
	initList(l);
	initList(l_find);
	int n = 0;
	Input(k);
	cout << "Nhap thong tin sinh vien vao dau danh sach " << endl;
	Input(k);
	addFirst(l, k);
	//addnoderandom(l, k, n);
	printList(l);
	cout << endl;

	cout << "Nhap thong tin sinh vien vao cuoi danh sach" << endl;
	Input(k);
	addFirst(l, k);
	printList(l);
	cout << endl;

	cout << "Nhap thong tin sinh vien them vao sau sinh vien dau tien" << endl;
	Input(k);
	addafterFirst(l, k);
	printList(l);
	cout << endl;

	cout << "Nhap thong tin sinh vien vao truoc sinh vien cuoi" << endl;
	Input(k);
	addbeforeTail(l, k);
	printList(l);
	cout << endl;
	//l_find = find(l, 'H');
	Input(k);
	update_node(l, k);
	//sort(l);
	printList(l);
	cout << endl;
	printList(l_find);
	//reversenode(l);
	/*randomdata(k);
	addFirst(l, k);
	randomdata(k);
	addTail(l, k);
	randomdata(k);
	addafterFirst(l, k);
	randomdata(k);
	addbeforeTail(l, k);
	printList(l);*/
	//addnoderandom(l, k, n);



	return 0;

}
