#include<iostream>
using namespace std;
int n;
struct Node // Tạo một kiểu dữ liệu mới có thuộc tính là data và địa chỉ của con trỏ next.
{
	int data;
	Node *next;
};
class List
{
private:
	Node *head;
	Node *tail;
public:
	List() // Khởi tạo danh sách rỗng.
	{
		head = tail = NULL;
	};
	Node *creatNode(int x) // Tạo Node mới có giá trị là X và không trỏ đến đâu.
	{
		Node *p = new Node;
		if (p == NULL)
			exit(1);
		p->next = NULL;
		p->data = x;
		return p;
	}
	bool isEmpty() // Kiểm tra xem danh sách có rỗng không?
	{
		if (head == NULL) return true;
		return false;
	}
	void AddFirst(int x) // Thêm vào đầu danh sách.
	{
		Node *p = creatNode(x);
		if (isEmpty())
			head = tail = p;
		else
		{
			p->next = head;
			head = p;
		}
	}
	void AddLast(int x) // Thêm vào cuối danh sách.
	{
		Node *p = creatNode(x);
		if (isEmpty())
			AddFirst(x);
		else
		{
			tail->next = p;
			tail = p;
		}
	}
	void InsertPos(int v, int Pos) // Thêm vào vị trí Pos của danh sách.
	{
		if (isEmpty() || Pos <= 1)
			AddFirst(v);
		else if (Pos >= n)
			AddLast(v);
		else
		{
			Node *p = new Node;
			Node *q = new Node;
			Node *temp = new Node;
			q = head;
			for (int i = 1; i<Pos; i++)
			{
				p = q;
				q = q->next;
			}
			temp->data = v;
			p->next = temp;
			temp->next = q;
		}
	}
	Node *Search(int k) // Tìm kiếm phần tử có giá trị k trong danh sách.
	{
		Node *p = head;
		while (p != NULL)
		{
			if (p->data == k)
				return p;
			else
				p = p->next;
		}
		return NULL;
	}
	void Inra() // In ra màn hình
	{
		Node *p = head;
		while (p != NULL){
			cout << " " << p->data;
			p = p->next;
		}
	}
	void DelFirst() // Xóa vị trí đầu tiên.
	{
		if (!isEmpty())
		{
			Node *p = head;
			head = head->next;
			delete p;
		}
	}
	void DelLast() // Xóa vị trí cuối cùng.
	{
		if (!isEmpty())
		{
			Node *p = head;
			Node *q = new Node;
			while (p->next != tail) p = p->next;
			q = p;
			p = p->next;
			tail = q;
			tail->next = NULL;
			delete p;
		}
	}
	void DelPos(int Pos) // Xóa vị trí Pos.
	{
		if (Pos <= 1)
			DelFirst();
		else if (Pos >= n)
			DelLast();
		else
		{
			int dem = 0;
			if (!isEmpty())
			{
				Node *p = head;
				Node *q = new Node;
				while (p != NULL)
				{
					dem++;
					q = p;
					if (dem == Pos)
						break;
					else
						p = p->next;
				}
				Node *r = head;
				while (r->next != q)
					r = r->next;
				r->next = q->next;
				delete q;
			}
		}
	}
	
	void ShellSort()
	{
		if (head)
		{
			int buocnhay = 0;
			int dodaichuoi = 0;
			Node *p = head;
			while (p) // Khoi Tao Lai Danh Sach
			{
				dodaichuoi++;
				p = p->next;
			}
			while (2 * (3 * buocnhay + 1) <= dodaichuoi)
			{
				buocnhay = 3 * buocnhay + 1;
			}
			
			for (buocnhay; buocnhay > 0; buocnhay /= 3)
			{
				for (int i = buocnhay; i > 0; i--)
				{
					for (int j = buocnhay - i; j < dodaichuoi; j += buocnhay)
					{
						p = head;
						int k;
						for (k = 0; k < j; k++)
						{
							p = p->next;
						}
						Node* c = p;
						int temp = k + buocnhay;
						while (c)
						{
							for (k; k<temp;)
							if (c)
							{
								k++;
								c = c->next;
							}
							else break;
							if (c)
							if (p->data>c->data)
							{
								int t = p->data;
								p->data = c->data;
								c->data = t;
							}
							temp += buocnhay;
						}
					}
				}
			}

		}
	}
};



