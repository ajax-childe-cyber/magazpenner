#include "Autorization.hpp"



void Start()
{
	while (true)
	{
		if (Login()) 
		{
			if (currentStatus == L"SuperAdmin")
			{
				CreateStroge();
				SuperAdminMenu();
			}
			else if (currentStatus == L"Admin")
			{
				//TO_DO
			}
			else if (currentStatus == L"User")
			{
				//TO_DO
			}
			else
			{
				std::wcerr << L"_CURRENT_STATUS_LOGIN_ERROR";
			}
		}
		else
		{

		}
	}
}

bool Login()
{
	std::wstring login, pass;
	while (true)
	{
		system("cls");
		std::wcout << L"\n\n\n\n\t\t\tДобро пожаловать!"
			<< L"\n\n\n\n\t\t\t   WigMake \n\n\n\t\t"
			<< L"Введите логин или \"exit\" для выхода: ";
		Getline(login);
		if (login == L"exit" || login == L"Exit")
		{
			return false;
		}
		else
		{
			std::wcout << L"Введите пароль: ";
			Getline(pass);
			for (size_t i = 0; i < userSize; i++)
			{
				if (login == loginArr[i] && pass == passArr[i])
				{
					std::wcout << L"Добро пожаловать " << loginArr[i] << L"\n"
						<< L"Ваш уровень доступа: " << statusArr[i] << L"\n";
					currentId = userIdArr[i];
					currentStatus = statusArr[i];
					Sleep(2000);
					return true;
				}
			}
			std::wcout << L"Неверный логин или пароль, введите заново\n";
			Sleep(2000);
		}
		
	}
}

void SuperAdminMenu()
{
	std::wstring choose;
	while (true)
	{
		system("cls");
		std::wcout << L"\n\n\t\t\t Меню супер админа\n\n";
		std::wcout << L"1 - Начать продажу\n";
		std::wcout << L"2 - Показать склад\n";
		std::wcout << L"3 - Пополнить товары\n";
		std::wcout << L"4 - Списать товары\n";
		std::wcout << L"5 - Изменить цены\n";
		std::wcout << L"6 - Редактировать склад\n";
		std::wcout << L"7 - Редактирование сотрудников\n";
		std::wcout << L"8 - Отчёт о прибыли\n";
		std::wcout << L"9 - Выход\n";
		std::wcout << L"Ввод: ";
		Getline(choose);

		if (choose == L"1")
		{

		}
		else if (choose == L"2")
		{
			ShopStorage();
		}
		else if (choose == L"3" && sizeSt > 0)
		{
			AddProduct();
		}
		else if (choose == L"4" && sizeSt > 0)
		{
			RemoveProduct();
		}
		else if (choose == L"5" && sizeSt > 0)
		{
			ChangePrice();
		}
		else if (choose == L"6")
		{
			ChangeStorage();
		}
		else if (choose == L"7")
		{
			ChangeAccount();
		}
		else if (choose == L"8")
		{
			ChangeStorageLimits();
		}
		else if (choose == L"9")
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
