object AddAcc_Form: TAddAcc_Form
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = #1058#1088#1077#1073#1091#1102#1090#1089#1103' '#1076#1086#1087#1086#1083#1085#1080#1090#1077#1083#1100#1085#1099#1077' '#1076#1072#1085#1085#1099#1077
  ClientHeight = 160
  ClientWidth = 269
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 0
    Top = 0
    Width = 254
    Height = 121
    Caption = #1042#1099#1073#1077#1088#1080#1090#1077' '#1073#1072#1085#1082'/'#1089#1095#1077#1090
    TabOrder = 0
    object Label1: TLabel
      Left = 3
      Top = 70
      Width = 134
      Height = 13
      Caption = #1042#1099#1073#1077#1088#1080#1090#1077' '#1089#1087#1086#1089#1086#1073' '#1087#1083#1072#1090#1077#1078#1072
    end
    object ComboBox1: TComboBox
      Left = 3
      Top = 43
      Width = 246
      Height = 21
      Enabled = False
      TabOrder = 0
      OnClick = ComboBox1Click
      OnExit = ComboBox1Exit
      OnSelect = ComboBox1Select
    end
    object ComboBox2: TComboBox
      Left = 3
      Top = 16
      Width = 246
      Height = 21
      TabOrder = 1
      OnClick = ComboBox2Click
      OnExit = ComboBox2Exit
      OnSelect = ComboBox2Select
    end
    object ComboBox3: TComboBox
      Left = 3
      Top = 89
      Width = 246
      Height = 21
      TabOrder = 2
      OnSelect = ComboBox3Select
    end
  end
  object BitBtn1: TBitBtn
    Left = 91
    Top = 127
    Width = 75
    Height = 25
    DoubleBuffered = True
    Kind = bkOK
    NumGlyphs = 2
    ParentDoubleBuffered = False
    TabOrder = 1
  end
  object BitBtn2: TBitBtn
    Left = 184
    Top = 128
    Width = 75
    Height = 25
    DoubleBuffered = True
    Kind = bkCancel
    NumGlyphs = 2
    ParentDoubleBuffered = False
    TabOrder = 2
  end
  object ADOQuery1: TADOQuery
    Connection = DM2.adoMainConn
    Parameters = <>
    Left = 8
    Top = 112
  end
end
