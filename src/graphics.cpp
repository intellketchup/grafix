#include <windows.h> // Para usar COLORREF y otras funciones de Windows
#include <cmath> // Para usar sqrt
#include "../include/graphics.h"

HWND hwnd; // Variable global para la ventana
Button button; // Declaración global del botón

// Función para inicializar la ventana
bool initWindow(const char* title, int width, int height) {
    WNDCLASS wc = {};
    wc.lpfnWndProc = DefWindowProc;
    wc.hInstance = GetModuleHandle(nullptr);
    wc.lpszClassName = "SimpleGraphicsClass";

    RegisterClass(&wc);

    hwnd = CreateWindowEx(
        0, "SimpleGraphicsClass", title,
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
        width, height, nullptr, nullptr,
        wc.hInstance, nullptr
    );

    if (hwnd == nullptr) {
        return false; // Error en la creación de la ventana
    }

    ShowWindow(hwnd, SW_SHOW);
    return true;
}

// Implementación de la función putPixel
void putPixel(int x, int y, COLORREF color) {
    HDC hdc = GetDC(hwnd);
    SetPixel(hdc, x, y, color);
    ReleaseDC(hwnd, hdc);
}

// Implementación de drawLine (algoritmo de Bresenham)
void drawLine(int x1, int y1, int x2, int y2, COLORREF color) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        putPixel(x1, y1, color);
        if (x1 == x2 && y1 == y2) break;
        int err2 = err * 2;
        if (err2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (err2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

// Implementación de drawRect
void drawRect(int x, int y, int width, int height, COLORREF color) {
    drawLine(x, y, x + width, y, color);               // Superior
    drawLine(x, y, x, y + height, color);              // Izquierda
    drawLine(x + width, y, x + width, y + height, color); // Derecha
    drawLine(x, y + height, x + width, y + height, color); // Inferior
}

// Implementación de drawCircle (algoritmo de Bresenham)
void drawCircle(int centerX, int centerY, int radius, COLORREF color) {
    int x = radius, y = 0;
    int err = 1 - radius;

    while (x >= y) {
        putPixel(centerX + x, centerY + y, color);
        putPixel(centerX + y, centerY + x, color);
        putPixel(centerX - y, centerY + x, color);
        putPixel(centerX - x, centerY + y, color);
        putPixel(centerX - x, centerY - y, color);
        putPixel(centerX - y, centerY - x, color);
        putPixel(centerX + y, centerY - x, color);
        putPixel(centerX + x, centerY - y, color);
        
        if (err <= 0) {
            err += 2 * ++y + 1;
        } else {
            err += 2 * (y - x--) + 1;
        }
    }
}

// Función para rellenar un rectángulo
void fillRect(int x, int y, int width, int height, COLORREF color) {
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            putPixel(x + i, y + j, color);
        }
    }
}

// Función para rellenar un círculo
void fillCircle(int centerX, int centerY, int radius, COLORREF color) {
    for (int y = -radius; y <= radius; y++) {
        for (int x = -radius; x <= radius; x++) {
            if (x * x + y * y <= radius * radius) {
                putPixel(centerX + x, centerY + y, color);
            }
        }
    }
}

// Función para dibujar un botón
void drawButton(const Button& button) {
    fillRect(button.x, button.y, button.width, button.height, button.color);
    drawText(button.x + 10, button.y + 10, button.text, RGB(0, 0, 0)); // Dibuja el texto en el botón
}

// Función para dibujar texto
void drawText(int x, int y, const char* text, COLORREF color) {
    HDC hdc = GetDC(hwnd);
    SetTextColor(hdc, color);
    TextOut(hdc, x, y, text, strlen(text)); // Dibuja el texto en la posición especificada
    ReleaseDC(hwnd, hdc);
}

// Función para comprobar si el mouse está sobre el botón
bool isMouseOverButton(const Button& button, int mouseX, int mouseY) {
    return mouseX >= button.x && mouseX <= button.x + button.width &&
           mouseY >= button.y && mouseY <= button.y + button.height;
}

// Manejo de clics del mouse
void handleMouseClick(int mouseX, int mouseY, const Button& button) {
    if (isMouseOverButton(button, mouseX, mouseY)) {
        if (button.onClick) {
            button.onClick(); // Llama a la función asociada al botón
        }
    }
}

void waitForClose() {
    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}