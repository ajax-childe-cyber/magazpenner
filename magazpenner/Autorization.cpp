#include "Autorization.hpp"
#include "Accounts.hpp"

void Start()
{
	while (true)
	{
		if (Login()) 
		{
			if (currentStatus == L"SuperAdmin")
			{
				//TO_DO
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
					return true;
				}
			}
			std::wcout << L"Неверный логин или пароль, введите заново\n";
			Sleep(2000);
		}
		
	}
}
