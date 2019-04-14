#include <stdio.h>
#include <stdlib.h>
typedef struct LNode{
    double a;//系数
    double b;//指数
    struct LNode *next;
}LNode,*LinkList;
void Init_LinkList(LinkList &L){
    L=(LinkList)malloc(sizeof(LNode));
    L->next=NULL;
}
void Input_LinkList(LinkList &L){
    double aa,bb;
    while(scanf("%lf%lf",&aa,&bb)!=EOF){
          LinkList p;
          p=(LinkList)malloc(sizeof(LNode));
          p->a=aa;
          p->b=bb;
          p->next=(L)->next;
          (L)->next=p;}
}
void Print_LinkList(LinkList L){
    LinkList p;
    p=L->next;
    if(p){
        if(p->b){
            printf("%fx^%f",p->a,p->b);
            p=p->next;
        }
        else{
            printf("%f",p->a);
            p=p->next;
        }
    }
    while(p){
        if(p->b){
            if(p->a) printf("%+fx^%f",p->a,p->b);
            else p=p->next;
        }
        else
            printf("%+f",p->a);
        p=p->next;
    }
}
void Add_LinkList(LinkList la,LinkList lb,LinkList &lc){
    LinkList pa,pb,pc;
    pa=la->next;
    pb=lb->next;
    pc=lc;
    while(pa&&pb){
        if((pa->b)<(pb->b)){
            pc->next=pb;pb=pb->next;pc=pc->next;pc->next=NULL;
        }
        if((pa->b)>(pb->b)){
            pc->next=pa;pa=pa->next;pc=pc->next;pc->next=NULL;
        }
        if((pa->b)==(pb->b)){
            if((pa->a)=(pa->a)+(pb->a)){
                pc->next=pa;pa=pa->next;pb=pb->next;pc=pc->next;pc->next=NULL;
            }
            else{
                pa=pa->next;pb=pb->next;
            }
        }
    }
    if(pb) pc->next=pb;
    else pc->next=pa;
}
int main(void)
{
    LinkList la,lb,lc;
    Init_LinkList(lc);
    Init_LinkList(la);
    Init_LinkList(lb);
    printf("请输入一元多项式\n");
    Input_LinkList(la);
    printf("请输入一元多项式\n");
    Input_LinkList(lb);
    printf("他们的和为\n");
    Add_LinkList(la,lb,lc);
    Print_LinkList(lc);
    return 0;
}
