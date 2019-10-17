//---------------------------------------------------------------------------

#ifndef ReaderReportsH
#define ReaderReportsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <stdio.h>
#include "sqlite3.h"
#include <iostream>
#include <string>
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *StringGrid3;
	TLabel *Label1;
	TButton *Button2;
	TButton *Button3;
	void __fastcall StringGrid3Click(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
