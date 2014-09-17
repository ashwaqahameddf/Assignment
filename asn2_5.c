#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
 {
  int lineCount=0,p=0,x=0;
  FILE *file;
  FILE *fp;
  fp=fopen("ash3.c","w");
  file=fopen("data3.csv","r");
   if(file==NULL)
     {
       printf("file is not opened properly\n");
       return -1;
     }
  char line[100];

  while ((fgets(line,sizeof(line),file)) != NULL)
    {
     lineCount++;
    }
  char *lineArray[lineCount-1];
  char *token;
  const char *j=",";
  rewind(file);
  char *country_name[lineCount];
  char *capital_name[lineCount];
  long int population[lineCount];
  char *language[lineCount];
  while ((fgets(line,sizeof(line),file)) != NULL)
   {
      lineArray[p]=(char *)malloc(strlen(line));//1st bunch of memory allocated
      strcpy(lineArray[p],line);
      token = strtok(lineArray[p],j);
      x=1;

      while( token != NULL)
        {
            if((x%4)==3)
              {
                population[p] =atoi(token);
                fprintf(fp," with a population of %ld ",population[p]);
              }
            else if((x%4)==1)
              {
                fprintf(fp, "The Capital of ");
                country_name[p]=malloc(strlen(token));
                strcpy(country_name[p],token);
                fprintf(fp,"%s",country_name[p]);
              }
           else if((x%4)==2)
              {
                fprintf(fp," is ");
                capital_name[p] = malloc(strlen(token));
                strcpy(capital_name[p],token);
                fprintf(fp,"%s",capital_name[p]);
              }
	    else if((x%4)==0)
	     {
		fprintf(fp," and the language spoken is ");
                language[p] = malloc(strlen(token));
                strcpy(language[p],token);
                fprintf(fp,"%s",language[p]);
		}
           token = strtok(NULL, j);
           x++;
        }   //end of inner while
    p++;
    fprintf(fp,"\n");
  }//end of outer while

fprintf(fp,"\n");
fclose(fp);
fclose(file);
return 0;
}
