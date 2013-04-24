/*
 *ftell() �� fseek() �ó����ͱ�ʾ�ļ��ڵ�ƫ�� (λ��), ���, ƫ������������ 20 �� (231-1) ���ڡ����µ� fgetpos() �� fsetpos()
 *����ʹ����һ����������Ͷ��� fpos_t ����ʾƫ������������ͻ��ʵ�ѡ��, ���, fgetpos() �� fsetpos ���Ա�ʾ�����С���ļ�
 *ƫ�ơ�fgetpos() ��  gsetpos() Ҳ����������¼���ֽ���ʽ�ļ���״̬��
 */

/*-----------------------------------------------------------------------------
 *  ����ԭ�ͣ� int fsetpos(FILE *fp, const fpos_t *pos);
 *-----------------------------------------------------------------------------*/
/*ͷ�ļ���#include<stdio.h>
 *
 *�Ƿ��Ǳ�׼��������
 *
 *�������ܣ����ļ�ָ�붨λ��posָ����λ���ϡ��ú����Ĺ�����ǰ���ᵽ��fgetpos�෴���ǽ��ļ�ָ��fp����posָ����λ�����ļ��ж�λ��posֵ���ڲ���ʽ�洢,����fgetpos��fsetposʹ�á�
 *
 *����ֵ���ɹ�����0�����򷵻ط�0��
 *
 *�������� Ӧ��fsetpos������λ�ļ�ָ�롣
 */

#include <stdio.h>

void main( void )

{

   FILE   *fp;

   fpos_t pos;

   char   buffer[50];

   /*��ֻ����ʽ����Ϊtest.txt���ļ�*/

   if( (fp = fopen( "test.txt", "rb" )) == NULL )

      printf( "Trouble opening file/n" );

   else

   {

      /*����posֵ*/

      pos = 10;

      /*Ӧ��fsetpos�������ļ�ָ��fp����

      posָ����λ�����ļ��ж�λ*/

      if( fsetpos( fp, &pos ) != 0 )

        perror( "fsetpos error" );

            else

            {

                /*���¶�λ���ļ�ָ�뿪ʼ��ȡ16���ַ���buffer������*/

                fread( buffer, sizeof( char ), 16, fp );

                 /*��ʾ���*/

                printf( "16 bytes at byte %ld: %.16s/n", pos, buffer );

                }

      }

   fclose( fp );

}

/*
 *����˵����
 *
 *��1�����ȣ�������ֻ����ʽ����Ϊtest.txt���ļ��������test.txt�ļ����Ѵ����ַ���This is a test for testing the function of fsetpos.
 *
 *��2����pos����Ϊ10��Ӧ��fsetpos�������ļ�ָ��fp����posָ����λ�����ļ��ж�λ�������ļ�ָ��fpָ���ַ�����test����ĸt��
 *
 *��3���ٴ��¶�λ���ļ�ָ�뿪ʼ��ȡ16���ַ���buffer��������Ҳ����˵��ȡ�ַ���"test for testing"��������buffer��
 *
 *��4�������ʾ�����16 bytes at byte 10: test for testing ��
 */





/*-----------------------------------------------------------------------------
 *  ����ԭ�ͣ�int fgetpos( FILE *stream, fpos_t *pos );
 *-----------------------------------------------------------------------------*/

/*
 *ͷ�ļ���#include<stdio.h>
 *
 *�Ƿ��Ǳ�׼��������
 *
 *�������ܣ�ȡ�õ�ǰ�ļ���ָ����ָ��λ�ã����Ѹ�ָ����ָ��λ������ŵ�pos��ָ�Ķ����С�posֵ���ڲ���ʽ�洢,����fgetpos��fsetposʹ�á�����fsetpos�Ĺ�����fgetpos�෴��Ϊ����ϸ���ܣ����ں�ڸ���˵����
 *
 *����ֵ���ɹ�����0��ʧ�ܷ��ط�0��������errno��
 *
 *�������£�Ӧ��fgetpos����ȡ�õ�ǰ�ļ���ָ����ָ��λ�á�
 */

#include <string.h>

#include <stdio.h>

int main(void)

{

   FILE *fp;

   char string[] = "This is a test";

   fpos_t pos;

   /* �Զ�д��ʽ��һ����Ϊtest.txt���ļ� */

   fp = fopen("test.txt", "w+");

   /* ���ַ���д���ļ� */

   fwrite(string, strlen(string), 1, fp);

   /* ȡ��ָ��λ�ò�����&pos��ָ��Ķ��� */

   fgetpos(fp, &pos);

   printf("The file pointer is at byte %ld/n", pos);

    /*�����ļ�ָ���λ��*/

   fseek(fp,3,0);

    /* �ٴ�ȡ��ָ��λ�ò�����&pos��ָ��Ķ��� */

   fgetpos(fp, &pos);

   printf("The file pointer is at byte %ld/n", pos);

   fclose(fp);

   return 0;

}

/*
 *����˵����
 *
 *��1�����ȣ������Զ�д��ʽ��һ����Ϊtest.txt���ļ��������ַ���"This is a test"д���ļ���ע�⣺�ַ�����14���ֽڣ���ַΪ0~13����fwrite����д����ļ�ָ���Զ�ָ���ļ����һ���ֽڵ���һ��λ�á�����ʱ��fp��ֵӦ����14��
 *
 *��2������fgetpos����ȡ��ָ��λ�ò�����&pos��ָ��Ķ��󣬴�ʱ�� pos�е�����Ϊ14��Ȼ������Ļ����ʾ��The file pointer is at byte 14��
 *
 *��3������fseek���������ļ�ָ���λ�ã���fp��ֵΪ3����ָ���ļ��е�4���ֽڡ�
 *
 *�ٴ�ȡ��ָ��λ�ò�����&pos��ָ��Ķ���Ȼ������Ļ����ʾ��The file pointer is at byte 3��
 *
 */
