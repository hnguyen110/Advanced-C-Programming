/*
 * Purpose: Workshop 5
 * Name Of Student: Hien Dao The Nguyen
 * Student Number: 103 152 195
 * Email: hnguyen110@myseneca.ca
 * Date: Friday Feb/12/2021
 * I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
 */

// Workshop 5 - Functions and Error Handling
// 2020/02 - Cornel
// 2021/01/19 - Chris
// 2021/02/12 - Cornel

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Collection.h"
#include "Collection.h"
#include "Book.h"
#include "Book.h"
#include "Movie.h"
#include "Movie.h"
#include "SpellChecker.h"
#include "SpellChecker.h"

using namespace sdds;

enum AppErrors {
    CannotOpenFile = 1, // An input file cannot be opened
    BadArgumentCount = 2, // The application didn't receive anough parameters
};

// The observer function for adding books to the collection:
//   should be called every time a new book is added to the collection
void bookAddedObserver(const Collection<Book> &theCollection,
                       const Book &theBook) {
    std::cout << "Book \"" << theBook.title() << "\" added!\n";
}

// The observer function for adding movies to the collection:
//   should be called every time a new movie is added to the collection
void movieAddedObserver(const Collection<Movie> &theCollection,
                        const Movie &theMovie) {
    std::cout << "Movie \"" << theMovie.title()
              << "\" added to collection \"" << theCollection.name()
              << "\" (" << theCollection.size() << " items).\n";
}

