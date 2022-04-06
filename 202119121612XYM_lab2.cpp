#include<iostream>
#include<fstream>

using namespace std;

struct node
{
    string num;
    string name;
    double mark;
    node* next;
};

class list
{
    public :
    node* head;
    node* tail;
    int length = 0;

    void create()
    {
        head = new node;
        tail = new node;
        head->next = NULL;
        tail->next = NULL;
    }

    void hadd(string a,string b,double c)
    {
        node* n = new node;
        n->num = a;
        n->name = b;
        n->mark = c;
        n->next = head->next;
        head->next = n;
        length++;
    }
    
    void tadd(string a,string b,double c)
    {
        node* n = new node;
        n->num = a;
        n->name = b;
        n->mark = c;
        tail->next->next = n;
        tail->next = n;
        length++;
    }

    void remove(node* pre)
    {
        node* tem = pre->next;
        printf("前面是%d----\n",pre->num);
        pre->next = pre->next->next;
        free(tem);
        length--;
    }

    void add(node*pre,string a,string b,double c)
    {
        node* n = new node;
        n->num = a;
        n->name = b;
        n->mark = c;
        n->next = pre->next;
        pre->next = n ;
    }

    node* findstr(string a)
    {
        printf("----所求值是 :----\n\t");
        node* p = head->next;
        while(p || p->next)
        {
            if (p->name == a || p->num == a)
            {
                cout<<"NUM "<<p->num<<" NAME "<<p->name<<" MARK "<<p->mark<<'\n';
                return p;
            }
            p = p->next;
        }
        printf("ERROR\n");
        return NULL;
    }

    void display()
    {
        printf("----展示如下:----\n");
        node* p = head->next;
        while(p)
        {
            cout<<"\t"<<p->num<<" "<<p->name<<" "<<p->mark<<'\n';
            p=p->next;
        }
    }

    void showL()
    {
        printf("----此时链表长度为 %d ----\n",length);
    }

    void destory()
    {
        node* tem = new node;
        node* p = new node;
        p = head->next;
        tem = p->next;
        while(p)
        {
            free(p);
            p = tem;
            if (p)tem = p->next;
        }
        printf("----链表已经摧毁----\n");
    }

    node* findval(double price)
    {
        printf("----所求值为----\n\t");
        node* p = head->next;
        while(p || p->next)
        {
            if (p->mark == price)
            {
                cout<<"NUM "<<p->num<<" NAME "<<p->name<<" MARK "<<p->mark<<'\n';
                return p;
            }
            p = p->next;
        }
        printf("ERROR\n");
        return NULL;
    }
};


int main()
{
    string name,num,op;
    double price;

    fstream a;
    
    a.open("student.txt",ios::in | ios::app);

    list l1;

    cout<<"202119121612徐一鸣\n";
    cout<<"---------------------\n";
	cout << "1. 初使化链表\n"; 
    cout<<"2. 前插法构建链表\n";
    cout<<"3. 后插法构建链表\n";
    cout<<"4. 显示链表长度\n";
    cout<<"5. 显示链表内容\n";
    cout<<"6. 查找学生信息\n";
    cout<<"7. 获取学生信息\n";
    cout<<"8. 插入学生信息\n";
    cout<<"9. 删除学生信息\n";
    cout<<"10. 销毁链表\n";
    cout<<"0.退出\n";
    cout<<"请选择:\n";

    //printf("1.add\n2.remove\n3.display\n4.find by name or num\n5.find by value\n6.destory\n7.end");
    // printf("\n----OP----\n");
    while(cin>>op)
    {
        if (op == "1" )
        {
            l1.create();
        }

        if (op == "2" || op == "3")
        {
            while(a>>num>>name>>price)
            {
                l1.hadd(num,name,price);
            }
        }

        if (op == "4")l1.showL();

        if (op == "8")
        {
            string pre;
            printf("展示前驱\n");
            cin>>pre;
            printf("THE INFO YOU WANT TO ADD\n");
            cin>>num>>name>>price;
            l1.add(l1.findstr(pre),num,name,price);
            printf("----FINISHED----\n");
        }
        if (op == "9")
        {
            string pre;
            printf("展示前驱\n");
            cin>>pre;
            l1.remove(l1.findstr(pre));
            printf("----FINISHED----\n");
        }
        if (op == "5")
        {
            l1.display();
            printf("----FINISHED----\n");
        }
        if (op == "6")
        {
            string tar;
            cin>>tar;
            l1.findstr(tar);
            printf("----FINISHED----\n");
        }
        if (op == "7")
        {
            cin>>price;
            l1.findval(price);
            printf("----FINISHED----\n");
        }

        if (op == "10")
        {
            l1.destory();
            printf("----FINISHED----\n");
        }

        if (op == "0")
        {
            printf("已退出!\n");
            break;
        }
    }
    a.close();
    system("pause");
    return 0;
}
