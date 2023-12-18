#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;
int main()
{

    setlocale(LC_ALL, "Russian");
    const char* archiveName = "archive.rar";
    HANDLE hFile = CreateFile(archiveName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE)
    {
        cerr << "Ошибка открытия архива. Пожалуйста, попробуйте снова" << endl;
        return 1;
    }

    DWORD archiveSize = GetFileSize(hFile, NULL);
    if (archiveSize == INVALID_FILE_SIZE)
    {
        cerr << "Ошибка подсчёта размера архива" << endl;
        CloseHandle(hFile);
        return 1;
    }

    cout << "Размер архива: " << archiveSize << " байт" << endl;

    vector<char> buffer(archiveSize);

    DWORD bytesRead;
    if (!ReadFile(hFile, &buffer[0], archiveSize, &bytesRead, NULL))
    {
        cerr << "Ошибка чтения архива" << endl;
        CloseHandle(hFile);
        return 1;
    }

    CloseHandle(hFile);


    return 0;
}
