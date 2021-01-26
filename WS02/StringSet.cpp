#include "StringSet.h"

namespace sdds {
    StringSet::StringSet() {
        setDefaultState();
    }

    StringSet::StringSet(const char *fileName) {
        setDefaultState();
        if (fileName != nullptr) {
            this->fileName = new char[strlen(fileName) + 1];
            strcpy(this->fileName, fileName);
            readFromFile();
        }
    }

    StringSet::StringSet(const StringSet &source) {
        setDefaultState();
        *this = source;
    }

    StringSet &StringSet::operator=(const StringSet &source) {
        if (this != &source) {
            if (source.fileName != nullptr) {
                releaseMemory();
                fileName = new char[strlen(source.fileName) + 1];
                strcpy(fileName, source.fileName);
                readFromFile();
            }
        }
        return *this;
    }

    StringSet::StringSet(StringSet &&source) {
        setDefaultState();
        *this = std::move(source);
    }

    StringSet &StringSet::operator=(StringSet &&source) {
        if (this != &source) {
            releaseMemory();
            fileName = source.fileName; source.fileName = nullptr;
            start = source.start; source.start = nullptr;
            stop = source.stop; source.stop = nullptr;
            wordNo = source.wordNo; source.wordNo = 0;
        }
        return *this;
    }

    StringSet::~StringSet() {
        releaseMemory();
    }

    size_t StringSet::size() const {
        return wordNo;
    }

    std::string StringSet::operator[](size_t index) const {
        if (index >= 0 && index <= wordNo) {
            Word *currentWord = start;
            while (currentWord != nullptr) {
                if (currentWord->index == index) return currentWord->value;
                else currentWord = currentWord->nextWord;
            }
        }
        return "";
    }

    void StringSet::push(const std::string &value) {
        Word *word = new Word();
        word->index = wordNo++;
        word->value = value;
        word->nextWord = nullptr;
        if (start == nullptr) {
            start = word;
            stop = start;
        } else {
            stop->nextWord = word;
            stop = word;
        }
    }

    void StringSet::readFromFile() {
        if (fileName != nullptr) {
            std::ifstream file(this->fileName);
            if (file.is_open()) {
                char word[256];
                while (file.good()) {
                    file.getline(word, 255, ' ');
                    push(word);
                }
                file.close();
            } else {
                delete[] fileName;
                fileName = nullptr;
            }
        }
    }

    void StringSet::releaseMemory() {
        if (fileName != nullptr) delete[] fileName;
        fileName = nullptr;
        Word *current = start;
        while (current != nullptr) {
            Word *next = current->nextWord;
            delete current;
            current = next;
        }
    }

    void StringSet::setDefaultState() {
        fileName = nullptr;
        start = nullptr;
        stop = nullptr;
        wordNo = 0;
    }
}