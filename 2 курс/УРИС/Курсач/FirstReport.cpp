//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FirstReport.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::StringGrid2Click(TObject *Sender)
{
StringGrid2->Cells[0][0] = "Книга";
StringGrid2->Cells[1][0] = "Автор";
StringGrid2->Cells[2][0] = "Издание";
StringGrid2->Cells[3][0] = "Год издания";
}
//---------------------------------------------------------------------------
