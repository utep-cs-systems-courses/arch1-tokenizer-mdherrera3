OBJS= tokenizer.o simpleui.o history.o

all:simpleui

simpleui:$(OBJS)

	cc -o simpleui $(CFLAGS) $(OBJS)

$(OBJS): tokenizer.h history.h


clean:

	rm -f *.o simpleui

run: simpleui
	./simpleui
