 /*
 
����һ������������ʹ�������ֵ���������������е����ֵݼ�����1.���ݼ�����2.�ݼ����и�λ��֮����������֮�͡�

�ݼ�����һ�����ֵĵݼ�����ָ���ڵ���λ�Ӵ�С���е����֣����������ڵ���λ��С��ͬ�������

���ݼ��������������������еݼ�����ֵ����һ���� �磺 75345323���ݼ����У�75,753,53,53,532,32����ô���ĵݼ���Ϊ753��

��λ����֮�����ĵݼ���: ��75345323�еĸ��ݼ�����75��λ��֮��=12(7+5=12),753��λ��֮��=15(7+5+3=15),53��λ��֮��=8(5+3=8),532��λ��֮��=10(5+3+2=10),32��λ��֮��=5(3+2=5)����ô��λ����֮�����ĵݼ���Ϊ753��

������=���ݼ���+��λ��֮�����ĵݼ�����(1506=753+753)

 
 */
 
 // O(N)..
 
 #include <stdio.h>
 #include <math.h>
 #include <stdlib.h>
 #include <string.h>
 
 int main(int argc, char **argv)
 {
     int N;
     char str[32];
     int max_value, max_bits_value, max_bits, temp_value, temp_bits;
     int i, len;
     while(scanf("%d", &N) != EOF)
     {
           if(N < 0) N = abs(N);
           itoa(N, str, 10);
           max_value = 0;
           max_bits_value = 0;
           max_bits = 0;
           temp_value = 0;
           temp_bits = 0;
           len = strlen(str);
           for(i = 0; i < len; )
           {
                  temp_value = str[i] - '0';
                  temp_bits = str[i] - '0';
                  i++;
                  while( (i < len) && (str[i - 1] > str[i]))
                  {
                         temp_value = temp_value*10 + str[i] - '0';
                         temp_bits = temp_bits + str[i] - '0';
                         i++;
                  }
                  if(temp_value > max_value)  max_value = temp_value;
                  if(temp_bits > max_bits)
                  {
                       max_bits = temp_bits;
                       max_bits_value = temp_value;
                  }
           }
           printf("%d\n", max_value + max_bits_value);
           
           
     }
     
     return 0;
 }
