import wx
import time
import os

class MyFrame(wx.Frame):
    def __init__(self, *args, **kw):
        # Quitar la barra de menú y otras opciones de estilo
        super(MyFrame, self).__init__(*args, **kw, style=wx.DEFAULT_FRAME_STYLE & ~wx.CAPTION & ~wx.RESIZE_BORDER)
        
        panel = wx.Panel(self)
        panel.SetBackgroundColour(wx.BLACK)
        sizer = wx.BoxSizer(wx.VERTICAL)
        
        self.label = wx.StaticText(panel, label="Init the system")
        self.label.SetForegroundColour(wx.WHITE)
        sizer.Add(self.label, 0, wx.ALL, 10)

        font = wx.Font(12, wx.FONTFAMILY_TELETYPE, wx.FONTSTYLE_NORMAL, wx.FONTWEIGHT_BOLD)
        self.label.SetFont(font)

        

        # self.button = wx.Button(panel, label="Haz clic aquí")
        # self.button.Bind(wx.EVT_BUTTON, self.on_button_click)
        # sizer.Add(self.button, 0, wx.ALL | wx.CENTER, 5)


        if not os.path.exists("src/versions/"):
            self.label2 = wx.StaticText(panel, label="ERROR: NOT FOUND FOLDER OF THE BASE CODE")
            self.label2.SetForegroundColour(wx.WHITE)
            sizer.Add(self.label2, 12, wx.ALL, 10)

            font = wx.Font(12, wx.FONTFAMILY_TELETYPE, wx.FONTSTYLE_NORMAL, wx.FONTWEIGHT_BOLD)
            self.label2.SetFont(font)
        else:
            self.label3 = wx.StaticText(panel, label="FOUND THE BASE CODE FOLDER")
            self.label3.SetForegroundColour(wx.WHITE)
            sizer.Add(self.label3, 12, wx.ALL, 10)

            font = wx.Font(12, wx.FONTFAMILY_TELETYPE, wx.FONTSTYLE_NORMAL, wx.FONTWEIGHT_BOLD)
            self.label3.SetFont(font)

            carpetas = [item for item in os.listdir("src/versions/") if os.path.isdir(os.path.join("src/versions/", item))]

            if carpetas:
                for carpeta in carpetas:
                    self.label4 = wx.StaticText(panel, label="VERSIONS:  " + carpeta)

                    self.label4.SetForegroundColour(wx.WHITE)
                    sizer.Add(self.label4, 12, wx.ALL, 10)

                    font = wx.Font(12, wx.FONTFAMILY_TELETYPE, wx.FONTSTYLE_NORMAL, wx.FONTWEIGHT_BOLD)
                    self.label4.SetFont(font)

        


        panel.SetSizer(sizer)

        # # Hacer que la ventana ocupe toda la pantalla
        self.ShowFullScreen(True)

        # # Vincular el evento de teclado
        self.Bind(wx.EVT_KEY_DOWN, self.on_key_press)

    def on_key_press(self, event):
        # Verificar si se presiona Ctrl + C
        if event.ControlDown() and event.GetKeyCode() == wx.WXK_C:
            self.Close()  # Cerrar la ventana
        else:
            event.Skip()  # Permitir que otros eventos se manejen normalmente

    def on_button_click(self, event):
        wx.MessageBox("¡Botón presionado en wxPython!", "Notificación", wx.OK | wx.ICON_INFORMATION)
        

if __name__ == "__main__":
    app = wx.App()
    frame = MyFrame(None)
    frame.Show()
    app.MainLoop()
