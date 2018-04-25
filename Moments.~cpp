//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <algorith.h>
#include <algorithm>
#include <time.h>
#include <string>

#pragma hdrstop

#include "Moments.h"
#include "Moments1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma link "PowerPoint_2K_SRVR"
#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int i,j;
    bool exsize(0);
    if(OpenPictureDialog1->Execute())
    {
          Image1->Picture->LoadFromFile(OpenPictureDialog1->FileName);

          for(i=0; i<Image1->Picture->Width; i++)
            for(j=0; j<Image1->Picture->Height; j++)

          InputImage.F[i][j]  =  Image1->Canvas->Pixels[i][j] >> CSpinEdit2->Text.ToInt();
          Edit2->Text = InputImage.ImWidth  = Image1->Picture->Width;
          Edit3->Text = InputImage.ImHeight = Image1->Picture->Height;
          N                   = InputImage.ImWidth;
          M                   = InputImage.ImHeight;
          Form1->Button2->Enabled = true;
          Bevel1->Width=InputImage.ImWidth+3;
          Bevel1->Height=InputImage.ImHeight+2;
          Bevel1->Style=bsRaised;
    }
    else
       return;

}
//---------------------------------------------------------------------------

void MainProcess(void)
{
    //if(!Form1->Button5->Click())
    {
    int p,q,x,y,NumMoments;
    double s1,s2,tpx,tqy,fxy,TMpq;

    NumMoments =0;

    Order   = StrToInt(Form1->CSpinEdit1->Text);

    ProgressBarConfig();

    for(p=0; p<=Order; p++)
    {
     for(q=0; q<=Order; q++)
     {
      s2 = 0;
      for(x=0;x<N;x++)
      {
       tpx = Tchebichef_bar_poly(p,x,N);
       s1  = 0;
       for(y=0;y<M;y++)
       {
        tqy  = Tchebichef_bar_poly(q,y,M);
        fxy  = (double)(InputImage.F[x][y]);
        s1   = s1+tqy*fxy;
       }
       s2 = s2 + tpx*s1;
      }
      NumMoments++;
      TMpq = (1/(p_norm(p,N)*p_norm(q,M)))*s2;
      Form1->ListBox1->Items->Add("T("+IntToStr(p)+","+IntToStr(q)+")"+"-->"+FloatToStr(TMpq));
      Form1->ProgressBar1->StepIt();
     }
    }
    Form1->Edit1->Text = IntToStr(NumMoments);
    }
}


void ProgressBarConfig(void)
{
    int p,q,count;

    Form1->ProgressBar1->Position = 0;

    count = 0;
    for(p=0; p<=Order; p++)
      for(q=0; q<=Order; q++)
         count++;

    Form1->ProgressBar1->Max = count;
}


double Factorial(int end)
{
    long double result;
    int i;

    if(end==0)
      return(1.0);

    result=1;
    for(i=1; i<=end; i++)
      result=result*i;

    return(result);
}

double Bhta(int n,int N)
{
 double B;

 B = pow(N,n);
 return(B);
}

double p_norm(int n,int N)
{
 double pnorm;

 pnorm = Factorial(2*n)*Factorial(N+n)/(Factorial(2*n+1)*Factorial(N-n-1));
 pnorm = pnorm/(pow(Bhta(n,N),2));

 return(pnorm);
}

double Tchebichef_bar_poly(int order,int xy,int dim)
{
 double *t = new double[Form1->CSpinEdit1->Text.ToInt()+1],A,B;
 int n,ni;

 switch(order)
 {
  case 0:
         t[0] = 1;
         break;
  case 1:
         t[1] = (double)(2*xy+1-dim)/(double)dim;
         break;
  default:
         t[0] = 1;
         t[1] = (double)(2*xy+1-dim)/(double)dim;
         for(n=1;n<order;n++)
         {
            ni = n+1;
            A  = (2*ni-1)*t[1];
            B  = (ni-1)*(double)(1-pow( (ni-1)/(double)dim,2));
            t[n+1] = (A*t[n]-B*t[n-1])/(ni);
         }
         break;
 }
 int pos = order;
 delete []t;
 return(t[pos]);
}



