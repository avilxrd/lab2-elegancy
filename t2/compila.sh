echo "Compilando arquivos .c para .o..."
gcc *.c -c
echo "Linkando arquivos .o para gerar o executável..."
gcc -o main main.o funcoes.o

echo "Compilação concluída. Execute o programa com ./main"