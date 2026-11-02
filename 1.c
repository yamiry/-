#include <stdio.h>
#define MAXSIZE 100

typedef struct{
    int data[MAXSIZE];
    int length; 
} SqList;

// 1
void InitList(SqList *L){
    L->length = 0;
}

// 2
void CreateList(SqList *L, int n){
    if(n<0 || n>MAXSIZE){
        printf("创建失败，长度非法！\n");
        return;
    }
    L->length = n;
    printf("请输入%d个元素：",n);
    for(int i=0;i<n;i++){
        scanf("%d",&L->data[i]);
    }
}

//3
int IsEmpty(SqList *L){
    if(L->length == 0)
        return 1;
    else
        return 0;
}

//4
int GetLength(SqList *L){
    return L->length;
}

//5
void PrintList(SqList *L){
    if(IsEmpty(L)){
        printf("顺序表为空！\n");
        return;
    }
    printf("顺序表元素：");
    for(int i=0;i<L->length;i++){
        printf("%d ",L->data[i]);
    }
    printf("\n");
}

//6
int GetElem(SqList *L, int position, int *e){
    if(position<1 || position>L->length)
        return 0;
    *e = L->data[position-1];
    return 1;
}

//7.1
int SearchSeq(SqList *L, int value){
    for(int i=0;i<L->length;i++){
        if(L->data[i]==value)
            return i+1;
    }
    return 0;
}

//7.2
int SearchBinary(SqList *L, int value){
    int low=0, high = L->length-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(L->data[mid]==value)
            return mid+1;
        else if(L->data[mid]>value)
            high = mid-1;
        else
            low = mid+1;
    }
    return 0;
}

//8
int ListInsert(SqList *L, int position, int x){
    if(position<1 || position>L->length+1) return 0;
    if(L->length >= MAXSIZE) return 0;
    //后移元素
    for(int i = L->length; i>=position; i--){
        L->data[i] = L->data[i-1];
    }
    L->data[position-1] = x;
    L->length++;
    return 1;
}

//9
int ListDeletePos(SqList *L, int position){
    if(position<1 || position>L->length) return 0;
    for(int i=position-1; i<L->length-1;i++){
        L->data[i] = L->data[i+1];
    }
    L->length--;
    return 1;
}

//10
void ListDeleteValue(SqList *L, int value){
    int j=0;
    for(int i=0;i<L->length;i++){
        if(L->data[i] != value){
            L->data[j++] = L->data[i];
        }
    }
    L->length = j;
}

int main(){
    SqList L;
    InitList(&L);
    int op,n,pos,e,x,val,res;
    printf("=====顺序表操作菜单=====\n");
    printf("2.创建顺序表\n3.判断是否为空\n4.获取长度\n5.打印顺序表\n");
    printf("6.取位置元素\n7.查找(1顺序 2二分)\n8.插入元素\n9.按位置删除\n10.按值删除全部\n0.退出\n");
    while(1){
        printf("\n请输入操作序号：");
        scanf("%d",&op);
        switch(op){
            case 2:
                printf("输入创建元素个数：");
                scanf("%d",&n);
                CreateList(&L,n);
                break;
            case 3:
                if(IsEmpty(&L)) printf("顺序表是空\n");
                else printf("顺序表非空\n");
                break;
            case 4:
                printf("顺序表长度：%d\n",GetLength(&L));
                break;
            case 5:
                PrintList(&L);
                break;
            case 6:
                printf("输入要获取的位置：");
                scanf("%d",&pos);
                if(GetElem(&L,pos,&e)) printf("该位置元素=%d\n",e);
                else printf("位置非法\n");
                break;
            case 7:
                printf("1顺序查找 2二分查找，请选择：");
                scanf("%d",&n);
                printf("输入查找值：");
                scanf("%d",&val);
                if(n==1){
                    res = SearchSeq(&L,val);
                }else{
                    res = SearchBinary(&L,val);
                }
                if(res) printf("找到，位置：%d\n",res);
                else printf("未找到\n");
                break;
            case 8:
                printf("输入插入位置、插入值：");
                scanf("%d%d",&pos,&x);
                if(ListInsert(&L,pos,x)) printf("插入成功\n");
                else printf("插入失败\n");
                break;
            case 9:
                printf("输入要删除的位置：");
                scanf("%d",&pos);
                if(ListDeletePos(&L,pos)) printf("删除成功\n");
                else printf("删除失败\n");
                break;
            case 10:
                printf("输入要删除的值：");
                scanf("%d",&val);
                ListDeleteValue(&L,val);
                printf("已删除所有值为%d的元素\n",val);
                break;
            case 0:
                printf("程序结束");
                return 0;
            default:
                printf("输入错误，请重新选择！");
        }
    }
    return 0;
}
