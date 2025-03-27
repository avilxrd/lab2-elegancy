// #include <stdio.h>
// #include <string.h>


// void calcular( int *hist, const char*str) {
//     memset( hist, 0, 256 * sizeof(int));
//     while(*str)
//         hist[(unsigned char) *(str++)]++;
// }


// int main(void) {
//     unsigned char c;
//     int histograma[256];
//     char palavra[30] = "";

//     printf("Informe uma palavra: ");
//     gets(palavra);

//     calcular( histograma, palavra );

//     for( c = 'a'; c <= 'z'; c++ )
//         printf("%c = %d\n", c, histograma[c]);

//     return 0;
// }