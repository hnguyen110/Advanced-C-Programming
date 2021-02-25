/usr/local/gcc/10.2.0/bin/g++ -Wall -std=c++17 -g -o ws Utils.cpp Utils.h Book.cpp Book.h Movie.cpp Movie.h SpellChecker.cpp SpellChecker.h main.cpp 
valgrind --leak-check=full ws books.txt movies.txt missing_file.txt words.txt
