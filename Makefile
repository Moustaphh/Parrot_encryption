

SUPP=rm

EXEC=main

ARCHIVE=main.zip


SRC=$(wildcard *.c)


OBJ=$(SRC:.c=.o)

%.o: %.c
	gcc -o $@ -c $<


$(EXEC):$(OBJ)
	gcc -o $(EXEC) $^


zip:
	tar -cvzf $(ARCHIVE) *.c *.h


clean:
	$(SUPP) -rf *.o


mrproper: clean
	$(SUPP) -f $(EXEC)