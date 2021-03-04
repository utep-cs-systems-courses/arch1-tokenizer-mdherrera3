tokenizer: tokenizer.o simpleui.o history.o
	cc -o tokenizer tokenizer.o simpleui.o history.o

clean:

	rm -f *.o tokenizer

tokenizer.o: tokenizer.h tokenizer.c

simpleui.o: simpleui.c tokenizer.h history.h

history.o: history.h history.c tokenizer.h
