#ifndef _SERVISE_HPP
#define	_SERVISE_HPP
#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>

void Getline(std::wstring& str);
bool IsNumber(const std::wstring& str);
bool IsNotSame(const std::wstring& chooseName, std::wstring* nameArr,size_t commonSize);

__forceinline void Err()
{
	std::wcout << L"Некорекктный ввод\n";
	Sleep(1500);
}


template <class ArrType>
void FillArray(ArrType* staticArr, ArrType* dinamicArr, size_t commonSize)
{
	for (size_t i = 0; i < commonSize; i++)
	{
		dinamicArr[i] = staticArr[i];
	}
}
template <class ArrType>
void ArrPushBack(ArrType*& arr, size_t size)
{
	size++;
	ArrType* temp = new ArrType[size];
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}
	std::swap(arr, temp);
	delete[]temp;
}





#endif //!_SERVISE_HPP
