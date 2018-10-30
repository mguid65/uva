#in\
clude<\
cstdio>
in\
t k, n, \
m, a, b                                            ;
int\
 main()                                                   {
  w\
hile(scanf("%d", &k) > 0 && k)                            {
    sca\
nf("%d %d", &n, &m)                                   ;
    fo\
r(int i = 0; i < k; i++)                               {
      sca\
nf("%d\
 %d", &a, &b)                                 ;
      if(a == n ||\
 b == m)                                   {
        pr\
intf("divi\
sa\n")                                  ;}
      else\
 if(a > n && b \
> m)                                {
        pri\
ntf("N\
E\n")                                      ;}
      else\
 if(a < n\
 && b > m)                                {
        pr\
intf("NO\n")                                      ;}
      else \
if(a > n \
&\
&\
 b < m)                                {
       pri\
ntf("SE\n")                                       ;}
      e\
lse                                                   {
        prin\
tf("\
SO\n")                                      ;}
                                                             }
                                                             }
                                                             }
