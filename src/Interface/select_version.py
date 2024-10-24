import os

def verificar_carpeta(nombre_carpeta):
    if not os.path.exists(nombre_carpeta):
        raise FileNotFoundError(f"La carpeta '{nombre_carpeta}' no existe.")
    else:
        print(f"La carpeta '{nombre_carpeta}' existe.")

# # Ejemplo de uso
# nombre_carpeta = "mi_carpeta"  # Cambia esto al nombre de la carpeta que deseas verificar
# try:
#     verificar_carpeta(nombre_carpeta)
# except FileNotFoundError as e:
#     print(e)
