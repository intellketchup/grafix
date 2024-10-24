#include "../include/graphics.h"

void onButtonClick() {
    MessageBox(NULL, "¡Botón presionado en C++!", "Notificación", MB_OK);
}

int main() {
    // Inicializa la ventana
    if (!initWindow("Mi Biblioteca Gráfica con wxPython", 800, 600)) {
        return -1; // Error en la creación de la ventana
    }
    
    // Definición del botón
    // Button myButton = {100, 100, 200, 50, "Lanzar wxPython", RGB(0, 255, 0), onButtonClick};

    // Dibuja el botón
    // drawButton(myButton);

    // Mantiene la ventana abierta y maneja los clics del mouse
    // MSG msg;
    // while (true) {
    //     if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
    //         TranslateMessage(&msg);
    //         DispatchMessage(&msg);
    //         if (msg.message == WM_LBUTTONDOWN) {
    //             int mouseX = LOWORD(msg.lParam);
    //             int mouseY = HIWORD(msg.lParam);
    //             handleMouseClick(mouseX, mouseY, myButton); // Maneja el clic del mouse
    //         }
    //     }
    // }

    // Lanza la aplicación wxPython
    system("python src/Interface/app.py &"); // Asegúrate de que Python esté en tu PATH

    waitForClose(); // Espera hasta que la ventana se cierre
    return 0;
}