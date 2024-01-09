object Form3: TForm3
  Left = 613
  Top = 150
  Caption = 'Form3'
  ClientHeight = 706
  ClientWidth = 697
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
    Width = 697
    Height = 706
    ActivePage = Tracker
    Align = alClient
    TabOrder = 0
    OnChange = PageControl1Change
    ExplicitWidth = 691
    ExplicitHeight = 697
    object TabSheet1: TTabSheet
      Caption = 'TabSheet1'
      ImageIndex = 3
    end
    object Tracker: TTabSheet
      Caption = 'Tracker'
      ImageIndex = 3
    end
    object Analytics: TTabSheet
      Caption = 'Analytics'
      ImageIndex = 1
      object ScrollBox1: TScrollBox
        AlignWithMargins = True
        Left = 3
        Top = 3
        Width = 683
        Height = 670
        HorzScrollBar.ButtonSize = 10
        HorzScrollBar.Color = clBtnShadow
        HorzScrollBar.ParentColor = False
        VertScrollBar.ButtonSize = 10
        Align = alClient
        TabOrder = 0
        OnMouseWheelDown = ScrollBox1MouseWheelDown
        OnMouseWheelUp = ScrollBox1MouseWheelUp
        object Chart1: TChart
          AlignWithMargins = True
          Left = 0
          Top = -338
          Width = 665
          Height = 360
          Foot.Font.Height = -17
          Foot.Font.Name = 'Copperplate Gothic Bold'
          Foot.Font.Style = [fsItalic, fsUnderline]
          Foot.Text.Strings = (
            '')
          Legend.Font.Height = -15
          Legend.Font.Style = [fsBold]
          Title.Font.Height = -20
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
          Top = -490
          Width = 669
          Height = 360
          Foot.Font.Height = -17
          Foot.Font.Name = 'Copperplate Gothic Bold'
          Foot.Font.Style = [fsItalic, fsUnderline]
          Legend.Font.Height = -15
          Legend.Font.Style = [fsBold]
          Title.Font.Height = -20
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
          Top = 28
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
          Top = 0
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
          Top = 30
          Width = 75
          Height = 25
          Caption = 'Refresh'
          TabOrder = 4
          OnClick = Button3Click
        end
        object ComboBox1: TComboBox
          Left = 39
          Top = 31
          Width = 130
          Height = 23
          TabOrder = 5
          Text = 'ComboBox1'
          OnChange = ComboBox1Change
        end
        object Edit3: TEdit
          Left = 3
          Top = 31
          Width = 38
          Height = 23
          TabOrder = 6
          Text = 'Year'
        end
        object Chart4: TChart
          Left = -2
          Top = 528
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
          Top = 703
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
      DesignSize = (
        689
        676)
      object ScrollBox2: TScrollBox
        AlignWithMargins = True
        Left = 0
        Top = 0
        Width = 687
        Height = 664
        HorzScrollBar.ButtonSize = 10
        VertScrollBar.ButtonSize = 10
        Anchors = [akLeft, akTop, akRight, akBottom]
        ParentShowHint = False
        ShowHint = False
        TabOrder = 0
        object StaticText1: TStaticText
          Left = 36
          Top = 40
          Width = 4
          Height = 4
          TabOrder = 0
        end
        object StaticText2: TStaticText
          Left = 3
          Top = 353
          Width = 133
          Height = 20
          Caption = 'Enter current balance'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Comic Sans MS'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 1
        end
        object StaticText3: TStaticText
          Left = 3
          Top = 3
          Width = 172
          Height = 23
          Caption = 'Choose calculation method'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Comic Sans MS'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 2
        end
        object RichEdit2: TRichEdit
          Left = 3
          Top = 43
          Width = 686
          Height = 304
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Comic Sans MS'
          Font.Style = [fsBold]
          Lines.Strings = (
            'RichEdit2')
          ParentFont = False
          TabOrder = 3
        end
        object Edit1: TEdit
          Left = 3
          Top = 379
          Width = 121
          Height = 23
          NumbersOnly = True
          TabOrder = 4
        end
        object ComboBox3: TComboBox
          Left = 3
          Top = 21
          Width = 145
          Height = 23
          TabOrder = 5
          Text = 'ComboBox3'
          OnChange = ComboBox3Change
        end
        object Button2: TButton
          Left = 3
          Top = 402
          Width = 75
          Height = 23
          Caption = 'Enter'
          TabOrder = 6
          OnClick = Button2Click
        end
        object LoadFromSavings: TButton
          Left = 544
          Top = 376
          Width = 136
          Height = 25
          Caption = 'Load'
          TabOrder = 7
          OnClick = LoadFromSavingsClick
        end
        object StaticText5: TStaticText
          Left = 509
          Top = 353
          Width = 177
          Height = 20
          Caption = 'Load Balance from App data?'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -12
          Font.Name = 'Comic Sans MS'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 8
        end
        object ByWeightInfo: TButton
          Left = 146
          Top = 21
          Width = 21
          Height = 23
          Caption = '!'
          TabOrder = 9
          OnClick = ByWeightInfoClick
        end
        object ManualBTInfo: TButton
          Left = 124
          Top = 379
          Width = 21
          Height = 24
          Caption = '!'
          TabOrder = 10
          OnClick = ManualBTInfoClick
        end
      end
    end
  end
end
