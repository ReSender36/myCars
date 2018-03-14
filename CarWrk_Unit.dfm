object Wrks_Form: TWrks_Form
  Left = 0
  Top = 0
  Caption = #1056#1072#1073#1086#1090#1099' '#1089' '#1072#1074#1090#1086
  ClientHeight = 346
  ClientWidth = 743
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
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 743
    Height = 21
    Caption = 'ToolBar1'
    TabOrder = 0
    object ComboBox1: TComboBox
      Left = 0
      Top = 0
      Width = 145
      Height = 21
      TabOrder = 0
      Text = #1040#1074#1090#1086#1084#1086#1073#1080#1083#1080
    end
    object ComboBox2: TComboBox
      Left = 145
      Top = 0
      Width = 145
      Height = 21
      TabOrder = 1
      Text = #1042#1080#1076#1099' '#1089#1077#1088#1074#1080#1089#1086#1074
    end
  end
  object DBGrid1: TDBGrid
    Left = 0
    Top = 24
    Width = 743
    Height = 289
    DataSource = DataSource1
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
  end
  object BitBtn1: TBitBtn
    Left = 660
    Top = 319
    Width = 75
    Height = 25
    DoubleBuffered = True
    Kind = bkClose
    NumGlyphs = 2
    ParentDoubleBuffered = False
    TabOrder = 2
    OnClick = BitBtn1Click
  end
  object ADOQuery1: TADOQuery
    Connection = DM2.adoMainConn
    Parameters = <>
    Left = 16
    Top = 296
  end
  object DataSource1: TDataSource
    DataSet = ADOQuery1
    Left = 72
    Top = 296
  end
end
