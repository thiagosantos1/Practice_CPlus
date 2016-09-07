all : main


main : bank.o checkingAccount.o savingsAcount.o main.o
	clang++ bank.o checkingAccount.o savingsAcount.o main.o -o main

bank.o : bank.cpp bank.h 
	clang++ -c bank.cpp


checkingAccount.o : checkingAccount.cpp checkingAccount.h bank.h
	clang++ -c checkingAccount.cpp


savingsAcount.o : savingsAcount.cpp savingsAcount.h bank.h
	clang++ -c savingsAcount.cpp

main.o : main.cpp savingsAcount.h checkingAccount.h bank.h
	clang++ -c main.cpp


clean :  // if you type make clean, it's gonna clean everything
	rm -f main *.o
