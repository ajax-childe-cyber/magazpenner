#include "Accounts.hpp"

size_t userSize = 3;
size_t currentId = 0;
std::wstring currentStatus;


std::wstring* loginArr = new std::wstring[userSize]{ L"admin", L"half-admin", L"user" };
std::wstring* passArr = new std::wstring[userSize]{ L"admin", L"half-admin", L"user" };
std::wstring* statusArr= new std::wstring[userSize]{ L"SuperAdmin", L"Admin", L"User" };
size_t* userIdArr = new size_t[userSize]{ 0, 1, 2 };

size_t maxLogin = 12;
size_t minLogin = 5;
size_t maxPass = 18;
size_t minPass = 6;

std::unordered_set<wchar_t> loginSymbols;
std::unordered_set<wchar_t> passSymbols;

void ChangeAccount()
{
	std::wstring choose;
	while (true)
	{
		system("cls");
		std::wcout << L"\n\n\t\t\t Редактирование учетных записей\n\n";
		std::wcout << L"1 - Создать новый аккаунт\n";
		std::wcout << L"2 - Показать всех сотрудников\n";
		std::wcout << L"3 - Изменить пароль\n";
		std::wcout << L"4 - Изменить уровни доступа\n";
		std::wcout << L"6 - Редактировать премии и штрафы сотрудников\n";
		std::wcout << L"6 - Удалить аккаунт\n";
		std::wcout << L"7 - Выход\n";
		std::wcout << L"Ввод: ";
		Getline(choose);

		if (choose == L"1")
		{
			
		}
		else if (choose == L"2")
		{
			
		}
		else if (choose == L"3")
		{
			
		}
		else if (choose == L"4")
		{
			
		}
		else if (choose == L"5")
		{

		}
		else if (choose == L"6")
		{
			
		}
		else if (choose == L"7")
		{
			std::wcout << L"\nВыход из редактора склада\n\n";
			Sleep(1500);
			break;
		}
		else
		{
			Err();
		}

	}
}

void CreateNewAccount()
{
	std::wstring chooseLogin, choosePass, chooseStatus, choose;
	while (true)
	{
		while (true)
		{
			system("cls");
			std::wcout << L"Введите логин для нового пользователя или \"exit\" для выхода: ";
			Getline(chooseLogin);
			if (chooseLogin = L"exit" || chooseLogin = L"Exit")
			{
				std::wcout << L"Отмена создания учетной записи\n\n";
				Sleep(1500);
				return;
			}
			if (CheakLogin(chooseLogin))
			{
				break;
			}
			else
			{
				Err();
			}
		}
	}
}

void CreateSet()
{
	for (wchar_t i = L'0'; i < L'9'; i++)
	{
		loginSymbols.insert(i);
	}
}

bool CheakLogin(const std::wstring& login)
{
	return false;
}
