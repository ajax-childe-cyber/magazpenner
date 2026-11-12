#include "Stroge.hpp"

size_t sixeSt = 0;
size_t* idArr = nullptr;
std::wstring* nameArr = nullptr;
size_t* countArr = nullptr;
double* priceArr = nullptr;

void CreateStroge(int mode)
{
	const size_t staticSize = 10;
	size_t idArrStatic[staticSize]{ 1,2,3,4,5,6,7,8,9,10 };
	std::wstring nameArrStatic[staticSize]
	{
		L"Длинный красный парик",L"Короткий блондинистый парик",L"Парик средней длинны зеленого цвета",
		L"Каркасный парик на Соника", L"Полу-каркасный парик на Мадоку",L"Парик с краевой на Акиру",
		L"Парик с подсветкой на Мавуику", L"Черно-белый парик",L"Парик из пряжи на Рагату",
		L"Сверкающая лысина"
	};
	size_t countArrStatic[staticSize]{ 10, 25, 7, 1, 2, 3, 1, 5, 1, 50 };
	double priceArrStatic[staticSize]{ 1000, 700, 1500, 10000, 7500, 2000,
		25000, 1200, 3000, 120};
}
