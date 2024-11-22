#include <iostream>
#include <string>

struct Empleado {
  std::string nombre;
  std::string fecha_de_nacimiento;
  int edad;
  float salario;
};

void IngresarEmpleado(Empleado empleados[], int cantidadEmpleados) {
  for (int i = 0; i < cantidadEmpleados; i++) {
    std::cin.ignore();
    std::cout << "Ingrese el nombre del empleado: ";
    std::getline(std::cin, empleados[i].nombre);
    std::cout << "Ingrese fecha de nacimiento del empleado: ";
    std::cin >> empleados[i].fecha_de_nacimiento;
    std::cout << "Ingrese la edad del empleado: ";
    std::cin >> empleados[i].edad;
    std::cout << "Ingrese el salario del empleado: ";
    std::cin >> empleados[i].salario;
    std::cout << std::endl;
  }
}

double CalcularPromedioSalario(Empleado empleados[], int cantidadEmpleados) {
  double suma = 0.0;
  for (int i = 0; i < cantidadEmpleados; i++) {
    suma += empleados[i].salario;
  }
  return suma / cantidadEmpleados;
}

int CalcularEdad(Empleado empleados[], int cantidadEmpleados) {
  int suma = 0;
  for (int i = 0; i < cantidadEmpleados; i++) {
    suma += empleados[i].edad;
  }
  return suma / cantidadEmpleados;
}

void MostrarEmpleados(Empleado empleados[], int cantidadEmpleados) {
  std::cout << "Datos de los empleados: " << std::endl;
  for (int i = 0; i < cantidadEmpleados; i++) {
    std::cout << "Nombre: " << empleados[i].nombre;
    std::cout << std::endl;
    std::cout << "Fecha de nacimiento: " << empleados[i].fecha_de_nacimiento;
    std::cout << std::endl;
    std::cout << "Edad: " << empleados[i].edad;
    std::cout << std::endl;
    std::cout << "Salario: $" << empleados[i].salario;
    std::cout << std::endl;
    std::cout << std::endl;
  }
}

int main(int argc, char* argv[]) {
  Empleado empleados[100];
  int cantidadEmpleados;

  std::cout << "Ingresar cuantos empleados se registraran: ";
  std::cin >> cantidadEmpleados;

  if (cantidadEmpleados > 0 && cantidadEmpleados < 100) {
    IngresarEmpleado(empleados, cantidadEmpleados);
    MostrarEmpleados(empleados, cantidadEmpleados);

    double PromedioSalarios = CalcularPromedioSalario(empleados, cantidadEmpleados);
    int PromedioEdad = CalcularEdad(empleados, cantidadEmpleados);

    std::cout << "El salario promedio es de: $" << PromedioSalarios;
    std::cout << std::endl;
    std::cout << "La edad promedio es de: " << PromedioEdad;
  } else {
    std::cout << "Cantidad invalida";
  }
  return 0;
}