void __fastcall TForm1::Button2Click(TObject *Sender)
{
    Form1->Button5->Enabled=False;
    Form1->ListBox1->Clear();
    MainProcess();
    Button7->Enabled=True;
    Button3->Enabled=True;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
    if(SaveDialog1->Execute())
    {
    ListBox1->Items->Insert(0,"DIM-->W"+Edit2->Text+ "-H"+Edit3->Text);
    ListBox1->Items->SaveToFile(SaveDialog1->FileName);
    }
    ListBox1->Items->Delete(0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
      int size = ListBox1->Items->Count;
      String temp;
      int i=0;
      double *Tpq = new double[size];
      int nStart,nEnd;
      for(i;i<size;i++)
         {
         String GetListItem = ListBox1->Items->Strings[i];
         nStart =  GetListItem.AnsiPos('>');
         nEnd   =  GetListItem.Length();
         temp = GetListItem.SubString(nStart+1,nEnd);
         ShowMessage(temp);
         Tpq[i] =  temp.ToDouble();
         }
      Order = sqrt(size);
      ProgressBarConfig();
      int cnt,x,y,M,N,p,q;
      double tpx,tqy,s1=0,s2;

      //Image OutputImage;

      M = Form1->Edit2->Text.ToInt();
      N = Form1->Edit3->Text.ToInt();
      TColor cl;
      Form1->ProgressBar2->Max = pow(Order,2);
      for(x=0;x<N;x++)
      {
      for(y=0;y<M;y++)
      {
      s2=0;
      cnt=0;
      for(p=0;p<Order;p++)
         {
         tpx = Tchebichef_bar_poly(p,x,N);
         s1 = 0;
            for(q=0;q<Order;q++)
            {
            tqy = Tchebichef_bar_poly(q,y,M);
            s1 = s1 + tqy * Tpq[cnt];
            cnt++;
            }//f4
            s2 = s2 + (tpx * s1);
      }//f3
      cl = s2 ;
      long  L = ColorToRGB(cl);
      //OutputImage.F[x][y] = cl;
      Form1->Image2->Canvas->Pixels[x][y] = L << CSpinEdit3->Text.ToInt();
      Form1->Image3->Canvas->Pixels[x][y] = L << CSpinEdit3->Text.ToInt()+8;
      Form1->Image4->Canvas->Pixels[x][y] = L << CSpinEdit3->Text.ToInt()+16;
      Form1->Image5->Canvas->Pixels[x][y] = L << CSpinEdit3->Text.ToInt()+24;
      }//f2
      // <M,<N loop missing dude
      Form1->ProgressBar2->StepIt();
      }//f1
      Image2->Width=N;
      Image2->Height=M;
      Bevel3->Width=N;
      Bevel3->Height=M;
      Bevel3->Style=bsRaised;
      if(ProgressBar2->Position<ProgressBar2->Max)
      {
      ShowMessage("ProgressBar does not work!");
      }

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button5Click(TObject *Sender)
{
    int dsx,dsy,dex,enl;
    if(OpenDialog1->Execute())
    {
    ListBox1->Items->LoadFromFile(OpenDialog1->FileName );
    if(ListBox1->Items->Strings[0].SubString(0,3)=="DIM")
    {
    dsx = ListBox1->Items->Strings[0].AnsiPos('W');
    dex = ListBox1->Items->Strings[0].AnsiPos('-');
    dsy = ListBox1->Items->Strings[0].AnsiPos('H');
    enl = ListBox1->Items->Strings[0].Length();
    Edit2->Text = ListBox1->Items->Strings[0].SubString(dsx+1,dex-1);
    Edit3->Text = ListBox1->Items->Strings[0].SubString(dsy+1,enl-1);
    ListBox1->Items->Delete(0);
    }
    Edit1->Text = ListBox1->Items->Count;
    }
    Button7->Enabled=True;
    Button3->Enabled=True;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
CSpinEdit1->Text="";
Form1->Edit1->Text= "";
//Form1->Edit2->Text= "";
//Form1->Edit3->Text= "";
Form1->ProgressBar2->Position=0;
Button5->Enabled=1;
Form1->ListBox1->Clear();
}
//---------------------------------------------------------------------------










void __fastcall TForm1::FormCreate(TObject *Sender)
{
Button7->Enabled=False;
Button3->Enabled=False;
}
//---------------------------------------------------------------------------






