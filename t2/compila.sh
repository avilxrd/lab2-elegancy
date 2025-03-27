echo "compilando arquivos .c para .o..."
gcc *.c -c
echo "linkando arquivos .o para gerar o executavel..."
gcc -o main main.o funcoes.o
echo "compilação concluída - para executar use ./main"