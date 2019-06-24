//---------------------------------------------------------------------------

#ifndef PrincipalH
#define PrincipalH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdSysLog.hpp>
#include <IdUDPBase.hpp>
#include <IdUDPClient.hpp>
//---------------------------------------------------------------------------
typedef struct STRUCT_MENSAJE
{
	UnicodeString strMensaje;
	TIdSyslogFacility Facility;
	TIdSyslogSeverity Gravedad;
	//void Inicializa(UnicodeString strMensaje,TIdSyslogFacility Facility,TIdSyslogSeverity Gravedad);
}
MENSAJE;
class TfrmPrincipal : public TForm
{
__published:	// IDE-managed Components
	TButton *btnEnviar;
	TMemo *memMensaje;
	TLabel *lblMensaje;
	TButton *btnLimpiar;
	TEdit *txtHost;
	TEdit *txtPuerto;
	TLabel *lblHost;
	TLabel *lblPuerto;
	TComboBox *Nivel;
	TLabel *Label1;
	void __fastcall btnEnviarClick(TObject *Sender);
	void __fastcall btnLimpiarClick(TObject *Sender);
	void __fastcall NivelChange(TObject *Sender);
private:	// User declarations
	TIdSysLog* getSysLog();
	TIdSysLogMessage* CreaMensaje(MENSAJE Msg);
    void EnviaMensaje(UnicodeString mensaje);
public:		// User declarations
	__fastcall TfrmPrincipal(TComponent* Owner);
    int NumNivel;
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmPrincipal *frmPrincipal;
//---------------------------------------------------------------------------
#endif
