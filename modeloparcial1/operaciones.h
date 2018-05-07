#ifndef OPERACIONES_H_INCLUDED
#define OPERACIONES_H_INCLUDED

/** \brief Suma dos numeros flotantes
 *
 * \param un primer flotante
 * \param un segundo flotante
 * \return un flotante resultado de la suma de dos flotantes
 *
 */

float sumar(float numero1, float numero2);

/** \brief Resta dos flotantes
 *
 * \param un primer flotante
 * \param un segundo flotante
 * \return un flotante resultado de la resta de dos flotantes
 *
 */
float restar(float numero1, float numero2);

/** \brief Dividir dos flotantes
 *
 * \param un numero flotante numerador
 * \param un segundo flotante denominador distinto de cero
 * \return un flotante resultado de la division
 *
 */

float dividir(float numero1, float numero2);

/** \brief multiplicar dos flotantes
 *
 * \param un pimer flotante
 * \param un segundo flotante
 * \return un flotante resultado de la multiplicacion
 *
 */

float multiplicar(float numero1, float numero2);

/** \brief factorizar numero entero hasta 20
 *
 * \param un entero
 * \return un resultado de factorizar un entero (long long int)
 *
 */

long long int factorizar(int numero);




 /** \brief lee un numero ingresado flotante
  *
  * \param valor mininimo flotante a ingresar
  * \param valor maximo flotante a ingresar
  * \return un numero flotante
  *
  */

  #endif // OPERACIONES_H_INCLUDED
