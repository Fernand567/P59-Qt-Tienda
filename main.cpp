#include "tienda.h"

#include <QApplication>
#include <QTranslator>
#include <QInputDialog>
#include <QLocale>
#include <QDebug>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    // Objeto para manejar las traducciones
        QTranslator traducion;
        // Solicitando al usuario que seleccione un idioma
        QString idioma=QLocale::system().name();
        // Dependiendo del idioma seleccionado, carga el archivo de rtaducción
        if (idioma == "fr_BE"){
            traducion.load(":/tienda_fr.qm");
        }else if (idioma == "en_US"){
            traducion.load(":/tienda_en.qm");
        }else if(idioma == "de_DE"){
            traducion.load(":/tienda_al.qm");
        }
        // Si es diferente de español, se instala la traducción en TODA la aplicación
        if (idioma != "es_Es"){
                a.installTranslator(&traducion);
            }
    Tienda w;
    w.show();
    return a.exec();
}
