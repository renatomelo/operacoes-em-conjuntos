#Este arquivo é um meio simples de automatizar a compilação de um programa com vários arquivos.
# Tutorial básico: http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
#How to:
#	Abra o temrinal linux
#   Entre no diretorio do projeto
#   Execute o comando: make
#   Execute o programa: ./trabalho < entrada.txt


trabalho: func_basicas.c op_vetor.c
	gcc -o trabalho func_basicas.c op_vetor.c -I.