#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <windows.h> // Para usar COLORREF

// Estructura para un botón
struct Button {
    int x, y, width, height;
    const char* text;
    COLORREF color;
    void (*onClick)(); // Función a ejecutar al hacer clic
};

// Función para inicializar la ventana
bool initWindow(const char* title, int width, int height);

// Funciones para dibujar
void drawLine(int x1, int y1, int x2, int y2, COLORREF color);
void drawRect(int x, int y, int width, int height, COLORREF color);
void drawCircle(int centerX, int centerY, int radius, COLORREF color);
void putPixel(int x, int y, COLORREF color);
void waitForClose();
void fillRect(int x, int y, int width, int height, COLORREF color);
void fillCircle(int centerX, int centerY, int radius, COLORREF color);
void drawButton(const Button& button); // Dibuja un botón
bool isMouseOverButton(const Button& button, int mouseX, int mouseY); // Comprueba si el mouse está sobre el botón
void handleMouseClick(int mouseX, int mouseY, const Button& button); // Maneja el clic del mouse
void drawText(int x, int y, const char* text, COLORREF color); // Dibuja texto en la ventana

#endif // GRAPHICS_H
