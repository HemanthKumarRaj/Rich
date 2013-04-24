/*
 *strtok�������ƻ����ֽ��ַ���������������ǰ�͵��ú��s�Ѿ���һ���ˡ����
 *Ҫ����ԭ�ַ���������������ʹ��strchr��sscanf����ϵȡ�
 */
//C code
#include <string.h>
#include <stdio.h>
int main(void)
{
    char input[16] = "abc,d";
    char *p;
    /**/ /* strtok places a NULL terminator
            in front of the token, if found */
    p = strtok(input, ",");
    if (p) printf("%s\n", p);
    /**/ /* A second call to strtok using a NULL
            as the first parameter returns a pointer
            to the character following the token */
    p = strtok(NULL, ",");
    if (p) printf("%s\n", p);
    return 0;
}


//C++ code
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char sentence[]="This is a sentence with 7 tokens";
    cout<<"The string to be tokenized is:\n"<<sentence<<"\n\nThe tokens are:\n\n";
    char *tokenPtr=strtok(sentence," ");
    while(tokenPtr!=NULL)
    {
        cout<<tokenPtr<<'\n';
        tokenPtr=strtok(NULL," ");
    }
    //cout<<"After strtok, sentence = "<<tokenPtr<<endl;
    return 0;
}
/*
 *������һ�ε���������������������һ�ηָ�Ľ�������ش��е�һ�� ',' ֮ǰ���ַ���,Ҳ��������ĳ����һ�����abc��
 *�ڶ��ε��øú���strtok(NULL,","),��һ����������ΪNULL��������طָ����ݺ�����ִ������ڶ������d��
 *strtok��һ���̲߳���ȫ�ĺ�������Ϊ��ʹ���˾�̬����Ŀռ����洢���ָ���ַ���λ��
 *�̰߳�ȫ�ĺ�����strtok_r,ca
 *����strtok���ж�ip����mac��ʱ�����Ҫ���������ķ����ж�'.'��':'�ĸ�������Ϊ��strtok�ضϵĻ������磺"192..168.0...8..."����ַ�����strtokֻ���ȡ�ĴΣ��м��...���۶��ٶ��ᱻ����һ��key
 */
