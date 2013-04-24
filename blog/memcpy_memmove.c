memcpy memmove�����ʵ��

memcpy��memmove��Ŀ�Ķ��ǽ�N���ֽڵ�Դ�ڴ��ַ�����ݿ�����Ŀ���ڴ��ַ�С�

����Դ�ڴ��Ŀ���ڴ�����ص�ʱ��memcpy����ִ��󣬶�memmove����ȷ��ʵʩ����������Ҳ������һ��㿪����

memmove�Ĵ����ʩ��

��1����Դ�ڴ���׵�ַ����Ŀ���ڴ���׵�ַʱ���������κο���

��2����Դ�ڴ���׵�ַ����Ŀ���ڴ���׵�ַʱ��ʵ�����򿽱�

��3����Դ�ڴ���׵�ַС��Ŀ���ڴ���׵�ַʱ��ʵ�з��򿽱�

-- memcpyʵ��
void* memcpy(void* dest, const void* src, size_t n)
{
    char*      d = (char*) dest;
    const char*  s = (const char*) src;
    while(n-?)
       *d++ = *s++;
    return dest;
}

��

-- memmoveʵ��
void* memmove(void* dest, const void* src, size_t n)
{
    char*     d  = (char*) dest;
    const char*  s = (const char*) src;

    if (s>d)
    {
         // start at beginning of s
         while (n--)
            *d++ = *s++;
    }
    else if (s<d)
    {
        // start at end of s
        d = d+n-1;
        s = s+n-1;

        while (n--)
           *d-- = *s--;
    }
    return dest;
}

��ʾ��ͼ��

��1���ڴ�Ͷ� <-----s-----> <-----d-----> �ڴ�߶� start at end of s
��2���ڴ�Ͷ� <-----s--<==>--d----->      �ڴ�߶� start at end of s
��3���ڴ�Ͷ� <-----sd----->              �ڴ�߶� do nothing
��4���ڴ�Ͷ� <-----d--<==>--s----->      �ڴ�߶� start at beginning of s
��5���ڴ�Ͷ� <-----d-----> <-----s-----> �ڴ�߶� start at beginning of s
