/*
* Khái niệm: là danh sách các NODE liên kết với nhau NODE gồm data và con trỏ
* Ưu - nhược: việc thêm xóa đơn giản, không cần biết trước số phần tử, các phần tử không nằm liên tiếp nhau trong bộ nhớ
		  Không truy xuất đến từng phần tử mà phải duyệt tuần tự, tốn bộ nhớ
*/

#include <iostream>

int count=0; //biến toàn cục đếm số phần tử
//tạo Node bao gồm data là số nguyên và con trỏ
struct Node
{
    int data;
    struct Node *pNext;
};

//khai báo danh sách liên kết đơn
struct List
{
    //2 con trỏ quản lí đầu và cuối danh sách
    Node *pHead;
    Node *pTail;
};

//khởi tạo
void Khoi_tao(List &list)
{
    //cho 2 con tro quan li la nullptr vi khong co phan tu
    list.pHead = nullptr;
    list.pTail = nullptr;
}

Node *Khoi_tao_Node(const int &value) 
{
    Node *p = new Node; //cấp phát động cho Node p
    if (p==nullptr)
    {
        std::cout<<"\nKhong du bo nho de cap phat"; //phòng khi RAM không đủ
        return nullptr;
    }
    p->data = value;    //giá trị truyền vào data
    p->pNext = nullptr; //đầu tiên khai báo Node => chưa có liên kết => con trỏ trỏ đến nullptr
    return p;
}

//thêm node vào đầu danh sách liên kết
void Add_head(List &list, const int &x) //node p là node cần thêm vào
{
    Node *add = Khoi_tao_Node(x);

    if (list.pHead == nullptr)
    {
        list.pHead = list.pTail = add; //node đầu cũng chính là node cuối và là p
    }
        else
        {
            add->pNext = list.pHead; //cho con trỏ node p liên kết với node đầu pHead
            list.pHead = add; //pHead là node p
        }
    count++;
}

//thêm node vào cuối danh sách liên kết
void Add_tail(List &list, const int &x)
{
    Node *add = Khoi_tao_Node(x);

    if (list.pHead == nullptr)
    {
        list.pHead = list.pTail = add;
    }
        else
        {
            list.pTail->pNext = add;
            list.pTail = add;
        }
    count++;
}

//thêm node add vào sau node p
void Add_after(List &list, const int &x, const int &y)
{    
    for (Node *i =list.pHead; i!=nullptr;i = i->pNext)
        if (i->data == x)
        {
            Node *add = Khoi_tao_Node(y);
            add->pNext = i->pNext;
            i->pNext = add;
        }
    count++;
}

//thêm node vào trước một node khác
void Add_before(List &list, const int &x, const int &y)
{
    Node *g = new Node;
    for(Node *i = list.pHead;i!=nullptr;i = i->pNext)
    {
        if (i->data == x)
        {
            if (i== list.pHead) Add_head(list,y);
            else
            {
                Node *add =  Khoi_tao_Node(y);
                add->pNext = i;
                g->pNext = add;
            }
        }
        g=i;
    }
    count++;
}

//thêm node vào một vị trí bất kì
void Add_pos(List&list, const int &pos, const int &value)
{
    if (list.pHead == nullptr || pos ==1)
        Add_head(list,value);

    else if (pos ==count+1)
        Add_tail(list,value);

         else
         {
            int count_for_pos = 0;
            Node *g = new Node;
            for (Node *i = list.pHead; i!=nullptr; i = i->pNext)
            {
                count_for_pos++;
                if(count_for_pos == pos)
                {
                    Node *add = Khoi_tao_Node(value);
                    add->pNext = i;
                    g->pNext = add;
                    break;
                }
                g = i;
            }
         }
    count++;
}

//xóa node đầu
void Delete_head(List&list)
{
    if (count==0) std::cout<<"Danh sach khong co phan tu!";
    else if (count==1) Khoi_tao(list);
        else 
        {
            Node *temp = list.pHead;
            list.pHead = list.pHead->pNext;
            delete temp;
            count--;
        }
}

//xóa node cuối
void Delete_tail(List&list)
{
    if (count==0) std::cout<<"Danh sach khong co phan tu";
    else if (count==1) Khoi_tao(list);
        else 
        {
            for(Node *i = list.pHead;i != nullptr; i = i->pNext)
            if (i->pNext == list.pTail)
            {
                delete list.pTail;
                list.pTail = i;
                list.pTail->pNext= nullptr;
            }
            count--;
        }
    
}

//xóa 1 node sau 1 node
void Delete_after(List&list, const int &value)
{
    for(Node *i = list.pHead; i!=nullptr; i = i->pNext)
    {
        if (i->data == value && i != list.pTail)
        {
            Node *temp = i->pNext;
            i->pNext = temp->pNext;
            delete temp;
            count--;
        }
    }
    
}

//xóa 1 node ở 1 vị trí
void Delete_pos(List &list, const int &pos)
{
    if (count==0) 
    {
        std::cout<<"Danh sach khong co phan tu";
        return;
    }
    if (count==1)
    {
        Khoi_tao(list);
        count=0;
        return;
    }
    if (pos==1)
    {
        Delete_head(list);
        return;
    }
    if (pos==count)
    {
        Delete_tail(list);
        return;
    }

    int count_for_pos=1;
    Node *temp = list.pHead;
    for(Node *i = list.pHead->pNext; i!=nullptr; i = i->pNext)
    {
        count_for_pos++;
        if (count_for_pos == pos)
        {
            Node *del = i;
            temp->pNext = i->pNext;
            delete del;
            break;
        }
        temp = i;
    }
    count--;
}

//in danh sách
void Print_list(List list)
{
    for(Node *i = list.pHead; i!= nullptr; i = i->pNext) //Bắt đầu từ node đầu tiên, đến node cuối chỉ đến nullptr, sau đó tương tự với i++
        std::cout<<i->data<<" "; //xuất data
}


int main()
{
    int n;
    List l;
    Khoi_tao(l);
    std::cout<<"Nhap so node can them vao: ";
    std::cin>>n;
    for (int i=1;i<=n;i++)
    {
        int x;
        std::cout<<"Nhap so nguyen can them: ";
        std::cin>>x;
        Add_tail (l,x);
    }
    
    system("cls");
    int x,y;
    std::cout<<"Nhap vi tri node xoa: ";
    std::cin>>x;

    Delete_pos(l,x);
    std::cout<<"\nDanh sach lien ket: ";
    Print_list(l);

    return 0;
}

