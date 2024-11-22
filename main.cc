#include <iostream>
#include <string>

struct Empleado {
  std::string nombre;
  std::string fecha_de_nacimiento;
  int edad;
  float salario;
};

void IngresarEmpleado(Empleado empleados[], int n) {
  for (int i = 0; i < n; i++) {
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

double CalcularPromedioSalario(Empleado empleados[], int n) {
  double suma = 0.0;
  for (int i = 0; i < n; i++) {
    suma += empleados[i].salario;
  }
  return suma / n;
}

int CalcularEdad(Empleado empleados[], int n) {
  int suma = 0;
  for (int i = 0; i < n; i++) {
    suma += empleados[i].edad;
  }
  return suma / n;
}

void MostrarEmpleados(Empleado empleados[], int n) {
  std::cout << "Datos de los empleados: " << std::endl;
  for (int i = 0; i < n; i++) {
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
  int n;

  std::cout << "Ingresar cuantos empleados se registraran: ";
  std::cin >> n;

  if (n > 0 && n < 100) {
    IngresarEmpleado(empleados, n);
    MostrarEmpleados(empleados, n);

    double PromedioSalarios = CalcularPromedioSalario(empleados, n);
    int PromedioEdad = CalcularEdad(empleados, n);

    std::cout << "El salario promedio es de: $" << PromedioSalarios;
    std::cout << std::endl;
    std::cout << "La edad promedio es de: " << PromedioEdad;
  } else {
    std::cout << "Cantidad invalida";
  }
  return 0;
}
