
#include<stdio.h>
struct ll
{
    int exp;
    int co;
    struct ll *link;
}*head1,*head2,*headr,*ptr1,*ptr2,*ptr3,*temp,*prev;

addNode1()
{


        if(head1==NULL)
        {
            head1=temp;
        }
        else
        {
            ptr1=head1;
            while(ptr1->link!=NULL)
            {
                ptr1=ptr1->link;
            }
            ptr1->link=temp;
        }

    }
void addNode2()
{


        if(head2==NULL)
        {
            head2=temp;
        }
        else
        {
            ptr2=head2;
            while(ptr2->link!=NULL)
            {
                ptr2=ptr2->link;
            }
            ptr2->link=temp;
        }

    }

    void addNode3()
{


        if(headr==NULL)
        {
            headr=temp;
        }
        else
        {
            ptr3=headr;
            while(ptr3->link!=NULL)
            {
                ptr3=ptr3->link;
            }
            ptr3->link=temp;
        }


    }



    void disp1(struct ll *h)
{
    ptr1=h;
    while(ptr1!=NULL)
    {
        printf("%dx^",ptr1->co);
        printf("%d ",ptr1->exp);
        ptr1=ptr1->link;
    }
}

void sort()
{
    int i,j,count=0,e,c;
    i=0;
    prev=head1;
   while(prev!=NULL)
   {
       count++;
       prev=prev->link;
   }
   while(i<count)
   {
        j=0;
       prev=head1;
       ptr1=prev->link;
       while(j<count-i-1)
       {
           if(prev->exp<ptr1->exp)
           {
               e=prev->exp;
               c=prev->co;
               prev->exp=ptr1->exp;
               prev->co=ptr1->co;
               ptr1->exp=e;
               ptr1->co=c;
           }
           prev=prev->link;
           ptr1=ptr1->link;
           j++;
       }
       i++;
   }
   count=0;
   prev=head2;
    i=0;
   ptr2=prev->link;
   while(prev!=NULL)
   {
       count++;
       prev=prev->link;
   }
   while(i<count)
   {
        j=0;
       prev=head2;
       ptr2=prev->link;
       while(j<count-i-1)
       {


           if(prev->exp<ptr2->exp)
           {
               e=prev->exp;
               c=prev->co;
               prev->exp=ptr2->exp;
               prev->co=ptr2->co;
               ptr2->exp=e;
               ptr2->co=c;
           }
           prev=prev->link;
           ptr2=ptr2->link;
           j++;
       }
       i++;
   }
}

void main()
{
    head1=NULL;
    head2=NULL;
    headr=NULL;
    int n1,n2,i,expo,cof;
    printf("no. of terms in 1:");
    scanf("%d",&n1);
    printf("no. of terms in 2:");
    scanf("%d",&n2);
    printf("enter eq 1:-\n");
    for(i=0;i<n1;i++)
    {
        printf("enter coef %d:",i+1);
        scanf("%d",&cof);
        printf("enter exp %d:",i+1);
        scanf("%d",&expo);
        temp=(struct ll *)malloc(sizeof(struct ll));
        if(temp==NULL)
    {
        printf("no memory");
        return;
    }
        temp->co=cof;
        temp->exp=expo;
        temp->link=NULL;
        addNode1();

}
    printf("enter eq 2:-\n");
    for(i=0;i<n2;i++)
    {
        printf("enter coef %d:",i+1);
        scanf("%d",&cof);
        printf("enter exp %d:",i+1);
        scanf("%d",&expo);
        temp=(struct ll *)malloc(sizeof(struct ll));
    if(temp==NULL)
    {
        printf("no memory");
        return;
    }
        temp->co=cof;
        temp->exp=expo;
        temp->link=NULL;
        addNode2();

    }
sort();
disp1(head1);
printf("\n");
disp1(head2);

ptr1=head1;
ptr2=head2;
while(ptr1!=NULL || ptr2!=NULL)
{
    if(ptr1->exp==ptr2->exp)
    {
       temp=(struct ll *)malloc(sizeof(struct ll));
       if(temp==NULL)
    {
        printf("no memory");
        return;
    }
        temp->co=ptr2->co+ptr1->co;
        temp->exp=ptr1->exp;
        temp->link=NULL;
        addNode3();
        ptr1=ptr1->link;
        ptr2=ptr2->link;
    }
    else if(ptr1->exp>ptr2->exp)
    {
            temp=(struct ll *)malloc(sizeof(struct ll));
            if(temp==NULL)
    {
        printf("no memory");
        return;
    }
        temp->co=ptr1->co;
        temp->exp=ptr1->exp;
        temp->link=NULL;
        addNode3();
        ptr1=ptr1->link;
    }
    else if(ptr1->exp<ptr2->exp)
    {
        temp=(struct ll *)malloc(sizeof(struct ll));
        if(temp==NULL)
    {
        printf("no memory");
        return;
    }
        temp->co=ptr2->co;
        temp->exp=ptr2->exp;
        temp->link=NULL;
        addNode3();
        ptr2=ptr2->link;
    }
    else
    {
        if(ptr1!=NULL)
        {
            temp=(struct ll *)malloc(sizeof(struct ll));
            if(temp==NULL)
    {
        printf("no memory");
        return;
    }
        temp->co=ptr1->co;
        temp->exp=ptr1->exp;
        temp->link=NULL;
        addNode3();
        ptr1=ptr1->link;
        }
        else
        {
            if(ptr2!=NULL)
            {
            temp=(struct ll *)malloc(sizeof(struct ll));
            if(temp==NULL)
    {
        printf("no memory");
        return;
    }
            temp->co=ptr2->co;
            temp->exp=ptr2->exp;
            temp->link=NULL;
            addNode3();
            ptr2=ptr2->link;
            }
        }
    }
}
printf("\n");
disp1(headr);

}
