#include "utils.h"

char *vovanex::get_word(char *string, char *word) {
    //Пропуск пустых символов
    while (*string <= ' ' && *string > '\0')
        ++string;

    while (*string > ' ' && *string)
        *(word++) = *(string++);

    *word = '\0';

    return string;
}

char *vovanex::get_word(char *string, std::string &word) {
    //Пропуск пустых символов
    while (*string <= ' ' && *string > '\0')
        ++string;

    while (*string > ' ' && *string)
        word += *(string++);

    return string;

}
