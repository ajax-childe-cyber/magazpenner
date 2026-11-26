#include "Accounts.hpp"

size_t userSize = 3;
size_t currentId = 0;
std::wstring currentStatus;


std::wstring* loginArr = new std::wstring[userSize]{ L"admin", L"half-admin", L"user" };
std::wstring* passArr = new std::wstring[userSize]{ L"admin", L"half-admin", L"user" };
std::wstring* statusArr= new std::wstring[userSize]{ L"SuperAdmin", L"Admin", L"User" };
size_t* userIdArr = new size_t[userSize]{ 0, 1, 2 };
double* awardArr = new double[userSize] {};
double* fineArr = new double[userSize] {};

size_t maxLogin = 12;
size_t minLogin = 5;
size_t maxPass = 18;
size_t minPass = 6;

bool isSetCreate = false;

std::unordered_set<wchar_t> loginSymbols;
std::unordered_set<wchar_t> passSymbols;

void ShowUsers(int mode)
{
	if (mode == 0)
	{
		system("cls");
		std::wcout << L"ID\t" << L"Логин: " << std::left << std::setw(maxLogin)
			<< L"\t\tПароль" << L"\t\tРоль" << L"\t\tСумма продаж"
			<< L"\t\tШтрафы" << L"\n\n";
		for (size_t i = 0; i < userSize; i++)
		{
			std::wcout << userIdArr[i] << L"\t" << std::left << std::setw(maxLogin)
				<< loginArr[i] <<  L"\t" <<  std::setw(maxPass) << passArr[i] << L"\t"
				<< std::setw(10) << statusArr[i] << L"\t\t" << awardArr[i] << std::fixed 
				<< std::setprecision(2) << L"\t\t" << fineArr[i] << L"\n";
		}
		system("Pause");
	}
}

