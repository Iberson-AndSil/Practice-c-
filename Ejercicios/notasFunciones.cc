#include <iostream>
using namespace std;

struct examen
{
    string CursoExamen;
}Examenes[10];

struct alumno
{
    string NombreAlumno;
    string CodigoAlumno;
    float Nota[10];
} Ae[30];

void DigitarDatosAlumnos(int);
void DigitarDatosExamenes(int);
void DigitarNotas(int, int);
void PromedioAlumno(int, int);
void MejorCalificacionExamenX(int, int);
//void MostrarDatos(int, int);

int main()
{

    int CantidadAlumnos, CantidadExamenes;
    cout << "---Cuantos alumnos desea agregar?---\n-->";
    cin >> CantidadAlumnos;
    DigitarDatosAlumnos(CantidadAlumnos);
    cout << "---Cuantos examenes dieron?---\n-->";
    cin >> CantidadExamenes;
    DigitarDatosExamenes(CantidadExamenes);
    DigitarNotas(CantidadAlumnos, CantidadExamenes);
    PromedioAlumno(CantidadAlumnos, CantidadExamenes);

    //MostrarDatos(CantidadAlumnos, CantidadExamenes);


    return 0;
}
void DigitarDatosAlumnos(int ca)
{
    cout << "\t_______________________\n";
    cout << "\t|NOMBRE DE LOS ALUMNOS|\n";
    cout << "\t-----------------------\n\n";
    cout << endl;
    for (int i = 0; i < ca; i++)
    {
        cout << "**********************************" << endl;
        cout << "=) Alumno " << i + 1 << ": " << endl << "\t=) Nombre: ";
        cin >> Ae[i].NombreAlumno;
        cout << "\n\t=) Codigo: ";
        cin >> Ae[i].CodigoAlumno;
        cout << endl;
        cout << "**********************************" << endl;
    }
}
void DigitarDatosExamenes(int ce)
{
    cout << "\t______________________\n";
    cout << "\t|NOMBRE DE LOS CURSOS|\n";
    cout << "\t----------------------\n\n";
    for (int i = 0; i < ce; i++)
    {
        cout << "**********************************" << endl;
        cout << "=) Curso " << i + 1 << ": ";
        cin >> Examenes[i].CursoExamen;
        cout << "**********************************" << endl;
    }
}
void DigitarNotas(int ca, int ce)
{
    cout << "\t_______________\n";
    cout << "\t|DIGITAR NOTAS|\n";
    cout << "\t---------------\n\n";
    for (int i = 0; i < ca; i++)
    {
         cout << "**********************************" << endl;
        cout << "=) Alumno " << Ae[i].NombreAlumno << endl;
        cout << "   |" << Ae[i].CodigoAlumno << "|" << endl;
        for (int j = 0; j < ce; j++)
        {
            cout << "\n\t" << "=) " << Examenes[j].CursoExamen << endl;
            cout << "\n\tNota --> ";
            cin >> Ae[i].Nota[j];
        }
         cout << "**********************************" << endl;
    }
}
void PromedioAlumno(int ca, int ce)
{
    int acumulador;
    float promedio;
    cout << "\t___________________\n";
    cout << "\t|PROMEDIO DE NOTAS|\n";
    cout << "\t-------------------\n\n";
    for(int i = 0; i < ca; i++){
        acumulador = 0;
        cout << "**********************************" << endl;
        cout << "=) Alumno " << Ae[i].NombreAlumno << ": \n\n";
        for (int j = 0; j < ce; j++)
        {
            acumulador = acumulador + Ae[i].Nota[j];
        }
        promedio = acumulador / ce;
        cout << "\t=) Promedio --> "<< promedio <<endl;
        cout << "**********************************" << endl;
    }
}
void MejorCalificacionExamenX(int ca, int ce){
    cout << "\t________________________\n";
    cout << "\t|MEJOR NOTA DE EXAMEN X|\n";
    cout << "\t------------------------\n\n";
    

}
