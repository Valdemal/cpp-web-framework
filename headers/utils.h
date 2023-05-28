#ifndef CN8_UTILS_H
#define CN8_UTILS_H

#include <string>

namespace vovanex {

    // Записывает в строку word первое слово строки string. Возвращает указатель на
    // первый символ после считанного слова
    char *get_word(char *string, char *word);

    char *get_word(char *string, std::string &word);
}

#endif //CN8_UTILS_H