void ChangeAccount()
{
	std::wstring choose;

	if (!isSetCreate)
	{
		CreateSet;
	}

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
			CreateNewAccount();
		}
		else if (choose == L"2")
		{
			ShowUsers();
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
			if (chooseLogin == L"exit" || chooseLogin == L"Exit")
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
		while (true)
		{
			system("cls");
			std::wcout << L"Введите пароль для нового пользователя или \"exit\" для выхода: ";
			Getline(choosePass);
			if (choosePass == L"exit" || choosePass == L"Exit")
			{
				std::wcout << L"Отмена создания учетной записи\n\n";
				Sleep(1500);
				return;
			}
			if (CheakLogin(choosePass))
			{
				break;
			}
			else
			{
				Err();
			}
		
		}
		while (true)
		{
			system("cls");
			std::wcout << L"Введите роль для нового пользователя или \"exit\" для выхода\n";
			std::wcout << L"1 - Сотрудник\n";
			std::wcout << L"1 - Администратор\n";
			std::wcout << L"Ввод: ";
			Getline(chooseStatus);
			if (choose == L"exit" || choose == L"Exit")
			{
				std::wcout << L"Отмена создания учетной записи\n\n";
				Sleep(1500);
				return;
			}
			else if (choose == L"1")
			{
				chooseStatus = L"User";
				break;
			}
			else if (choose == L"2")
			{
				std::wcout << L"Для подтверждения введите пароль суперадмина: ";
				Getline(choose);
				if (choose == passArr[0])
				{
					chooseStatus = L"Admin";
					break;
				}

			}
			else
			{
				Err();
			}
		}
		while (true)
		{
			system("cls");
			std::wcout << L"Логин: " << chooseLogin << L"\n\n"
				<< L"Пароль: " << choosePass << L"\n\n"
				<< L"Роль: " << chooseStatus << L"\n\n"
				<< L"Подтвердить?\n1 - Да\n2 - Отмена\n\nВвод: ";
			Getline(choose);
			if (choose == L"1")
			{
					std::wcout << L"Создание новой учетной записи";
					for (size_t i = 0; i < 5; i++)
					{
						Sleep(1500);
						std::wcout << L" .";
					}
					Sleep(500);

					ArrPushBack(userIdArr, userSize);
					ArrPushBack(loginArr, userSize);
					ArrPushBack(passArr, userSize);
					ArrPushBack(statusArr, userSize);
					ArrPushBack(fineArr, userSize);
					ArrPushBack(awardArr, userSize);
					userSize++;
					userIdArr [userSize - 1] = userSize - 1;
					loginArr [userSize - 1] = chooseLogin;
					passArr [userSize - 1] = choosePass;
					statusArr[userSize - 1] = chooseStatus;
					fineArr [userSize - 1] = 0.0;
					awardArr[userSize - 1] = 0.0;
					std::wcout << L"\n\nУчётная запись создана\n";
					Sleep(1500);
					break;
			}
			else if (choose == L"2")
			{
				std::wcout << L"Отмена создания учетной записи\n\n";
				Sleep(1500);
				return;
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
	for (wchar_t i = L'A'; i < L'Z'; i++)
	{
		loginSymbols.insert(i);
	}
	for (wchar_t i = L'a'; i < L'z'; i++)
	{
		loginSymbols.insert(i);
	}
	for (wchar_t i = L'!'; i < L'~'; i++)
	{
		passSymbols.insert(i);
	}
	isSetCreate = true;
}

bool CheakLogin(const std::wstring& login)
{
	if (login.size() < minLogin || login.size() > maxLogin)
	{
		std::wcout << L"Ошибка длинны логина! Допустимо от " << minLogin << L" до " <<
			maxLogin << L"\n\n";
		Sleep(1500);
		return false;
	}

	if (!IsNotSame(login, loginArr, userSize))
	{
		std::wcout << L"Такой пользователь уже создан\n\n";
		Sleep(1500);
		return false;
	}
	int count = 0;
	for (size_t i = 0; i < login.size(); i++)
	{
		if (loginSymbols.count(login[1]))
		{
			std::wcout << L"Неккоректные символы в логине!\nДопустимые символы: A-Z, a-z, 0-9\n\n";
			Sleep(1500);
			return false;
		}
		if (!std::iswdigit(login[i]) && count <= 4)
		{
			count++;
		}
	}
	if (count >= 4)
	{
		return true;
	}
	else
	{
		std::wcout << L"Слишком мало буквенных символов! Минимум 4 символа\n\n";
		Sleep(1500);
		return false;
	}
}

bool CheakPass(const std::wstring& pass)
{
	if (pass.size() < minPass || pass.size() > maxPass)
	{
		std::wcout << L"Ошибка длинны пароля! Допустимо от " << minPass << L" до " <<
			maxPass << L"\n\n";
		Sleep(1500);
		return false;
	}

	int SymbolCount = 0, letterCount = 0, letterCapCount = 0, numberCount = 0;
	for (size_t i = 0; i < pass.size(); i++)
	{
		if (!loginSymbols.count(pass[1]))
		{
			std::wcout << L"Неккоректные символы в пароле!" 
				<< "\nДопустимые символы : A - Z, a - z, 0 - 9 + спецсимволы\n\n";
			Sleep(1500);
			return false;
		}
		if (std::iswdigit(pass[i]) && numberCount <= 2)
		{
			numberCount++;
		}
		else if (pass[i] >= L'A' && pass[i] <= L'Z' && letterCapCount <= 1)
		{
			letterCapCount++;
		}
		else if (pass[i] >= L'a' && pass[i] <= L'z' && letterCount <= 3)
		{
			letterCount++;
		}
		else
		{
			SymbolCount++;
		}
	}



	if (SymbolCount > 0 && letterCount > 2 && letterCapCount > 0 && numberCount > 0)
	{
		return true;
	}
	else
	{
		std::wcout << L"Неккоректный пароль! Минимальные требования: \nСпец символы - 1 и более\n"
			<< L"Нижний регистр букв - 3 и более"
			<< "\nВерхний регистр букв - 1 и более\nЦифры - 1 и более\n";
		Sleep(1500);
		return false;
	}
}
