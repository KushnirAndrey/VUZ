//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StartWindow.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
	Form2->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N35Click(TObject *Sender)
{
Form3->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)
{
Form4->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button10Click(TObject *Sender)
{
if (MessageDlg("Закрыть приложение?", mtError, TMsgDlgButtons() << mbYes << mbNo,0) == mrYes)
	Close();
}
//---------------------------------------------------------------------------
