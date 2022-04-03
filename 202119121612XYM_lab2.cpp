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
        printf("----Will remove student next to num %d----\n",pre->num);
        node* tem = pre->next;
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
        printf("----The number or name you want to find :----\n\t");
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
        printf("----Display as follows:----\n");
        node* p = head->next;
        while(p)
        {
            cout<<"\t"<<p->num<<" "<<p->name<<" "<<p->mark<<'\n';
            p=p->next;
        }
    }

    void showL()
    {
        printf("----The length is %d ----\n");
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
        printf("----List has been destoryed----\n");
    }

    node* findval(double price)
    {
        printf("----The value you want to find :----\n\t");
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
    a.open("data.txt",ios::in | ios::app);

    list l1;
    l1.create();
    while(a>>num>>name>>price)
    {
        l1.hadd(num,name,price);
    }

    printf("----FILE IN FINISHED----\n");
    printf("----OP----\n");
    printf("1.add\n2.remove\n3.display\n4.find by name or num\n5.find by value\n6.destory\n7.end");
    printf("\n----OP----\n");
    while(cin>>op)
    {
        if (op == "1")
        {
            string pre;
            printf("SHOW THE INFO OF THE PRE\n");
            cin>>pre;
            printf("THE INFO YOU WANT TO ADD\n");
            cin>>num>>name>>price;
            l1.add(l1.findstr(pre),num,name,price);
            printf("----FINISHED----\n");
        }
        else if (op == "2")
        {
            string pre;
            printf("SHOW THE INFO OF THE PRE\n");
            cin>>pre;
            l1.remove(l1.findstr(pre));
            printf("----FINISHED----\n");
        }
        else if (op == "3")
        {
            l1.display();
            printf("----FINISHED----\n");
        }
        else if (op == "4")
        {
            string tar;
            cin>>tar;
            l1.findstr(tar);
            printf("----FINISHED----\n");
        }
        else if (op == "5")
        {
            cin>>price;
            l1.findval(price);
            printf("----FINISHED----\n");
        }
        else if (op == "6")
        {
            l1.destory();
            printf("----FINISHED----\n");
        }
        else 
        {
            printf("THANK YOU FOR YOUR USING !\n");
            break;
        }
    }
    a.close();
    system("pause");
    return 0;
}