// ws books.txt movies.txt file_missing.txt file_words.txt
int main(int argc, char **argv) {
    std::cout << "Command Line:\n";
    std::cout << "--------------------------\n";
    for (int i = 0; i < argc; i++)
        std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
    std::cout << "--------------------------\n\n";

    // get the books
    sdds::Collection<sdds::Book> library("Bestsellers");
    if (argc == 5) {
        // TODO: load the first 4 books from the file "argv[1]".
        //       - read one line at a time, and pass it to the Book constructor
        //       - store each book read into the collection "library" (use the += operator)
        //       - lines that start with "#" are considered comments and should be ignored
        //       - if the file cannot be open, print a message to standard error console and
        //                exit from application with error code "AppErrors::CannotOpenFile"

        std::ifstream file_1(argv[1]);
        if (file_1.is_open()) {
            char buffer[256];
            size_t index = 0;
            while (file_1.is_open()) {
                file_1.getline(buffer, 255, '\n');
                if (buffer[0] != '#' && buffer[0] != '\0') {
                    library += Book(buffer);
                    if (++index == 4) { break; }
                }
            }
        } else {
            std::cerr << "ERROR: Can not open file.\n";
            exit(AppErrors::CannotOpenFile);
        }

        /*
         ♪ Hey, I just met you,      ♪
         ♪ And this is crazy,        ♪
         ♪ But here's my number.     ♪    (register the observer)
         ♪ So, if something happens, ♪    (event)
         ♪ Call me, maybe?           ♪    (callback)
         */
        library.setObserver(bookAddedObserver);

        // TODO: add the rest of the books from the file.
        if (file_1.is_open()) {
            char buffer[256];
            while (file_1.good()) {
                file_1.getline(buffer, 255, '\n');
                if (buffer[0] != '#' && buffer[0] != '\0') {
                    library += Book(buffer);
                }
            }
            file_1.close();
        } else {
            std::cerr << "ERROR: Can not open file.\n";
            exit(AppErrors::CannotOpenFile);
        }

    } else {
        std::cerr << "ERROR: Incorrect number of arguments.\n";
        exit(AppErrors::BadArgumentCount);
    }

    double usdToCadRate = 1.3;
    double gbpToCadRate = 1.5;

    // TODO: (from part #1) create a lambda expression that fixes the price of a book accoding to the rules
    //       - the expression should receive a single parameter of type "Book&"
    //       - if the book was published in US, multiply the price with "usdToCadRate"
    //            and save the new price in the book object
    //       - if the book was published in UK between 1990 and 1999 (inclussive),
    //            multiply the price with "gbpToCadRate" and save the new price in the book object
    auto updatePrice = [&](Book &book) {
        if (book.country() == "US")
            book.price() = book.price() * usdToCadRate;
        if (book.country() == "UK")
            if (book.year() >= 1990 && book.year() <= 1999)
                book.price() = book.price() * gbpToCadRate;
    };

    std::cout << "-----------------------------------------\n";
    std::cout << "The library content\n";
    std::cout << "-----------------------------------------\n";
    std::cout << library;
    std::cout << "-----------------------------------------\n\n";

    // TODO (from part #1): iterate over the library and update the price of each book
    //         using the lambda defined above.
    for (size_t index = 0; index < library.size(); ++index)
        updatePrice(library[index]);

    std::cout << "-----------------------------------------\n";
    std::cout << "The library content (updated prices)\n";
    std::cout << "-----------------------------------------\n";
    std::cout << library;
    std::cout << "-----------------------------------------\n\n";

    Collection<Movie> theCollection("Action Movies");

    // Process the file
    Movie movies[5];
    if (argc > 2) {
        // TODO: load 5 movies from the file "argv[2]".
        //       - read one line at a time, and pass it to the Movie constructor
        //       - store each movie read into the array "movies"
        //       - lines that start with "#" are considered comments and should be ignored
        std::ifstream file_2(argv[2]);
        if (file_2.is_open()) {
            char buffer[256];
            size_t index = 0;
            while (file_2.good()) {
                file_2.getline(buffer, 255, '\n');
                if (buffer[0] != '#' && buffer[0] != '\0') {
                    movies[index++] = Movie(buffer);
                    if (index == 5) break;
                }
            }
            file_2.close();
        }
    }

    std::cout << "-----------------------------------------\n";
    std::cout << "Testing addition and callback function\n";
    std::cout << "-----------------------------------------\n";
    if (argc > 2) {
        // Add a few movies to collection; no observer is set
        ((theCollection += movies[0]) += movies[1]) += movies[2];
        theCollection += movies[1];
        // add more movies; now we get a callback from the collection
        theCollection.setObserver(movieAddedObserver);
        theCollection += movies[3];
        theCollection += movies[3];
        theCollection += movies[4];
    } else {
        std::cout << "** No movies in the Collection\n";
    }
    std::cout << "-----------------------------------------\n\n";

    std::cout << "-----------------------------------------\n";
    std::cout << "Testing exceptions and operator[]\n";
    std::cout << "-----------------------------------------\n";


    // TODO: The following loop can generate generate an exception
    //         write code to handle the exception
    //       If an exception occurs print a message in the following format
    //** EXCEPTION: ERROR_MESSAGE<endl>
    //         where ERROR_MESSAGE is extracted from the exception object.
    try {
        for (auto i = 0u; i < 10; ++i)
            std::cout << theCollection[i];
    } catch (std::out_of_range &err) {
        std::cout << "** EXCEPTION: " << err.what() << std::endl;
    }

    std::cout << "-----------------------------------------\n\n";


    std::cout << "-----------------------------------------\n";
    std::cout << "Testing the functor\n";
    std::cout << "-----------------------------------------\n";
    for (auto i = 3; i < argc; ++i) {
        // TODO: The following statement can generate generate an exception
        //         write code to handle the exception
        //       If an exception occurs print a message in the following format
        try {
            const auto filename = argv[i];
            SpellChecker sp(filename);
            for (auto j = 0u; j < library.size(); ++j)
                library[j].fixSpelling(sp);
            sp.showStatistics(std::cout);

            for (auto j = 0u; j < theCollection.size(); ++j)
                theCollection[j].fixSpelling(sp);
            sp.showStatistics(std::cout);
        } catch (std::out_of_range &err) {
            std::cout << "** EXCEPTION: " << err.what() << std::endl;
        } catch (std::string &err) {
            std::cout << "** EXCEPTION: " << err << std::endl;
        }
    }
    if (argc < 3) {
        std::cout << "** Spellchecker is empty\n";
        std::cout << "-----------------------------------------\n";
    }
    std::cout << "\n";

    std::cout << "=========================================\n";
    std::cout << "Wrapping up this workshop\n";
    std::cout << "--------------- Movies ------------------\n";
    std::cout << theCollection;
    std::cout << "--------------- Books -------------------\n";
    std::cout << library;
    std::cout << "-----------------------------------------\n";
    std::cout << "Testing operator[] (the other overload)\n";
    std::cout << "-----------------------------------------\n";
    const Movie *aMovie = theCollection["Terminator 2"];
    if (aMovie == nullptr)
        std::cout << "** Movie Terminator 2 not in collection.\n";
    aMovie = theCollection["Dark Phoenix"];
    if (aMovie != nullptr)
        std::cout << "In this collection:\n" << *aMovie;
    std::cout << "-----------------------------------------\n\n";

    return 0;
}