//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "ReaderReports.h"
#include <stdio.h>
//#include "mysql.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm4::StringGrid3Click(TObject *Sender)
{  /*
StringGrid3->Cells[0][0] = "ФИО";
StringGrid3->Cells[1][0] = "Возраст";
StringGrid3->Cells[2][0] = "Пол";
StringGrid3->Cells[3][0] = "Телефон";
StringGrid3->Cells[4][0] = "Адрес";
StringGrid3->Cells[5][0] = "e-mail";
StringGrid3->Cells[0][1] = "Кушнир А.С.";
StringGrid3->Cells[1][1] = "21";
StringGrid3->Cells[2][1] = "М";
StringGrid3->Cells[3][1] = "89778722795";
StringGrid3->Cells[4][1] = "ул. Полины Осипенко";
StringGrid3->Cells[5][1] = "akushnir@croc.ru";
StringGrid3->Cells[0][2] = "Бажанов И.Д.";
StringGrid3->Cells[1][2] = "22";
StringGrid3->Cells[2][2] = "М";
StringGrid3->Cells[3][2] = "89652117745";
StringGrid3->Cells[4][2] = "ул. Ленина";
StringGrid3->Cells[5][2] = "baj@yandex.ru";
StringGrid3->Cells[0][3] = "Подарь А.О.";
StringGrid3->Cells[1][3] = "34";
StringGrid3->Cells[2][3] = "М";
StringGrid3->Cells[3][3] = "89652475645";
StringGrid3->Cells[4][3] = "ул. Тверская";
StringGrid3->Cells[5][3] = "podr@mail.ru";       */

	MYSQL *conn;
	MYSQL_RES *res;
	MYSQL_ROW row;
	// Получаем дескриптор соединения
	conn = mysql_init(NULL);
	if(conn == NULL)
	{
		// Если дескриптор не получен – выводим сообщение об ошибке
		if (MessageDlg("Error connection!", mtError, TMsgDlgButtons() << mbYes << mbNo,0) == mrYes)
			Close();
		}
	}
	// Подключаемся к серверу
	if(!mysql_real_connect(conn, "localhost", "andrey", "qwerty1234", "Library", NULL, NULL, 0))
	{
	// Если нет возможности установить соединение с сервером
	// базы данных выводим сообщение об ошибке
		if (MessageDlg("Error connection!", mtError, TMsgDlgButtons() << mbYes << mbNo,0) == mrYes)
			Close();
	}
	//Выставляем нужную кодировку символов
	mysql_set_character_set(conn, "utf8");
	cout<<"connectioncharacterset: "<<mysql_character_set_name(conn) <<endl;
	mysql_query(conn,"SELECT * FROM Readers"); // Делаем запрос к таблице по имени
	if (res = mysql_store_result(conn)){
		while(row = mysql_fetch_row(res)) {
			for (int i=0; i < mysql_num_fields(res); i++){  // Перебираем строки запроса 
				for (j = 0; i < Stringgrid3.ColCount(); i++) {
					StringGrid3->Cells[i][j] = row[i][j];  // Заполняем таблицу значениями		
				}
			}
		}
	}
	else{
		if (MessageDlg("Error connection!", mtError, TMsgDlgButtons() << mbYes << mbNo,0) == mrYes)
			Close();
	}
	// Закрываем соединение с сервером базы данных
	mysql_close(conn);
}
//---------------------------------------------------------------------------



void __fastcall TForm4::FormActivate(TObject *Sender)
{
/*
StringGrid3->Cells[0][0] = "ФИО";
StringGrid3->Cells[1][0] = "Возраст";
StringGrid3->Cells[2][0] = "Пол";
StringGrid3->Cells[3][0] = "Телефон";
StringGrid3->Cells[4][0] = "Адрес";
StringGrid3->Cells[5][0] = "e-mail";
StringGrid3->Cells[0][1] = "Кушнир А.С.";
StringGrid3->Cells[1][1] = "21";
StringGrid3->Cells[2][1] = "М";
StringGrid3->Cells[3][1] = "89778722795";
StringGrid3->Cells[4][1] = "ул. Полины Осипенко";
StringGrid3->Cells[5][1] = "akushnir@croc.ru";
StringGrid3->Cells[0][2] = "Бажанов И.Д.";
StringGrid3->Cells[1][2] = "22";
StringGrid3->Cells[2][2] = "М";
StringGrid3->Cells[3][2] = "89652117745";
StringGrid3->Cells[4][2] = "ул. Ленина";
StringGrid3->Cells[5][2] = "baj@yandex.ru";
StringGrid3->Cells[0][3] = "Подарь А.О.";
StringGrid3->Cells[1][3] = "34";
StringGrid3->Cells[2][3] = "М";
StringGrid3->Cells[3][3] = "89652475645";
StringGrid3->Cells[4][3] = "ул. Тверская";
StringGrid3->Cells[5][3] = "podr@mail.ru";       */

	MYSQL *conn;
	MYSQL_RES *res;
	MYSQL_ROW row;
	// Получаем дескриптор соединения
	conn = mysql_init(NULL);
	if(conn == NULL)
	{
		// Если дескриптор не получен – выводим сообщение об ошибке
		if (MessageDlg("Error connection!", mtError, TMsgDlgButtons() << mbYes << mbNo,0) == mrYes)
			Close();
		}
	}
	// Подключаемся к серверу
	if(!mysql_real_connect(conn, "localhost", "andrey", "qwerty1234", "Library", NULL, NULL, 0))
	{
	// Если нет возможности установить соединение с сервером
	// базы данных выводим сообщение об ошибке
		if (MessageDlg("Error connection!", mtError, TMsgDlgButtons() << mbYes << mbNo,0) == mrYes)
			Close();
	}
	//Выставляем нужную кодировку символов
	mysql_set_character_set(conn, "utf8");
	cout<<"connectioncharacterset: "<<mysql_character_set_name(conn) <<endl;
	mysql_query(conn,"SELECT * FROM Readers"); // Делаем запрос к таблице по имени
	if (res = mysql_store_result(conn)){
		while(row = mysql_fetch_row(res)) {
			for (int i=0; i < mysql_num_fields(res); i++){  // Перебираем строки запроса 
				for (j = 0; i < Stringgrid3.ColCount(); i++) {
					StringGrid3->Cells[i][j] = row[i][j];  // Заполняем таблицу значениями		
				}
			}
		}
	}
	else{
		if (MessageDlg("Error connection!", mtError, TMsgDlgButtons() << mbYes << mbNo,0) == mrYes)
			Close();
	}
	// Закрываем соединение с сервером базы данных
	mysql_close(conn);
	
}
//---------------------------------------------------------------------------

