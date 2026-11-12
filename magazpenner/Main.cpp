#include <io.h>
#include <fcntl.h>
#include "Autorization.hpp"

int main()
{

	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);

	Start();






	return 0;
}


/*
	авторизация: ввод логина и пароля
	аккаунт: д пользователей + функции. Суперадмин, админ, пользователь
	Продажи: покупка, оплата, формирование чека
	Склад: бд товаров, функции
	Служебные: всяка для работы программы

*/