#ifndef _STROGE_HPP
#define	_STROGE_HPP

#include "Servise.hpp"



extern size_t sizeSt;
extern size_t* idArr;
extern std::wstring* nameArr;
extern size_t* countArr;
extern double* priceArr;

extern bool isCtorageCreated;

extern size_t maxStorageSize;
extern size_t currentStorageSize;

extern double maxPrice;

void CreateStroge(int mode = 0);
void ShopStorage(int mode = 0);
void AddProduct();
void RemoveProduct();
void ChangePrice();

void ChangeStorage();
void AddNewProduct();

#endif //!_STROGE_HPP