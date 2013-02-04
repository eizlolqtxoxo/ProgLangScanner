ALL: scanner-simplest  scanner-simplest-lex 


scanner-simplest-lex: simplest.o scanner-lex.o
							cc -o scanner-simplest-lex scanner-lex.o simplest.o





