#include<conio.h>
#include<stdio.h>
#include<string.h>
main()
{
      FILE *p1,*p2;
      p1=fopen("spy.in","r");
      p2=fopen("spy.out","w");
      int i,j,z[26],taga=0,tagb=0,x[101];
      char a[101],b[101],c[101];
      fscanf(p1,"%s",&a);
      fscanf(p1,"%s",&b);
      fscanf(p1,"%s",&c);
      for(i=0;i<26;i++)   z[i]=0;
      for(i=0;b[i]!='\0';i++)   z[b[i]-'A']=1;
      for(i=0;i<26;i++)
      {
                       if(z[i]==0)
                       {
                                  taga=1;
                                  break;
                       }
      }
      if(taga==1)   fprintf(p2,"Failed");
      else
      {
          for(i=0;a[i]!='\0';i++)
                    for(j=0;b[j]!='\0';j++)
                    {
                                           if(a[i]==a[j]&&b[i]!=b[j])
                                           {
                                                     tagb=1;
                                                     break;
                                           }
                    }
          if(tagb==1)   fprintf(p2,"Failed");
          else
          {
              for(i=0;c[i]!='\0';i++)
                   for(j=0;a[j]!='\0';j++)
                   {
                                          if(c[i]==a[j])
                                          {
                                                        x[i]=j;
                                                        break;
                                          }
                   }
              for(i=0;c[i]!='\0';i++)
                        fprintf(p2,"%c",b[x[i]]);
          }
      }
}
