 /*
 
给出一个整数（负数使用其绝对值），输出这个整数中的两种递减数（1.最大递减数；2.递减数中各位数之和最大的数）之和。

递减数：一个数字的递减数是指相邻的数位从大到小排列的数字，不包含相邻的数位大小相同的情况。

最大递减数：所输入整数的所有递减数中值最大的一个。 如： 75345323，递减数有：75,753,53,53,532,32。那么最大的递减数为753。

各位数字之和最大的递减数: 如75345323中的各递减数：75各位数之和=12(7+5=12),753各位数之和=15(7+5+3=15),53各位数之和=8(5+3=8),532各位数之和=10(5+3+2=10),32各位数之和=5(3+2=5)。那么各位数字之和最大的递减数为753。

输出结果=最大递减数+各位数之和最大的递减数。(1506=753+753)

 
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
