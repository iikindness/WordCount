#include <stdio.h>
#include <string.h>
int main (int argc, char *argv[]) {
	
    FILE *fp;
    int count = 0; 
    
    //��ȡ�ĵ� 
    fp=fopen(argv[2], "r"); 
    
    //ͳ�Ƶ��ʸ���
    if (argv[1][1] == 'w') {
        char s[1024];
        while (fscanf(fp, "%s", s) != EOF)
        {
            count ++;
            for (int i = 1; i < strlen(s) - 1; i ++)
                if (s[i] == ',' && s[i - 1] != ',' && s[i + 1] != ',') 
                    count ++;
        }
        printf("������=%d\n", count);
    }
    
    //ͳ���ַ�����
    else if (argv[1][1] == 'c') {
        char c;
        while ((c = fgetc(fp)) != EOF) count ++;
        printf("�ַ���=%d", count);
    }

    fclose(fp);
    return 0;
}
