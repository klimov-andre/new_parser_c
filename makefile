FNAME = test
SOURCES = src
TEMPORARY = tmp
BUILD = run

lex:
	lex -o $(TEMPORARY)/lex.yy.c $(SOURCES)/$(FNAME).l
	
yacc:
	yacc -dt  $(SOURCES)/$(FNAME).y -o $(TEMPORARY)/y.tab.c

clean: 
	rm -rf $(TEMPORARY)
	rm -rf $(BUILD)

build:
	cc $(TEMPORARY)/lex.yy.c $(TEMPORARY)/y.tab.c -o $(BUILD)/$(FNAME)

all: 
	mkdir -p $(BUILD)
	mkdir -p $(TEMPORARY)
	make lex yacc build

rebuild: clean all
