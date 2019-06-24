object frmPrincipal: TfrmPrincipal
  Left = 0
  Top = 0
  Caption = 'Principal'
  ClientHeight = 199
  ClientWidth = 456
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object lblMensaje: TLabel
    Left = 24
    Top = 8
    Width = 67
    Height = 18
    Caption = 'Mensaje:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lblHost: TLabel
    Left = 32
    Top = 141
    Width = 50
    Height = 13
    Caption = 'IP-HOST:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lblPuerto: TLabel
    Left = 192
    Top = 141
    Width = 41
    Height = 13
    Caption = 'Puerto:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label1: TLabel
    Left = 295
    Top = 45
    Width = 75
    Height = 13
    Caption = 'NIVEL ERROR:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object btnEnviar: TButton
    Left = 24
    Top = 103
    Width = 75
    Height = 25
    Caption = 'Enviar'
    TabOrder = 0
    OnClick = btnEnviarClick
  end
  object memMensaje: TMemo
    Left = 24
    Top = 32
    Width = 265
    Height = 74
    ScrollBars = ssVertical
    TabOrder = 1
  end
  object btnLimpiar: TButton
    Left = 214
    Top = 105
    Width = 75
    Height = 25
    Caption = 'Limpiar'
    TabOrder = 2
    OnClick = btnLimpiarClick
  end
  object txtHost: TEdit
    Left = 32
    Top = 160
    Width = 121
    Height = 21
    TabOrder = 3
  end
  object txtPuerto: TEdit
    Left = 192
    Top = 160
    Width = 97
    Height = 21
    TabOrder = 4
  end
  object Nivel: TComboBox
    Left = 295
    Top = 64
    Width = 145
    Height = 21
    TabOrder = 5
    Text = 'Nivel'
    OnChange = NivelChange
    Items.Strings = (
      '0-Emergencia'
      '1-Critico'
      '2-Alerta'
      '3-Error'
      '4-Warning'
      '5-Notificaciones'
      '6-Informativo'
      '7-Debug')
  end
end
