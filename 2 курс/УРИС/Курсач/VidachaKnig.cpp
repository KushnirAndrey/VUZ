//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "VidachaKnig.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::StringGrid1Click(TObject *Sender)
{
StringGrid1->Cells[0][0] = "Книга";
StringGrid1->Cells[1][0] = "Автор";
StringGrid1->Cells[2][0] = "Дата выдачи";
StringGrid1->Cells[3][0] = "Дата сдачи";
StringGrid1->Cells[4][0] = "Стоимость";
}
//---------------------------------------------------------------------------
