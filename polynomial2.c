#include<stdio.h>
#include<math.h>
int i,j,n1,n2,k,l,m,p,q,x,y,r,t,u,s;
int w=0;
void poly1st(),poly2nd(),process();
char function;
int set[244];

//main code starts from here
int main(){
    printf("Enter degree of polynomial 1: ");
    scanf("%d",&n1);
    printf("Enter degree of polynomial 2: ");
    scanf("%d",&n2);

    i=j=fmax(n1,n2)+1;
    int poly1[i],poly2[j];
    int set[i*i];
//initialization of all elements of 1st and 2nd array = 0
    for (r=fmax(n1,n2);r>(-1);r--)
    {
        poly1[r]=0;
    }
    for (t=fmax(n1,n2);t>(-1);t--)
    {
        poly2[t]=0;
    }
    for (s=(i*i)-1;s>(-1);s--)
    {
        set[s]=0;
    }
    
    
    printf("\n");
    printf("Coefficient 1 is the coefficient of the\nvariable of the highest degree and same\ncontinued for polynomial 2\n\n");
//process for selecting array for 1st polynomial
    for (k=n1;k>(-1);k--)
    {
        printf("Enter coefficient %0.0d of polynomial 1: ",n1+1-k);
        scanf("%d",&poly1[k]);
    }
    printf("Polynomial 1 is: ");
    for (l=n2;l>(-1);l--)
    { 
        printf("%dx^%d,", poly1[l],l);
    }
    printf("\n");
//process for selecting array for 2nd polynomial
    for (p=fmax(n1,n2);p>(-1);p--)
    {
        printf("Enter coefficient %0.0d of polynomial 2: ",n2+1-p);
        scanf("%d",&poly2[p]);
    }
    printf("Polynomial 2 is: ");
    for (q=fmax(n1,n2);q>(-1);q--)
    { 
        printf("%dx^%d,", poly2[q],q);
    }
    printf("\n");
//now process for operation addition subtraction or multiplication
    printf("Enter your Choice\n+\n*\n- :-\na(poly1-poly2)\nb(poly2-poly1) : ");
    scanf(" %c", &function);
    printf("\nResult is:\n");
    switch (function)
    {
    case '+':
        for (m=fmax(n1,n2);m>(-1);m--)
        {
            printf("%dx^%d,",poly1[m]+poly2[m],m);
        }
        break;
    case 'a':
        for (m=fmax(n1,n2);m>(-1);m--)
        {
            printf("%dx^%d,",poly1[m]-poly2[m],m);
        }
        break;
    case 'b':
        for (m=fmax(n1,n2);m>(-1);m--)
        {
            printf("%dx^%d,",poly2[m]-poly1[m],m);
        }
        break;
    case '*':
        for (x=0;x<fmax(n1,n2)+1;x++)
        {
            for (y=0;y<fmax(n1,n2)+1;y++)
            {
                set[w]=poly1[x]*poly2[y];
                printf("%dx^%d,",poly1[x]*poly2[y],x+y);
                w++;
            }
            printf("\n");
        }
        break;
    default:
    printf("\nInvalid Function\n");
        break;
    }
    printf("\n\n");
    return 0;
}