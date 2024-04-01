#include <iostream>
#include <string>
#include <windows.h>

using namespace std;
int main()
{
    while (true)
    {
        cout << "[1] Computer Name" << endl;
        cout << "[2] Hardware" << endl;
        cout << "[3] Advanced" << endl;
        cout << "[4] System Protection" << endl;
        cout << "[5] Remote" << endl << endl;

        cout << "Enter the page number: ";
        wstring page_num;
        wcin >> page_num;
        if (stoi(page_num) <= 5 && stoi(page_num) >= 1)
        {
            wstring rundll32_params = L"shell32.dll,Control_RunDLL sysdm.cpl,," + page_num;
            HINSTANCE result = ShellExecuteW(nullptr, L"open", L"rundll32.exe", rundll32_params.c_str(), nullptr, SW_SHOW);
            if ((int)result <= 32) {
                cerr << "\nError executing rundll32.exe.\nError code: " << (int)result << endl << endl;

                cout << "Press the enter/return key to exit..." << endl;
                getchar();
                return 1;
            }

            system("cls");
        }
        else {
            system("cls");
            wcout << "'" << page_num << L"' is undefined: Please provide the correct input (one through five)" << endl << endl;
        }
    }
}
