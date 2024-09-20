// #include <stdio.h> 
// int main(){
// float *fp, **mfp, val; 
// fp = &val; 
// mfp = &fp; 
// **mfp = 123.903; 
// printf("%f %f", val, **mfp); 
// return 0;
// }

#include <stdio.h> 
int main(){
char *p, **mp, str [80] ; 
p = str; 
mp = &p;
printf ("Enter your name: "); 
gets (*mp) ; 
printf ("Hi %s", str);
return 0;
}