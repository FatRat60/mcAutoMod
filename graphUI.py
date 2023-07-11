import customtkinter
import os

customtkinter.set_appearance_mode('dark')
customtkinter.set_default_color_theme('dark-blue')

class Application(customtkinter.CTk):
    def __init__(self):
        super().__init__()
        self.geometry("500x350")
        self.title("Minecraft Mod Adder")
        self.createWidgets()
    
    def createWidgets(self):
        frame = customtkinter.CTkFrame(master=self)
        frame.pack(pady=20, padx=60, fill="both", expand=True, anchor=customtkinter.CENTER)

        label = customtkinter.CTkLabel(master=frame, text="Login System")
        label.pack(pady=12, padx=10)

        entry1 = customtkinter.CTkEntry(master=frame, placeholder_text="Username")
        entry1.pack(pady=12, padx=10)

        entry2 = customtkinter.CTkEntry(master=frame, placeholder_text="Password", show="*")
        entry2.pack(pady=12, padx=10)

        button = customtkinter.CTkButton(master=frame, text="Login", command=None)
        button.pack(pady=12, padx=10)

        checkbox = customtkinter.CTkCheckBox(master=frame, text="Remember Me")
        checkbox.pack(pady=12, padx=10)

    def findDefPath(self):
        username = os.path.expanduser('~')
        defPath = username + "\AppData\Roaming\.minecraft"
        if os.path.isdir(defPath):
            print("Success")
        else :
            print("Nope")
    
    mcmod.defPathFound()