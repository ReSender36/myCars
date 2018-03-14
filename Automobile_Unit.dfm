object Automobile_Base_Form: TAutomobile_Base_Form
  Left = 0
  Top = 0
  Caption = #1040#1074#1090#1086#1084#1086#1073#1080#1083#1100#1085#1099#1077' '#1076#1077#1083#1072
  ClientHeight = 552
  ClientWidth = 1147
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
  object Label1: TLabel
    Left = 68
    Top = 34
    Width = 101
    Height = 13
    Caption = #1042#1099#1073#1077#1088#1080' '#1072#1074#1090#1086#1084#1086#1073#1080#1083#1100
  end
  object Label2: TLabel
    Left = 16
    Top = 100
    Width = 146
    Height = 13
    Caption = #1058#1077#1082#1091#1097#1080#1081' '#1087#1088#1086#1073#1077#1075' '#1072#1074#1090#1086#1084#1086#1073#1080#1083#1103
  end
  object Label3: TLabel
    Left = 176
    Top = 100
    Width = 238
    Height = 13
    Caption = #1057#1088#1077#1076#1085#1080#1081' '#1088#1072#1089#1093#1086#1076' '#1090#1086#1087#1083#1080#1074#1072' '#1079#1072' '#1087#1077#1088#1080#1086#1076' '#1080#1079#1084#1077#1088#1077#1085#1080#1081
  end
  object ComboBox1: TComboBox
    Left = 16
    Top = 53
    Width = 249
    Height = 21
    TabOrder = 0
    OnSelect = ComboBox1Select
  end
  object Edit1: TEdit
    Left = 16
    Top = 119
    Width = 146
    Height = 21
    Color = clBtnFace
    ReadOnly = True
    TabOrder = 2
  end
  object Edit2: TEdit
    Left = 216
    Top = 119
    Width = 121
    Height = 21
    Color = clBtnFace
    ReadOnly = True
    TabOrder = 3
  end
  object GroupBox1: TGroupBox
    Left = 440
    Top = 22
    Width = 707
    Height = 118
    Caption = #1055#1088#1086#1073#1077#1075#1080' '#1089' '#1079#1072#1084#1077#1085':'
    TabOrder = 4
    object Label4: TLabel
      Left = 12
      Top = 20
      Width = 56
      Height = 13
      Caption = #1052#1072#1089#1083#1072' ('#1058#1054')'
    end
    object Label5: TLabel
      Left = 12
      Top = 41
      Width = 37
      Height = 13
      Caption = #1057#1074#1077#1095#1077#1081
    end
    object Label6: TLabel
      Left = 12
      Top = 62
      Width = 64
      Height = 13
      Caption = #1042#1042' '#1087#1088#1086#1074#1086#1076#1086#1074
    end
    object Label7: TLabel
      Left = 222
      Top = 15
      Width = 53
      Height = 13
      Caption = #1056#1077#1084#1085#1103' '#1043#1056#1052
    end
    object Label8: TLabel
      Left = 222
      Top = 36
      Width = 52
      Height = 13
      Caption = #1056#1077#1084#1085#1103' '#1043#1059#1056
    end
    object Label9: TLabel
      Left = 222
      Top = 57
      Width = 92
      Height = 13
      Caption = #1056#1077#1084#1085#1103' '#1075#1077#1085#1077#1088#1072#1090#1086#1088#1072
    end
    object Label10: TLabel
      Left = 222
      Top = 78
      Width = 106
      Height = 13
      Caption = #1056#1077#1084#1085#1103' '#1082#1086#1085#1076#1080#1094#1080#1086#1085#1077#1088#1072
    end
    object Label11: TLabel
      Left = 12
      Top = 83
      Width = 64
      Height = 13
      Caption = #1052#1072#1089#1083#1072' '#1074' '#1050#1055#1055
    end
    object Label12: TLabel
      Left = 443
      Top = 60
      Width = 141
      Height = 13
      Caption = #1047#1072#1076#1085#1080#1093' '#1090#1086#1088#1084#1086#1079#1085#1099#1093' '#1082#1086#1083#1086#1076#1086#1082
    end
    object Label13: TLabel
      Left = 443
      Top = 11
      Width = 154
      Height = 13
      Caption = #1055#1077#1088#1077#1076#1085#1080#1093' '#1090#1086#1088#1084#1086#1079#1085#1099#1093' '#1082#1086#1083#1086#1076#1086#1082
    end
    object Label14: TLabel
      Left = 443
      Top = 33
      Width = 147
      Height = 13
      Caption = #1055#1077#1088#1077#1076#1085#1080#1093' '#1090#1086#1088#1084#1086#1079#1085#1099#1093' '#1076#1080#1089#1082#1086#1074
    end
    object Label15: TLabel
      Left = 443
      Top = 85
      Width = 134
      Height = 13
      Caption = #1047#1072#1076#1085#1080#1093' '#1090#1086#1088#1084#1086#1079#1085#1099#1093' '#1076#1080#1089#1082#1086#1074
    end
    object Edit3: TEdit
      Left = 116
      Top = 12
      Width = 100
      Height = 21
      Color = clBtnFace
      ReadOnly = True
      TabOrder = 0
    end
    object Edit4: TEdit
      Left = 116
      Top = 33
      Width = 100
      Height = 21
      Color = clBtnFace
      ReadOnly = True
      TabOrder = 1
    end
    object Edit5: TEdit
      Left = 116
      Top = 54
      Width = 100
      Height = 21
      Color = clBtnFace
      ReadOnly = True
      TabOrder = 2
    end
    object Edit6: TEdit
      Left = 116
      Top = 75
      Width = 100
      Height = 21
      Color = clBtnFace
      ReadOnly = True
      TabOrder = 3
    end
    object Edit7: TEdit
      Left = 334
      Top = 12
      Width = 95
      Height = 21
      Color = clBtnFace
      ReadOnly = True
      TabOrder = 4
    end
    object Edit8: TEdit
      Left = 334
      Top = 33
      Width = 95
      Height = 21
      Color = clBtnFace
      ReadOnly = True
      TabOrder = 5
    end
    object Edit9: TEdit
      Left = 334
      Top = 54
      Width = 95
      Height = 21
      Color = clBtnFace
      ReadOnly = True
      TabOrder = 6
    end
    object Edit10: TEdit
      Left = 334
      Top = 75
      Width = 95
      Height = 21
      Color = clBtnFace
      ReadOnly = True
      TabOrder = 7
    end
    object Edit11: TEdit
      Left = 603
      Top = 8
      Width = 100
      Height = 21
      Color = clBtnFace
      ReadOnly = True
      TabOrder = 8
    end
    object Edit12: TEdit
      Left = 603
      Top = 57
      Width = 100
      Height = 21
      Color = clBtnFace
      ReadOnly = True
      TabOrder = 9
    end
    object Edit13: TEdit
      Left = 603
      Top = 30
      Width = 100
      Height = 21
      Color = clBtnFace
      ReadOnly = True
      TabOrder = 10
    end
    object Edit14: TEdit
      Left = 603
      Top = 82
      Width = 100
      Height = 21
      Color = clBtnFace
      ReadOnly = True
      TabOrder = 11
    end
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 1147
    Height = 24
    Caption = 'ToolBar1'
    Images = DM2.IWImageList1
    TabOrder = 5
    object ToolButton1: TToolButton
      Left = 0
      Top = 0
      Hint = #1042#1074#1077#1089#1090#1080' '#1085#1086#1074#1091#1102' '#1088#1072#1073#1086#1090#1091' '#1089' '#1072#1074#1090#1086
      Caption = 'ToolButton1'
      ImageIndex = 1
      ParentShowHint = False
      ShowHint = True
      OnClick = ToolButton1Click
    end
    object ToolButton2: TToolButton
      Left = 23
      Top = 0
      Width = 8
      Caption = 'ToolButton2'
      ImageIndex = 2
      Style = tbsSeparator
    end
    object ToolButton3: TToolButton
      Left = 31
      Top = 0
      Hint = #1057#1087#1080#1089#1086#1082' '#1088#1072#1073#1086#1090' '#1089' '#1072#1074#1090#1086
      Caption = 'ToolButton3'
      ImageIndex = 2
      ParentShowHint = False
      ShowHint = True
      OnClick = ToolButton3Click
    end
    object ToolButton4: TToolButton
      Left = 54
      Top = 0
      Hint = #1057#1087#1080#1089#1086#1082' '#1087#1083#1072#1090#1077#1078#1077#1081
      Caption = 'ToolButton4'
      ImageIndex = 0
      ParentShowHint = False
      ShowHint = True
    end
    object ToolButton5: TToolButton
      Left = 77
      Top = 0
      Width = 8
      Caption = 'ToolButton5'
      ImageIndex = 1
      Style = tbsSeparator
    end
    object ToolButton6: TToolButton
      Left = 85
      Top = 0
      Caption = 'ToolButton6'
      ImageIndex = 1
      OnClick = ToolButton6Click
    end
    object DBNavigator1: TDBNavigator
      Left = 108
      Top = 0
      Width = 240
      Height = 22
      DataSource = DM2.ds_FirstReq
      TabOrder = 0
      OnClick = DBNavigator1Click
    end
  end
  object BitBtn1: TBitBtn
    Left = 875
    Top = 161
    Width = 75
    Height = 25
    DoubleBuffered = True
    Kind = bkClose
    NumGlyphs = 2
    ParentDoubleBuffered = False
    TabOrder = 1
  end
  object GridPanel1: TGridPanel
    Left = 0
    Top = 296
    Width = 1147
    Height = 225
    Caption = 'GridPanel1'
    ColumnCollection = <
      item
        Value = 50.000000000000000000
      end
      item
        Value = 50.000000000000000000
      end>
    ControlCollection = <
      item
        Column = 0
        Control = ToolBar2
        Row = 0
      end
      item
        Column = 1
        Control = ToolBar3
        Row = 0
      end
      item
        Column = 0
        Control = DBGrid1
        Row = 1
      end
      item
        Column = 1
        Control = DBGrid2
        Row = 1
      end>
    RowCollection = <
      item
        SizeStyle = ssAbsolute
        Value = 31.000000000000000000
      end
      item
        SizeStyle = ssAbsolute
        Value = 200.000000000000000000
      end>
    TabOrder = 6
    DesignSize = (
      1147
      225)
    object ToolBar2: TToolBar
      Left = 1
      Top = 1
      Width = 572
      Height = 29
      Anchors = []
      ButtonHeight = 21
      Caption = 'ToolBar2'
      TabOrder = 0
      object ToolButton7: TToolButton
        Left = 0
        Top = 0
        Caption = 'ToolButton7'
        ImageIndex = 0
      end
      object Label16: TLabel
        Left = 23
        Top = 0
        Width = 119
        Height = 13
        Caption = #1053#1077#1086#1073#1093#1086#1076#1080#1084#1099#1077' '#1079#1072#1087#1095#1072#1089#1090#1080
      end
    end
    object ToolBar3: TToolBar
      Left = 573
      Top = 1
      Width = 573
      Height = 29
      Anchors = []
      ButtonHeight = 21
      Caption = 'ToolBar2'
      TabOrder = 1
      object ToolButton8: TToolButton
        Left = 0
        Top = 0
        Caption = 'ToolButton8'
        ImageIndex = 0
      end
      object Label17: TLabel
        Left = 23
        Top = 0
        Width = 111
        Height = 13
        Caption = #1053#1077#1086#1073#1093#1086#1076#1080#1084#1099#1077' '#1088#1072#1073#1086#1090#1099
      end
    end
    object DBGrid1: TDBGrid
      Left = 1
      Top = 38
      Width = 572
      Height = 188
      Anchors = []
      TabOrder = 2
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -11
      TitleFont.Name = 'Tahoma'
      TitleFont.Style = []
    end
    object DBGrid2: TDBGrid
      Left = 573
      Top = 38
      Width = 573
      Height = 188
      Anchors = []
      TabOrder = 3
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -11
      TitleFont.Name = 'Tahoma'
      TitleFont.Style = []
    end
  end
  object GridPanel2: TGridPanel
    Left = 16
    Top = 160
    Width = 853
    Height = 89
    Caption = 'GridPanel2'
    ColumnCollection = <
      item
        Value = 100.000000000000000000
      end>
    ControlCollection = <
      item
        Column = 0
        Control = ToolBar4
        Row = 0
      end
      item
        Column = 0
        Control = DBGrid3
        Row = 1
      end>
    RowCollection = <
      item
        SizeStyle = ssAbsolute
        Value = 23.000000000000000000
      end
      item
        SizeStyle = ssAbsolute
        Value = 65.000000000000000000
      end>
    TabOrder = 7
    DesignSize = (
      853
      89)
    object ToolBar4: TToolBar
      Left = 1
      Top = 1
      Width = 851
      Height = 22
      Anchors = []
      Caption = 'ToolBar4'
      TabOrder = 0
      object ToolButton9: TToolButton
        Left = 0
        Top = 0
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090
        Caption = 'ToolButton9'
        ImageIndex = 0
        ParentShowHint = False
        ShowHint = True
      end
    end
    object DBGrid3: TDBGrid
      Left = 1
      Top = 24
      Width = 851
      Height = 65
      Anchors = []
      TabOrder = 1
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -11
      TitleFont.Name = 'Tahoma'
      TitleFont.Style = []
    end
  end
  object DataSource1: TDataSource
    DataSet = ADODataSet1
    Left = 120
    Top = 208
  end
  object ADODataSet1: TADODataSet
    FieldDefs = <
      item
        Name = 'ADODataSet1Field1'
      end>
    Parameters = <>
    StoreDefs = True
    Left = 56
    Top = 208
  end
end
