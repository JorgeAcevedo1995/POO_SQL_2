// mysql_c.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include "Marcas.h"

using namespace std;
int main()
{
    string producto, descripcion, fecha_ingreso,marca;
    int idproducto = 0, idmarca = 0, existencia = 0;
    double precio_costo = 0, precio_venta = 0;

  
    cout << "Ingresar el producto:";
    getline(cin, producto);
    cout << "Ingresar ID de marca:";
    cin >> idmarca;
    cin.ignore();
    cout << "Ingresar marca:";
    getline(cin, marca);
    cout << "Ingresar descripcion:";
    getline(cin, descripcion);
    cout << "Ingresar precio costo:";
    cin >> precio_costo;
    cin.ignore();
    cout << "Ingresar precio venta:";
    cin >> precio_venta;
    cin.ignore();
    cout << "Ingresar existencias:";
    cin >> existencia;
    cin.ignore();
    cout << "Ingrese fecha de ingreso:";
    cin >> fecha_ingreso;

    Marcas c = Marcas(producto, descripcion, fecha_ingreso, idproducto, idmarca, existencia, precio_costo, precio_venta, marca);
    c.crear();
    c.leer();

    system("pause");
    return 0;
}
