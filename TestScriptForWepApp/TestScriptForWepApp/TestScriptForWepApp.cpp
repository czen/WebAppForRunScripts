// TestScriptForWepApp.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <ctime> 
#include <windows.h>

using namespace std;

#define SIZE 26

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//setlocale(LC_ALL, "Russian");

	time_t ltime;
	wchar_t buf[SIZE];
	errno_t err;
	
	if (argc > 1)// если передаем аргументы, то argc будет больше 1(в зависимости от кол-ва аргументов)
	{
		//получение времени
		time(&ltime);// возвращает число секунд, истекших с полуночи (00:00:00), 1 января 1970, время в формате UTC.
		err = _wctime_s(buf, SIZE, &ltime);
		if (err != 0) {
			printf("Invalid Arguments for _wctime_s. Error Code: %d\n", err);
		}
		srand(time(0));//запуск таймера
		int length = 0;
		unsigned int end_time = 0;
		cout << "Code: system_1 " << "Msg: The program is running" << endl;// успешный запуск
		Sleep(10);//для разрыва строк и более упрощенного их ивзлечения в node.js для передачи в интерфейс
		cout << "Code: program_start_time " << "Msg: ";
		//wprintf_s(L"%s", buf); 
		//Sleep(10);
		cout << " start_time " << ltime << endl; 
		Sleep(10);
		cout << "Enter parametrs: " << argv[1] << endl; 
		Sleep(10);
		length = atoi(argv[1]);

		if (length > 0) {
			for (int i = 1; i < length + 1; i++) {
				cout << i * i << "\n";
			}
		}

		end_time = clock() - 3 * 10; //clock() возвращает значение времени в миллисекундах. Вычетание времени остановки програмы с помощью (Sleep(10))
		cout << "Code: system_2 " << "Msg: The program is completed successfully." << endl; // успешное завершение
		Sleep(10);
		cout << "Code: program_elapsed_time " << "Msg: " << end_time/1000.0 << endl; //значение в сек
		Sleep(10);
	}
	else
	{
		cout << "Code: system_0 " << "Msg: Not arguments" << endl;// ошибка запуска
		Sleep(10);
	}

	// для паузы
	//system("pause");

	return 0;
}