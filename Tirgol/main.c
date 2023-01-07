#include<stdio.h>




int main(){
int p =1;
int* p1= &p;
int**p2 =&p1;

printf("&p=%p\n *p1=%d\n &p1=%p\n**p2=%d",&p,*p1,&p1,**p2);
 



return -1;
}