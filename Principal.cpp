//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Principal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmPrincipal *frmPrincipal;
//---------------------------------------------------------------------------
__fastcall TfrmPrincipal::TfrmPrincipal(TComponent* Owner)
	: TForm(Owner)
{
	txtPuerto->Text = 516;
	txtHost->Text = "192.168.15.130";
    NumNivel = 0;
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::btnEnviarClick(TObject *Sender)
{

  EnviaMensaje(memMensaje->Text);

}
//---------------------------------------------------------------------------
TIdSysLog* TfrmPrincipal::getSysLog()
{
	TIdSysLog *SysLog = new TIdSysLog(NULL);
	SysLog->Port = (System::Word)txtPuerto->Text.ToInt();
	SysLog->Host = txtHost->Text; //"192.168.15.130";
	SysLog->Connect();
	return SysLog;
}
//---------------------------------------------------------------------------
TIdSysLogMessage* TfrmPrincipal::CreaMensaje(MENSAJE Msg)
{
	TIdSysLogMessage  *nuevoMensaje= new TIdSysLogMessage(NULL);
	nuevoMensaje->Msg->Content=Msg.strMensaje;
	nuevoMensaje->Facility=Msg.Facility;
	nuevoMensaje->Severity=Msg.Gravedad;
	nuevoMensaje->Hostname="PRUEBA";
	return nuevoMensaje;
}
//---------------------------------------------------------------------------
void TfrmPrincipal::EnviaMensaje(UnicodeString mensaje)
{
	MENSAJE Msg;
	Msg.strMensaje=AnsiString(mensaje);
	Msg.Facility=sfLogAlert;
 //slEmergency, slAlert, slCritical, slError, slWarning, slNotice, slInformational, slDebug
	switch(NumNivel)
	{
		case 0:
			Msg.Gravedad=slEmergency;
			break;
		case 1:
			Msg.Gravedad=slAlert;
			break;
		case 2:
			Msg.Gravedad=slCritical;
			break;
		case 3:
			Msg.Gravedad=slError;
			break;
		case 4:
			Msg.Gravedad=slWarning;
			break;
		case 5:
			Msg.Gravedad=slNotice;
			break;
		case 6:
			Msg.Gravedad=slInformational;
			break;
		case 7:
			Msg.Gravedad=slDebug;
			break;
    }
	//,sfLogAlert,slNotice

	TIdSysLogMessage *IdSysLogMessage=NULL;
	TIdSysLog *SysLog=NULL;
	try
	{
		SysLog=getSysLog();
		IdSysLogMessage=CreaMensaje(Msg);
		try
		{
			SysLog->SendLogMessage(IdSysLogMessage);
		}
		catch(Exception &E)
		{
			E.Message=E.Message+"Excepcion al enviar log";
		}
	}
	__finally
	{
		if(IdSysLogMessage!=NULL)
		{
			delete IdSysLogMessage;
			IdSysLogMessage=NULL;
		}
		if(SysLog!=NULL)
		{
			delete SysLog;
			SysLog=NULL;
		}

	}
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::btnLimpiarClick(TObject *Sender)
{
    memMensaje->Text = "";
}
//---------------------------------------------------------------------------


void __fastcall TfrmPrincipal::NivelChange(TObject *Sender)
{
	NumNivel = Nivel->ItemIndex;
}
//---------------------------------------------------------------------------

