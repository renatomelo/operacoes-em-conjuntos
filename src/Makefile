#Este arquivo é um meio simples de automatizar a compilação de um programa com vários arquivos.
# Tutorial básico: http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
#How to:
#	1 Abra o terminal linux
#   2 Entre no diretorio do projeto
#   3 Execute o comando: make
#   4 Execute o programa: ./trabalho < ../entrada.txt


#trabalho: func_basicas.c op_vetor.c arvore.c
#	gcc -o trabalho func_basicas.c op_vetor.c arvore.c -I.

IDIR = ../include
CC = gcc
CFLAGS = -I$(IDIR)

ODIR = obj
LDIR = ../lib

LIBS = -lm

_DEPS = arvore.h op_vetor.h operacoes.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o op_vetor.o arvore.o operacoes.o
OBJ = $(patsubst %, $(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

trabalho: $(OBJ)
	gcc -W -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
