.SILENT:

FNAME = test
SOURCES = src
TEMPORARY = tmp
BUILD = run
TEST_DIR = test

lex:
	mkdir -p $(TEMPORARY)
	lex -o $(TEMPORARY)/lex.yy.c $(SOURCES)/$(FNAME).l

yacc:
	mkdir -p $(TEMPORARY)
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

mtest:
	for file in $(TEST_DIR)/*.c ; \
	do \
		 echo "$$file" ; \
		 ./$(BUILD)/$(FNAME) $$file ;\
	done 
	
