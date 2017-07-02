word 宏：
	教程： https://msdn.microsoft.com/zh-cn/library/ff197417.aspx
	       https://msdn.microsoft.com/zh-cn/library/ff834504.aspx
	
	
	ActiveDocument.Shapes.Range(Array("文本框 2")).Select
	
=========================================================	
Sub AddContentContrlRichText()
'
'https://msdn.microsoft.com/zh-cn/library/ff836891.aspx
'将剪贴板的内容粘贴到文本框
'
    Dim objCC As ContentControl
 
    Set objCC = ActiveDocument.ContentControls _
        .Add(wdContentControlRichText)
        
    With objCC.Range
    .Paste
    .Font.Size = 7
    .ParagraphFormat.LineSpacingRule = wdLineSpaceExactly
    .ParagraphFormat.LineSpacing = 7.5
    End With
     
End Sub


=========================================================


