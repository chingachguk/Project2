#include <stdio.h>
#include <string.h>
#include <ctype.h> // ������������ ���� ��� ������� toupper()

int main()
{
    char str[81]; // ��������� ������ ������ �� 80 ��������
    printf("Vvedite stroku: ");
    fgets(str, 81, stdin); // ������ ������ � �������

    int len = strlen(str); // ���������� ����� ������

    // �������� ��� ��������� ������� 'a' � 'b' �� ���������
    for (int i = 0; i < len; i++)
    {
        if (str[i] == 'a' || str[i] == 'b')
        {
            str[i] = toupper(str[i]); // ������� toupper ����������� ������ � ��������� �������
        }
    }

    printf("Result: %s\n", str); // ������� ���������� ������ �� �������

    return 0;
}
