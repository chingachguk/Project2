#include <stdio.h>
#include <string.h>
#include <ctype.h> // заголовочный файл дл€ функции toupper()

int main()
{
    char str[81]; // объ€вл€ем строку длиной до 80 символов
    printf("Vvedite stroku: ");
    fgets(str, 81, stdin); // вводим строку с консоли

    int len = strlen(str); // определ€ем длину строки

    // замен€ем все маленькие символы 'a' и 'b' на заглавные
    for (int i = 0; i < len; i++)
    {
        if (str[i] == 'a' || str[i] == 'b')
        {
            str[i] = toupper(str[i]); // функци€ toupper преобразует символ в заглавный регистр
        }
    }

    printf("Result: %s\n", str); // выводим полученную строку на консоль

    return 0;
}
