//---------------------------------------------------------------------------

#ifndef MomentsH
#define MomentsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "CSPIN.h"
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
#include <CheckLst.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include <Mask.hpp>
#include "PowerPoint_2K_SRVR.h"
#include <OleServer.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TBevel *Bevel1;
        TImage *Image1;
        TCSpinEdit *CSpinEdit1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TOpenPictureDialog *OpenPictureDialog1;
        TButton *Button1;
        TEdit *Edit1;
        TLabel *Label4;
        TLabel *Label5;
        TProgressBar *ProgressBar1;
        TButton *Button2;
        TListBox *ListBox1;
        TSaveDialog *SaveDialog1;
        TButton *Button3;
        TButton *Button4;
        TButton *Button5;
        TEdit *Edit2;
        TEdit *Edit3;
        TLabel *Label6;
        TLabel *Label7;
        TBevel *Bevel2;
        TBevel *Bevel3;
        TImage *Image2;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TProgressBar *ProgressBar2;
        TButton *Button7;
        TOpenDialog *OpenDialog1;
        TButton *Button8;
        TLabel *Label12;
        TLabel *Label13;
        TCSpinEdit *CSpinEdit2;
        TCSpinEdit *CSpinEdit3;
        TImage *Image3;
        TImage *Image4;
        TImage *Image5;
        TImage *Image6;
        TPopupMenu *PopupMenu1;
        TMenuItem *File1;
        TMenuItem *Exit1;
        TMenuItem *N1;
        TMenuItem *PrintSetup1;
        TMenuItem *Print1;
        TMenuItem *N2;
        TMenuItem *SaveAs1;
        TMenuItem *Save1;
        TMenuItem *Open1;
        TMenuItem *New1;
        TMenuItem *Help1;
        TMenuItem *About1;
        TMenuItem *HowtoUseHelp1;
        TMenuItem *Tutorial1;
        TMenuItem *SearchforHelpOn1;
        TMenuItem *Keyboard1;
        TMenuItem *Procedures1;
        TMenuItem *Commands1;
        TMenuItem *Index1;
        TMenuItem *Contents1;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button7Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button8Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
