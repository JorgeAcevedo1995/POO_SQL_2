#pragma once
#include <iostream>
using namespace std;
class Producto {
	// atributos
	protected: string producto, descripcion,fecha_ingreso;
		 int idproducto=0,idmarca=0,existencia=0;
		 double precio_costo = 0, precio_venta=0;
		 // costructor
	protected:
	Producto() {
	}
	Producto(string pro, string desc, string fi, int idpro, int idmar, int exi, double costo, double venta) {
		producto = pro;
		descripcion = desc;
		fecha_ingreso = fi;
		idproducto = idpro;
		idmarca = idmar;
		existencia = exi;
		precio_costo = costo;
		precio_venta = venta;
	}
};

