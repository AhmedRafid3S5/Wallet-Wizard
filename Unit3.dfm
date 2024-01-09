object Form3: TForm3
  Left = 613
  Top = 150
  Caption = 'Form3'
  ClientHeight = 442
  ClientWidth = 617
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Position = poDesigned
  TextHeight = 15
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 617
    Height = 442
    ActivePage = Expense
    Align = alClient
    TabOrder = 0
    OnChange = PageControl1Change
    object Income: TTabSheet
      Caption = 'Income'
      ImageIndex = 3
      object Label1: TLabel
        Left = 194
        Top = 3
        Width = 209
        Height = 38
        Caption = 'Income Tracker'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Comic Sans MS'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label2: TLabel
        Left = 27
        Top = 95
        Width = 62
        Height = 26
        Caption = 'Source'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Comic Sans MS'
        Font.Style = []
        ParentFont = False
      end
      object Label3: TLabel
        Left = 27
        Top = 146
        Width = 66
        Height = 26
        Caption = 'Amount'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Comic Sans MS'
        Font.Style = []
        ParentFont = False
      end
      object Label4: TLabel
        Left = 32
        Top = 212
        Width = 42
        Height = 26
        Caption = 'Date'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Comic Sans MS'
        Font.Style = []
        ParentFont = False
      end
      object Label9: TLabel
        Left = 27
        Top = 60
        Width = 129
        Height = 29
        Caption = 'Add Or Edit '
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -21
        Font.Name = 'Comic Sans MS'
        Font.Style = []
        ParentFont = False
      end
      object Label10: TLabel
        Left = 80
        Top = 223
        Width = 76
        Height = 15
        Caption = 'DD/MM/YYYY'
      end
      object Label11: TLabel
        Left = 264
        Top = 60
        Width = 152
        Height = 29
        Caption = 'Search By Date'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -21
        Font.Name = 'Comic Sans MS'
        Font.Style = []
        ParentFont = False
      end
      object Label13: TLabel
        Left = 32
        Top = 273
        Width = 112
        Height = 29
        Caption = 'Short Note'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -21
        Font.Name = 'Comic Sans MS'
        Font.Style = []
        ParentFont = False
      end
      object Label14: TLabel
        Left = 264
        Top = 313
        Width = 55
        Height = 26
        Caption = 'Month'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Comic Sans MS'
        Font.Style = []
        ParentFont = False
      end
      object Label15: TLabel
        Left = 375
        Top = 313
        Width = 41
        Height = 26
        Caption = 'Year'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -19
        Font.Name = 'Comic Sans MS'
        Font.Style = []
        ParentFont = False
      end
      object Button5: TButton
        Left = 32
        Top = 344
        Width = 75
        Height = 25
        Caption = 'Add '
        TabOrder = 0
        OnClick = Button5Click
      end
      object Edit2: TEdit
        Left = 30
        Top = 178
        Width = 100
        Height = 23
        TabOrder = 1
        Text = 'Edit2'
      end
      object Edit4: TEdit
        Left = 30
        Top = 244
        Width = 44
        Height = 23
        TabOrder = 2
        Text = 'Edit4'
      end
      object Edit5: TEdit
        Left = 80
        Top = 244
        Width = 44
        Height = 23
        TabOrder = 3
        Text = 'Edit5'
      end
      object Edit6: TEdit
        Left = 130
        Top = 244
        Width = 75
        Height = 23
        TabOrder = 4
        Text = 'Edit6'
      end
      object Edit7: TEdit
        Left = 30
        Top = 117
        Width = 100
        Height = 23
        TabOrder = 5
        Text = 'Edit7'
      end
      object Button4: TButton
        Left = 130
        Top = 344
        Width = 75
        Height = 25
        Caption = 'Edit'
        TabOrder = 6
        OnClick = Button4Click
      end
      object Button6: TButton
        Left = 162
        Top = 212
        Width = 43
        Height = 26
        Caption = 'Auto'
        TabOrder = 7
        OnClick = Button6Click
      end
      object ListBox1: TListBox
        Left = 264
        Top = 117
        Width = 329
        Height = 190
        ItemHeight = 15
        TabOrder = 8
      end
      object Edit13: TEdit
        Left = 32
        Top = 304
        Width = 173
        Height = 23
        TabOrder = 9
        Text = 'Edit13'
      end
      object Button9: TButton
        Left = 502
        Top = 344
        Width = 75
        Height = 25
        Caption = 'Search'
        TabOrder = 10
        OnClick = Button9Click
      end
      object Edit14: TEdit
        Left = 264
        Top = 345
        Width = 63
        Height = 23
        TabOrder = 11
        Text = 'Edit14'
      end
      object Edit15: TEdit
        Left = 375
        Top = 345
        Width = 85
        Height = 23
        TabOrder = 12
        Text = 'Edit15'
      end
    end
    object Expense: TTabSheet
      Caption = 'Expense'
      ImageIndex = 4
      object Label5: TLabel
        Left = 207
        Top = 3
        Width = 213
        Height = 31
        Caption = 'EXPENSE TRACKER'
        Font.Charset = ANSI_CHARSET
        Font.Color = clBlack
        Font.Height = -22
        Font.Name = 'Comic Sans MS'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label6: TLabel
        Left = 19
        Top = 139
        Width = 78
        Height = 30
        Caption = 'Amount'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -22
        Font.Name = 'Comic Sans MS'
        Font.Style = []
        ParentFont = False
      end
      object Label7: TLabel
        Left = 21
        Top = 80
        Width = 92
        Height = 32
        Caption = 'Category'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -22
        Font.Name = 'Comic Sans MS'
        Font.Style = [fsItalic]
        ParentFont = False
      end
      object Label12: TLabel
        Left = 74
        Top = 216
        Width = 76
        Height = 15
        Caption = 'DD/MM/YYYY'
      end
      object Label8: TLabel
        Left = 19
        Top = 204
        Width = 49
        Height = 30
        Caption = 'Date'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -22
        Font.Name = 'Comic Sans MS'
        Font.Style = []
        ParentFont = False
      end
      object Label16: TLabel
        Left = 19
        Top = 280
        Width = 112
        Height = 29
        Caption = 'Short Note'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -21
        Font.Name = 'Comic Sans MS'
        Font.Style = []
        ParentFont = False
      end
      object Label17: TLabel
        Left = 21
        Top = 54
        Width = 114
        Height = 28
        Caption = 'Add Or Edit'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -20
        Font.Name = 'Comic Sans MS'
        Font.Style = []
        ParentFont = False
      end
      object Label18: TLabel
        Left = 261
        Top = 52
        Width = 159
        Height = 30
        Caption = 'Search By Date'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -22
        Font.Name = 'Comic Sans MS'
        Font.Style = []
        ParentFont = False
      end
      object Label19: TLabel
        Left = 264
        Top = 315
        Width = 51
        Height = 24
        Caption = 'Month'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -17
        Font.Name = 'Comic Sans MS'
        Font.Style = []
        ParentFont = False
      end
      object Label20: TLabel
        Left = 382
        Top = 315
        Width = 38
        Height = 24
        Caption = 'Year'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -17
        Font.Name = 'Comic Sans MS'
        Font.Style = []
        ParentFont = False
      end
      object Edit8: TEdit
        Left = 21
        Top = 175
        Width = 138
        Height = 23
        TabOrder = 0
        Text = 'Edit8'
      end
      object Edit9: TEdit
        Left = 21
        Top = 118
        Width = 136
        Height = 23
        TabOrder = 1
        Text = 'Edit9'
      end
      object Edit10: TEdit
        Left = 21
        Top = 240
        Width = 57
        Height = 23
        TabOrder = 2
        Text = 'Edit10'
      end
      object Edit11: TEdit
        Left = 84
        Top = 240
        Width = 65
        Height = 23
        TabOrder = 3
        Text = 'Edit11'
      end
      object Edit12: TEdit
        Left = 155
        Top = 240
        Width = 65
        Height = 23
        TabOrder = 4
        Text = 'Edit12'
      end
      object Button1: TButton
        Left = 21
        Top = 344
        Width = 70
        Height = 25
        Caption = 'Add'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Segoe UI'
        Font.Style = []
        ParentFont = False
        TabOrder = 5
        OnClick = Button1Click
      end
      object Button7: TButton
        Left = 112
        Top = 344
        Width = 75
        Height = 25
        Caption = 'Edit'
        TabOrder = 6
        OnClick = Button7Click
      end
      object Button8: TButton
        Left = 175
        Top = 207
        Width = 45
        Height = 27
        Caption = 'Auto'
        TabOrder = 7
        OnClick = Button8Click
      end
      object Edit16: TEdit
        Left = 19
        Top = 315
        Width = 202
        Height = 23
        TabOrder = 8
        Text = 'Edit16'
      end
      object ListBox2: TListBox
        Left = 264
        Top = 107
        Width = 337
        Height = 202
        ItemHeight = 15
        TabOrder = 9
      end
      object Edit17: TEdit
        Left = 264
        Top = 345
        Width = 70
        Height = 23
        TabOrder = 10
        Text = 'Edit17'
      end
      object Edit18: TEdit
        Left = 382
        Top = 345
        Width = 81
        Height = 23
        TabOrder = 11
        Text = 'Edit18'
      end
      object Search: TButton
        Left = 526
        Top = 344
        Width = 75
        Height = 25
        Caption = 'Search'
        TabOrder = 12
        OnClick = SearchClick
      end
    end
    object Analytics: TTabSheet
      Caption = 'Analytics'
      ImageIndex = 1
      object ScrollBox1: TScrollBox
        AlignWithMargins = True
        Left = 3
        Top = 3
        Width = 603
        Height = 406
        HorzScrollBar.ButtonSize = 10
        HorzScrollBar.Color = clBtnShadow
        HorzScrollBar.ParentColor = False
        VertScrollBar.ButtonSize = 10
        VertScrollBar.Position = 554
        Align = alClient
        TabOrder = 0
        OnMouseWheelDown = ScrollBox1MouseWheelDown
        OnMouseWheelUp = ScrollBox1MouseWheelUp
        object Chart1: TChart
          AlignWithMargins = True
          Left = 0
          Top = -892
          Width = 665
          Height = 360
          Foot.Font.Height = -17
          Foot.Font.Name = 'Copperplate Gothic Bold'
          Foot.Font.Style = [fsItalic, fsUnderline]
          Foot.Text.Strings = (
            '')
          Legend.Font.Height = -15
          Legend.Font.Style = [fsBold]
          Title.Font.Name = 'Copperplate Gothic Bold'
          Title.Text.Strings = (
            'Expenses')
          AxisBehind = False
          TopAxis.LabelsSize = 10
          TopAxis.TitleSize = 10
          View3DOptions.Elevation = 315
          View3DOptions.Orthogonal = False
          View3DOptions.Perspective = 0
          View3DOptions.Rotation = 360
          TabOrder = 0
          DefaultCanvas = 'TGDIPlusCanvas'
          ColorPaletteIndex = 13
          object Series1: TPieSeries
            HoverElement = []
            Marks.Tail.Margin = 2
            XValues.Order = loAscending
            YValues.Name = 'Pie'
            YValues.Order = loNone
            CustomXRadius = 200
            CustomYRadius = 200
            Frame.InnerBrush.BackColor = clRed
            Frame.InnerBrush.Gradient.EndColor = clGray
            Frame.InnerBrush.Gradient.MidColor = clWhite
            Frame.InnerBrush.Gradient.StartColor = 4210752
            Frame.InnerBrush.Gradient.Visible = True
            Frame.MiddleBrush.BackColor = clYellow
            Frame.MiddleBrush.Gradient.EndColor = 8553090
            Frame.MiddleBrush.Gradient.MidColor = clWhite
            Frame.MiddleBrush.Gradient.StartColor = clGray
            Frame.MiddleBrush.Gradient.Visible = True
            Frame.OuterBrush.BackColor = clGreen
            Frame.OuterBrush.Gradient.EndColor = 4210752
            Frame.OuterBrush.Gradient.MidColor = clWhite
            Frame.OuterBrush.Gradient.StartColor = clSilver
            Frame.OuterBrush.Gradient.Visible = True
            Frame.Width = 4
            OtherSlice.Legend.Visible = False
            PiePen.Visible = False
          end
        end
        object Chart2: TChart
          Left = 0
          Top = -1044
          Width = 669
          Height = 360
          Foot.Font.Height = -17
          Foot.Font.Name = 'Copperplate Gothic Bold'
          Foot.Font.Style = [fsItalic, fsUnderline]
          Legend.Font.Height = -15
          Legend.Font.Style = [fsBold]
          Title.Font.Name = 'Copperplate Gothic Bold'
          Title.Text.Strings = (
            'Income')
          View3DOptions.Elevation = 315
          View3DOptions.Orthogonal = False
          View3DOptions.Perspective = 0
          View3DOptions.Rotation = 360
          TabOrder = 1
          DefaultCanvas = 'TGDIPlusCanvas'
          ColorPaletteIndex = 13
          object Series2: TPieSeries
            HoverElement = []
            Marks.Tail.Margin = 2
            XValues.Order = loAscending
            YValues.Name = 'Pie'
            YValues.Order = loNone
            CustomXRadius = 200
            CustomYRadius = 200
            Frame.InnerBrush.BackColor = clRed
            Frame.InnerBrush.Gradient.EndColor = clGray
            Frame.InnerBrush.Gradient.MidColor = clWhite
            Frame.InnerBrush.Gradient.StartColor = 4210752
            Frame.InnerBrush.Gradient.Visible = True
            Frame.MiddleBrush.BackColor = clYellow
            Frame.MiddleBrush.Gradient.EndColor = 8553090
            Frame.MiddleBrush.Gradient.MidColor = clWhite
            Frame.MiddleBrush.Gradient.StartColor = clGray
            Frame.MiddleBrush.Gradient.Visible = True
            Frame.OuterBrush.BackColor = clGreen
            Frame.OuterBrush.Gradient.EndColor = 4210752
            Frame.OuterBrush.Gradient.MidColor = clWhite
            Frame.OuterBrush.Gradient.StartColor = clSilver
            Frame.OuterBrush.Gradient.Visible = True
            Frame.Width = 4
            OtherSlice.Legend.Visible = False
            PiePen.Visible = False
          end
        end
        object Chart3: TChart
          Left = 3
          Top = -526
          Width = 668
          Height = 500
          Title.Text.Strings = (
            'Transaction averages over the months')
          View3D = False
          TabOrder = 2
          DefaultCanvas = 'TGDIPlusCanvas'
          ColorPaletteIndex = 13
          object ComboBox2: TComboBox
            Left = 560
            Top = 33
            Width = 97
            Height = 23
            TabOrder = 0
            Text = 'ComboBox2'
            OnChange = ComboBox2Change
          end
          object Series3: TLineSeries
            HoverElement = [heCurrent]
            SeriesColor = 65408
            Title = 'Avg_Income'
            Brush.BackColor = clDefault
            ClickTolerance = 5
            DrawStyle = dsCurve
            OutLine.Width = 5
            Pointer.Brush.Color = clGreen
            Pointer.Brush.Image.Data = {
              07544269746D61707E000000424D7E000000000000003E000000280000001000
              0000100000000100010000000000400000000000000000000000020000000000
              000000000000FFFFFF0000000000AAAA000000000000AAAA000000000000AAAA
              000000000000AAAA000000000000AAAA000000000000AAAA000000000000AAAA
              000000000000AAAA0000}
            Pointer.HorizSize = 5
            Pointer.InflateMargins = True
            Pointer.Style = psDiamond
            Pointer.VertSize = 5
            Pointer.Visible = True
            XValues.Name = 'X'
            XValues.Order = loAscending
            YValues.Name = 'Y'
            YValues.Order = loNone
            OnClickPointer = Series3ClickPointer
          end
          object Series4: TLineSeries
            HoverElement = [heCurrent]
            SeriesColor = clRed
            Title = 'Avg_Expense'
            Brush.BackColor = clDefault
            Pointer.Brush.Color = 33023
            Pointer.HorizSize = 5
            Pointer.InflateMargins = True
            Pointer.Style = psHexagon
            Pointer.VertSize = 5
            Pointer.Visible = True
            XValues.Name = 'X'
            XValues.Order = loAscending
            YValues.Name = 'Y'
            YValues.Order = loNone
            OnClickPointer = Series4ClickPointer
            object TSmoothingFunction
              Period = 1.000000000000000000
              Factor = 8
            end
          end
        end
        object StaticText4: TStaticText
          Left = 200
          Top = -554
          Width = 301
          Height = 25
          Caption = 'Monthly Financial Analysis'
          Color = clTeal
          Font.Charset = ANSI_CHARSET
          Font.Color = clTeal
          Font.Height = -20
          Font.Name = 'Copperplate Gothic Light'
          Font.Style = [fsUnderline]
          ParentColor = False
          ParentFont = False
          TabOrder = 3
        end
        object Button3: TButton
          Left = 590
          Top = -524
          Width = 75
          Height = 25
          Caption = 'Refresh'
          TabOrder = 4
          OnClick = Button3Click
        end
        object ComboBox1: TComboBox
          Left = 39
          Top = -523
          Width = 130
          Height = 23
          TabOrder = 5
          Text = 'ComboBox1'
          OnChange = ComboBox1Change
        end
        object Edit3: TEdit
          Left = 3
          Top = -523
          Width = 38
          Height = 23
          TabOrder = 6
          Text = 'Edit3'
        end
        object Chart4: TChart
          Left = -2
          Top = -26
          Width = 668
          Height = 500
          Title.Text.Strings = (
            'TChart')
          OnScroll = Chart4Scroll
          View3D = False
          TabOrder = 7
          DefaultCanvas = 'TGDIPlusCanvas'
          ColorPaletteIndex = 13
          object MoreInfo: TButton
            Left = 582
            Top = 40
            Width = 75
            Height = 25
            Caption = 'MoreInfo'
            TabOrder = 0
            OnClick = MoreInfoClick
          end
          object Series5: TPointSeries
            HoverElement = [heCurrent]
            ClickableLine = False
            Pointer.HorizSize = 8
            Pointer.InflateMargins = True
            Pointer.Style = psDiagCross
            Pointer.VertSize = 8
            XValues.Name = 'X'
            XValues.Order = loAscending
            YValues.Name = 'Y'
            YValues.Order = loNone
          end
          object Series6: TFastLineSeries
            HoverElement = []
            LinePen.Color = 3513587
            XValues.Name = 'X'
            XValues.Order = loAscending
            YValues.Name = 'Y'
            YValues.Order = loNone
            object TeeFunction1: TCustomTeeFunction
              Period = 1.000000000000000000
              NumPoints = 100
            end
          end
        end
        object RichEdit3: TRichEdit
          Left = -2
          Top = 149
          Width = 657
          Height = 161
          Color = clBtnFace
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Comic Sans MS'
          Font.Style = []
          Lines.Strings = (
            'RichEdit3')
          ParentFont = False
          ReadOnly = True
          TabOrder = 8
        end
      end
    end
    object ZakatPage: TTabSheet
      Caption = 'Zakat'
      ImageIndex = 2
      OnContextPopup = ZakatPageContextPopup
      object StaticText1: TStaticText
        Left = 36
        Top = 40
        Width = 4
        Height = 4
        TabOrder = 0
      end
      object RichEdit2: TRichEdit
        Left = 3
        Top = 3
        Width = 611
        Height = 296
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Segoe UI'
        Font.Style = []
        Lines.Strings = (
          'RichEdit2')
        ParentFont = False
        TabOrder = 1
      end
      object Edit1: TEdit
        Left = 3
        Top = 329
        Width = 121
        Height = 23
        NumbersOnly = True
        TabOrder = 2
        Text = 'Edit1'
      end
      object StaticText2: TStaticText
        Left = 3
        Top = 313
        Width = 150
        Height = 18
        Caption = 'Enter current balance'
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = 'Stencil'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
      end
      object Button2: TButton
        Left = 3
        Top = 358
        Width = 75
        Height = 25
        Caption = 'Enter'
        TabOrder = 4
        OnClick = Button2Click
      end
    end
  end
end
