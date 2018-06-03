#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct polynomial
{
    int coef;
    int exp;
    struct polynomial *next;
};
struct polynomial poly_1[101000];
struct polynomial poly_2[101000];
int count1=0,count2=0;
struct polynomial *head1=NULL,*head2=NULL;

int myCompare(const void *p, const void *q)
{
    struct polynomial *e1,*e2;
    e1=(struct polynomial *)p;
    e2=(struct polynomial *)q;
    return e1->exp-e2->exp;
}

void createList()
{
    struct polynomial *p1,*q1;
    struct polynomial *p2,*q2;
    int i=0;
    while(i<count1)
    {
        p1=(struct polynomial *)malloc(sizeof(struct polynomial));
        p1->coef=poly_1[i].coef;
        p1->exp=poly_1[i].exp;
        if(head1==NULL)
        {
            head1=(struct polynomial *)malloc(sizeof(struct polynomial));
            head1->coef=-1;
            head1->exp=-1;
            head1->next=p1;
        }
        else
            q1->next=p1;
        q1=p1;
        i++;
    }
    q1->next=NULL;

    int j=0;
    while(j<count2)
    {
        p2=(struct polynomial *)malloc(sizeof(struct polynomial));
        p2->coef=poly_2[j].coef;
        p2->exp=poly_2[j].exp;
        if(head2==NULL)
        {
            head2=(struct polynomial *)malloc(sizeof(struct polynomial));
            head2->coef=-1;
            head2->exp=-1;
            head2->next=p2;
        }
        else
            q2->next=p2;
        q2=p2;
        j++;
    }
    q2->next=NULL;
}

void sum()
{
    struct polynomial *p1=head1->next,*q1=head1;
    struct polynomial *p2=head2->next,*q2=head2;

    while(p1!=NULL && p2!=NULL)
    {
        if(p2->exp<p1->exp)
        {
                q2->next=p2->next;
                q1->next=p2;
                p2->next=p1;
                p2=q2->next;
                q1=q1->next;
        }
        else if(p2->exp > p1->exp)
        {
            q1=p1;
            p1=p1->next;
        }
        else
        {
            p1->coef=p1->coef+p2->coef;
            if(p1->coef==0)
            {
                    q1->next=p1->next;
                    //free(p1);
                    p1=q1->next;
                    q2->next=p2->next;
                    //free(p2);
                    p2=q2->next;
            }
            else
            {
                q1=p1;
                p1=p1->next;
                q2->next=p2->next;
                //free(p2);
                p2=q2->next;
            }
        }
    }
    if(p1==NULL && p2!=NULL)
    {
        q1->next=p2;
    }
}

void printList()
{
    struct polynomial *p,*q;
    p=head1->next;
    while(p!=NULL)
    {
        printf("%d*x^%d",p->coef,p->exp);
        p=p->next;
        if(p!=NULL)
            if(p->coef>0)
            printf("+");
    }
}

int main()
{
    char poly1[101000],poly2[101000];

    scanf("%s",poly1);
    scanf("%s",poly2);

    int length1=strlen(poly1),length2=strlen(poly2);
    int i=0,j=0,sum1=0,sum2=0;
    if(poly1[0]!='-')
    {
        for (j = 0; poly1[j] != '*'; j++)
        {
            sum1 *= 10;
            sum1 += (int)poly1[j]-48;
        }
        poly_1[count1].coef=sum1;
        sum1=0;
        i=j+3;
        for(j=i;poly1[j]!='+' && poly1[j]!='-' && j<length1;j++)
        {
            sum2*=10;
            sum2+=(int)poly1[j]-48;
        }
        poly_1[count1].exp=sum2;

        sum2=0;
        i=j;
        count1++;
    }
    while(i<length1)
    {
        if(poly1[i]=='-')
        {
            for (j = i+1; poly1[j] != '*'; j++)
            {
                sum1 *= 10;
                sum1 += (int)poly1[j]-48;
            }
            poly_1[count1].coef=-sum1;
            sum1=0;
            i=j+3;
            for(j=i;poly1[j]!='+' && poly1[j]!='-' && j<length1;j++)
            {
                sum2*=10;
                sum2+=(int)poly1[j]-48;
            }
            poly_1[count1].exp=sum2;
            sum2=0;
            i=j;
            count1++;
        }
        else if(poly1[i]=='+')
        {
            for (j = i+1; poly1[j] != '*'; j++)
            {
                sum1 *= 10;
                sum1 += (int)poly1[j]-48;
            }
            poly_1[count1].coef=sum1;
            sum1=0;
            i=j+3;
            for(j=i;poly1[j]!='-' && poly1[j]!='+' && j<length1;j++)
            {
                sum2*=10;
                sum2+=(int)poly1[j]-48;
            }
            poly_1[count1].exp=sum2;
            sum2=0;
            i=j;
            count1++;
        }

    }
    qsort(poly_1,count1, sizeof(struct polynomial),myCompare);

    i=0;
    if(poly2[0]!='-')
    {
        for (j = 0; poly2[j] != '*'; j++)
        {
            sum1 *= 10;
            sum1 += (int)poly2[j]-48;
        }
        poly_2[count2].coef=sum1;
        sum1=0;
        i=j+3;
        for(j=i;poly2[j]!='+' && poly2[j]!='-' && j<length2;j++)
        {
            sum2*=10;
            sum2+=(int)poly2[j]-48;
        }
        poly_2[count2].exp=sum2;
        sum2=0;
        i=j;
        count2++;
    }
    while(i<length2)
    {
        if(poly2[i]=='-')
        {
            for (j = i+1; poly2[j] != '*'; j++)
            {
                sum1 *= 10;
                sum1 += (int)poly2[j]-48;
            }
            poly_2[count2].coef=-sum1;
            sum1=0;
            i=j+3;
            for(j=i;poly2[j]!='+' && poly2[j]!='-' && j<length2;j++)
            {
                sum2*=10;
                sum2+=(int)poly2[j]-48;
            }
            poly_2[count2].exp=sum2;
            sum2=0;
            i=j;
            count2++;
        }
        else if(poly2[i]=='+')
        {
            for (j = i+1; poly2[j] != '*'; j++)
            {
                sum1 *= 10;
                sum1 += (int)poly2[j]-48;
            }
            poly_2[count2].coef=sum1;
            sum1=0;
            i=j+3;
            for(j=i;poly2[j]!='-' && poly2[j]!='+' && j<length2;j++)
            {
                sum2*=10;
                sum2+=(int)poly2[j]-48;
            }
            poly_2[count2].exp=sum2;
            sum2=0;
            i=j;
            count2++;
        }

    }
    qsort(poly_2,count2, sizeof(struct polynomial),myCompare);

    createList();
    sum();
    printList();

}