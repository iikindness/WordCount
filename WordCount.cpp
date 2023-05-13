#include <stdio.h>
#include <string.h>
int main (int argc, char *argv[]) {
	
    FILE *fp;
    int count = 0; 
    
    //读取文档 
    fp=fopen(argv[2], "r"); 
    
    //统计单词个数
    if (argv[1][1] == 'w') {
        char s[1024];
        while (fscanf(fp, "%s", s) != EOF)
        {
            count ++;
            for (int i = 1; i < strlen(s) - 1; i ++)
                if (s[i] == ',' && s[i - 1] != ',' && s[i + 1] != ',') 
                    count ++;
        }
        printf("单词数=%d\n", count);
    }
    
    //统计字符个数
    else if (argv[1][1] == 'c') {
        char c;
        while ((c = fgetc(fp)) != EOF) count ++;
        printf("字符数=%d", count);
    }

    fclose(fp);
    return 0;
}
